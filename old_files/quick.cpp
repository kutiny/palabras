// metodo de ordenamiento Quick Sort y Merge Sort
#include <cstdlib>
#include <iostream>

using namespace std;

void ordenaQS(int v[], int primero, int ultimo);
int ordenaMS(int a[], int low, int high);
int merge(int a[], int low, int high, int mid);
void impre(int v[], int n);

int main(int argc, char *argv[])
{   int A[10]={30,45,130,70,100,150,30,140,18,110};
    //ordenaQS(A,0,9);
    ordenaMS(A,0,9);
    impre(A,10);
    cout<<endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}

void ordenaQS(int v[], int primero, int ultimo)
{ int i,j,k,pivot,aux;
      if(ultimo>primero){
             pivot=v[ultimo];
             printf("\n -> %d  %d <-%4i",primero,ultimo,pivot);
             i=primero-1; j=ultimo;      
             for(;;){
                     while(v[++i]<pivot);
                     while(v[ --j ] >pivot);
                     if(i>=j)break;
                     aux=v[i];v[i]=v[j];v[j]=aux;      
             }// fin for
             aux=v[i];v[i]=v[ultimo];v[ultimo]=aux;
             for(k=0;k<10;k++)printf("\n a[%d]=%d",k,v[k]);
             printf("\n ------------------------------------");
             ordenaQS(v,primero,i-1);
             ordenaQS(v,i+1,ultimo);
             printf("\nRETORNO -> %d  %d <-",primero,ultimo);
      } //fin if 
}// fin ordena

int ordenaMS(int a[], int low, int high)
{   int mid;
    if(low<high){
                 mid=(low+high)/2;
                 cout<<"\n llamo a ordenaMS(1) con low= "<<low<<" mid= "<<mid<<endl;
                 ordenaMS(a,low,mid);
                 cout<<"\n llamo a ordenaMS(2) con mid+1= "<<mid+1<<" high= "<<high<<endl;
                 ordenaMS(a,mid+1,high);
                 merge(a,low,high,mid);
    }
    return(0);
}

int merge(int a[], int low, int high, int mid)
{   int i, j, k, c[20];
    cout<<"\n Estoy en merge() con low= "<<low<<" high= "<<high<<" mid= "<<mid<<endl;
    system("PAUSE");
    i=low; j=mid+1; k=low;
    
    while((i<=mid)&&(j<=high)){
         if(a[i]<a[j]){
                c[k]=a[i];
                k++; i++;
         }
         else{
                c[k]=a[j];
                k++; j++;
         }
    }
    while(i<=mid){ c[k]=a[i]; k++; i++; }
    while(j<=high){c[k]=a[j]; k++; j++; }
    for(i=low;i<k;i++) a[i]=c[i];
} 

void impre(int v[], int n)
{  
     for(int i=0;i<n;i++) cout<<endl<<v[i];
}
