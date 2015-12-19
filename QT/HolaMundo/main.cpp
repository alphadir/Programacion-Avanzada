#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QTextEdit>


int main(int argc, char *argv[])
{
    //QGuiApplication app(argc, argv);
    QApplication app(argc, argv);
    QWidget *mi_widget=new QWidget;
    mi_widget->setGeometry(300,200,300,190);
    QLabel *mi_etiqueta=new QLabel("HOLA MUNDO \nescribe tu nombre :v",mi_widget);
    mi_etiqueta->setGeometry(30,10,100,40);
    QTextEdit *mi_editor=new QTextEdit(mi_widget);
    mi_editor->setGeometry(10,50,100,30);
    QPushButton *mi_boton=new QPushButton("SALIR",mi_widget);
    mi_boton->setGeometry(10,80,100,30);
    QObject::connect(mi_boton,SIGNAL(clicked()),&app,SLOT(quit()));
    mi_widget->show();
    return app.exec();
}
