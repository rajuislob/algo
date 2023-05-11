 #include<iostream >
 #include<cstdlib>
 using namespace std ;
 
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
 
 int randomized_partition(int a[],int p,int r)
 {
 	int i=rand() % (r + 1 - p) + p;
 	swap(a[r],a[i]);
 	return partition(a,p,r);
 }
 int randomized_quicksort(int a[],int p,int r)
 {
 	if(p<r)
 	{
 		int q=randomized_partition(a,p,r);
 		randomized_quicksort(a,p,q-1);
 		randomized_quicksort(a,q+1,r);
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
 	randomized_quicksort(a,1,21);
 	printarray(a,21);
 	return 0;
 }
