#include<stdio.h>
#include<stdlib.h>

struct point
{
    int x;
}a[20010];

int b[20010],ans;

int cmp(const void *a,const void *b)
{
    return (*(point *)a).x - (*(point *)b).x;
}

int main()
{
    int t,n,i,mid,start,end;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i].x);
        }
        qsort(a,n,sizeof(point),cmp);
        ans=0;
        b[0]=a[0].x;
        for(i=1;i<n;i++)
        {
            if(a[i].x<=b[ans])
            {
                ans++;
                b[ans]=a[i].x;
                continue;
            }
            start=ans;
            end=0;
            while(start>end)
            {
                mid=(start+end)/2;
                if(b[mid]>=a[i].x)
                    end=mid+1;
                else
                    start=mid;
            }
            b[end]=a[i].x;
        }
        printf("%d\n",ans+1);
    }
    return 0;
}


