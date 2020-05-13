#pragma once
#ifndef SEQSTACK_H
#define SEQSTACK_K
#include<iostream>
#include"NODE.h"
using namespace std;
class SeqStack 
{
private:
	NODE *arr;//���鶯̬����
	int top;//ջ��λ��
	int size;//���ɴ����Ԫ����Ŀ
public:
	//���캯�� ��ʼ����̬����һ��˳��ջ
	SeqStack(int size);
	//��ȡѹ��ջ��Ԫ�صĸ���
	int GetNum();
	//�ж�ջ�Ƿ�Ϊ��
	bool SeqStack_isempty();
	//��Ԫ����ջ
	void SeqStack_Push(pNODE p);
	//��Ԫ�س�ջ
	void SeqStack_Pop();
	//��ӡ���
	void print();
	//��ȡ�������
	pNODE GetTop();
	//��ֵ��������
	SeqStack& operator=(const SeqStack&c);
	//���ջ
	void Clear();
	pNODE GetValus();
};
#endif
