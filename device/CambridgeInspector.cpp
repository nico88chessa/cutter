#include "CambridgeInspector.hpp"

#include <Logger.hpp>
#include <QNetworkInterface>
#include <Settings.hpp>


namespace CTBW = BroadcastWin32Wrapper;
using namespace PROGRAM_NAMESPACE;

static inline CTBW::BroadcastWin32& CTBInstance() {
    return CTBW::BroadcastWin32::Instance();
}

CambridgeInspector::CambridgeInspector(QObject *parent) : QObject(parent),
    refreshTimer(this), restartIntervalMs(0) {

    traceEnter;

    auto&& s = Settings::instance();

    ipBroadcastAddress = s.getCtBroadcastIpAddress();
    broadcastPort = s.getCtBroadcastPort();

    quint16 refreshTimeMs = s.getCtRefreshIntervalMs();

    restartIntervalMs = s.getCtRestartIntervalMs();

    refreshTimer.setInterval(refreshTimeMs);

    traceExit;

}

CambridgeInspector::~CambridgeInspector() {

    traceEnter;
    traceExit;

}

bool CambridgeInspector::beforeProcess() {

    traceEnter;
    auto&& res = QNetworkInterface::allInterfaces();

    traceExit;
    return true;

}

void CambridgeInspector::startProcess() {

    traceEnter;

    if (!beforeProcess()) {
        traceInfo() << "Cambridge inspector: auto restart process";
        QTimer::singleShot(restartIntervalMs, this, &CambridgeInspector::startProcess);
    }

    refreshTimer.start();

    traceExit;

}

void CambridgeInspector::stopProcess() {

    traceEnter;

    if (refreshTimer.isActive())
        refreshTimer.stop();

    traceExit;

}

void CambridgeInspector::process() {

    traceEnter;

    traceExit;

}
