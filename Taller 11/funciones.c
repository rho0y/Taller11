#include <stdio.h>
#include <string.h>
#include "funciones.h"

void menu()
{
    printf("\n=== SISTEMA DE BIBLIOTECA ===\n");
    printf("1. Agregar libro\n");
    printf("2. Listar libros\n");
    printf("3. Buscar libro\n");
    printf("4. Actualizar estado de libro\n");
    printf("5. Eliminar libro\n");
    printf("6. Salir\n");
}

int idExiste(DatosLibroAnidado coleccion[], int totalLibros, const char *id)
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

void registrarLibros(DatosLibroAnidado coleccion[], int *totalLibros)
{
    int n;
    printf("Cuantos libros deseas registrar? ");
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        printf("Entrada invalida. Debes ingresar un numero positivo.\n");
        while (getchar() != '\n')
            ;
        return;
    }

    if (*totalLibros + n > MAX_LIBROS)
    {
        printf("Solo puedes registrar hasta %d libros.\n", MAX_LIBROS);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        printf("\n=== REGISTRANDO LIBRO #%d ===\n", *totalLibros + 1);

        int idValido = 0;
        while (!idValido)
        {
            printf("ID del libro: ");
            getchar();
            fgets(coleccion[*totalLibros].ID, sizeof(coleccion[*totalLibros].ID), stdin);
            strtok(coleccion[*totalLibros].ID, "\n");

            if (!idExiste(coleccion, *totalLibros, coleccion[*totalLibros].ID))
            {
                idValido = 1;
            }
            else
            {
                printf("El ID ya existe. Ingresa un ID unico.\n");
            }
        }

        printf("\n--- INFORMACION BASICA ---\n");
        printf("Titulo: ");
        fgets(coleccion[*totalLibros].titulo, sizeof(coleccion[*totalLibros].titulo), stdin);
        strtok(coleccion[*totalLibros].titulo, "\n");

        printf("Numero de paginas: ");
        scanf("%d", &coleccion[*totalLibros].numeroPaginas);
        getchar();

        printf("Idioma: ");
        fgets(coleccion[*totalLibros].idioma, sizeof(coleccion[*totalLibros].idioma), stdin);
        strtok(coleccion[*totalLibros].idioma, "\n");

        printf("\n--- INFORMACION DEL AUTOR ---\n");
        printf("Nombre del autor: ");
        fgets(coleccion[*totalLibros].autor.nombre, sizeof(coleccion[*totalLibros].autor.nombre), stdin);
        strtok(coleccion[*totalLibros].autor.nombre, "\n");

        printf("Apellido del autor: ");
        fgets(coleccion[*totalLibros].autor.apellido, sizeof(coleccion[*totalLibros].autor.apellido), stdin);
        strtok(coleccion[*totalLibros].autor.apellido, "\n");

        printf("Nacionalidad del autor: ");
        fgets(coleccion[*totalLibros].autor.nacionalidad, sizeof(coleccion[*totalLibros].autor.nacionalidad), stdin);
        strtok(coleccion[*totalLibros].autor.nacionalidad, "\n");

        printf("Edad del autor: ");
        scanf("%d", &coleccion[*totalLibros].autor.edad);
        getchar();

        printf("\n--- INFORMACION DE PUBLICACION ---\n");
        printf("Ano de publicacion: ");
        scanf("%d", &coleccion[*totalLibros].publicacion.año);
        getchar();

        printf("Editorial: ");
        fgets(coleccion[*totalLibros].publicacion.editorial, sizeof(coleccion[*totalLibros].publicacion.editorial), stdin);
        strtok(coleccion[*totalLibros].publicacion.editorial, "\n");

        printf("Ciudad de publicacion: ");
        fgets(coleccion[*totalLibros].publicacion.ciudad, sizeof(coleccion[*totalLibros].publicacion.ciudad), stdin);
        strtok(coleccion[*totalLibros].publicacion.ciudad, "\n");

        printf("Pais de publicacion: ");
        fgets(coleccion[*totalLibros].publicacion.pais, sizeof(coleccion[*totalLibros].publicacion.pais), stdin);
        strtok(coleccion[*totalLibros].publicacion.pais, "\n");

        printf("Numero de edicion: ");
        scanf("%d", &coleccion[*totalLibros].publicacion.numeroEdicion);
        getchar();

        printf("\n--- CATEGORIZACION ---\n");
        printf("Genero: ");
        fgets(coleccion[*totalLibros].categoria.genero, sizeof(coleccion[*totalLibros].categoria.genero), stdin);
        strtok(coleccion[*totalLibros].categoria.genero, "\n");

        printf("Categoria: ");
        fgets(coleccion[*totalLibros].categoria.categoria, sizeof(coleccion[*totalLibros].categoria.categoria), stdin);
        strtok(coleccion[*totalLibros].categoria.categoria, "\n");

        printf("Subcategoria: ");
        fgets(coleccion[*totalLibros].categoria.subcategoria, sizeof(coleccion[*totalLibros].categoria.subcategoria), stdin);
        strtok(coleccion[*totalLibros].categoria.subcategoria, "\n");

        printf("Clasificacion por edad: 0=infantil, 1=juvenil, 2=adulto: ");
        scanf("%d", &coleccion[*totalLibros].categoria.clasificacionEdad);
        getchar();

        coleccion[*totalLibros].estado.disponible = 1;
        strcpy(coleccion[*totalLibros].estado.fechaPrestamo, "N/A");
        strcpy(coleccion[*totalLibros].estado.fechaDevolucion, "N/A");
        strcpy(coleccion[*totalLibros].estado.nombrePrestatario, "N/A");
        strcpy(coleccion[*totalLibros].estado.contactoPrestatario, "N/A");

        *totalLibros = *totalLibros + 1;
        printf("\nLibro registrado exitosamente!\n");
    }
}

