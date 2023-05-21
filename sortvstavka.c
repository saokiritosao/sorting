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
    int ch, l;
    for(int i = 1; i < n; i++)
    {
        ch = a[i];
        l = i - 1;
        while(l >= 0 && a[l] > ch)
        {
            a[l + 1] = a[l];
            l = l - 1;
        }
        a[l + 1] = ch;
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
            a[i] = abs(rand()) % n;
        }
        sortq();
        time_t end = clock();
        printf("%lld, ", (end - begin) * 100);
        n += 1000;
    }
    return 0;
}
