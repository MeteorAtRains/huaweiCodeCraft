#ifndef _LV_DJIKSTRA_H_
#define _LV_DJIKSTRA_H_

#include <bits/stdc++.h>

const int infinity = 1000; //定义无穷常量，用1000表示

//定义图结构，采用邻接矩阵存储形式
template <int max_size>
class Graph
{
    private:
/*邻接矩阵，对于有向网络（带权的有向图）其中存放的是权值*/
        int adjacent[max_size][max_size]; 
    public:
        void Dijkstra(int); //Dijkstra算法,求最短路径
};


#endif
