#include "SetupData.hpp"

#include <MathUtils.hpp>
#include <Logger.hpp>


using namespace PROGRAM_NAMESPACE;


SetupData::SetupData(QObject* parent) : QObject(parent),
    cutHeight(0),
    xStart(0),
    yStart(0),
    laserPower(0),
    laserDuty(0),
    laserJumpSpeed(0),
    laserMarkSpeed(0),
    encoderPulses(0),
    dialogMessage("") {

    traceEnter;
    traceExit;

}

real SetupData::getCutHeight() const {
    return cutHeight;
}

void SetupData::setCutHeight(const real& value) {
    if (!MathUtils::almostEqual(value, cutHeight)) {
        cutHeight = value;
        emit cutHeightChanged();
    }
}

real SetupData::getXStart() const {
    return xStart;
}

void SetupData::setXStart(const real& value) {
    if (!MathUtils::almostEqual(value, xStart)) {
        xStart = value;
        emit xStartChanged();
    }
}

real SetupData::getYStart() const {
    return yStart;
}

void SetupData::setYStart(const real& value) {
    if (!MathUtils::almostEqual(value, yStart)) {
        yStart = value;
        emit yStartChanged();
    }
}

int SetupData::getLaserDuty() const {
    return laserDuty;
}

void SetupData::setLaserDuty(int value) {
    if (!MathUtils::almostEqual(value, laserDuty)) {
        laserDuty = value;
        emit laserDutyChanged();
    }
}

int SetupData::getLaserJumpSpeed() const {
    return laserJumpSpeed;
}

void SetupData::setLaserJumpSpeed(int value) {
    if (!MathUtils::almostEqual(value, laserJumpSpeed)) {
        laserJumpSpeed = value;
        emit laserJumpSpeedChanged();
    }
}

int SetupData::getLaserMarkSpeed() const {
    return laserMarkSpeed;
}

void SetupData::setLaserMarkSpeed(int value) {
    if (!MathUtils::almostEqual(value, laserMarkSpeed)) {
        laserMarkSpeed = value;
        emit laserMarkSpeedChanged();
    }
}

int SetupData::getEncoderPulses() const {
    return encoderPulses;
}

void SetupData::setEncoderPulses(int value) {
    if (!MathUtils::almostEqual(value, encoderPulses)) {
        encoderPulses = value;
        emit encoderPulsesChanged();

    }
}

QString SetupData::getDialogMessage() const {
    return dialogMessage;
}

void SetupData::setDialogMessage(const QString& value) {
    dialogMessage = value;
    emit dialogMessageChanged();
}
