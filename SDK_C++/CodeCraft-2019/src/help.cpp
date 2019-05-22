#include "help.h"

using std::cout;
using std::endl;

const int ONE 	= 1;
const int _ONE 	= -1;
const int ZERO	= 0;

void ReadRoad(const std::string &filename,std::vector<Road> &Rs){

	std::ifstream file(filename);
	std::string line;

	assert(file.is_open());
	assert(std::getline(file, line));
	std::stringstream ss(line);
	assert(line == "#(id,length,speed,channel,from,to,isDuplex)");
std::cout << line << std::endl;
	Rs.push_back(Road(-1, -1, -1, -1, -1, -1, 0));//Rs[0]不存储道路信息

	int ID, Length, Vmax, LaneNum, StartID, EndID;
	bool DoubleDirect;
	char temp;
	while (true){
		if (!std::getline(file, line))
		{
			break;
		}

//cout<<std::getline(file, line)<<endl;
//std::cout << line << std::endl;
		std::stringstream ss(line);

		ss >> temp >> ID >> temp >> Length >> temp >> Vmax >> temp >> LaneNum >> temp >> StartID >> temp >> EndID >> temp >> DoubleDirect >> temp;
//cout<<temp<<endl;
//cout<<ID<<endl;
		if (DoubleDirect == 1){
			Road t(ID, Length, Vmax, LaneNum, EndID, StartID, 0);
			Rs.push_back(t);
		}
		Road t(ID, Length, Vmax, LaneNum, StartID, EndID, 0);
		Rs.push_back(t);
	}
	file.close();
}

void ReadCross(const std::string &filename, std::vector<Cross> &Cs){

	int ID, NorthID, EastID, SouthID, WestID;
	char temp;
	std::ifstream file(filename);
	std::string line;

	assert(file.is_open());
	assert(std::getline(file, line));
	std::stringstream ss(line);
	assert(line == "#(id,roadId,roadId,roadId,roadId)");
	//std::cout << line << std::endl;
	Cs.push_back(Cross(ONE - _ONE, _ONE, _ONE, _ONE, _ONE));//Cs[0]不存储路口信息

	while (true){
		if (!std::getline(file, line))
			break;
		std::stringstream ss(line);
		ss >> temp >> ID >> temp >> NorthID >> temp >> EastID >> temp >> SouthID >> temp >> WestID >> temp;
		Cs.push_back(Cross(ID, NorthID, EastID, SouthID, WestID));
	}
	file.close();
}

void ReadCar(const std::string &filename, std::vector<Car> &Cars){

	int ID, StartID, EndID, Vmax, StartTime;
	char temp;
	std::ifstream file(filename);
	std::string line;

	assert(file.is_open());
	assert(std::getline(file, line));
	std::stringstream ss(line);
	assert(line == "#(id,from,to,speed,planTime)");
	//std::cout << line << std::endl;
	Cars.push_back(Car (1 -1, -1, -1, -1, -1));//Cs[0]不存储路口信息

	while (true){
		if (!std::getline(file, line))
			break;
		std::stringstream ss(line);
		ss >> temp >> ID >> temp >> StartID >> temp >> EndID >> temp >> Vmax >> temp >> StartTime >> temp;
		Cars.push_back(Car(ID, StartID, EndID, Vmax, StartTime));
	}
	file.close();
}

int findRoadID(int id, int startid, std::vector<Road> &Rs)
{
	for (std::size_t  i = 1; i < Rs.size() && id >= Rs[i].id(); i++)
		if (id == Rs[i].id() && startid == Rs[i].startid())
			return i;

	return -1;
}
