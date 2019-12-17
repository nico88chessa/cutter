#ifndef SYSTEMSTATUSDATA_HPP
#define SYSTEMSTATUSDATA_HPP

#include <QObject>

#include <configure.h>


namespace PROGRAM_NAMESPACE {

class CambridgeStatusData;

class SystemStatusData : public QObject {
    Q_OBJECT

    Q_PROPERTY(QString pMsn READ getMsn WRITE setMsn NOTIFY smcStatusUpdate)
    Q_PROPERTY(QString pPVer READ getPVer WRITE setPVer NOTIFY smcStatusUpdate)
    Q_PROPERTY(QString pAVer READ getAVer WRITE setAVer NOTIFY smcStatusUpdate)
    Q_PROPERTY(QString pObjextVer READ getObjextVer WRITE setObjextVer NOTIFY smcStatusUpdate)
    Q_PROPERTY(QString pFpgaFirmVer READ getFpgaFirmVer WRITE setFpgaFirmVer NOTIFY smcStatusUpdate)
    Q_PROPERTY(int pStateCode READ getStateCode WRITE setStateCode NOTIFY smcStatusUpdate)
    Q_PROPERTY(int pLastError READ getLastError WRITE setLastError NOTIFY smcStatusUpdate)
    Q_PROPERTY(int pFreeTempStorage READ getFreeTempStorage WRITE setFreeTempStorage NOTIFY smcStatusUpdate)
    Q_PROPERTY(QString pPermStoragePath READ getPermStoragePath WRITE setPermStoragePath NOTIFY smcStatusUpdate)
    Q_PROPERTY(int pFreePermStorage READ getFreePermStorage WRITE setFreePermStorage NOTIFY smcStatusUpdate)
    Q_PROPERTY(int pFreeUsbStorage READ getFreeUsbStorage WRITE setFreeUsbStorage NOTIFY smcStatusUpdate)
    Q_PROPERTY(QString pMac READ getMac WRITE setMac NOTIFY smcStatusUpdate)
    Q_PROPERTY(QString pNetmask READ getNetmask WRITE setNetmask NOTIFY smcStatusUpdate)
    Q_PROPERTY(QString pNetassign READ getNetassign WRITE setNetassign NOTIFY smcStatusUpdate)
    Q_PROPERTY(QString pIp READ getIp WRITE setIp NOTIFY smcStatusUpdate)
    Q_PROPERTY(QString pConnectIp READ getConnectIp WRITE setConnectIp NOTIFY smcStatusUpdate)
    Q_PROPERTY(QString pFriendlyName READ getFriendlyName WRITE setFriendlyName NOTIFY smcStatusUpdate)
    Q_PROPERTY(QString pConnectJob READ getConnectJob WRITE setConnectJob NOTIFY smcStatusUpdate)
    Q_PROPERTY(int pPort READ getPort WRITE setPort NOTIFY smcStatusUpdate)
    Q_PROPERTY(int pHsn READ getHsn WRITE setHsn NOTIFY smcStatusUpdate)

    Q_PROPERTY(bool pXPosAck READ getXPosAck WRITE setXPosAck NOTIFY smcStatusUpdate)
    Q_PROPERTY(bool pYPosAck READ getYPosAck WRITE setYPosAck NOTIFY smcStatusUpdate)
    Q_PROPERTY(int pXPos READ getXPos WRITE setXPos NOTIFY smcStatusUpdate)
    Q_PROPERTY(int pYPos READ getYPos WRITE setYPos NOTIFY smcStatusUpdate)
    Q_PROPERTY(int pXActPos READ getXActPos WRITE setXActPos NOTIFY smcStatusUpdate)
    Q_PROPERTY(int pYActPos READ getYActPos WRITE setYActPos NOTIFY smcStatusUpdate)
    Q_PROPERTY(bool pXTemp READ getXTemp WRITE setXTemp NOTIFY smcStatusUpdate)
    Q_PROPERTY(bool pYTemp READ getYTemp WRITE setYTemp NOTIFY smcStatusUpdate)
    Q_PROPERTY(int pContrlTemp READ getContrlTemp WRITE setContrlTemp NOTIFY smcStatusUpdate)
    Q_PROPERTY(int pXStatus READ getXStatus WRITE setXStatus NOTIFY smcStatusUpdate)
    Q_PROPERTY(int pYStatus READ getYStatus WRITE setYStatus NOTIFY smcStatusUpdate)
    Q_PROPERTY(bool pXPower READ getXPower WRITE setXPower NOTIFY smcStatusUpdate)
    Q_PROPERTY(bool pYPower READ getYPower WRITE setYPower NOTIFY smcStatusUpdate)
    Q_PROPERTY(int pInterlock READ getInterlock WRITE setInterlock NOTIFY smcStatusUpdate)
    Q_PROPERTY(int pCurrentDIO READ getCurrentDIO WRITE setCurrentDIO NOTIFY smcStatusUpdate)

