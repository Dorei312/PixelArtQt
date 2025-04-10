#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pixelwidget.h"

#include <QVBoxLayout>
#include <QPushButton>
#include <QColorDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    pixelWidgetInstance = new PixelWidget(this);


    QPushButton *colorButton = new QPushButton("Wybierz kolor", this);
    QPushButton *saveButton = new QPushButton("Zapisz obraz", this);

    connect(colorButton, &QPushButton::clicked, this, [=]() {
        QColor color = QColorDialog::getColor(Qt::black, this);
        if (color.isValid()) {
            pixelWidgetInstance->setColor(color);
        }
    });


    QWidget *central = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(central);
    layout->addWidget(colorButton);
    layout->addWidget(pixelWidgetInstance);
    layout->addWidget(saveButton);

    connect(saveButton, &QPushButton::clicked, this, [=](){
        pixelWidgetInstance->saveImage();
    });

    setCentralWidget(central);
}

MainWindow::~MainWindow()
{
    delete ui;
}
