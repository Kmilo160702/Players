#include <stdio.h>
#include <stdlib.h>
#define CAD 20
#define TAM 3

/*Elaborar un programa en lenguaje c, que pida al usuario los nombres, edades y estaturas
de 10 jugadores y muestre un menú que permita:
1. Listar los nombres de los jugadores
2. Listar las estaturas de los jugadores
3. Listar las edades de los jugadores*/
struct jugador
{
    char nombre[CAD];
    int edad;
    float altura;
};

typedef struct jugador TJugador;
int menu(void);
void listarNombres(TJugador jug[], const int tam);
void listarAlturas(TJugador jug[], const int tam);
void listarEdades(TJugador jug[], const int tam);
void entradaJugador(TJugador jug[], const int tam);
int main()
{
    int opcion;
    TJugador j[TAM];
    entradaJugador(j, TAM);
    opcion = menu();
    while (opcion != 4)
    {
        switch (opcion)
        {
        case 1:
            listarNombres(j, TAM);
            break;

        case 2:
            listarAlturas(j, TAM);
            break;
        case 3:
            listarEdades(j, TAM);
            break;
        }
        opcion = menu();
    }
    return 0;
}

int menu(void)
{
    int resp;

    printf("\n\t Menu de opciones\n\t");
    printf("1. listar nombres\n");
    printf("2. Listar alturas\n");
    printf("3. Listar edades\n");
    scanf("%d", &resp);
    return resp;
}

void listarNombres(TJugador jug[], const int tam)
{
    int i;
    printf("\nListado de nombres: \n");
    for (i = 0; i < tam; i++)
        printf("%s\n", jug[i].nombre);
    printf("\n");
}

void listarAlturas(TJugador jug[], const int tam)
{
    int i;
    printf("\nListado de alturas:\n");
    for (i = 0; i < tam; i++)
        printf("%.2f\n", jug[i].altura);
    printf("\n");
}

void listarEdades(TJugador jug[], const int tam)
{
    int i;
    printf("\nListado de edades:\n");
    for (i = 0; i < tam; i++)
        printf("%d\n", jug[i].edad);
    printf("\n");
}

void entradaJugador(TJugador jug[], const int tam)
{
    int i;

    for (i = 0; i < tam; i++)
    {
        printf("\tIngrese datos del jugador: %d\t\n", i + 1);
        printf("Nombre: ");
        fflush(stdin);
        gets(jug[i].nombre);
        printf("Edad: ");
        scanf("%d", &jug[i].edad);
        printf("Altura: ");
        scanf("%f", &jug[i].altura);
    }
}