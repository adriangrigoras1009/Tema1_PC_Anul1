#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void citire_parametri(char del[10], char out_del[10], int fields[200], int *n, int *m)
{
	int i;
	fgets(del,10,stdin);
	del[strlen(del)]='\n';
	scanf("%d",n);
	getchar();
	for(i=0;i<(*n);i++)
	{
		fscanf(stdin,"%d%*c",&fields[i]);
	}
	scanf("%s",out_del);
	scanf("%d",m);
}
void citire_sir(char final[], char **s)
{
	fgets(final,200,stdin);
	*s=(char*)calloc(1,(strlen(final)+1)*sizeof(char));//aloc memoria necesara pentru fiecare linie
	strcpy(*s,"");
	strncpy(*s,final,strlen(final)-1);
}
void prelucrare(char *final, char out_del[], char del[], int fields[], int *n, char vector[])
{
	int j;
	int contor=1,i,contor2=0;
	char *aux;
	strcpy(vector,"");
	while((aux=strtok(final,del))!=NULL)//iau un cuvant pana la un caracter din delimitatori
	{
		for(j=0;j<(*n);j++)
		{
			if(contor==fields[j])//verific daca am vreo coloana egala cu contorul
			{	
				strcat(vector,strtok(final,del));//copiez cuvantul
				strcat(vector,out_del);//pun noul delimitator
				break;
			}			
		}
		contor++;
		final=final+strlen(strtok(final,del))+1;
		do
		{
			contor2=0;
			for(i=0;i<strlen(del);i++)
			{
				if(final[0]==del[i])//verific daca exista mai multi delimitatori unul dupa altul
				{
					final+=1;//sar peste ei
					contor2++;
				}
			}
		}while(contor2!=0);
	}
}
int main()
{
	char del[10]={0},out_del[10]={0},**final,sir[200]={0},vector[250]={0};
	int fields[200]={0};
	int n,m,i;
	citire_parametri(del,out_del,fields,&n,&m);
	getchar();
	final=(char**)malloc(m*sizeof(char*));
	for(i=0;i<m;i++)
	{
		citire_sir(sir,&final[i]);	
		final[i][strlen(final[i])]=0;
	}
	for(i=0;i<m;i++)
	{
		//strcpy(vector,"");
		prelucrare(final[i],out_del,del,fields,&n,vector);
		vector[strlen(vector)-strlen(out_del)]='\0';
		printf("%s",vector);
		printf("\n");
	}
	for(i=0;i<m;i++)
		free(final[i]);
	free(final);
	return 0;
}