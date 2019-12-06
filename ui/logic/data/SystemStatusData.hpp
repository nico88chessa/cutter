#ifndef SYSTEMSTATUSDATA_HPP
#define SYSTEMSTATUSDATA_HPP

#include <QObject>

#include <configure.h>


namespace PROGRAM_NAMESPACE {

class SystemStatusData : public QObject {
    Q_OBJECT

    Q_PROPERTY(QString msn READ getMsn WRITE setMsn NOTIFY smcStatusUpdate)
    Q_PROPERTY(QString pVer READ getPVer WRITE setPVer NOTIFY smcStatusUpdate)
    Q_PROPERTY(QString aVer READ getAVer WRITE setAVer NOTIFY smcStatusUpdate)
    Q_PROPERTY(QString objextVer READ getObjextVer WRITE setObjextVer NOTIFY smcStatusUpdate)
    Q_PROPERTY(QString fpgaFirmVer READ getFpgaFirmVer WRITE setFpgaFirmVer NOTIFY smcStatusUpdate)
    Q_PROPERTY(int stateCode READ getStateCode WRITE setStateCode NOTIFY smcStatusUpdate)
    Q_PROPERTY(int lastError READ getLastError WRITE setLastError NOTIFY smcStatusUpdate)
    Q_PROPERTY(int freeTempStorage READ getFreeTempStorage WRITE setFreeTempStorage NOTIFY smcStatusUpdate)
    Q_PROPERTY(QString permStoragePath READ getPermStoragePath WRITE setPermStoragePath NOTIFY smcStatusUpdate)
    Q_PROPERTY(int freePermStorage READ getFreePermStorage WRITE setFreePermStorage NOTIFY smcStatusUpdate)
    Q_PROPERTY(int freeUsbStorage READ getFreeUsbStorage WRITE setFreeUsbStorage NOTIFY smcStatusUpdate)
    Q_PROPERTY(QString mac READ getMac WRITE setMac NOTIFY smcStatusUpdate)
    Q_PROPERTY(QString netmask READ getNetmask WRITE setNetmask NOTIFY smcStatusUpdate)
    Q_PROPERTY(QString netassign READ getNetassign WRITE setNetassign NOTIFY smcStatusUpdate)
    Q_PROPERTY(QString ip READ getIp WRITE setIp NOTIFY smcStatusUpdate)
    Q_PROPERTY(QString connectIp READ getConnectIp WRITE setConnectIp NOTIFY smcStatusUpdate)
    Q_PROPERTY(QString friendlyName READ getFriendlyName WRITE setFriendlyName NOTIFY smcStatusUpdate)
    Q_PROPERTY(QString connectJob READ getConnectJob WRITE setConnectJob NOTIFY smcStatusUpdate)
    Q_PROPERTY(int port READ getPort WRITE setPort NOTIFY smcStatusUpdate)
    Q_PROPERTY(int hsn READ getHsn WRITE setHsn NOTIFY smcStatusUpdate)

    Q_PROPERTY(bool xPosAck READ getXPosAck WRITE setXPosAck NOTIFY smcStatusUpdate)
    Q_PROPERTY(bool yPosAck READ getYPosAck WRITE setYPosAck NOTIFY smcStatusUpdate)
    Q_PROPERTY(int xPos READ getXPos WRITE setXPos NOTIFY smcStatusUpdate)
    Q_PROPERTY(int yPos READ getYPos WRITE setYPos NOTIFY smcStatusUpdate)
    Q_PROPERTY(int xActPos READ getXActPos WRITE setXActPos NOTIFY smcStatusUpdate)
    Q_PROPERTY(int yActPos READ getYActPos WRITE setYActPos NOTIFY smcStatusUpdate)
    Q_PROPERTY(bool xTemp READ getXTemp WRITE setXTemp NOTIFY smcStatusUpdate)
    Q_PROPERTY(bool yTemp READ getYTemp WRITE setYTemp NOTIFY smcStatusUpdate)
    Q_PROPERTY(int contrlTemp READ getContrlTemp WRITE setContrlTemp NOTIFY smcStatusUpdate)
    Q_PROPERTY(int xStatus READ getXStatus WRITE setXStatus NOTIFY smcStatusUpdate)
    Q_PROPERTY(int yStatus READ getYStatus WRITE setYStatus NOTIFY smcStatusUpdate)
    Q_PROPERTY(bool xPower READ getXPower WRITE setXPower NOTIFY smcStatusUpdate)
    Q_PROPERTY(bool yPower READ getYPower WRITE setYPower NOTIFY smcStatusUpdate)
    Q_PROPERTY(int interlock READ getInterlock WRITE setInterlock NOTIFY smcStatusUpdate)
    Q_PROPERTY(int currentDIO READ getCurrentDIO WRITE setCurrentDIO NOTIFY smcStatusUpdate)
    Q_PROPERTY(int jobMarker READ getJobMarker WRITE setJobMarker NOTIFY smcStatusUpdate)
    Q_PROPERTY(int jobDataCntr READ getJobDataCntr WRITE setJobDataCntr NOTIFY smcStatusUpdate)

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

signals:
    void smcStatusUpdate();
};

}

#endif // SYSTEMSTATUSDATA_HPP
