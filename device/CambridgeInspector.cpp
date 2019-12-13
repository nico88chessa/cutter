#include "CambridgeInspector.hpp"

#include "CambridgeUtils.hpp"

#include <CTIECUtilsWin32Cls.h>

#include <Logger.hpp>
#include <Settings.hpp>


namespace CTBW = BroadcastWin32Wrapper;
using namespace PROGRAM_NAMESPACE;

static inline CTBW::BroadcastWin32& CTBInstance() {
    return CTBW::BroadcastWin32::Instance();
}

static inline bool str2Bool(const QString& str) {
    return str.compare("TRUE", Qt::CaseInsensitive) == 0;
}

bool CambridgeInspector::getIsConnected() const {

    traceEnter;
    traceExit;
    return isConnected;

}

void CambridgeInspector::setIsConnected(bool value) {

    traceEnter;

    isConnected = value;
    if (isConnected)
        emit connectedSignal();
    else
        emit disconnectedSignal();

    traceExit;
}

CambridgeInspector::CambridgeInspector(QObject *parent) :
    QObject(parent),
    isConnected(false),
    refreshTimer(this), restartIntervalMs(0), clientId(0) {

    traceEnter;

    auto&& s = Settings::instance();

    ipBroadcastAddress = s.getCtBroadcastIpAddress();
    broadcastPort = s.getCtBroadcastPort();
    localIpAddress = s.getMachineLocalIpAddress();

    quint16 refreshTimeMs = s.getCtRefreshIntervalMs();
    restartIntervalMs = s.getCtRestartIntervalMs();

    refreshTimer.setInterval(refreshTimeMs);

    connect(&refreshTimer, &QTimer::timeout, this, &CambridgeInspector::process);

    traceExit;

}

CambridgeInspector::~CambridgeInspector() {

    traceEnter;
    traceExit;

}

bool CambridgeInspector::beforeProcess() {

    traceEnter;

    namespace ECU = ECUtilsWin32Wrapper;

    traceInfo() << "Try connection to SMC Broadcast service";

    SMCError errCode;
    if (!getIsConnected()) {

        errCode = CTBInstance().clientAttachBroadcast(
                    ipBroadcastAddress.toStdString().data(),
                    localIpAddress.toStdString().data(),
                    broadcastPort,
                    clientId
                    );

        if (CambridgeUtils::isError(errCode)) {
            traceErr() << "Failed to connect to SMC Broadcast service";
            traceErr() << "Error code: " << errCode;
            traceErr() << "Error description: " << CTBInstance().GetErrorCodeDescription(errCode);
            return false;
        }

        traceInfo() << "SMC Broadcast service connection succesful";
        setIsConnected(true);
    }

    const char* deviceList = nullptr;
    int serverCount = 0;
    errCode = CTBInstance().getServerList(clientId, serverCount, deviceList);

    if (CambridgeUtils::isError(errCode)) {
        traceErr() << "Failed to get server list from broadcast";
        traceErr() << "Error code: " << errCode;
        traceErr() << "Error description: " << CTBInstance().GetErrorCodeDescription(errCode);
        setIsConnected(false);
        return false;
    }

    ECU::ECUtilsWin32 ecUtils;
    const char* fName = nullptr;
    ecUtils.ReadFromXML(deviceList, 0, "Device", "name", fName);
    friendlyName = fName;

    if (friendlyName.isEmpty()) {
        traceErr() << "SMC Friendly name not retrieved yet";
        return false;
    }

    traceInfo() << "SMC friendly name: " << friendlyName;


    traceExit;
    return true;

}

void CambridgeInspector::restartProcess() {

    traceEnter;

    if (refreshTimer.isActive())
        refreshTimer.stop();

    QTimer::singleShot(restartIntervalMs, this, &CambridgeInspector::startProcess);

    traceExit;

}

void CambridgeInspector::startProcess() {

    traceEnter;

    if (!beforeProcess()) {
        traceInfo() << "Cambridge inspector: auto restart process";
        QTimer::singleShot(restartIntervalMs, this, &CambridgeInspector::startProcess);
        return;
    }

    refreshTimer.start();
    emit processStartedSignal();

    traceExit;

}

