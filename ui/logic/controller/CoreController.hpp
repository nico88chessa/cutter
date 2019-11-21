#ifndef CORECONTROLLER_HPP
#define CORECONTROLLER_HPP

#include <QObject>
#include <QQmlEngine>

#include <common/FactoryQml.hpp>

#include <configure.h>


namespace PROGRAM_NAMESPACE {

class CoreController : public QObject {
    Q_OBJECT
    Q_DISABLE_COPY(CoreController)
    DECL_QML_SINGLETON_INSTANCEABLE(CoreController)

private:
    explicit CoreController(QObject* parent = Q_NULLPTR);

public:
    ~CoreController();

public slots:
    void test();

};

}

#endif // CORECONTROLLER_HPP
