#include "CoreController.hpp"

#include <Logger.hpp>

using namespace PROGRAM_NAMESPACE;

CoreController::CoreController(QObject* parent) : QObject(parent) {

    traceEnter;
    traceExit;

}

QObject* CoreController::qmlInstance(QQmlEngine* qmlEngine, QJSEngine* jsEngine) {

    Q_UNUSED(qmlEngine)
    Q_UNUSED(jsEngine)

    traceEnter;
    static CoreController instance;
    static bool isInitialized = false;
    if (!isInitialized) {
        qmlEngine->setObjectOwnership(&instance, QQmlEngine::CppOwnership);
        isInitialized = true;
    }
    traceExit;
    return &instance;

}

void CoreController::test() {
    traceEnter;
    traceExit;
}
