#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QList>
#include <personaje.h>
#include <objeto.h>
#include <particula.h>
#include <QKeyEvent>
#include <QDebug>
#include <QTimer>
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

    QList<Objeto*> muros;
    QList<Objeto*> piedras;

private slots:


    //SLOTS DE LA PARTÍCULA
    void mover();

    //void on_pushButton_clicked();

    //void lanzamiento (int xi, int xf, int yi, int yf);

     void lanzarfuego();

private:

    Ui::MainWindow *ui;
    QGraphicsScene *scene;

    //PARTÍCULA
    QTimer  *timer;
    Particula *cuerpo;
    QList<Particula*>cuerpos;

    //OBJETOS
    Personaje *personaje1;
    Personaje *enemigo1;
    Personaje *lanzador;
    Objeto *puerta;
    Objeto *bolaH;

    Objeto *bolaFuego;
    Objeto *llave;
    double x;
    double y;
    int i=0;


    void keyPressEvent(QKeyEvent * evento);



};
#endif // MAINWINDOW_H
