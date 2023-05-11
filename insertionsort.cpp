 #include<iostream >
 using namespace std ;
 
 void insertionsort(int a[],int n)
 {
 	for(int j=1;j<n;j++)
 	{
 		int key = a[j];
 		int i=j-1;
 		while(j>0 && a[i]>key)
 		{
 			a[i+1]=a[i];
 			i--;
		}
		a[i+1]=key;
	}
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
 	insertionsort(a,21);
 	printarray(a,21);
 	return 0;
 }
