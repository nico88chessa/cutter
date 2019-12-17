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

    Q_PROPERTY(int pEncoderPulses READ getEncoderPulses WRITE setEncoderPulses NOTIFY encoderPulsesChanged)

    Q_PROPERTY(QString pDialogMessage READ getDialogMessage WRITE setDialogMessage NOTIFY dialogMessageChanged)

public:
    using Ptr = SetupData*;
    using ConstPtr = const SetupData*;

private:
    real cutHeight;
    real xStart;
    real yStart;

    int laserPower;
    int laserDuty;
    int laserJumpSpeed;
    int laserMarkSpeed;

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

signals:
    void cutHeightChanged();
    void xStartChanged();
    void yStartChanged();

    void laserPowerChanged();
    void laserDutyChanged();
    void laserJumpSpeedChanged();
    void laserMarkSpeedChanged();

    void encoderPulsesChanged();

    void dialogMessageChanged();

};

}

#endif // SETUPDATA_HPP
