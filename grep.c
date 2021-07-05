#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void citire_siruri(char sir[], char **s)
{	
	fgets(sir,200,stdin);
	*s=(char*)calloc(1,strlen(sir)*sizeof(char));//aloc memoria necesara pt fiecare sir
	strcpy(*s,"");
	strncpy(*s,sir,strlen(sir)-1);//copiez sirul citit in vector
}
void prelucrare(char *p, char *s, int *contor)
{
	(*contor)=0;
	while(strstr(s,p)!=NULL)
	{
		(*contor)++;//contorizez numarul de aparitii al cuvantului
		s=s+(strstr(s,p)-s)+strlen(p);
	}
}
void afisare(int *contor, char *j, char p[], int *dim)
{
	char *aux;
	char *str;
	str=(char*)calloc(1,((*dim)+(*contor)*11)*sizeof(char));//aloc memoria necesara pentru colorarea sirului
	strcpy(str,"");
	while((aux=strstr(j,p))!=NULL)//verific daca exista cuvantul
	{
		strncpy(str,j,aux-j);//copiez ce e inainte de sirul cautat
		str[aux-j]='\0';
		strcat(str,"\e[0;31m");
		strcat(str,p);//copiez sirul
		strcat(str,"\e[m");
		printf("%s",str);
		j=j+(aux-j)+strlen(p);//ma duc la urmatoarele aparitii
	}
	printf("%s",j);//afisez ce e dupa ultima aparitie a sirului
	printf("\n");
	free(str);
}
int main()
{
	char c[30]={0}, **s, sir[200]={0};
	int i,n,contor;
	fgets(c,30,stdin);
	c[strlen(c)-1]='\0';
	scanf("%d",&n);
	getchar();
	s=(char**)malloc(n*sizeof(char*));
	for(i=0;i<n;i++)
	{
		citire_siruri(sir,&s[i]);
		s[i][strlen(s[i])]=0;
	}
	for(i=0;i<n;i++)
	{
		if(strstr(s[i],c)!=NULL)
		{
			int dim;
			char *j;
			j=(char*)malloc((strlen(s[i])+1)*sizeof(char));
			strcpy(j,s[i]);
			j[strlen(j)]=0;
			prelucrare(c,s[i],&contor);
			dim=strlen(j);
			afisare(&contor,j,c,&dim);
			free(j);
		}
		free(s[i]);
	}
	free(s);
	return 0;
}