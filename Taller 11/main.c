#include <stdio.h>
#include <string.h>
#include "funciones.h"

int main()
{
    struct DatosLibroAnidado coleccion[MAX_LIBROS];
    int totalLibros = 0;
    int opcion;

    do
    {
        menu();
        printf("Selecciona una opcion: ");
        if (scanf("%d", &opcion) != 1)
        {
            printf("Entrada invalida. Por favor ingresa un numero.\n");
            while (getchar() != '\n')
                ;
            continue;
        }
        getchar();

        if (opcion == 1)
        {
            registrarLibros(coleccion, &totalLibros);
        }
        else if (opcion == 2)
        {
            listaLibros(coleccion, totalLibros);
        }
        else if (opcion == 3)
        {
            buscarLibro(coleccion, totalLibros);
        }
        else if (opcion == 4)
        {
            actualizarEstadoLibro(coleccion, totalLibros);
        }
        else if (opcion == 5)
        {
            if (totalLibros <= 0)
            {
                printf("No hay libros registrados para eliminar.\n");
            }
            else
            {
                listaLibros(coleccion, totalLibros);
                int indice;
                printf("Ingrese el indice del libro a eliminar entre 1 y %d: ", totalLibros);
                if (scanf("%d", &indice) != 1)
                {
                    printf("Indice invalido. Por favor ingresa un numero entre 1 y %d.\n", totalLibros);
                    while (getchar() != '\n')
                        ;
                }
                else if (indice < 1)
                {
                    printf("Indice invalido. Por favor ingresa un numero entre 1 y %d.\n", totalLibros);
                    while (getchar() != '\n')
                        ;
                }
                else if (indice > totalLibros)
                {
                    printf("Indice invalido. Por favor ingresa un numero entre 1 y %d.\n", totalLibros);
                    while (getchar() != '\n')
                        ;
                }
                else
                {
                    getchar();
                    eliminarLibro(coleccion, &totalLibros, indice - 1);
                }
            }
        }
        else if (opcion == 6)
        {
            printf("Gracias por usar el sistema de biblioteca. Hasta luego!\n");
        }
        else
        {
            printf("Opcion invalida. Por favor selecciona una opcion del menu.\n");
        }

    } while (opcion != 6);

    return 0;
}
