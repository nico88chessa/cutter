#include "ApplicationData.hpp"

#include <Logger.hpp>


using namespace PROGRAM_NAMESPACE;


ApplicationData::ApplicationData(QObject* parent): QObject(parent) {

    traceEnter;
    this->setApplicationName(APPLICATION_NAME);
    this->setApplicationVersion(APPLICATION_VERSION);

    traceExit;

}

ApplicationData::~ApplicationData() { }
