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


//vector���±��·�ڵ�idСһ
void ReadCross(const std::string &filename, std::vector<Cross> &Cs);

//vector[0]����car��Ϣ
void ReadCar(const std::string &filename, std::vector<Car> &Cars);

//�ҵ���·��Ϊid�����Ϊstartid�ĵ�·��Rs�е�λ��,�Ҳ�������-1
int findRoadID(int id, int startid, std::vector<Road> &Rs);



#endif
