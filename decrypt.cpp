#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>

int main()
{
	FILE *fr,*fr1,*fw;
	//otvorenie  ssuboru s klucom
	fr=	fopen("codeTable.txt","r");
	if(fr==NULL)
	{
		printf("File error");
		return 1;
	}
	char key[80],z=0,x=0,y=0;
	int i=0,j=0;

	while ((z = fgetc(fr)) != EOF) 
	{
    	if (isalpha(z) || isdigit(z)) 
		{
     	key[i] = z;
     	i++;
   		}
 	}
 	fclose(fr);
	
	fr1=fopen("secretCode.txt","r");
	fw=fopen("ans.txt","w");
	
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

	
	while((x=fgetc(fr1)) != EOF)
	{
		if(isalnum(toupper(x)))
		{
			for(j=0;j<i;j=j+2)
			{
				if(toupper(x)==key[j])
				x=key[j+1];
				break;
			}
			
		}
		
		fputc(x,fw);
			
		
	}
	fclose(fr1);
	fclose(fw);
	
	return 0;
}
