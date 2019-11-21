#include <iostream>
#include <CTIBroadcastWin32Cls.h>
#include <CTISessionWin32Cls.h>
#include <CTIECUtilsWin32Cls.h>
#include <SMCEventCodes.h>
#include <thread>
#include <string>

#include <ui/logic/CoreController.hpp>

#include <QQmlEngine>
#include <Logger.hpp>
#include <QGuiApplication>
#include <QQmlApplicationEngine>

using namespace std;
//namespace CT = BroadcastWin32Wrapper;
//namespace CTS = SessionWin32Wrapper;
namespace ECU = ECUtilsWin32Wrapper;


void test(const char* s) {
    std::cout << (int) &s;
    std::cout << (int) s;
    s = new char[20];
    std::cout << (long) &s;
    std::cout << (int) s;
}


int main(int argc, char** argv) {

    using namespace PROGRAM_NAMESPACE;

    traceInfo() << "Cutter started" << endl;

    int res = qmlRegisterSingletonType<CoreController>("Cutter.CoreController", 1, 0, "CoreController", CoreController::qmlInstance);
//    qmlRegisterType<CoreController>("Cutter.CoreController", 1, 0, "CoreController");

    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("file:///C://Users//nicola//workspace//cutter//src//ui//qml//main.qml")));

    auto&& test = CoreController::qmlInstance(&engine, nullptr);

    return app.exec();


}

int main2(int argc, char** argv) {

    cout << "Hello" << endl;

    using SMCError = unsigned int;

    ECU::ECUtilsWin32 ecUtils;
    SessionWin32Wrapper::SessionWin32 ctSession;

    qmlRegisterSingletonType<CoreController>("Cutter.CoreController", 1, 0, "CoreController",
                                                                static_cast<QObject*(*)(QQmlEngine*, QJSEngine*)>(&CoreController::qmlInstance));

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
