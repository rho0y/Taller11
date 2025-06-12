#define MAX_LIBROS 10
#define MAX_ID 20
#define MAX_TITULOS 100

struct InfoAutor
{
    char nombreCompleto[100];
};

struct EstadoLibro
{
    int disponible;
    char fechaPrestamo[20];
    char fechaDevolucion[20];
    char nombrePrestatario[50];
    char contactoPrestatario[50];
};

struct DatosLibroAnidado
{
    char ID[MAX_ID];
    char titulo[MAX_TITULOS];
    char idioma[20];
    char genero[30];
    struct InfoAutor autor;
    struct EstadoLibro estado;
};

void menu();
int idExiste(struct DatosLibroAnidado coleccion[], int totalLibros, const char *id);
void registrarLibros(struct DatosLibroAnidado coleccion[], int *totalLibros);
void listaLibros(struct DatosLibroAnidado coleccion[], int totalLibros);
void buscarLibro(struct DatosLibroAnidado coleccion[], int totalLibros);
void actualizarEstadoLibro(struct DatosLibroAnidado coleccion[], int totalLibros);
void eliminarLibro(struct DatosLibroAnidado coleccion[], int *totalLibros, int indice);
int validarCadenaVacia(const char *cadena);
