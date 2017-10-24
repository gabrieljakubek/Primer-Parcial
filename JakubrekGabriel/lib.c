#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "lib.h"

void funCambiarEstado(eUsuario listaUsu[],int tU, eProducto listaPro[], int tP)
{
    int i;
    for(i=0; i<tU; i++)
    {
        listaUsu[i].Estado = 0;
    }
    for(i=0; i<tP; i++)
    {
        listaPro[i].Estado = 0;
    }
}

int funMostrarMenu(char texto[])
{
    int opcion;
    printf("%s", texto);
    scanf("%d", &opcion);

    return opcion;
}

int funObtenerEspacioLibre(eUsuario lista[], int t)
{
    int i;
    int index;
    for (i=0; i<t; i++)
    {
        if (lista[i].Estado == 0)
        {
            index = i;
            break;
        }
        else
        {
            index = -1;
        }
    }
    return index;
}

int funObtenerEspacioLibreProducto(eProducto lista[], int t)
{
    int i;
    int index;
    for (i=0; i<t; i++)
    {
        if (lista[i].Estado == 0)
        {
            index = i;
            break;
        }
        else
        {
            index = -1;
        }
    }
    return index;
}

int funAltaUsu(eUsuario lista[],int t)
{
    int index, auxInt;
    int flag = 0;
    index = funObtenerEspacioLibre(lista,t);

    if(index!=-1)
    {
        auxInt = funCrearUsu(lista,index,t);
        if (auxInt)
        {
            printf("Ingrese el Nombre: ");
            fflush(stdin);
            gets(lista[index].Nombre);
            auxInt = funChequeoLetras(lista[index].Nombre);
            while (auxInt != 0)
            {
                printf("Reingrese el Nombre: ");
                fflush(stdin);
                gets(lista[index].Nombre);
                auxInt = funChequeoLetras(lista[index].Nombre);
            }
            printf("Ingrese el Apellido: ");
            fflush(stdin);
            gets(lista[index].Apellido);
            auxInt = funChequeoLetras(lista[index].Apellido);
            while (auxInt != 0)
            {
                printf("Reingrese el Apellido: ");
                fflush(stdin);
                gets(lista[index].Apellido);
                auxInt = funChequeoLetras(lista[index].Apellido);
            }

            lista[index].calificacion = 0;
            lista[index].CantVentas = 0;

            lista[index].Estado = 1;
        }
        else
        {
            flag = 1;
        }
    }
    else
    {
        flag = -1;
    }
    return flag;
}

int funAltaProd(eProducto lista[],int tP, eUsuario listaUsu[], int tU)
{
    int index, auxInt;
    int flag, flag2 = 0;
    char auxChar [50], auxChar1[50], auxChar2[50];
    index = funObtenerEspacioLibreProducto(lista,tP);
    if (index != -1)
    {
        printf("Igrese el Usuario: ");
        fflush(stdin);
        gets(auxChar1);
        printf("Igrese La Contraseña: ");
        fflush(stdin);
        gets(auxChar2);
        flag2 = funBuscarUsyCon(listaUsu, tU,auxChar1,auxChar2);
        if (flag2 != -1)
        {
            flag = 0;
            strcpy(lista[index].Usuario, auxChar1);
            lista[index].idProducto = index + 1;
            printf("Ingrese el Producto: ");
            fflush(stdin);
            gets(lista[index].Nombre);
            printf("Ingrese el Stock: ");
            fflush(stdin);
            gets(auxChar);
            auxInt = funChequeoNumero(auxChar);
            while (auxInt != 0)
            {
                printf("Reingrese el Stock: ");
                fflush(stdin);
                gets(auxChar);
                auxInt = funChequeoNumero(auxChar);
            }
            auxInt = atoi(auxChar);
            lista[index].Stock=auxInt;

            printf("Ingrese el Precio (solo enteros): ");
            fflush(stdin);
            gets(auxChar);
            auxInt = funChequeoNumero(auxChar);
            while (auxInt != 0)
            {
                printf("Reingrese el Precio con Enteros: ");
                fflush(stdin);
                gets(auxChar);
                auxInt = funChequeoNumero(auxChar);
            }
            auxInt = atoi(auxChar);
            lista[index].Precio=auxInt;

            lista[index].cantVentas = 0;
            lista[index].cantVentProduc = 0;

            lista[index].Estado = 1;
        }
        else if (index == -1)
        {
            flag = 1;
        }
    }
    else
    {
        flag = -1;
    }
    return flag;
}

