/* 	
*	判题器 的基础数据结构
*/

#ifndef _LV_IDENTIFYBASIC_H_
#define _LV_IDENTIFYBASIC_H_

#include <bits/stdc++.h>

#include "Road.h"
#include "Car.h"
#include "Cross.h"
#include "Trajectory.h"

class RoadsStatus{
public://成员函数
	RoadsStatus(const vector<Road>& roads);
	RoadsStatus();
	~RoadsStatus();
	
	void clear();
	Road* find(int roadId);
	
private://成员函数
	
public://成员数据
	vector<Road> roadsList_;
private://私有成员数据
	
};

#endif
