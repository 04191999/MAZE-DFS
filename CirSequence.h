#pragma once
#ifndef CIRSEQUENCE_H
#define CIRSEQUENCE_H
#include"NODE.h"
class CirSequence
{
private:
	pNODE Seq;
	int start;//寻路起始方向
	int spin=1;//1为顺时针，-1为逆时针
public:
	CirSequence(const NODE &staloc, const NODE &endloc);//带参构造
	CirSequence() ;//无参数构造
	pNODE GetSeq();
	int GetStart();//获取寻路起始方向
	void AdjustSeq(const NODE &staloc, const NODE &endloc);//根据起始点调整寻路方向
	int GetSpin();//获得寻路的旋转方向
};
#endif