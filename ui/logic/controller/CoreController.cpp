#include "CoreController.hpp"
#include "CoreControllerPrivate.hpp"

#include <Logger.hpp>


using namespace PROGRAM_NAMESPACE;


/*
 * MENU ITEM
 */

MenuItem::MenuItem() : MenuItem("", MenuKeyType::NONE) { }

MenuItem::MenuItem(const QString& label, MenuKeyType key) :
    label(label), key(key) {

    traceEnter;
    traceExit;

}

QString MenuItem::getLabel() const { return label; }
void MenuItem::setLabel(const QString& value) { label = value; }

MenuKeyType MenuItem::getKey() const { return key; }
void MenuItem::setKey(const MenuKeyType& value) { key = value; }



/*
 * MENU LIST MODEL
 */

int MenuListModel::rowCount(const QModelIndex& parent) const {

    traceEnter;
    traceExit;
    return items.size();

}

QVariant MenuListModel::data(const QModelIndex& index, int role) const {

    traceEnter;

    const MenuItem& bean = items.at(index.row());
    switch (role) {
    case LABEL_ROLE: return bean.getLabel();
    case KEY_ROLE: return QVariant::fromValue<MenuKeyType>(bean.getKey());
    default: return QVariant();

    }
    traceExit;

}

void MenuListModel::appendData(const MenuItem& item) {

    traceEnter;
    int size = this->rowCount(QModelIndex());
    beginInsertRows(QModelIndex(), size, size);
    items.append(item);
    endInsertRows();
    traceExit;

}

QHash<int, QByteArray> MenuListModel::roleNames() const {

    traceEnter;

    QHash<int, QByteArray> roles;
    roles[LABEL_ROLE] = "pLabelRole";
    roles[KEY_ROLE] = "pKeyRole";

    traceExit;
    return roles;
}



/*
 * CORE CONTROLLER PRIVATE
 */

CoreControllerPrivate::CoreControllerPrivate(QObject* parent) : QObject(parent), model(new MenuListModel()) {

    traceEnter;
    model->appendData(MenuItem("uno", MenuKeyType::SETUP));
    model->appendData(MenuItem("due", MenuKeyType::SYSTEM_STATUS));
    model->appendData(MenuItem("tre", MenuKeyType::SETTINGS));
    model->appendData(MenuItem("quattro", MenuKeyType::INFO));
    traceExit;

}

CoreControllerPrivate::~CoreControllerPrivate() {

    traceEnter;
    traceExit;

}



/*
 * CORE CONTROLLER
 */

CoreController::CoreController(QObject* parent) : QObject(parent), dPtr(new CoreControllerPrivate()) {

    traceEnter;
    dPtr->qPtr = this;

    qRegisterMetaType<MenuListModel*>("MenuListModel*");
    qRegisterMetaType<PROGRAM_NAMESPACE::MenuListModel*>("cutter::MenuListModel*");
    traceExit;

}

MenuListModel* CoreController::getMenuModel() const {

    traceEnter;
    return dPtr->model.data();
    traceExit;

}

CoreController::~CoreController() {

    traceEnter;
    traceExit;

}

void CoreController::test() {
    traceEnter;
    traceExit;
}
