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


enum class CurrentDIO_Order : int {
    AUX_GPI1 = 0,
    AUX_GPI2,
    AUX_GPI3,
    AUX_GPI4,
    AUX_START,
    START,
    INTERLOCK1,
    INTERLOCK2,
    INTERLOCK3,
    INTERLOCK4,
    AUX_GPO1,
    AUX_GPO2,
    AUX_GPO3,
    AUX_GPO4,
    JOBACTIVE,
    ERROR_NREADY,
    BUSY,
    LASING
};

enum class CurrentDIO_Mask : int {
    AUX_GPI1 = 0x01 << static_cast<int>(CurrentDIO_Order::AUX_GPI1),
    AUX_GPI2 = 0x01 << static_cast<int>(CurrentDIO_Order::AUX_GPI2),
    AUX_GPI3 = 0x01 << static_cast<int>(CurrentDIO_Order::AUX_GPI3),
    AUX_GPI4 = 0x01 << static_cast<int>(CurrentDIO_Order::AUX_GPI4),
    AUX_START = 0x01 << static_cast<int>(CurrentDIO_Order::AUX_START),
    START = 0x01 << static_cast<int>(CurrentDIO_Order::START),
    INTERLOCK1 = 0x01 << static_cast<int>(CurrentDIO_Order::INTERLOCK1),
    INTERLOCK2 = 0x01 << static_cast<int>(CurrentDIO_Order::INTERLOCK2),
    INTERLOCK3 = 0x01 << static_cast<int>(CurrentDIO_Order::INTERLOCK3),
    INTERLOCK4 = 0x01 << static_cast<int>(CurrentDIO_Order::INTERLOCK4),
    AUX_GPO1 = 0x01 << static_cast<int>(CurrentDIO_Order::AUX_GPO1),
    AUX_GPO2 = 0x01 << static_cast<int>(CurrentDIO_Order::AUX_GPO2),
    AUX_GPO3 = 0x01 << static_cast<int>(CurrentDIO_Order::AUX_GPO3),
    AUX_GPO4 = 0x01 << static_cast<int>(CurrentDIO_Order::AUX_GPO4),
    JOBACTIVE = 0x01 << static_cast<int>(CurrentDIO_Order::JOBACTIVE),
    ERROR_NREADY = 0x01 << static_cast<int>(CurrentDIO_Order::ERROR_NREADY),
    BUSY = 0x01 << static_cast<int>(CurrentDIO_Order::BUSY),
    LASING = 0x01 << static_cast<int>(CurrentDIO_Order::LASING)
};
Q_ENUMS(CurrentDIO_Mask)

}

#endif // TYPES_HPP
