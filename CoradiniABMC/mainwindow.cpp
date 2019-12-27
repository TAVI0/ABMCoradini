#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include "QMessageBox"
#include <QTextStream>

#include <QPrinter>
#include <QPrintDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->widgetMenu->hide();
    ui->widgetLista->hide();
    ui->widgetBuscar->hide();
    ui->widgetVender->hide();
    ui->widgetAgregar->hide();
    ui->widgetEncontrado->hide();
    ui->widgetAdicional->hide();
    ui->widgetCantidad->hide();

    ui->widgetAuxiliar->hide();

    ui->labelMenuTitulo->setText(" ");

    setGeometry(0,0,440,250);
    setMaximumSize(440,250);
    setMinimumSize(440,250);

    ui->widgetLista->setGeometry(10,10,440,250);
    ui->widgetMenu->setGeometry(110,30,550,390);
    ui->widgetLista->setGeometry(110,30,550,390);
    ui->widgetBuscar->setGeometry(110,30,550,390);
    ui->widgetVender->setGeometry(110,30,550,390);
    ui->widgetAgregar->setGeometry(110,30,550,390);
    ui->widgetEncontrado->setGeometry(110,30,550,390);
    ui->widgetAdicional->setGeometry(110,30,550,390);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ButtonLoginIngresar_clicked()
{
    QString user= ui->lineLoginUsuario->text();
    QString contra= ui->lineLoginContra->text();
    QString userArch;
    QString contraArch;

    QFile arch("data.dt");

    if (arch.open(QIODevice::ReadOnly|QIODevice::Text)) {
        userArch=arch.readLine();
        userArch.chop(1);
        contraArch=arch.readLine();
        contraArch.chop(1);
        if(user==userArch&&contra==contraArch){
            ui->widgetLogin->hide();
            ui->widgetMenu->show();
            ui->widgetMenu->setGeometry(0,0,660,420);
            setMaximumSize(660,420);
            setMinimumSize(660,420);
        }else {
            QMessageBox::warning(0,"Advertencia","Nombre de usuario o contraseña incorrectos");
        }
        arch.close();
    }}

void MainWindow::on_ButonMenuAgregar_clicked()
{
    ui->ButtonMenuBuscar->hide();
    ui->ButonMenuAgregar->hide();
    ui->ButtonMenuVender->hide();

    ui->widgetLista->hide();
    ui->widgetBuscar->hide();
    ui->widgetVender->hide();
    ui->widgetEncontrado->hide();
    ui->widgetAgregar->show();
    ui->ButonAgregarAceptar->setText("AGREGAR");
    ui->labelMenuTitulo->setText("AGREGAR");


    ui->lineAgregarCodbarras->clear();
    ui->lineAgregarNombre->clear();
    ui->lineAgregarMarca->clear();
    ui->lineAgregarProve->clear();
    ui->lineAgregarDescrip->clear();
    ui->lineAgregarPrecio->clear();
    ui->lineAgregarCantidad->clear();

    QFile archtemp("inventario.txt");
    QString idToInt;
    QString renglon;
    int idInt;
    if (archtemp.open(QIODevice::ReadOnly|QIODevice::Text)) {
        while(!archtemp.atEnd()){
            idToInt=archtemp.readLine();
            for (int i=0;i<=7;i++) {
                renglon=archtemp.readLine();}
        }
        idInt=idToInt.toInt();
        idInt++;
        ui->lebelAgregarNumid->setNum(idInt);
        archtemp.close();
 }}

void MainWindow::on_ButonAgregarAceptar_clicked()
{
    if(ui->ButonAgregarAceptar->text()=="AGREGAR"){
       QString id = ui->lebelAgregarNumid->text();
       QString codbarras = ui->lineAgregarCodbarras->text();
       QString nombre = ui->lineAgregarNombre->text();
       QString marca = ui->lineAgregarMarca->text();
       QString prove = ui->lineAgregarProve->text();
       QString descri = ui->lineAgregarDescrip->text();
       QString precio = ui->lineAgregarPrecio->text();
       QString cantidad = ui->lineAgregarCantidad->text();

       nombre = nombre.toUpper();
       marca = marca.toUpper();
       prove = prove.toUpper();
       descri = descri.toUpper();

       if(ui->lineAgregarCodbarras->text().isEmpty()){
           QMessageBox::warning(0,"Advertencia","Ingrese un codigo de barras");
       }else if (ui->lineAgregarNombre->text().isEmpty()) {
           QMessageBox::warning(0,"Advertencia","Ingrese un Nombre");
       }else if (ui->lineAgregarMarca->text().isEmpty()) {
           QMessageBox::warning(0,"Advertencia","Ingrese una Marca");
       }else if (ui->lineAgregarProve->text().isEmpty()) {
           QMessageBox::warning(0,"Advertencia","Ingrese un proveedor");
       }else if (ui->lineAgregarDescrip->text().isEmpty()) {
           QMessageBox::warning(0,"Advertencia","Ingrese una descripcion");
       }else if (ui->lineAgregarPrecio->text().isEmpty()) {
           QMessageBox::warning(0,"Advertencia","Ingrese un precio");
       }else if (ui->lineAgregarCantidad->text().isEmpty()) {
           QMessageBox::warning(0,"Advertencia","Ingrese una cantidad");
       }else {

       QFile arch("inventario.txt");
       if (arch.open(QIODevice::Append|QIODevice::Text)){
           QTextStream out (&arch);
           out<<id<<"\n";
           out<<codbarras<< "\n";
           out<<nombre<< "\n";
           out<<marca<< "\n";
           out<<prove<< "\n";
           out<<descri<< "\n";
           out<<precio<< "\n";
           out<<cantidad<< "\n";
           out<< "*\n";

           arch.close();
           QMessageBox::warning(0,"Aviso","SE A AGREGADO EL PRODUCTO ");
       }
       int idInt=id.toInt();
       idInt++;
       ui->lebelAgregarNumid->setNum(idInt);
       ui->lineAgregarCodbarras->clear();
       ui->lineAgregarNombre->clear();
       ui->lineAgregarMarca->clear();
       ui->lineAgregarProve->clear();
       ui->lineAgregarDescrip->clear();
       ui->lineAgregarPrecio->clear();
       ui->lineAgregarCantidad->clear();
   }}

   if(ui->ButonAgregarAceptar->text()=="MODIFICAR"){
       QString id = ui->lebelAgregarNumid->text();
       QString codbarras = ui->lineAgregarCodbarras->text();
       QString nombre = ui->lineAgregarNombre->text();
       QString marca = ui->lineAgregarMarca->text();
       QString prove = ui->lineAgregarProve->text();
       QString descri = ui->lineAgregarDescrip->text();
       QString precio = ui->lineAgregarPrecio->text();
       QString cantidad = ui->lineAgregarCantidad->text();

       nombre = nombre.toUpper();
       marca = marca.toUpper();
       prove = prove.toUpper();
       descri = descri.toUpper();
       if(ui->lineAgregarCodbarras->text().isEmpty()){
           QMessageBox::warning(0,"Advertencia","Ingrese un codigo de barras");
       }else if (ui->lineAgregarNombre->text().isEmpty()) {
           QMessageBox::warning(0,"Advertencia","Ingrese un Nombre");
       }else if (ui->lineAgregarMarca->text().isEmpty()) {
           QMessageBox::warning(0,"Advertencia","Ingrese una Marca");
       }else if (ui->lineAgregarProve->text().isEmpty()) {
           QMessageBox::warning(0,"Advertencia","Ingrese un proveedor");
       }else if (ui->lineAgregarDescrip->text().isEmpty()) {
           QMessageBox::warning(0,"Advertencia","Ingrese una descripcion");
       }else if (ui->lineAgregarPrecio->text().isEmpty()) {
           QMessageBox::warning(0,"Advertencia","Ingrese un precio");
       }else if (ui->lineAgregarCantidad->text().isEmpty()) {
           QMessageBox::warning(0,"Advertencia","Ingrese una cantidad");
       }else {
           QFile arch("inventario.txt");
           QFile arch2("inventario.tmp");
           if (arch.open(QIODevice::ReadOnly|QIODevice::Text) && arch2.open(QIODevice::WriteOnly|QIODevice::Text)) {
               QTextStream out (&arch2);
               QString idEnArch;
               QString renglon;

               while (!arch.atEnd()) {
                   idEnArch = arch.readLine();
                   idEnArch.chop(1);
                   out << idEnArch << "\n";

                   do {
                       renglon = QString::fromLatin1(arch.readLine());
                       renglon.chop(1);
                       if (id != idEnArch) {
                           out << renglon << "\n";
                       }
                   } while (renglon != "*");
                   if (id == idEnArch) {
                       out << codbarras << "\n";
                       out << nombre << "\n";
                       out << marca << "\n";
                       out << prove << "\n";
                       out << descri << "\n";
                       out << precio << "\n";
                       out << cantidad << "\n";
                       out << "*\n";
                   }
               }
               arch.close();
               arch2.close();
               arch.remove();
               arch2.rename("inventario.txt");
               QMessageBox::warning(0,"Aviso","SE HA MODIFICADO EL PRODUCTO");
 }}}}

