#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <locale.h>

int Funct(int **a, int m)
{
	int i, j, k=0, x=0, y;
	int *c=(int*)malloc(m*sizeof(int));

	for(i=0;i<2;i++)
	{
		for(j=0;j<m;j++)
		{
			if((a[i][j]>m) || (a[i][j]<1))
			{
				printf("У вас ошибка. ");
				return -1;
			}
		}
	}

	for(i=0; i<2; i++)
	{
		for(j=0; j<m-1; j++)
		{
			if(a[i][j]==a[i][j+1])
			{
				printf("У вас ошибка.");
				return -1;
			}
		}
	}

	int *b=(int*)malloc(m*sizeof(int));
	for(i=0; i<m; i++)
		b[i]=0;

	printf("Циклы данной подстановки: \n");
	i=a[0][0];

	while(x<m)
	{
		int l=0, z=0;
		printf("(");

		while(i!=j)
		{
			if(l==0)
			{
				j=i;
				l=1;
			}
			printf ("%d", i);
			b[i-1]=1;
			x++;
			i=a[1][i-1];
			z++;
		}
		printf (")");
		c[k]=z;
		k++;

		for(y=0; y<m; y++)
		{
			if(b[y]==0)
			{
				i=y+1;
				break;
			}
		}
	}
	printf("\n");
	printf("Длина циклов: \n");
	for(i=0; i<m; i++)
	{
		if(c[i]==0)
			break;
		printf("%d цикл: %d\n", i+1, c[i]);
	}
	free(b);
	free(c);
	return 0;
}


int main()
{
	int m;
    setlocale (LC_ALL, "Russsian");
	printf("Введите мощность подстановки: ");
	scanf("%d", &m);

	int **a=(int**)malloc(2*sizeof(int*));

        a[0] = (int*)malloc(m*sizeof(int));
        a[1] = (int*)malloc(m*sizeof(int));

	printf("Введите подстановку: \n");

    for(int j=0;j<m;j++)
		{
			scanf("%d", &a[0][j]);
		}

    for(int j=0;j<m;j++)
		{
			scanf("%d", &a[1][j]);
		}

	Funct(a, m);


	for (int i=0;i<2;i++)
	{
		free(a[i]);
	}
	free(a);
	return 0;
}