void CambridgeInspector::stopProcess() {

    traceEnter;

    if (isConnected) {
        SMCError errCode = CTBInstance().clientDetachBroadcast(clientId);

        if (CambridgeUtils::isError(errCode)) {
            traceErr() << "Failed to detach client";
            traceErr() << "Error code: " << errCode;
            traceErr() << "Error description: " << CTBInstance().GetErrorCodeDescription(errCode);
        }
        setIsConnected(false);

    }

    if (refreshTimer.isActive())
        refreshTimer.stop();

    emit processStoppedSignal();

    traceExit;

}

void CambridgeInspector::process() {

    traceEnter;

    const char* data = nullptr;
    SMCError errCode;
    CambridgeStatusData ctStatus;

    errCode = CTBInstance().getBroadcastData(clientId, friendlyName.toStdString().c_str(), CT_DATATYPE_SYSTEM_INFORMATION, data);
    if (CambridgeUtils::isError(errCode)) {
        traceErr() << "Failed to get broadcast system information";
        traceErr() << "Error code: " << errCode;
        traceErr() << "Error description: " << CTBInstance().GetErrorCodeDescription(errCode);
        setIsConnected(false);
    }
    traceDebug() << "System information" << data;
    parseSystemXML(data, ctStatus);

    errCode = CTBInstance().getBroadcastData(clientId, friendlyName.toStdString().c_str(), CT_DATATYPE_STATUS_INFORMATION, data);
    if (CambridgeUtils::isError(errCode)) {
        traceErr() << "Failed to get broadcast status information";
        traceErr() << "Error code: " << errCode;
        traceErr() << "Error description: " << CTBInstance().GetErrorCodeDescription(errCode);
        setIsConnected(false);
    }
    traceDebug() << "Status information" << data;
    parseStatusXML(data, ctStatus);

    if (!isConnected)
        this->restartProcess();

    emit statusSignal(ctStatus);

    traceExit;

}

