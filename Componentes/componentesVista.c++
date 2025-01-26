#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstring>
#include <sstream>
#include <vector>
#include <cstdio>
using namespace std;

const string direccionArchivoDatos = "DatosLogin/Datos.txt"; 
const string direcionDoc = "DatosLogin/Doc.txt";
const string direccionBanner = "Componentes/banner.txt";
vector<string> arregloDeDatosConstante;  

void abrirDocumentacion();
void LogoPixel();
void vistaDespuesRegistro(string datosRegistro[], int tamano);
void creaArchivoDatosIngresados(string arreglo[], int tamano);
bool validarExistenciaArchivoDatos();
void regresarDatosDocTXT();
void RegistrarDatos();
void accesoPermitido();
void menuAccesoPermitido(string listaDatos[], int tamano);
void vistaGananciaMensual();
void vistaIngresarMensual();
void vistaIngresarAhorros();
void vistaVerProximosPagos();
void vistaListaGastos();
void regresarDatosUsuarioTXT();


void vistaDespuesRegistro(){
    int opcion;
    string nombre = arregloDeDatosConstante[1];
    string nombreGestor = arregloDeDatosConstante[2];
    cout << "Binvenido " << nombre << " soy " << nombreGestor <<endl;
    cout << "Estas son las opciones displonibles:  " << endl;
    cout << "[1] ingresar ganancias quincenales" << endl;
    cout << "[2] ingresar perdidas" << endl;
    cout << "[3] ingresar ahorros" << endl;
    cout << "[4] lista de gastos" << endl;
    cout << "[5] Ver pagos / prestamos / proximos pagos" << endl;

    //switch(opcion){
    //    case 1:
    //}
}

void regresarDatosUsuarioTXT() {
    ifstream archivo(direccionArchivoDatos);
    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo." << endl;
        return;
    }
    string fecha, nombrePropio, nombreGestor, correo, diasEnvios;
    getline(archivo, fecha);
    getline(archivo, nombrePropio);
    getline(archivo, nombreGestor);
    getline(archivo, correo);
    getline(archivo, diasEnvios);

    archivo.close();
    arregloDeDatosConstante = {fecha, nombrePropio, nombreGestor, correo, diasEnvios};
}

void LogoPixel(){
   ifstream archivoEntrada(direccionBanner);
   string lineas;
    while(getline(archivoEntrada,lineas)){
        cout << lineas << endl;
    }
    archivoEntrada.close();

}

void abrirDocumentacion(){
    system("xdg-open DatosLogin/Doc.txt > /dev/null 2>&1 &");
}
//2
void  crearArchivoDatosIngresados(string primerLogin, string nombrePropio, string nombreGestor, string correo, string diasDeEnvios){
    ofstream archivo(direccionArchivoDatos);
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
//1
void RegistrarDatos(){
    cout << "[1]   Breve introduccion, si desea leer la instruccion " << endl;
    cout << "[Y / N]" << endl;
    string opcion;
    cin >>  opcion;

    if(opcion == "Y" || opcion == "y"){
        // redireccion para leer la documentacion 
        abrirDocumentacion();
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

bool validarExistenciaArchivoDatos(){
    string linea;
    ifstream archivo(direccionArchivoDatos);

    //valida si exciste
    if(!archivo){
        //ni existe el archivo, funcion
        //RegistrarDatos();
        return false;
    }   
    //valida si esta vacio
    if(!getline(archivo,linea)){
        cout << "los datos fueron modificados, se redirigera... \n" << endl;
        //RegistrarDatos();
        return false;
    }
    return true;
}



void abrirConsolaNueva(){
    string comando = "gnome-terminal ";
    system(comando.c_str());
    cout << "asdasdasdasda" << endl;

    cout << "asdfkajds" << endl;
}
void vistaGananciaMensual(){

}
void vistaIngresarMensual(){

}
void vistaIngresarAhorros(){

}
void vistaListaGastos(){

}
void vistaVerProximosPagos(){

}