int funChequeoLetras(char letras[])
{
    int i = 0, cont;
    int flag = 0;
    cont = strlen(letras);
    while (i<cont && flag == 0)
    {
        if (isalpha(letras[i]) != 0)
        {
            i++;
        }
        else
        {
            flag = 1;
        }

    }
    return flag;
}

int funBuscarUsuario(eUsuario lista[], char usua[], int t)
{
    int i;
    int index;
    for (i=0; i<t; i++)
    {
        if (strcmp(lista[i].Usuario,usua)==0)
        {
            index = i;
        }
        else
        {
            index = -1;
        }

    }
    return index;
}

int funBuscarPub(eProducto lista[], int ID, int t)
{
    int i;
    int index;
    for (i=0; i<t; i++)
    {
        if (lista[i].idProducto == ID)
        {
            index = i;
        }
        else
        {
            index = -1;
        }

    }
    return index;
}

int funChequeoNumero(char num[])
{
    int i = 0, cont;
    int flag = 0;
    cont = strlen(num);
    while (i<cont && flag == 0)
    {
        if(isdigit(num[i])!=0)
        {
            i++;
        }
        else
        {
            flag = 1;
        }
    }
    return flag;
}

int funBuscarUsyCon(eUsuario lista[], int T, char usu[], char contr[])
{

    int i;
    int flag = -1;
    for (i=0; i<T; i++)
    {
        if (strcmp(lista[i].Usuario,usu) == 0 && strcmp(lista[i].Password, contr) == 0 && (lista[i].Estado == 0))
        {
            flag = i;
            break;
        }
    }
    return flag;
}

void funMostrarPublicacion(eProducto lista)
{
    printf("%d\t%50s\t%d\t%d\t\%18s\n",lista.idProducto,lista.Nombre,lista.Stock,lista.Precio,lista.Usuario);
}

void funMostrarTodasPublicaciones(eProducto lista[], int t)
{
    int i;
    printf("ID\t%50s\t%s\t%s\t%s\t%18s\n","Nombre","Precio","Vendido","Stock","Usuario");
    for(i=0; i<t; i++)
    {
        if (lista[i].Estado != 0)
        {
            funMostrarPublicacion(lista[i]);
        }
    }
}

int funCrearUsu(eUsuario lista[],int index, int t)
{
    int flag = 0,auxInt;
    char auxChar[50];
    printf("Ingrese el Usuario: ");
    fflush(stdin);
    gets(auxChar);
    auxInt = funBuscarUsuario(lista,auxChar,t);
    if (auxInt != -1)
    {
        strcpy(lista[index].Usuario,auxChar);
        printf("Ingrese el Contrasenia: ");
        fflush(stdin);
        gets(lista[index].Password);
        flag = 1;
    }

    return flag;
}

