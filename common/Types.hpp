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


enum class CurrentDIO_Mask : int {
    AUX_GPI1 = 0x01 << 0,
    AUX_GPI2 = 0x01 << 1,
    AUX_GPI3 = 0x01 << 2,
    AUX_GPI4 = 0x01 << 3,
    AUX_START = 0x01 << 4,
    START = 0x01 << 5,
    INTERLOCK1 = 0x01 << 6,
    INTERLOCK2 = 0x01 << 7,
    INTERLOCK3 = 0x01 << 8,
    INTERLOCK4 = 0x01 << 9,
    AUX_GPO1 = 0x01 << 10,
    AUX_GPO2 = 0x01 << 11,
    AUX_GPO3 = 0x01 << 12,
    AUX_GPO4 = 0x01 << 13,
    JOBACTIVE = 0x01 << 14,
    ERROR_NREADY = 0x01 << 15,
    BUSY = 0x01 << 16,
    LASING = 0x01 << 17
};
Q_ENUMS(CurrentDIO_Mask)

}

#endif // TYPES_HPP
