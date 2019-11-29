#ifndef APPLICATIONDATA_HPP
#define APPLICATIONDATA_HPP

#include <QObject>
#include <QQmlEngine>

#include <common/FactoryQml.hpp>

#include <configure.h>


namespace PROGRAM_NAMESPACE {

class ApplicationData : public QObject {
    Q_OBJECT
    Q_DISABLE_COPY(ApplicationData)
    DECL_QML_SINGLETON_INSTANCEABLE()

    Q_PROPERTY(QString pApplicationName READ getApplicationName WRITE setApplicationName NOTIFY applicationNameChanged)
    Q_PROPERTY(QString pApplicationVersion READ getApplicationVersion WRITE setApplicationVersion NOTIFY applicationVersionChanged)


private:
    QString applicationName;
    QString applicationVersion;

private:
    explicit ApplicationData(QObject* parent = Q_NULLPTR);

public:
    ~ApplicationData();

public slots:
    QString getApplicationName() const { return applicationName; }
    void setApplicationName(const QString& value) { applicationName = value; }

    QString getApplicationVersion() const { return applicationVersion; }
    void setApplicationVersion(const QString& value) { applicationVersion = value; }

signals:
    void applicationNameChanged();
    void applicationVersionChanged();

};

}

#endif // APPLICATIONDATA_HPP
