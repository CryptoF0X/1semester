#include <stdio.h>
#include <malloc.h>
#include <locale.h>

int finds(int **a, int n)
{
    int t=0;
    for(int i=0;i<n;i++)
    {
        if (a[0][i]==a[1][i])
            t++;
    }
    if  (t==n)
    {
        printf("Ваша подстановка первого порядка.");
    }
    else
    {
        int s=1;
        int **b = (int **)malloc(2*sizeof(int*)); //выделяем память под копию первичной подстановки
            b[0]=(int *)malloc(n*sizeof(int));
            b[1]=(int *)malloc(n*sizeof(int));

        for (int k=0;k<n;k++) //делаем копию подстановки
            {
                b[0][k]=a[0][k];
                b[1][k]=a[1][k];
            }

        while(t!=n)
        {
            t=0;
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
            s++;

            for(int i=0;i<n;i++)
            {
                if (a[0][i]==a[1][i])
                t++;
            }
        }

        for(int i=0;i<2;i++) //очищение памяти c копией
        {
            free(b[i]);
        }
        free(b);

        printf("Ваша подстановка %d порядка.", s);
    }
    return 0;
}




int main()
{
    int n,i;
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

    finds(a,n);

    for(i=0;i<2;i++) //очищение памяти
    {
        free(a[i]);
    }
    free(a);
    return 0;
}

