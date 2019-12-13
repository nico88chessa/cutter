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

    void loadValuesFromFile();
    void writeValuesToFile();

public:
    Settings(const Settings&) = delete;
    void operator=(const Settings&) = delete;
    void operator=(Settings&&) = delete;

    static Settings& instance();

    quint16 getCtRefreshIntervalMs() const { return ctRefreshIntervalMs; }
    quint16 getCtRestartIntervalMs() const { return ctRestartIntervalMs; }
    QString getCtBroadcastIpAddress() const { return ctBroadcastIpAddress; }
    quint16 getCtBroadcastPort() const { return ctBroadcastPort; }

    QString getMachineLocalIpAddress() const { return machineLocalIpAddress; }

private:
    // Cambridge technology (CT)
    quint16 ctRefreshIntervalMs;
    quint16 ctRestartIntervalMs;
    QString ctBroadcastIpAddress;
    quint16 ctBroadcastPort;

    QString machineLocalIpAddress;

};

}

#endif // SETTINGS_HPP
