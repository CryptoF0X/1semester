#include <stdio.h>
#include <malloc.h>
#include <locale.h>

int step(int **a, int n, int s)
{
    if (s==0)
        printf("Нулевая степень: (e)");

    if (s==1)
    {
        printf("Результирующая подстановка: \n");
            for (int i=0;i<n;i++)
            printf("%d ", a[0][i]);
        printf("\n");
            for (int i=0;i<n;i++)
            printf("%d ", a[1][i]);
    }

    else


    {
        int **b = (int **)malloc(2*sizeof(int*));
            b[0]=(int *)malloc(n*sizeof(int));
            b[1]=(int *)malloc(n*sizeof(int));
        for (int k=0;k<n;k++)
                {
                b[0][k]=a[0][k];
                b[1][k]=a[1][k];
                }
        for (int c=0;c<s-1;c++)
        {
            for (int k=0;k<n;k++)
            {
                for (int i=0;i<n;i++)
                {
                    if (a[1][k]==b[0][i]) // проверяем связь
                    {
                        a[1][k]=b[1][i];
                        break;
                    }
                }
            }
        }
        printf("Результирующая подстановка: \n");
            for (int i=0;i<n;i++)
            printf("%d ", a[0][i]);
        printf("\n");
            for (int i=0;i<n;i++)
            printf("%d ", a[1][i]);
        for(int i=0;i<2;i++) //очищение памяти
        {
            free(b[i]);
        }
        free(b);
    }
return 0;
}


    int main()
{
    int n,i,s;
    setlocale (LC_ALL, "Russsian");
    printf("Введите мощность подстановки: ");
    scanf("%d", &n);

    int **a = (int **)malloc(2*sizeof(int *)); // выделяем память под массив адресов

        a[0] = (int *)malloc(n*sizeof(int)); // выделяем память под  строки
        a[1] = (int *)malloc(n*sizeof(int));


    printf("Введите подстановку: \n");
    for (i=0;i<n;i++) // считываем элементы подстановки
        scanf("%d", &a[0][i]);
    for (i=0;i<n;i++)
        scanf("%d", &a[1][i]);

    printf("\n");

    printf("Введите степень: ");
    scanf("%d", &s);


    step(a,n,s);


    for(i=0;i<2;i++) //очищение памяти
    {
        free(a[i]);
    }
    free(a);
    return 0;
}
