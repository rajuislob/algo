#include<iostream>

using namespace std;

int maxele(int a[],int n)
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

void countsort(int array[], int size, int place) {
  const int max = 10;
  int output[size];
  int count[max];

  for (int i = 0; i < max; ++i)
    count[i] = 0;

  for (int i = 0; i < size; i++)
    count[(array[i] / place) % 10]++;

  for (int i = 1; i < max; i++)
    count[i] += count[i - 1];
    
  for (int i = size - 1; i >= 0; i--) 
  {
    output[count[(array[i] / place) % 10] - 1] = array[i];
    count[(array[i] / place) % 10]--;
  }

  for (int i = 0; i < size; i++)
    array[i] = output[i];
}

//sorting from lsb to msb 
void radixsort(int array[], int size) {
  int max = maxele(array, size);

  for (int place = 1; max / place > 0; place *= 10)
    countsort(array, size, place);
}

int main()
{
	int array[11]={3,1,2,6,4,5,9,7,8,11,10};
	cout<<"array initially \n";
	for(int i=0;i<11;i++)
	{
		cout<<array[i]<<"	";
	}
	cout<<"\n array after radix sort\n";
	radixsort(array,11);
	for(int i=0;i<11;i++)
	{
		cout<<array[i]<<"	";
	}
}
