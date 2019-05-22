#include "Trajectory.h"

void lv_trajectory::Trajectory::showPath() const
{
	cout<<"Car["<<carID_<<"] PATH:";
	for(auto it = roadList_.begin(); it != roadList_.end(); it++)
	{
		cout<<" "<<*(it)<<" ";
	}
	cout<<endl;
}

void lv_trajectory::Trajectory::showAll() const
{	
	cout<<"Car["<<carID_<<"] StartTime: "<<startTime_<<" StartVex: "<<*(crossList_.end()-1)<<" PATH:"<<endl;
	cout<<"Cross:";
	for(auto it = crossList_.begin(); it != crossList_.end(); it++)
	{
		cout<<" "<<*(it)<<" ";
	}
	cout<<endl;
	cout<<"Road:";
		for(auto it = roadList_.begin(); it != roadList_.end(); it++)
	{
		cout<<" "<<*(it)<<" ";
	}
	cout<<endl;
}

void lv_trajectory::Trajectory::clean() 
{
	carID_ = 0;
	roadList_.clear();
	crossList_.clear();
	runTimeList_.clear();
}

void lv_trajectory::Trajectory::addRoad(int roadID)
{ 
	roadList_.push_back(roadID); 
}

void lv_trajectory::Trajectory::addCross(int crossID)
{ 
	crossList_.push_back(crossID); 
}

void lv_trajectory::Trajectory::setSingleRunTime(const vector<Road> roads)
{
	runTimeList_.clear();
	int s=0;
	for(auto its = roadList_.begin(); its != roadList_.end(); its++)
	{
		for(auto it = roads.begin(); it != roads.end(); it++)
		{
			if( *its == it->id())
			{
				s += it->length()/vel_;
				runTimeList_.push_back( s );
			}
		}
	} 
}

//void lv_trajectory::Trajectory::crossToRoad(int crossID)
