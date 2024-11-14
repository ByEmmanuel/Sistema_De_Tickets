#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
#include <limits>
#include <algorithm> 
#include <thread>
using namespace std; 
int userop;
int user_acces;
int second_acces;
int id;

//función menú
void main_menu(){
        cout << "\n\t\t\t---Bienvenido al Sistema de Tickets---" << endl;
        cout << "\n\t╦ Seleccione una operación:═══════════╗"<<endl;
        cout << "\t╠ 1) Búsqueda de Usuario              ║"<<endl;
        cout << "\t╠ 2) Actualizar datos de Usuario      ║"<<endl;
        cout << "\t╠ 3) Registrar Usuario                ║"<<endl;
        cout << "\t╠ 4) Borrar Usuario                   ║"<<endl;
        cout << "\t╠ 5) Acción de Usuario                ║"<<endl;
        cout << "\t╠ 6) Salir                            ║" <<endl;
        cout << "\t╚═════════════════════════════════════╝"<<endl;
        cout << "\nEjecutar operación ─> ";
        }
//Funcion menú secundario//
//función menú
void second_menu(){
        cout << "\n\t\t\t---Acciones de Usuario---" << endl;
      cout << "\n\t╦ Seleccione una operación:═════════════════════╗"<<endl;
        cout << "\t╠ 1) Generar cita                               ║"<<endl;
        cout << "\t╠ 2) Consultar cita                             ║"<<endl;
        cout << "\t╠ 3) Cancelar cita                              ║"<<endl;
        cout << "\t╠ 4) Consulta de citas disponibles              ║"<<endl;
        cout << "\t╠ 5) Horarios de Atención                       ║"<<endl;
        cout << "\t╠ 6) Volver a inicio                            ║" <<endl;
        cout << "\t╚═══════════════════════════════════════════════╝"<<endl;
        cout << "\nEjecutar operación ─> ";
        }
//  v v v  // User vector //
struct user{
    int id;
    string nombre;
    string apellidop;
    string apellidom;
    int passnum;
    string referencia;
    long long phone_number;
    string user_email;    
    };
    //  v v v  // Cita vector //
struct cita{
    long long id_cita;
    string operacion_cita;
    string area;
    string departamento;    
    string referencia;    
    //agregar personal que atiende    
    };
// funcion generacion de ID random único
int identification_Number() {
    srand(time(0));  
    int id = 10001 + rand() % 99999; 
    return id;
}
// Número NIP o contraseña de 5 dígitos
int pass_Number(){
    int passnum;
    cout<<"Por favor escribe un NIP de 5 dígitos\n a continuación -> ";
    cin>>passnum;
     while (passnum < 10000 || passnum > 99999) {
        cout << "\033[1;31mEl NIP debe contener 5 dígitos.\n Por favor inténtalo de nuevo\033[0m -> ";
        cin >> passnum;
    }
    return passnum;
}
// Número de teléfono
long long user_phone_Number() {
    long long phone_number;
    cout << "Por favor ingresa tu número telefónico (10 dígitos): ";
    // Validación del número de teléfono
    while (true) {
        cin >> phone_number;
        // Verificar que la entrada es un número válido
        if (cin.fail() || phone_number < 1000000000 || phone_number > 9999999999) {
            cin.clear();            
            cin.ignore(numeric_limits<streamsize>::max(), '\n');           
            cout << "\033[1;31mEl número ingresado no es válido. Debe tener 10 dígitos.\n";
            cout << "Por favor, inténtalo de nuevo.\033[0m -> ";
        } else {
            break;
        }
    }
    
    return phone_number;
}
// Correo electrónico
void user_Mail(string& user_email) {    
    cin.ignore(); 
    cout << "Por favor, proporcione una dirección \nde correo elecrónico: ";
    getline(cin, user_email);  
}
// Nombre y apellido de usuario
void user_Name(string& nombre, string& apellidop, string& apellidom) {
    
    cin.ignore(); 
    cout << "Escribe tu nombre: ";
    getline(cin, nombre);  

    cout << "Escribe tu apellido Paterno: ";
    getline(cin, apellidop);

    cout << "Escribe tu apellido Materno: ";
    getline(cin, apellidom);  
}
//Eliminación de Usuario
void delete_user_by_id(vector<user>& users, int id) {
    auto it = find_if(users.begin(), users.end(), [id](const user& u) { return u.id == id; });
    
    if (it != users.end()) {
        users.erase(it);
        cout << "\033[1;32mUsuario con ID " << id << " eliminado exitosamente.\033[0m\n";
    } else {
        // Si no lo encontramos, mostramos un mensaje de error
        cout << "\033[1;31mUsuario con ID " << id << " no encontrado.\033[0m\n";
    }
}
// Creación de usuario
user create_user() {
    user nuevo_usuario;
    nuevo_usuario.id = identification_Number();
    user_Name(nuevo_usuario.nombre, nuevo_usuario.apellidop, nuevo_usuario.apellidom);    
    nuevo_usuario.phone_number = user_phone_Number();
    user_Mail(nuevo_usuario.user_email);
    nuevo_usuario.passnum = pass_Number();
    cout << "Usuario creado con ID: " << nuevo_usuario.id << endl; // Depuración
    return nuevo_usuario;
}
// Búsqueda por ID
user* search_user_by_id(const vector<user>& users, int id) {
    for (size_t i = 0; i < users.size(); ++i) {
        if (users[i].id == id) {
            return const_cast<user*>(&users[i]);  // Devolver un puntero al usuario encontrado
        }
    }
    return nullptr;  // Si no se encuentra el usuario, devolver nullptr
}
void show_user_details(const user& u) {
    cout << "ID: " << u.id << endl;
    cout << "Nombre: " << u.nombre << endl;
    cout << "Apellido Paterno: " << u.apellidop << endl;
    cout << "Apellido Materno: " << u.apellidom << endl;
    cout << "Correo asociado: "<< u.user_email << endl;
    cout << "Número telefónico: " << u.phone_number << endl;
}
//Función 4 Actualizar
void update_user(vector<user>& users, int id) {
  
    user* u = search_user_by_id(users, id);    
    if (u != nullptr) {  
        int option;
        cout << "Usuario encontrado: " << u->nombre << " " << u->apellidop << " " << u->apellidom << endl;
        cout << "¿Qué campo deseas actualizar?\n";
        cout << "1. Nombre\n";
        cout << "2. Apellido Paterno\n";
        cout << "3. Apellido Materno\n";
        cout << "4. Número de Teléfono\n";
        cout << "5. Correo Electrónico\n";
        cout << "6. NIP (Contraseña)\n";
        cout << "Selecciona una opción: "; cin >> option;      
        // Dependiendo de la opción, actualizar el campo correspondiente
        switch (option) {
            case 1:
            {
                cout << "Escribe el nuevo nombre: ";
                cin.ignore(); 
                getline(cin, u->nombre);
                break;}
            case 2:{
                cout << "Escribe el nuevo apellido paterno: ";
                cin.ignore();  
                getline(cin, u->apellidop);
                break;}
            case 3:{
                cout << "Escribe el nuevo apellido materno: ";
                cin.ignore();  
                getline(cin, u->apellidom);
                break;}
            case 4:{
                u->phone_number = user_phone_Number(); 
                break;}
            case 5:{
                user_Mail(u->user_email); 
                break;}
            case 6:{
                u->passnum = pass_Number(); 
                break;}
            default:
                cout << "\033[1;31mOpción inválida. No se realizó ninguna actualización.\033[0m\n";
                return;
        }

        cout << "\033[1;32mLos datos del usuario han sido actualizados exitosamente.\033[0m\n";
    } else {
        cout << "\033[1;31mUsuario con ID " << id << " no encontrado.\033[0m\n";
    }
}


