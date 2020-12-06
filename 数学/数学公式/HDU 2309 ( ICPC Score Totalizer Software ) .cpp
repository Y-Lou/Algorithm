#include <iostream>

using namespace std;

int main()
{
    int n, b, Max, Min, i;
    while(scanf("%d", &n) != EOF && n)
    {
        int sum  = 0;
        Max = -1;
        Min = -1;
        
        for(i = 0; i < n; i++)
        {
            scanf("%d", &b);
            sum += b;
            if(Max == -1 || b > Max)
                Max = b;
            if(Min == -1 || b < Min)
                Min = b;
        }
        sum -= (Max + Min);
        printf("%d\n", sum/(n-2));
        
    }
}

