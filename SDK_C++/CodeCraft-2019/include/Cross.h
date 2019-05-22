#ifndef CROSS_H
#define CROSS_H

//#include<iostream>
#include <bits/stdc++.h>

class Cross{

private:

	int ID;
	int NorthID, EastID, SouthID, WestID;

public:

	Cross(){}

	//Cross(int& ID, int& NorthID, int& EastID, int& SouthID, int& WestID)
	//	:ID(ID),NorthID(NorthID),EastID(EastID),SouthID(SouthID),WestID(WestID)
	//{ }
	
	Cross(int ID, int NorthID, int EastID, int SouthID, int WestID)
		:ID(ID),NorthID(NorthID),EastID(EastID),SouthID(SouthID),WestID(WestID)
	{ }
	
	~Cross(){}

	int id() const { return ID; }

	int north() const { return NorthID; }

	int east() const { return EastID; }

	int south() const { return SouthID; }

	int west() const { return WestID; }

	void show() const {
		std::cout << "(" << ID << ", " << NorthID << ", " << EastID << ", " << SouthID << ", " << WestID << ")" << std::endl;
	}



};



#endif
