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

int idExiste(struct DatosLibroAnidado coleccion[], int totalLibros, const char *id)
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

int validarCadenaVacia(const char *cadena)
{
    int i = 0;
    while (cadena[i] != '\0')
    {
        if (cadena[i] != ' ' && cadena[i] != '\t' && cadena[i] != '\n')
        {
            return 1;
        }
        i++;
    }
    return 0;
}

void registrarLibros(struct DatosLibroAnidado coleccion[], int *totalLibros)
{
    int n;
    printf("Cuantos libros deseas registrar? ");
    if (scanf("%d", &n) != 1)
    {
        printf("Entrada invalida. Debes ingresar un numero positivo.\n");
        while (getchar() != '\n')
            ;
        return;
    }
    else if (n <= 0)
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
        while (idValido == 0)
        {
            printf("ID del libro: ");
            getchar();
            fgets(coleccion[*totalLibros].ID, MAX_ID, stdin);
            int len = strlen(coleccion[*totalLibros].ID);
            if (len > 0 && coleccion[*totalLibros].ID[len - 1] == '\n')
            {
                coleccion[*totalLibros].ID[len - 1] = '\0';
            }

            if (validarCadenaVacia(coleccion[*totalLibros].ID) == 0)
            {
                printf("Error: El ID no puede estar vacio.\n");
            }
            else if (idExiste(coleccion, *totalLibros, coleccion[*totalLibros].ID) == 1)
            {
                printf("El ID ya existe. Ingresa un ID unico.\n");
            }
            else
            {
                idValido = 1;
            }
        }

        printf("\n--- INFORMACION BASICA ---\n");

        int tituloValido = 0;
        while (tituloValido == 0)
        {
            printf("Titulo: ");
            fgets(coleccion[*totalLibros].titulo, MAX_TITULOS, stdin);
            int len = strlen(coleccion[*totalLibros].titulo);
            if (len > 0 && coleccion[*totalLibros].titulo[len - 1] == '\n')
            {
                coleccion[*totalLibros].titulo[len - 1] = '\0';
            }

            if (validarCadenaVacia(coleccion[*totalLibros].titulo) == 0)
            {
                printf("Error: El titulo no puede estar vacio.\n");
            }
            else
            {
                tituloValido = 1;
            }
        }

        int idiomaValido = 0;
        while (idiomaValido == 0)
        {
            printf("Idioma: ");
            fgets(coleccion[*totalLibros].idioma, 20, stdin);
            int len = strlen(coleccion[*totalLibros].idioma);
            if (len > 0 && coleccion[*totalLibros].idioma[len - 1] == '\n')
            {
                coleccion[*totalLibros].idioma[len - 1] = '\0';
            }

            if (validarCadenaVacia(coleccion[*totalLibros].idioma) == 0)
            {
                printf("Error: El idioma no puede estar vacio.\n");
            }
            else
            {
                idiomaValido = 1;
            }
        }

        int generoValido = 0;
        while (generoValido == 0)
        {
            printf("Genero: ");
            fgets(coleccion[*totalLibros].genero, 30, stdin);
            int len = strlen(coleccion[*totalLibros].genero);
            if (len > 0 && coleccion[*totalLibros].genero[len - 1] == '\n')
            {
                coleccion[*totalLibros].genero[len - 1] = '\0';
            }

            if (validarCadenaVacia(coleccion[*totalLibros].genero) == 0)
            {
                printf("Error: El genero no puede estar vacio.\n");
            }
            else
            {
                generoValido = 1;
            }
        }

        printf("\n--- INFORMACION DEL AUTOR ---\n");
        int autorValido = 0;
        while (autorValido == 0)
        {
            printf("Nombre completo del autor: ");
            fgets(coleccion[*totalLibros].autor.nombreCompleto, 100, stdin);
            int len = strlen(coleccion[*totalLibros].autor.nombreCompleto);
            if (len > 0 && coleccion[*totalLibros].autor.nombreCompleto[len - 1] == '\n')
            {
                coleccion[*totalLibros].autor.nombreCompleto[len - 1] = '\0';
            }

            if (validarCadenaVacia(coleccion[*totalLibros].autor.nombreCompleto) == 0)
            {
                printf("Error: El nombre del autor no puede estar vacio.\n");
            }
            else
            {
                autorValido = 1;
            }
        }

        coleccion[*totalLibros].estado.disponible = 1;
        strcpy(coleccion[*totalLibros].estado.fechaPrestamo, "N/A");
        strcpy(coleccion[*totalLibros].estado.fechaDevolucion, "N/A");
        strcpy(coleccion[*totalLibros].estado.nombrePrestatario, "N/A");
        strcpy(coleccion[*totalLibros].estado.contactoPrestatario, "N/A");

        *totalLibros = *totalLibros + 1;
        printf("\nLibro registrado exitosamente!\n");
    }
}

void listaLibros(struct DatosLibroAnidado coleccion[], int totalLibros)
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
        printf("Idioma: %s | Genero: %s\n", coleccion[i].idioma, coleccion[i].genero);

        printf("Autor: %s\n", coleccion[i].autor.nombreCompleto);

        if (coleccion[i].estado.disponible == 1)
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

