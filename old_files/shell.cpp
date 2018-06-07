// Metodo de Ordenamiento por Inserci�n con incrementos decrecientes (Shell)
// Wirth pag. 75
#include <stdio.h>
#include <stdlib.h>
#define MAX 5000

int main(int argc, char *argv[]){
	int i,j,pos,aux,b,m=0,c=0,n,s,x,k;
	int h[9]={517,257,127,63,31,17,7,3,1};
	int a[MAX];
	for(i=0;i<MAX;i++){
		a[i]=int(rand());
	}
	i=0; b=1;
	for(n=0;n<9;n++){
		k=h[n]; s=-k;
		for(i=k+1;i<MAX;i++){
			x=a[i]; j=i-k; m++;c++;
			while((j>0)&&(x<a[j])){
				a[j+k]=a[j]; j=j-k;  m++;c++;
			}
			a[j+k]=x; m++;
		}
	}
	printf("\n cantidad de comparaciones= %d  movimientos= %d",c,m);
}