void MainWindow::on_ButonAgregarCancelar_clicked()
{

    ui->widgetAgregar->hide();
    if(ui->ButonAgregarAceptar->text()=="AGREGAR"){
        ui->ButtonMenuBuscar->show();
        ui->ButonMenuAgregar->show();
        ui->ButtonMenuVender->show();
    }

    if(ui->ButonAgregarAceptar->text()=="MODIFICAR"){
        ui->widgetEncontrado->show();
 }}

void MainWindow::on_ButtonMenuBuscar_clicked()
{
    ui->ButtonMenuBuscar->hide();
    ui->ButonMenuAgregar->hide();
    ui->ButtonMenuVender->hide();

    ui->widgetLista->hide();
    ui->widgetVender->hide();
    ui->widgetAgregar->hide();
    ui->widgetEncontrado->hide();
    ui->widgetBuscar->show();
    ui->labelListaIDAUX->setText("BUSCAR");
    ui->ButonAgregarAceptar->setText("MODIFICAR");
    ui->ButtonEncontradoModificar->setText("MODIFICAR");
    ui->labelMenuTitulo->setText("BUSCAR");
}

void MainWindow::on_ButtonBuscarID_clicked()
{
    QString id = ui->lineBuscarID->text();
    QString idArch;
    QString codigo;
    QString nombre;
    QString marca;
    QString prove;
    QString descri;
    QString precio;
    QString cantidad;
    QString renglon;

    QString direccion="inventario.txt";
    /*
    if(ui->labelMenuTitulo->text()=="BUSCAR"){
    direccion="inventario.txt";
    }
    if(ui->labelMenuTitulo->text()=="VENDER"){
    direccion="cloninvent.txt";
    }
*/

    QFile arch(direccion);
    if (ui->lineBuscarID->text().isEmpty()){
        QMessageBox::warning(0,"Alerta","INGRESE UN ID PARA BUSCAR");
    }else if (arch.open(QIODevice::ReadOnly|QIODevice::Text)) {
        while(id!=idArch && !arch.atEnd()){
            idArch=arch.readLine();
            idArch.chop(1);
            codigo=arch.readLine();
            codigo.chop(1);
            nombre=arch.readLine();
            nombre.chop(1);
            marca=arch.readLine();
            marca.chop(1);
            prove=arch.readLine();
            prove.chop(1);
            descri=arch.readLine();
            descri.chop(1);
            precio=arch.readLine();
            precio.chop(1);
            cantidad=arch.readLine();
            cantidad.chop(1);
            renglon=arch.readLine();
        }
        if(id==idArch){
            ui->widgetBuscar->hide();
            ui->widgetEncontrado->show();
            ui->lebelEncontradoNumid->setText(idArch);
            ui->lebelEncontradoCodBarras->setText(codigo);
            ui->lebelEncontradoNombre->setText(nombre);
            ui->lebelEncontradoMarca->setText(marca);
            ui->lebelEncontradoProve->setText(prove);
            ui->lebelEncontradoDescripcion->setText(descri);
            ui->lebelEncontradoPrecio->setText(precio);
            ui->lebelEncontradoCantidad->setText(cantidad);

            ui->lineBuscarID->clear();
        }
        if(id!=idArch && arch.atEnd()){
            QMessageBox::warning(0,"Alerta","No se encuentra el ID del producto");
            }arch.close();
}}

