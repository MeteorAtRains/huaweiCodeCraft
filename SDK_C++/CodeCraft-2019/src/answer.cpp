#include "answer.h"

using std::cout;
using std::endl;

void answerout(std::string carPath,std::string  roadPath,std::string crossPath,std::string  answerPath)
{
	std::vector<Road> Rs(0);
	ReadRoad(roadPath, Rs);
	std::vector<Cross> Cs(0);
	ReadCross(crossPath, Cs);
	std::vector<Car> Cars(0);
	ReadCar(carPath, Cars);	
	vector<Trajectory> Ts(0);
	                                                                                                                                                                   
	run(Cars,Rs,Cs,Ts);
	
	std::ofstream outfile(answerPath);
	
	outfile << "#(carId,StartTime,RoadId...)" << std::endl;
	
	for(auto itTs = Ts.begin(); itTs != Ts.end(); itTs++)
	{
		outfile << "(" << itTs->carId() << "," << itTs->canStartTime();
		for(auto itTs_rL = itTs->roadList_.begin(); itTs_rL != itTs->roadList_.end(); itTs_rL++)
		{
			outfile<<","<<*itTs_rL;
		}
		outfile << ")"<<endl;
	}
	
	//outfile <<")" << std::endl;

	outfile.close();
//*/
}
