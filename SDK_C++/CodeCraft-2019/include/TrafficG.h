#ifndef TRAFFICG_H
#define TRAFFICG_H

/*
#include<iostream>
#include<vector>
*/

#include <bits/stdc++.h>
#include"help.h"

class TrafficG{

//路口数目和道路数目
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

	int crossnum(){ return cross; }	//输出路口数目
	int roadnum(){ return road; }	//输出道路数目
	bool construct(std::vector<Cross>&Cs, std::vector<Road>&Rs);//构建交通图，成功返回true，否则返回false
	//显示输出所有边
	void show(){
		for (std::size_t i = 1; i < G.size(); i++)
			for (std::size_t j = 0; j < G[i].size(); j++)
				std::cout << G[i][j].id() << " ," << G[i][j].startid() << " ," << G[i][j].endid() << " ," << G[i][j].twoways() << std::endl;
	}
	//返回路口sourceid的第一条道路
	Road* begin(int sourceid){
		assert(sourceid>0 && sourceid <= cross);
		return &G[sourceid][0];
	}
	//返回路口sourceid的第i+1条道路
	Road* findRoad(int sourceid,int i){
		assert(sourceid>0 && sourceid <= cross);
		assert(i >= 0 && (std::size_t)i < G[sourceid].size());
		return &G[sourceid][i];
	}
	//返回路口Sourceid的最后一条道路
	//Road* end(int sourceid){
	//	assert(sourceid>0 && sourceid <= cross);
	//	return &G[sourceid][G[sourceid].size()-1];
	//}
	//i是否已经是末尾了
	bool isend(int sourceid, int i){
		return (std::size_t)i == G[sourceid].size();
	}
	//路口i的道路数目
	int size(int i){
		assert(i>0 && i <= cross);
		return G[i].size();
	}
	class TraRoadIterator{

private:
		int Sourceid;//路口坐标
		int Index;
		TrafficG &traff;
		Road* Begin;//交通图中指定路口的第一条道路

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
