#include <iostream>
#include <thread>
#include <string>

#include <CTIBroadcastWin32Cls.h>
#include <CTISessionWin32Cls.h>
#include <CTIECUtilsWin32Cls.h>
#include <SMCEventCodes.h>

#include <QQmlEngine>
#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <common/FactoryQml.hpp>
#include <common/MathUtils.hpp>

#include <ui/logic/data/CoreData.hpp>
#include <ui/logic/data/ApplicationData.hpp>
#include <device/CambridgeStatusData.hpp>
#include <ui/logic/controller/CoreController.hpp>
#include <ui/logic/controller/SetupController.hpp>
#include <ui/logic/controller/SystemStatusController.hpp>

#include <Logger.hpp>
#include <Types.hpp>

using namespace std;
namespace ECU = ECUtilsWin32Wrapper;


void test(const char*& s) {
//    std::cout << (int) &s;
//    std::cout << (int) s;
//    s = new char[20];
//    std::cout << (long) &s;
//    std::cout << (int) s;
}


void registerSingletons() {

    using namespace PROGRAM_NAMESPACE;

    traceEnter;
    int regCount = 0;

    auto&& factory = FactoryQml::instance();

    regCount += qmlRegisterSingletonType<PROGRAM_NAMESPACE::CoreController>("Cutter.CoreController", 1, 0, "CoreController", [](QQmlEngine* qmlEngine, QJSEngine* jsEngine) -> QObject* {
            return FactoryQml::instance().build<PROGRAM_NAMESPACE::CoreController>(qmlEngine, jsEngine);
    });
    regCount += qmlRegisterSingletonType<PROGRAM_NAMESPACE::ApplicationData>("Cutter.ApplicationData", 1, 0, "ApplicationData", [](QQmlEngine* qmlEngine, QJSEngine* jsEngine) -> QObject* {
            return FactoryQml::instance().build<PROGRAM_NAMESPACE::ApplicationData>(qmlEngine, jsEngine);
    });
    regCount += qmlRegisterSingletonType<PROGRAM_NAMESPACE::SetupController>("Cutter.SetupController", 1, 0, "SetupController", [](QQmlEngine* qmlEngine, QJSEngine* jsEngine) -> QObject* {
            return FactoryQml::instance().build<PROGRAM_NAMESPACE::SetupController>(qmlEngine, jsEngine);
    });
    regCount += qmlRegisterSingletonType<PROGRAM_NAMESPACE::SystemStatusController>("Cutter.SystemStatusController", 1, 0, "SystemStatusController", [](QQmlEngine* qmlEngine, QJSEngine* jsEngine) -> QObject* {
            return FactoryQml::instance().build<PROGRAM_NAMESPACE::SystemStatusController>(qmlEngine, jsEngine);
    });


    traceDebug() << "SingleTon registrati: " << regCount;
    traceExit;

}

void registerQMLMetatypes() {

    using namespace PROGRAM_NAMESPACE;

    traceEnter;
    qmlRegisterUncreatableMetaObject(PROGRAM_NAMESPACE::staticMetaObject, "com.dv", 1, 0, "CutterNS", "Cannot create a namespace object");

    traceExit;

}

void registerMetatypes() {

    /* NOTE NIC 18/03/2019 - registrazione tipi custom
     * qui vanno registrati i tipi custom che devono essere gestiti
     * dalle connessioni Signal / Slot (soprattutto nel caso di QueueConnection);
     * non e' necessario registrare i tipi se utilizzati solo come QVariant
     * ricordarsi di registrare il tipi sia con namespace sia senza
     * altrimenti le chiamate fatte usando QMetaObject::invokeMethod(...) non funzionano
     */

    using namespace PROGRAM_NAMESPACE;

    traceEnter;

    qRegisterMetaType<PROGRAM_NAMESPACE::real>("cutter::real");
    qRegisterMetaType<real>("real");
    qRegisterMetaType<PROGRAM_NAMESPACE::realHP>("cutter::realHP");
    qRegisterMetaType<realHP>("realHP");
    qRegisterMetaType<PROGRAM_NAMESPACE::SMCError>("cutter::SMCError");
    qRegisterMetaType<SMCError>("SMCError");
    qRegisterMetaType<PROGRAM_NAMESPACE::CambridgeStatusData>("cutter::CambridgeStatusData");
    qRegisterMetaType<CambridgeStatusData>("CambridgeStatusData");
}


int main(int argc, char** argv) {

    using namespace PROGRAM_NAMESPACE;

    traceInfo() << "Cutter started";

    registerSingletons();
    registerQMLMetatypes();
    registerMetatypes();

//    const char* prova = nullptr;
//    test(prova);
    //MathUtils::almostEqual(10, 10);
    //MathUtils::almostEqual(10.0, 10.0);

    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:///qml/main.qml")));

    return app.exec();

}

int main2(int argc, char** argv) {

    cout << "Hello" << endl;

    using SMCError = unsigned int;

    ECU::ECUtilsWin32 ecUtils;
    SessionWin32Wrapper::SessionWin32 ctSession;

//    qmlRegisterSingletonType<PROGRAM_NAMESPACE::CoreController>("Cutter.CoreController", 1, 0, "CoreController",
//                                                                static_cast<QObject*(*)(QQmlEngine*, QJSEngine*)>(&PROGRAM_NAMESPACE::CoreController::qmlInstance));

//    prova.loginSession("192.168.100.2", "192.168.100.20", 12200, 1000);
    BroadcastWin32Wrapper::BroadcastWin32 sample = BroadcastWin32Wrapper::BroadcastWin32::Instance();

    int sc;
    int id = 1;
    string broadcastAdd = "224.168.100.2";
    int port = 11000;
    SMCError err;
    err = sample.clientAttachBroadcast(broadcastAdd.c_str(), "192.168.100.1", port, id);
    this_thread::sleep_for(std::chrono::seconds(5));
    err = sample.getServerCount(id, sc);
    const char* list;
    err = sample.getServerList(id, sc, list);

    const char* friendlyName;
    ecUtils.ReadFromXML(list, 0, "Device", "name", friendlyName);

    const char* data1;
    sample.getBroadcastData(id, friendlyName, 0x01, data1);
    const char* data2;
    sample.getBroadcastData(id, friendlyName, 0x07, data2);

    cout << "Err: " << err;
    cout << "Server count: " << sc;
    sample.clientDetachBroadcast(id);

    return 0;

}