void buscarLibro(struct DatosLibroAnidado coleccion[], int totalLibros)
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
    printf("Seleccione una opcion: ");

    if (scanf("%d", &opcion) != 1)
    {
        printf("Opcion invalida.\n");
        while (getchar() != '\n')
            ;
        return;
    }
    else if (opcion < 1)
    {
        printf("Opcion invalida.\n");
        while (getchar() != '\n')
            ;
        return;
    }
    else if (opcion > 4)
    {
        printf("Opcion invalida.\n");
        while (getchar() != '\n')
            ;
        return;
    }
    getchar();

    int encontrado = 0;
    char busqueda[100];
    int busquedaValida = 0;

    if (opcion == 1)
    {
        while (busquedaValida == 0)
        {
            printf("Ingrese el titulo a buscar: ");
            fgets(busqueda, 100, stdin);
            int len = strlen(busqueda);
            if (len > 0 && busqueda[len - 1] == '\n')
            {
                busqueda[len - 1] = '\0';
            }

            if (validarCadenaVacia(busqueda) == 0)
            {
                printf("Error: La busqueda no puede estar vacia.\n");
            }
            else
            {
                busquedaValida = 1;
            }
        }

        for (int i = 0; i < totalLibros; i++)
        {
            if (strstr(coleccion[i].titulo, busqueda) != 0)
            {
                printf("\n--- LIBRO ENCONTRADO ---\n");
                printf("ID: %s | Titulo: %s\n", coleccion[i].ID, coleccion[i].titulo);
                printf("Autor: %s\n", coleccion[i].autor.nombreCompleto);
                if (coleccion[i].estado.disponible == 1)
                {
                    printf("Estado: Disponible\n");
                }
                else
                {
                    printf("Estado: Prestado\n");
                }
                encontrado = 1;
            }
        }
    }
    else if (opcion == 2)
    {
        while (busquedaValida == 0)
        {
            printf("Ingrese el ID a buscar: ");
            fgets(busqueda, 100, stdin);
            int len = strlen(busqueda);
            if (len > 0 && busqueda[len - 1] == '\n')
            {
                busqueda[len - 1] = '\0';
            }

            if (validarCadenaVacia(busqueda) == 0)
            {
                printf("Error: La busqueda no puede estar vacia.\n");
            }
            else
            {
                busquedaValida = 1;
            }
        }

        for (int i = 0; i < totalLibros; i++)
        {
            if (strcmp(coleccion[i].ID, busqueda) == 0)
            {
                printf("\n--- LIBRO ENCONTRADO ---\n");
                printf("ID: %s | Titulo: %s\n", coleccion[i].ID, coleccion[i].titulo);
                printf("Autor: %s\n", coleccion[i].autor.nombreCompleto);
                if (coleccion[i].estado.disponible == 1)
                {
                    printf("Estado: Disponible\n");
                }
                else
                {
                    printf("Estado: Prestado\n");
                }
                encontrado = 1;
                break;
            }
        }
    }
    else if (opcion == 3)
    {
        while (busquedaValida == 0)
        {
            printf("Ingrese el nombre del autor: ");
            fgets(busqueda, 100, stdin);
            int len = strlen(busqueda);
            if (len > 0 && busqueda[len - 1] == '\n')
            {
                busqueda[len - 1] = '\0';
            }

            if (validarCadenaVacia(busqueda) == 0)
            {
                printf("Error: La busqueda no puede estar vacia.\n");
            }
            else
            {
                busquedaValida = 1;
            }
        }

        for (int i = 0; i < totalLibros; i++)
        {
            if (strstr(coleccion[i].autor.nombreCompleto, busqueda) != 0)
            {
                printf("\n--- LIBRO ENCONTRADO ---\n");
                printf("ID: %s | Titulo: %s\n", coleccion[i].ID, coleccion[i].titulo);
                printf("Autor: %s\n", coleccion[i].autor.nombreCompleto);
                if (coleccion[i].estado.disponible == 1)
                {
                    printf("Estado: Disponible\n");
                }
                else
                {
                    printf("Estado: Prestado\n");
                }
                encontrado = 1;
            }
        }
    }
    else if (opcion == 4)
    {
        while (busquedaValida == 0)
        {
            printf("Ingrese el genero a buscar: ");
            fgets(busqueda, 100, stdin);
            int len = strlen(busqueda);
            if (len > 0 && busqueda[len - 1] == '\n')
            {
                busqueda[len - 1] = '\0';
            }

            if (validarCadenaVacia(busqueda) == 0)
            {
                printf("Error: La busqueda no puede estar vacia.\n");
            }
            else
            {
                busquedaValida = 1;
            }
        }

        for (int i = 0; i < totalLibros; i++)
        {
            if (strstr(coleccion[i].genero, busqueda) != 0)
            {
                printf("\n--- LIBRO ENCONTRADO ---\n");
                printf("ID: %s | Titulo: %s\n", coleccion[i].ID, coleccion[i].titulo);
                printf("Genero: %s\n", coleccion[i].genero);
                if (coleccion[i].estado.disponible == 1)
                {
                    printf("Estado: Disponible\n");
                }
                else
                {
                    printf("Estado: Prestado\n");
                }
                encontrado = 1;
            }
        }
    }

    if (encontrado == 0)
    {
        printf("No se encontraron libros con ese criterio de busqueda.\n");
    }
}

