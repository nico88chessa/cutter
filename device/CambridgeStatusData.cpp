#include "CambridgeStatusData.hpp"


using namespace PROGRAM_NAMESPACE;


CambridgeStatusData::CambridgeStatusData() {  }

QString CambridgeStatusData::getMsn() const { return msn; }

void CambridgeStatusData::setMsn(const QString& value) { msn = value; }

QString CambridgeStatusData::getPVer() const { return pVer; }

void CambridgeStatusData::setPVer(const QString& value) { pVer = value; }

QString CambridgeStatusData::getAVer() const { return aVer; }

void CambridgeStatusData::setAVer(const QString& value) { aVer = value; }

QString CambridgeStatusData::getObjextVer() const { return objextVer; }

void CambridgeStatusData::setObjextVer(const QString& value) { objextVer = value; }

QString CambridgeStatusData::getFpgaFirmVer() const { return fpgaFirmVer; }

void CambridgeStatusData::setFpgaFirmVer(const QString& value) { fpgaFirmVer = value; }

int CambridgeStatusData::getStateCode() const { return stateCode; }

void CambridgeStatusData::setStateCode(int value) { stateCode = value; }

int CambridgeStatusData::getLastError() const { return lastError; }

void CambridgeStatusData::setLastError(int value) { lastError = value; }

int CambridgeStatusData::getFreeTempStorage() const { return freeTempStorage; }

void CambridgeStatusData::setFreeTempStorage(int value) { freeTempStorage = value; }

QString CambridgeStatusData::getPermStoragePath() const { return permStoragePath; }

void CambridgeStatusData::setPermStoragePath(const QString& value) { permStoragePath = value; }

int CambridgeStatusData::getFreePermStorage() const { return freePermStorage; }

void CambridgeStatusData::setFreePermStorage(int value) { freePermStorage = value; }

int CambridgeStatusData::getFreeUsbStorage() const { return freeUsbStorage; }

void CambridgeStatusData::setFreeUsbStorage(int value) { freeUsbStorage = value; }

QString CambridgeStatusData::getMac() const { return mac; }

void CambridgeStatusData::setMac(const QString& value) { mac = value; }

QString CambridgeStatusData::getNetmask() const { return netmask; }

void CambridgeStatusData::setNetmask(const QString& value) { netmask = value; }

QString CambridgeStatusData::getNetassign() const { return netassign; }

void CambridgeStatusData::setNetassign(const QString& value) { netassign = value; }

QString CambridgeStatusData::getIp() const { return ip; }

void CambridgeStatusData::setIp(const QString& value) { ip = value; }

QString CambridgeStatusData::getConnectIp() const { return connectIp; }

void CambridgeStatusData::setConnectIp(const QString& value) { connectIp = value; }

QString CambridgeStatusData::getFriendlyName() const { return friendlyName; }

void CambridgeStatusData::setFriendlyName(const QString& value) { friendlyName = value; }

QString CambridgeStatusData::getConnectJob() const { return connectJob; }

void CambridgeStatusData::setConnectJob(const QString& value) { connectJob = value; }

int CambridgeStatusData::getPort() const { return port; }

void CambridgeStatusData::setPort(int value) { port = value; }

int CambridgeStatusData::getHsn() const { return hsn; }

void CambridgeStatusData::setHsn(int value) { hsn = value; }

bool CambridgeStatusData::getXPosAck() const { return xPosAck; }

void CambridgeStatusData::setXPosAck(bool value) { xPosAck = value; }

bool CambridgeStatusData::getYPosAck() const { return yPosAck; }

void CambridgeStatusData::setYPosAck(bool value) { yPosAck = value; }

int CambridgeStatusData::getXPos() const { return xPos; }

void CambridgeStatusData::setXPos(int value) { xPos = value; }

int CambridgeStatusData::getYPos() const { return yPos; }

void CambridgeStatusData::setYPos(int value) { yPos = value; }

int CambridgeStatusData::getXActPos() const { return xActPos; }

void CambridgeStatusData::setXActPos(int value) { xActPos = value; }

int CambridgeStatusData::getYActPos() const { return yActPos; }

void CambridgeStatusData::setYActPos(int value) { yActPos = value; }

bool CambridgeStatusData::getXTemp() const { return xTemp; }

void CambridgeStatusData::setXTemp(bool value) { xTemp = value; }

bool CambridgeStatusData::getYTemp() const { return yTemp; }

void CambridgeStatusData::setYTemp(bool value) { yTemp = value; }

int CambridgeStatusData::getContrlTemp() const { return contrlTemp; }

void CambridgeStatusData::setContrlTemp(int value) { contrlTemp = value; }

int CambridgeStatusData::getXStatus() const { return xStatus; }

void CambridgeStatusData::setXStatus(int value) { xStatus = value; }

int CambridgeStatusData::getYStatus() const { return yStatus; }

void CambridgeStatusData::setYStatus(int value) { yStatus = value; }

bool CambridgeStatusData::getXPower() const { return xPower; }

void CambridgeStatusData::setXPower(bool value) { xPower = value; }

bool CambridgeStatusData::getYPower() const { return yPower; }

void CambridgeStatusData::setYPower(bool value) { yPower = value; }

int CambridgeStatusData::getInterlock() const { return interlock; }

void CambridgeStatusData::setInterlock(int value) { interlock = value; }

int CambridgeStatusData::getCurrentDIO() const { return currentDIO; }

void CambridgeStatusData::setCurrentDIO(int value) { currentDIO = value; }

int CambridgeStatusData::getJobMarker() const { return jobMarker; }

void CambridgeStatusData::setJobMarker(int value) { jobMarker = value; }

int CambridgeStatusData::getJobDataCntr() const { return jobDataCntr; }

void CambridgeStatusData::setJobDataCntr(int value) { jobDataCntr = value; }
