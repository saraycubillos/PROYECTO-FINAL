#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{


    //ELEMENTOS PARA EL LANZAMIENTO DE LAS PARTÍCULAS
    timer= new QTimer;
    connect(timer,SIGNAL(timeout()), this, SLOT (mover()));
    QTimer *cronometro = new QTimer(this);
    connect(cronometro, SIGNAL(timeout()),this,SLOT(lanzarfuego()));
    cronometro->start(1000);

    QTimer *cronometro2 = new QTimer(this);
    connect(cronometro2, SIGNAL(timeout()),this,SLOT(lanzamiento()));
    cronometro2->start(1000);


    //CREANDO LA ESCENA
    ui->setupUi(this);
    scene = new QGraphicsScene;
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(0,0,400,400);

    //OBJETOS

    personaje1=new Personaje(495,410,30, ":/IMAGENES/PERSONAJE1.png");
    scene->addItem(personaje1);

    enemigo1= new Personaje (-135,415,60,":/IMAGENES/ENEMIGO.png");
   scene->addItem(enemigo1);

    lanzador= new Personaje (-40,70,60,":/IMAGENES/lanzador.png");
    scene->addItem(lanzador);


    puerta=new Objeto(465,25, 80,":/IMAGENES/PUERTA.png" );
    scene->addItem(puerta);

    llave= new Objeto (210,160,30,":/IMAGENES/llave.png");
    scene->addItem(llave);

    bolaH= new Objeto (75,160, 30,":/IMAGENES/BOLADEMETAL.png");
    scene->addItem(bolaH);

   /* muros.push_back(new Objeto(-40,500, 80,":/IMAGENES/BLOQUE.jpg"));
    scene->addItem(muros.back());
    muros.push_back(new Objeto(120,500, 80,":/IMAGENES/BLOQUE.jpg"));
    scene->addItem(muros.back());
    muros.push_back(new Objeto(270,500, 80,":/IMAGENES/BLOQUE.jpg" ));
    scene->addItem(muros.back());
    muros.push_back(new Objeto(360,500, 80,":/IMAGENES/BLOQUE.jpg"));
    scene->addItem(muros.back());
    muros.push_back(new Objeto(520,500, 80,":/IMAGENES/BLOQUE.jpg"));
    scene->addItem(muros.back());


    muros.push_back(new Objeto(-200,-55, 80,":/IMAGENES/BLOQUE.jpg"));
    scene->addItem(muros.back());
    muros.push_back(new Objeto(-200,20, 80,":/IMAGENES/BLOQUE.jpg")); //arriba, Y
    scene->addItem(muros.back());
    muros.push_back(new Objeto(-200,115, 80,":/IMAGENES/BLOQUE.jpg" )); //MURO 2 DE ABAJO
    scene->addItem(muros.back());
    muros.push_back(new Objeto(-200,275, 80,":/IMAGENES/BLOQUE.jpg"));
    scene->addItem(muros.back());
    muros.push_back(new Objeto(-200,420, 80,":/IMAGENES/BLOQUE.jpg"));
    scene->addItem(muros.back());

    muros.push_back(new Objeto(-40,-100, 80,":/IMAGENES/BLOQUE.jpg"));
    scene->addItem(muros.back());
    muros.push_back(new Objeto(120,-100, 80,":/IMAGENES/BLOQUE.jpg")); //arriba, Y
    scene->addItem(muros.back());
    muros.push_back(new Objeto(270,-100, 80,":/IMAGENES/BLOQUE.jpg" )); //MURO 2 DE ABAJO
    scene->addItem(muros.back());
    muros.push_back(new Objeto(360,-100, 80,":/IMAGENES/BLOQUE.jpg"));
    scene->addItem(muros.back());
    muros.push_back(new Objeto(520,-100, 80,":/IMAGENES/BLOQUE.jpg"));
    scene->addItem(muros.back());


    muros.push_back(new Objeto(595,-55, 80,":/IMAGENES/BLOQUE.jpg"));
    scene->addItem(muros.back());
    muros.push_back(new Objeto(595,20, 80,":/IMAGENES/BLOQUE.jpg")); //arriba, Y
    scene->addItem(muros.back());
    muros.push_back(new Objeto(595,115, 80,":/IMAGENES/BLOQUE.jpg" )); //MURO 2 DE ABAJO
    scene->addItem(muros.back());
    muros.push_back(new Objeto(595,275, 80,":/IMAGENES/BLOQUE.jpg"));
    scene->addItem(muros.back());
    muros.push_back(new Objeto(595,420, 80,":/IMAGENES/BLOQUE.jpg"));
    scene->addItem(muros.back());*/


    piedras.push_back(new Objeto(130,110,40,":/IMAGENES/piedra.png"));
   scene->addItem(piedras.back());
   piedras.push_back(new Objeto(300,220,40,":/IMAGENES/piedra.png"));
   scene->addItem(piedras.back());
   piedras.push_back(new Objeto(300,115,40,":/IMAGENES/piedra.png"));
   scene->addItem(piedras.back());
   piedras.push_back(new Objeto(130,220,40,":/IMAGENES/piedra.png"));
   scene->addItem(piedras.back());
   piedras.push_back(new Objeto(130,170,40,":/IMAGENES/piedra.png"));
   scene->addItem(piedras.back());
   piedras.push_back(new Objeto(205,110,40,":/IMAGENES/piedra.png"));
   scene->addItem(piedras.back());
   piedras.push_back(new Objeto(300,160,40,":/IMAGENES/piedra.png"));
   scene->addItem(piedras.back());



}

