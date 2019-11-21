#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

#include <configure.h>
#include <Types.hpp>

namespace PROGRAM_NAMESPACE {

constexpr double EPSILON = 2.0;

namespace settings {

// variabili configurazione cambridge technology (CT)
constexpr char CT_REFRESH_INTERVAL_MS[] = "Cambridge/RefreshTimeMs";
constexpr char CT_RESTART_INTERVAL_MS[] = "Cambridge/RestartTimeMs";
constexpr char CT_BROADCAST_IP_ADDRESS[] = "Cambridge/BroadcastIpAddress";
constexpr char CT_BROADCAST_PORT[] = "Cambridge/BroadcastPort";

constexpr quint16 CT_REFRESH_INTERVAL_MS_DFLT = 100;
constexpr quint16 CT_RESTART_INTERVAL_MS_DFLT = 5000;
constexpr char CT_BROADCAST_IP_ADDRESS_DFLT[] = "224.168.100.2";
constexpr quint16 CT_BROADCAST_PORT_DFLT = 11000;


// variabili di macchina
constexpr char MACHINE_ETH_INTERFACE[] = "Machine/EthInterface";

constexpr char MACHINE_ETH_INTERFACE_DFLT[] = "eth0";

}

}

#endif // CONSTANTS_HPP