void listaLibros(DatosLibroAnidado coleccion[], int totalLibros)
{
    if (totalLibros <= 0)
    {
        printf("No hay libros registrados.\n");
        return;
    }

    printf("\n=== LISTA COMPLETA DE LIBROS ===\n");

    for (int i = 0; i < totalLibros; i++)
    {
        printf("\n--- LIBRO #%d ---\n", i + 1);
        printf("ID: %s\n", coleccion[i].ID);
        printf("Titulo: %s\n", coleccion[i].titulo);
        printf("Paginas: %d | Idioma: %s\n", coleccion[i].numeroPaginas, coleccion[i].idioma);

        printf("Autor: %s %s de %s, %d anos\n",
               coleccion[i].autor.nombre,
               coleccion[i].autor.apellido,
               coleccion[i].autor.nacionalidad,
               coleccion[i].autor.edad);

        printf("Publicacion: %s en %d - %s, %s - Edicion #%d\n",
               coleccion[i].publicacion.editorial,
               coleccion[i].publicacion.año,
               coleccion[i].publicacion.ciudad,
               coleccion[i].publicacion.pais,
               coleccion[i].publicacion.numeroEdicion);

        const char *clasificaciones[] = {"Infantil", "Juvenil", "Adulto"};
        printf("Categoria: %s > %s > %s - %s\n",
               coleccion[i].categoria.genero,
               coleccion[i].categoria.categoria,
               coleccion[i].categoria.subcategoria,
               clasificaciones[coleccion[i].categoria.clasificacionEdad]);

        if (coleccion[i].estado.disponible)
        {
            printf("Estado: DISPONIBLE\n");
        }
        else
        {
            printf("Estado: PRESTADO\n");
            printf("  Prestatario: %s\n", coleccion[i].estado.nombrePrestatario);
            printf("  Contacto: %s\n", coleccion[i].estado.contactoPrestatario);
            printf("  Fecha prestamo: %s\n", coleccion[i].estado.fechaPrestamo);
            printf("  Fecha devolucion: %s\n", coleccion[i].estado.fechaDevolucion);
        }

        printf("--------------------------------------------\n");
    }
}

