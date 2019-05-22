#ifndef ROAD_H
#define ROAD_H

/*
#include<iostream>
#include<vector>
*/
#include <bits/stdc++.h>

class Road{

private:
	int ID;
	int Length;
	int Vmax;
	int LaneNum;
	int StartID;
	int EndID;
	bool DoubleDirect;
	bool* step;

public:
	//构造函数
	Road(int ID, int Length, int Vmax, int LaneNum, int StartID, int EndID, bool DoubleDirect)
		:ID(ID),
		Length(Length),
		Vmax(Vmax),
		LaneNum(LaneNum),
		StartID(StartID),
		EndID(EndID),
		DoubleDirect(DoubleDirect)
	{
		step = new bool(Length);
		for(int i = 0; i < Length; i++)
		{
			step[i] = false;
		}	 
	}
	bool operator == (const Road& roadFindID);
	Road operator = (const Road roadFindID);
	Road()
	{	
		//step = new bool(Length);
	}
	//析构函数
	~Road()
	{
		delete [] step;
	}

	//返回道路id
	int id() const { return ID; }
	void setId(int id)  { ID=id; }

	//返回道路长度
	int length() const { return Length; }

	//返回道路限速
	int vmax() const { return Vmax; }

	//返回车道数目
	int lanenum() const { return LaneNum; }

	//返回道路的起点
	int startid() const { return StartID; }

	//返回道路的终点
	int endid() const { return EndID; }

	//返回是否双车道
	bool twoways() const { return DoubleDirect; }

	// 输出道路参数
	void show() const;
};


#endif
