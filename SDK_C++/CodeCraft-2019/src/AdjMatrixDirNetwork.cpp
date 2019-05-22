#include "AdjMatrixDirNetwork.h"

AdjMatrixDirNetwork::AdjMatrixDirNetwork(int vertexMaxNum,int infinite)
{
	vexMaxNum=vertexMaxNum;
	vexNum=0;
	arcNum=0;
	infinity=infinite;
	vertexes=new int[vexMaxNum];
	tag=new VisitStatus[vexMaxNum];
	arcs=new int *[vexMaxNum];
	for(int i=0;i<vexMaxNum;i++)
		arcs[i]=new int[vexMaxNum];
}

AdjMatrixDirNetwork& AdjMatrixDirNetwork::operator=(AdjMatrixDirNetwork& netRaw)
{
	this->vexMaxNum=netRaw.vexMaxNum;
	this->vexNum=netRaw.vexNum;
	this->arcNum=netRaw.arcNum;
	this->infinity=netRaw.infinity;
	
	//this->vertexes=new int[this->vexMaxNum];
	//this->tag=new VisitStatus[this->vexMaxNum];
	//this->arcs=new int *[this->vexMaxNum];
	for(int i=0;i<this->vexMaxNum;i++)
		this->arcs[i]=new int[this->vexMaxNum];	
		
	for(int i=0;i<(this->vexMaxNum);i++)
	{
		this->vertexes[i]=netRaw.vertexes[i];
		this->tag[i]=netRaw.tag[i];
		for(int j=0;j<this->vexMaxNum;j++)
			this->arcs[i][j]=netRaw.arcs[i][j];
	}

}

AdjMatrixDirNetwork& operator / (AdjMatrixDirNetwork& lhd, int x)
{
	for(int i=0;i<(lhd.vexMaxNum);i++)
	{
		for(int j=0;j<lhd.vexMaxNum;j++)
		{
			if(lhd.arcs[i][j] == lhd.infinity )	{}
			else
			{
				lhd.arcs[i][j]=ceil((float)lhd.arcs[i][j]/(float)x);
			}
		}
	}
	return lhd;
}


AdjMatrixDirNetwork::AdjMatrixDirNetwork(AdjMatrixDirNetwork& netRaw)
{
	this->vexMaxNum=netRaw.vexMaxNum;
	this->vexNum=netRaw.vexNum;
	this->arcNum=netRaw.arcNum;
	this->infinity=netRaw.infinity;
	
	this->vertexes=new int[this->vexMaxNum];
	this->tag=new VisitStatus[this->vexMaxNum];
	this->arcs=new int *[this->vexMaxNum];
	for(int i=0;i<this->vexMaxNum;i++)
		this->arcs[i]=new int[this->vexMaxNum];	
		
	for(int i=0;i<(this->vexMaxNum);i++)
	{
		this->vertexes[i]=netRaw.vertexes[i];
		this->tag[i]=netRaw.tag[i];
		for(int j=0;j<this->vexMaxNum;j++)
			this->arcs[i][j]=netRaw.arcs[i][j];
	}

}

AdjMatrixDirNetwork::AdjMatrixDirNetwork(int *vexs,int vertexNum,int vertexMaxNum,int infinite)
{
	vexMaxNum=vertexMaxNum;
	vexNum=vertexNum;
	infinity=infinite;
	arcNum=0;
	vertexes=new int[vexMaxNum];
	tag=new VisitStatus[vexMaxNum];
	arcs=new int *[vexMaxNum];
	for(int i=0;i<vexMaxNum;i++)
		arcs[i]=new int[vexMaxNum];
	for(int i=0;i<vexMaxNum;i++)
	{
		vertexes[i]=vexs[i];
		tag[i]=UNVISIT;
		for(int j=0;j<vexMaxNum;j++)
			arcs[i][j]=infinity;
	}
}

AdjMatrixDirNetwork::~AdjMatrixDirNetwork()
{
	if(vertexes!=NULL)
		delete[] vertexes;
	if(tag!=NULL)
		delete[] tag;
	if(arcs!=NULL)
	{
		for(int i=0;i<vexNum;i++)
			delete[] arcs[i];
		delete[] arcs;
	}
}

void AdjMatrixDirNetwork::InsertArc(int vex1,int vex2,int weight)
{
	arcs[vex1][vex2]=weight;
	arcNum++;
}

//void AdjMatrixDirNetwork::changeToTime()
//{
//}

int AdjMatrixDirNetwork::GetElem(int vex)
{
	return vertexes[vex];
}

int AdjMatrixDirNetwork::GetVexNum()
{
	return vexNum;
}

int AdjMatrixDirNetwork::GetArcNum()
{
	return arcNum;
}

int AdjMatrixDirNetwork::GetWeight(int vex1,int vex2)
{
	return arcs[vex1][vex2];
}

int AdjMatrixDirNetwork::GetInfinity()
{
	return infinity;
}

int AdjMatrixDirNetwork::FirstAdjVex(int vex)
{
	for(int i=0;i<vexNum;i++)
		if(arcs[vex][i]!=infinity)
			return i;
	return -1;
}

int AdjMatrixDirNetwork::NextAdjVex(int vex,int vex2)
{
	for(int i=vex2+1;i<vexNum;i++)
		if(arcs[vex][i]!=infinity)
			return i;
	return -1;
}

void AdjMatrixDirNetwork::Display()
{
	if(vexNum!=0)
	{
		for(int i=0;i<vexNum;i++)
		{
			cout<<"[ ";
			for(int j=0;j<vexNum;j++)
				cout<<arcs[i][j]<<" ";
			cout<<"]"<<endl;
		}
	}
}

VisitStatus AdjMatrixDirNetwork::GetTag(int vex)
{
	return tag[vex];
}

int AdjMatrixDirNetwork::SetTag(int vex,VisitStatus _tag)
{
	if(vex>=vexNum)
		return 0;
	tag[vex]=_tag;
	return 1;
}
