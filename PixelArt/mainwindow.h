#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "pixelwidget.h"  // Upewnij się że masz cudzysłowy, nie <>

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    PixelWidget *pixelWidgetInstance;  // Zmienna zadeklarowana tutaj!
};

#endif // MAINWINDOW_H
