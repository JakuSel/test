#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>

typedef struct{
	char origin[2];
	char cyp[2];
}cyper;
int main()
{
	cyper arr[36];
	FILE *fr,*fr1,*fw,*fw1;
	//otvorenie  ssuboru s klucom
	fr=	fopen("key.txt","r");
	if(fr==NULL)
	{
		printf("File error");
		return 1;
	}
	
	char z=0,x=0,y=0;
	int i=0;
	//nacitanie klucu do strukturi, origin-> original písmeno, cyp-> sifra
	while((z=fgetc(fr)) != EOF)
	{
		for(i=0;i<36;i++)
		{
		fscanf(fr,"%s%s",&arr[i].origin,&arr[i].cyp);
		
		}					
	}
	fclose(fr);
	//vypis struktury
	for(i=0;i<36;i++)
	{
		printf("%s %s ",arr[i].origin,arr[i].cyp);
	}
	printf("\n");
	printf("%s%s ",arr[0].origin,arr[0].cyp);
	//po tade to ide, vypise mi strukturu a každu jednu poziciu
	
	//otvorim dekodovaci subor a subor kde ten dekodovaci text zmenim
	fr1=fopen("encodedText.txt","r");
	fw=fopen("ans.txt","rw");
	fw1=fopen("ans1.txt","w");
	if(fr1==NULL)
	{
		printf("File error");
		return 1;
	}
	if(fw==NULL)
	{
		printf("File error");
		return 1;
	}
	if(fw1==NULL)
	{
		printf("File error");
		return 1;
	}
	//menim dekodavany subor na ciste znaky a zapisujem ich do suboru
	while((x=fgetc(fr1)) != EOF)
	{
		//ak to nie je pismeno alebo cislo tak idem dalej, continue
		if(isalnum(x)==0)
		continue;
		else
		{
		fputc(toupper(x),fw);
	//a tu som chcel aby znaky z predosleho suboru dalo do dalšieho suboru, kde by ich kontrolovalo zo strukturov a 
	//zapísalo by len znak ktory patri origin znaku
	while(y=fgetc(fw)!=EOF)
	{
	for(i=0;i<36;i++)
	{
		if (arr[i].origin=y)
		y=arr[i].cyp;
	}
		fputc(y,fw);
		
	} 		
	
	}
	}
	fclose(fr1);
	fclose(fw);
	
	return 0;
}
