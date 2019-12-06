#ifndef SETUPCONTROLLER_HPP
#define SETUPCONTROLLER_HPP

#include <QAbstractListModel>
#include <QObject>
#include <QQmlEngine>

#include <common/FactoryQml.hpp>

#include "../data/SetupData.hpp"

#include <configure.h>


namespace PROGRAM_NAMESPACE {

class SetupController : public QObject {
    Q_OBJECT
    Q_DISABLE_COPY(SetupController)
    DECL_QML_SINGLETON_INSTANCEABLE()

    Q_PROPERTY(SetupData* pData READ getData CONSTANT)

public:
    using Ptr = SetupController*;
    using ConstPtr = const SetupController*;

private:
    explicit SetupController(QObject* parent = Q_NULLPTR);

    QScopedPointer<SetupData> data;

public:
    ~SetupController();

    SetupData* getData() const;

public slots:
    void sendData() const;

};

}

#endif // SETUPCONTROLLER_HPP
