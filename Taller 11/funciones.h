#define MAX_LIBROS 10
#define MAX_TITULOS 100
#define MAX_AUTORES 50
#define MAX_ID 20

typedef struct
{
    char ID[MAX_ID];
    char titulo[MAX_TITULOS];
    char autor[MAX_AUTORES];
    int añoPublicacion;
    int disponible;
} Datoslibro;

void menu();
void registrarLibros(Datoslibro coleccion[], int *totalLibros);
void listaLibros(Datoslibro coleccion[], int totalLibros);
void buscarLibro(Datoslibro coleccion[], int totalLibros);
void eliminarLibro(Datoslibro coleccion[], int *totalLibros, int indice);
void actualizarEstadoLibro(Datoslibro coleccion[], int totalLibros);
int idExiste(Datoslibro coleccion[], int totalLibros, const char *id);