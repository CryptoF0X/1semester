#include <stdio.h>
#include <malloc.h>
#include <locale.h>

void sut(int **a, int n)
{
    for (int k=0;k<n;k++)
    {
        for (int i=0;i<n;i++)
        {
            if (a[1][k]==a[2][i]) // проверяем связь первой подстановки со второй
            {
                a[1][k]=a[3][i];//сразу заменяем соответствующий элемент первой подстановки
            break;
            }

        }
    }

    for (int k=0;k<n;k++) //сортировка методом пузырька
    {
        for (int i=k+1;i<n;i++)
        {
            if (a[0][k]>a[0][i])
            {
                int buf1=a[0][i];
                int buf2=a[1][i];
                a[0][i]=a[0][k];
                a[1][i]=a[1][k];
                a[0][k]=buf1;
                a[1][k]=buf2;
            }
        }
    }
}

int main()
{
    int n,i,k;
    setlocale (LC_ALL, "Russsian");
    printf("Введите мощность подстановки: ");
    scanf("%d", &n);

    int **a = (int **)malloc(4*sizeof(int *)); // выделяем память под массив адресов

        a[0] = (int *)malloc(n*sizeof(int)); // выделяем память под 4 строки
        a[1] = (int *)malloc(n*sizeof(int));
        a[2] = (int *)malloc(n*sizeof(int));
        a[3] = (int *)malloc(n*sizeof(int));


    printf("Введите подстановки: \n");
    for (i=0;i<n;i++) // считываем элементы первой подстановки
        scanf("%d", &a[0][i]);
    for (i=0;i<n;i++)
        scanf("%d", &a[1][i]);

    printf("\n");

    for (i=0;i<n;i++) // считываем элементы второй подстановки
        scanf("%d", &a[2][i]);
    for (i=0;i<n;i++)
        scanf("%d", &a[3][i]);

    sut(a,n);


    printf("Результирующая подстановка: \n");
    for (i=0;i<n;i++)
        printf("%d ", a[0][i]);

    printf("\n");

    for (i=0;i<n;i++)
        printf("%d ", a[1][i]);



    for(i=0;i<4;i++) //очищение памяти
    {
        free(a[i]);
    }
    free(a);
    return 0;
}