int funModProd(eUsuario listaUsu[], int tU, eProducto listaProd[], int tP)
{
    int i, auxInt, opcion, id;
    char auxChar1[CHARUSU], auxChar2[CHARPASS], auxResp, auxCharNum[6];
    char salir = 'n';
    int index, flag =0;
    printf("Igrese el Usuario: ");
    fflush(stdin);
    gets(auxChar1);
    printf("Igrese la Contraseña: ");
    fflush(stdin);
    gets(auxChar2);
    index = funBuscarUsyCon(listaUsu, tU,auxChar1,auxChar2);
    if (index != -1)
    {
        system("cls");
        printf("ID\t%50s\t%s\t%s\t%s\t%18s\n","Nombre","Precio","Vendido","Stock","Usuario");
        for(i=0; i<tP; i++)
        {
            if(strcmp(listaUsu[index].Usuario,listaProd[i].Usuario) == 0 && (listaProd[i].Estado != 0))
            {
                funMostrarPublicacion(listaProd[i]);
            }
        }
        printf("Ingrese el ID de la publicacion que desea modificar: ");
        fflush(stdin);
        gets(auxCharNum);
        auxInt = funChequeoNumero(auxCharNum);
        while (auxInt != 0)
        {
            printf("Reingrese el ID de la publicacion que desea modificar: ");
            fflush(stdin);
            gets(auxCharNum);
            auxInt = funChequeoNumero(auxCharNum);
        }
        id = atoi(auxCharNum);
        index = funBuscarPub(listaProd, id, tP);
        if (index != -1)
        {
            system("cls");
            do
            {
                printf("ID\t%50s\t%s\t%s\t%s\t%18s\n","Nombre","Precio","Vendido","Stock","Usuario");
                funMostrarPublicacion(listaProd[index]);
                opcion=funMostrarMenu("1-Modificar Precio\
                                      \n2-Modificar Stock\
                                      \n3-Finalizar\
                                      \nIngrese la opcion a usar: ");
                switch (opcion)
                {
                case 1:
                    printf("Ingrese el nuevo precio (solo enteros): ");
                    fflush(stdin);
                    gets(auxCharNum);
                    auxInt = funChequeoNumero(auxCharNum);
                    while (auxInt != 0)
                    {
                        printf("Reingrese el nuevo precio (solo Enteros): ");
                        fflush(stdin);
                        gets(auxCharNum);
                        auxInt = funChequeoNumero(auxCharNum);
                    }
                    auxInt = atoi(auxCharNum);
                    printf("Esta seguro de cambiar el precio? s/n");
                    auxResp = getche();
                    if (auxResp == 's')
                    {
                        listaProd[index].Precio=auxInt;
                        printf("Se modifico el precio!!!\n");
                        flag = 1;
                    }
                    else
                    {
                        printf("No se modifico el precio!!!\n");
                    }
                    funBorrarPantalla();
                    break;

                case 2:
                    printf("Ingrese el nuevo stock (solo enteros): ");
                    fflush(stdin);
                    gets(auxCharNum);
                    auxInt = funChequeoNumero(auxCharNum);
                    while (auxInt != 0)
                    {
                        printf("Reingrese el nuevo stock (solo enteros): ");
                        fflush(stdin);
                        gets(auxCharNum);
                        auxInt = funChequeoNumero(auxCharNum);
                    }
                    auxInt = atoi(auxCharNum);
                    printf("Esta seguro de cambiar el stock? s/n");
                    auxResp = getche();
                    if (auxResp == 's')
                    {
                        listaProd[index].Stock=auxInt;
                        printf("Se modifico el stock!!!\n");
                        flag = 1;
                    }
                    else
                    {
                        printf("No se modifico el stock!!!\n");
                    }
                    funBorrarPantalla();
                    break;

                case 3:
                    salir = 's';
                    break;
                default:
                    printf("Opcion inexistente!!!");
                    funBorrarPantalla();
                    break;
                }
            }
            while (salir != 's');
        }
    }
    else
    {
        flag = -1;
    }
    return flag;
}

