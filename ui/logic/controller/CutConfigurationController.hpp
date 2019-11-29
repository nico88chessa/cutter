#ifndef CUTCONFIGURATIONCONTROLLER_HPP
#define CUTCONFIGURATIONCONTROLLER_HPP

#include <QObject>
#include <QQmlEngine>

#include <common/FactoryQml.hpp>

#include <configure.h>


namespace PROGRAM_NAMESPACE {

class CutConfigurationController : public QObject {
    Q_OBJECT
    Q_DISABLE_COPY(CutConfigurationController)
    DECL_QML_SINGLETON_INSTANCEABLE()

private:
    CutConfigurationController(QObject* parent = Q_NULLPTR);

public:
    ~CutConfigurationController();

};

}

#endif // CUTCONFIGURATIONCONTROLLER_HPP
