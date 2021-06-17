#include<stdio.h>
int max(int a, int b)
{
    return ((a>b) ? a : b);
}
int knapsack_0_1(int n,int c,int *v,int *w)
{
    int p[n+1][c+1],i,j;
    for(i=0;i<=n;i++)
        p[i][0]=0;
    for(i=0;i<=c;i++)
        p[0][i]=0;

        for(i=0;i<=n;i++)
        {
            printf("\t");
            for(j=0;j<=c;j++)
                printf("%d\t",p[i][j]);
            printf("\n");
        }

    for(i=1;i<=n;i++)
        for(j=1;j<=c;j++)
        {
            if(w[n-1]>j)
                p[i][j]=p[i-1][j];
            else
                p[i][j]=max(p[i-1][j] , v[i] + p[i-1][ j-w[i] ] );
        }
    for(i=0;i<=n;i++)
    {
        printf("\t");
        for(j=0;j<=c;j++)
            printf("%d\t",p[i][j]);
        printf("\n");
    }
    return p[n+1][c+1];
}
int main()
{
    int n,*w,*v,c,val,i;
    printf("\nEnter the no of items : ");
    scanf("%d",&n);
    w=(int *)malloc(n*sizeof(n));
    v=(int *)malloc(n*sizeof(n));
    printf("\nEnter the value & weight of the items ...\n");
    for(i=0;i<n;i++)
    {
        printf("\nValue : ");
        scanf("%d",&v[i]);
        printf("\nWeight : ");
        scanf("%d",&w[i]);
        printf("\n\n");
    }
    printf("\nEnter the capacity of the knapsack : ");
    scanf("%d",&c);;

    for(i=0;i<n;i++)
        printf("%d  %d\n",w[i],v[i]);

    val = knapsack_0_1(n,c,v,w);
    printf("\nMaximum value can be stored in the knapsack : %d",val);
}
