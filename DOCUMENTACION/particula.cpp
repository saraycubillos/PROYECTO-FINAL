#include "particula.h"

double Particula::getPosy() const
{
    return posy;
}

double Particula::getPosx() const
{
    return posx;
}

int Particula::getR()
{
    return radio;
}

void Particula::setR(int r)
{
    radio=r;
}
QRectF Particula::boundingRect() const
{
    return QRectF(-radio,-radio,2*radio,2*radio);
}

void Particula::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap;

    pixmap.load(ruta);

    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}


Particula::Particula()
{

}

Particula::Particula(double an, double posxx, double posyy, double velocidad,int r, QString path)
{
    angulo=an;
    posx=posxx;
    posy=posyy;
    vel=velocidad;
    ruta=path;
    radio=r;
    setPos(posx, posy);

}

void Particula::ActualizarPosicion()
{
    posx+=vx*delta;

    setPos(posx,posy);
}

void Particula::CalcularVelocidad()
{

    vx=vel*cos(angulo);


}

