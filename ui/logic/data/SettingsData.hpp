#ifndef SETTINGSDATA_HPP
#define SETTINGSDATA_HPP

#include <QObject>
#include <QQmlEngine>

#include <common/FactoryQml.hpp>

#include <configure.h>


namespace PROGRAM_NAMESPACE {

class SettingsData : public QObject {
    Q_OBJECT
    Q_DISABLE_COPY(SettingsData)
    DECL_QML_SINGLETON_INSTANCEABLE()

private:
    SettingsData(QObject* parent = Q_NULLPTR);

public:
    ~SettingsData();

};

}

#endif // SETTINGSDATA_HPP
