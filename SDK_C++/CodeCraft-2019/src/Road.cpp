#include "Road.h"

void Road::show() const
{ 
	std::cout << "(" << ID << ", " << Length << ", " << Vmax << ", " << LaneNum << ", " << StartID << ", " << EndID << ", " << DoubleDirect << " )" << std::endl; 
}

bool Road::operator == (const Road& roadFindID)
{
	return (this->ID == roadFindID.ID);	
}

Road Road::operator = (const Road rhd)
{
	this->ID			= rhd.ID;
	this->Length		= rhd.Length;
	this->Vmax			= rhd.Vmax;
	this->LaneNum		= rhd.LaneNum;
	this->StartID		= rhd.StartID;
	this->EndID			= rhd.EndID;
	this->DoubleDirect	= rhd.DoubleDirect;
}
