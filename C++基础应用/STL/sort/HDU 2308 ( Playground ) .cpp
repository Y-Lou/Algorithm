#include <iostream>
#include <algorithm>
using namespace std;

int i, j, n;
double a[100];
int flag;
double sum = 0;
int main()
{
    while(scanf("%d", &n) != EOF && n)
    {
        for(i = 0; i < n; i++)
        {
            scanf("%lf", &a[i]);
        }
        sort(a, a+n);
        flag = 0;
        for(i = 1; i < n; i++)
        {
            sum = 0;
            for(j = 0; j < i; j++)
            {
                sum += a[j];
            }
            if(a[j] <= sum)
            {
                flag = 1;
                break;
            }
        }
        if(flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
}