void buscarLibro(DatosLibroAnidado coleccion[], int totalLibros)
{
    if (totalLibros <= 0)
    {
        printf("No hay libros registrados.\n");
        return;
    }

    int opcion;
    printf("\n=== BUSQUEDA AVANZADA ===\n");
    printf("1. Buscar por titulo\n");
    printf("2. Buscar por ID\n");
    printf("3. Buscar por autor\n");
    printf("4. Buscar por genero\n");
    printf("5. Buscar por editorial\n");
    printf("Seleccione una opcion: ");

    if (scanf("%d", &opcion) != 1 || opcion < 1 || opcion > 5)
    {
        printf("Opcion invalida.\n");
        while (getchar() != '\n')
            ;
        return;
    }
    getchar();

    int encontrado = 0;
    char busqueda[100];

    switch (opcion)
    {
    case 1:
        printf("Ingrese el titulo a buscar: ");
        fgets(busqueda, sizeof(busqueda), stdin);
        strtok(busqueda, "\n");

        for (int i = 0; i < totalLibros; i++)
        {
            if (strstr(coleccion[i].titulo, busqueda) != 0)
            {
                printf("\n--- LIBRO ENCONTRADO ---\n");
                printf("ID: %s | Titulo: %s\n", coleccion[i].ID, coleccion[i].titulo);
                printf("Autor: %s %s\n", coleccion[i].autor.nombre, coleccion[i].autor.apellido);
                printf("Estado: %s\n", coleccion[i].estado.disponible ? "Disponible" : "Prestado");
                encontrado = 1;
            }
        }
        break;

    case 2:
        printf("Ingrese el ID a buscar: ");
        fgets(busqueda, sizeof(busqueda), stdin);
        strtok(busqueda, "\n");

        for (int i = 0; i < totalLibros; i++)
        {
            if (strcmp(coleccion[i].ID, busqueda) == 0)
            {
                printf("\n--- LIBRO ENCONTRADO ---\n");
                printf("ID: %s | Titulo: %s\n", coleccion[i].ID, coleccion[i].titulo);
                printf("Autor: %s %s\n", coleccion[i].autor.nombre, coleccion[i].autor.apellido);
                printf("Estado: %s\n", coleccion[i].estado.disponible ? "Disponible" : "Prestado");
                encontrado = 1;
                break;
            }
        }
        break;

    case 3:
        printf("Ingrese el nombre o apellido del autor: ");
        fgets(busqueda, sizeof(busqueda), stdin);
        strtok(busqueda, "\n");

        for (int i = 0; i < totalLibros; i++)
        {
            if (strstr(coleccion[i].autor.nombre, busqueda) != 0 ||
                strstr(coleccion[i].autor.apellido, busqueda) != 0)
            {
                printf("\n--- LIBRO ENCONTRADO ---\n");
                printf("ID: %s | Titulo: %s\n", coleccion[i].ID, coleccion[i].titulo);
                printf("Autor: %s %s\n", coleccion[i].autor.nombre, coleccion[i].autor.apellido);
                printf("Estado: %s\n", coleccion[i].estado.disponible ? "Disponible" : "Prestado");
                encontrado = 1;
            }
        }
        break;

    case 4:
        printf("Ingrese el genero a buscar: ");
        fgets(busqueda, sizeof(busqueda), stdin);
        strtok(busqueda, "\n");

        for (int i = 0; i < totalLibros; i++)
        {
            if (strstr(coleccion[i].categoria.genero, busqueda) != 0)
            {
                printf("\n--- LIBRO ENCONTRADO ---\n");
                printf("ID: %s | Titulo: %s\n", coleccion[i].ID, coleccion[i].titulo);
                printf("Genero: %s\n", coleccion[i].categoria.genero);
                printf("Estado: %s\n", coleccion[i].estado.disponible ? "Disponible" : "Prestado");
                encontrado = 1;
            }
        }
        break;

    case 5:
        printf("Ingrese la editorial a buscar: ");
        fgets(busqueda, sizeof(busqueda), stdin);
        strtok(busqueda, "\n");

        for (int i = 0; i < totalLibros; i++)
        {
            if (strstr(coleccion[i].publicacion.editorial, busqueda) != 0)
            {
                printf("\n--- LIBRO ENCONTRADO ---\n");
                printf("ID: %s | Titulo: %s\n", coleccion[i].ID, coleccion[i].titulo);
                printf("Editorial: %s en %d\n", coleccion[i].publicacion.editorial, coleccion[i].publicacion.año);
                printf("Estado: %s\n", coleccion[i].estado.disponible ? "Disponible" : "Prestado");
                encontrado = 1;
            }
        }
        break;
    }

    if (!encontrado)
    {
        printf("No se encontraron libros con ese criterio de busqueda.\n");
    }
}

void actualizarEstadoLibro(DatosLibroAnidado coleccion[], int totalLibros)
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
            if (coleccion[i].estado.disponible)
            {
                coleccion[i].estado.disponible = 0;

                printf("--- REGISTRO DE PRESTAMO ---\n");
                printf("Nombre del prestatario: ");
                fgets(coleccion[i].estado.nombrePrestatario, sizeof(coleccion[i].estado.nombrePrestatario), stdin);
                strtok(coleccion[i].estado.nombrePrestatario, "\n");

                printf("Contacto del prestatario: ");
                fgets(coleccion[i].estado.contactoPrestatario, sizeof(coleccion[i].estado.contactoPrestatario), stdin);
                strtok(coleccion[i].estado.contactoPrestatario, "\n");

                printf("Fecha de prestamo DD/MM/AAAA: ");
                fgets(coleccion[i].estado.fechaPrestamo, sizeof(coleccion[i].estado.fechaPrestamo), stdin);
                strtok(coleccion[i].estado.fechaPrestamo, "\n");

                printf("Fecha de devolucion estimada DD/MM/AAAA: ");
                fgets(coleccion[i].estado.fechaDevolucion, sizeof(coleccion[i].estado.fechaDevolucion), stdin);
                strtok(coleccion[i].estado.fechaDevolucion, "\n");

                printf("Estado del libro actualizado a: PRESTADO\n");
            }
            else
            {
                coleccion[i].estado.disponible = 1;
                strcpy(coleccion[i].estado.fechaPrestamo, "N/A");
                strcpy(coleccion[i].estado.fechaDevolucion, "N/A");
                strcpy(coleccion[i].estado.nombrePrestatario, "N/A");
                strcpy(coleccion[i].estado.contactoPrestatario, "N/A");
                printf("Estado del libro actualizado a: DISPONIBLE\n");
            }
            return;
        }
    }

    printf("Libro no encontrado.\n");
}

void eliminarLibro(DatosLibroAnidado coleccion[], int *totalLibros, int indice)
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

    printf("Eliminando libro: %s - %s\n", coleccion[indice].ID, coleccion[indice].titulo);

    for (int i = indice; i < *totalLibros - 1; i++)
    {
        coleccion[i] = coleccion[i + 1];
    }

    *totalLibros = *totalLibros - 1;
    printf("Libro eliminado exitosamente.\n");
}
