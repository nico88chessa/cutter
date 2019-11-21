#ifndef COREDATA_HPP
#define COREDATA_HPP

#include <QObject>
#include <QQmlEngine>

#include <common/FactoryQml.hpp>

#include <configure.h>


namespace PROGRAM_NAMESPACE {

class CoreData : public QObject {
    Q_OBJECT
    Q_DISABLE_COPY(CoreData)
    DECL_QML_SINGLETON_INSTANCEABLE(CoreData)

private:
    explicit CoreData(QObject* parent = Q_NULLPTR);

public:
    ~CoreData();

};

}

#endif // COREDATA_HPP
