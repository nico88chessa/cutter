#ifndef CORECONTROLLER_HPP
#define CORECONTROLLER_HPP

#include <QAbstractListModel>
#include <QObject>
#include <QQmlEngine>

#include <common/FactoryQml.hpp>

#include <configure.h>


namespace PROGRAM_NAMESPACE {

class CoreControllerPrivate;
class MenuListModel;

class CoreController : public QObject {
    Q_OBJECT
    Q_DISABLE_COPY(CoreController)
    DECL_QML_SINGLETON_INSTANCEABLE()

    Q_PROPERTY(MenuListModel* pMenuModel READ getMenuModel CONSTANT)

    friend class CoreControllerPrivate;

public:
    using Ptr = CoreController*;
    using ConstPtr = const CoreController*;

private:
    explicit CoreController(QObject* parent = Q_NULLPTR);
    CoreControllerPrivate* dPtr;

public slots:

    void close();

    MenuListModel* getMenuModel() const;

public:
    ~CoreController();

public slots:
    void test();

};

}

#endif // CORECONTROLLER_HPP
