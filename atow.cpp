#include "atow.h"
#include "ui_atow.h"
#include "staticdata.h"

atow::atow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::atow)
{
    ui->setupUi(this);

    DATA->init();

    editor = new Editor(parent);
    connect(ui->boxEditor, SIGNAL(clicked(bool)), editor, SLOT(setVisible(bool)));

    viewer = new Viewer(parent);
    viewer->init();
    connect(ui->boxViewer, SIGNAL(clicked(bool)), viewer, SLOT(setVisible(bool)));

}

atow::~atow()
{
    delete viewer;
    delete editor;
    delete ui;
}
