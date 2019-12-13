#include "SystemStatusController.hpp"

#include <Logger.hpp>
#include <DeviceFactory.hpp>

#include <device/CambridgeInspector.hpp>


using namespace PROGRAM_NAMESPACE;

SystemStatusController::SystemStatusController(QObject* parent) :
    QObject(parent), data(new SystemStatusData()) {

    traceEnter;

    qmlRegisterType<SystemStatusData>();
    this->setupSignalsAndSlots();

    traceExit;

}

void SystemStatusController::setupSignalsAndSlots() {

    traceEnter;
    auto&& devFact = DeviceFactory::instance();

    connect(devFact.getCtWatcher(), &CambridgeInspector::statusSignal, this, &SystemStatusController::updateStatus);

    traceExit;

}

SystemStatusController::~SystemStatusController() {

}

SystemStatusData* SystemStatusController::getData() const {
    return data.data();
}

void SystemStatusController::initQML() {

    traceEnter;
    traceExit;

}

void SystemStatusController::updateStatus(const CambridgeStatusData& status) {

    traceEnter;
    data->updateCambridgeStatus(status);
    traceExit;

}
