#ifndef DEVICEFACTORY_HPP
#define DEVICEFACTORY_HPP

#include <QScopedPointer>

#include <QWeakPointer>
#include <configure.h>


namespace PROGRAM_NAMESPACE {

class CambridgeInspector;

class DeviceFactory {
private:
    QScopedPointer<CambridgeInspector> ctWatcher;

    DeviceFactory();

public:
    ~DeviceFactory();

    static DeviceFactory& instance();
    void stop();

    const CambridgeInspector* getCtWatcher();

private:
    void initCambridgeWatcher();

};

}

#endif // DEVICEFACTORY_HPP
