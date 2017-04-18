#include <stdio.h>
#include <stdlib.h>
#define E 5

typedef struct
{
    char nombres[20];
    float sueldos;
    int legajos;
    int estado;

}eEmpleado;



void cargarEmpleado(eEmpleado empleado[], int);
void eliminarEmpleado(eEmpleado empleado[], int );
void modificarEmpleado(eEmpleado empleado[], int );
void inicializar (eEmpleado empleado[], int);

int main()

{

    int flagEncontro;
    system("color 4f");
    eEmpleado empleado[E], auxEmpleado;

    flagEncontro=0;

    int opcion;
    char seguir ='s', respuesta;

    inicializar(empleado, E);

    do
    {

        printf("1.Alta\n2.Baja\n3.Modificacion\n4.ordenar\n5. mostrar\n6.salir\n");
        printf("Elija una opcion: ");
        scanf("%d", &opcion);
        int i;
        int j;
        switch(opcion)
        {
        case 1:
            cargarEmpleado(empleado, E);//funcion
            break;
        case 2:
            eliminarEmpleado(empleado, E);//funcion
            break;
        case 3:

            modificarEmpleado(empleado,E);//funcion
            break;
        case 4:
            for(i=0; i<E-1; i++)
            {
                for(j=i+1; j<E; j++)
                {
                    if(strcmp(empleado[i].nombres, empleado[j].nombres)>0)//funcion que uso para comparar dos datos y los ordena

                    {
                        auxEmpleado=empleado[i];//copia los datos de nombre a una auxiliar cadena
                        empleado[i]= empleado[j];//copia los datos de i a j
                        empleado[j]=auxEmpleado;//pia los datos de la j a auxiliar

                    }
                    else
                    {
                        if(strcmp(empleado[i].nombres, empleado[j].nombres)==0)
                        {
                            if(empleado[i].legajos>empleado[j].legajos)
                            {
                                auxEmpleado=empleado[i];//copia los datos de nombre a una auxiliar cadena
                                empleado[i]= empleado[j];//copia los datos de i a j
                                empleado[j]=auxEmpleado;//pia los datos de la j a auxiliar

                            }
                        }
                    }
                }
            }





            break;

        case 5:

            printf("Legajo\tnombre\tsueldo\n");
            for(i=0; i<E; i++)
            {
                if(empleado[i].estado!=0)
                    printf("%d\t%s\t%.2f\n", empleado[i].legajos,empleado[i].nombres,empleado[i].sueldos);//muestra solos que que no estan en estado cero
            }

            break;
        case 6:
            seguir='n';//funcion salir del programa
            break;

        }




    }
    while(seguir=='s');







    return 0;
}

void cargarEmpleado(eEmpleado empleado[], int tam)
{
    int flagEncontro = 0, i;
    for(i=0; i<tam; i++)
    {
        if(empleado[i].estado==0)
        {
            printf("Ingrese legajo: ");
            scanf("%d", empleado[i].legajos);
            printf("Ingrese nombre: ");
            fflush(stdin);//hay que hacer fflush antes de pasar un gets porque es un char, si no, va a mostrar basura
            gets(empleado[i].nombres);
            printf("Ingrese sueldo: ");
            scanf("%f", empleado[i].sueldos);

            empleado[i].estado = 1;//si el numero de lagajo fue ingresado el estado tiene que pasar a uno, para que indique que esa fila ya tiene un dato
            flagEncontro = 1;//pasa a 1 porque cuando estaba en cero estaba vacio

            break;
        }
    }
    if(!flagEncontro)
    {
        printf("No hay espacio suficiente!!!");//significa que todos los estados flagencontro estan con unos, es decir, tienen informacion y no hay lugares vacios
    }
}

/*void eliminarEmpleado(int legajos[], char nombres[][20], float sueldos[], int estados[], int tam)
{
    int flagEncontro=0, i;//flag inicia en cero, significa que encontro lugares para eliminar
    int auxInt;//
    char respuesta;
    printf("Ingrese legajo: ");
    scanf("%d", &auxInt);
    for(i=0; i<tam; i++)
    {
        //inicializador
        if(estados[i]==1)//si estado esta en 1 es decir tiene informacion, entonces...
        {
            if(auxInt == legajos[i])
            {
                printf("%d\t%s\t%.2f\n", legajos[i],nombres[i],sueldos[i]);//va a mostrar el dato a eliminar

                printf("Esta seguro de eliminar el dato s/n: ");
                respuesta = getche();
                if(respuesta=='s')
                {
                    estados[i] = 0;//pasa los estados a cero, eso significa que los datos estan cargados, pero no se va a mostrar porque solo se muestra los estados en uno
                }
                else
                {
                    printf("Accion cancelada por el usuario!!!");//si responde que no en la opcion anterior el dato no se va a eliminar
                }

                flagEncontro=1;//
                break;//para deje de iterar. Si  no, va a seguir saliendo hasta cinco veces mas

            }

        }
    }
    if(flagEncontro==0)
    {
        printf("Dato inexistente");//si no tiene datos para eliminar
    }
}*/

void modificarEmpleado(int legajos[], char nombres[][20], float sueldos[], int estados[], int tam)
{
    int flagEncontro=0, i, auxInt;
    float auxFloat;
    char respuesta;
    printf("Ingrese legajo: ");//busca el nro de legajo a modificar
    scanf("%d", &auxInt);
    for(i=0; i<tam; i++)
    {
        if(estados[i]==1)
        {
            if(auxInt == legajos[i])
            {
                printf("%d\t%s\t%.2f\n", legajos[i],nombres[i],sueldos[i]);
                printf("Ingrese sueldo a modificar");
                scanf("%f", &auxFloat);
                printf("Esta seguro de realizar la modificacion s/n: ");
                respuesta = getche();
                if(respuesta=='s')
                {
                    sueldos[i] = auxFloat;
                }
                else
                {
                    printf("Accion cancelada por el usuario!!!");
                }

                flagEncontro=1;
                break;

            }

        }
    }
    if(flagEncontro==0)
    {
        printf("Dato inexistente");
    }
}
void inicializar (eEmpleado empleado, int E)
{

    int i;
    for(i=0; i<E; i++)
    {

        empleado[i].estado=0;
    }

}
