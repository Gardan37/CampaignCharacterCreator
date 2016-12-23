#ifndef VIEWER_H
#define VIEWER_H

#include "component.h"

#include <QWidget>
#include <QComboBox>

namespace Ui {
class Viewer;
}

class Viewer : public QWidget
{
    Q_OBJECT

public:
    enum ViewType { Table, Tree, List };

    explicit Viewer(QWidget *parent = 0);
    ~Viewer();
    void init();

private slots:
    void viewTypeChanged(int selection);
    void viewSystemChanged(int selection);
    void addComponent(Component *component);

private:
    void addComponent(int id, QVariant value);

    Ui::Viewer *ui;
    QMap<int, Component *> m_components;

};

#endif // VIEWER_H