void MainWindow::on_ButtonBuscarCodbarras_clicked()
{
    QString codigo = ui->lineBuscarCodbarras->text();
    QString id;
    QString codigoArch;
    QString nombre;
    QString marca;
    QString prove;
    QString descri;
    QString precio;
    QString cantidad;
    QString renglon;

    QString direccion="inventario.txt";
    /*
    if(ui->labelMenuTitulo->text()=="BUSCAR"){
    direccion="inventario.txt";
    }
    if(ui->labelMenuTitulo->text()=="VENDER"){
    direccion="cloninvent.txt";
    }
*/
    QFile arch(direccion);
    if (ui->lineBuscarCodbarras->text().isEmpty()){
        QMessageBox::warning(0,"Alerta","INGRESE UN CODIGO DE BARRAS PARA BUSCAR");
    }else if (arch.open(QIODevice::ReadOnly|QIODevice::Text)) {
        while(codigo!=codigoArch && !arch.atEnd()){
            id=arch.readLine();
            id.chop(1);
            codigoArch=arch.readLine();
            codigoArch.chop(1);
            nombre=arch.readLine();
            nombre.chop(1);
            marca=arch.readLine();
            marca.chop(1);
            prove=arch.readLine();
            prove.chop(1);
            descri=arch.readLine();
            descri.chop(1);
            precio=arch.readLine();
            precio.chop(1);
            cantidad=arch.readLine();
            cantidad.chop(1);
            renglon=arch.readLine();
        }
        if(codigo==codigoArch){
            ui->widgetBuscar->hide();
            ui->widgetEncontrado->show();
            ui->lebelEncontradoNumid->setText(codigoArch);
            ui->lebelEncontradoCodBarras->setText(codigo);
            ui->lebelEncontradoNombre->setText(nombre);
            ui->lebelEncontradoMarca->setText(marca);
            ui->lebelEncontradoProve->setText(prove);
            ui->lebelEncontradoDescripcion->setText(descri);
            ui->lebelEncontradoPrecio->setText(precio);
            ui->lebelEncontradoCantidad->setText(cantidad);

            ui->lineBuscarCodbarras->clear();
        }
        if(codigo!=codigoArch && arch.atEnd()){
            QMessageBox::warning(0,"Alerta","No se encuentra el codigo de barras del producto");
            }arch.close();
    }}

void MainWindow::on_ButtonBuscarNombre_clicked()
{
    QString nombre = ui->lineBuscarNombre->text();
    nombre = nombre.toUpper();
    QString id;
    QString codigo;
    QString nombreArch;
    QString marca;
    QString prove;
    QString descri;
    QString precio;
    QString cantidad;
    QString renglon;
    QString direccion="inventario.txt";
    /*
    if(ui->labelMenuTitulo->text()=="BUSCAR"){
    direccion="inventario.txt";
    }
    if(ui->labelMenuTitulo->text()=="VENDER"){
    direccion="cloninvent.txt";
    }
*/

    QFile arch(direccion);
    if (ui->lineBuscarNombre->text().isEmpty()){
        QMessageBox::warning(0,"Alerta","INGRESE UN CODIGO DE BARRAS PARA BUSCAR");
    }else if (arch.open(QIODevice::ReadOnly|QIODevice::Text)) {
        while(nombre!=nombreArch && !arch.atEnd()){
            id=arch.readLine();
            id.chop(1);
            codigo=arch.readLine();
            codigo.chop(1);
            nombreArch=arch.readLine();
            nombreArch.chop(1);
            marca=arch.readLine();
            marca.chop(1);
            prove=arch.readLine();
            prove.chop(1);
            descri=arch.readLine();
            descri.chop(1);
            precio=arch.readLine();
            precio.chop(1);
            cantidad=arch.readLine();
            cantidad.chop(1);
            renglon=arch.readLine();
        }
        if(nombre==nombreArch){
            ui->widgetBuscar->hide();
            ui->widgetEncontrado->show();
            ui->lebelEncontradoNumid->setText(id);
            ui->lebelEncontradoCodBarras->setText(codigo);
            ui->lebelEncontradoNombre->setText(nombreArch);
            ui->lebelEncontradoMarca->setText(marca);
            ui->lebelEncontradoProve->setText(prove);
            ui->lebelEncontradoDescripcion->setText(descri);
            ui->lebelEncontradoPrecio->setText(precio);
            ui->lebelEncontradoCantidad->setText(cantidad);

            ui->lineBuscarNombre->clear();
        }
        if(nombre!=nombreArch && arch.atEnd()){
            QMessageBox::warning(0,"Alerta","No se encuentra el nombre del producto");
            }arch.close();
}}

void MainWindow::on_ButtonBuscarCancelar_clicked()
{


    ui->widgetLista->hide();
    ui->widgetBuscar->hide();
    ui->widgetVender->hide();
    ui->widgetAgregar->hide();
    ui->widgetEncontrado->hide();

    if(ui->labelMenuTitulo->text()=="VENDER"){
        ui->widgetVender->show();

    }else{
        ui->ButtonMenuBuscar->show();
        ui->ButonMenuAgregar->show();
        ui->ButtonMenuVender->show();
    }
}

void MainWindow::on_ButtonEncontradoModificar_clicked()
{
    if(ui->ButtonEncontradoModificar->text()=="MODIFICAR"){
    ui->widgetEncontrado->hide();
    ui->widgetAgregar->show();
    QString id = ui->lebelEncontradoNumid->text();
    QString codigo = ui->lebelEncontradoCodBarras->text();
    QString nombre = ui->lebelEncontradoNombre->text();
    QString marca = ui->lebelEncontradoMarca->text();
    QString prove = ui->lebelEncontradoProve->text();
    QString descri = ui->lebelEncontradoDescripcion->text();
    QString precio = ui->lebelEncontradoPrecio->text();
    QString cantidad = ui->lebelEncontradoCantidad->text();

    ui->lebelAgregarNumid->setText(id);
    ui->lineAgregarCodbarras->setText(codigo);
    ui->lineAgregarNombre->setText(nombre);
    ui->lineAgregarMarca->setText(marca);
    ui->lineAgregarProve->setText(prove);
    ui->lineAgregarDescrip->setText(descri);
    ui->lineAgregarPrecio->setText(precio);
    ui->lineAgregarCantidad->setText(cantidad);
    ui->ButonAgregarAceptar->setText("MODIFICAR");
}
    if(ui->ButtonEncontradoModificar->text()=="AGREGAR"){
        ui->widgetCantidad->show();
        ui->widgetCantidad->setGeometry(250,50,260,130);
        ui->labelCantidadTotal->setText(ui->lebelEncontradoCantidad->text());


        QFile arch("venta.txt");
        if (arch.open(QIODevice::ReadOnly|QIODevice::Text)) {
}}}

void MainWindow::on_ButtonEncontradoAtras_clicked()
{

    ui->widgetLista->hide();
    ui->widgetBuscar->hide();
    ui->widgetVender->hide();
    ui->widgetAgregar->hide();
    ui->widgetEncontrado->hide();

    if(ui->labelListaIDAUX->text()=="BUSCAR"){
        ui->widgetBuscar->show();
    }
    if(ui->labelListaIDAUX->text()=="LISTA"){
        ui->widgetLista->show();
}}