int funModUsu(eUsuario lista[], int t)
{
    int index, opcion,auxRetor;
    int flag = 0;
    char auxChar [50], auxChar1[50], auxChar2[50];
    char salir = 'n', auxResp;
    printf("Igrese el Usuario : ");
    fflush(stdin);
    gets(auxChar1);
    printf("Igrese La Contraseña: ");
    fflush(stdin);
    gets(auxChar2);
    index = funBuscarUsyCon(lista,t,auxChar1,auxChar2);
    if (index != -1)
    {
        system("cls");
        do
        {
            printf("&s\t%30s\t%20s\t%s\n","Usuario","Nombre","Apellido","Calificacion");
            funMostrarUsu(lista[index]);
            opcion=funMostrarMenu("1-Modificar Nombre\
                             \n2-Modificar Apellido\
                             \n3-Modificar Apellido\
                             \n4-Finalizar\
                             \nIngrese la opcion a usar: ");
            switch (opcion)
            {
            case 1:
                printf("Ingrese el nuevo Nombre (%d caracteres Maximo): ",CHARNOMUSU);
                fflush(stdin);
                gets(auxChar);
                auxRetor = funContarCaracteres(auxChar, CHARNOMUSU);
                while (auxRetor!=0)
                {
                    printf("Reingrese el nuevo Nombre (%d caracteres Maximo): ",CHARNOMUSU);
                    fflush(stdin);
                    gets(auxChar);
                    auxRetor = funContarCaracteres(auxChar, CHARNOMUSU);
                }
                printf("Esta seguro de cambiar el Nombre? s/n");
                auxResp = getche();
                if (auxResp == 's')
                {
                    strcpy(lista[index].Nombre, auxChar);
                    printf("\nSe modifico el Nombre\n");
                    flag = 1;
                }
                else
                {
                    printf("\nNo se modifico el Nombre\n");
                }
                funBorrarPantalla();
                break;

            case 2:
                printf("Ingrese el nuevo Apellido (%d caracteres Maximo): ",CHARAPEUSU);
                fflush(stdin);
                gets(auxChar);
                auxRetor = funContarCaracteres(auxChar, CHARAPEUSU);
                while (auxRetor!=0)
                {
                    printf("Reingrese el nuevo Apellido (%d caracteres Maximo): ",CHARAPEUSU);
                    fflush(stdin);
                    gets(auxChar);
                    auxRetor = funContarCaracteres(auxChar, CHARAPEUSU);
                }
                printf("Esta seguro de cambiar el Apellido? s/n");
                auxResp = getche();
                if (auxResp == 's')
                {
                    strcpy(lista[index].Apellido, auxChar);
                    printf("\nSe modifico el Apellido\n");
                    flag = 1;
                }
                else
                {
                    printf("\nNo se modifico el Apellido\n");
                }
                funBorrarPantalla();
                break;

            case 3:
                printf("Ingrese la nueva Contrasenia (%d caracteres Maximo): ",CHARPASS);
                fflush(stdin);
                gets(auxChar);
                auxRetor = funContarCaracteres(auxChar, CHARPASS);
                while (auxRetor!=0)
                {
                    printf("Reingrese la nueva Contrasenia (%d caracteres Maximo): ",CHARPASS);
                    fflush(stdin);
                    gets(auxChar);
                    auxRetor = funContarCaracteres(auxChar, CHARPASS);
                }
                printf("Esta seguro de cambiar la Contrasenia? s/n");
                auxResp = getche();
                if (auxResp == 's')
                {
                    strcpy(lista[index].Password, auxChar);
                    printf("\nSe modifico la Contrasenia\n");
                    flag = 1;
                }
                else
                {
                    printf("\nNo se modifico la Contrasenia\n");
                }
                funBorrarPantalla();
                break;

            case 4:
                salir = 's';
                break;
            default:
                printf("Opcion inexistente!!!");
                funBorrarPantalla();
                break;
            }
        }
        while (salir != 's');
    }
    return flag;
}

void funMostrarUsu(eUsuario lista)
{
    printf("%s\t%30s\t%20s\t%2f\n",lista.Usuario,lista.Nombre, lista.Apellido, lista.calipromedio);
}

void funMostrarTodosUsu(eUsuario lista[], int t)
{
    int i;
    printf("Usuario\t%30s\t%20s\t%s\n","Nombre","Apellido","Calificacion");
    for(i=0; i<t; i++)
    {
        if (lista[i].Estado != 0)
        {
            funMostrarUsu(lista[i]);
        }
    }
}

