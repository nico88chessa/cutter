#include "SystemStatusController.hpp"

using namespace PROGRAM_NAMESPACE;

SystemStatusController::SystemStatusController(QObject* parent) :
    QObject(parent), data(new SystemStatusData()) { }

SystemStatusController::~SystemStatusController() {

}

SystemStatusData* SystemStatusController::getData() const {
    return data.data();
}
