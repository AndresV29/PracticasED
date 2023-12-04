#include <iostream>
#include <string>
#include <vector>
#include<ctime>
using namespace std;

struct Libro{
    string titulo, autor;
    bool disponible;
    int atraso;
    Libro* sig;
};

struct Usuario {
    string nombre;
    string contrasenia;
    int id;
    Usuario* siguiente;
   // vector<Libro*>librosPrestados;
};
struct Prestamo{
    string nomUsuario;
    string libro;
    int diasPrestado;
    Prestamo* siguiente;

};

//Menus
void mostrarMenuPrincipal(){
    cout << "Menu principal" << endl;
    cout << "1. Registro de libros" << endl;
    cout << "2. Registro de usuarios" << endl;
    cout << "3. Prestamos de libros" << endl;
    cout << "4. Salir" << endl;
    cout << "Ingrese una opcion: ";
};

void mostrarMenuLibros() {
    cout << "Menu de registro de libros"<< endl;;
    cout << "1. Agregar un libro" << endl;
    cout << "2. Mostrar todos los libros"<< endl;
    cout << "3. Buscar libros" << endl;
    cout << "4. Volver al menu principal" << endl;;
    cout << "Ingrese una opcion: ";
}
void MostrarMenuUsuarios() {
    cout << "Menu de registro de usuarios"<<endl;
    cout << "1. Registrar un usuario"<<endl;
    cout << "2. Mostrar todos los usuarios"<<endl;
    cout << "3. Volver al menu principal"<<endl;
    cout << "Ingrese una opcion: ";
}
void mostrarMenuPrestamos(){
    cout<<"Menu Gestion de Prestamos"<< endl;
    cout<<"1. Prestar un libro"<< endl;
    cout<<"2. Mostrar prestamos actuales"<<endl;
    cout<<"3. Devolver Libro" << endl;
    cout<<"4. Volver a menu principal"<<endl;
    cout<<"Ingrese una opcion: "<<endl;
}

//Libros
void prestarLibro(Usuario *usuario,Libro *libro,string libroB, string usuarioB){
    // lista users, libreria, lista prestamos, strings a buscar
    int dias = 10;
    auto *miPrestamo = new Prestamo;
    bool continuar = true;

    if (usuario == nullptr ){
        cout << "No existen usuarios" << endl;
    }
    if (libro== nullptr){
        cout << "No existen libros" << endl;

    }
    while (continuar) {
        if (usuario->nombre == usuarioB && libro->titulo == libroB) {

            miPrestamo->nomUsuario = usuarioB;
            miPrestamo->libro= libroB;
            miPrestamo->diasPrestado = dias;
            libro->disponible = false;
            cout << "Libro prestado con exito."<< endl;
            continuar = false;
        }
        //Buscar el siguiente en listas correspondientes.
        libro = libro->sig;
        usuario = usuario->siguiente;
    }
}
void mostrarPrestamos(Prestamo *cabeza){
    Prestamo* tmp = cabeza;

    if(cabeza == nullptr){
            cout << "No hay prestamos activos actualmente." << endl;
            return;
    }else{
            cout << "Lista de Prestamos:" << endl;
            while (tmp != nullptr) {
                cout << "Persona: " << tmp->nomUsuario<< ", Titulo: " << tmp->libro << endl;
                tmp = tmp->siguiente;
            }
            cout << endl;
        }

}
void devolverLibro(Libro* cabeza, string libroB, Prestamo *prestamo){
    Libro* actual = cabeza;
    Prestamo *temp = prestamo;
    bool found = false;
    int diasAtraso = 0;
    double multa=(diasAtraso-2)*20.2;
    //Validacion que existan libros en el sistema
    if (cabeza == nullptr) {
        cout << "No hay libros registrados en el sistema" << endl;
        return;
    }
    //Validacion de disponbilidad en el sistema
    if (actual->disponible == true) {
        cout << "Libro " << libroB << " actualmente no esta prestado." << endl;
    }
    while (actual) {
        if (actual->titulo == libroB && !actual->disponible && prestamo->libro == libroB) {
            actual->disponible = true;
            cout << "Libro devuelto y prestamo"<< prestamo << "anulado" << endl;
            //Calcula multa por atraso.
            cout << "Ingrese la cantidad de atraso que tiene el libro de atrasado: " << endl;
            cin >> diasAtraso;
            actual->atraso = diasAtraso;
            if (diasAtraso > 0) {
                cout << "Se le ha aplicado una multa de $"<< multa << endl;
                //Simular el pago de la multa
                cout << "Multa ha sido cancelada, gracias por su comprension." << endl;
            }else{
                cout << "No se le ha aplicado una multa." << endl;
            }
            //Borrar el prestamo.
            delete prestamo;
            found = true;
        }
        actual = actual->sig;
    }
    if (!found){
        cout << "El libro solicitado no se encuentra en el sistema." << endl;
    }
}

//libros
void agregarLibro(Libro*& cabeza, string nomAutor, string nomLibro){
    Libro* nuevo = new Libro;
    nuevo->autor = nomAutor;
    nuevo->titulo= nomLibro;
    nuevo->sig = cabeza;

    cabeza = nuevo;
    cout << "Se agrego con exito el libro."<< endl;
}


void mostrarLibros(Libro* cabeza){
    if(cabeza == nullptr){
        cout << "No hay libros registrados." << endl;
        return;
    }
    else{
        Libro* actual = cabeza;
        cout << "Lista de Libros:" << endl;
        while (actual != nullptr) {
            cout << "Autor: " << actual->autor << ", Titulo: " << actual->titulo << endl;
            actual = actual->sig;
        }
        cout << endl;
    }

}

