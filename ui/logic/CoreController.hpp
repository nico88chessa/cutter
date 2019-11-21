#ifndef CORECONTROLLER_HPP
#define CORECONTROLLER_HPP


#include <QObject>

#include <QJSEngine>
#include <QQmlEngine>
#include <configure.h>


//namespace PROGRAM_NAMESPACE {

class CoreController : public QObject {
    Q_OBJECT
    Q_DISABLE_COPY(CoreController)

private:
    CoreController(QObject* parent = Q_NULLPTR);

public:
    static QObject* qmlInstance(QQmlEngine* qmlEngine, QJSEngine* jsEngine);

public slots:
    void test();

};

//}

#endif // CORECONTROLLER_HPP
