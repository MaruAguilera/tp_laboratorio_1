#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmpleados.h"
#include "utn.h"

int empleados_Inicializar(Empleado arrayEmpleados[], int size)
{
    int retorno=-1;
    if(arrayEmpleados!= NULL && size>0)
    {
        for(;size>0;size--)
        {
            arrayEmpleados[size-1].isEmpty=1;
        }
        retorno=0;
    }
    return retorno;
}


int empleado_alta(Empleado arrayEmpleados[], int size, int* contadorID)
{
    int retorno=-1;
    int posicion;
    if(arrayEmpleados!=NULL && size>0 && contadorID!=NULL)
    {
        if(empleados_buscarEmpty(arrayEmpleados,size,&posicion)==-1)
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            arrayEmpleados[posicion].id=*contadorID;
            arrayEmpleados[posicion].isEmpty=0;
            utn_getString("\nIngrese el nombre el empleado ","\nError, nombre no valido",1,TEXT_SIZE,5,&arrayEmpleados[posicion].nombre);
            utn_getString("\nIngrese el apelido el empleado ","\nError, apellido no valido",1,TEXT_SIZE,1,&arrayEmpleados[posicion].apellido);
            utn_getFloat("\nIngrese el salario ","\nError,salario incorrecto",1,10,0,10,1,&arrayEmpleados[posicion].salario);
            utn_getIntConSigno("\nIngrese el sector  ","\nError, sector no valido",1,sizeof(int),0,10,1,&arrayEmpleados[posicion].sector);

            printf("\nPosicion %d", posicion);
            printf("\nId %d", arrayEmpleados[posicion].id);
            printf("\nNombre %s", arrayEmpleados[posicion].nombre);
            printf("\nApellido %s", arrayEmpleados[posicion].apellido);
            printf("\nSalario %f", arrayEmpleados[posicion].salario);
            printf("\nSector %d", arrayEmpleados[posicion].sector);
            retorno=0;
        }
    }

    return retorno;
}

