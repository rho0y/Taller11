#define MAX_LIBROS 100
#define MAX_ID 20
#define MAX_TITULOS 100

typedef struct
{
    char nombre[50];
    char apellido[50];
    char nacionalidad[30];
    int edad;
} InfoAutor;

typedef struct
{
    int año;
    char editorial[50];
    char ciudad[30];
    char pais[30];
    int numeroEdicion;
} InfoPublicacion;

typedef struct
{
    int disponible;
    char fechaPrestamo[20];
    char fechaDevolucion[20];
    char nombrePrestatario[50];
    char contactoPrestatario[50];
} EstadoLibro;

typedef struct
{
    char genero[30];
    char categoria[30];
    char subcategoria[30];
    int clasificacionEdad;
} CategorizacionLibro;

typedef struct
{
    char ID[MAX_ID];
    char titulo[MAX_TITULOS];
    InfoAutor autor;
    InfoPublicacion publicacion;
    EstadoLibro estado;
    CategorizacionLibro categoria;
    int numeroPaginas;
    char idioma[20];
} DatosLibroAnidado;

void menu();
int idExiste(DatosLibroAnidado coleccion[], int totalLibros, const char *id);
void registrarLibros(DatosLibroAnidado coleccion[], int *totalLibros);
void listaLibros(DatosLibroAnidado coleccion[], int totalLibros);
void buscarLibro(DatosLibroAnidado coleccion[], int totalLibros);
void actualizarEstadoLibro(DatosLibroAnidado coleccion[], int totalLibros);
void eliminarLibro(DatosLibroAnidado coleccion[], int *totalLibros, int indice);
