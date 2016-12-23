#ifndef ATOW_H
#define ATOW_H

#include "editor.h"
#include "viewer.h"

#include <QMainWindow>
#include "QComboBox"

namespace Ui {
class atow;
}

class atow : public QMainWindow
{
    Q_OBJECT

public:
    explicit atow(QWidget *parent = 0);
    ~atow();

private slots:

private:
    Ui::atow *ui;

    Editor *editor;
    Viewer *viewer;
};

#endif // ATOW_H
