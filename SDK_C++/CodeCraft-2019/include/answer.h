#ifndef ANSWER_H
#define ANSWER_H

//#include"iostream"
//#include<string>
//#include<vector>

#include <bits/stdc++.h>

#include "help.h"
#include"TrafficG.h"
#include"b_dijkstra.h"
#include "Car.h"
#include "Road.h"
#include "Cross.h"
#include "Trajectory.h"
#include "Scheduling.h"

using std::vector;

using namespace lv_trajectory;
//using namespace lv_scheduling;

void answerout(std::string carPath,std::string  roadPath,std::string crossPath,std::string  answerPath);
//void run(vector<Car>& cars,vector<Road>& roads,vector<Cross>& crosses,vector<Trajectory>& trajectorys);

#endif
