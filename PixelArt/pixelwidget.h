#ifndef PIXELWIDGET_H
#define PIXELWIDGET_H

#include <QWidget>
#include <QColor>
#include <QVector>

class PixelWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PixelWidget(QWidget *parent = nullptr);

    QSize sizeHint() const override;

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

private:
    static const int gridSize = 16;
    static const int pixelSize = 30;

    QVector<QVector<QColor>> pixels;
    QColor currentColor;

public slots:
    void setColor(const QColor &color);
    void saveImage();
};

#endif // PIXELWIDGET_H
