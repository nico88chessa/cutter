#ifndef CAMBRIDGEUTILS_HPP
#define CAMBRIDGEUTILS_HPP


#include <configure.h>
#include <Types.hpp>


namespace PROGRAM_NAMESPACE {

class CambridgeUtils {

public:

    static inline bool isError(SMCError errorCode) {
        return errorCode != 0;
    }

    static inline bool isSuccess(SMCError errorCode) {
        return !isError(errorCode);
    }


};

}

#endif // CAMBRIDGEUTILS_HPP
