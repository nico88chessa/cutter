#ifndef CAMBRIDGEINSPECTOR_HPP
#define CAMBRIDGEINSPECTOR_HPP

#include <configure.h>

#include <QObject>
#include <QTimer>

#include <CTIBroadcastWin32Cls.h>
#include <CTIECUtilsWin32Cls.h>

#include "CambridgeStatusData.hpp"


namespace PROGRAM_NAMESPACE {

class CambridgeStatusData;

class CambridgeInspector : public QObject {
    Q_OBJECT

public:
    using Ptr = CambridgeInspector*;
    using ConstPtr = const CambridgeInspector*;

private:

    static const int CT_DATATYPE_SYSTEM_INFORMATION = 0x01;
    static const int CT_DATATYPE_STATUS_INFORMATION = 0x07;

    bool isConnected;

    QString ipBroadcastAddress;
    quint16 broadcastPort;
    QString localIpAddress;

    int clientId;
    QString friendlyName;

    quint16 restartIntervalMs;
    QTimer refreshTimer;

public:
    explicit CambridgeInspector(QObject *parent = nullptr);
    ~CambridgeInspector();

    bool getIsConnected() const;
    void setIsConnected(bool value);

public slots:
    bool beforeProcess();
    void restartProcess();
    void startProcess();
    void stopProcess();
    void process();

private:
    void parseSystemXML(const char* systemData, CambridgeStatusData& status);
    void parseStatusXML(const char* statusData, CambridgeStatusData& status);

signals:
    void processStartedSignal();
    void processStoppedSignal();
    void statusSignal(const CambridgeStatusData& data);
    void connectedSignal();
    void disconnectedSignal();

};

}

#endif // CAMBRIDGEINSPECTOR_HPP