    Q_PROPERTY(bool pAuxGPI1 READ getAuxGPI1 WRITE setAuxGPI1 NOTIFY smcStatusUpdate)
    Q_PROPERTY(bool pAuxGPI2 READ getAuxGPI2 WRITE setAuxGPI2 NOTIFY smcStatusUpdate)
    Q_PROPERTY(bool pAuxGPI3 READ getAuxGPI3 WRITE setAuxGPI3 NOTIFY smcStatusUpdate)
    Q_PROPERTY(bool pAuxGPI4 READ getAuxGPI4 WRITE setAuxGPI4 NOTIFY smcStatusUpdate)
    Q_PROPERTY(bool pAuxStart READ getAuxStart WRITE setAuxStart NOTIFY smcStatusUpdate)
    Q_PROPERTY(bool pStart READ getStart WRITE setStart NOTIFY smcStatusUpdate)
    Q_PROPERTY(bool pInterlock1 READ getInterlock1 WRITE setInterlock1 NOTIFY smcStatusUpdate)
    Q_PROPERTY(bool pInterlock2 READ getInterlock2 WRITE setInterlock2 NOTIFY smcStatusUpdate)
    Q_PROPERTY(bool pInterlock3 READ getInterlock3 WRITE setInterlock3 NOTIFY smcStatusUpdate)
    Q_PROPERTY(bool pInterlock4 READ getInterlock4 WRITE setInterlock4 NOTIFY smcStatusUpdate)
    Q_PROPERTY(bool pAuxGPO1 READ getAuxGPO1 WRITE setAuxGPO1 NOTIFY smcStatusUpdate)
    Q_PROPERTY(bool pAuxGPO2 READ getAuxGPO2 WRITE setAuxGPO2 NOTIFY smcStatusUpdate)
    Q_PROPERTY(bool pAuxGPO3 READ getAuxGPO3 WRITE setAuxGPO3 NOTIFY smcStatusUpdate)
    Q_PROPERTY(bool pAuxGPO4 READ getAuxGPO4 WRITE setAuxGPO4 NOTIFY smcStatusUpdate)
    Q_PROPERTY(bool pJobactive READ getJobactive WRITE setJobactive NOTIFY smcStatusUpdate)
    Q_PROPERTY(bool pErrorNready READ getErrorNready WRITE setErrorNready NOTIFY smcStatusUpdate)
    Q_PROPERTY(bool pBusy READ getBusy WRITE setBusy NOTIFY smcStatusUpdate)
    Q_PROPERTY(bool pLasing READ getLasing WRITE setLasing NOTIFY smcStatusUpdate)

    Q_PROPERTY(int pJobMarker READ getJobMarker WRITE setJobMarker NOTIFY smcStatusUpdate)
    Q_PROPERTY(int pJobDataCntr READ getJobDataCntr WRITE setJobDataCntr NOTIFY smcStatusUpdate)

public:
    using Ptr = SystemStatusData*;
    using ConstPtr = const SystemStatusData*;

public:
    explicit SystemStatusData(QObject* parent = Q_NULLPTR);

private:
    // system information parameters
    QString msn;
    QString pVer;
    QString aVer;
    QString objextVer;
    QString fpgaFirmVer;
    int stateCode;
    int lastError;
    int freeTempStorage;
    QString permStoragePath;
    int freePermStorage;
    int freeUsbStorage;
    QString mac;
    QString netmask;
    QString netassign;
    QString ip;
    QString connectIp;
    QString friendlyName;
    QString connectJob;
    int port;
    int hsn;

    // status information parameters
    bool xPosAck;
    bool yPosAck;
    int xPos;
    int yPos;
    int xActPos;
    int yActPos;
    bool xTemp;
    bool yTemp;
    int contrlTemp;
    int xStatus;
    int yStatus;
    bool xPower;
    bool yPower;
    int interlock;
    int currentDIO;

