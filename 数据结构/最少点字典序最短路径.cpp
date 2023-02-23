#include <bits/stdc++.h>
using namespace std;
//用邻接表存储的图
int b[40000], path[40000], so[40000], dist[40000], route[40000];
typedef struct Edge //边结点的结构
{
	int VerAdj; //邻接顶点序号
	int cost;	//边的权值
	Edge *link; //指向下一个边结点的指针
} * ptrEdge;
ptrEdge arr[20010];
void initial(ptrEdge *arr, int num) //初始化
{
	for (int i = 0; i < num; i++)
	{
		arr[i] = (ptrEdge)malloc(sizeof(struct Edge));
		arr[i]->VerAdj = i;
		arr[i]->cost = 0;
		arr[i]->link = NULL;
	}
}
void insert(ptrEdge s, int pos, int loc)
{
	ptrEdge tmp = (ptrEdge)malloc(sizeof(struct Edge));
	tmp->cost = loc;
	tmp->VerAdj = pos;
	if (s->link == NULL) //无邻接节点
	{
		s->link = tmp;
		tmp->link = NULL;
		return;
	}
	tmp->link = s->link; 
	s->link = tmp; //插入两个之间
}
void DshortPath(ptrEdge *arr, int n, int v, int *dist, int *path)
{
	//计算v到其他点最小路径
	for (int i = 0; i < n; i++)
	{
		path[i] = -1;
		dist[i] = 2147483647;
		so[i] = 0;
		route[i] = 2147483647;
	}
	route[0]=1;
	dist[v] = 0;
	so[v] = 1;
	ptrEdge p = arr[v]->link;
	int u = v;
	//求从初始顶点v到其他顶点的最短路径
	for (int j = 0; j < n; j++)
	{
		/*for(int i=0;i<n;i++)
		printf("%d ",route[i]);
		printf("\n");*/
	/*cout<<"vist:";for(int i=0;i<n;i++)cout<<so[i]<<" ";cout<<endl;
      cout<<"dist:";for(int i=0;i<n;i++)cout<<dist[i]<<" ";cout<<endl;
      cout<<"path:";for(int i=0;i<n;i++)cout<<path[i]<<" ";cout<<endl;
      cout<<"node:";for(int i=0;i<n;i++)cout<<route[i]<<" ";cout<<endl;
printf("\n");*/
		while (p != NULL)
		{
			int k = p->VerAdj;
			int num=route[u]+1;
			if (so[k] != 1 && dist[u] + p->cost < dist[k])
			{
				dist[k] = dist[u] + p->cost;
				path[k] = u;
				route[k] = num;
			}
			else if (so[k] != 1 && dist[u] + p->cost == dist[k] && route[k] > num)
			{
				// dist[k]=dist[u]+p->cost;
				path[k] = u;
				route[k] = num;
			}
			else if(so[k] != 1 && dist[u] + p->cost == dist[k] && route[k] == num)
			{
				int path1[20050],path2[20050];
			    int i=1,j=1;
			    int m=k,lkc=u;
			    k=path[k];
			    while(k!=0)
			    {
			    	path1[i++]=k;
			    	k=path[k];
				}
				while(u!=0)
				{
					path2[j++]=u;
			    	u=path[u];
				}
				/*while(i--)
				{
					printf("%d ",path1[i]);
				}
				printf("\n");
				while(j--)
				{
					printf("%d ",path2[j]);
				}*/
				i--;
				for(int p=i;p>0;p--)
				{
					//printf("%d ",i);
					//printf("%d %d ",path1[p],path2[p]);
					if(path1[p]>path2[p])
					{
						path[m]=lkc;
						//printf("%d %d ",m,lkc);
						break;
					}
					else if(path1[p]<path2[p])
					break;
				}
		    }
			p = p->link;
		}
		int idist = 2147483647;
		for (int i = 0; i < n; i++)
		{
			if (dist[i] < idist && so[i] == 0)
			{
				idist = dist[i];
				u = i;
			}
		}//找最小边 
		so[u] = 1;
		p = arr[u]->link;
	}
}
void print(int n) //输出
{
	for (int i = 1; i < n;)
	{
		int j = i, o = 0;
		while (j != 0)
		{
			b[o++] = j;
			j = path[j];
			if(j==-1)goto flag; 
		}
		printf("0");
		for (int p = o - 1; p >= 0; p--)
		{
			printf("->%d", b[p]);
		}
		// memset(b,0,sizeof(b));
		printf("\n");
		flag:
			i++;
	}
}
int main()
{
	int n, e;
	cin >> n >> e;
	initial(arr, n);
	while (e--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		insert(arr[a], b, c);
	}
	DshortPath(arr, n, 0, dist, path);
	print(n);
	return 0;
}
