#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
  
 void printarray(int a[],int n)
 {
 	for(int i=0;i<n;i++)
 	{
 		cout<<a[i]<<",";
	 }
	 cout<<"\n";
 }
 
  int partition(int a[],int p,int r)
 {
 	int x=a[r];
 	int i=p-1;
 	for(int j=p;j<=r-1;j++)
 	{
 		if(a[j]<=x)
		{
		 	i++;
		 	swap(a[i],a[j]);
		}
	}
	swap(a[i+1],a[r]);
	return i+1;
 }
 

 void tail_recursion_quicksort(int a[],int p,int r)
 {
 	while(p<r)
 	{
 		int q=partition(a,p,r);
 		tail_recursion_quicksort(a,p,q-1);
 		p=q+1;
	 }
 }
 
int main()
{
   
  int a[]={1,2,3,6,5,4,9,8,7,12,13,1,9,1,7,1,6,1,4,1,20};
  printarray(a,21);
 	
 
    tail_recursion_quicksort(a, 1, 21);
 	printarray(a,21);
 
    return 0;
}
