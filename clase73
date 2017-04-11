#include <stdio.h>
#include <stdlib.h>
#define A 5

void cargarEnteros(int[], int);
void mostrarEnteros(int[], int);

int main()
{
    char name[A][20]= {"maria","luis","maria", "jose", "ana"};
    int legajo[A];
    int auxInt;
    char auxString[20];
    int i, j;



    cargarEnteros(legajo, A);
    printf("\n");
    mostrarEnteros(legajo,A);




/*
    for(i=0; i<A-1; i++)
    {
        for(j=i+1; j<A; j++)
        {
            if(strcmp(name[i], name[j])>0)
            {
                strcpy(auxString, name[i]);
                strcpy(name[i], name[j]);
                strcpy(name[j], auxString);

                auxInt=legajo[i];
                legajo[i] = legajo[j];
                legajo[j] = auxInt;
            }
            else
            {
                if(strcmp(name[i], name[j])==0)
                {
                    if(legajo[i]>legajo[j])
                    {
                        auxInt=legajo[i];
                        legajo[i] = legajo[j];
                        legajo[j] = auxInt;
                    }
                }
            }
        }
    }



    for(i=0; i<A; i++)
    {
        printf("%d--%s\n",legajo[i], name[i]);
    }
*/
    return 0;
}

void mostrarEnteros(int numeros[], int tam)
{
    int i;
     for(i=0; i<tam; i++)
    {
        printf("%d\n",numeros[i]);
    }
}
void cargarEnteros(int numeros[], int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d", &numeros[i]);
    }
}
