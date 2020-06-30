#ifndef PERSONAJE_H
#define PERSONAJE_H
#include <QGraphicsItem>
#include <QPainter>
class Personaje : public QGraphicsItem
{
public:
    int radio;
    int posx, posy;
    QString ruta;

public:

    Personaje();
    Personaje (  int x, int y , int r, QString path);
    int getR();
    void setR(int radio);
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

#endif // PERSONAJE_H
