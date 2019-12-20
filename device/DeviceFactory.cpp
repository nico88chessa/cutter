#include "DeviceFactory.hpp"

#include <QThread>
#include <QObject>

#include <device/CambridgeInspector.hpp>
#include <Logger.hpp>


using namespace PROGRAM_NAMESPACE;

DeviceFactory::DeviceFactory() :
    ctWatcher(new CambridgeInspector()) {

    initCambridgeWatcher();

}

DeviceFactory::~DeviceFactory() {

    traceEnter;
    traceExit;

}

DeviceFactory& DeviceFactory::instance() {

    traceEnter;
    static DeviceFactory df;
    traceExit;

    return df;
}

void DeviceFactory::stop() {

    traceEnter;

    if (!this->ctWatcher.isNull()) {
        traceDebug() << "Stop thread Cambridge Inspector";
        QMetaObject::invokeMethod(ctWatcher.data(), "stopProcess", Qt::QueuedConnection);
        ctWatcher->thread()->wait();
        traceDebug() << "Thread Cambridge Inspector chiuso";
    }

    traceExit;

}

CambridgeInspector::ConstPtr DeviceFactory::getCtWatcher() {

    traceEnter;
    if (ctWatcher.isNull())
        initCambridgeWatcher();

    return ctWatcher.data();
    traceExit;

}

void DeviceFactory::initCambridgeWatcher() {

    traceEnter;

    QThread* th = new QThread();
    th->setObjectName("CTWatcher");

    QObject::connect(th, &QThread::started, ctWatcher.data(), &CambridgeInspector::startProcess);
    QObject::connect(ctWatcher.data(), &CambridgeInspector::processStoppedSignal, [th]() {
        th->quit();
    });
    QObject::connect(th, &QThread::finished, th, &QThread::deleteLater);
//    QObject::connect(th, &QThread::finished, ctWatcher.data(), &CambridgeInspector::deleteLater);

    ctWatcher->moveToThread(th);
    ctWatcher->thread()->start();

    traceExit;

}