int funBorrarProd(eUsuario listaUsu[], int tU, eProducto listaProd[], int tP)
{
    int i, auxInt, id;
    char auxChar1[CHARUSU], auxChar2[CHARPASS], auxResp, auxCharNum[10];
    int index, flag =0;
    printf("Igrese el Usuario: ");
    fflush(stdin);
    gets(auxChar1);
    printf("Igrese la Contraseña: ");
    fflush(stdin);
    gets(auxChar2);
    index = funBuscarUsyCon(listaUsu, tU,auxChar1,auxChar2);
    if (index != -1)
    {
        system("cls");
        printf("ID\t%50s\t%s\t%s\t%s\t%18s\n","Nombre","Precio","Vendido","Stock","Usuario");
        for(i=0; i<tP; i++)
        {
            if(strcmp(listaUsu[index].Usuario,listaProd[i].Usuario) == 0 && (listaProd[i].Estado != 0))
            {
                funMostrarPublicacion(listaProd[i]);
            }
        }
        printf("Ingrese el ID de la publicacion que desea cancelar: ");
        fflush(stdin);
        gets(auxCharNum);
        auxInt = funChequeoNumero(auxCharNum);
        while (auxInt != 0)
        {
            printf("Reingrese el ID de la publicacion que desea cancelar: ");
            fflush(stdin);
            gets(auxCharNum);
            auxInt = funChequeoNumero(auxCharNum);
        }
        id = atoi(auxCharNum);
        index = funBuscarPub(listaProd, id, tP);
        if (index != -1)
        {
            system("cls");
            printf("ID\t%50s\t%s\t%s\t%s\t%18s\n","Nombre","Precio","Vendido","Stock","Usuario");
            funMostrarPublicacion(listaProd[index]);
            printf("Esta seguro que desea cancelar la publicacion? s/n");
            auxResp = getche();
            if (auxResp == 's')
            {
                listaProd[index].Estado = 0;
                flag = 1;
            }
        }
    }
    else
    {
        flag = -1;
    }
    return flag;
}

int funBorrarUsu(eUsuario listaUsu[], int tU, eProducto listaProd[], int tP)
{
    int i;
    char auxChar1[CHARUSU], auxChar2[CHARPASS], auxResp;
    int index, flag =0;
    printf("Igrese el Usuario que desaea borrar: ");
    fflush(stdin);
    gets(auxChar1);
    printf("Igrese la Contraseña: ");
    fflush(stdin);
    gets(auxChar2);
    index = funBuscarUsyCon(listaUsu, tU,auxChar1,auxChar2);
    if (index != -1)
    {
        printf("Esta seguro de borrarlo? s/n");
        auxResp = getche();
        if(auxResp == 's')
        {
            for(i=0; i<tP; i++)
            {
                if(strcmp(listaProd[i].Usuario,auxChar1)== 0)
                {
                    listaProd[i].Estado = 0;
                }
            }
            listaUsu[index].Estado =0;
            flag = 1;
        }
    }
    else
    {
        flag = -1;
    }
    return flag;
}