void MainWindow::keyPressEvent(QKeyEvent *evento)
{

    if(evento->key()==Qt::Key_A)
    {
        //lanzamiento(-40,personaje1->x(),70,personaje1->y());

       //---------GIRO DEL PERSONAJE-------
    personaje1->setTransformOriginPoint(0,0);
    //personaje1->setRotation(180);
    personaje1->izquierda();


    //---------COALISIONES-------
    if(personaje1->collidesWithItem(bolaH))
    {
            bolaH->izquierda();
    }
    if(personaje1->collidesWithItem(enemigo1))

    {
            enemigo1->izquierda();
            x = enemigo1->x();
            y = enemigo1->y();
            cuerpos.push_back(new Particula (0,  x, y ,100,10,":/IMAGENES/BOLADEFUEGO.png"));
            scene->addItem(cuerpos.back());

            timer->start(30);
    }
    for (int i=0;i<cuerpos.size();i++)
    {
        if (personaje1->collidesWithItem(cuerpos.at(i)))
           {
            scene->removeItem(cuerpos.at(i));
            cuerpos.removeOne(cuerpos.at(i));
            //vidas-=1;
            }
    }
    //-------EVALUAR COALISIONES CON MUROS-----
    for (int i=0;i<muros.size();i++)
    {
        if (personaje1->collidesWithItem(muros.at(i)))
        {

            personaje1->derecha();
        }
    }


    //-------EVALUAR COALISIONES CON PIEDRAS-----

    for (int i=0;i<piedras.size();i++)
        {
            if (personaje1->collidesWithItem(piedras.at(i)))
            {

                personaje1->derecha();
            }
        }

    //-------CAPTURAR LLAVES-----
    if (personaje1->collidesWithItem(llave))
        {

            scene->removeItem(llave);
             //llaves+=1;

        }

    //------------PUERTA--------------
    if (personaje1->collidesWithItem(puerta))
            {
                personaje1->derecha();
                //remover escena
            }


    }

    else

    if(evento->key()==Qt::Key_D)
    {
       //lanzamiento(-40,personaje1->x(),70,personaje1->y());

        //---------GIRO DEL PERSONAJE-------
        personaje1->setTransformOriginPoint(0,0);
        //personaje1->setRotation(0);
        personaje1->derecha();

        //---------COALISIONES-------
        if(personaje1->collidesWithItem(bolaH))

        {
                bolaH->derecha();
        }
        if(personaje1->collidesWithItem(enemigo1))

        {
            x = enemigo1->x();
            y = enemigo1->y();
                enemigo1->derecha();
                //bolaFuego->setPosx(personaje1->pos());
                cuerpos.push_back(new Particula (0,  x, y ,100,10,":/IMAGENES/BOLA DE FUEGO.png"));
                scene->addItem(cuerpos.back());

                timer->start(30);
        }

        for (int i=0;i<cuerpos.size();i++)
        {
            if (personaje1->collidesWithItem(cuerpos.at(i)))
               {
                scene->removeItem(cuerpos.at(i));
                cuerpos.removeOne(cuerpos.at(i));
                //vidas-=1;
                }
        }
        //-------EVALUAR COALISIONES CON MUROS-----
        for (int i=0;i<muros.size();i++)
        {
            if (personaje1->collidesWithItem(muros.at(i)))
            {



                personaje1->izquierda();
            }
        }
        //-------EVALUAR COALISIONES CON PIEDRAS-----

        for (int i=0;i<piedras.size();i++)
            {
                if (personaje1->collidesWithItem(piedras.at(i)))
                {

                    personaje1->izquierda();
                }
            }

        //-------CAPTURAR LLAVES-----
        if (personaje1->collidesWithItem(llave))
            {

                scene->removeItem(llave);
                 //llaves+=1;

            }

        //------------PUERTA--------------
        if (personaje1->collidesWithItem(puerta))
                {
                    personaje1->izquierda();
                    //remover escena
                }



    }
    else if(evento->key()==Qt::Key_W)
        {
        //lanzamiento(-40,personaje1->x(),70,personaje1->y());


            //---------GIRO DE PERSONAJE-------
        personaje1->setTransformOriginPoint(0,0);
       // personaje1->setRotation(270);
        personaje1->subir();


        //---------COALISIONES-------
        if(personaje1->collidesWithItem(bolaH))
        {
                bolaH->subir();
        }
        if(personaje1->collidesWithItem(enemigo1))

        {
                enemigo1->subir();

                //posx.rx()
                  //      posy.rx())


                //punto=enemigo1->pos();
                x = enemigo1->x();
                y = enemigo1->y();
                cuerpos.push_back(new Particula (0,  x, y ,100,10,":/IMAGENES/BOLA DE FUEGO.png"));
                scene->addItem(cuerpos.back());

                timer->start(30);
        }
        for (int i=0;i<cuerpos.size();i++)
        {
            if (personaje1->collidesWithItem(cuerpos.at(i)))
               {
                scene->removeItem(cuerpos.at(i));
                cuerpos.removeOne(cuerpos.at(i));
                //vidas-=1;
                }
        }
        //-------EVALUAR COALISIONES CON MUROS-----
        for (int i=0;i<muros.size();i++)
        {
            if (personaje1->collidesWithItem(muros.at(i)))
            {


                personaje1->bajar();
            }
        }
        //-------EVALUAR COALISIONES CON PIEDRAS-----

        for (int i=0;i<piedras.size();i++)
            {
                if (personaje1->collidesWithItem(piedras.at(i)))
                {

                    personaje1->bajar();
                }
            }

        //-------CAPTURAR LLAVES-----
        if (personaje1->collidesWithItem(llave))
            {

                scene->removeItem(llave);
                 //llaves+=1;

            }

        //------------PUERTA--------------
        if (personaje1->collidesWithItem(puerta))
                {
                    personaje1->bajar();
                    //remover escena
                }


    }
    else if(evento->key()==Qt::Key_S)
        {
        //lanzamiento(-40,personaje1->x(),70,personaje1->y());


          //---------GIRO DE PERSONAJE-------
          personaje1->setTransformOriginPoint(0,0);
          //personaje1->setRotation(90);
          personaje1->bajar();


          //---------COALISIONES-------
          if(personaje1->collidesWithItem(bolaH))
          {
                  bolaH->bajar();
          }
          if(personaje1->collidesWithItem(enemigo1))


          {

              x = enemigo1->x();
              y = enemigo1->y();
                  enemigo1->bajar();
                  cuerpos.push_back(new Particula (0,  x, y ,100,10,":/IMAGENES/BOLA DE FUEGO.png"));
                  scene->addItem(cuerpos.back());

                  timer->start(30);
          }
          for (int i=0;i<cuerpos.size();i++)
          {
              if (personaje1->collidesWithItem(cuerpos.at(i)))
                 {
                  scene->removeItem(cuerpos.at(i));
                  cuerpos.removeOne(cuerpos.at(i));
                  //vidas-=1;
                  }
          }

            //-------EVALUAR COALISIONES CON MUROS-----

          for (int i=0;i<muros.size();i++)
          {
              if (personaje1->collidesWithItem(muros.at(i)))
              {

                  personaje1->subir();
              }
          }
          //-------EVALUAR COALISIONES CON PIEDRAS-----

          for (int i=0;i<piedras.size();i++)
              {
                  if (personaje1->collidesWithItem(piedras.at(i)))
                  {

                      personaje1->subir();
                  }
              }

          //-------CAPTURAR LLAVES-----
          if (personaje1->collidesWithItem(llave))
              {

                  scene->removeItem(llave);
                   //llaves+=1;

              }

          //------------PUERTA--------------
          if (personaje1->collidesWithItem(puerta))
                  {
                      personaje1->subir();
                      //remover escena
                  }


        }


    qDebug()<<personaje1->pos()<<personaje1->x();
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::mover()
{
    for (QList<Particula*> :: iterator it=cuerpos.begin(); it!=cuerpos.end(); it++)
    {
        (*it)->CalcularVelocidad();
        (*it)->ActualizarPosicion();


    }
    for (int i=0;i<cuerpos.size();i++)
    {
        if (personaje1->collidesWithItem(cuerpos.at(i)))
           {
            scene->removeItem(cuerpos.at(i));
            cuerpos.removeOne(cuerpos.at(i));
            //vidas-=1;
            }
    }


}

/*void MainWindow::on_pushButton_clicked()
{



    /*cuerpos.push_back(new Particula (0,enemigo1->pos(),  enemigo1->pos(),100,":/IMAGENES/BOLADEFUEGO.png")); //radianes, x , y, velocidad
    scene->addItem(cuerpos.back());

    timer->start(30);
}

void MainWindow:: lanzamiento (int xinicial, int xfinal, int yinicial, int yfinal)
{



    while ((xinicial!=xfinal) or (yinicial!=yfinal))
    {

        if (xinicial<xfinal)
        {

            xinicial++;

            if(yinicial<yfinal)
            {
                yinicial++;

            }

            if (yinicial>yfinal)
            {
                yinicial--;

            }



        }
        //cout<<" PATH: "<<"( "<<xinicial<<" ; "<<yfinal<<" ) "<<endl;
        else
        if(xinicial>xfinal)

        {

            xinicial--;
            if(yinicial<yfinal)
            {
                yinicial++;

            }
            if (yinicial>yfinal)
            {
                yinicial--;

            }



            }

        if (i==1)
        {
            cuerpos.push_back(new Particula (0,  xinicial, yinicial,100,10,":/IMAGENES/TUMBLEWEED.png"));
            scene->addItem(cuerpos.back());

            timer->start(60);

        }

        if(i==100)
        {
            cuerpos.push_back(new Particula (0,  xinicial, yinicial,100,10,":/IMAGENES/TUMBLEWEED.png"));
            scene->addItem(cuerpos.back());

            timer->start(60);
            i=0;
        }

        i++;

}




}
*/

void MainWindow::lanzarfuego()
    {

        x = enemigo1->x();
        y = enemigo1->y();
       cuerpos.push_back(new Particula (0,x, y,100,30,":/IMAGENES/BOLADEFUEGO.png"));
        scene->addItem(cuerpos.back());

        timer->start(30);
    }