int main(){
        
        vector<user> users;
    do{
        main_menu();
        cin>> userop;
        switch(userop){

        //inicio de menú interactivo
        case 1:{
           cout<<"\n\t\t\t===> Búsquedas <===" <<endl;
           cout<<"\n Ingrese su número de identificación ";
           cout<<"Ingresar__";cin>> id;
           user* encontrado = search_user_by_id(users, id);
                if (encontrado != nullptr) {
                    cout << "\n\033[1;32mUsuario encontrado.\033[0m\n"<<endl;
                    show_user_details(*encontrado);
                    this_thread::sleep_for(chrono::seconds(3));
                                        
                } else {
                    cout << "\033[1;31mUsuario no encontrado.\033[0m\n"; 
                    this_thread::sleep_for(chrono::seconds(2));                                      
                }                      
          break; 
        }
        case 2:{             
            cout << "Ingresa el ID del usuario a actualizar -> ";cin >>id;
            update_user(users, id);        
            this_thread::sleep_for(chrono::seconds(2));
            break;
             }
        case 3:{
              cout<<"\n\t\t\t===> Nuevo Usuario <==="<<endl;
              cout<<"\n\t\t\t-+ A continuación, por favor, ingrese los siguientes datos \npara crear un nuevo formato de -ticket-"<<endl;
            
             user nuevo_usuario = create_user();
                users.push_back(nuevo_usuario);            
                cout << "\n\t\t\t---Detalles del nuevo usuario---\n";
                cout << "╦  ID: " << nuevo_usuario.id << endl;
                cout << "╠  Nombre(s): " << nuevo_usuario.nombre << endl;
                cout << "╠  Apellido 1: " << nuevo_usuario.apellidop << endl;
                cout << "╠  Apellido 2: " << nuevo_usuario.apellidom << endl;
                cout << "╠  Correo asociado: " << nuevo_usuario.user_email << endl;
                cout << "╠  Teléfono: " << nuevo_usuario.phone_number << endl;
                cout << "╠  NIP: " << nuevo_usuario.passnum << endl;
                cout << "╚══════════════════════════════════════════╝"<< endl;
                cout << "\033[1;32mTerminado exitosamente.\033[0m\n"<<endl; 
                this_thread::sleep_for(chrono::seconds(3));                 
                break;             
            }
        
        case 4:{
            cout<<"\n\t\t\t===> Eliminar Usuario <==="<<endl;
            cout<<"Por favor ingresa tu ID\na continuación -> ";cin>>id;
            delete_user_by_id(users, id); 
            this_thread::sleep_for(chrono::seconds(1));                        
        }
        break;
        //ACCIONES DE USUARIO//
        case 5:{
            second_menu();
            cin>>user_acces;
            do{ switch (user_acces)
            {
            case 1:{
                /* code */
            }break;
            case 2:{

            }break;
            case 3:{

            }break;
            case 4:{

            }break;
            case 5:{

            }break;
            case 6:{

            }break;
                default:
                cout<<"\033[1;31mOpción no válida\033[0m"<<endl;
                cout<<"Por favor intente de nuevo."<<endl;
                break;
            }

            }while(user_acces !=6);
            
           }  
        break;
        //SALIDA//
        case 6:{
            cout<<"Gracias por utilizar nuestro Sistema de Tickets"<<endl;
            system("PAUSE");
            cout<<"Saliendo..."<<endl;
        }  break;

        default:
            cout<<"\033[1;31mOpción no válida\033[0m"<<endl;
            cout<<"Por favor intente de nuevo."<<endl;


return 0; 
        }
    }while(userop !=6);
}