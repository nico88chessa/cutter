#ifndef CAMBRIDGESTATUSDATA_HPP
#define CAMBRIDGESTATUSDATA_HPP

#include <QObject>
#include <QString>

#include <configure.h>


namespace PROGRAM_NAMESPACE {

class CambridgeStatusData {
public:
    CambridgeStatusData();

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
    int jobMarker;
    int jobDataCntr;
};

}

Q_DECLARE_METATYPE(PROGRAM_NAMESPACE::CambridgeStatusData);


#endif // CAMBRIDGESTATUSDATA_HPP
