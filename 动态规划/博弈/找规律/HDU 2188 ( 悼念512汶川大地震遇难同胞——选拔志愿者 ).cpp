#include <iostream>
using namespace std;
struct point
{
    int w;
    int v;
}p[10000];
int i, j, a[10000];
int k, t, n, m;

int cmp(const void *a, const void *b)
{
    point *c = (point *)a;
    point *d = (point *)b;
    return c->v - d->v;
}
double sum = 0;
int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &n, &m);
        if(n%(m+1) == 0)
            printf("Rabbit\n");
        else
            printf("Grass\n");
    }
    return 0;
}


