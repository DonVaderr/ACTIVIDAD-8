// GABRIEL TEJEDA CHAVEZ
// PROGRAMA QUE CREA E IMPRIME ARREGLOS NUMERICOS
// 19/03/2024

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

int msges();
void menu();
void llenar_vector(int vect[], int m);
void vector_num_aleat(int vect[], int m);
void vector_datos_arreglo(int vect1[], int vect2[], int m);
void imprimir_vector1(int vect[], int m, char nombre[]);
void imprimir_vector2(int vect[], int m, char nombre[]);
void imprimir_vector3(int vect[], int vect2[], int vect3[], int m, char nombre[]);
void llenar_matriz(int vect1[], int vect2[], int m);
void imprimir_matriz(int vect1[], int vect2[], int m);
int buscador(int vect2[], int num, int m);

int main()
{
    menu();
    system("CLS");
    return 0;
}

int msges()
{
    int op;
    system("CLS");
    printf("    Men%c\n", 163);
    printf("1.- Llenar vector 1 (manualmente) \n");
    printf("2.- Llenar vector 2 (aleatoriamente) \n");
    printf("3.- Llenar vector 3 (vector 1 y vector 2) \n");
    printf("4.- Imprimir vectores  \n");
    printf("5.- Llena matriz 4*4  \n");
    printf("6.- Imprimir matriz  \n");
    printf("0.- Salir  \n");
    printf("Escoge una opci%cn: ", 162);
    scanf("%d", &op);
    return op;
}

void menu()
{
    int op, vect1[N], vect2[N], vect3[21], matriz[2][N];
    do
    {
        op = msges();
        switch (op)
        {
        case 1:
            llenar_vector(vect1, N);
            break;

        case 2:
            vector_num_aleat(vect2, N);
            break;

        case 3:
            vector_datos_arreglo(vect1, vect2, N);
            break;

        case 4:
            imprimir_vector1(vect1, N, "VECTOR 1");
            imprimir_vector2(vect2, N, "VECTOR 2");
            imprimir_vector3(vect1, vect2, vect3, N, "VECTOR 3");
            break;

        case 5:
            llenar_matriz(vect1, vect2, N);
            break;

        case 6:
            imprimir_matriz(vect1, vect2, N);
            break;
        }

    } while (op != 0);
}

void llenar_vector(int vect1[], int m)
{
    system("CLS");
    int i, j;

    for (i = 0; i < m; i++)
    {
        j = i;
        do
        {
            system("CLS");
            printf("Ingrese un numero entero que este entre el 30 y el 70 para el vector[%d]: ", i);
            scanf("%d", &vect1[j]);
            if (vect1[j] >= 30 && vect1[j] <= 70)
            {
                j++;
            }
            else
            {
                printf("Valor incorrecto, intentelo nuevamente\n");
                system("PAUSE");
            }

        } while (j <= i);
    }
}

int buscador(int vect2[], int num, int m)
{
    int i;
    for (i = 0; i < m; i++)
    {
        if (vect2[i] == num)
        {
            return 1;
        }
    }
    return 0;
}

void vector_num_aleat(int vect2[], int m)
{
    system("CLS");
    int i, j, k, repetido, num;
    srand(time(NULL));

    i = 0;
    while (i < m)
    {
        num = (rand() % 20) + 1;
        if (buscador(vect2, num, m) == 0)
        {
            vect2[i] = num;
            i++;
        }
    }
}

void vector_datos_arreglo(int vect1[], int vect2[], int m)
{
    system("CLS");

    int vect3[20], i;

    for (i = 0; i < 10; i++)
    {
        vect3[i] = vect1[i];
    }

    for (i = 0; i < 10; i++)
    {
        vect3[i + 10] = vect2[i];
    }
}

void imprimir_vector1(int vect1[], int m, char nombre[])
{
    int i;
    system("CLS");
    printf("\n\n %s  \n", nombre);
    for (i = 0; i < m; i++)
    {
        printf("Vect1[%d] = %d\n", i, vect1[i]);
    }
}

void imprimir_vector2(int vect2[], int m, char nombre[])
{
    int i;
    printf("\n\n %s  \n", nombre);
    for (i = 0; i < m; i++)
    {
        printf("Vect2[%d] = %d\n", i, vect2[i]);
    }
}

void imprimir_vector3(int vect1[], int vect2[], int vect3[], int m, char nombre[])
{
    int i;
    printf("\n\n %s  \n", nombre);

    for (i = 0; i < 10; i++)
    {
        vect3[i] = vect1[i];
    }

    for (i = 0; i < 10; i++)
    {
        vect3[i + 10] = vect2[i];
    }

    for (i = 0; i < 20; i++)
    {
        printf("Vector[%d]= %d\n", i, vect3[i]);
    }
    system("PAUSE");
}

void llenar_matriz(int vect1[], int vect2[], int m)
{
    system("CLS");
    int matriz[2][N];
    int i, j;

    for (i = 0; i < m; i++)
    {
        matriz[0][i] = vect1[i];
    }

    for (i = 0; i < m; i++)
    {
        matriz[1][i] = vect2[i];
    }
}

void imprimir_matriz(int vect1[], int vect2[], int m)
{
    system("CLS");
    int matriz[2][N];
    int i, j;

    for (i = 0; i < m; i++)
    {
        matriz[0][i] = vect1[i];
    }

    for (i = 0; i < m; i++)
    {
        matriz[1][i] = vect2[i];
    }

    printf("Matriz resultante:\n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    system("PAUSE");
}
