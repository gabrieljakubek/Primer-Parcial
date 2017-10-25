#include <stdio.h>
#include <stdlib.h>
#include "lib.h"


int main()
{
    system("mode con: cols=140 lines=30");
    system("color 2");
    int opcion, auxInt;
    char auxChar = 's';
    eUsuario listaUsu[USUARIO];
    eProducto listaProducto[PRODUCTOS];
    funCambiarEstado(listaUsu,USUARIO,listaProducto,PRODUCTOS);
    funInicializarUsu(listaUsu, USUARIO);
    funInicializarProd(listaProducto, PRODUCTOS);
    do
    {
        opcion = funMostrarMenu("1-Alta de Usuario\
                             \n2-Modificar datos del Usuario\
                             \n3-Baja del Usuario\
                             \n4-Publicar Producto\
                             \n5-Modificar Producto\
                             \n6-Cancelar Publicacion\
                             \n7-Comprar Producto\
                             \n8-Listar Publicaciones de Usuario\
                             \n9-Listar Publicaciones\
                             \n10-Listar Usuarios\
                             \n11-Salir");
        switch(opcion)
        {
        case 1:
            auxInt = funAltaUsu(listaUsu,USUARIO);
            if(auxInt == 0)
            {
                printf("Se ha dado de alta\n");
            }
            else if (auxInt == -1)
            {
                printf("No hay mas espacio para ingresar personas.\n");
            }
            else
            {
                printf("El Usuario ingresado ya figura en la lista\n");
            }
            funBorrarPantalla();
            break;

        case 2:
            auxInt = funModUsu(listaUsu,USUARIO);
            if(auxInt == 0)
            {
                printf("El usuario no se modifico!\n");
            }
            else if (auxInt == 1)
            {
                printf("El Usuario o Contrasenia no son correctos\n");
            }
            else
            {
                printf("El usuario se modifico!\n");
            }
            funBorrarPantalla();
            break;

        case 3:
            auxInt = funBorrarUsu(listaUsu,USUARIO,listaProducto,PRODUCTOS);
            if(auxInt == 0)
            {
                printf("\nEl usuario no se dio de baja!\n");
            }
            else if (auxInt == 1)
            {
                printf("\nEl usuario se dio de baja!\n");
            }
            else
            {
                printf("El Usuario o Contrasenia no son correctos\n");
            }
            funBorrarPantalla();
            break;

        case 4:
            auxInt = funAltaProd(listaProducto,PRODUCTOS,listaUsu,USUARIO);
            if(auxInt == 0)
            {
                printf("Se ha dado de alta el Producto\n");
            }
            else if (auxInt == -1)
            {
                printf("El Usuario o Contrasenia no son correctos\n");
            }
            else
            {
                printf("No hay mas espacio para ingresar productos.\n");
            }
            funBorrarPantalla();
            break;

        case 5:
            auxInt = funModProd(listaUsu,USUARIO,listaProducto,PRODUCTOS);
            if(auxInt == 0)
            {
                printf("La publicacion no se modifico!\n");
            }
            else if (auxInt == 1)
            {
                printf("La publicacion se modifico!\n");
            }
            else
            {
                printf("El Usuario o Contrasenia no son correctos\n");
            }
            funBorrarPantalla();
            break;

        case 6:
            auxInt = funBorrarProd(listaUsu,USUARIO,listaProducto,PRODUCTOS);
            if(auxInt == 0)
            {
                printf("La publicacion no se cancelo!\n");
            }
            else if (auxInt == 1)
            {
                printf("La publicacion fue cancelada!\n");
            }
            else
            {
                printf("El Usuario o Contrasenia no son correctos\n");
            }
            funBorrarPantalla();
            break;

        case 7:
            auxInt = funCompra(listaUsu,USUARIO,listaProducto,PRODUCTOS);
            if(auxInt == 1)
            {
                printf("La compra se realizo exitosamente!!!\n");
            }
            else if (auxInt == 2)
            {
                printf("La publicacion no tiene stock!!!\n");
            }
            else
            {
                printf("El Usuario o Contrasenia no son correctos\n");
            }
            funBorrarPantalla();
            break;

        case 8:
            auxInt = funListarPubUsu(listaUsu,USUARIO,listaProducto,PRODUCTOS);
            if(auxInt == -1)
            {
                printf("El Usuario ingresado no existe!!!\n");
            }
            system("cls");
            break;

        case 9:
            system("cls");
            funMostrarTodasPublicaciones(listaProducto,PRODUCTOS);
            funBorrarPantalla();
            break;

        case 10:
            system("cls");
            funMostrarTodosUsu(listaUsu,USUARIO);
            funBorrarPantalla();
            break;

        case 11:
            auxChar = 'n';
            break;
        default:
            printf("Opcion inexistente!!!");
            funBorrarPantalla();
            break;
        }
    }
    while(auxChar != 'n');
    return 0;
}