void CambridgeInspector::parseSystemXML(const char* systemData, CambridgeStatusData& status) {

    traceEnter;
    namespace ECU = ECUtilsWin32Wrapper;

    ECU::ECUtilsWin32 ecUtils;
    const char* data;
    bool res;

    res = ecUtils.ReadFromXML(systemData, 0, CT_SYSTEM_MSN, "", data);
    if (res) status.setMsn(data); else traceWarn() << "Failed to get parameter: " << CT_SYSTEM_MSN;

    res = ecUtils.ReadFromXML(systemData, 0, CT_SYSTEM_PVER, "", data);
    if (res) status.setPVer(data); else traceWarn() << "Failed to get parameter: " << CT_SYSTEM_PVER;

    res = ecUtils.ReadFromXML(systemData, 0, CT_SYSTEM_AVER, "", data);
    if (res) status.setAVer(data); else traceWarn() << "Failed to get parameter: " << CT_SYSTEM_AVER;

    res = ecUtils.ReadFromXML(systemData, 0, CT_SYSTEM_OBJEXTVER, "", data);
    if (res) status.setObjextVer(data); else traceWarn() << "Failed to get parameter: " << CT_SYSTEM_OBJEXTVER;

    res = ecUtils.ReadFromXML(systemData, 0, CT_SYSTEM_FPGAFIRMVER, "", data);
    if (res) status.setFpgaFirmVer(data); else traceWarn() << "Failed to get parameter: " << CT_SYSTEM_FPGAFIRMVER;

    res = ecUtils.ReadFromXML(systemData, 0, CT_SYSTEM_STATECODE, "", data);
    if (res) status.setStateCode(QString(data).toInt()); else traceWarn() << "Failed to get parameter: " << CT_SYSTEM_STATECODE;

    res = ecUtils.ReadFromXML(systemData, 0, CT_SYSTEM_LASTERROR, "", data);
    if (res) status.setLastError(QString(data).toInt()); else traceWarn() << "Failed to get parameter: " << CT_SYSTEM_LASTERROR;

    res = ecUtils.ReadFromXML(systemData, 0, CT_SYSTEM_FREETEMPSTORAGE, "", data);
    if (res) status.setFreeTempStorage(QString(data).toInt()); else traceWarn() << "Failed to get parameter: " << CT_SYSTEM_FREETEMPSTORAGE;

    res = ecUtils.ReadFromXML(systemData, 0, CT_SYSTEM_PERMSTORAGEPATH, "", data);
    if (res) status.setPermStoragePath(data); else traceWarn() << "Failed to get parameter: " << CT_SYSTEM_PERMSTORAGEPATH;

    res = ecUtils.ReadFromXML(systemData, 0, CT_SYSTEM_FREEPERMSTORAGE, "", data);
    if (res) status.setFreePermStorage(QString(data).toInt()); else traceWarn() << "Failed to get parameter: " << CT_SYSTEM_FREEPERMSTORAGE;

    res = ecUtils.ReadFromXML(systemData, 0, CT_SYSTEM_FREEUSBSTORAGE, "", data);
    if (res) status.setFreeUsbStorage(QString(data).toInt()); else traceWarn() << "Failed to get parameter: " << CT_SYSTEM_FREEUSBSTORAGE;

    res = ecUtils.ReadFromXML(systemData, 0, CT_SYSTEM_MAC, "", data);
    if (res) status.setMac(data); else traceWarn() << "Failed to get parameter: " << CT_SYSTEM_MAC;

    res = ecUtils.ReadFromXML(systemData, 0, CT_SYSTEM_NETMASK, "", data);
    if (res) status.setNetmask(data); else traceWarn() << "Failed to get parameter: " << CT_SYSTEM_NETMASK;

    res = ecUtils.ReadFromXML(systemData, 0, CT_SYSTEM_NETASSIGN, "", data);
    if (res) status.setNetassign(data); else traceWarn() << "Failed to get parameter: " << CT_SYSTEM_NETASSIGN;

    res = ecUtils.ReadFromXML(systemData, 0, CT_SYSTEM_IP, "", data);
    if (res) status.setIp(data); else traceWarn() << "Failed to get parameter: " << CT_SYSTEM_IP;

    res = ecUtils.ReadFromXML(systemData, 0, CT_SYSTEM_CONNECTIP, "", data);
    if (res) status.setConnectIp(data); else traceWarn() << "Failed to get parameter: " << CT_SYSTEM_CONNECTIP;

    res = ecUtils.ReadFromXML(systemData, 0, CT_SYSTEM_FRIENDLYNAME, "", data);
    if (res) status.setFriendlyName(friendlyName); else traceWarn() << "Failed to get parameter: " << CT_SYSTEM_FRIENDLYNAME;

    res = ecUtils.ReadFromXML(systemData, 0, CT_SYSTEM_CONNECTJOB, "", data);
    if (res) status.setConnectJob(data); else traceWarn() << "Failed to get parameter: " << CT_SYSTEM_CONNECTJOB;

    res = ecUtils.ReadFromXML(systemData, 0, CT_SYSTEM_PORT, "", data);
    if (res) status.setPort(QString(data).toInt()); else traceWarn() << "Failed to get parameter: " << CT_SYSTEM_PORT;

    res = ecUtils.ReadFromXML(systemData, 0, CT_SYSTEM_HSN, "", data);
    if (res) status.setHsn(QString(data).toInt()); else traceWarn() << "Failed to get parameter: " << CT_SYSTEM_HSN;

    traceExit;

}

