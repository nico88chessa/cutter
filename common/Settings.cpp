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

    traceDebug() << "ctRefreshIntervalMs:" << ctRefreshIntervalMs;
    traceDebug() << "ctRestartIntervalMs:" << ctRestartIntervalMs;
    traceDebug() << "ctBroadcastIpAddress:" << ctBroadcastIpAddress;
    traceDebug() << "ctBroadcastIpAddress:" << ctBroadcastIpAddress;

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

    settings.sync();

    traceExit;

}

Settings& Settings::instance() {

    static Settings instance;
    return instance;

}



