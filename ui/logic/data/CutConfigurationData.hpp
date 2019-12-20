#ifndef CUTCONFIGURATIONDATA_HPP
#define CUTCONFIGURATIONDATA_HPP

#include <QObject>
#include <QQmlEngine>

#include <common/FactoryQml.hpp>

#include <configure.h>


namespace PROGRAM_NAMESPACE {

class CutConfigurationData : public QObject {
    Q_OBJECT
    Q_DISABLE_COPY(CutConfigurationData)
    DECL_QML_SINGLETON_INSTANCEABLE()

private:
    CutConfigurationData(QObject* parent = Q_NULLPTR);

public:
    ~CutConfigurationData();

};

}


#endif // CUTCONFIGURATIONDATA_HPP
