/*Given a File of N employee records with a set K of Keys(4-digit) which uniquely 
determine the records in file F. Assume that file F is maintained in memory by a
Hash Table(HT) of m memory locations with L as the set of memory addresses (2-digit)
of locations in HT. Let the keys in K and addresses in L are Integers. Design 
and develop a Program in C that uses Hash function H: K ®L as H(K)=K mod m (remainder method),
and implement hashing technique to map a given key K to the address space L. Resolve the collision (if any) 
using linear probing.*/


#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int create(int);
void linear_prob(int[], int, int);
void display (int[]);


int main() {
	int a[MAX],key,adr,i;
	int ans=1;
	printf(" collision handling by linear probing : \n");
	for (i=0; i<MAX; i++) {
		a[i] = -1;
	}
	do {
		printf("\n Enter the data: ");
		scanf("%4d", &key);
		adr=create(key);
		linear_prob(a,adr,key);
		printf("\n Do you wish to continue ? (1/0) ");
		scanf("%d",&ans);
	} while(ans);
	printf("work is done");
	display(a);
	
	return 0;
}


//creating a key
int create(int key) {
	int adr;
	adr=key%10;
	return adr;
}

void linear_prob(int a[MAX], int adr, int key) {
	int flag, i, count=0;
	flag=0;
	if(a[adr]== -1) {
		a[adr] = key;
	} else {
		printf("\nCollision Detected...!!!\n");
		i=0;
		while(i<MAX) {
			if (a[i]!=-1)
				count++;
			i++;
		}
		printf("Collision avoided successfully using LINEAR PROBING\n");
		if(count == MAX) {
			printf("\n Hash table is full");
			display(a);
			exit(1);
		}
		for(i=adr+1; i<MAX; i++)
			if(a[i] == -1) {
				a[i] = key;
				flag =1;
				break;
			}
			i=0;
			while((i<adr) && (flag==0)) {
			if(a[i] == -1) {
				a[i] =key;
				flag=1;
				break;
			}
			i++;
		}
	}

	
}
void display(int a[MAX]) {
	
		printf("\n the hash table is\n");
		for(int i=0; i<MAX; i++)
			printf("\n %d %d ", i, a[i]);
			
			
	}

