#include <iostream>
using namespace std;
int n, m;
struct point
{
    int pri;
    int wei;
}p[100000];
int k;
int f[2001];
int i, j;
int a, b, c;
int Max(int a, int b)
{
    return a > b ? a : b;
}
int cmp(const void *a, const void *b)
{
    point *c = (point *)a;
    point *d = (point *)b;
    return c->pri - d->pri;
}
int t, v;
int main()
{
    scanf("%d", &t);
    while(t--)
    {
        k = 0;
        scanf("%d%d", &n, &m);
        for(i = 0;i < m; i++)
        {
            scanf("%d%d%d", &a, &b, &c);
            for(j = k; j < k+c; j++)
            {
                p[j].pri = a;
                p[j].wei = b;
            }
            k = k + c;
        }
        qsort(p, k, sizeof(point), cmp);
        //for(i = 0;i < k; i++)
        //    printf("%d %d\n", p[i].pri, p[i].wei);
        if(p[0].pri > n)
        {
            printf("0\n");
            continue;
        }
        memset(f, 0, sizeof(f));

        for(i = 0; i < k; i++)
        {
            for(v = n; v >= 0; v--)
            {
                if(v - p[i].pri >= 0)
                    f[v] = Max(f[v], f[ v - p[i].pri ] + p[i].wei);
            }
        }
        printf("%d\n", f[n]);



    }
}

