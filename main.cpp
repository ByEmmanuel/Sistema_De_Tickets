#include <ioStream>
#include <string>

using namespace std;

int main()
{   //Guadado de datos
       string nombre[20];
       string apellido[20];
       int codigo_de_estudiante[20];
       string correo[20];       
       
       for (int i = 0; i < 1; ++i) {
        cout << "Introduce tu nombre " << i + 1 << ": ";
        cin >> nombre[i];
        cout << "Introduce tu apellido " << i + 1 << ": ";
        cin >> apellido[i];
        cout << "Introduce tu código de estudiante " << i + 1 << ": ";
        cin >> codigo_de_estudiante[i];
        cout << "Introduce tu correo estudiantil " << i + 1 << ": ";
        cin >> correo[i];}

    //("Juan", "Perez", "000000001", "alumno@correo.com");
    
    //Inicio de sesión
       int codigo_inicio;
       cout << "Introduce tu codigo de estudiante para ingresar";
       cin >> codigo_inicio;

       bool encontrado = false;
       for(int i = 0; i < 10; ++i){
        if (codigo_inicio == codigo_de_estudiante[i]){
            cout << "Bienvenido " << nombre[i] << ":)" << endl;
            encontrado = true;
            break;
            }
    //Inicio del Menu        
            int opc = -1;
            string pausa; 
            string PROFESORES[2] = {"Conchita Alcatraz" , "Mario Catañeda"};

            do{ 
                cout << ("**Sistema de citas**") << endl;
                cout << ("1. Solicitar una cita") << endl;
                cout << ("2. Ver profesores disponibles") << endl;
                cout << ("0. Salir") << endl;
                cin >> opc;
                if(opc == 1){
                    cout << ("**Solicita tu cita**") << endl;
                    string nombre_profesor;
                    cout << ("Introduce el nombre del profesor") << endl;
                    cin >> nombre_profesor;
                    
                    bool profesor_encontrado = false;
                    for(int j = 0; i < 2; ++j){
                    if(nombre_profesor == PROFESORES[j])
                    cout << ("Cita solicitada por :") << nombre[i] << "para ver a" << nombre_profesor << endl;
                    profesor_encontrado = true;
                    break;
                    }
                    {
                        if(!profesor_encontrado){
                            cout << "Profesor no encontrado" << endl;}
                    }
                }
                else if (opc == 2){
                    cout << ("**Profesores disponibles**") << endl;
                    
                    cout << PROFESORES << endl;
                    }
                    cout << "Para regresar escribe 'regresar' o teclea 0 "  << endl;
                    int regresar;
                    cin >> regresar;
                    if (regresar == 0) {
                        continue; // Regresar al menú anterior                   
                }
                else if (opc == 0){
                    cout << ("Saliendo...") << endl;
                }
            } while (opc != 0);
            break;
       }
       if (!encontrado){
        cout << "Datos incorrectos o alumno no existente" << endl;
       }
    return 0;
}