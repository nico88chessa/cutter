#include "SystemStatusData.hpp"

#include <CambridgeStatusData.hpp>
#include <Types.hpp>
#include <Logger.hpp>

using namespace PROGRAM_NAMESPACE;

SystemStatusData::SystemStatusData(QObject* parent) :
    QObject(parent) {

    emit smcStatusUpdate();

}

bool SystemStatusData::getLasing() const { return lasing; }

void SystemStatusData::setLasing(bool value) { lasing = value; }

void SystemStatusData::updateCambridgeStatus(const CambridgeStatusData& status) {

    traceEnter;

    this->setMsn(status.getMsn());
    this->setPVer(status.getPVer());
    this->setAVer(status.getAVer());
    this->setObjextVer(status.getObjextVer());
    this->setFpgaFirmVer(status.getFpgaFirmVer());
    this->setStateCode(status.getStateCode());
    this->setLastError(status.getLastError());
    this->setFreeTempStorage(status.getFreeTempStorage());
    this->setPermStoragePath(status.getPermStoragePath());
    this->setFreePermStorage(status.getFreePermStorage());
    this->setFreeUsbStorage(status.getFreeUsbStorage());
    this->setMac(status.getMac());
    this->setNetmask(status.getNetmask());
    this->setNetassign(status.getNetassign());
    this->setIp(status.getIp());
    this->setConnectIp(status.getConnectIp());
    this->setFriendlyName(status.getFriendlyName());
    this->setConnectJob(status.getConnectJob());
    this->setPort(status.getPort());
    this->setHsn(status.getHsn());

    this->setXPosAck(status.getXPosAck());
    this->setYPosAck(status.getYPosAck());
    this->setXPos(status.getXPos());
    this->setYPos(status.getYPos());
    this->setXActPos(status.getXActPos());
    this->setYActPos(status.getYActPos());
    this->setXTemp(status.getXTemp());
    this->setYTemp(status.getYTemp());
    this->setContrlTemp(status.getContrlTemp());
    this->setXStatus(status.getXStatus());
    this->setYStatus(status.getYStatus());
    this->setXPower(status.getXPower());
    this->setYPower(status.getYPower());
    this->setInterlock(status.getInterlock());
    this->setJobMarker(status.getJobMarker());
    this->setJobDataCntr(status.getJobDataCntr());
    this->setCurrentDIO(status.getCurrentDIO());

    int currentIO = status.getCurrentDIO();

    this->setAuxGPI1((currentIO & static_cast<int>(CurrentDIO_Mask::AUX_GPI1)) >> static_cast<int>(CurrentDIO_Order::AUX_GPI1));
    this->setAuxGPI2((currentIO & static_cast<int>(CurrentDIO_Mask::AUX_GPI2)) >> static_cast<int>(CurrentDIO_Order::AUX_GPI2));
    this->setAuxGPI3((currentIO & static_cast<int>(CurrentDIO_Mask::AUX_GPI3)) >> static_cast<int>(CurrentDIO_Order::AUX_GPI3));
    this->setAuxGPI4((currentIO & static_cast<int>(CurrentDIO_Mask::AUX_GPI4)) >> static_cast<int>(CurrentDIO_Order::AUX_GPI4));
    this->setAuxStart((currentIO &static_cast<int>(CurrentDIO_Mask::AUX_START)) >> static_cast<int>(CurrentDIO_Order::AUX_START));
    this->setStart((currentIO & static_cast<int>(CurrentDIO_Mask::START)) >> static_cast<int>(CurrentDIO_Order::START));
    this->setInterlock1((currentIO & static_cast<int>(CurrentDIO_Mask::INTERLOCK1)) >> static_cast<int>(CurrentDIO_Order::INTERLOCK1));
    this->setInterlock2((currentIO & static_cast<int>(CurrentDIO_Mask::INTERLOCK2)) >> static_cast<int>(CurrentDIO_Order::INTERLOCK2));
    this->setInterlock3((currentIO & static_cast<int>(CurrentDIO_Mask::INTERLOCK3)) >> static_cast<int>(CurrentDIO_Order::INTERLOCK3));
    this->setInterlock4((currentIO & static_cast<int>(CurrentDIO_Mask::INTERLOCK4)) >> static_cast<int>(CurrentDIO_Order::INTERLOCK4));
    this->setAuxGPO1((currentIO & static_cast<int>(CurrentDIO_Mask::AUX_GPO1)) >> static_cast<int>(CurrentDIO_Order::AUX_GPO1));
    this->setAuxGPO2((currentIO & static_cast<int>(CurrentDIO_Mask::AUX_GPO2)) >> static_cast<int>(CurrentDIO_Order::AUX_GPO2));
    this->setAuxGPO3((currentIO & static_cast<int>(CurrentDIO_Mask::AUX_GPO3)) >> static_cast<int>(CurrentDIO_Order::AUX_GPO3));
    this->setAuxGPO4((currentIO & static_cast<int>(CurrentDIO_Mask::AUX_GPO4)) >> static_cast<int>(CurrentDIO_Order::AUX_GPO4));
    this->setJobactive((currentIO &static_cast<int>(CurrentDIO_Mask::JOBACTIVE)) >> static_cast<int>(CurrentDIO_Order::JOBACTIVE));
    this->setErrorNready((currentIO & static_cast<int>(CurrentDIO_Mask::ERROR_NREADY)) >> static_cast<int>(CurrentDIO_Order::ERROR_NREADY));
    this->setBusy((currentIO &    static_cast<int>(CurrentDIO_Mask::BUSY)) >>    static_cast<int>(CurrentDIO_Order::BUSY));
    this->setLasing((currentIO &  static_cast<int>(CurrentDIO_Mask::LASING)) >>  static_cast<int>(CurrentDIO_Order::LASING));

    emit smcStatusUpdate();

    traceExit;

}

