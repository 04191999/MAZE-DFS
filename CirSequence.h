#pragma once
#ifndef CIRSEQUENCE_H
#define CIRSEQUENCE_H
#include"NODE.h"
class CirSequence
{
private:
	pNODE Seq;
	int start;//Ѱ·��ʼ����
	int spin=1;//1Ϊ˳ʱ�룬-1Ϊ��ʱ��
public:
	CirSequence(const NODE &staloc, const NODE &endloc);//���ι���
	CirSequence() ;//�޲�������
	pNODE GetSeq();
	int GetStart();//��ȡѰ·��ʼ����
	void AdjustSeq(const NODE &staloc, const NODE &endloc);//������ʼ�����Ѱ·����
	int GetSpin();//���Ѱ·����ת����
};
#endif