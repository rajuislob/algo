#include <iostream>
#include<cmath>
using namespace std;

class counter{
	public:
		int n;
		int *a;
		counter(int size)
		{
			n=size;
			a=new int[n];
			
			int i=0;
			while(i<size)
			{
				a[i]=0;
				i++;
			}
		}
		void increment()
		{
			int i=0;
			while(i<n && a[i] ==1)
			{
				a[i]=0;
				i++;
			}
			if(i<n)
			{
				a[i]=1;
			}
		}
		void print()
		{
			int sum=0;
			int i=0;
			while(i<n)
			{
				sum+=a[i]*pow(2,i);
				i++;
			}
			cout<<"\n"<<sum<<"\n";
		}
};

int main()
{
	counter c(16);
	for(int i=0;i<5;i++)
		c.increment();
		
	c.print();
	return 0;
}