bool SystemStatusData::getBusy() const { return busy; }

void SystemStatusData::setBusy(bool value) { busy = value; }

bool SystemStatusData::getErrorNready() const { return errorNready; }

void SystemStatusData::setErrorNready(bool value) { errorNready = value; }

bool SystemStatusData::getJobactive() const { return jobactive; }

void SystemStatusData::setJobactive(bool value) { jobactive = value; }

bool SystemStatusData::getAuxGPO4() const { return auxGPO4; }

void SystemStatusData::setAuxGPO4(bool value) { auxGPO4 = value; }

bool SystemStatusData::getAuxGPO3() const { return auxGPO3; }

void SystemStatusData::setAuxGPO3(bool value) { auxGPO3 = value; }

bool SystemStatusData::getAuxGPO2() const { return auxGPO2; }

void SystemStatusData::setAuxGPO2(bool value) { auxGPO2 = value; }

bool SystemStatusData::getAuxGPO1() const { return auxGPO1; }

void SystemStatusData::setAuxGPO1(bool value) { auxGPO1 = value; }

bool SystemStatusData::getInterlock4() const { return interlock4; }

void SystemStatusData::setInterlock4(bool value) { interlock4 = value; }

bool SystemStatusData::getInterlock3() const { return interlock3; }

void SystemStatusData::setInterlock3(bool value) { interlock3 = value; }

bool SystemStatusData::getInterlock2() const { return interlock2; }

void SystemStatusData::setInterlock2(bool value) { interlock2 = value; }

bool SystemStatusData::getInterlock1() const { return interlock1; }

void SystemStatusData::setInterlock1(bool value) { interlock1 = value; }

bool SystemStatusData::getStart() const { return start; }

void SystemStatusData::setStart(bool value) { start = value; }

bool SystemStatusData::getAuxStart() const { return auxStart; }

void SystemStatusData::setAuxStart(bool value) { auxStart = value; }

bool SystemStatusData::getAuxGPI4() const { return auxGPI4; }

void SystemStatusData::setAuxGPI4(bool value) { auxGPI4 = value; }

bool SystemStatusData::getAuxGPI3() const { return auxGPI3; }

void SystemStatusData::setAuxGPI3(bool value) { auxGPI3 = value; }

bool SystemStatusData::getAuxGPI2() const { return auxGPI2; }

void SystemStatusData::setAuxGPI2(bool value) { auxGPI2 = value; }

bool SystemStatusData::getAuxGPI1() const { return auxGPI1; }

void SystemStatusData::setAuxGPI1(bool value) { auxGPI1 = value; }

 QString SystemStatusData::getMsn() const { return msn; }

void SystemStatusData::setMsn(const QString& value) { msn = value; }

QString SystemStatusData::getPVer() const { return pVer; }

void SystemStatusData::setPVer(const QString& value) { pVer = value; }

QString SystemStatusData::getAVer() const { return aVer; }

void SystemStatusData::setAVer(const QString& value) { aVer = value; }

QString SystemStatusData::getObjextVer() const { return objextVer; }

void SystemStatusData::setObjextVer(const QString& value) { objextVer = value; }

QString SystemStatusData::getFpgaFirmVer() const { return fpgaFirmVer; }

