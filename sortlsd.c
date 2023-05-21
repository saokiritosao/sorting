#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<time.h>
#define ll long long
#define ld long double
#define str string
#define ull unsigned long long

int n, a[10000010], b[10000010], c[10000010];

int digit(int a, int b)
{
    for(int i = 1; i < b; i++)
    {
        a /= 10;
    }
    return a % 10;
}

void radixSort()
{
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j <= 10 - 1; j++)
            c[j] = 0;
        for(int j = 0; j <= n - 1; j++)
        {
            int d = digit(a[j], i);
            c[d]++;
        }
        int count = 0;
        for(int j = 0; j <= 10 - 1; j++)
        {
            int tmp = c[j];
            c[j] = count;
            count += tmp;
        }
        for(int j = 0; j <= n - 1; j++)
        {
            int d = digit(a[j], i);
            b[c[d]] = a[j];
            c[d]++;
        }
        for(int j = 0; j <= n - 1; j++)
            a[j] = b[j];
    }
}
int main()
{
    n = 1000;
    while(n <= 10000000)
    {
        time_t begin = clock();
        for(int i = 0; i < n; i++)
        {
            a[i] = abs(rand()) % n;
        }
        radixSort();
        time_t end = clock();
        printf("%lld, ", end - begin);
        n += 100000;
    }
    return 0;
}