    bool auxGPI1;
    bool auxGPI2;
    bool auxGPI3;
    bool auxGPI4;
    bool auxStart;
    bool start;
    bool interlock1;
    bool interlock2;
    bool interlock3;
    bool interlock4;
    bool auxGPO1;
    bool auxGPO2;
    bool auxGPO3;
    bool auxGPO4;
    bool jobactive;
    bool errorNready;
    bool busy;
    bool lasing;

    int jobMarker;
    int jobDataCntr;

public:
    QString getMsn() const;
    void setMsn(const QString& value);

    QString getPVer() const;
    void setPVer(const QString& value);

    QString getAVer() const;
    void setAVer(const QString& value);

    QString getObjextVer() const;
    void setObjextVer(const QString& value);

    QString getFpgaFirmVer() const;
    void setFpgaFirmVer(const QString& value);

    int getStateCode() const;
    void setStateCode(int value);

    int getLastError() const;
    void setLastError(int value);

    int getFreeTempStorage() const;
    void setFreeTempStorage(int value);

    QString getPermStoragePath() const;
    void setPermStoragePath(const QString& value);

    int getFreePermStorage() const;
    void setFreePermStorage(int value);

    int getFreeUsbStorage() const;
    void setFreeUsbStorage(int value);

    QString getMac() const;
    void setMac(const QString& value);

    QString getNetmask() const;
    void setNetmask(const QString& value);

    QString getNetassign() const;
    void setNetassign(const QString& value);

    QString getIp() const;
    void setIp(const QString& value);

    QString getConnectIp() const;
    void setConnectIp(const QString& value);

    QString getFriendlyName() const;
    void setFriendlyName(const QString& value);

    QString getConnectJob() const;
    void setConnectJob(const QString& value);

    int getPort() const;
    void setPort(int value);

    int getHsn() const;
    void setHsn(int value);

    bool getXPosAck() const;
    void setXPosAck(bool value);

    bool getYPosAck() const;
    void setYPosAck(bool value);

    int getXPos() const;
    void setXPos(int value);

    int getYPos() const;
    void setYPos(int value);

    int getXActPos() const;
    void setXActPos(int value);

    int getYActPos() const;
    void setYActPos(int value);

    bool getXTemp() const;
    void setXTemp(bool value);

    bool getYTemp() const;
    void setYTemp(bool value);

    int getContrlTemp() const;
    void setContrlTemp(int value);

    int getXStatus() const;
    void setXStatus(int value);

    int getYStatus() const;
    void setYStatus(int value);

    bool getXPower() const;
    void setXPower(bool value);

    bool getYPower() const;
    void setYPower(bool value);

    int getInterlock() const;
    void setInterlock(int value);

    int getCurrentDIO() const;
    void setCurrentDIO(int value);

    int getJobMarker() const;
    void setJobMarker(int value);

    int getJobDataCntr() const;
    void setJobDataCntr(int value);

    bool getAuxGPI1() const;
    void setAuxGPI1(bool value);

    bool getAuxGPI2() const;
    void setAuxGPI2(bool value);

    bool getAuxGPI3() const;
    void setAuxGPI3(bool value);

    bool getAuxGPI4() const;
    void setAuxGPI4(bool value);

    bool getAuxStart() const;
    void setAuxStart(bool value);

    bool getStart() const;
    void setStart(bool value);

    bool getInterlock1() const;
    void setInterlock1(bool value);

    bool getInterlock2() const;
    void setInterlock2(bool value);

    bool getInterlock3() const;
    void setInterlock3(bool value);

    bool getInterlock4() const;
    void setInterlock4(bool value);

    bool getAuxGPO1() const;
    void setAuxGPO1(bool value);

    bool getAuxGPO2() const;
    void setAuxGPO2(bool value);

    bool getAuxGPO3() const;
    void setAuxGPO3(bool value);

    bool getAuxGPO4() const;
    void setAuxGPO4(bool value);

    bool getJobactive() const;
    void setJobactive(bool value);

    bool getErrorNready() const;
    void setErrorNready(bool value);

    bool getBusy() const;
    void setBusy(bool value);

    bool getLasing() const;
    void setLasing(bool value);

    void updateCambridgeStatus(const CambridgeStatusData& status);

signals:
    void smcStatusUpdate();
};

}

#endif // SYSTEMSTATUSDATA_HPP