void actualizarEstadoLibro(struct DatosLibroAnidado coleccion[], int totalLibros)
{
    if (totalLibros <= 0)
    {
        printf("No hay libros registrados.\n");
        return;
    }

    char idBuscar[MAX_ID];
    int idValido = 0;
    while (idValido == 0)
    {
        printf("Ingrese el ID del libro para actualizar su estado: ");
        getchar();
        fgets(idBuscar, MAX_ID, stdin);
        int len = strlen(idBuscar);
        if (len > 0 && idBuscar[len - 1] == '\n')
        {
            idBuscar[len - 1] = '\0';
        }

        if (validarCadenaVacia(idBuscar) == 0)
        {
            printf("Error: El ID no puede estar vacio.\n");
        }
        else
        {
            idValido = 1;
        }
    }

    for (int i = 0; i < totalLibros; i++)
    {
        if (strcmp(coleccion[i].ID, idBuscar) == 0)
        {
            if (coleccion[i].estado.disponible == 1)
            {
                coleccion[i].estado.disponible = 0;

                printf("--- REGISTRO DE PRESTAMO ---\n");

                int nombreValido = 0;
                while (nombreValido == 0)
                {
                    printf("Nombre del prestatario: ");
                    fgets(coleccion[i].estado.nombrePrestatario, 50, stdin);
                    int len = strlen(coleccion[i].estado.nombrePrestatario);
                    if (len > 0 && coleccion[i].estado.nombrePrestatario[len - 1] == '\n')
                    {
                        coleccion[i].estado.nombrePrestatario[len - 1] = '\0';
                    }

                    if (validarCadenaVacia(coleccion[i].estado.nombrePrestatario) == 0)
                    {
                        printf("Error: El nombre del prestatario no puede estar vacio.\n");
                    }
                    else
                    {
                        nombreValido = 1;
                    }
                }

                int contactoValido = 0;
                while (contactoValido == 0)
                {
                    printf("Contacto del prestatario: ");
                    fgets(coleccion[i].estado.contactoPrestatario, 50, stdin);
                    int len = strlen(coleccion[i].estado.contactoPrestatario);
                    if (len > 0 && coleccion[i].estado.contactoPrestatario[len - 1] == '\n')
                    {
                        coleccion[i].estado.contactoPrestatario[len - 1] = '\0';
                    }

                    if (validarCadenaVacia(coleccion[i].estado.contactoPrestatario) == 0)
                    {
                        printf("Error: El contacto del prestatario no puede estar vacio.\n");
                    }
                    else
                    {
                        contactoValido = 1;
                    }
                }

                int fechaPrestamoValida = 0;
                while (fechaPrestamoValida == 0)
                {
                    printf("Fecha de prestamo DD/MM/AAAA: ");
                    fgets(coleccion[i].estado.fechaPrestamo, 20, stdin);
                    int len = strlen(coleccion[i].estado.fechaPrestamo);
                    if (len > 0 && coleccion[i].estado.fechaPrestamo[len - 1] == '\n')
                    {
                        coleccion[i].estado.fechaPrestamo[len - 1] = '\0';
                    }

                    if (validarCadenaVacia(coleccion[i].estado.fechaPrestamo) == 0)
                    {
                        printf("Error: La fecha de prestamo no puede estar vacia.\n");
                    }
                    else
                    {
                        fechaPrestamoValida = 1;
                    }
                }

                int fechaDevolucionValida = 0;
                while (fechaDevolucionValida == 0)
                {
                    printf("Fecha de devolucion estimada DD/MM/AAAA: ");
                    fgets(coleccion[i].estado.fechaDevolucion, 20, stdin);
                    int len = strlen(coleccion[i].estado.fechaDevolucion);
                    if (len > 0 && coleccion[i].estado.fechaDevolucion[len - 1] == '\n')
                    {
                        coleccion[i].estado.fechaDevolucion[len - 1] = '\0';
                    }

                    if (validarCadenaVacia(coleccion[i].estado.fechaDevolucion) == 0)
                    {
                        printf("Error: La fecha de devolucion no puede estar vacia.\n");
                    }
                    else
                    {
                        fechaDevolucionValida = 1;
                    }
                }

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

void eliminarLibro(struct DatosLibroAnidado coleccion[], int *totalLibros, int indice)
{
    if (*totalLibros <= 0)
    {
        printf("No hay libros registrados.\n");
        return;
    }

    if (indice < 0)
    {
        printf("Indice invalido.\n");
        return;
    }
    else if (indice >= *totalLibros)
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
