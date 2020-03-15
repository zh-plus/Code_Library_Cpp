//
// Created by 10578 on 3/15/2020.
//

#include <QApplication>
#include <QDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    auto *dlg = new QDialog();
    dlg->setWindowTitle("Hello World");
    dlg->show();
    return QApplication::exec();
}