int funCompra(eUsuario listaUsu[], int tUsu, eProducto listaProd[], int tProd)
{
    int indexProd, indexUsu, auxInt, id,cantComp;
    int flag = 0;
    char auxChar[6];
    funMostrarTodasPublicaciones(listaProd, tProd);
    printf("Ingrese el ID de la publicacion a comprer:");
    fflush(stdin);
    gets(auxChar);
    auxInt = funChequeoNumero(auxChar);
    while (auxInt != 0)
    {
        system("cls");
        funMostrarTodasPublicaciones(listaProd, tProd);
        printf("Reingrese el ID de la publicacion a comprar: ");
        fflush(stdin);
        gets(auxChar);
        auxInt = funChequeoNumero(auxChar);
    }
    id = atoi(auxChar);
    indexProd = funBuscarPub(listaProd, id, tProd);
    if (indexProd != -1)
    {
        system("cls");
        funMostrarPublicacion(listaProd[indexProd]);
        if (listaProd[indexProd].Stock>0)
        {
            printf("Ingrese la cantidad a comprar: ");
            fflush(stdin);
            gets(auxChar);
            auxInt = funChequeoNumero(auxChar);
            while (auxInt != 0)
            {
                printf("Reingrese la cantidad a comprar: ");
                fflush(stdin);
                gets(auxChar);
                auxInt = funChequeoNumero(auxChar);
            }
            cantComp = atoi(auxChar);
            while (cantComp> listaProd[indexProd].Stock || cantComp<0)
            {
                system("cls");
                funMostrarPublicacion(listaProd[indexProd]);
                printf(" Reingrese la cantidad a comprar: ");
                fflush(stdin);
                gets(auxChar);
                auxInt = funChequeoNumero(auxChar);
                while (auxInt != 0)
                {
                    system("cls");
                    funMostrarPublicacion(listaProd[indexProd]);
                    printf("Reingrese la cantidad a comprar: ");
                    fflush(stdin);
                    gets(auxChar);
                    auxInt = funChequeoNumero(auxChar);
                }
                cantComp = atoi(auxChar);
            }
            listaProd[indexProd].Stock-=cantComp;
            listaProd[indexProd].cantVentProduc+=cantComp;
            listaProd[indexProd].cantVentas++;
            indexUsu = funBuscarUsuario(listaUsu, listaProd[indexProd].Usuario, tUsu);
            listaUsu[indexUsu].CantVentas++;
            printf("Califique al usuario entre 1 y 100: ");
            fflush(stdin);
            gets(auxChar);
            auxInt = funChequeoNumero(auxChar);
            while (auxInt != 0)
            {
                system("cls");
                printf("Reingrese la califique al usuario entre 1 y 100: ");
                fflush(stdin);
                gets(auxChar);
                auxInt = funChequeoNumero(auxChar);
            }
            auxInt = atoi(auxChar);
            while (auxInt < 1 || auxInt > 101)
            {
                system("cls");
                printf("Reingrese la califique al usuario entre 1 y 100: ");
                fflush(stdin);
                gets(auxChar);
                auxInt = funChequeoNumero(auxChar);
                while (auxInt != 0)
                {
                    system("cls");
                    printf("Reingrese la califique al usuario entre 1 y 100: ");
                    fflush(stdin);
                    gets(auxChar);
                    auxInt = funChequeoNumero(auxChar);
                }
                auxInt = atoi(auxChar);
            }
            listaUsu[indexUsu].calificacion+=auxInt;
            listaUsu[indexUsu].calipromedio = (float) listaUsu[indexUsu].calificacion / listaUsu[indexUsu].CantVentas;
            flag = 1;
        }
        else
        {
            flag = 2;
        }
    }
    else
    {
        flag = -1;
    }
    return flag;
}

int funListarPubUsu(eUsuario listaUsu[], int tUsu, eProducto listaPro[], int tPro)
{
    int i;
    char auxChar1[CHARUSU];
    int index, flag =0;
    funMostrarTodosUsu(listaUsu, tUsu);
    printf("Igrese el Usuario que desaea listar: ");
    fflush(stdin);
    gets(auxChar1);
    index = funBuscarUsuario(listaUsu, auxChar1, tUsu);
    if (index != -1)
    {
        for (i=0; i<tPro; i++)
        {
            printf("ID\t%50s\t%s\t%s\t%s\t%18s\n","Nombre","Precio","Vendido","Stock","Usuario");
            if (strcmp(listaUsu[index].Usuario,listaPro[i].Usuario) == 0 && (listaPro[i].Estado == 0))
            {
                funMostrarPublicacion(listaPro[i]);
            }
        }
        funBorrarPantalla();
    }
    else
    {
        flag = -1;
    }

    return flag;
}

int funContarCaracteres(char campo[], int tamano)
{
    int flag = 0;
    int cont;
    cont = strlen(campo);
    if (cont > tamano)
    {
        flag = 1;
    }
    return flag;
}

void funBorrarPantalla()
{
    system("pause");
    system("cls");
}
