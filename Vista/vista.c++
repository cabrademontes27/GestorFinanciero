#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstring>
#include <sstream>
using namespace std;


void guardarDatos();

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

void  crearArchivoDatosIngresados(string primerLogin,string nombrePropio,string nombreGestor,string correo, string diasDeEnvios){
    ofstream archivo("DatosLogin/Datos.txt");
    if(archivo.is_open()){
        archivo << primerLogin ;
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
    string linea;
    ifstream archivo("DatosLogin/Datos.txt");

    //valida si exciste
    if(!archivo){
        //ni existe el archivo, funcion
        cout << "No existe el documentos de los datos";
        guardarDatos();
    }   
    //valida si esta vacio
    if(!getline(archivo,linea)){
        cout << "los datos fueron modificados, se redirigera... \n" << endl;
        guardarDatos();
    }
}

string leerDatos(){
    //deberia agregar a qui el validar la existencia del
    //archivo datos ??
    // deberia leer los datos y separarlos
    ifstream archivo("DatosLogin/Datos.txt");
    string linea;
    string primerLogin, nombrePropio,nombreGestor,correo,diasEnvios;
    while(getline(archivo,linea)){
        istringstream separador(linea);
        separador >> primerLogin >> nombrePropio >> nombreGestor >> correo >> diasEnvios;
    }
    return " ";
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
    crearArchivoDatosIngresados(fechaPrimerLogin,nombrePropio,nombreDelGestor,correo,cantidadDeDias);
}
