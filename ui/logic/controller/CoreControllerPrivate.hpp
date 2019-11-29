#ifndef CORECONTROLLERPRIVATE_HPP
#define CORECONTROLLERPRIVATE_HPP

#include <QAbstractListModel>
#include <QObject>
#include <QQmlEngine>

#include <configure.h>


namespace PROGRAM_NAMESPACE {

class CoreController;

class MenuItem {
    Q_GADGET
    Q_PROPERTY(QString pLabel READ getLabel WRITE setLabel)
    Q_PROPERTY(QString pIconPath READ getIconPath WRITE setIconPath)


private:
    QString label;
    QString iconPath;

public:
    MenuItem();
    MenuItem(const QString& label, const QString& iconPath);

public slots:
    QString getLabel() const;
    void setLabel(const QString& value);
    QString getIconPath() const;
    void setIconPath(const QString& value);

};


class MenuListModel : public QAbstractListModel {
    Q_OBJECT

private:
    QList<MenuItem> items;

    enum MenuRoles {
        LABEL_ROLE = Qt::UserRole + 1,
        ICON_ROLE
    };

public:
    int rowCount(const QModelIndex& parent) const;
    QVariant data(const QModelIndex& index, int role) const;
    void appendData(const MenuItem& item);

    QHash<int, QByteArray> roleNames() const;
};


class CoreControllerPrivate : public QObject {
    Q_OBJECT
    friend class CoreController;

public:
    using Ptr = CoreControllerPrivate*;
    using ConstPtr = const CoreControllerPrivate*;

private:
    CoreController* qPtr;
    QScopedPointer<MenuListModel> model;

public:
    explicit CoreControllerPrivate(QObject* parent = Q_NULLPTR);

public:
    ~CoreControllerPrivate();

};


}

//Q_DECLARE_METATYPE(PROGRAM_NAMESPACE::MenuItem)


#endif // CORECONTROLLERPRIVATE_HPP
