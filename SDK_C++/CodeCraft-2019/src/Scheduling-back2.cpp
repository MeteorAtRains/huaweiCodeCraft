#include "Scheduling.h"
//#include "sys/time.h"

#define UNUSED(x) (void)x
#define STARTCAR(x) cars[(x)].startid()-1
#define ENDCAR(x) cars[(x)].endid()-1
#define CARVEL(x) x->vmax()

Scheduling::Scheduling(vector<Car>& cars,vector<Road>& roads,vector<Cross>& crosses,vector<Trajectory>& trajectorys)
{
	uint vexsSize = crosses.size()-1;
	int* crossVexs = new int[crosses.size()-1];
	Trajectory tra;
//	lv_status::Status status(roads);
//	RoadsStatus roadStatus(roads);
	
	for(uint i=0 ; i < vexsSize; i++)
	{
		*(crossVexs+i) = crosses[i+1].id();
	}
	*(crossVexs+vexsSize) = 0;
	
	AdjMatrixDirNetwork network(crossVexs,vexsSize,vexsSize);
	AdjMatrixDirNetwork netCopy(crossVexs,vexsSize,vexsSize);
	AdjMatrixDirNetwork netTime(crossVexs,vexsSize,vexsSize);
	AdjMatrixDirNetwork netCopy1(crossVexs,vexsSize,vexsSize);
	
	for(auto it = roads.begin(); it != roads.end(); it++)
	{
		if( it == roads.begin())	
		{
			continue;
		}
		//SHOW_LINK_BY_ITERATOR(it);					
		network.InsertArc(it->startid()-1,it->endid()-1,it->length());

	}	
/*#| Time[1] |######################################
	tra.setStartTime(cars[1].starttime());
	cout<<cars[1].starttime()<<endl;
	int timeTmp[2] = {0,0}; //last time
//*/
//Add[3-1] | Init Tra_List|###################	
	for(auto it = cars.begin(); it != cars.end(); it++)
	{
		if( it == cars.begin())
		{
			continue;
		}
		tra.setCanStartTime(it->starttime());
		tra.setCarVel(CARVEL(it));
		tra.setCarId(it->id());
		trajectorys.push_back(tra);
	}//*/
//Add[2-1]| Car Status |###############################
	vector<lv_status::CarStatus> carsStatus(0);
	lv_status::CarStatus singleCarStatus;
//init car status
	for(auto itCsSta = trajectorys.begin(); itCsSta != trajectorys.end(); itCsSta++)
	{
		singleCarStatus.clear();
		singleCarStatus.carId = itCsSta->carId();	
		//for(auto itRdList = itCsSta->roadList_.begin();itRdList != itCsSta->roadList_.end(); itRdList++)
		//{
		//	singleCarStatus.leftRoad.push_back(*itRdList);
		//}
		carsStatus.push_back(singleCarStatus);
	}
//#####################################################	

//	for(auto titCsSta = carsStatus.begin(); titCsSta != carsStatus.end(); titCsSta++)
//	{
//		cout<<titCsSta->carId<<" "<<titCsSta->hasGone<<endl;
//	}
	
//set car start time
	//bool allDone = false;
	int  undoneCount = 0;
	bool notUse  = false;
cout<<"Debug[0] | First ID:"<<cars[1].id()<<endl;
	for(int i = 0;; i++)//按时间进程
	{
		//记录未完成车辆的数量
		undoneCount = 0;
		for(auto itCarRun = carsStatus.begin(); itCarRun != carsStatus.end(); itCarRun++)
		{
			undoneCount += (!itCarRun->run());
		}
cout<<i<<"  undoneCount: "<<undoneCount<<endl;
		if(undoneCount == 0)
		{
cout<<"Debug[1] | Break!"<<endl;
			break;
		}
		
		for(size_t carId = 1; carId < cars.size();carId++)
		{	
//cout<<<<end;
			if((carsStatus[carId-1].run())||(carsStatus[carId-1].finish()))//如果车已经在行驶或者结束，则跳过
			{
//cout<<"Debug[2] | Has done carId:"<<cars[carId].id()<<endl;
				continue;
			}
//cout<<"Debug[3] | no Gone carId:"<<cars[carId].id()<<" Start time:"<<cars[carId].starttime()<<endl;		
			if(cars[carId].starttime()<=i)//验证出发时间
			{
				notUse = false;
				//canUse  = true;
				//验证是否tra[carId-1]中的轨迹道路是否都使用
				for(auto itTra = trajectorys[carId-1].roadList_.begin();itTra != trajectorys[carId-1].roadList_.end(); itTra++)//获取每条轨迹中的所有路径		
				{
					notUse += status.checkFilled(*itTra);//验证该段路径是否有用
				}
				if(!notUse)//如果道路可用，则设置该车辆始发时间
				{
					trajectorys[carId-1].setCanStartTime(i);
					carsStatus[carId-1].updateRun();//车辆行信息更新
					status.updateNewRun(trajectorys[carId-1],carId-1);//更新新的道路信息
				}
			}
		}
		status.updateAuto();
		status.roadSatusShow(1);
		//status.roadStatusUsing();
	}

//######################################################	
	std::cout<<"Scheduling running!"<<std::endl;
	
	delete[] crossVexs;
	UNUSED(vexsSize);
	//delete vexsSize;
}

void run(vector<Car>& cars,vector<Road>& roads,vector<Cross>& crosses,vector<Trajectory>& trajectorys)
{}

void findRoad(vector<Road>& roads,Trajectory& trajectory)
{
	for(auto itT = trajectory.crossList_.end()-1;itT != trajectory.crossList_.begin(); --itT)
	{
		for(auto itR = roads.begin();itR != roads.end(); itR++)
		{
			if(*(itT)==itR->startid())
			{
				if(*(itT-1)==itR->endid()) trajectory.addRoad(itR->id());
			}
		}
	}
}





























