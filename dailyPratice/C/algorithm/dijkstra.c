#include<stdio.h>
#include<stdlib.h>
#define MAX 1000000000


static int a[1000][1000];
static int d[1000];//d��ʾĳ�ض��߾���
static int p[1000];//p��ʾ���ñ߾���
static int i,j,k;
static int m;//m�������
static int n;//n�������
int main()
{
    scanf("%d %d",&n,&m);
    int min;
    int x,y,z;
    for(i=1;i<=m;i++)
    {
        scanf("%d %d %d",&x,&y,&z);
        a[x][y]=z;
        a[y][x]=z;
    }
    for(i=1;i<=n;i++)
        d[i]=MAX;
    d[1]=0;
    for(i=1;i<=n;i++)
    {
        min=MAX;
        for(j=1;j<=n;j++)
            if(!p[j]&&d[j]<min)
            {
                min=d[j];
                k=j;
            }
        p[k]=j;
        for(j=1;j<=n;j++)
            if(a[k][j]!=0&&!p[j]&&d[j]>d[k]+a[k][j])
                d[j]=d[k]+a[k][j];
    }
    for(i=1;i<n;i++)
        printf("%d->",p[i]);
    printf("%d\n",p[n]);
    return 0;
}