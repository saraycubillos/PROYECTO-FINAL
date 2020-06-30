#ifndef OBJETO_H
#define OBJETO_H

#include <QGraphicsItem>
#include <QPainter>
class Objeto  : public QGraphicsItem
{

    int radio;
    int posx, posy;
    QString ruta;

public:
    Objeto();
    Objeto(int x, int y, int r, QString ruta);
    int getR();
    void setR(int r);
    int getPosx();
    void setPosx(int px);
    int getPosy();
    void setPosy(int py);
    void subir();
    void bajar();
    void derecha();
    void izquierda();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
};

#endif // OBJETO_H
