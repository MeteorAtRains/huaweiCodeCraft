#ifndef _LV_SHORTESTPATHDIJKSTRA_H_
#define _LV_SHORTESTPATHDIJKSTRA_H_

#include <bits/stdc++.h>

#include "AdjMatrixDirNetwork.h"
#include "Trajectory.h"
//#include <iostream>
using namespace std;
using namespace lv_trajectory;

void ShortestPathDijkstra(AdjMatrixDirNetwork network,int startVex);
int ShortestPathDijkstra(AdjMatrixDirNetwork &network,int startVex,int endVex,Trajectory& trajectory);

#endif