void MainWindow::on_ButtonMenuVer_clicked()
{

    ui->widgetLista->show();
    ui->widgetBuscar->hide();
    ui->widgetVender->hide();
    ui->widgetAgregar->hide();
    ui->widgetEncontrado->hide();
    ui->labelListaIDAUX->setText("LISTA");
    ui->label_53->setNum(1);
    int articulos=0;
    double pag=0;

    QString direccion="inventario.txt";
    /*
    if(ui->labelMenuTitulo->text()=="BUSCAR"){
    direccion="inventario.txt";
    }
    if(ui->labelMenuTitulo->text()=="VENDER"){
    direccion="cloninvent.txt";
    }
*/

    QFile archaux(direccion);
    if (archaux.open(QIODevice::ReadOnly|QIODevice::Text)){
        while (!archaux.atEnd()){
            for (int i = 0; i < 9; i++) {
                archaux.readLine();
            }
            articulos++;
            pag++;
        }
        archaux.close();
    }
    pag=pag/5;
    articulos=articulos/5;

    if(pag>articulos){
        articulos++;
    }
    ui->label_55->setNum(articulos);

    QFile arch(direccion);
    if (arch.open(QIODevice::ReadOnly|QIODevice::Text)){

        QString id1,nombre1,marca1,precio1,cantidad1;
        QString id2,nombre2,marca2,precio2,cantidad2;
        QString id3,nombre3,marca3,precio3,cantidad3;
        QString id4,nombre4,marca4,precio4,cantidad4;
        QString id5,nombre5,marca5,precio5,cantidad5;

        id1=arch.readLine();
        id1.chop(1);
        arch.readLine();//salto
        nombre1=arch.readLine();
        nombre1.chop(1);
        marca1=arch.readLine();
        marca1.chop(1);
        arch.readLine();//salto
        arch.readLine();//salto
        precio1=arch.readLine();
        precio1.chop(1);
        cantidad1=arch.readLine();
        cantidad1.chop(1);
        arch.readLine();//salto

        ui->labelListaID->setText(id1);
        ui->labelListaNombre->setText(nombre1);
        ui->labelListaMarca->setText(marca1);
        ui->labelListaPrecio->setText(precio1);
        ui->labelListaCantidad->setText(cantidad1);

        id2=arch.readLine();
        arch.readLine();//salto
        nombre2=arch.readLine();
        marca2=arch.readLine();
        arch.readLine();//salto
        arch.readLine();//salto
        precio2=arch.readLine();
        cantidad2=arch.readLine();
        arch.readLine();//salto

        id2.chop(1);
        nombre2.chop(1);
        marca2.chop(1);
        precio2.chop(1);
        cantidad2.chop(1);

        ui->labelListaID_2->setText(id2);
        ui->labelListaNombre_2->setText(nombre2);
        ui->labelListaMarca_2->setText(marca2);
        ui->labelListaPrecio_2->setText(precio2);
        ui->labelListaCantidad_2->setText(cantidad2);

        id3=arch.readLine();
        arch.readLine();//salto
        nombre3=arch.readLine();
        marca3=arch.readLine();
        arch.readLine();//salto
        arch.readLine();//salto
        precio3=arch.readLine();
        cantidad3=arch.readLine();
        arch.readLine();//salto

        id3.chop(1);
        nombre3.chop(1);
        marca3.chop(1);
        precio3.chop(1);
        cantidad3.chop(1);

        ui->labelListaID_3->setText(id3);
        ui->labelListaNombre_3->setText(nombre3);
        ui->labelListaMarca_3->setText(marca3);
        ui->labelListaPrecio_3->setText(precio3);
        ui->labelListaCantidad_3->setText(cantidad3);

        id4=arch.readLine();
        arch.readLine();//salto
        nombre4=arch.readLine();
        marca4=arch.readLine();
        arch.readLine();//salto
        arch.readLine();//salto
        precio4=arch.readLine();
        cantidad4=arch.readLine();
        arch.readLine();//salto

        id4.chop(1);
        nombre4.chop(1);
        marca4.chop(1);
        precio4.chop(1);
        cantidad4.chop(1);

        ui->labelListaID_4->setText(id4);
        ui->labelListaNombre_4->setText(nombre4);
        ui->labelListaMarca_4->setText(marca4);
        ui->labelListaPrecio_4->setText(precio4);
        ui->labelListaCantidad_4->setText(cantidad4);

        id5=arch.readLine();
        arch.readLine();//salto
        nombre5=arch.readLine();
        marca5=arch.readLine();
        arch.readLine();//salto
        arch.readLine();//salto
        precio5=arch.readLine();
        cantidad5=arch.readLine();
        arch.readLine();//salto

        id5.chop(1);
        nombre5.chop(1);
        marca5.chop(1);
        precio5.chop(1);
        cantidad5.chop(1);

        ui->labelListaID_5->setText(id5);
        ui->labelListaNombre_5->setText(nombre5);
        ui->labelListaMarca_5->setText(marca5);
        ui->labelListaPrecio_5->setText(precio5);
        ui->labelListaCantidad_5->setText(cantidad5);

        arch.close();
    }}

