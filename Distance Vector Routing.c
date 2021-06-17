#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define INTMAX 99999
int main()
{
	int **adj, **cost, **next, n, i, j, k, e, u, v, c;
	printf("Enter the no of routers in the network : ");
	scanf("%d",&n);

	adj=(int**)malloc(n*sizeof(int*));
	for(i=0;i<n;i++)
		adj[i]=(int*)malloc(n*sizeof(int));

	cost=(int**)malloc(n*sizeof(int*));
	for(i=0;i<n;i++)
		cost[i]=(int*)malloc(n*sizeof(int));

	next=(int**)malloc(n*sizeof(int*));
	for(i=0;i<n;i++)
		next[i]=(int*)malloc(n*sizeof(int));

	for(i=0;i<n;i++)
	{
	    adj[i][i]=0;
		for(j=i+1;j<n;j++)
		{
			adj[i][j]=999;
			adj[j][i]=999;
		}
	}

	printf("Enter the no of links : ");
	scanf("%d",&e);
	printf("Enter the source, destination & cost of each link one by one\n");
	for(i=0;i<e;i++)
	{
		printf("Source-> ");
		scanf("%d",&u);
		printf("Destination-> ");
		scanf("%d",&v);
		printf("Cost-> ");
		scanf("%d",&c);
		adj[u][v]=c;
		adj[v][u]=c;
	}

	for(i=0;i<n;i++)
		for(j=i;j<n;j++)
		{
			cost[i][j]=adj[i][j];
			next[i][j]=i;
			cost[j][i]=adj[j][i];
			next[j][i]=j;
		}

	for(i=0;i<n;i++)
        for(j=i+1;j<n;j++)
            for(k=0;k<n;k++)
			{
				if(k==i || k==j)
					continue;
				c=cost[j][k]+cost[k][i];
				if(c<=cost[i][j])
				{
					if(adj[j][k]!=999)
					{
						cost[j][i]=c;
						next[j][i]=k;
					}
					if(adj[i][k]!=999)
					{
						cost[i][j]=c;
						next[i][j]=k;
					}
				}
			}

	printf("COST MATRIX\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%9d",cost[i][j]);
		printf("\n");
	}

	printf("NEXT MATRIX\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%3d",next[i][j]);
		printf("\n");
	}

	return 0;
}
