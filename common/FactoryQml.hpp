#ifndef FACTORYQML_HPP
#define FACTORYQML_HPP

#include <QScopedPointer>
#include <QQmlEngine>

#include <Logger.hpp>

#include <configure.h>


#define DECL_QML_SINGLETON_INSTANCEABLE() \
    template <typename T> \
    friend QObject* PROGRAM_NAMESPACE::FactoryQml::build(QQmlEngine*, QJSEngine*);


namespace PROGRAM_NAMESPACE {

class FactoryQml {
private:
    FactoryQml() { }
    Q_DISABLE_COPY(FactoryQml)

public:
    static FactoryQml& instance() {
        static FactoryQml instance;
        return instance;
    }

    template <typename T>
    QObject* build(QQmlEngine* qmlEngine, QJSEngine* jsEngine) {

        traceEnter;

        static QScopedPointer<T> instance(new T()); // qui inizializzo l'oggetto di tipo T la prima volta sola
        static bool isInitialized = false;
        if (!isInitialized) {
            qmlEngine->setObjectOwnership(instance.data(), QQmlEngine::CppOwnership);
            isInitialized = true;
        }
        auto&& ptr = instance.data();

        traceExit;
        return ptr;

    }

};

}

#endif // FACTORYQML_HPP
