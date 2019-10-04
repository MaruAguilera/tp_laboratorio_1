/*
 ============================================================================
 Name        : Tp2.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmpleados.h"
#include "utn.h"



int main(void) {

Empleado arrayEmpleado[EMPLEADOS_NUMERO];
empleados_Inicializar(arrayEmpleado,EMPLEADOS_NUMERO);

int opcion;
int contadorIdEmpleados;
int flag =0;
float promedioSalarios;
int CantidadEmpleadossuperanSalariopromedio;
float salarioTotal;

	do {
		utn_getIntSinSigno("\n\n1) Alta \n2) Modificar \n3) Baja \n4) Informar \n5)Salir\n","\nError, numero invalido",1,sizeof(int),1,5,1,&opcion);
		switch (opcion) {
			case 1:
				if(empleado_alta(arrayEmpleado,EMPLEADOS_NUMERO,&contadorIdEmpleados)==0)
				{
					printf("\nSe cargo el empleado exitosamente");
				}else{
					printf("\nEl empeado no se cargo, intente nuevamente");
				}
				flag=1;
				break;
			case 2:
				if(flag==1 && empleado_modificar(arrayEmpleado,EMPLEADOS_NUMERO)==0){
					printf("\nSe modifico el usuario");
				}else{
					printf("\nNo se pudo modificar el usuario, intete nuevamente");
				}

				break;
			case 3:
				if(flag==1 && empleado_baja(arrayEmpleado, EMPLEADOS_NUMERO)==0 )
				{
					printf("\nEl empleado se dio de baja");
				}else{
					printf("\nEl empleado no se pudo dar de baja, intente nuevamente");
				}

				break;

			case 4:



				if(empleado_ordenar(arrayEmpleado,EMPLEADOS_NUMERO)==0)
				   {
				      if(empleado_listar(arrayEmpleado,EMPLEADOS_NUMERO)==0)
				          {

				    	   salarioTotal = getSalrioTotal(arrayEmpleado,EMPLEADOS_NUMERO);
				    	   printf("\nsalario total  %f",salarioTotal);
				           promedioSalarios=getSalarioPromedio(arrayEmpleado,EMPLEADOS_NUMERO);
				           printf("\npromedio salario  %f",promedioSalarios);
				           CantidadEmpleadossuperanSalariopromedio=empleadosqueSuperanSalarioPromedio(arrayEmpleado,EMPLEADOS_NUMERO,promedioSalarios);
				           printf("\ncantidad empleados que superan el promedio  %d ",CantidadEmpleadossuperanSalariopromedio );

				             }
				           }
				           else
				           {
				             printf("\nNo hay empleados registrados\n");
				           }



				break;
		}




	} while (opcion !=5);

	return 0;
}