void MainWindow::on_ButtonEncontradoAtras_4_clicked()
{

    int numpag,numlibro;
    numlibro=ui->label_55->text().toInt();
    numpag = ui->label_53->text().toInt();

    if(numpag<numlibro){

    numpag++;
    ui->label_53->setNum(numpag);

    QString id1,id2,id3,id4,id5;
    id1 = ui->labelListaID->text();
    id2 = ui->labelListaID_2->text();
    id3 = ui->labelListaID_3->text();
    id4 = ui->labelListaID_4->text();
    id5 = ui->labelListaID_5->text();

    int id1int, id2int, id3int, id4int, id5int;

    id1int=id1.toInt()+5;
    id2int=id2.toInt()+5;
    id3int=id3.toInt()+5;
    id4int=id4.toInt()+5;
    id5int=id5.toInt()+5;

    QFile arch("inventario.txt");
    if (arch.open(QIODevice::ReadOnly|QIODevice::Text)){
        QString IDEncontr="";
        while(ui->labelListaID_5->text()!=IDEncontr){
            IDEncontr=arch.readLine();
            IDEncontr.chop(1);
            arch.readLine();
            arch.readLine();
            arch.readLine();
            arch.readLine();
            arch.readLine();
            arch.readLine();
            arch.readLine();
            arch.readLine();
            }
        ui->labelListaID->setNum(id1int);
        ui->labelListaID_2->setNum(id2int);
        ui->labelListaID_3->setNum(id3int);
        ui->labelListaID_4->setNum(id4int);
        ui->labelListaID_5->setNum(id5int);

        QString nombre1,marca1,precio1,cantidad1;
        QString nombre2,marca2,precio2,cantidad2;
        QString nombre3,marca3,precio3,cantidad3;
        QString nombre4,marca4,precio4,cantidad4;
        QString nombre5,marca5,precio5,cantidad5;

        arch.readLine();
        arch.readLine();//salto
        nombre1=arch.readLine();
        marca1=arch.readLine();
        arch.readLine();//salto
        arch.readLine();//salto
        precio1=arch.readLine();
        cantidad1=arch.readLine();
        arch.readLine();//salto

        nombre1.chop(1);
        marca1.chop(1);
        precio1.chop(1);
        cantidad1.chop(1);

        ui->labelListaNombre->setText(nombre1);
        ui->labelListaMarca->setText(marca1);
        ui->labelListaPrecio->setText(precio1);
        ui->labelListaCantidad->setText(cantidad1);

        arch.readLine();
        arch.readLine();//salto
        nombre2=arch.readLine();
        marca2=arch.readLine();
        arch.readLine();//salto
        arch.readLine();//salto
        precio2=arch.readLine();
        cantidad2=arch.readLine();
        arch.readLine();//salto

        nombre2.chop(1);
        marca2.chop(1);
        precio2.chop(1);
        cantidad2.chop(1);

        ui->labelListaNombre_2->setText(nombre2);
        ui->labelListaMarca_2->setText(marca2);
        ui->labelListaPrecio_2->setText(precio2);
        ui->labelListaCantidad_2->setText(cantidad2);

        arch.readLine();
        arch.readLine();//salto
        nombre3=arch.readLine();
        marca3=arch.readLine();
        arch.readLine();//salto
        arch.readLine();//salto
        precio3=arch.readLine();
        cantidad3=arch.readLine();
        arch.readLine();//salto

        nombre3.chop(1);
        marca3.chop(1);
        precio3.chop(1);
        cantidad3.chop(1);

        ui->labelListaNombre_3->setText(nombre3);
        ui->labelListaMarca_3->setText(marca3);
        ui->labelListaPrecio_3->setText(precio3);
        ui->labelListaCantidad_3->setText(cantidad3);

        arch.readLine();
        arch.readLine();//salto
        nombre4=arch.readLine();
        marca4=arch.readLine();
        arch.readLine();//salto
        arch.readLine();//salto
        precio4=arch.readLine();
        cantidad4=arch.readLine();
        arch.readLine();//salto

        nombre4.chop(1);
        marca4.chop(1);
        precio4.chop(1);
        cantidad4.chop(1);

        ui->labelListaNombre_4->setText(nombre4);
        ui->labelListaMarca_4->setText(marca4);
        ui->labelListaPrecio_4->setText(precio4);
        ui->labelListaCantidad_4->setText(cantidad4);

        arch.readLine();
        arch.readLine();//salto
        nombre5=arch.readLine();
        marca5=arch.readLine();
        arch.readLine();//salto
        arch.readLine();//salto
        precio5=arch.readLine();
        cantidad5=arch.readLine();
        arch.readLine();//salto

        nombre5.chop(1);
        marca5.chop(1);
        precio5.chop(1);
        cantidad5.chop(1);

        ui->labelListaNombre_5->setText(nombre5);
        ui->labelListaMarca_5->setText(marca5);
        ui->labelListaPrecio_5->setText(precio5);
        ui->labelListaCantidad_5->setText(cantidad5);
        ui->labelListaIDAUX_2->setText(id5);

        arch.close();
    }}}

void MainWindow::on_ButtonEncontradoAtras_3_clicked()
{
    int numpag;
    numpag = ui->label_53->text().toInt();

    if(numpag>1){
    numpag--;
    ui->label_53->setNum(numpag);

    QString id1,id2,id3,id4,id5;
    id1 = ui->labelListaID->text();
    id2 = ui->labelListaID_2->text();
    id3 = ui->labelListaID_3->text();
    id4 = ui->labelListaID_4->text();
    id5 = ui->labelListaID_5->text();

    int id1int, id2int, id3int, id4int, id5int;

    id1int=id1.toInt()-5;
    id2int=id2.toInt()-5;
    id3int=id3.toInt()-5;
    id4int=id4.toInt()-5;
    id5int=id5.toInt()-5;

    ui->labelListaID->setNum(id1int);
    ui->labelListaID_2->setNum(id2int);
    ui->labelListaID_3->setNum(id3int);
    ui->labelListaID_4->setNum(id4int);
    ui->labelListaID_5->setNum(id5int);

    QFile arch("inventario.txt");
    if (arch.open(QIODevice::ReadOnly|QIODevice::Text)){

        QString nombre1,marca1,precio1,cantidad1;
        QString nombre2,marca2,precio2,cantidad2;
        QString nombre3,marca3,precio3,cantidad3;
        QString nombre4,marca4,precio4,cantidad4;
        QString nombre5,marca5,precio5,cantidad5;

        QString IDcompara;
        QString IDbuscar = ui->labelListaID->text();

        do{

        IDcompara = arch.readLine();
        IDcompara.chop(1);
        arch.readLine();//salto
        nombre1=arch.readLine();
        marca1=arch.readLine();
        arch.readLine();//salto
        arch.readLine();//salto
        precio1=arch.readLine();
        cantidad1=arch.readLine();
        arch.readLine();//salto

        nombre1.chop(1);
        marca1.chop(1);
        precio1.chop(1);
        cantidad1.chop(1);

        ui->labelListaNombre->setText(nombre1);
        ui->labelListaMarca->setText(marca1);
        ui->labelListaPrecio->setText(precio1);
        ui->labelListaCantidad->setText(cantidad1);

        arch.readLine();
        arch.readLine();//salto
        nombre2=arch.readLine();
        marca2=arch.readLine();
        arch.readLine();//salto
        arch.readLine();//salto
        precio2=arch.readLine();
        cantidad2=arch.readLine();
        arch.readLine();//salto

        nombre2.chop(1);
        marca2.chop(1);
        precio2.chop(1);
        cantidad2.chop(1);

        ui->labelListaNombre_2->setText(nombre2);
        ui->labelListaMarca_2->setText(marca2);
        ui->labelListaPrecio_2->setText(precio2);
        ui->labelListaCantidad_2->setText(cantidad2);

        arch.readLine();
        arch.readLine();//salto
        nombre3=arch.readLine();
        marca3=arch.readLine();
        arch.readLine();//salto
        arch.readLine();//salto
        precio3=arch.readLine();
        cantidad3=arch.readLine();
        arch.readLine();//salto

        nombre3.chop(1);
        marca3.chop(1);
        precio3.chop(1);
        cantidad3.chop(1);

        ui->labelListaNombre_3->setText(nombre3);
        ui->labelListaMarca_3->setText(marca3);
        ui->labelListaPrecio_3->setText(precio3);
        ui->labelListaCantidad_3->setText(cantidad3);

        arch.readLine();
        arch.readLine();//salto
        nombre4=arch.readLine();
        marca4=arch.readLine();
        arch.readLine();//salto
        arch.readLine();//salto
        precio4=arch.readLine();
        cantidad4=arch.readLine();
        arch.readLine();//salto

        nombre4.chop(1);
        marca4.chop(1);
        precio4.chop(1);
        cantidad4.chop(1);

        ui->labelListaNombre_4->setText(nombre4);
        ui->labelListaMarca_4->setText(marca4);
        ui->labelListaPrecio_4->setText(precio4);
        ui->labelListaCantidad_4->setText(cantidad4);

        arch.readLine();
        arch.readLine();//salto
        nombre5=arch.readLine();
        marca5=arch.readLine();
        arch.readLine();//salto
        arch.readLine();//salto
        precio5=arch.readLine();
        cantidad5=arch.readLine();
        arch.readLine();//salto

        nombre5.chop(1);
        marca5.chop(1);
        precio5.chop(1);
        cantidad5.chop(1);

        ui->labelListaNombre_5->setText(nombre5);
        ui->labelListaMarca_5->setText(marca5);
        ui->labelListaPrecio_5->setText(precio5);
        ui->labelListaCantidad_5->setText(cantidad5);
        ui->labelListaIDAUX_2->setText(id5);

        }while(IDbuscar != IDcompara);
        arch.close();
    }}}

