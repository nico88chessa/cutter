#ifndef SETTINGS_HPP
#define SETTINGS_HPP

#include <QSettings>
#include <QString>

#include <Types.hpp>
#include <Constants.hpp>

namespace PROGRAM_NAMESPACE {


class Settings {
public:
    using Ptr = Settings*;
    using ConstPtr = const Settings*;

private:
    Settings();
    ~Settings() { }


public:
    Settings(const Settings&) = delete;
    void operator=(const Settings&) = delete;
    void operator=(Settings&&) = delete;
    void loadValuesFromFile();
    void writeValuesToFile();

    static Settings& instance();

    quint16 getCtRefreshIntervalMs() const { return ctRefreshIntervalMs; }
    quint16 getCtRestartIntervalMs() const { return ctRestartIntervalMs; }
    QString getCtBroadcastIpAddress() const { return ctBroadcastIpAddress; }
    quint16 getCtBroadcastPort() const { return ctBroadcastPort; }
    QString getCtSetupSocketIpAddress() const { return ctSetupSocketIpAddress; }
    quint16 getCtSetupSocketPort() const { return ctSetupSocketPort; }

    QString getMachineLocalIpAddress() const { return machineLocalIpAddress; }

    realHP getSmcConfCutHeight() const { return smcConfCutHeight; }
    void setSmcConfCutHeight(const realHP& value) { smcConfCutHeight = value; }
    realHP getSmcConfXStart() const { return smcConfXStart; }
    void setSmcConfXStart(const realHP& value) { smcConfXStart = value; }
    realHP getSmcConfYStart() const { return smcConfYStart; }
    void setSmcConfYStart(const realHP& value) { smcConfYStart = value; }
    int getSmcConfLaserDuty() const { return smcConfLaserDuty; }
    void setSmcConfLaserDuty(int value) { smcConfLaserDuty = value; }
    int getSmcConfLaserJumpSpeed() const { return smcConfLaserJumpSpeed; }
    void setSmcConfLaserJumpSpeed(int value) { smcConfLaserJumpSpeed = value; }
    int getSmcConfLaserMarkSpeed() const { return smcConfLaserMarkSpeed; }
    void setSmcConfLaserMarkSpeed(int value) { smcConfLaserMarkSpeed = value; }
    int getSmcConfLaserMarkDelay() const { return smcConfLaserMarkDelay; }
    void setSmcConfLaserMarkDelay(int value) { smcConfLaserMarkDelay = value; }
    int getSmcConfLaserJumpDelay() const { return smcConfLaserJumpDelay; }
    void setSmcConfLaserJumpDelay(int value) { smcConfLaserJumpDelay = value; }
    int getSmcConfLaserPolyDelay() const { return smcConfLaserPolyDelay; }
    void setSmcConfLaserPolyDelay(int value) { smcConfLaserPolyDelay = value; }
    int getSmcConfLaserOnDelay() const { return smcConfLaserOnDelay; }
    void setSmcConfLaserOnDelay(int value) { smcConfLaserOnDelay = value; }
    int getSmcConfLaserOffDelay() const { return smcConfLaserOffDelay; }
    void setSmcConfLaserOffDelay(int value) { smcConfLaserOffDelay = value; }
    int getSmcConfLaserPipelineDelay() const { return smcConfLaserPipelineDelay; }
    void setSmcConfLaserPipelineDelay(int value) { smcConfLaserPipelineDelay = value; }
    int getSmcConfEncoderPulses() const { return smcConfEncoderPulses; }
    void setSmcConfEncoderPulses(int value) { smcConfEncoderPulses = value; }


private:
    // Cambridge technology (CT)
    quint16 ctRefreshIntervalMs;
    quint16 ctRestartIntervalMs;
    QString ctBroadcastIpAddress;
    quint16 ctBroadcastPort;
    QString ctSetupSocketIpAddress;
    quint16 ctSetupSocketPort;

    QString machineLocalIpAddress;

    // smc setup
    realHP smcConfCutHeight;
    realHP smcConfXStart;
    realHP smcConfYStart;
    int smcConfLaserDuty;
    int smcConfLaserJumpSpeed;
    int smcConfLaserMarkSpeed;
    int smcConfLaserMarkDelay;
    int smcConfLaserJumpDelay;
    int smcConfLaserPolyDelay;
    int smcConfLaserOnDelay;
    int smcConfLaserOffDelay;
    int smcConfLaserPipelineDelay;
    int smcConfEncoderPulses;

};

}

#endif // SETTINGS_HPP
