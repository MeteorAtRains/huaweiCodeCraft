#include "ShortestPathDijkstra.h"

void ShortestPathDijkstra(AdjMatrixDirNetwork network,int startVex)
{
	int vexNum=network.GetVexNum(),*dist,*path;
	int	i,j,infinity=network.GetInfinity(),min,minOrder(0);
	dist=new int[vexNum];
	path=new int[vexNum];
	network.SetTag(startVex,VISIT);
	cout<<startVex<<endl;
	for(i=0;i<vexNum;i++)    //初始化
	{
		if(i!=startVex)
		{
			dist[i]=network.GetWeight(startVex,i);
		    if(dist[i]==infinity)
				path[i]=-1;
			else
				path[i]=startVex;
		}
		else
		{
			dist[i]=0;
			path[i]=-1;
		}
	}
	for(i=1;i<vexNum;i++)   //循环n-1次，找出以startvex为起点，其他n-1个顶点为终点的最短路径
	{
		 min=infinity;
//		 cout<<"["<<i<<"]---"<<endl;
		 for(j=0;j<vexNum;j++)
		 {
			 if(network.GetTag(j)==UNVISIT&&dist[j]<min)
			 {
				 min=dist[j];
				 minOrder=j;
			 }
//			 cout<<" |minOrder["<<j<<"]: "<<minOrder;
		 }
//		 cout<<endl;
		 network.SetTag(minOrder,VISIT);
		 for(j=0;j<vexNum;j++)
		 {
			 if(network.GetTag(j)==UNVISIT&&(min+network.GetWeight(minOrder,j)<dist[j]))
			 {
				 dist[j]=min+network.GetWeight(minOrder,j);
				 path[j]=minOrder;
			 }
//			 cout<<" |path["<<j<<"]: "<<path[j];
		 }
//		 cout<<endl;
	}
	for(i=0;i<vexNum;i++)
		cout<<dist[i]<<" ";
	cout<<endl;
	for(i=0;i<vexNum;i++)
		cout<<path[i]<<" ";
	cout<<endl;
	for(i=0;i<vexNum;i++)
	{
		if(i!=startVex)
		{
			cout<<"from node ["<<network.GetElem(startVex)<<"] to node ["<<network.GetElem(i)<<"], the shortest distence is:"<<dist[i];
			cout<<", the trajectory is:"<<network.GetElem(i);
			j=i;
			while(path[j]!=-1)
			{
				j=path[j];
				cout<<"<-"<<network.GetElem(j);
			}
			cout<<endl;
		}
	}
	delete[] dist;
	delete[] path;
}

int ShortestPathDijkstra(AdjMatrixDirNetwork& network,int startVex,int endVex,Trajectory& trajectory)
{
	int runTime = 0;
	trajectory.clean();
	int vexNum=network.GetVexNum();
	int *dist,*path;
	int	i,j,infinity=network.GetInfinity(),min,minOrder(0);
	dist=new int[vexNum];
	path=new int[vexNum];
	network.SetTag(startVex,VISIT);
//	cout<<startVex<<endl;
	for(i=0;i<vexNum;i++)    //初始化
	{
		if(i!=startVex)
		{
			dist[i]=network.GetWeight(startVex,i);
		    if(dist[i]==infinity)
				path[i]=-1;
			else
				path[i]=startVex;
		}
		else
		{
			dist[i]=0;
			path[i]=-1;
		}
	}
	for(i=1;i<vexNum;i++)   //循环n-1次，找出以startvex为起点，其他n-1个顶点为终点的最短路径
	{
		 min=infinity;
		 for(j=0;j<vexNum;j++)
		 {
			 if(network.GetTag(j)==UNVISIT&&dist[j]<min)
			 {
				 min=dist[j];
				 minOrder=j;
			 }
		 }
		 network.SetTag(minOrder,VISIT);
		 for(j=0;j<vexNum;j++)
		 {
			 if(network.GetTag(j)==UNVISIT&&(min+network.GetWeight(minOrder,j)<dist[j]))
			 {
				 dist[j]=min+network.GetWeight(minOrder,j);
				 path[j]=minOrder;
			 }
		 }
	}
	
//	for(i=0;i<vexNum;i++) {cout<<dist[i]<<" ";}
//	cout<<endl;
	
//	for(i=0;i<vexNum;i++) {cout<<path[i]<<" ";}
//	cout<<endl;
	
	for(i=0;i<vexNum;i++)
	{
		if(i!=startVex)
		{
			if(i!=endVex)
			{
				continue;
			}
			//cout<<"["<<network.GetElem(startVex)<<"] ==> ["<<network.GetElem(i)<<"], min dist:"<<dist[i];
			//cout<<", trajectory:"<<network.GetElem(i);
			j=i;
			trajectory.addCross(network.GetElem(j));
			runTime = dist[i];
			trajectory.setRunTime(dist[i]);
			//trajectory.updateStartTime(dist[i]);
			while(path[j]!=-1)
			{
				j=path[j];
				//cout<<"<-"<<network.GetElem(j);
				trajectory.addCross(network.GetElem(j));
			}
			//cout<<endl;
		}
	}
	//network = netCopy;
	//delete netCopy;
	
	delete[] dist;
	delete[] path;
	return runTime;
}

