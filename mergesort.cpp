 #include<iostream >
 using namespace std ;
  void printarray(int a[],int n)
 {
 	for(int i=0;i<n;i++)
 	{
 		cout<<a[i]<<",";
	 }
	 cout<<"\n";
 }
 
 
 void merge(int a[],int p,int q,int r)
 {
 	int n1=q-p+1;
 	int n2=r-q;
 	int *L=new int[n1+1];
 	int *R=new int[n2+1];
 	for(int i=0;i<n1;i++)
 	{
 		L[i]=a[p+i];
	}
	for(int j=0;j<n2;j++)
	{
		R[j]=a[q+j+1];
	}
	L[n1]=INT_MAX;
	R[n2]=INT_MAX;
	int i=0;
	int j=0;
	for(int k=p;k<=r;k++)
	{
		if(L[i]<=R[j])
		{
			a[k]=L[i];
			i++;
		}
		else
		{
			a[k]=R[j];
			j++;
		}
	}
 }
 
 
void mergesort(int a[],int p,int r)
{
	if(p<r)
	{
		int q=(p+r)/2;
		mergesort(a,p,q);
		mergesort(a,q+1,r);
		merge(a,p,q,r);
	}
 } 
 
 
 
 
 
 
 
 
 
 int main()
 {
 	int a[]={1,2,3,6,5,4,9,8,7,12,13,1,9,1,7,1,6,1,4,1,20};
 	printarray(a,21);
 	mergesort(a,0,20);
 	printarray(a,21);
 	return 0;
 }
