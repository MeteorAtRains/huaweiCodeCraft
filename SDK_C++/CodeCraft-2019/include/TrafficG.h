#ifndef TRAFFICG_H
#define TRAFFICG_H

/*
#include<iostream>
#include<vector>
*/

#include <bits/stdc++.h>
#include"help.h"

class TrafficG{

//·����Ŀ�͵�·��Ŀ
private:
	int cross;
	int road;
	std::vector<std::vector<Road>> G;

public:
	TrafficG(){}

	TrafficG(int c, int r) :cross(c), road(r){
		std::vector<Road> temp(0);
		G.push_back(temp);
	}

	~TrafficG(){}

	int crossnum(){ return cross; }	//���·����Ŀ
	int roadnum(){ return road; }	//�����·��Ŀ
	bool construct(std::vector<Cross>&Cs, std::vector<Road>&Rs);//������ͨͼ���ɹ�����true�����򷵻�false
	//��ʾ������б�
	void show(){
		for (std::size_t i = 1; i < G.size(); i++)
			for (std::size_t j = 0; j < G[i].size(); j++)
				std::cout << G[i][j].id() << " ," << G[i][j].startid() << " ," << G[i][j].endid() << " ," << G[i][j].twoways() << std::endl;
	}
	//����·��sourceid�ĵ�һ����·
	Road* begin(int sourceid){
		assert(sourceid>0 && sourceid <= cross);
		return &G[sourceid][0];
	}
	//����·��sourceid�ĵ�i+1����·
	Road* findRoad(int sourceid,int i){
		assert(sourceid>0 && sourceid <= cross);
		assert(i >= 0 && (std::size_t)i < G[sourceid].size());
		return &G[sourceid][i];
	}
	//����·��Sourceid�����һ����·
	//Road* end(int sourceid){
	//	assert(sourceid>0 && sourceid <= cross);
	//	return &G[sourceid][G[sourceid].size()-1];
	//}
	//i�Ƿ��Ѿ���ĩβ��
	bool isend(int sourceid, int i){
		return (std::size_t)i == G[sourceid].size();
	}
	//·��i�ĵ�·��Ŀ
	int size(int i){
		assert(i>0 && i <= cross);
		return G[i].size();
	}
	class TraRoadIterator{

private:
		int Sourceid;//·������
		int Index;
		TrafficG &traff;
		Road* Begin;//��ͨͼ��ָ��·�ڵĵ�һ����·

public:
		TraRoadIterator(TrafficG &traffic,int sourceid):traff(traffic){
			Sourceid = sourceid;
			Index = 0;
			//traff = traffic;
			Begin = traffic.begin(Sourceid);
		}

		~TraRoadIterator(){}

		
		Road* begin(){
			Index = 0;
			if (traff.size(Sourceid))
				return traff.begin(Sourceid);
			return NULL;

		}

		Road* next(){
			Index++;
			if (Index<traff.size(Sourceid))
				return traff.findRoad(Sourceid, Index);
			return NULL;
		}


		bool end(){
			return traff.isend(Sourceid,Index);	
		}
	};

};


#endif
