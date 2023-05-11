 #include<iostream >
 using namespace std ;
 
 void countingsort(int a[],int b[],int n,int k)
 {
 	int *c=new int[k];
 	for(int i=0;i<k;i++)
 	{
 		c[i]=0;
	}
	for(int j=0;j<n;j++)
	{
		c[a[j]]=c[a[j]]+1;
	}
	for(int i=1;i<k;i++)
	{
		c[i]=c[i]+c[i-1];
	}
	for(int j=0;j<n;j++)
	{
		b[c[a[j]]-1]=a[j];
		c[a[j]]--;
	}
 	
 }
int max_ele(int a[],int n)
 {
 	int max=INT_MIN;
 	for(int i=0;i<n;i++)
 	{
 		if(max<a[i])
 		{
 			max=a[i];
		 }
	 }
	 return max;
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
 	int b[21];
 	int k=max_ele(a,21);
 	printarray(a,21);
 	countingsort(a,b,21,k);
 	printarray(a,21);
 	return 0;
 }
