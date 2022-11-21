

#include<stdio.h>
#include<string.h>

void repSub(char [],char[],char[]);

main() {
	char string[100],sub[100],newstrstr[100];
	printf("\nEnter a string: ");
	gets(string);
	printf("\nEnter the substring: ");
	gets(sub);
	printf("\nEnter the newstrstr substring: ");
	gets(newstrstr);
	repSub(string,sub,newstrstr);
	printf("\nThe string after replacing : %s\n",string);
}

void repSub(char string[],char sub[],char newstrstr[]) {
	int stringLen,subLen,newstrstrLen;
	int i=0,j,k;
	int flag=0,start,end;
	stringLen=strlen(string);
	subLen=strlen(sub);
	newstrstrLen=strlen(newstrstr);

	for(i=0; i<stringLen; i++) {
		flag=0;
		start=i;
		for(j=0; string[i]==sub[j]; j++,i++)
			if(j==subLen-1)
				flag=1;
		end=i;
		if(flag==0)
			i-=j;
		else {
			for(j=start; j<end; j++) {
				for(k=start; k<stringLen; k++)
					string[k]=string[k+1];
				stringLen--;
				i--;
			}

			for(j=start; j<start+newstrstrLen; j++) {
				for(k=stringLen; k>=j; k--)
					string[k+1]=string[k];
				string[j]=newstrstr[j-start];
				stringLen++;
				i++;
			}
		}
	}
}
