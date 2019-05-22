#ifndef _B_AIJKSTRA_H_
#define _B_AIJKSTRA_H_

//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<stack>

#include <bits/stdc++.h>

#include"Cross.h"
#include"Road.h"
#include"TrafficG.h"
#include"IndexMinHeap.h"

class DijkStra{

private:
	
	int test_i;
	
	TrafficG G;//公交图
	int StartID, EndID, Vmax;//起始路口id,终止路口id，汽车最大速度

	float* Time;//耗时数组
	bool* Marked;//是否遍历数组
	std::vector<Road*> from;//路径向量

public:
	DijkStra(TrafficG &graph, Car &c);
	~DijkStra();

	float shortestPathTo(){
		return Time[EndID];
	}

	void shortestPath(vector<Road*> &vec);

	void showPathCross(){

		assert(EndID > 0 && EndID <= G.crossnum());

		vector<Road*> vec;
		shortestPath(vec);
		cout << vec[0]->startid() << "->";
		for (std::size_t i = 0; i < vec.size(); i++){
			if (i == vec.size() - 1)
				cout << vec[i]->endid() << endl;
			else
				cout << vec[i]->endid() << " -> ";
		}
	}

	void showPathRoad(){

		vector<Road*> vec;
		shortestPath(vec);	
		for (std::size_t i = 0; i < vec.size(); i++)
			if (i != vec.size() - 1)
				cout << vec[i]->id() << " -> ";
			else
				cout << vec[i]->id() << endl;
	}

	void showtime(){
		std::cout << Time[EndID] << std::endl;
	}

	void savePathTime(vector<Road*> &vec, int &t);

};




#endif
