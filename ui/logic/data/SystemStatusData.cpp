#include "SystemStatusData.hpp"

using namespace PROGRAM_NAMESPACE;

SystemStatusData::SystemStatusData(QObject* parent) :
    QObject(parent) { }


QString SystemStatusData::getMsn() const {
    return msn;
}

void SystemStatusData::setMsn(const QString& value) {
    msn = value;
}

QString SystemStatusData::getPVer() const {
    return pVer;
}

void SystemStatusData::setPVer(const QString& value) {
    pVer = value;
}

QString SystemStatusData::getAVer() const {
    return aVer;
}

void SystemStatusData::setAVer(const QString& value) {
    aVer = value;
}

QString SystemStatusData::getObjextVer() const {
    return objextVer;
}

void SystemStatusData::setObjextVer(const QString& value) {
    objextVer = value;
}

QString SystemStatusData::getFpgaFirmVer() const {
    return fpgaFirmVer;
}

void SystemStatusData::setFpgaFirmVer(const QString& value) {
    fpgaFirmVer = value;
}

int SystemStatusData::getStateCode() const {
    return stateCode;
}

void SystemStatusData::setStateCode(int value) {
    stateCode = value;
}

int SystemStatusData::getLastError() const {
    return lastError;
}

void SystemStatusData::setLastError(int value) {
    lastError = value;
}

int SystemStatusData::getFreeTempStorage() const {
    return freeTempStorage;
}

void SystemStatusData::setFreeTempStorage(int value) {
    freeTempStorage = value;
}

QString SystemStatusData::getPermStoragePath() const {
    return permStoragePath;
}

void SystemStatusData::setPermStoragePath(const QString& value) {
    permStoragePath = value;
}

int SystemStatusData::getFreePermStorage() const {
    return freePermStorage;
}

void SystemStatusData::setFreePermStorage(int value) {
    freePermStorage = value;
}

int SystemStatusData::getFreeUsbStorage() const {
    return freeUsbStorage;
}

void SystemStatusData::setFreeUsbStorage(int value) {
    freeUsbStorage = value;
}

QString SystemStatusData::getMac() const {
    return mac;
}

void SystemStatusData::setMac(const QString& value) {
    mac = value;
}

QString SystemStatusData::getNetmask() const {
    return netmask;
}

void SystemStatusData::setNetmask(const QString& value) {
    netmask = value;
}

QString SystemStatusData::getNetassign() const {
    return netassign;
}

void SystemStatusData::setNetassign(const QString& value) {
    netassign = value;
}

QString SystemStatusData::getIp() const {
    return ip;
}

void SystemStatusData::setIp(const QString& value) {
    ip = value;
}

QString SystemStatusData::getConnectIp() const {
    return connectIp;
}

void SystemStatusData::setConnectIp(const QString& value) {
    connectIp = value;
}

QString SystemStatusData::getFriendlyName() const {
    return friendlyName;
}

void SystemStatusData::setFriendlyName(const QString& value) {
    friendlyName = value;
}

QString SystemStatusData::getConnectJob() const {
    return connectJob;
}

void SystemStatusData::setConnectJob(const QString& value) {
    connectJob = value;
}

int SystemStatusData::getPort() const {
    return port;
}

void SystemStatusData::setPort(int value) {
    port = value;
}

int SystemStatusData::getHsn() const {
    return hsn;
}

void SystemStatusData::setHsn(int value) {
    hsn = value;
}

bool SystemStatusData::getXPosAck() const {
    return xPosAck;
}

void SystemStatusData::setXPosAck(bool value) {
    xPosAck = value;
}

bool SystemStatusData::getYPosAck() const {
    return yPosAck;
}

void SystemStatusData::setYPosAck(bool value) {
    yPosAck = value;
}

int SystemStatusData::getXPos() const {
    return xPos;
}

void SystemStatusData::setXPos(int value) {
    xPos = value;
}

int SystemStatusData::getYPos() const {
    return yPos;
}

void SystemStatusData::setYPos(int value) {
    yPos = value;
}

int SystemStatusData::getXActPos() const {
    return xActPos;
}

void SystemStatusData::setXActPos(int value) {
    xActPos = value;
}

int SystemStatusData::getYActPos() const {
    return yActPos;
}

void SystemStatusData::setYActPos(int value) {
    yActPos = value;
}

bool SystemStatusData::getXTemp() const {
    return xTemp;
}

void SystemStatusData::setXTemp(bool value) {
    xTemp = value;
}

bool SystemStatusData::getYTemp() const {
    return yTemp;
}

void SystemStatusData::setYTemp(bool value) {
    yTemp = value;
}

int SystemStatusData::getContrlTemp() const {
    return contrlTemp;
}

void SystemStatusData::setContrlTemp(int value) {
    contrlTemp = value;
}

int SystemStatusData::getXStatus() const {
    return xStatus;
}

void SystemStatusData::setXStatus(int value) {
    xStatus = value;
}

int SystemStatusData::getYStatus() const {
    return yStatus;
}

void SystemStatusData::setYStatus(int value) {
    yStatus = value;
}

bool SystemStatusData::getXPower() const {
    return xPower;
}

void SystemStatusData::setXPower(bool value) {
    xPower = value;
}

bool SystemStatusData::getYPower() const {
    return yPower;
}

void SystemStatusData::setYPower(bool value) {
    yPower = value;
}

int SystemStatusData::getInterlock() const {
    return interlock;
}

void SystemStatusData::setInterlock(int value) {
    interlock = value;
}

int SystemStatusData::getCurrentDIO() const {
    return currentDIO;
}

void SystemStatusData::setCurrentDIO(int value) {
    currentDIO = value;
}

int SystemStatusData::getJobMarker() const {
    return jobMarker;
}

void SystemStatusData::setJobMarker(int value) {
    jobMarker = value;
}

int SystemStatusData::getJobDataCntr() const {
    return jobDataCntr;
}

void SystemStatusData::setJobDataCntr(int value) {
    jobDataCntr = value;
}
