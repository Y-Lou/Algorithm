#include <iostream>

using namespace std;
char ch[201];
int i, j;
int dp[201][1001];
int pre[2][1001], tp, Min , k;
int main()
{

    for(i = 0; i < 2; i++)
    {
        for(j = 0; j <= 1000; j++)
        {
            pre[i][j] = (j - i * 1000) * (j - i * 1000);
        }
    }
    while(scanf("%s", ch) !=EOF)
    {
        int len = strlen(ch);
        for(i = 1; i <= len; i++)
        {
            for(j = 0; j <= 1000; j ++)
            {
                Min = 999999999;
                for(k = 0; k <= j; k++)
                {
                    tp = dp[i-1][k] + pre[ ch[i - 1] - '0' ][k];
                    if(tp < Min)
                        Min = tp;
                }
                dp[i][j] = Min;
            }
        }
        Min = 999999999;
        for(i = 0; i <= 1000; i++)
            if(dp[len][i] < Min)
                Min = dp[len][i];
        printf("%.3lf\n", Min/1000000.0);
    }
}
