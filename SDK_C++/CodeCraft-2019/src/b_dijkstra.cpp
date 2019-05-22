#include "b_dijkstra.h"

void DijkStra::shortestPath(vector<Road*> &vec)
{

	assert(EndID > 0 && EndID <= G.crossnum());

	std::stack<Road*> s;
	Road *e = from[EndID];
	while (e->startid() != this->StartID){
		s.push(e);
		e = from[e->startid()];
	}
	s.push(e);

	while (!s.empty()){
		e = s.top();
		vec.push_back(e);
		s.pop();
	}
}

void DijkStra::savePathTime(vector<Road*> &vec, int &t)
{
	shortestPath(vec);
	t = ceil(Time[EndID]);
}

DijkStra::DijkStra(TrafficG &graph, Car &c)
{
	G = graph;
	StartID = c.startid();
	EndID = c.endid();
	Vmax = c.vmax();
	Time = new float[G.crossnum()+1];
	Marked = new bool[G.roadnum()+1];
 	for (int i = 0; i < G.crossnum()+1; i++){
		Time[i] = 0;
		Marked[i] = false;
		from.push_back(NULL);
	}
		//start dijkstra		l;
	//cout<<G.crossnum()<<endl;
	IndexMinHeap<float> IMHRoad(G.crossnum());

	Time[StartID] = 0;
	Marked[StartID] = true;
	IMHRoad.insert(StartID, Time[StartID]);
	//cout<<"Debug[1] | IMHRoad size: "<<IMHRoad.size()<<endl;
	
	//test_i = 1;
	
	while (!IMHRoad.isEmpty())
	{
		int v = IMHRoad.extractMinIndex();
		//test_i++;
		//cout<<v<<endl;
		//cout<<"Debug["<<test_i<<"] | IMHRoad size: "<<IMHRoad.size()<<endl;
		Marked[v] = true;

		TrafficG::TraRoadIterator adj(G, v);
		for (Road* e = adj.begin(); !adj.end(); e = adj.next()){
			int w = e->endid();
			if (!Marked[w])
			 {
				if (from[w]==NULL||Time[v] + e->length() < Time[w])
				{
					Time[w] = Time[v] + e->length()/(float)(min(e->vmax(),c.vmax()));
					from[w] = e;
					if (IMHRoad.contain(w))
						IMHRoad.change(w, Time[w]);
					else
						IMHRoad.insert(w, Time[w]);
				}
			}
		}
	}
}
DijkStra::~DijkStra()
{
	delete[] Time;
	delete[] Marked;
}

