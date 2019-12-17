#ifndef SETUPDATA_HPP
#define SETUPDATA_HPP

#include <QObject>

#include <Types.hpp>


namespace PROGRAM_NAMESPACE {


class SetupData : public QObject {
    Q_OBJECT

    Q_PROPERTY(real pCutHeight READ getCutHeight WRITE setCutHeight NOTIFY cutHeightChanged)
    Q_PROPERTY(real pXStart READ getXStart WRITE setXStart NOTIFY xStartChanged)
    Q_PROPERTY(real pYStart READ getYStart WRITE setYStart NOTIFY yStartChanged)

    Q_PROPERTY(int pLaserDuty READ getLaserDuty WRITE setLaserDuty NOTIFY laserDutyChanged)
    Q_PROPERTY(int pLaserJumpSpeed READ getLaserJumpSpeed WRITE setLaserJumpSpeed NOTIFY laserJumpSpeedChanged)
    Q_PROPERTY(int pLaserMarkSpeed READ getLaserMarkSpeed WRITE setLaserMarkSpeed NOTIFY laserMarkSpeedChanged)

    Q_PROPERTY(int pLaserMarkDelay READ getLaserMarkDelay WRITE setLaserMarkDelay NOTIFY laserMarkDelayChanged)
    Q_PROPERTY(int pLaserJumpDelay READ getLaserJumpDelay WRITE setLaserJumpDelay NOTIFY laserJumpDelayChanged)
    Q_PROPERTY(int pLaserPolyDelay READ getLaserPolyDelay WRITE setLaserPolyDelay NOTIFY laserPolyDelayChanged)
    Q_PROPERTY(int pLaserOnDelay READ getLaserOnDelay WRITE setLaserOnDelay NOTIFY laserOnDelayChanged)
    Q_PROPERTY(int pLaserOffDelay READ getLaserOffDelay WRITE setLaserOffDelay NOTIFY laserOffDelayChanged)
    Q_PROPERTY(int pLaserPipelineDelay READ getLaserPipelineDelay WRITE setLaserPipelineDelay NOTIFY laserPipelineDelayChanged)

    Q_PROPERTY(int pEncoderPulses READ getEncoderPulses WRITE setEncoderPulses NOTIFY encoderPulsesChanged)

    Q_PROPERTY(QString pDialogMessage READ getDialogMessage WRITE setDialogMessage NOTIFY dialogMessageChanged)

public:
    using Ptr = SetupData*;
    using ConstPtr = const SetupData*;

private:
    real cutHeight;
    real xStart;
    real yStart;

    int laserDuty;
    int laserJumpSpeed;
    int laserMarkSpeed;
    int laserMarkDelay;
    int laserJumpDelay;
    int laserPolyDelay;
    int laserOnDelay;
    int laserOffDelay;
    int laserPipelineDelay;

    int encoderPulses;

    QString dialogMessage;

public:
    explicit SetupData(QObject* parent = Q_NULLPTR);

    real getCutHeight() const;
    void setCutHeight(const real& value);

    real getXStart() const;
    void setXStart(const real& value);

    real getYStart() const;
    void setYStart(const real& value);

    int getLaserDuty() const;
    void setLaserDuty(int value);

    int getLaserJumpSpeed() const;
    void setLaserJumpSpeed(int value);

    int getLaserMarkSpeed() const;
    void setLaserMarkSpeed(int value);

    int getEncoderPulses() const;
    void setEncoderPulses(int value);

    QString getDialogMessage() const;
    void setDialogMessage(const QString& value);

    int getLaserMarkDelay() const;
    void setLaserMarkDelay(int value);

    int getLaserJumpDelay() const;
    void setLaserJumpDelay(int value);

    int getLaserPolyDelay() const;
    void setLaserPolyDelay(int value);

    int getLaserOnDelay() const;
    void setLaserOnDelay(int value);

    int getLaserOffDelay() const;
    void setLaserOffDelay(int value);

    int getLaserPipelineDelay() const;
    void setLaserPipelineDelay(int value);

signals:
    void cutHeightChanged();
    void xStartChanged();
    void yStartChanged();

    void laserPowerChanged();
    void laserDutyChanged();
    void laserJumpSpeedChanged();
    void laserMarkSpeedChanged();

    void laserMarkDelayChanged();
    void laserJumpDelayChanged();
    void laserPolyDelayChanged();
    void laserOnDelayChanged();
    void laserOffDelayChanged();
    void laserPipelineDelayChanged();

    void encoderPulsesChanged();

    void dialogMessageChanged();

};

}

#endif // SETUPDATA_HPP
