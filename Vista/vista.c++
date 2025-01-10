#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstring>
using namespace std;



int logoPixel(){
   ifstream archivoEntrada("Vista/banner.txt");
   string lineas;
    while(getline(archivoEntrada,lineas)){
        cout << lineas << endl;
    }
    archivoEntrada.close();
    return 0;

}

void cargarDocInstrucciones(){
    cout << "" ;
    //rediriger a documento
}

void  crearFileDatosIngresados(string primerLogin,string nombrePropio,string nombreGestor,string correo, string diasDeEnvios){
    ofstream archivo("DatosLogin/Datos.txt");
    if(archivo.is_open()){
        archivo << primerLogin + "\n";
        archivo << nombrePropio + "\n";
        archivo << nombreGestor + "\n";
        archivo << correo + "\n";
        archivo << diasDeEnvios + "\n";
        archivo.close();
    }else {
        cout << "No se pudo abrir el archivo";
    }
} 

void validarExistenciaArchivoDatos(){
    // cada que se corra el programa, validar la existencia 
    // del archivo de los datos, si no, redirigir para 
    //guardarDatos()
}


void guardarDatos(){
    cout << "[1]   Breve introduccion, si desea leer la instruccion " << endl;
    cout << "[Y / N]" << endl;
    string opcion;
    cin >>  opcion;

    if(opcion == "Y" || opcion == "y"){
        // redireccion para leer la documentacion 
        cargarDocInstrucciones();
    }else{
        cout << "continuemos... \n" << endl; 
    }
    cout << "[2] Asigneme un nombre" << endl;
    string nombreDelGestor;
    cin >> nombreDelGestor;
    cout << "[3] Ingrese su nombre con el cual lo llamare" << endl;
    string nombrePropio;
    cin >> nombrePropio;
    cout << "[3.1] Correo electronico" << endl;
    string correo;
    cin >> correo;
    cout <<"[4] Por ultimo mencione el tiempo que desea que se mande a su correo el estado" <<endl;
    cout <<"Dias: ";
    string cantidadDeDias; 
    cin >> cantidadDeDias;

    cout <<"Su inicio quedara guardado desde el dia de hoy: " << endl;

    time_t fechaDeIncio = time(0);
    string fechaPrimerLogin = ctime(&fechaDeIncio);
    cout << fechaPrimerLogin << endl;
    crearFileDatosIngresados(fechaPrimerLogin,nombrePropio,nombreDelGestor,correo,cantidadDeDias);
}


void leerFecha() {
    std::ifstream archivo("registro.txt");  // Abre el archivo para leer
    if (archivo.is_open()) {
        std::string fecha;
        std::getline(archivo, fecha);  // Lee la primera línea del archivo
        archivo.close();
        std::cout << "Fecha registrada: " << fecha << std::endl;
    } else {
        std::cerr << "No se pudo abrir el archivo." << std::endl;
    }
}
