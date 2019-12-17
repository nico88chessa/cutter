#include "SetupController.hpp"

#include <QTcpSocket>
#include <QtMath>

#include <QDataStream>
#include <Settings.hpp>

using namespace PROGRAM_NAMESPACE;


SetupController::SetupController(QObject* parent) :
    QObject(parent),
    data(new SetupData()) {

    traceEnter;

    qmlRegisterType<SetupData>();

    auto&& settings = Settings::instance();
    ctSetupIp = settings.getCtSetupSocketIpAddress();
    ctSetupPort = settings.getCtSetupSocketPort();

    traceExit;

}

SetupController::~SetupController() {
    traceEnter;

    traceExit;
}

SetupData* SetupController::getData() const {
    return data.data();
}

void SetupController::sendData() const {

    traceEnter;
    //this->data->setCutHeight(20);

    traceInfo() << "Invio configurazione a SMC";
    traceInfo() << "Ip: " << ctSetupIp;
    traceInfo() << "Port: " << ctSetupPort;

    QScopedPointer<QTcpSocket> socket(new QTcpSocket());

    connect(socket.data(), &QTcpSocket::connected, []() {
        traceInfo() << "Socket connection OK";
    });

    connect(socket.data(), &QTcpSocket::bytesWritten, [&](int bytes) {
        data->setDialogMessage("Dati spediti correttamente");
    });

    connect(socket.data(), static_cast<void (QTcpSocket::*)(QAbstractSocket::SocketError)>(&QTcpSocket::error),
            [&](QAbstractSocket::SocketError err) {
        traceErr() << "Err";
        data->setDialogMessage("Errore socket");
    });

    socket->connectToHost(ctSetupIp, ctSetupPort);

    int bodySize = sizeof(int)*7;
    QByteArray body(bodySize, ' ');
    QDataStream dgBody(&body, QIODevice::OpenModeFlag::ReadWrite);
    dgBody.setByteOrder(QDataStream::LittleEndian);

    dgBody << qFloor(data->getCutHeight() * 1000);
    dgBody << qFloor(data->getXStart() * 1000);
    dgBody << qFloor(data->getYStart() * 1000);
    dgBody << data->getLaserDuty();
    dgBody << data->getLaserJumpSpeed();
    dgBody << data->getLaserMarkSpeed();
    dgBody << data->getEncoderPulses();

    int headerSize = sizeof(int);
    QByteArray header(headerSize, ' ');
    QDataStream dgHeader(&header, QIODevice::OpenModeFlag::ReadWrite);
    dgHeader.setByteOrder(QDataStream::LittleEndian);
    dgHeader << bodySize; //bytes2Send.length();
    socket->write(header);
    socket->waitForBytesWritten();

    socket->write(body);
    socket->waitForBytesWritten();

    traceExit;

}

