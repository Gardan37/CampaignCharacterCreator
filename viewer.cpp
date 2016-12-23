#include "viewer.h"
#include "ui_viewer.h"

#include <QMetaObject>
#include <QMetaProperty>

Viewer::Viewer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Viewer)
{
    ui->setupUi(this);

    ui->viewtype->insertItem(0, "No selection");
    ui->viewtype->insertItem(1, "TableView");
    ui->viewtype->insertItem(2, "TreeView");
    ui->viewtype->insertItem(3, "ListView");

    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setRowCount(10);
    ui->tableWidget->setHorizontalHeaderLabels({"Field", "Type", "Value"});


    connect(ui->viewtype, SIGNAL(currentIndexChanged(int)), this, SLOT(viewTypeChanged(int)));
    connect(ui->viewSystem, SIGNAL(currentIndexChanged(int)), this, SLOT(viewSystemChanged(int)));

}

void Viewer::addComponent(Component *component)
{
    int id = component->element();
    m_components.insert(id, component);
    int boxId = ui->viewSystem->count();
    ui->viewSystem->insertItem(boxId, component->name());
    ui->viewSystem->setItemData(boxId, id);
}

Viewer::~Viewer()
{
    delete ui;
}

void Viewer::init()
{
    addComponent(0, 345);
    addComponent(2, "Nimi");
    addComponent(3, 5.5);
    addComponent(6, true);

    foreach (auto component, m_components.values())
    {
        ui->listWidget->addItem(component->name());
    }

    viewSystemChanged(3);
    viewTypeChanged(3);

}

void Viewer::addComponent(int id, QVariant value)
{
    Component *component = new Component(id, value);
    m_components.insert(id, component);
    int boxId = ui->viewSystem->count();
    ui->viewSystem->insertItem(boxId, component->name());
    ui->viewSystem->setItemData(boxId, id);
}

void Viewer::viewTypeChanged(int selection)
{
    switch (selection)
    {
    case 0: // No Selection
        ui->tableView->hide();
        ui->treeView->hide();
        ui->listWidget->hide();
        break;
    case 1: // Table
        ui->tableView->show();
        ui->treeView->hide();
        ui->listWidget->hide();
        break;
    case 2: //Tree:
        ui->tableView->hide();
        ui->treeView->show();
        ui->listWidget->hide();
        break;
    case 3: //List:
        ui->tableView->hide();
        ui->treeView->hide();
        ui->listWidget->show();
        break;
    default:
        break;
    }
}

void Viewer::viewSystemChanged(int selection)
{
    ui->tableWidget->clearContents();
    QVariant userData = ui->viewSystem->itemData(selection);
    Component *component = m_components.value(userData.toInt());
    const QMetaObject *metaobject = component->metaObject();
    int count = metaobject->propertyCount();
    for (int i=0; i<count; ++i)
    {
        QMetaProperty metaproperty = metaobject->property(i);
        const char *name = metaproperty.name();
        QVariant property = component->property(name);
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(name));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(property.typeName()));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(property.toString()));
    }
}

