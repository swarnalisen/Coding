#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
int matrix_chain_order(int* p,int n,int** s)
{
    int i,j,k,l,m[n][n],no_of_op;
    for(i=0;i<n;i++)
        m[i][i]=0;

    for(l=1;l<n;l++)
    {
        for(j=l;j<n;j++)
        {
            i=j-l;
            m[i][j]=INT_MAX;
            for(k=i;k<j;k++)
            {
                no_of_op=m[i][k] + m[k+1][j] + p[i]*p[k+1]*p[j+1];
                if(no_of_op < m[i][j])
                {
                    m[i][j]=no_of_op;
                    s[i][j]=k;
                }
            }
        }
    }
    return m[0][n-1];
}

void print_sequence(int** s,int first,int last)
{
    int k;
    if(first==last)
        printf(" %d ",first+1);
    else
    {
        k=s[first][last];
        printf("( ");
        print_sequence(s,first,k);
        print_sequence(s,k+1,last);
        printf(") ");
    }
}

int main()
{
    int n,i,no_of_op,*order, **seq;;
    printf("\nEnter the no of matrices : ");
    scanf("%d",&n);
    order=(int *)malloc((n+1)*sizeof(int));
    seq=(int **)malloc(n*sizeof(int *));
    for(i=0;i<n;i++)
        seq[i]=(int *)malloc(n*sizeof(int ));
    printf("\nEnter the order of the matrices ..\n");
    for(i=0;i<=n;i++)
        scanf("%d",&order[i]);
    no_of_op=matrix_chain_order(order,n,seq);
    printf("\n\nMinimum no of operations for the multiplication : %d\n\n",no_of_op);
    printf("Order  :: ");
    print_sequence(seq,0,n-1);

    return 100;
}
