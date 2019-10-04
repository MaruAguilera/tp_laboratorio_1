#define EMPLEADOS_NUMERO 1000
#define TEXT_SIZE 50
struct
{
 int id;
 char nombre[51];
 char apellido[51];
 float salario;
 int sector;
 int isEmpty;
}typedef Empleado;
//inicializa los empleados, recibe un vector y el tamnaño del mismo
int empleados_Inicializar(Empleado arrayEmpleados[], int size);
//genera el alta de los empleados, recibe el vecntor empleados, el tamaño y devuelve el contador id del empleado
int empleado_alta(Empleado arrayEmpleados[], int size, int* contadorID);
//busca si hay lugares vacios, y la posicion del mismo
int empleados_buscarEmpty(Empleado arrayEmpleados[], int size, int* posicion);
//busca al empleado por id, y devuelve la posicion del mismo
int empleado_buscarID(Empleado arrayEmpleados[], int size, int valorBuscado, int* posicion);
//modifca a los empleados
int empleado_modificar(Empleado arrayEmpleados[], int sizeArray);
//da de baja a los empleados
int empleado_baja(Empleado arrayEmpleados[], int sizeArray);
//ordena a los empleados por Apellido, si estos se repiten, los ordena por sector
int empleado_ordenar(Empleado arrayEmpleados[],int size);
//lista a los empleados
int empleado_listar(Empleado arrayEmpleados[], int size);
//te devuelve el alario promedio
float getSalarioPromedio(Empleado arrayEmpleados[],int arrayLenght);
//devuelve el numero de empleados que superan el salario promedio
int empleadosqueSuperanSalarioPromedio(Empleado arrayEmpleados[],int size,int promedioSalario);
//devuelve el salario total de todos los empleados
float getSalrioTotal(Empleado arrayEmpleados[],int size);




