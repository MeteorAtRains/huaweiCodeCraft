#include "dijkstra.h"

//Dijkstra算法实现(基于邻接矩阵存储的带权有向图)
void Graph::Dijkstra(int vertex)
{
    //注意：下标表示结点
    int count = 0; //用于记录访问过的结点数目,后面用于控制循环
    bool find[max_size]; //用于标记已经找到最短路径的结点
    int pre[max_size]; //用于存放当前结点的前驱结点的最短路径
    int distance[max_size]; //用于存放当前结点的最短路径
    //初始化
    for(int i=0;i<max_size;i++)
        pre[i] = vertex; //开始所有结点的前驱结点都是开始的vertex
    for(int i=0;i<max_size;i++)
        distance[i] = adjacent[vertex][i]; //邻接矩阵中存放的权值就是距离
    for(int i=0;i<max_size;i++)
        find[i] = false; //初始化所有结点都没有找到最短路径
    find[vertex] = true;
    
    int v = vertex; //用来迭代顶点的变量
    int d; //用来表示距离
    while(count < max_size)
    {
        d = infinity;
        for(int i=0;i<max_size;i++) //找到离最初结点最短路径的一个未访问到的结点
        {
            if(!find[i] && distance[i]<d) 
            {
                d = diatance[i];
                v = i;
            }        
        }
        find[v] = true;
        //更新剩余的结点的前驱和最短距离
        for(int i=0;i<max_size;i++)
        {
            if(!find[i])
            {
                /*将上面找到的最短路径的结点作为起始点，
                *连到其他未访问过的结点上，
                *当比从最初结点到这个结点的路径短的时候，
                *就将上个结点作为前驱结点，更新一下即可*/
                d = distance[v] + adjacent[v][i];
                if(d < distance[i])
                {
                    pre[i] = v;
                    distance[i] = d;
                }
            }
        }
        count++;
    }
    
}
