#include"CirSequence.h"
CirSequence::CirSequence(const NODE &staloc, const NODE &endloc)
{
	this->Seq = new NODE[4];
	Seq[0] = { 0,1 }; Seq[1] = { 1,0 }; Seq[2] = { 0,-1 }; Seq[3] = { -1,0 };
	this->AdjustSeq(staloc, endloc);
}
pNODE CirSequence::GetSeq() { return Seq; }
CirSequence::CirSequence()
{
	this->Seq = new NODE[4];
	Seq[0] = { 0,1 }; Seq[1] = { 1,0 }; Seq[2] = { 0,-1 }; Seq[3] = { -1,0 };
	this->spin = this->start = 0;
}
void  CirSequence::AdjustSeq(const NODE &staloc, const NODE &endloc)
{
	NODE vec = { endloc.i - staloc.i,endloc.j - staloc.j };
	spin = 1;
	if (vec.j > 0)//终点在起点右方
	{
		start = 0;
		if (vec.i < 0)//终点在起点右上方
			spin = -1;
	}
	if (vec.i == 0) //终点与起点横坐标相同
		if(vec.j>0)//终点在起点右方
			start = 0;
		else start = 2;//终点在起点左方
	if (vec.j == 0)//终点与起点纵坐标相同
		if (vec.i > 0)//终点在起点下方
			start = 1;
		else start = 3;// 终点在起点上方
	if (vec.j < 0)//终点在起点左方
	{
		start = 2;
		if (vec.i > 0)//终点在起点左下方
			spin = -1; 
	}
}
int CirSequence::GetSpin() { return spin; }
int CirSequence::GetStart() { return this->start; }
