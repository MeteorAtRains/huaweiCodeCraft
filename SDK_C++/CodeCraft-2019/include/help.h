#ifndef HELP_H
#define HELP_H

/*
#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<cassert>
#include<vector>
*/

#include <bits/stdc++.h>

#include"Cross.h"
#include"Road.h"
#include"Car.h"


void ReadRoad(const std::string &filename,std::vector<Road> &Rs);


//vector的下标比路口的id小一
void ReadCross(const std::string &filename, std::vector<Cross> &Cs);

//vector[0]不存car信息
void ReadCar(const std::string &filename, std::vector<Car> &Cars);

//找到道路名为id，起点为startid的道路在Rs中的位置,找不到返回-1
int findRoadID(int id, int startid, std::vector<Road> &Rs);



#endif
