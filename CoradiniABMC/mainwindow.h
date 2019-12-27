#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ButtonLoginIngresar_clicked();

    void on_ButonMenuAgregar_clicked();

    void on_ButonAgregarAceptar_clicked();

    void on_ButonAgregarCancelar_clicked();

    void on_ButtonMenuBuscar_clicked();

    void on_ButtonBuscarID_clicked();

    void on_ButtonBuscarCodbarras_clicked();

    void on_ButtonBuscarNombre_clicked();

    void on_ButtonBuscarCancelar_clicked();

    void on_ButtonEncontradoModificar_clicked();

    void on_ButtonEncontradoAtras_clicked();

    void on_ButtonMenuVer_clicked();

    void on_ButtonEncontradoAtras_4_clicked();

    void on_ButtonEncontradoAtras_3_clicked();

    void on_ButtonListaVer_clicked();

    void on_ButtonListaVer_2_clicked();

    void on_ButtonListaVer_3_clicked();

    void on_ButtonListaVer_4_clicked();

    void on_ButtonListaVer_5_clicked();

    void on_ButtonEncontradoAtras_2_clicked();

    void on_ButtonMenuVender_clicked();

    void on_ButtonVenderAgregar_clicked();

    void on_ButtonCantidadCancelar_clicked();

    void on_ButtonCantidadAceptar_2_clicked();

    void on_ButtonCantidadAceptar_3_clicked();

    void on_ButtonCantidadAceptar_clicked();

    void on_ButtonVenderCancelar_clicked();

    void on_ButtonVenderAdicional_clicked();

    void on_ButtonBuscarCancelar_5_clicked();

    void on_lineAdicionalPrecio_editingFinished();

    void on_lineAdicionalCantidad_editingFinished();

    void on_ButtonBuscarCancelar_3_clicked();

    void on_ButtonMenuSalir_clicked();

    void on_ButtonVenderImprimir_clicked();

    void on_ButtonSemanasMenos_clicked();

    void on_ButtonSemanasMas_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