void CambridgeInspector::parseStatusXML(const char* statusData, CambridgeStatusData& status) {

    traceEnter;
    namespace ECU = ECUtilsWin32Wrapper;

    ECU::ECUtilsWin32 ecUtils;
    const char* data;
    bool res;
    QString boolStr;

    res = ecUtils.ReadFromXML(statusData, 0, CT_STATUS_XPOSACK, "", data);
    if (res) {
        boolStr = data;
        status.setXPosAck(str2Bool(boolStr));
    } else
        traceWarn() << "Failed to get parameter: " << CT_STATUS_XPOSACK;

    res = ecUtils.ReadFromXML(statusData, 0, CT_STATUS_YPOSACK, "", data);
    if (res) {
        boolStr = data;
        status.setYPosAck(str2Bool(boolStr));
    } else
        traceWarn() << "Failed to get parameter: " << CT_STATUS_YPOSACK;

    res = ecUtils.ReadFromXML(statusData, 0, CT_STATUS_XPOS, "", data);
    if (res) status.setXPos(QString(data).toInt()); else traceWarn() << "Failed to get parameter: " << CT_STATUS_XPOS;

    res = ecUtils.ReadFromXML(statusData, 0, CT_STATUS_YPOS, "", data);
    if (res) status.setYPos(QString(data).toInt()); else traceWarn() << "Failed to get parameter: " << CT_STATUS_YPOS;

    res = ecUtils.ReadFromXML(statusData, 0, CT_STATUS_XACTPOS, "", data);
    if (res) status.setXActPos(QString(data).toInt()); else traceWarn() << "Failed to get parameter: " << CT_STATUS_XACTPOS;

    res = ecUtils.ReadFromXML(statusData, 0, CT_STATUS_YACTPOS, "", data);
    if (res) status.setYActPos(QString(data).toInt()); else traceWarn() << "Failed to get parameter: " << CT_STATUS_YACTPOS;

    res = ecUtils.ReadFromXML(statusData, 0, CT_STATUS_XTEMP, "", data);
    if (res) {
        boolStr = data;
        status.setXTemp(str2Bool(data));
    } else
        traceWarn() << "Failed to get parameter: " << CT_STATUS_XTEMP;

    res = ecUtils.ReadFromXML(statusData, 0, CT_STATUS_YTEMP, "", data);
    if (res) {
        boolStr = data;
        status.setYTemp(str2Bool(data));
    } else
        traceWarn() << "Failed to get parameter: " << CT_STATUS_YTEMP;

    res = ecUtils.ReadFromXML(statusData, 0, CT_STATUS_CONTRLTEMP, "", data);
    if (res) status.setContrlTemp(QString(data).toInt()); else traceWarn() << "Failed to get parameter: " << CT_STATUS_CONTRLTEMP;

    res = ecUtils.ReadFromXML(statusData, 0, CT_STATUS_XSTATUS, "", data);
    if (res) status.setXStatus(QString(data).toInt(nullptr, 16)); else traceWarn() << "Failed to get parameter: " << CT_STATUS_XSTATUS;

    res = ecUtils.ReadFromXML(statusData, 0, CT_STATUS_YSTATUS, "", data);
    if (res) status.setYStatus(QString(data).toInt(nullptr, 16)); else traceWarn() << "Failed to get parameter: " << CT_STATUS_YSTATUS;

    res = ecUtils.ReadFromXML(statusData, 0, CT_STATUS_XPOWER, "", data);
    if (res) {
        boolStr = data;
        status.setXPower(str2Bool(data));
    } else
        traceWarn() << "Failed to get parameter: " << CT_STATUS_XPOWER;

    res = ecUtils.ReadFromXML(statusData, 0, CT_STATUS_YPOWER, "", data);
    if (res) {
        boolStr = data;
        status.setYPower(str2Bool(data));
    } else
        traceWarn() << "Failed to get parameter: " << CT_STATUS_YPOWER;

    res = ecUtils.ReadFromXML(statusData, 0, CT_STATUS_INTERLOCK, "", data);
    if (res) status.setInterlock(QString(data).toInt(nullptr, 16)); else traceWarn() << "Failed to get parameter: " << CT_STATUS_INTERLOCK;

    res = ecUtils.ReadFromXML(statusData, 0, CT_STATUS_CURRENTDIO, "", data);
    if (res) status.setCurrentDIO(QString(data).toInt(nullptr, 16)); else traceWarn() << "Failed to get parameter: " << CT_STATUS_CURRENTDIO;

    res = ecUtils.ReadFromXML(statusData, 0, CT_STATUS_JOBMARKER, "", data);
    if (res) status.setJobMarker(QString(data).toInt()); else traceWarn() << "Failed to get parameter: " << CT_STATUS_JOBMARKER;

    res = ecUtils.ReadFromXML(statusData, 0, CT_STATUS_JOBDATACNTR, "", data);
    if (res) status.setJobDataCntr(QString(data).toInt()); else traceWarn() << "Failed to get parameter: " << CT_STATUS_JOBDATACNTR;

    traceExit;

}
