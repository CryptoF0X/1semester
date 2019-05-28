#include <stdio.h>
#include <malloc.h>
#include <locale.h>

void buble(int **a, int n)
    {
        for (int k=0;k<n;k++)
        {
            for (int i=k+1;i<n;i++)
            {
                if (a[1][k]>a[1][i])
                {
                int buf1=a[1][i];
                int buf2=a[0][i];
                a[1][i]=a[1][k];
                a[0][i]=a[0][k];
                a[1][k]=buf1;
                a[0][k]=buf2;
                }
            }
        }
    }

int main()
{
    int n,i,k;
    setlocale (LC_ALL, "Russian");
    printf("Введите мощность подстановки: ");
    scanf("%d", &n);

    int **a = (int **)malloc(2*sizeof(int *)); // выделяем память под массив адресов

        a[0] = (int *)malloc(n*sizeof(int)); // выделяем память под две строки
        a[1] = (int *)malloc(n*sizeof(int));

    printf("Введите подстановку: \n");
    for (i=0;i<n;i++)
        scanf("%d", &a[0][i]); // считываем элементы из верхней строки

    for (i=0;i<n;i++)
        scanf("%d", &a[1][i]); // считываем элементы из нижней строки

    buble(a,n);

    printf("Обратная подстановка: \n");
    for (i=0;i<n;i++)
        printf("%d ", a[1][i]); // вывод упорядоченной строки подстановки
    printf("\n");
    for (i=0;i<n;i++)
        printf("%d ", a[0][i]); //вывод соответствующих элементов подстановки


    for(i=0;i<2;i++) //очищение памяти
    {
        free(a[i]);
    }
    free(a);
    return 0;
}
