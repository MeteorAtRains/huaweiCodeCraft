#ifndef _LV_SCHEDULING_H_
#define _LV_SCHEDULING_H_

#include <bits/stdc++.h>

#include "common.h"
#include "Car.h"
#include "Road.h"
#include "Cross.h"
#include "Trajectory.h"
#include "Status.h"
#include "ShortestPathDijkstra.h"
#include "AdjMatrixDirNetwork.h"
#include "IdentifyBasic.h"

using namespace lv_trajectory;

using std::vector;

//#define std::vector<T> V<T> 




void run(vector<Car>& cars,vector<Road>& roads,vector<Cross>& crosses,vector<Trajectory>& trajectorys);
void findRoad(vector<Road>& roads,Trajectory& trajectorys);
//void run(V<Car>& cars,V<Road>& roads,V<Cross>& crosses,V<Trajectory>& trajectorys);


#endif