void SystemStatusData::setFpgaFirmVer(const QString& value) { fpgaFirmVer = value; }

int SystemStatusData::getStateCode() const { return stateCode; }

void SystemStatusData::setStateCode(int value) { stateCode = value; }

int SystemStatusData::getLastError() const { return lastError; }

void SystemStatusData::setLastError(int value) { lastError = value; }

int SystemStatusData::getFreeTempStorage() const { return freeTempStorage; }

void SystemStatusData::setFreeTempStorage(int value) { freeTempStorage = value; }

QString SystemStatusData::getPermStoragePath() const { return permStoragePath; }

void SystemStatusData::setPermStoragePath(const QString& value) { permStoragePath = value; }

int SystemStatusData::getFreePermStorage() const { return freePermStorage; }

void SystemStatusData::setFreePermStorage(int value) { freePermStorage = value; }

int SystemStatusData::getFreeUsbStorage() const { return freeUsbStorage; }

void SystemStatusData::setFreeUsbStorage(int value) { freeUsbStorage = value; }

QString SystemStatusData::getMac() const { return mac; }

void SystemStatusData::setMac(const QString& value) { mac = value; }

QString SystemStatusData::getNetmask() const { return netmask; }

void SystemStatusData::setNetmask(const QString& value) { netmask = value; }

QString SystemStatusData::getNetassign() const { return netassign; }

void SystemStatusData::setNetassign(const QString& value) { netassign = value; }

QString SystemStatusData::getIp() const { return ip; }

void SystemStatusData::setIp(const QString& value) { ip = value; }

QString SystemStatusData::getConnectIp() const { return connectIp; }

void SystemStatusData::setConnectIp(const QString& value) { connectIp = value; }

QString SystemStatusData::getFriendlyName() const { return friendlyName; }

void SystemStatusData::setFriendlyName(const QString& value) { friendlyName = value; }

QString SystemStatusData::getConnectJob() const { return connectJob; }

void SystemStatusData::setConnectJob(const QString& value) { connectJob = value; }

int SystemStatusData::getPort() const { return port; }

void SystemStatusData::setPort(int value) { port = value; }

int SystemStatusData::getHsn() const { return hsn; }

void SystemStatusData::setHsn(int value) { hsn = value; }

bool SystemStatusData::getXPosAck() const { return xPosAck; }

void SystemStatusData::setXPosAck(bool value) { xPosAck = value; }

bool SystemStatusData::getYPosAck() const { return yPosAck; }

void SystemStatusData::setYPosAck(bool value) { yPosAck = value; }

int SystemStatusData::getXPos() const { return xPos; }

void SystemStatusData::setXPos(int value) { xPos = value; }

int SystemStatusData::getYPos() const { return yPos; }

void SystemStatusData::setYPos(int value) { yPos = value; }

int SystemStatusData::getXActPos() const { return xActPos; }

void SystemStatusData::setXActPos(int value) { xActPos = value; }

int SystemStatusData::getYActPos() const { return yActPos; }

void SystemStatusData::setYActPos(int value) { yActPos = value; }

bool SystemStatusData::getXTemp() const { return xTemp; }

void SystemStatusData::setXTemp(bool value) { xTemp = value; }

bool SystemStatusData::getYTemp() const { return yTemp; }

void SystemStatusData::setYTemp(bool value) { yTemp = value; }

int SystemStatusData::getContrlTemp() const { return contrlTemp; }

void SystemStatusData::setContrlTemp(int value) { contrlTemp = value; }

int SystemStatusData::getXStatus() const { return xStatus; }

void SystemStatusData::setXStatus(int value) { xStatus = value; }

int SystemStatusData::getYStatus() const { return yStatus; }

void SystemStatusData::setYStatus(int value) { yStatus = value; }

bool SystemStatusData::getXPower() const { return xPower; }

void SystemStatusData::setXPower(bool value) { xPower = value; }

bool SystemStatusData::getYPower() const { return yPower; }

void SystemStatusData::setYPower(bool value) { yPower = value; }

int SystemStatusData::getInterlock() const { return interlock; }

int SystemStatusData::getCurrentDIO() const { return currentDIO; }

void SystemStatusData::setCurrentDIO(int value) { currentDIO = value; }

void SystemStatusData::setInterlock(int value) { interlock = value; }

int SystemStatusData::getJobMarker() const { return jobMarker; }

void SystemStatusData::setJobMarker(int value) { jobMarker = value; }

int SystemStatusData::getJobDataCntr() const { return jobDataCntr; }

void SystemStatusData::setJobDataCntr(int value) { jobDataCntr = value; }
