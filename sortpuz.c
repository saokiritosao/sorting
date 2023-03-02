#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<time.h>
#define ll long long
#define ld long double
#define str string
#define ull unsigned long long

int n, a[1000010];

void sortq()
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(a[j] > a[j + 1])
            {
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
}

int main()
{
    n = 1000;
    while(n <= 100000)
    {
        time_t begin = clock();
        for(int i = 0; i < n; i++)
        {
            a[i] = n - i + 1;
        }
        sortq();
        time_t end = clock();
        printf("%lld, ", (end - begin) * 100);
        n += 1000;
    }
//    for(int i = 1; i <= n; i++)
//        printf("%d ", a[i]);
    return 0;
}
