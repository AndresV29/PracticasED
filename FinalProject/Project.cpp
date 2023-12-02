#include <iostream>
#include <string>
#include <vector>
#include<ctime>
using namespace std;

struct Libro{
    string titulo, autor, disponible;
    int atraso;
    Libro* sig;
};

struct Usuario {
    string nombre;
    string contrasenia;
    int id;
    Usuario* siguiente;
    vector<Libro*>librosPrestados;
};
struct Prestamo{
    Usuario *usuario;
    Libro *libro;
    //hacerlo con numeros porque time cuenta que tiempo si pase.
    int fechaPrestamo;

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
    cout << "4. Devolver Libro" << endl;
    cout << "5. Volver al menu principal" << endl;;
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
    cout<<"Menu gestion de prestamos"<< endl;
    cout<<"1. Prestar un libro"<< endl;
    cout<<"2. Mostrar los prestamos"<<endl;
    cout<<"3.Calcular multa" << endl;
    cout<<"4. Volver a menu principal"<<endl;
    cout<<"5.Ingrese una opcion: "<<endl;
}

//Libros
void prestarLibro(Usuario*usuario,Libro*libro){
    double dias = 10;
    if(libro){
        cout<<"Libro no  se encuentra disponible"<<endl;
        return;
    }
    for(Libro*prestado:usuario->librosPrestados){
        if(prestado==libro){
            cout<<"Libro prestado de manera exitosa"<<endl;
            return;
        }
    }
    libro->disponible=false;
    usuario->librosPrestados.push_back(libro);
    //time_t now=time(nullptr);
    Prestamo Prestamo;
    Prestamo.usuario=usuario;
    Prestamo.libro=libro;
    //Prestamo.fechaPrestamo=now;
    Prestamo.fechaPrestamo = dias;
    cout<<"Libro prestado!"<<endl;
}
void calcularMulta(const Prestamo& Prestamo){
   // time_t now= time(nullptr);
    //double diasAtraso=difftime(now, Prestamo.fechaPrestamo)/(60*60*24);
    double dias = Prestamo.fechaPrestamo;
    double atraso = 0;
    cout << "Ingrese la cantidad de dias de atraso: ";
    cin >> atraso;
    if (atraso>1)
    {
        double multa=(atraso-2)*20.2;
        cout<<"La multa es de  ₡"<<multa<<"por retraso en devolver el libro"<<endl;
    }else{
        cout<<"Libro devuelto a tiempo, no se le cobra una multa."<<endl;
    }

}

void agregarLibro(Libro*& cabeza, string nomAutor, string nomLibro){
    Libro* nuevo = new Libro;
    nuevo->autor = nomAutor;
    nuevo->titulo= nomLibro;
    nuevo->sig = cabeza;

    cabeza = nuevo;
    cout << "Se agrego con exito el libro."<< endl;
}
void devolverLibro(Libro* cabeza, string libroB){
    Libro* actual = cabeza;
    bool found = false;
    string estado = "disponible";
    int diasAtraso;

    while (actual) {
        if (actual->titulo == libroB) {
            cout<< "Libro Encontrado!" << endl;
            actual->disponible = estado;
            cout << "Libro devuelto" << endl;
            cout << "Ingrese la cantidad de atraso que tiene el libro de atrasado: " << endl;
            cin >> diasAtraso;
            actual->atraso = diasAtraso;
            if (diasAtraso > 0) cout << "Se le ha aplicado una multa de 10$ por cada dia de atraso";
            found = true;
        }
        actual = actual->sig;
    }

    if (!found) {
        cout << "Libro " << libroB << " actualmente no esta prestado." << endl;
    }
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
        cout << "No se encontro el libro." << endl;
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
            cout << "ID: " << actual->id << ", Nombre: " << actual->nombre << endl;
            actual = actual->siguiente;
        }
        cout << endl;
    }
}

int main() {

    Usuario* listaUsuarios = nullptr;
    Libro* libreria = nullptr;
    string nombre, contrasenia, autor, titulo, infoLibro;
    Prestamo *prestamos;
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
                            cout << "Ingrese el titulo del libro: ";
                            cin >> titulo;
                            devolverLibro(libreria, titulo);
                            break;
                        case 5:
                            salirMenuLibros = true;
                            break;
                        default:
                            cout << "Ingrese opciones válidas del 1 al 3"<<endl;
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
                            cout << "Contraseña: ";
                            cin >> contrasenia;
                            cout << "ID del usuario: ";
                            cin >> id;
                            agregarUsuarios(listaUsuarios, nombre, contrasenia, id);
                            cout << "Usuario agregado con éxito." << endl;
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
                    mostrarMenuPrestamos();cin>>opcionMenuPrestamos;
                    switch (opcionMenuPrestamos)
                    {
                        case 1:
                            prestarLibro(listaUsuarios,libreria);
                            break;
                        case 2:
                            //Mostrar prestamos

                            break;
                        case 3:
                            //calcularMulta();
                            break;
                        case 4:
                            //Regresar menu principal
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
                cout << "Ingrese opciones validas del 1 al 3\n";
                break;
        };
    } while (!salirMenuPrincipal);

    cout << "Gracias por utilizar el programa";
    return 0;
}
