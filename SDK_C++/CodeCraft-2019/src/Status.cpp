#include "Status.h"

//void lv_status::RoadStatus::countRealTime()
//{
//	carNum = 0;
//	for(auto i=runningCarId.begin();i!=runningCarId.end();i++)
//	{
//		carNum++;
//	}
//}
void lv_status::CarStatus::updateRun()
{
	hasGone = true;
}
bool lv_status::CarStatus::run()
{
	return hasGone;
}
bool lv_status::CarStatus::finish()
{
	return finished;
}
void lv_status::CarStatus::clear()
{
	carId 	 = 0;
	hasGone  = false;
	finished = false;
	leftRoad.clear();
}

lv_status::Status::Status(vector<Road>& roads)
{
	//tempRoadStatus.crossOut = 0;
	//tempRoadStatus.crossIn  = 0;
	//tempRoadStatus.runningCarId.clear();
	roadsStatus.clear();
	
	for(auto itRoads = roads.begin(); itRoads != roads.end(); itRoads++)
	{
		if(itRoads == roads.begin()){ continue;	}
		
		tempRoadStatus.id = itRoads->id();
		tempRoadStatus.carMaxNum = itRoads->lanenum();
		tempRoadStatus.carNum = 0;
		roadsStatus.push_back(tempRoadStatus);
		
		for(size_t i = 0; i < roadsStatus.size()-1; i++)
		{
			if(tempRoadStatus.id == roadsStatus[i].id)
			{
				roadsStatus.erase(roadsStatus.end()-1);
			}
		}
	}
}
void lv_status::Status::showRoadStatus()
{
	for(auto itRdsSta = roadsStatus.begin(); itRdsSta != roadsStatus.end(); itRdsSta++)
	{
		cout<<"Road id: "<<itRdsSta->id<<endl;
	}
}

void lv_status::Status::roadStatusUsing()
{
	for(auto itRdsSta = roadsStatus.begin(); itRdsSta != roadsStatus.end(); itRdsSta++)
	{
		if(itRdsSta->carNum != 0)
		{
		cout<<"Road id: "<<itRdsSta->id<<" running CarNum:"<<itRdsSta->carNum<<endl;
		}
				
	}
}

void lv_status::Status::updateAuto()
{
	for(size_t i = 0; i < roadsStatus.size(); i++)
	{
		for(auto it = roadsStatus[i].carInfo.begin();it != roadsStatus[i].carInfo.end(); it++)
		{
			if(it->leftTime == 1)
			{
				roadsStatus[i].carInfo.erase(it);
				it--;
				roadsStatus[i].carNum--;
			}
			else if(it->leftTime > 1)
			{
				it->leftTime--;
			}
			else
			{ }
		}
		
	}
}
void lv_status::Status::updateNewRun(lv_trajectory::Trajectory tempTra,int i)
{
	for(size_t j = 0 ; j < tempTra.roadList_.size(); j++)
	{
		for(auto it = roadsStatus.begin();it !=roadsStatus.end();it++)
		{
			if(it->id == tempTra.roadList_[j])
			{
				it->carNum++;
				it->carInfo.push_back(carIdAndLeftTime(i+1,tempTra.runTimeList_[j]));
				//it->runningCarId.push_back(i+1);
			}
		}
	}
}

void lv_status::Status::roadSatusShow(int i)
{
	if(i<roadsStatus.size()&&i>0)
	{
		cout<<"road["<<roadsStatus[i].id<<"] Max:"<<roadsStatus[i].carMaxNum<<" running car:"<<roadsStatus[i].carNum<<endl;
	}
}


bool lv_status::Status::checkFilled(int roadId)
{
	for(auto it = roadsStatus.begin();it != roadsStatus.end(); it++)
	{
		if(it->id == roadId)
		{
			if(it->carNum>=it->carMaxNum)	return true;//已满
		}
	}
	return false;
}
