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
    for(int i = 0; i < n; i++)
    {
        int mp = i;
        for(int j = i + 1; j < n; j++)
            if(a[mp] > a[j])
                mp = j;
        int tmp = a[mp];
        a[mp] = a[i];
        a[i] = tmp;
    }
}

int main()
{
    n = 1000;
    while(n <= 100000)
    {
        for(int i = 0; i < n; i++)
        {
            a[i] = abs(rand()) % n;
        }
        time_t begin = clock();
        sortq();
        time_t end = clock();
        printf("%lld, ", (end - begin) * 100);
        n += 1000;
    }
//    for(int i = 1; i <= n; i++)
//        printf("%d ", a[i]);
    return 0;
}
