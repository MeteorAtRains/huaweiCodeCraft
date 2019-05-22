#ifndef ADJMATRIX_DIR_NETWORK_H
#define ADJMATRIX_DIR_NETWORK_H

#include <bits/stdc++.h>

#include "Road.h"
#include "Cross.h"

//#include <iostream>
#define DEFAULT_INFINITY 500
#define DEFAULT_SIZE 10
using namespace std;

enum VisitStatus{VISIT,UNVISIT};

class AdjMatrixDirNetwork    //
{
public:
	AdjMatrixDirNetwork(int vertexMaxNum=DEFAULT_SIZE,int infinite=DEFAULT_INFINITY);  //Ĭ�Ϲ��캯��������һ����ͼ
	AdjMatrixDirNetwork(int *vexs,int vertexNum,int vertexMaxNum=DEFAULT_SIZE,int infinite=DEFAULT_INFINITY);
	AdjMatrixDirNetwork(AdjMatrixDirNetwork& netRaw);
	AdjMatrixDirNetwork& operator=(AdjMatrixDirNetwork& netRaw);
	friend AdjMatrixDirNetwork& operator / (AdjMatrixDirNetwork& lhd, int x);
//### LV ## 2019 03 20  ##
	//AdjMatrixDirNetwork(vector<Cross>& vexsRoads,int vertexNum,int vertexMaxNum=DEFAULT_SIZE,int infinite=DEFAULT_INFINITY);
	
	
//### end	
	
	~AdjMatrixDirNetwork();
	void InsertArc(int vex1,int vex2,int weight);   //����Ϸ���vex1��vex2С��vexNum��vex1!=vex2��������ƽ�б�
	int GetElem(int vex);  
	int GetVexNum();
	int GetArcNum();
	int GetWeight(int vex1,int vex2);
	int GetInfinity();
	int FirstAdjVex(int vex);   //���ض���vex�ĵ�һ���ڽӶ������ţ���û���򷵻�-1
	int NextAdjVex(int vex,int vex2);   //���ض���vex�������vex2����һ���ڽӶ������ţ���û���򷵻�-1
	void Display();
	VisitStatus GetTag(int vex);   //����Ϸ�
	int SetTag(int vex,VisitStatus _tag);  //����״̬
//	void changeToTime();

private:
	int *vertexes;
	VisitStatus *tag;
	int **arcs;
	int vexNum,vexMaxNum,arcNum;
	int infinity;
};

#endif
