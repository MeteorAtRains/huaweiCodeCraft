#ifndef CAR_H
#define CAR_H

//#include<iostream>
#include <bits/stdc++.h>

class Car{
private:
	int ID;
	int StartID;
	int EndID;
	int Vmax;
	int StartTime;

public:
	Car(){}

	Car(int ID, int StartID, int EndID, int Vmax, int StartTime)
		:ID(ID),StartID(StartID),EndID(EndID),Vmax(Vmax),StartTime(StartTime)	
	{ }

	~Car(){}

	int id() const { return ID; }

	int startid() const { return StartID; }

	int endid() const { return EndID; }

	int vmax() const { return Vmax; }

	int starttime() const { return StartTime; }

	void show() const {
		std::cout << "(" << ID << " ," << StartID << " ," << EndID << " ," << Vmax << " ," << StartTime << ")" << std::endl;
	}
	
	void set(int& ID, int& StartID, int& EndID, int& Vmax, int& StartTime)
	{
		
	}
	
};



#endif
