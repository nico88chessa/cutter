#include "Settings.hpp"

using namespace PROGRAM_NAMESPACE;

#include <Logger.hpp>
//#include <Utils.hpp>

Settings::Settings() {

    traceEnter;

    this->loadValuesFromFile();

    this->writeValuesToFile();

    traceExit;

}

void Settings::loadValuesFromFile() {

    traceEnter;

    using namespace settings;

    QSettings settings(QSettings::IniFormat, QSettings::UserScope, ORGANIZATION, APPLICATION_NAME);

    ctRefreshIntervalMs = settings.value(CT_REFRESH_INTERVAL_MS, CT_REFRESH_INTERVAL_MS_DFLT).value<quint16>();
    ctRestartIntervalMs = settings.value(CT_RESTART_INTERVAL_MS, CT_RESTART_INTERVAL_MS_DFLT).value<quint16>();
    ctBroadcastIpAddress = settings.value(CT_BROADCAST_IP_ADDRESS, CT_BROADCAST_IP_ADDRESS_DFLT).value<QString>();
    ctBroadcastPort = settings.value(CT_BROADCAST_PORT, CT_BROADCAST_PORT_DFLT).value<quint16>();
    ctSetupSocketIpAddress = settings.value(CT_SETUP_SOCKET_IP_ADDRESS, CT_SETUP_SOCKET_IP_ADDRESS_DFLT).value<QString>();
    ctSetupSocketPort = settings.value(CT_SETUP_SOCKET_PORT, CT_SETUP_SOCKET_PORT_DFLT).value<quint16>();

    traceDebug() << "ctRefreshIntervalMs:" << ctRefreshIntervalMs;
    traceDebug() << "ctRestartIntervalMs:" << ctRestartIntervalMs;
    traceDebug() << "ctBroadcastIpAddress:" << ctBroadcastIpAddress;
    traceDebug() << "ctBroadcastPort:" << ctBroadcastPort;
    traceDebug() << "ctSetupSocketIpAddress:" << ctSetupSocketIpAddress;
    traceDebug() << "ctSetupSocketPort: " << ctSetupSocketPort;

    machineLocalIpAddress = settings.value(MACHINE_LOCAL_IP_ADDRESS, MACHINE_LOCAL_IP_ADDRESS_DFLT).value<QString>();

    traceDebug() << "machineLocalIpAddress: " << machineLocalIpAddress;

    traceExit;

}

void Settings::writeValuesToFile() {

    traceEnter;

    using namespace settings;

    QSettings settings(QSettings::IniFormat, QSettings::UserScope, ORGANIZATION, APPLICATION_NAME);

    settings.setValue(CT_REFRESH_INTERVAL_MS, ctRefreshIntervalMs);
    settings.setValue(CT_RESTART_INTERVAL_MS, ctRestartIntervalMs);
    settings.setValue(CT_BROADCAST_IP_ADDRESS, ctBroadcastIpAddress);
    settings.setValue(CT_BROADCAST_PORT, ctBroadcastPort);
    settings.setValue(CT_SETUP_SOCKET_IP_ADDRESS, ctSetupSocketIpAddress);
    settings.setValue(CT_SETUP_SOCKET_PORT, ctSetupSocketPort);

    settings.setValue(MACHINE_LOCAL_IP_ADDRESS, machineLocalIpAddress);

    settings.sync();

    traceExit;

}

Settings& Settings::instance() {

    static Settings instance;
    return instance;

}
