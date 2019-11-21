#ifndef SETTINGSCONTROLLER_HPP
#define SETTINGSCONTROLLER_HPP

#include <QObject>
#include <QQmlEngine>

#include <common/FactoryQml.hpp>

#include <configure.h>


namespace PROGRAM_NAMESPACE {

class SettingsController : public QObject {
    Q_OBJECT
    Q_DISABLE_COPY(SettingsController)
    DECL_QML_SINGLETON_INSTANCEABLE(SettingsController)

private:
    SettingsController(QObject* parent = Q_NULLPTR);

public:
    ~SettingsController();

};

}

#endif // SETTINGSCONTROLLER_HPP
