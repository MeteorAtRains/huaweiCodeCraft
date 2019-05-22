#include "TrafficG.h"

bool TrafficG::construct(std::vector<Cross>&Cs, std::vector<Road>&Rs)
{
	for (std::size_t i = 1; i < Cs.size(); i++)
	{
		std::vector<Road> temp(0);
		G.push_back(temp);//插入空道路向量，初始化G[i]	
		int num = findRoadID(Cs[i].north(), i, Rs);//找出Cs[i]的上道路是否是从i路口出发，是返回道路的下标，否返回-1
		if (num != -1)
			G[i].push_back(Rs[num]);
		num = findRoadID(Cs[i].east(), i, Rs);//找出Cs[i]的右道路是否是从i路口出发，是返回道路的下标，否返回-1
		if (num != -1)
			G[i].push_back(Rs[num]);
		num = findRoadID(Cs[i].south(), i, Rs);//找出Cs[i]的下道路是否是从i路口出发，是返回道路的下标，否返回-1
		if (num != -1)
			G[i].push_back(Rs[num]);
		num = findRoadID(Cs[i].west(), i, Rs);//找出Cs[i]的左道路是否是从i路口出发，是返回道路的下标，否返回-1
		if (num != -1)
			G[i].push_back(Rs[num]);
	}
	return true;
}
