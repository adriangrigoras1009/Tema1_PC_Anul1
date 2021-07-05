#include<stdio.h>
#include<stdlib.h>

void citire(int **note)
{
	int *i;
	*note=(int*)malloc(3*sizeof(int));
	int contor=0;
	int j=0;
	i=*note;
	do
	{
		scanf("%d",&i[j]);
		contor++;
		j++;
		if(contor==3)
		{
			*note=(int*)realloc(*note,(contor+j)*sizeof(int));
			contor=0;
			i=*note;
		}
	}while(i[j-1]!=0);
}
void medie(float **index, int *nl, int **note)
{
	double suma;
	int i,j;
	double media;
	for(i=0;i<(*nl);i++)
	{
		suma=0;
		for(j=0;note[i][j]!=0;j++)
		{
			suma=suma+note[i][j];
		}
		media=((double)suma/j);
		index[0][i]=media;//dupa ce calculez media, o pun intr-o matrice
		index[1][i]=i;//pe cealalta linie pun indexu pentru a retine a cata linie citita e
	}
}
void sortare(float **index, int *nl)
{
	int s,j,i;
	float aux;
	do
	{
		s=0;
		for(j=0;j<*(nl)-1;j++)
		{
			if(index[0][j]>index[0][j+1])
			{
				for(i=0;i<2;i++)//sortez mediile
				{
					aux=index[i][j];
					index[i][j]=index[i][j+1];
					index[i][j+1]=aux;
				}
				s++;
			}
		}
	}while(s!=0);
	do
	{
		s=0;
		for(j=0;j<*(nl)-1;j++)
			if(index[0][j]==index[0][j+1])//sortez mediile la fel in functie de momentul citirii lor
				if(index[1][j+1]>index[1][j])
					for(i=0;i<2;i++)
					{
						s++;
						aux=index[i][j];
						index[i][j]=index[i][j+1];
						index[i][j+1]=aux;
					}
	}while(s!=0);
}
void afisare(int **note,float **index, int *nl)
{
	int i,j;
	for(i=(*nl)-1;i>=0;i--)
	{
		printf("%-10.3f",index[0][i]);
		int c=index[1][i];
		for(j=0;note[c][j]!=0;j++)
		{
			printf("%d ",note[c][j]);
		}
		printf("\n");
	}
}
int main()
{
	int **note;
	int nl,i;
	float **index;
	scanf("%d",&nl);
	note=(int**)malloc(nl*sizeof(int*));
	for(i=0;i<nl;i++)
	{
		citire(&note[i]);
	}
	index=(float**)malloc(2*sizeof(float*));
	index[0]=(float*)calloc(1,nl*sizeof(float));
	index[1]=(float*)calloc(1,nl*sizeof(float));
	medie(index,&nl,note);
	sortare(index,&nl);
	afisare(note,index,&nl);
	for(i=0;i<2;i++)
		free(index[i]);
	free(index);
	for(i=0;i<nl;i++)
		free(note[i]);
	free(note);
	return 0;
}