void MainWindow::on_ButtonListaVer_clicked()
{
    QString id = ui->labelListaID->text();
    QString idArch, codigo, nombre, marca, prove, descri, precio, cantidad, renglon;

    QFile arch("inventario.txt");
    if (arch.open(QIODevice::ReadOnly|QIODevice::Text)) {
        while(id!=idArch && !arch.atEnd()){
            idArch=arch.readLine();
            idArch.chop(1);
            codigo=arch.readLine();
            codigo.chop(1);
            nombre=arch.readLine();
            nombre.chop(1);
            marca=arch.readLine();
            marca.chop(1);
            prove=arch.readLine();
            prove.chop(1);
            descri=arch.readLine();
            descri.chop(1);
            precio=arch.readLine();
            precio.chop(1);
            cantidad=arch.readLine();
            cantidad.chop(1);
            renglon=arch.readLine();
        }
        if(id==idArch){
            ui->widgetLista->hide();
            ui->widgetEncontrado->show();
            ui->lebelEncontradoNumid->setText(idArch);
            ui->lebelEncontradoCodBarras->setText(codigo);
            ui->lebelEncontradoNombre->setText(nombre);
            ui->lebelEncontradoMarca->setText(marca);
            ui->lebelEncontradoProve->setText(prove);
            ui->lebelEncontradoDescripcion->setText(descri);
            ui->lebelEncontradoPrecio->setText(precio);
            ui->lebelEncontradoCantidad->setText(cantidad);
        }else if(id!=idArch && arch.atEnd()){
                QMessageBox::warning(0,"Alerta","No se encuentra del producto");
                }arch.close();
}}

void MainWindow::on_ButtonListaVer_2_clicked()
{
    QString id = ui->labelListaID_2->text();
    QString idArch, codigo, nombre, marca, prove, descri, precio, cantidad, renglon;

    QFile arch("inventario.txt");
    if (arch.open(QIODevice::ReadOnly|QIODevice::Text)) {
        while(id!=idArch && !arch.atEnd()){
            idArch=arch.readLine();
            idArch.chop(1);
            codigo=arch.readLine();
            codigo.chop(1);
            nombre=arch.readLine();
            nombre.chop(1);
            marca=arch.readLine();
            marca.chop(1);
            prove=arch.readLine();
            prove.chop(1);
            descri=arch.readLine();
            descri.chop(1);
            precio=arch.readLine();
            precio.chop(1);
            cantidad=arch.readLine();
            cantidad.chop(1);
            renglon=arch.readLine();
        }
        if(id==idArch){
            ui->widgetLista->hide();
            ui->widgetEncontrado->show();
            ui->lebelEncontradoNumid->setText(idArch);
            ui->lebelEncontradoCodBarras->setText(codigo);
            ui->lebelEncontradoNombre->setText(nombre);
            ui->lebelEncontradoMarca->setText(marca);
            ui->lebelEncontradoProve->setText(prove);
            ui->lebelEncontradoDescripcion->setText(descri);
            ui->lebelEncontradoPrecio->setText(precio);
            ui->lebelEncontradoCantidad->setText(cantidad);
        }else if(id!=idArch && arch.atEnd()){
                QMessageBox::warning(0,"Alerta","No se encuentra del producto");
                }arch.close();
}}

void MainWindow::on_ButtonListaVer_3_clicked()
{
    QString id = ui->labelListaID_3->text();
    QString idArch, codigo, nombre, marca, prove, descri, precio, cantidad, renglon;

    QFile arch("inventario.txt");
    if (arch.open(QIODevice::ReadOnly|QIODevice::Text)) {
        while(id!=idArch && !arch.atEnd()){
            idArch=arch.readLine();
            idArch.chop(1);
            codigo=arch.readLine();
            codigo.chop(1);
            nombre=arch.readLine();
            nombre.chop(1);
            marca=arch.readLine();
            marca.chop(1);
            prove=arch.readLine();
            prove.chop(1);
            descri=arch.readLine();
            descri.chop(1);
            precio=arch.readLine();
            precio.chop(1);
            cantidad=arch.readLine();
            cantidad.chop(1);
            renglon=arch.readLine();
        }
        if(id==idArch){
            ui->widgetLista->hide();
            ui->widgetEncontrado->show();
            ui->lebelEncontradoNumid->setText(idArch);
            ui->lebelEncontradoCodBarras->setText(codigo);
            ui->lebelEncontradoNombre->setText(nombre);
            ui->lebelEncontradoMarca->setText(marca);
            ui->lebelEncontradoProve->setText(prove);
            ui->lebelEncontradoDescripcion->setText(descri);
            ui->lebelEncontradoPrecio->setText(precio);
            ui->lebelEncontradoCantidad->setText(cantidad);
        }else if(id!=idArch && arch.atEnd()){
                QMessageBox::warning(0,"Alerta","No se encuentra del producto");
                }arch.close();
}}

