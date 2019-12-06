#ifndef TYPES_HPP
#define TYPES_HPP

#include <QObject>

#include <configure.h>


namespace PROGRAM_NAMESPACE {

Q_NAMESPACE

using SMCError = unsigned int;
using real = float;
using realHP = double;

enum class MenuKeyType : int {
    NONE = -1,
    SETUP,
    SYSTEM_STATUS,
    SETTINGS,
    INFO
};
Q_ENUM_NS(MenuKeyType)


enum class EC100StatusType : int {
    AVAILABLE = 0x0,            // available for connection
    CLIENT_TCP = 0x01 << 0,     // connected to network client
    CLIENT_SERIAL = 0x01 << 1,  // connected to serial client (future)
    CLIENT_LOCAL = 0x01 << 2,   // in local mode
    RESTARTING = 0x01 << 3,     // server restarting
    WAITING = 0x01 << 4,        // waiting for server startup
    PAUSING = 0x01 << 5,        // job paused
    WAITING_TCP = 0x01 << 6,    // waiting for tcp connection
    NOT_AVAILABLE = 0x01 << 7   // server is in a transitional state and unavailable
};
Q_ENUM_NS(EC100StatusType)

}

#endif // TYPES_HPP
