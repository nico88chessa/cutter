#ifndef COREDATA_HPP
#define COREDATA_HPP

#include <QObject>
#include <QString>
#include <QList>

#include <common/FactoryQml.hpp>


namespace PROGRAM_NAMESPACE {

class CoreData : public QObject {
    Q_OBJECT
    Q_DISABLE_COPY(CoreData)
    DECL_QML_SINGLETON_INSTANCEABLE()

private:
    explicit CoreData(QObject* parent = Q_NULLPTR);
    ~CoreData();

signals:
    void menuChanged();
};

}

#endif // COREDATA_HPP
