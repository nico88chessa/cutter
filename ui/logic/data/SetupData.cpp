#include "SetupData.hpp"

#include <MathUtils.hpp>
#include <Logger.hpp>


using namespace PROGRAM_NAMESPACE;


SetupData::SetupData(QObject* parent) : QObject(parent) {
    
    traceEnter;
    
    cutHeight = 0;
    xStart = 0;
    yStart = 0;
    
    laserDuty = 0;
    laserJumpSpeed = 0;
    laserMarkSpeed = 0;
    laserMarkDelay = 0;
    laserJumpDelay = 0;
    laserPolyDelay = 0;
    laserOnDelay = 0;
    laserOffDelay = 0;
    laserPipelineDelay = 0;

    encoderPulses = 0;

    traceExit;

}

real SetupData::getCutHeight() const { return cutHeight; }

void SetupData::setCutHeight(const real& value) {
    if (!MathUtils::almostEqual(value, cutHeight)) {
        cutHeight = value;
        emit cutHeightChanged();
    }
}

real SetupData::getXStart() const { return xStart; }

void SetupData::setXStart(const real& value) {
    if (!MathUtils::almostEqual(value, xStart)) {
        xStart = value;
        emit xStartChanged();
    }
}

real SetupData::getYStart() const { return yStart; }

void SetupData::setYStart(const real& value) {
    if (!MathUtils::almostEqual(value, yStart)) {
        yStart = value;
        emit yStartChanged();
    }
}

int SetupData::getLaserDuty() const { return laserDuty; }

void SetupData::setLaserDuty(int value) {
    if (!MathUtils::almostEqual(value, laserDuty)) {
        laserDuty = value;
        emit laserDutyChanged();
    }
}

int SetupData::getLaserJumpSpeed() const { return laserJumpSpeed; }

void SetupData::setLaserJumpSpeed(int value) {
    if (!MathUtils::almostEqual(value, laserJumpSpeed)) {
        laserJumpSpeed = value;
        emit laserJumpSpeedChanged();
    }
}

int SetupData::getLaserMarkSpeed() const { return laserMarkSpeed; }

void SetupData::setLaserMarkSpeed(int value) {
    if (!MathUtils::almostEqual(value, laserMarkSpeed)) {
        laserMarkSpeed = value;
        emit laserMarkSpeedChanged();
    }
}

int SetupData::getLaserMarkDelay() const { return laserMarkDelay; }

void SetupData::setLaserMarkDelay(int value) {

    {
        laserMarkDelay = value;
        emit laserMarkDelayChanged();
    }
}

int SetupData::getLaserJumpDelay() const { return laserJumpDelay; }

void SetupData::setLaserJumpDelay(int value) {
    if (!MathUtils::almostEqual(value, laserJumpDelay)) {
        laserJumpDelay = value;
        emit laserJumpDelayChanged();
    }
}

int SetupData::getLaserPolyDelay() const { return laserPolyDelay; }

void SetupData::setLaserPolyDelay(int value) {
    if (!MathUtils::almostEqual(value, laserPolyDelay)) {
        laserPolyDelay = value;
        emit laserPolyDelayChanged();
    }
}

int SetupData::getLaserOnDelay() const { return laserOnDelay; }

void SetupData::setLaserOnDelay(int value) {
    if (!MathUtils::almostEqual(value, laserOnDelay)) {
        laserOnDelay = value;
        emit laserOnDelayChanged();
    }
}

int SetupData::getLaserOffDelay() const { return laserOffDelay; }

void SetupData::setLaserOffDelay(int value) {
    if (!MathUtils::almostEqual(value, laserOffDelay)) {
        laserOffDelay = value;
        emit laserOffDelayChanged();
    }
}

int SetupData::getLaserPipelineDelay() const { return laserPipelineDelay; }

void SetupData::setLaserPipelineDelay(int value) {
    if (!MathUtils::almostEqual(value, laserPipelineDelay)) {
        laserPipelineDelay = value;
        emit laserPipelineDelayChanged();
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

bool SetupData::getIsSendButtonEnabled() const { return isSendButtonEnabled; }

void SetupData::setIsSendButtonEnabled(bool value) {
    if (value != isSendButtonEnabled) {
        isSendButtonEnabled = value;
        emit isSendButtonEnabledChanged();
    }
}

QString SetupData::getDialogMessage() const {
    return dialogMessage;
}

void SetupData::setDialogMessage(const QString& value) {
    dialogMessage = value;
    emit dialogMessageChanged();
}
