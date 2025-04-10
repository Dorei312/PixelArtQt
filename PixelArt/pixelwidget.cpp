#include "pixelwidget.h"
#include <QPainter>
#include <QMouseEvent>
#include <QDialog>
#include <QFileDialog>

PixelWidget::PixelWidget(QWidget *parent)
    : QWidget(parent), pixels(gridSize, QVector<QColor>(gridSize, Qt::white)), currentColor(Qt::black)
{
    setFixedSize(gridSize * pixelSize, gridSize * pixelSize);
}

QSize PixelWidget::sizeHint() const
{
    return QSize(gridSize * pixelSize, gridSize * pixelSize);
}

void PixelWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    for (int y = 0; y < gridSize; ++y) {
        for (int x = 0; x < gridSize; ++x) {
            painter.setBrush(pixels[y][x]);
            painter.drawRect(x * pixelSize, y * pixelSize, pixelSize, pixelSize);
        }
    }
}

void PixelWidget::mousePressEvent(QMouseEvent *event)
{
    int x = event->x() / pixelSize;
    int y = event->y() / pixelSize;

    if (x >= 0 && x < gridSize && y >= 0 && y < gridSize) {
        if(event->button()==Qt::LeftButton){
        pixels[y][x] = currentColor;
        }
        if(event->button()==Qt::RightButton){
            pixels[y][x] = Qt::white;
        }
    update();
    }
}

void PixelWidget::setColor(const QColor &color)
{
    currentColor = color;
}

void PixelWidget::saveImage()
{
    QImage image(gridSize * pixelSize, gridSize * pixelSize, QImage::Format_ARGB32);
    image.fill(Qt::white);

    QPainter painter(&image);
    for (int y = 0; y < gridSize; ++y) {
        for (int x = 0; x < gridSize; ++x) {
            painter.setBrush(pixels[y][x]);
            painter.setPen(Qt::NoPen);
            painter.drawRect(x * pixelSize, y * pixelSize, pixelSize, pixelSize);
        }
    }

    QString filePath = QFileDialog::getSaveFileName(this, "Zapisz obraz", QDir::homePath() + "/Desktop/obraz.png", "PNG (*.png)");
    if (!filePath.isEmpty()) {
        image.save(filePath);
    }
}