int empleados_buscarEmpty(Empleado arrayEmpleados[], int size, int* posicion)
{
    int retorno=-1;
    int i;
    if(arrayEmpleados!= NULL && size>=0 && posicion!=NULL)
    {
        for(i=0;i<size;i++)
        {
            if(arrayEmpleados[i].isEmpty==1)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}
int empleado_buscarID(Empleado arrayEmpleados[], int size, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(arrayEmpleados!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(arrayEmpleados[i].isEmpty==1)
                continue;
            else if(arrayEmpleados[i].id==valorBuscado)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}
int empleado_modificar(Empleado arrayEmpleados[], int sizeArray)
{
    int retorno=-1;
    int posicion;
    int id;
    char opcion;
    if(arrayEmpleados!=NULL && sizeArray>0)
    {
        utn_getIntSinSigno("\nID a modificar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);
        if(empleado_buscarID(arrayEmpleados,sizeArray,id,&posicion)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {


                 printf("\nPosicion %d", posicion);
                 printf("\nId %d", arrayEmpleados[posicion].id);
                 printf("\nNombre %s", arrayEmpleados[posicion].nombre);
                 printf("\nApellido %s", arrayEmpleados[posicion].apellido);
                 printf("\nSalario %f", arrayEmpleados[posicion].salario);
                 printf("\nSector %d", arrayEmpleados[posicion].sector);
                 printf("\n#####################################################\n");

                if(utn_getChar("\nSeleccione que desea Modificar: \nA:Nombre \nB:Apellido \nC:Salario \nD:Sector \nE:salir","\nError ",'A','E',1,&opcion)==-1)
                {
                	printf("Letra Invalida");
                }
                else{


					switch(opcion)
					{
						case 'A':
							utn_getString("\nIngrese el nuevo nombre el empleado","\nError, nombre no valido",1,TEXT_SIZE,5,&arrayEmpleados[posicion].nombre);
							break;
						case 'B':
							utn_getString("\nIngrese el nuevo apelido el empleado ","\nError, apellido no valido",1,TEXT_SIZE,1,&arrayEmpleados[posicion].apellido);
							break;
						case 'C':
							utn_getFloat("\nIngrese el nuevo salario  ","\nError,salario incorrecto",1,sizeof(float),0,1,1,&arrayEmpleados[posicion].salario);
							break;
						case 'D':
							utn_getIntConSigno("\nIngrese el nuevo sector  ","\nError, sector no valido",1,sizeof(int),0,1,1,&arrayEmpleados[posicion].sector);
							break;
						default:
							printf("Saliste del menu");



					}
					retorno=0;
              }

        }

    }
    return retorno;
}

int empleado_baja(Empleado arrayEmpleados[], int sizeArray)
{
    int retorno=-1;
    int posicion;
    int id;
    if(arrayEmpleados!=NULL && sizeArray>0)
    {
        utn_getIntSinSigno("\nID a BORRAR: ","\nError",1,sizeof(int),1,sizeArray,1,&id);
        if(empleado_buscarID(arrayEmpleados,sizeArray,id,&posicion)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            arrayEmpleados[posicion].isEmpty=1;
            arrayEmpleados[posicion].id=0;
            strcpy(arrayEmpleados[posicion].nombre,"");
            strcpy(arrayEmpleados[posicion].apellido,"");
            arrayEmpleados[posicion].salario=0;
            arrayEmpleados[posicion].sector=0;



            retorno=0;
        }
    }
    return retorno;
}


int empleado_ordenar(Empleado arrayEmpleados[],int size)                              //cambiar estudiante
{

    int retorno=-1;
    int i, j;
    char auxNombre[TEXT_SIZE];
    char auxApellido[TEXT_SIZE];
    float auxSalario;
    int auxSector;
   int auxIsEmpty;
   int auxId;

    if(arrayEmpleados!=NULL && size>=0)
    {
        for (i = 1; i < size; i++)
        {
        	auxId=arrayEmpleados[i].id;
        	strcpy(auxNombre,arrayEmpleados[i].nombre);
        	strcpy(auxApellido,arrayEmpleados[i].apellido);
        	auxSalario=arrayEmpleados[i].salario;
  	        auxSector=arrayEmpleados[i].sector;
        	auxIsEmpty=arrayEmpleados[i].isEmpty;


            j = i - 1;
            while ((j >= 0) && strcmp(auxApellido,arrayEmpleados[j].apellido)<0)
            {
            	arrayEmpleados[j+1].id=arrayEmpleados[j].id;
            	strcpy(arrayEmpleados[j+1].nombre,arrayEmpleados[j].nombre);
            	strcpy(arrayEmpleados[j+1].apellido,arrayEmpleados[j].apellido);
            	arrayEmpleados[j+1].salario=arrayEmpleados[j].salario;
            	arrayEmpleados[j+1].sector=arrayEmpleados[j].sector;
            	arrayEmpleados[j+1].isEmpty=arrayEmpleados[j].isEmpty;

                j--;
            }
            if (strcmp(arrayEmpleados[j].apellido,arrayEmpleados[j+1].apellido)==0){



            	 j = i - 1;
            	 while ((j >= 0) && auxSector<arrayEmpleados[j].sector)
            	 {
            	  arrayEmpleados[j+1].id=arrayEmpleados[j].id;
            	  strcpy(arrayEmpleados[j+1].nombre,arrayEmpleados[j].nombre);
            	  strcpy(arrayEmpleados[j+1].apellido,arrayEmpleados[j].apellido);
            	  arrayEmpleados[j+1].salario=arrayEmpleados[j].salario;
            	  arrayEmpleados[j+1].sector=arrayEmpleados[j].sector;
            	  arrayEmpleados[j+1].isEmpty=arrayEmpleados[j].isEmpty;

            	   j--;
            	 }
            }

            arrayEmpleados[j+1].id=auxId;
                        	strcpy(arrayEmpleados[j+1].nombre,auxNombre);
                        	strcpy(arrayEmpleados[j+1].apellido,auxApellido);
                        	arrayEmpleados[j+1].salario=auxSalario;
                        	arrayEmpleados[j+1].sector=auxSector;
                        	arrayEmpleados[j+1].isEmpty=auxIsEmpty;

        }
        retorno=0;
    }
    return retorno;
  }


int empleado_listar(Empleado arrayEmpleados[], int size)                      //cambiar fantasma
{
    int retorno=-1;
    int i;
    if(arrayEmpleados!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(arrayEmpleados[i].isEmpty==1){continue;}

            else{
				printf("\nId %d", arrayEmpleados[i].id);
				printf("\nNombre %s", arrayEmpleados[i].nombre);
				printf("\nApellido %s", arrayEmpleados[i].apellido);
				printf("\nSalario %f", arrayEmpleados[i].salario);
				printf("\nSector %d", arrayEmpleados[i].sector);
            }

        }
        retorno=0;
    }
    return retorno;
}
float getSalrioTotal(Empleado arrayEmpleados[],int size)
{
    int i;
    float totalSalario = 0;
    for(i=0;i < size; i++)
    {
        if(arrayEmpleados[i].isEmpty==0)
        {
            totalSalario = totalSalario + arrayEmpleados[i].salario;

        }
    }
    return totalSalario;
}

float getSalarioPromedio(Empleado arrayEmpleados[],int size)
{
    int i;
    float totalSalario = 0;
    int empleadosActivos = 0;
    float promedio;

    for(i=0;i < size; i++)
    {
        if(arrayEmpleados[i].isEmpty==0)
        {
            totalSalario = totalSalario + arrayEmpleados[i].salario;
            empleadosActivos++;
        }
    }
    if(empleadosActivos == 0)
        return -1;
    promedio=(totalSalario / empleadosActivos);

    return promedio;
}

int empleadosqueSuperanSalarioPromedio(Empleado arrayEmpleados[],int size,int promedioSalario)
{
   int i;
   int contador=0;

   for(i=0;i<size;i++)
       {


        	   if(arrayEmpleados[i].salario>=promedioSalario  ){

        		   contador++;
        	   }


       }
return contador;
}

