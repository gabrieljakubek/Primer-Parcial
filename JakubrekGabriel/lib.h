#define USUARIO 100
#define PRODUCTOS 1000
#define TOTALVENTAS 100000
#define CHARUSU 18
#define CHARPASS 18
#define CHARNOMUSU 30
#define CHARAPEUSU 20
#define CHARNOMPRO 50

typedef struct
{
    char Usuario[CHARUSU];
    char Password[CHARPASS];
    char Nombre[CHARNOMUSU];
    char Apellido[CHARAPEUSU];
    int calificacion;
    int CantVentas;
    float calipromedio;
    int Estado;
} eUsuario;

typedef struct
{
    int idProducto;
    char Nombre[CHARNOMPRO];
    char Usuario [CHARNOMUSU];
    int Stock;
    int Precio;
    int cantVentas; //Cantidad de compras que se realizaron
    int cantVentProduc; // Cantidad de productos Vendidos
    int Estado;
} eProducto;

/**
 * Genera un menu segun la informacion que se le pasa y entrega la opcion elegida
 * \param char texto Son los datos que se desean mostrar
 * \return int Devuelve la opcion que se elige segun el texto
 */
int funMostrarMenu(char texto[]);

/**
 * Permite ingresar datos a la estructura Usuario
 * \param eUsuario Se le pasa la estructura con la que se va a trabajar
 * \param int La cantidad de estucturas disponibles
 * \return int Retorna 0 si se logro dar de alta, 1 si el usuario ya existe o -1 si no se pueden crear mas usuarios.
 */
int funAltaUsu(eUsuario[],int);


/** \brief
 * Permite dar de alta el producto
 * \param eProducto[] array de productos
 * \param int el tamaño del array producto
 * \param eUsuario[] array de usuarios
 * \param int el tamaño del array usuario
 * \return int Retorna 0 si se logro cargar el producto, 1 si no se encontro el usuario y contraseña o -1 si no hay mas espacio para cargar productos.
 *
 */
int funAltaProd(eProducto[],int, eUsuario[],int);

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * \param int La cantidad de estucturas disponibles.
 * @return el primer indice disponible.
 */
int funObtenerEspacioLibre(eUsuario[], int);

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * \param int La cantidad de estucturas disponibles.
 * @return el primer indice disponible.
 */
int funObtenerEspacioLibreProducto(eProducto lista[], int t);

/**
 * Chequea que lo ingresado en sean letras
 * \param char Las letras que se ingresaron
 * \return int Devuelve 0 si son solo letras o 1 si no lo son
 *
 */
int funChequeoLetras(char[]);

/** \brief
 *
 * \param eUsuario[] array de usuarios
 * \param int tamaño del array de usuarios
 * \param char[] cadena de caracteres de el campo usuario
 * \param char[] cadena de caracteres de el campo password
 * \return int retorna la posicion en donde se encuentra el usuario de ser correcto o -1 de no encontrarlo.
 *
 */
int funBuscarUsyCon(eUsuario[], int, char[], char[]);

/**
 * Chequea que el dato ingresado sea solo numeros positivos enteros
 * \param num[] char variable donde se guardan los datos
 * \return int 1 si no esta compuesto de numeros positivos o caracteres y 0 si son numeros positivos
 *
 */
int funChequeoNumero(char num[]);

/**
 * Comprueba la posicion de el Usuario ingresado o si ya fue ingresado
 * \param [] eUsuario array de usuarios
 * \param char[] cadena de caracteres ingrsada para usuario
 * \param int tamaño del array usuario
 * \return int retorna la posicion del usuari de encontrarlo o -1 de no lograrlo/encontrarlo
 *
 */
int funBuscarUsuario(eUsuario [], char[], int);


/**
 * Inicia los estados de Producto y Usuario en 0
 * \param [] eUsuario array de usuarios
 * \param int tamaño del array de usuarios
 * \param [] eProducto array de productos
 * \param int tamaño del array de productos
 * \return void
 *
 */
void funCambiarEstado(eUsuario [],int, eProducto [], int);

/**
 *  Crea un usuario
 * \param lista[] eUsuario array de usuarios
 * \param Index int pocicion en donde se encontro espacio libre
 * \param t int tamaño del array usuario
 * \return int retorna 0 si se encontro el usuario o 1 si se logro dar de alta
 *
 */
