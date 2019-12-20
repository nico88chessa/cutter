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

    // cambridge setup
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


    // smc setup
    smcConfCutHeight = settings.value(SMC_CONF_CUTHEIGHT, 0).value<realHP>();
    smcConfXStart = settings.value(SMC_CONF_XSTART, 0).value<realHP>();
    smcConfYStart = settings.value(SMC_CONF_YSTART, 0).value<realHP>();
    smcConfLaserDuty = settings.value(SMC_CONF_LASERDUTY, 0).value<int>();
    smcConfLaserJumpSpeed = settings.value(SMC_CONF_LASERJUMPSPEED, 0).value<int>();
    smcConfLaserMarkSpeed = settings.value(SMC_CONF_LASERMARKSPEED, 0).value<int>();
    smcConfLaserMarkDelay = settings.value(SMC_CONF_LASERMARKDELAY, 0).value<int>();
    smcConfLaserJumpDelay = settings.value(SMC_CONF_LASERJUMPDELAY, 0).value<int>();
    smcConfLaserPolyDelay = settings.value(SMC_CONF_LASERPOLYDELAY, 0).value<int>();
    smcConfLaserOnDelay = settings.value(SMC_CONF_LASERONDELAY, 0).value<int>();
    smcConfLaserOffDelay = settings.value(SMC_CONF_LASEROFFDELAY, 0).value<int>();
    smcConfLaserPipelineDelay = settings.value(SMC_CONF_LASERPIPELINEDELAY, 0).value<int>();
    smcConfEncoderPulses = settings.value(SMC_CONF_ENCODERPULSES, 0).value<int>();
    traceDebug() << "smcConfCutHeight" << smcConfCutHeight;
    traceDebug() << "smcConfXStart" << smcConfXStart;
    traceDebug() << "smcConfYStart" << smcConfYStart;
    traceDebug() << "smcConfLaserDuty" << smcConfLaserDuty;
    traceDebug() << "smcConfLaserJumpSpeed" << smcConfLaserJumpSpeed;
    traceDebug() << "smcConfLaserMarkSpeed" << smcConfLaserMarkSpeed;
    traceDebug() << "smcConfLaserMarkDelay" << smcConfLaserMarkDelay;
    traceDebug() << "smcConfLaserJumpDelay" << smcConfLaserJumpDelay;
    traceDebug() << "smcConfLaserPolyDelay" << smcConfLaserPolyDelay;
    traceDebug() << "smcConfLaserOnDelay" << smcConfLaserOnDelay;
    traceDebug() << "smcConfLaserOffDelay" << smcConfLaserOffDelay;
    traceDebug() << "smcConfLaserPipelineDelay" << smcConfLaserPipelineDelay;
    traceDebug() << "smcConfEncoderPulses" << smcConfEncoderPulses;

    // machine setup
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

    settings.setValue(SMC_CONF_CUTHEIGHT, smcConfCutHeight);
    settings.setValue(SMC_CONF_XSTART, smcConfXStart);
    settings.setValue(SMC_CONF_YSTART, smcConfYStart);
    settings.setValue(SMC_CONF_LASERDUTY, smcConfLaserDuty);
    settings.setValue(SMC_CONF_LASERJUMPSPEED, smcConfLaserJumpSpeed);
    settings.setValue(SMC_CONF_LASERMARKSPEED, smcConfLaserMarkSpeed);
    settings.setValue(SMC_CONF_LASERMARKDELAY, smcConfLaserMarkDelay);
    settings.setValue(SMC_CONF_LASERJUMPDELAY, smcConfLaserJumpDelay);
    settings.setValue(SMC_CONF_LASERPOLYDELAY, smcConfLaserPolyDelay);
    settings.setValue(SMC_CONF_LASERONDELAY, smcConfLaserOnDelay);
    settings.setValue(SMC_CONF_LASEROFFDELAY, smcConfLaserOffDelay);
    settings.setValue(SMC_CONF_LASERPIPELINEDELAY, smcConfLaserPipelineDelay);
    settings.setValue(SMC_CONF_ENCODERPULSES, smcConfEncoderPulses);

    settings.setValue(MACHINE_LOCAL_IP_ADDRESS, machineLocalIpAddress);

    settings.sync();

    traceExit;

}

Settings& Settings::instance() {

    static Settings instance;
    return instance;

}
