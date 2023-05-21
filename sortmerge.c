#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define ll long long
#define ld long double
#define str string
#define ull unsigned long long
int a[10000000 + 10], coa[100000 + 10], n;

void Merge(int low, int mid, int high)
{
    int k = low, i = low, j = mid + 1;
    while(i <= mid && j <= high)
    {
        if(a[i] <= a[j])
        {
            coa[k++] = a[i++];
        }
        else
        {
            coa[k++] = a[j++];
        }
    }
    while(i <= mid)
    {
        coa[k++] = a[i++];
    }
    for(int i = low; i <= high; i++)
    {
        a[i] = coa[i];
    }
}

void mergesort(int low, int high)
{
    if (high == low)
    {
        return;
    }
    int mid = (low + ((high - low) >> 1));
    mergesort(low, mid);
    mergesort(mid + 1, high);
    Merge(low, mid, high);
}

int main()
{
    n = 1000;
    while(n <= 10000000)
    {
        for(int i = 0; i < n; i++)
        {
            a[i] = abs(rand()) % n;
        }
        time_t begin = clock();
        mergesort(0, n - 1);
        time_t end = clock();
        printf("%lld, ", end - begin);
        n += 100000;
    }
    return 0;
}
/**


**/
