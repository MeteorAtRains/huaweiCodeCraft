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
	
	TrafficG G;//����ͼ
	int StartID, EndID, Vmax;//��ʼ·��id,��ֹ·��id����������ٶ�

	float* Time;//��ʱ����
	bool* Marked;//�Ƿ��������
	std::vector<Road*> from;//·������

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
