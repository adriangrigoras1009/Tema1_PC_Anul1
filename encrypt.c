#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
void citire(unsigned char **sir, int *n)
{
	int i;
	for(i=0;i<(*n);i++)
	{
		sir[i]=(unsigned char*)malloc(200*sizeof(unsigned char));
		fgets(sir[i],200,stdin);
		sir[i][strlen(sir[i])-1]='\0';
	}
}
void prelucrare_afis(unsigned char *sir)
{
	int contor,t,i,j=0;
	unsigned char *g;
		while((g=strtok(sir," "))!=NULL)//iau fiecare cuvant
		{
			contor=0;
			for(t=0;t<strlen(g);t++)
				if(g[t]<48 || g[t]>57)//verific daca e format doar din numere
					contor++;
			if(contor!=0)
				for(t=1;t<strlen(g);t++)
				{
					g[t]=(g[t]+g[0])%(256);//calculez suma lui cu cheia si fac mod 256
				}

			for(i=0;i<strlen(g);i++)
			{
				printf("%c",g[i]);
			}
			sir=sir+strlen(g)+1;//ma duc la urmatorul cuvant
			if((strtok(sir," "))!=NULL)
				printf(" ");
		}
}
int main()
{
	unsigned char **sir;
	int n,i;
	scanf("%d",&n);
	getchar();
	sir=(unsigned char**)malloc(n*sizeof(unsigned char*));
	citire(sir,&n);
	for(i=0;i<n;i++)
	{
		prelucrare_afis(sir[i]);
		printf("\n");
	}
	for(i=0;i<n;i++)
	{
		free(sir[i]);
	}
	free(sir);
	return 0;
}