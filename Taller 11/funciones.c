#include <stdio.h>
#include <string.h>
#include "funciones.h"

void menu()
{
    printf("1. Agregar libro\n");
    printf("2. Listar libros\n");
    printf("3. Buscar libro\n");
    printf("4. Actualizar estado de libro\n");
    printf("5. Eliminar libro\n");
    printf("6. Salir\n");
}

int idExiste(Datoslibro coleccion[], int totalLibros, const char *id)
{
    for (int i = 0; i < totalLibros; i++)
    {
        if (strcmp(coleccion[i].ID, id) == 0)
        {
            return 1; 
        }
    }
    return 0; 
}
void registrarLibros(Datoslibro coleccion[], int *totalLibros)
{
    int n;
    printf("Cuantos libros deseas registrar? ");
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        printf("Entrada invalida. Debes ingresar un numero positivo.\n");
        while (getchar() != '\n');
        return;
    }

    if (*totalLibros + n > MAX_LIBROS)
    {
        printf("Solo puedes registrar hasta %d libros.\n", MAX_LIBROS);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        printf("\nLibro #%d\n", *totalLibros + 1);

        int idValido = 0;
        while (!idValido)
        {
            printf("ID: ");
            getchar();
            fgets(coleccion[*totalLibros].ID, sizeof(coleccion[*totalLibros].ID), stdin);
            strtok(coleccion[*totalLibros].ID, "\n");

            idValido = 1;
            for (int j = 0; j < *totalLibros; j++)
            {
                if (strcmp(coleccion[j].ID, coleccion[*totalLibros].ID) == 0)
                {
                    printf("El ID ya existe. Ingresa un ID unico.\n");
                    idValido = 0;
                    break;
                }
            }
        }

        printf("Titulo: ");
        fgets(coleccion[*totalLibros].titulo, sizeof(coleccion[*totalLibros].titulo), stdin);
        strtok(coleccion[*totalLibros].titulo, "\n");

        printf("Autor: ");
        fgets(coleccion[*totalLibros].autor, sizeof(coleccion[*totalLibros].autor), stdin);
        strtok(coleccion[*totalLibros].autor, "\n");

        printf("Ano de publicacion: ");
        if (scanf("%d", &coleccion[*totalLibros].añoPublicacion) != 1 || coleccion[*totalLibros].añoPublicacion <= 0)
        {
            printf("Entrada invalida. Debes ingresar un numero positivo.\n");
            while (getchar() != '\n');
            return;
        }
        getchar();

        coleccion[*totalLibros].disponible = 1;
        (*totalLibros)++;

        printf("Libro registrado exitosamente.\n");
    }
}

void listaLibros(Datoslibro coleccion[], int totalLibros)
{
    if (totalLibros <= 0)
    {
        printf("No hay libros registrados.\n");
        return;
    }

    printf("\n%-5s %-15s %-30s %-20s %-6s %-12s\n", "#", "ID", "Titulo", "Autor", "Ano", "Estado");
    printf("--------------------------------------------------------------------------------\n");

    for (int i = 0; i < totalLibros; i++)
    {
        printf("%-5d %-15s %-30s %-20s %-6d ", i + 1, coleccion[i].ID, coleccion[i].titulo, coleccion[i].autor, coleccion[i].añoPublicacion);
        if (coleccion[i].disponible)
        {
            printf("Disponible\n");
        }
        else
        {
            printf("Prestado\n");
        }
    }
}

void buscarLibro(Datoslibro coleccion[], int totalLibros)
{
    if (totalLibros <= 0)
    {
        printf("No hay libros registrados.\n");
        return;
    }

    int opcion;
    printf("Buscar por:\n1. Titulo\n2. ID\nSeleccione una opcion: ");
    if (scanf("%d", &opcion) != 1 || (opcion != 1 && opcion != 2))
    {
        printf("Opcion invalida.\n");
        while (getchar() != '\n')
            ;
        return;
    }
    getchar();

    int encontrado = 0;

    if (opcion == 1)
    {
        char tituloBuscar[MAX_TITULOS];
        printf("Ingrese el titulo del libro a buscar: ");
        fgets(tituloBuscar, MAX_TITULOS, stdin);
        tituloBuscar[strcspn(tituloBuscar, "\n")] = 0;

        for (int i = 0; i < totalLibros; i++)
        {
            if (strcmp(coleccion[i].titulo, tituloBuscar) == 0)
            {
                printf("Libro encontrado:\n");
                printf("ID: %s\n", coleccion[i].ID);
                printf("Titulo: %s\n", coleccion[i].titulo);
                printf("Autor: %s\n", coleccion[i].autor);
                printf("Ano de publicacion: %d\n", coleccion[i].añoPublicacion);
                printf("Estado: %s\n", coleccion[i].disponible ? "Disponible" : "Prestado");
                encontrado = 1;
                break;
            }
        }
    }
    else if (opcion == 2)
    {
        char idBuscar[MAX_ID];
        printf("Ingrese el ID del libro a buscar: ");
        getchar();
        fgets(idBuscar, MAX_ID, stdin);
        strtok(idBuscar, "\n");

        for (int i = 0; i < totalLibros; i++)
        {
            if (strcmp(coleccion[i].ID, idBuscar) == 0)
            {
                printf("Libro encontrado:\n");
                printf("ID: %s\n", coleccion[i].ID);
                printf("Titulo: %s\n", coleccion[i].titulo);
                printf("Autor: %s\n", coleccion[i].autor);
                printf("Ano de publicacion: %d\n", coleccion[i].añoPublicacion);
                printf("Estado: %s\n", coleccion[i].disponible ? "Disponible" : "Prestado");
                encontrado = 1;
                break;
            }
        }
    }

    if (!encontrado)
    {
        printf("Libro no encontrado.\n");
    }
}

void actualizarEstadoLibro(Datoslibro coleccion[], int totalLibros)
{
    if (totalLibros <= 0)
    {
        printf("No hay libros registrados.\n");
        return;
    }

    char idBuscar[MAX_ID];
    printf("Ingrese el ID del libro para actualizar su estado: ");
    getchar();
    fgets(idBuscar, MAX_ID, stdin);
    strtok(idBuscar, "\n");

    for (int i = 0; i < totalLibros; i++)
    {
        if (strcmp(coleccion[i].ID, idBuscar) == 0)
        {
            if (coleccion[i].disponible)
            {
                coleccion[i].disponible = 0;
                printf("Estado del libro actualizado a: Prestado\n");
            }
            else
            {
                coleccion[i].disponible = 1;
                printf("Estado del libro actualizado a: Disponible\n");
            }
            return;
        }
    }

    printf("Libro no encontrado.\n");
}

void eliminarLibro(Datoslibro coleccion[], int *totalLibros, int indice)
{
    if (*totalLibros <= 0)
    {
        printf("No hay libros registrados.\n");
        return;
    }

    if (indice < 0 || indice >= *totalLibros)
    {
        printf("Indice invalido.\n");
        return;
    }

    for (int i = indice; i < *totalLibros - 1; i++)
    {
        coleccion[i] = coleccion[i + 1];
    }

    (*totalLibros)--;

    printf("Libro eliminado exitosamente.\n");
}