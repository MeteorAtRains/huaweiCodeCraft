#ifndef _LV_STATUS_H_
#define _LV_STATUS_H_

#include <bits/stdc++.h>

#include "Road.h"
#include "Trajectory.h"

using namespace std;

namespace lv_status{
	//enum 
	typedef struct carIdAndLeftTime
	{
		int runningCarId;
		int leftTime;
			
		carIdAndLeftTime(int a,int b)
		{
			runningCarId = a;
			leftTime	 = b;
		}
	}CarInfo;
	struct CarStatus{
		int  carId;
		bool hasGone;
		bool finished;
		vector<int> leftRoad;
		
		
		void clear();		
		void updateRun();
		bool run();
		bool finish();
	};
	
	struct RoadStatus{
		int id;
		//vector<int> runningCarId;
		int	carNum;
		int carMaxNum;
		//vector<int> leftTime;
		vector<CarInfo> carInfo;
		
		void countRealTime();
	};

	struct CrossStatus{
		int id;
		vector<int> roadConnectId;
		vector<int> runningCarId;
		int	carNum;
	
		void countRealTime()
		{
			carNum = 0;
			for(auto i=runningCarId.begin();i!=runningCarId.end();i++)
			{
				carNum++;
			}
		}
	};

	class Status{
	public:
		Status(vector<Road>& roads);
		void buildStatusSet();	
		void showRoadStatus();
		bool checkFilled(int roadId);
		void updateAuto();
		void updateNewRun(lv_trajectory::Trajectory,int);
		void roadSatusShow(int);
		void roadStatusUsing();
	private:
		vector<RoadStatus>	roadsStatus;
		vector<CrossStatus>	crossesStatus;
		RoadStatus tempRoadStatus;
	
	};
	
	class Structure{
	public:
	
	private:
	
	};

}

#endif