int funCrearUsu(eUsuario lista[],int Index, int t);

/**
 * Muestra la publicacion que se le pasa
 * \param lista eProducto array de productos
 * \return void
 *
 */
void funMotrarPublicacion(eProducto lista);

/**
 * Lista todas las publicaciones cargadas
 * \param lista[] eProducto array de productos
 * \param t int tamaño del array productos
 * \return void
 *
 */
void funMostrarTodasPublicaciones(eProducto lista[], int t);

/**
 *  Muestra el usuario que se le pasa
 * \param lista eUsuario array de usuarios
 * \return void
 *
 */
void funMostrarUsu(eUsuario lista);

/**
 *  Lista todos los usuarios cargados
 * \param lista[] eUsuario array de usuarios
 * \param t int tamaño del array usuario
 * \return void
 *
 */
void funMostrarTodosUsu(eUsuario lista[], int t);

/**
 *  Permite borrar un usuario y elimina todas sus publicaciones
 * \param listaUsu[] eUsuario array de usuarios
 * \param tU int tamaño del array de usuarios
 * \param listaProduc[] eProducto array de productos
 * \param tP int tamaño del array productos
 * \return int Retorna 1 si se logro borrar o -1 si se cancelo la accion
 *
 */
int funBorrarUsu(eUsuario listaUsu[], int tU, eProducto listaProduc[], int tP);

/**
 * Cuenta la cantidad de caracteres que se ingresados no superen un tam especifico
 * \param campo[] char var donde se almacena la cadena de caracteres
 * \param tamaño int tamaño fijo de la variable a chequear
 * \return int 1 si se ingresaron mas caracteres de los establecidos
 *
 */
int funContarCaracteres(char campo[], int tamano);

/**
 *  Pausa la pantalla y luego la limpia
 * \return void
 *
 */
void funBorrarPantalla();

/**
 * Permite modificar los datos del usuario
 * \param lista[] eUsuario array de usuarios
 * \param t int tamaño del array usuario
 * \return int retorna 1 si se modifico algun campo o 0 si no se realizo ningun cambio
 *
 */
int funModUsu(eUsuario lista[], int t);

/**
 *  Busca la publicacion ingresada
 * \param lista[] eProducto array de productos
 * \param ID int numero de ID de la publicacion a buscar
 * \param t int tamaño del array productos
 * \return int retorna la posicion de el producto de encontrarlo o -1 si no se encontro
 *
 */
int funBuscarPub(eProducto lista[], int ID, int t);

/**
 *  Borra una publicacion
 * \param listaUsu[] eUsuario array de usuarios
 * \param tUsu int tamaño del array usuarios
 * \param listaProd[] eProducto array de productos
 * \param tPro int tamaño del array productos
 * \return int retorna 1 si se borro la publicacion, 0 si se cancela la accion y -1 si no se encontro
 *
 */
int funBorrarProd(eUsuario listaUsu[], int tUsu, eProducto listaProd[], int tPro);

/**
 *  Permite modificar el precio y el stock de la publicacion
 * \param listaUsu[] eUsuario array de usuarios
 * \param tUsu int tamaño del array usuarios
 * \param listaProd[] eProducto array de productos
 * \param tPro int tamaño del array productos
 * \return int retorna 0 si no se encontro el producto, 1 si se modifico y -1 si no se modifica ningun campo
 *
 */
int funModProd(eUsuario listaUsu[], int tUsu, eProducto listaProd[], int tPro);

/** \brief
 *  Lista las publicaciones de un usuario especifico
 * \param listaUsu[] eUsuario array de usuarios
 * \param tUsu int tamaño del array usuario
 * \param listaPro[] eProducto array de productos
 * \param tPro int tamaño del arrya productos
 * \return int retorna -1 si no se encontro el usuario a buscar
 *
 */
int funListarPubUsu(eUsuario listaUsu[], int tUsu, eProducto listaPro[], int tPro);

/**
 *  Hardcodea 2 productos
 * \param lista[] eUsuario array de usuario
 * \param t int tamaño del array usuario
 * \return void
 *
 */
void funInicializarUsu(eUsuario lista[], int t);

/**
 *  Hardcodea 5 productos
 * \param lista[] eProducto array de producto
 * \param t int tamaño del array producto
 * \return void
 *
 */
void funInicializarProd(eProducto lista[], int t);
