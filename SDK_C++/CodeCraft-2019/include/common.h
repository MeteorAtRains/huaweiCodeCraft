#include <iostream>
#define SHOW_LINK_BY_ITERATOR(x)			\
{											\
	cout<<"I:"<<x->id();					\
	cout<<" S:"<<x->startid();				\
	cout<<" E:"<<x->endid();				\
	cout<<" L:"<<x->length()<<endl;			\
}	

#define SHOW_CAR_START_AND_END(testCarNum)	\
{											\
	cout<<cars[testCarNum].id()<<":"<<cars[testCarNum].startid()<<"==>"<<cars[testCarNum].endid()<<endl;\
}

#define SHOW_CAR_ID(testCarNum)\
{\
	cout<<"car id["<<cars[testCarNum].id()<<"]"<<endl;\
}

#define SHOW_CAR_(id,net,network)\
{\
	net=network;\
	SHOW_CAR_START_AND_END(id-10000);\
	ShortestPathDijkstra(net,cars[id-10000].startid(),cars[id-10000].endid());\
}
