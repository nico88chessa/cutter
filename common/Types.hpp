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

}

#endif // TYPES_HPP
