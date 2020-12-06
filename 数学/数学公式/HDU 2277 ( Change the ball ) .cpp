/*#include <iostream>

using namespace std;

struct point {
    int num;
    int time;
}po[100001], pu[100001];


int cmp(const void *a, const void *b) {
    point *c = (point *)a;
    point *d = (point *)b;
    return c->num - d->num;
}

int topo, topu;
int n, m, i, j;
int hash[100001];
char str[10];

int main() {
    while(scanf("%d", &n) != EOF) {
        topo = topu = 0;
        for(i = 0; i < n; i++) {
            scanf("%s %d", str, &m);

            if(strcmp( str, "Push") == 0) {
                pu[ topu ].num = m;
                pu[ topu++ ].time = i;
            }else {
                po[ topo ].num = m;
                po[ topo++ ].time = i;
            }
        }

        qsort(pu, topu, sizeof(point), cmp);

        memset(hash, 0, sizeof(hash));

        int start = -1;

        for(i = 0; i < topo; i++) {


            int flag = 0;
            for(j = start + 1; j < topu; j ++) {
                
                if(po[i].num < pu[j].num)
                    break;

                if(hash[j])
                    continue;

                if(!flag && po[i].time > pu[j].time
                    && po[i].num >= pu[j].num) {
                    start = j - 1;
                    flag = 1;
                }
            }

            if(!flag)
                printf("No Element!\n");
            else {
                for(j = j - 1; j >= start + 1; j--) {

                    if(hash[j]) continue;

                    if(po[i].time > pu[j].time
                        && po[i].num >= pu[j].num) {
                        hash[j] = 1;
                        printf("%d\n", pu[j].num);
                        break;
                    }
                }
            }
        }

        puts("");

    }
}*/

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int a[4];
int i;

int Min(int a, int b) {
    return a < b ? a : b;
}

int Mi(int a, int b, int c) {

    int T = 99999;
    if(a == b) {
        if(a < T)
            T = a;
    }

    if(a > c && (a - c) % 3 == 0) {
        if(a < T)
            T = a;
    }

    return T;
}
int main() {
    while(scanf("%d %d %d", &a[0], &a[1], &a[2]) != EOF) {


        if(
            (a[0] - a[2]) % 3 == 0 
            || (a[1] - a[2]) % 3 == 0 
            || (a[0] - a[1]) % 3 == 0) {

            int M = 999999;
            M = Min(M, Mi(a[0], a[1], a[2]) );
            M = Min(M, Mi(a[0], a[2], a[1]) );

            M = Min(M, Mi(a[1], a[0], a[2]) );
            M = Min(M, Mi(a[1], a[2], a[0]) );

            M = Min(M, Mi(a[2], a[1], a[0]) );
            M = Min(M, Mi(a[2], a[0], a[1]) );

            printf("%d\n", M);
        }else
            printf("):\n");
    }
}

