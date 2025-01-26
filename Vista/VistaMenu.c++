#include <cstdlib>
#include <cstdio>
#include <iostream>
#include "../Componentes/componentesVista.c++"


using namespace std;

void run(){
    LogoPixel();
    if(!validarExistenciaArchivoDatos()){
        RegistrarDatos();
    }
    regresarDatosUsuarioTXT();
    vistaDespuesRegistro();
}