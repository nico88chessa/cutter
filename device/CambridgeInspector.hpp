#ifndef CAMBRIDGEINSPECTOR_HPP
#define CAMBRIDGEINSPECTOR_HPP

#include <configure.h>

#include <QObject>

#include <CTIBroadcastWin32Cls.h>
#include <CTIECUtilsWin32Cls.h>

#include <QTimer>

namespace PROGRAM_NAMESPACE {

class CambridgeInspector : public QObject {
    Q_OBJECT

private:
    QString ipBroadcastAddress;
    quint16 broadcastPort;
    quint16 restartIntervalMs;

    QTimer refreshTimer;

public:
    explicit CambridgeInspector(QObject *parent = nullptr);

    ~CambridgeInspector();

signals:

public slots:

    bool beforeProcess();

    void startProcess();

    void stopProcess();

    void process();

};

}

#endif // CAMBRIDGEINSPECTOR_HPP