void buscarLibros(Libro* cabeza, const string& infoLibro){
    if (cabeza == nullptr){
        cout << "El libro solicitado no se encuentra registrado en el sistema." << endl;
        return;
    }
    else{
        Libro* actual = cabeza;
        cout << "Resultados:" << endl;
        while (actual != nullptr){
            if (actual->titulo.find(infoLibro) != string::npos || actual->autor.find(infoLibro) != string::npos){
                cout << "Autor: " << actual->autor << " Titulo: " << actual->titulo << endl;
            }
            actual  = actual->sig;
        }
        cout << endl;
    }
}

//Usuarios
void agregarUsuarios(Usuario*& cabeza, string nombre, string contrasenia, int id){
    Usuario* nuevo_usuario = new Usuario;
    nuevo_usuario -> nombre = nombre;
    nuevo_usuario -> contrasenia = contrasenia;
    nuevo_usuario -> id = id;

    nuevo_usuario->siguiente = cabeza;
    cabeza = nuevo_usuario;

}

void mostrarUsuarios(Usuario* cabeza) {
    if(cabeza == nullptr){
        cout << "No hay usuarios registrados." << endl;
        return;
    }
    else{
        Usuario* actual = cabeza;
        cout << "Lista de Usuarios:" << endl;
        while (actual != nullptr) {
            cout << "Cedula: " << actual->id << ", Nombre: " << actual->nombre << endl;
            actual = actual->siguiente;
        }
        cout << endl;
    }
}

int main() {

    Usuario* listaUsuarios = nullptr;
    Libro* libreria = nullptr;
    string nombre, contrasenia, autor, titulo, infoLibro;
    Prestamo *prestamos = nullptr;
    int opcionMenuPrincipal, OpcionMenuUsuarios, OpcionMenuLibros, id,opcionMenuPrestamos;
    bool salirMenuPrincipal = false;
    bool salirMenuLibros = false;
    bool salirMenuUsuarios = false;
    //bool salirMenuPrestamos=false;
    //variable para salir del menu prestamos
    bool regresar = false;


    do {
        //Menu principal
        mostrarMenuPrincipal();
        cin >> opcionMenuPrincipal;

        switch (opcionMenuPrincipal) {
            case 1:
                salirMenuLibros = false;
                do {
                    mostrarMenuLibros();
                    cin >> OpcionMenuLibros;

                    switch (OpcionMenuLibros) {
                        //Menu de libros
                        case 1:
                            cout << "Ingrese el nombre del autor: ";
                            cin >> autor;
                            cout << "Ingrese el titulo del libro: ";
                            cin >> titulo;
                            agregarLibro(libreria, autor, titulo );
                            break;
                        case 2:
                            mostrarLibros(libreria);
                            break;
                        case 3:
                            cout << "Ingrese el titulo o autor del libro: ";
                            cin >> infoLibro;
                            buscarLibros(libreria, infoLibro);
                            break;
                        case 4:
                            salirMenuLibros = true;
                            break;
                        default:
                            cout << "Ingrese un numero del 1 al 4"<<endl;
                    }
                } while (!salirMenuLibros);
                break;

            case 2:
                salirMenuUsuarios = false;
                do {
                    MostrarMenuUsuarios();
                    cin >> OpcionMenuUsuarios;

                    switch (OpcionMenuUsuarios) {
                        //Menu de usuarios
                        case 1:
                            cout << "Nombre del usuario: ";
                            cin >> nombre;
                            cout << "Contrasenna: ";
                            cin >> contrasenia;
                            cout << "ID del usuario: ";
                            cin >> id;
                            agregarUsuarios(listaUsuarios, nombre, contrasenia, id);
                            cout << "Usuario agregado con exito." << endl;
                            break;
                        case 2:
                            mostrarUsuarios(listaUsuarios);
                            break;
                        case 3:
                            salirMenuUsuarios = true;
                            break;
                        default:
                            cout << "Ingrese opciones válidas del 1 al 3"<<endl;
                            break;
                    }
                } while (!salirMenuUsuarios);
                break;
            case 3:
                do{
                    //Menu de prestamos
                    mostrarMenuPrestamos();
                    cin>>opcionMenuPrestamos;
                    switch (opcionMenuPrestamos)
                    {
                        case 1:
                            //Crear prestamo libro
                            cout << "Ingrese el titulo del libro: ";
                            cin >> titulo;
                            cout << "Ingrese el nombre del usuario: ";
                            cin >> nombre;
                            prestarLibro(listaUsuarios,libreria, titulo, nombre);
                            break;
                        case 2:
                            //Mostrar prestamos
                            mostrarPrestamos(prestamos);
                            break;
                        case 3:
                            //Devolver y calcular la multa
                            cout << "Ingrese el titulo del libro: ";
                            cin >> titulo;
                            devolverLibro(libreria, titulo, prestamos);
                            break;
                        case 4:
                            //Salir al menu principal
                            regresar = true;
                            break;
                        default:
                            cout<<"opcion no es valida" << endl;
                            break;
                    }
                }while(!regresar);
                break;
            case 4:
                //Salir del programa
                salirMenuPrincipal = true;
                break;
            default:
                cout << "Ingrese opciones validas del 1 al 3" << endl;
                break;
        };
    } while (!salirMenuPrincipal);

    cout << "Gracias por utilizar el programa";
    return 0;
}
