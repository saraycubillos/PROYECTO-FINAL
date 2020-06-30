#ifndef PARTICULA_H
#define PARTICULA_H

#include <QGraphicsItem>
#include <QPainter>
#include <math.h> //seno coseno raiz

class Particula: public QGraphicsItem
{
    //velocidades y posiciones afectadas por angulos, para que no haya desfase y mas presicion
    //se le dan las conidiones iniciales (atributos)
    double angulo, vx, vy,vel;
    double posx, posy;
    int radio;
    // se van a recalculas con base en las ecuaciones
    double g= 9.8;
    double delta= 0.1; //tiempo
    QString ruta;

    int r=30;
public:
    Particula();
    Particula(double an, double posxx, double  posyy , double velocidad, int r, QString path);
    //para poder saber la posicion a la que va a llegar , depende de la velocidad, antes de actualizar la posicion , la velocidad debe actualizarse
    void ActualizarPosicion();
    //primero se calcula la velocidaD Y LUEGO LAS POSICIONES SE ACTUALIZAN

    void CalcularVelocidad();
    void CalcularAceleracion(Particula par );

    double getPosy() const;
    double getPosx() const;

    int getR();
    void setR(int r);



    QRectF boundingRect() const ;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
};

#endif // PARTICULA_H
