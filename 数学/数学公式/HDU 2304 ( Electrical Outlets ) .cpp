#include <iostream>
using namespace std;

int t;
int n, sum, a;
int main()
{
   scanf("%d", &t);
   while(t--)
   {
       scanf("%d", &n);
       sum = 1-n;
       while(n--)
       {
           scanf("%d", &a);
           sum += a;
       }
       printf("%d\n", sum );
   }
}
