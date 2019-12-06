#include "SetupController.hpp"

using namespace PROGRAM_NAMESPACE;


SetupController::SetupController(QObject* parent) :
    QObject(parent),
    data(new SetupData()) {

    traceEnter;
    qmlRegisterType<SetupData>();

    traceExit;

}

SetupController::~SetupController() {
    traceEnter;

    traceExit;
}

SetupData* SetupController::getData() const {
    return data.data();
}

void SetupController::sendData() const {

    traceEnter;
    this->data->setCutHeight(20);
    traceExit;

}

