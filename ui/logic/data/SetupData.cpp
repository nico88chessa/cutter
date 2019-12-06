#include "SetupData.hpp"

#include <MathUtils.hpp>

using namespace PROGRAM_NAMESPACE;

SetupData::SetupData(QObject* parent) : QObject(parent) {

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

int SetupData::getLaserPower() const {
    return laserPower;
}

void SetupData::setLaserPower(int value) {
    if (!MathUtils::almostEqual(value, laserPower)) {
        laserPower = value;
        emit laserPowerChanged();
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
