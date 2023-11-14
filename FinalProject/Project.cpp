#include <iostream>
#include <string>
#include <vector>
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
};


void mostrarMenuPrincipal(){
    cout << "\nMenu principal\n";
    cout << "\n 1. Registro de libros\n";
    cout << "\n 2. Registro de usuarios\n";
    cout << "\n 3. Salir\n";
    cout << "\nIngrese una opcion:\n ";
};

void mostrarMenuLibros() {
    cout << "\nMenu de registro de libros\n";
    cout << "1. Agregar un libro\n";
    cout << "2. Mostrar todos los libros\n";
    cout << "3. Buscar libros" << endl;
    cout << "4. Devolver Libro" << endl;
    cout << "5. Volver al menu principal\n";
    cout << "Ingrese una opcion: ";
}
void MostrarMenuUsuarios() {
    cout << "\nMenu de registro de usuarios\n";
    cout << "1. Registrar un usuario\n";
    cout << "2. Mostrar todos los usuarios\n";
    cout << "3. Volver al menu principal\n";
    cout << "Ingrese una opcion: ";
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
    int opcionMenuPrincipal, OpcionMenuUsuarios, OpcionMenuLibros, id;
    bool salirMenuPrincipal = false, salirMenuLibros = false, salirMenuUsuarios = false;

    do {
        mostrarMenuPrincipal();
        cin >> opcionMenuPrincipal;

        switch (opcionMenuPrincipal) {
            case 1:
                salirMenuLibros = false;
                do {
                    mostrarMenuLibros();
                    cin >> OpcionMenuLibros;

                    switch (OpcionMenuLibros) {
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
                            cout << "Ingrese opciones válidas del 1 al 3\n";
                    }
                } while (!salirMenuLibros);
                break;

            case 2:
                salirMenuUsuarios = false;
                do {
                    MostrarMenuUsuarios();
                    cin >> OpcionMenuUsuarios;

                    switch (OpcionMenuUsuarios) {
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
                            cout << "Ingrese opciones válidas del 1 al 3\n";
                            break;
                    }
                } while (!salirMenuUsuarios);
                break;

            case 3:
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
