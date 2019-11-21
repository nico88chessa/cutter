#include "CoreController.hpp"

#include <Logger.hpp>


using namespace PROGRAM_NAMESPACE;


CoreController::CoreController(QObject* parent) : QObject(parent) {

    traceEnter;
    traceExit;

}

CoreController::~CoreController() {

    traceEnter;
    traceExit;

}

void CoreController::test() {
    traceEnter;
    traceExit;
}
