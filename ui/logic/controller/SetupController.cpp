#include "SetupController.hpp"

#include <DeviceFactory.hpp>
#include <QTcpSocket>
#include <QtMath>

#include <CambridgeInspector.hpp>
#include <QDataStream>
#include <Settings.hpp>

using namespace PROGRAM_NAMESPACE;

static constexpr int WAIT_TIME_MS_SOCKET = 2000;

SetupController::SetupController(QObject* parent) :
    QObject(parent),
    data(new SetupData()) {

    traceEnter;

    qmlRegisterType<SetupData>();

    auto&& settings = Settings::instance();

    ctSetupIp = settings.getCtSetupSocketIpAddress();
    ctSetupPort = settings.getCtSetupSocketPort();

    data->setCutHeight(settings.getSmcConfCutHeight());
    data->setXStart(settings.getSmcConfXStart());
    data->setYStart(settings.getSmcConfYStart());
    data->setLaserDuty(settings.getSmcConfLaserDuty());
    data->setLaserJumpSpeed(settings.getSmcConfLaserJumpSpeed());
    data->setLaserMarkSpeed(settings.getSmcConfLaserMarkSpeed());
    data->setLaserMarkDelay(settings.getSmcConfLaserMarkDelay());
    data->setLaserJumpDelay(settings.getSmcConfLaserJumpDelay());
    data->setLaserPolyDelay(settings.getSmcConfLaserPolyDelay());
    data->setLaserOnDelay(settings.getSmcConfLaserOnDelay());
    data->setLaserOffDelay(settings.getSmcConfLaserOffDelay());
    data->setLaserPipelineDelay(settings.getSmcConfLaserPipelineDelay());
    data->setEncoderPulses(settings.getSmcConfEncoderPulses());

    this->setupSignalsAndSlots();
    traceExit;

}

void SetupController::setupSignalsAndSlots() {

    traceEnter;
    auto&& devFact = DeviceFactory::instance();

    connect(devFact.getCtWatcher(), &CambridgeInspector::statusSignal, [&](const CambridgeStatusData& status) {
        int currentIO = status.getCurrentDIO();
        bool isEnabled = (currentIO & static_cast<int>(CurrentDIO_Mask::AUX_GPO4)) >> static_cast<int>(CurrentDIO_Order::AUX_GPO4);
        data->setIsSendButtonEnabled(isEnabled);
    });
    traceExit;

}

void SetupController::showDialog(QAbstractSocket::SocketError err) {
    traceErr() << "Socket error: " << static_cast<int>(err);
    this->showDialog(QString("Invio dati a SMC fallito - Err: %1").arg(static_cast<int>(err)));
}

void SetupController::showDialog(const QString& msg) {
    emit notifyDialog(msg);
}

SetupController::~SetupController() {
    traceEnter;

    traceExit;
}

SetupData* SetupController::getData() const {
    return data.data();
}

void SetupController::sendData() {

    traceEnter;
    auto&& settings = Settings::instance();

    settings.setSmcConfCutHeight(data->getCutHeight());
    settings.setSmcConfXStart(data->getXStart());
    settings.setSmcConfYStart(data->getYStart());
    settings.setSmcConfLaserDuty(data->getLaserDuty());
    settings.setSmcConfLaserJumpSpeed(data->getLaserJumpSpeed());
    settings.setSmcConfLaserMarkSpeed(data->getLaserMarkSpeed());
    settings.setSmcConfLaserMarkDelay(data->getLaserMarkDelay());
    settings.setSmcConfLaserJumpDelay(data->getLaserJumpDelay());
    settings.setSmcConfLaserPolyDelay(data->getLaserPolyDelay());
    settings.setSmcConfLaserOnDelay(data->getLaserOnDelay());
    settings.setSmcConfLaserOffDelay(data->getLaserOffDelay());
    settings.setSmcConfLaserPipelineDelay(data->getLaserPipelineDelay());
    settings.setSmcConfEncoderPulses(data->getEncoderPulses());

    settings.writeValuesToFile();

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
            this, static_cast<void (SetupController::*)(QAbstractSocket::SocketError)>(&SetupController::showDialog));

    socket->connectToHost(ctSetupIp, ctSetupPort);
    if (!socket->waitForConnected(WAIT_TIME_MS_SOCKET)) {
        traceErr() << "Impossibile connettersi a SMC per invio dati";
        this->showDialog("Impossibile connettersi a SMC");
        return;
    }

    int bodySize = sizeof(int)*13;
    QByteArray body(bodySize, ' ');
    QDataStream dgBody(&body, QIODevice::OpenModeFlag::ReadWrite);
    dgBody.setByteOrder(QDataStream::LittleEndian);

    dgBody << qFloor(data->getCutHeight() * 1000);
    dgBody << qFloor(data->getXStart() * 1000);
    dgBody << qFloor(data->getYStart() * 1000);
    dgBody << data->getLaserDuty();
    dgBody << data->getLaserJumpSpeed();
    dgBody << data->getLaserMarkSpeed();
    dgBody << data->getLaserMarkDelay();
    dgBody << data->getLaserJumpDelay();
    dgBody << data->getLaserPolyDelay();
    dgBody << data->getLaserOnDelay();
    dgBody << data->getLaserOffDelay();
    dgBody << data->getLaserPipelineDelay();
    dgBody << data->getEncoderPulses();

    traceInfo() << "Invio dati a SMC";
    traceInfo() << "CutHeight: " << qFloor(data->getCutHeight() * 1000);
    traceInfo() << "XStart: " << qFloor(data->getXStart() * 1000);
    traceInfo() << "YStart: " << qFloor(data->getYStart() * 1000);
    traceInfo() << "LaserDuty: " << data->getLaserDuty();
    traceInfo() << "LaserJumpSpeed: " << data->getLaserJumpSpeed();
    traceInfo() << "LaserMarkSpeed: " << data->getLaserMarkSpeed();
    traceInfo() << "LaserMarkDelay: " << data->getLaserMarkDelay();
    traceInfo() << "LaserJumpDelay: " << data->getLaserJumpDelay();
    traceInfo() << "LaserPolyDelay: " << data->getLaserPolyDelay();
    traceInfo() << "LaserOnDelay: " << data->getLaserOnDelay();
    traceInfo() << "LaserOffDelay: " << data->getLaserOffDelay();
    traceInfo() << "LaserPipelineDelay: " << data->getLaserPipelineDelay();
    traceInfo() << "EncoderPulses: " << data->getEncoderPulses();

    int headerSize = sizeof(int);
    QByteArray header(headerSize, ' ');
    QDataStream dgHeader(&header, QIODevice::OpenModeFlag::ReadWrite);
    dgHeader.setByteOrder(QDataStream::LittleEndian);
    dgHeader << bodySize;
    socket->write(header);
    if (!socket->waitForBytesWritten(WAIT_TIME_MS_SOCKET)) {
        traceErr() << "Impossibile inviare header dati";
        this->showDialog("Impossibile inviare header dati");
        socket->close();
        return;
    };

    socket->write(body);
    if (!socket->waitForBytesWritten(WAIT_TIME_MS_SOCKET)) {
        traceErr() << "Impossibile inviare body dati";
        this->showDialog("Impossibile inviare body dati");
        socket->close();
        return;
    }

    socket->close();

    this->showDialog("Invio dati avvenuto correttamente");

    traceExit;

}