void MainWindow::on_ButtonListaVer_4_clicked()
{
    QString id = ui->labelListaID_4->text();
    QString idArch, codigo, nombre, marca, prove, descri, precio, cantidad, renglon;

    QFile arch("inventario.txt");
    if (arch.open(QIODevice::ReadOnly|QIODevice::Text)) {
        while(id!=idArch && !arch.atEnd()){
            idArch=arch.readLine();
            idArch.chop(1);
            codigo=arch.readLine();
            codigo.chop(1);
            nombre=arch.readLine();
            nombre.chop(1);
            marca=arch.readLine();
            marca.chop(1);
            prove=arch.readLine();
            prove.chop(1);
            descri=arch.readLine();
            descri.chop(1);
            precio=arch.readLine();
            precio.chop(1);
            cantidad=arch.readLine();
            cantidad.chop(1);
            renglon=arch.readLine();
        }
        if(id==idArch){
            ui->widgetLista->hide();
            ui->widgetEncontrado->show();
            ui->lebelEncontradoNumid->setText(idArch);
            ui->lebelEncontradoCodBarras->setText(codigo);
            ui->lebelEncontradoNombre->setText(nombre);
            ui->lebelEncontradoMarca->setText(marca);
            ui->lebelEncontradoProve->setText(prove);
            ui->lebelEncontradoDescripcion->setText(descri);
            ui->lebelEncontradoPrecio->setText(precio);
            ui->lebelEncontradoCantidad->setText(cantidad);
        }else if(id!=idArch && arch.atEnd()){
                QMessageBox::warning(0,"Alerta","No se encuentra del producto");
                }arch.close();
}}

void MainWindow::on_ButtonListaVer_5_clicked()
{
    QString id = ui->labelListaID_5->text();
    QString idArch, codigo, nombre, marca, prove, descri, precio, cantidad, renglon;

    QFile arch("inventario.txt");
    if (arch.open(QIODevice::ReadOnly|QIODevice::Text)) {
        while(id!=idArch && !arch.atEnd()){
            idArch=arch.readLine();
            idArch.chop(1);
            codigo=arch.readLine();
            codigo.chop(1);
            nombre=arch.readLine();
            nombre.chop(1);
            marca=arch.readLine();
            marca.chop(1);
            prove=arch.readLine();
            prove.chop(1);
            descri=arch.readLine();
            descri.chop(1);
            precio=arch.readLine();
            precio.chop(1);
            cantidad=arch.readLine();
            cantidad.chop(1);
            renglon=arch.readLine();
        }
        if(id==idArch){
            ui->widgetLista->hide();
            ui->widgetEncontrado->show();
            ui->lebelEncontradoNumid->setText(idArch);
            ui->lebelEncontradoCodBarras->setText(codigo);
            ui->lebelEncontradoNombre->setText(nombre);
            ui->lebelEncontradoMarca->setText(marca);
            ui->lebelEncontradoProve->setText(prove);
            ui->lebelEncontradoDescripcion->setText(descri);
            ui->lebelEncontradoPrecio->setText(precio);
            ui->lebelEncontradoCantidad->setText(cantidad);
        }else if(id!=idArch && arch.atEnd()){
                QMessageBox::warning(0,"Alerta","No se encuentra del producto");
                }arch.close();
}}

void MainWindow::on_ButtonEncontradoAtras_2_clicked()
{
    ui->widgetLista->hide();
    ui->widgetBuscar->show();
    ui->widgetVender->hide();
    ui->widgetAgregar->hide();
    ui->widgetEncontrado->hide();
}

void MainWindow::on_ButtonMenuVender_clicked()
{
    ui->ButtonMenuBuscar->hide();
    ui->ButonMenuAgregar->hide();
    ui->ButtonMenuVender->hide();

    ui->widgetLista->hide();
    ui->widgetBuscar->hide();
    ui->widgetVender->show();
    ui->widgetAgregar->hide();
    ui->widgetEncontrado->hide();
    ui->labelMenuTitulo->setText("VENDER");

    QDate fecha = QDate::currentDate();

    QFile arch1("inventario.txt");
    QFile arch2("cloninvent.txt");
    if (arch1.open(QIODevice::ReadOnly|QIODevice::Text) && arch2.open(QIODevice::WriteOnly|QIODevice::Text)) {
        QTextStream out (&arch2);
        QString renglon=arch1.readAll();
        out<<renglon;

        arch1.close();
        arch2.close();
}
    QFile archaux("ticket.txt");
    if (archaux.open(QIODevice::WriteOnly|QIODevice::Text)) {
        QTextStream out (&archaux);
        out<<fecha.toString("dd/MM/yyyy")<<"\n";
        archaux.close();
}
    QFile archaux2("ticket.txt");
    if (archaux2.open(QIODevice::ReadOnly|QIODevice::Text)) {
        ui->TextVenderTicket->setPlainText(archaux2.readAll());
        archaux2.close();
}}

void MainWindow::on_ButtonVenderAgregar_clicked()
{
    ui->widgetBuscar->show();
    ui->widgetVender->hide();
    ui->widgetLista->hide();
    ui->widgetEncontrado->hide();
    ui->widgetCantidad->hide();

    ui->ButtonEncontradoModificar->setText("AGREGAR");
}

void MainWindow::on_ButtonCantidadCancelar_clicked()
{
    ui->widgetCantidad->hide();
}

void MainWindow::on_ButtonCantidadAceptar_2_clicked()
{   int cantNum=ui->labelCantidadSeleccion->text().toInt();
    int cantNumTotal=ui->labelCantidadTotal->text().toInt();
    if(cantNum<cantNumTotal){
        cantNum++;
        ui->labelCantidadSeleccion->setNum(cantNum);
}}

void MainWindow::on_ButtonCantidadAceptar_3_clicked()
{
    int cantNum=ui->labelCantidadSeleccion->text().toInt();
    if(cantNum>0){
        cantNum--;
        ui->labelCantidadSeleccion->setNum(cantNum);
}}

