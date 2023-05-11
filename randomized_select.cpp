#include <cstdio>
#include <cstdlib>
#include <ctime>

int partition(int *A, int p, int r)	{
    int i = p + rand() % (r - p + 1); 
    int temp = A[r]; A[r] = A[i]; A[i] = temp; 
    int x = A[r];
    i = p - 1;
    for(int j=p; j<r; j++)
        if(A[j] <= x)	{
            i++;
            temp = A[j]; A[j] = A[i]; A[i] = temp; 
        }
    temp = A[r]; A[r] = A[i+1]; A[i+1] = temp; 
    return i+1;
}


int recursiveSelect(int *A, int p, int r, int i)	{
    if(p == r) return A[p];
    int q = partition(A, p, r);
    int k = q - p + 1;
    if(i == k) return A[q];
    else if(i < k) return recursiveSelect(A, p, q-1, i);
    else return recursiveSelect(A, q+1, r, i-k);
}


int iterativeSelect(int *A, int n, int i)	{
    int low = 0, high = n - 1, mid, k;
    while(low < high)	{
        mid = partition(A, low, high);
        k = mid - low + 1;
        if(i == k) return A[mid];
        else if(i < k)
            high = mid - 1;
        else	{
            low = mid + 1;
            i -= k;
        }
    }
    return A[low];
}

int main()  {
    int *arr, N, i; 
    srand(time(NULL));

    printf("Enter size of array : ");
    scanf("%d", &N);
    arr = new int[N];
    printf("Enter %d integers :\n", N);
    for(i=0; i<N; i++)
        scanf("%d", &arr[i]);

    printf("Enter i (0 to exit): ");
    scanf("%d", &i);
    while(i > 0 && i <= N)    {
        printf("'%d'th order statistic :\n", i);
        printf("\tRecursive selection : %d\n", recursiveSelect(arr, 0, N-1, i));
        printf("\tIterative selection : %d\n", iterativeSelect(arr, N, i));

        printf("Enter i (0 to exit): ");
        scanf("%d", &i);
    }
    return 0;
}
