#ifndef SYSTEMSTATUSCONTROLLER_HPP
#define SYSTEMSTATUSCONTROLLER_HPP

#include <CambridgeStatusData.hpp>
#include <QAbstractListModel>
#include <QObject>
#include <QQmlEngine>

#include <common/FactoryQml.hpp>

#include "../data/SystemStatusData.hpp"

#include <configure.h>


namespace PROGRAM_NAMESPACE {

class SystemStatusController : public QObject {
    Q_OBJECT
    Q_DISABLE_COPY(SystemStatusController)
    DECL_QML_SINGLETON_INSTANCEABLE()

    Q_PROPERTY(SystemStatusData* pData READ getData CONSTANT)

public:
    using Ptr = SystemStatusController*;
    using ConstPtr = const SystemStatusController*;

private:
    QScopedPointer<SystemStatusData> data;

private:
    explicit SystemStatusController(QObject* parent = Q_NULLPTR);
    void setupSignalsAndSlots();

public:
    ~SystemStatusController();
    SystemStatusData* getData() const;

public slots:
    void initQML();

private slots:
    void updateStatus(const CambridgeStatusData& status);
};


}

#endif // SYSTEMSTATUSCONTROLLER_HPP