void MainWindow::on_ButtonCantidadAceptar_clicked()
{
    if(ui->labelCantidadSeleccion->text()=="0"){
        QMessageBox::warning(0,"Alerta","No se ha seleccionado ninguna cantidad");
    }else {
    ui->widgetVender->show();
    ui->widgetBuscar->hide();
    ui->widgetLista->hide();
    ui->widgetCantidad->hide();

    QFile archticket("ticket.txt");
    if (archticket.open(QIODevice::Append|QIODevice::Text)) {
        QTextStream out (&archticket);
        out<<ui->lebelEncontradoNumid->text()<<"\t";
        out<<ui->lebelEncontradoNombre->text()<<"\t";
        out<<ui->lebelEncontradoPrecio->text()<<"$\tX";
        out<<ui->labelCantidadSeleccion->text()<<"\t";
        int total=ui->lebelEncontradoPrecio->text().toInt()*ui->labelCantidadSeleccion->text().toInt();
        out<<total<<"$\n";
        out<<"---\n";
        archticket.close();
}
    QFile archaux("ticket.txt");
    if (archaux.open(QIODevice::ReadOnly|QIODevice::Text)) {
        ui->TextVenderTicket->setPlainText(archaux.readAll());
        archaux.close();
}
    QFile arch("inventario.txt");
    QFile arch2("inventario.tmp");
    QString id = ui->lebelEncontradoNumid->text();
    QString codbarras = ui->lebelEncontradoCodBarras->text();
    QString nombre = ui->lebelEncontradoNombre->text();
    QString marca = ui->lebelEncontradoMarca->text();
    QString prove = ui->lebelEncontradoProve->text();
    QString descri = ui->lebelEncontradoDescripcion->text();
    QString precio = ui->lebelEncontradoPrecio->text();

    if (arch.open(QIODevice::ReadOnly|QIODevice::Text) && arch2.open(QIODevice::WriteOnly|QIODevice::Text)) {
            QTextStream out (&arch2);
            QString idEnArch;
            QString renglon;
            while (!arch.atEnd()) {
                idEnArch = arch.readLine();
                idEnArch.chop(1);
                out << idEnArch << "\n";
                do {
                    renglon = QString::fromLatin1(arch.readLine());
                    renglon.chop(1);
                    if (id != idEnArch) {
                        out << renglon << "\n";
            }} while (renglon != "*");
                if (id == idEnArch) {
                    out << codbarras << "\n";
                    out << nombre << "\n";
                    out << marca << "\n";
                    out << prove << "\n";
                    out << descri << "\n";
                    out << precio << "\n";
                    int cantTotal= ui->lebelEncontradoCantidad->text().toInt();
                    int cant = ui->labelCantidadSeleccion->text().toInt();
                    out << cantTotal-cant << "\n";
                    out << "*\n";
                }}
            arch.close();
            arch2.close();
            arch.remove();
            arch2.rename("inventario.txt");


}}}

void MainWindow::on_ButtonVenderCancelar_clicked()
{
    ui->ButtonMenuBuscar->show();
    ui->ButonMenuAgregar->show();
    ui->ButtonMenuVender->show();

    ui->widgetVender->hide();
    QFile arch("inventario.txt");
    QFile arch2("cloninvent.txt");
    arch.remove();
    arch2.rename("inventario.txt");
    QMessageBox::warning(0,"Aviso","SE HA DEVUELTO EL STOCK");
}

void MainWindow::on_ButtonVenderAdicional_clicked()
{
    ui->widgetAdicional->show();
    ui->widgetVender->hide();

}

void MainWindow::on_ButtonBuscarCancelar_5_clicked()
{
    QFile archticket("ticket.txt");
    if(ui->lineAdicionalNombre->text().isEmpty()){
        QMessageBox::warning(0,"Alerta","Ingrese un Nombre");
    }else if (ui->lineAdicionalPrecio->text().isEmpty()) {
        QMessageBox::warning(0,"Alerta","Ingrese un Precio");
    }else if (ui->lineAdicionalCantidad->text().isEmpty()) {
        QMessageBox::warning(0,"Alerta","Ingrese una Cantidad");
    }else if (archticket.open(QIODevice::Append|QIODevice::Text)) {
        QTextStream out (&archticket);
        out<<"A\t";
        out<<ui->lineAdicionalNombre->text()<<"\t";
        out<<ui->lineAdicionalPrecio->text()<<"$\t X";
        out<<ui->lineAdicionalCantidad->text()<<"\t";
        out<<ui->labelAdicionalTotal->text()<< "$\n";
        out<<"---\n";

        archticket.close();
        ui->lineAdicionalNombre->clear();
        ui->lineAdicionalPrecio->clear();
        ui->lineAdicionalCantidad->clear();
        ui->labelAdicionalTotal->setNum(0);
}
    if (archticket.open(QIODevice::ReadOnly|QIODevice::Text)) {
        ui->TextVenderTicket->setPlainText(archticket.readAll());
        archticket.close();
    }
    ui->widgetAdicional->hide();
    ui->widgetVender->show();
    ui->labelCantidadSeleccion->setNum(0);
}

void MainWindow::on_lineAdicionalPrecio_editingFinished()
{
   int numa = ui->lineAdicionalPrecio->text().toInt();
   int numb = ui->lineAdicionalCantidad->text().toInt();
   ui->labelAdicionalTotal->setNum(numa*numb);
}

void MainWindow::on_lineAdicionalCantidad_editingFinished()
{
    int numa = ui->lineAdicionalPrecio->text().toInt();
    int numb = ui->lineAdicionalCantidad->text().toInt();
    ui->labelAdicionalTotal->setNum(numa*numb);
}

void MainWindow::on_ButtonBuscarCancelar_3_clicked()
{
    ui->widgetAdicional->hide();
    ui->widgetVender->show();
}

void MainWindow::on_ButtonMenuSalir_clicked()
{
    ui->ButtonMenuBuscar->show();
    ui->ButonMenuAgregar->show();
    ui->ButtonMenuVender->show();

    ui->widgetMenu->hide();
    ui->widgetLista->hide();
    ui->widgetBuscar->hide();
    ui->widgetVender->hide();
    ui->widgetAgregar->hide();
    ui->widgetEncontrado->hide();
    ui->widgetAdicional->hide();
    ui->widgetCantidad->hide();

    ui->widgetLogin->show();

    setMaximumSize(440,250);
    setMinimumSize(440,250);

    setGeometry(200,100,440,250);

}

void MainWindow::on_ButtonVenderImprimir_clicked()
{
    QPrinter printer(QPrinter::HighResolution);
    QPrintDialog printDialog(&printer, NULL);
    if (printDialog.exec() == QDialog::Accepted) {
        ui->TextVenderTicket->print(&printer);
    }
}

void MainWindow::on_ButtonSemanasMenos_clicked()
{
    int cantNum=ui->labelSemanasCantidad->text().toInt();
    if(cantNum>0){
        cantNum--;
        ui->labelSemanasCantidad->setNum(cantNum);
}}

void MainWindow::on_ButtonSemanasMas_clicked()
{
    int cantNum=ui->labelSemanasCantidad->text().toInt();
    if(cantNum>0){
        cantNum--;
        ui->labelSemanasCantidad->setNum(cantNum);
}}
