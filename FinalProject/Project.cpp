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

void agregarUsuarios(Usuario*& cabeza, string nombre, string contrasenia, int id);
void agregarLibro(Libro*& cabeza, string nomAutor, string nomLibro);
void agregarPrestamo(Prestamo*& cabeza, string nombreLibro, string nombreUsuario);



void insertaDatosPruebas(Usuario *&usuario,Libro *&libro){
    agregarUsuarios(usuario, "Mario", "1111", 1);
    agregarUsuarios(usuario, "Peach", "2222", 2);
    agregarUsuarios(usuario, "Bowser", "3333", 3);
    agregarUsuarios(usuario, "Wario", "4444", 4);
    agregarUsuarios(usuario, "Luigi", "5555", 5);

    agregarLibro(libro, "Jean", "El_principito");
    agregarLibro(libro, "Bran", "Dracula");
    agregarLibro(libro, "Gabriel Garcia", "100_annos_de_soledad");
}

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
void prestarLibro(Prestamo *& miPrestamo, Usuario *usuario,Libro *libro,string libroB, string usuarioB){
    // lista users, libreria, lista prestamos, strings a buscar
    int dias = 10;
    //auto *miPrestamo = new Prestamo;
    bool siLibro, siUsuario = false;

    if (usuario == nullptr ){
        cout << "No existen usuarios" << endl;
        return;
    }
    if (libro== nullptr){
        cout << "No existen libros" << endl;
        return;
    }
    do{
        if(libro->titulo == libroB){
            siLibro = true;
            libro->disponible = false;
            break;
        } else{
            libro = libro->sig;
        }
    }while(libro != nullptr);

    do{
        if(usuario->nombre == usuarioB){
            siUsuario = true;
            break;
        } else{
            usuario = usuario->siguiente;
        }
    }while(usuario!= nullptr);
    if (siLibro && siUsuario) {
        agregarPrestamo(miPrestamo, libroB, usuarioB);
        //llamar insertar prestamo

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
void devolverLibro(Libro* cabeza, string libroB, Prestamo *&prestamo){
    Libro* actual = cabeza;
    Prestamo *temp = prestamo;
    Prestamo *anterior = temp;
    int diasAtraso = 0;
    double multa=(diasAtraso)*20.2;
    //Validacion que existan libros en el sistema
    if (cabeza == nullptr) {
        cout << "No hay libros registrados en el sistema" << endl;
        return;
    }
    //Validacion de disponbilidad en el sistema
//    if (actual->disponible == true) {
//        cout << "Libro " << libroB << " actualmente no esta prestado." << endl;
//        return;
//    }


//busqueda del libro en la lista de libros
    while(actual!= nullptr){
        if(actual->titulo == libroB){
            if(actual->disponible == true){
                cout << "El libro no ha sido prestado";
                return;
            }
            break;
        }
        actual = actual->sig;
    }

    //busqueda del libro en lista de prestamos
    while(temp != nullptr){
        if(temp->libro == libroB){
            break;
        }
        anterior = temp;
        temp = temp->siguiente;
    }
    
    //verifica si libro fue encontrado en lista de libros, sino nos vamos
    if(actual == nullptr){
        cout << "libro no encotrado!" << endl;
        return;
    }
    
    //verificamos si el libro fue encontrado en lista de prestamos, sino nos vamos
    if(temp == nullptr){
        cout << "libro no ha sido prestado" << endl;
        return;
    }

    //despues de todas las verificaciones, se libera el libro
    //se aplica la multa y finalmente se borra de prestamos
    actual->disponible = true;
    cout << "Libro devuelto y prestamo anulado" << endl;
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
    //El proceso de borrado verifica si el elemento a borrar
    //corresponde al unico prestamo de la lista, si es asi 
    //se le vuelve a asignar el nullptr para evitar errores de 
    //verifiacion posteriores 
    anterior->siguiente = temp->siguiente;
    if(temp == prestamo){
        delete temp;
        prestamo = nullptr;
    }else{
        delete temp;
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

void agregarPrestamo(Prestamo*& cabeza, string nombreLibro, string nombreUsuario){
    Prestamo* nuevoPrestamo = new Prestamo;
    nuevoPrestamo->libro = nombreLibro;
    nuevoPrestamo->nomUsuario = nombreUsuario;
    nuevoPrestamo->diasPrestado = 1;

    nuevoPrestamo->siguiente = cabeza;
    cabeza = nuevoPrestamo;
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

    insertaDatosPruebas(listaUsuarios, libreria);

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
                            prestarLibro(prestamos, listaUsuarios,libreria, titulo, nombre);
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
