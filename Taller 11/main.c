#include <stdio.h>
#include <string.h>
#include "funciones.h"

int main()
{
    Datoslibro coleccion[MAX_LIBROS];
    int totalLibros = 0;
    int opcion;

    do
    {
        menu();
        printf("Selecciona una opcion: ");
        if (scanf("%d", &opcion) != 1)
        {
            printf("Entrada invalida. Por favor ingresa un numero.\n");
            while (getchar() != '\n');
            continue;
        }
        getchar();

        switch (opcion)
        {
        case 1:
            registrarLibros(coleccion, &totalLibros);
            break;
        case 2:
            listaLibros(coleccion, totalLibros);
            break;
        case 3:
            buscarLibro(coleccion, totalLibros);
            break;
        case 4:
            actualizarEstadoLibro(coleccion, totalLibros);
            break;
        case 5:
            if (totalLibros <= 0)
            {
                printf("No hay libros registrados para eliminar.\n");
                break;
            }

            listaLibros(coleccion, totalLibros);
            int indice;
            printf("Ingrese el indice del libro a eliminar (1 a %d): ", totalLibros);
            if (scanf("%d", &indice) != 1 || indice < 1 || indice > totalLibros)
            {
                printf("Indice invalido. Por favor ingresa un numero entre 1 y %d.\n", totalLibros);
                while (getchar() != '\n');
                break;
            }
            getchar();
            eliminarLibro(coleccion, &totalLibros, indice - 1);
            break;
        case 6:
            printf("Saliendo...\n");
            break;
        default:
            printf("Opcion invalida. Por favor selecciona una opcion del menu.\n");
        }

    } while (opcion != 6);

    return 0;
}