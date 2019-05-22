/* 	
*	判题器 的 操作类
*/

#ifndef _LV_IDENTIFY_H_
#define _LV_IDENTIFY_H_

#include <bits/stdc++.h>

#include "IdentifyBasic.h"
#include "Road.h"
#include "Car.h"
#include "Cross.h"
#include "Trajectory.h"

using namespace lv_trajectory;

class Identify{
public://成员函数
	Identify(vector<Car>& cars,vector<Road>& roads,vector<Cross>& crosses,vector<Trajectory>& trajectorys);
	Identify();
	~Identify();

private://成员函数
	
public://成员数据
	RoadsStatus roadsStatus;
private://成员数据


};
#endif
