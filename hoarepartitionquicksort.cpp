#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
 
#define N 15
 

int partition(int a[], int p, int r)
{
    int q = a[p];
    int i = p - 1;
    int j = r + 1;
    while (1)
    {
        do {
            i++;
        } while (a[i] < q);
 
        do {
            j--;
        } while (a[j] > q);
 
        if (i >= j) {
            return j;
        }
 
        swap(a[i], a[j]);
    }
}
 

void quicksort(int a[], int p, int r)
{

    if (p >= r) {
        return;
    }
 

    int q = partition(a, p, r);
 
    
    quicksort(a, p, q);
 

    quicksort(a, q + 1, r);
}


 
 void printarray(int a[],int n)
 {
 	for(int i=0;i<n;i++)
 	{
 		cout<<a[i]<<",";
	 }
	 cout<<"\n";
 }
 
 
 
int main()
{
   
  int a[]={1,2,3,6,5,4,9,8,7,12,13,1,9,1,7,1,6,1,4,1,20};
  printarray(a,21);
 	
 
    quicksort(a, 0, 20);
 	printarray(a,21);
 
    return 0;
}
