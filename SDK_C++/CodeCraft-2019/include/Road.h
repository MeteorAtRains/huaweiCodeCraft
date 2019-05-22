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
	//���캯��
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
	//��������
	~Road()
	{
		delete [] step;
	}

	//���ص�·id
	int id() const { return ID; }
	void setId(int id)  { ID=id; }

	//���ص�·����
	int length() const { return Length; }

	//���ص�·����
	int vmax() const { return Vmax; }

	//���س�����Ŀ
	int lanenum() const { return LaneNum; }

	//���ص�·�����
	int startid() const { return StartID; }

	//���ص�·���յ�
	int endid() const { return EndID; }

	//�����Ƿ�˫����
	bool twoways() const { return DoubleDirect; }

	// �����·����
	void show() const;
};


#endif
