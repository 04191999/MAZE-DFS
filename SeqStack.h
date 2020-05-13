#pragma once
#ifndef SEQSTACK_H
#define SEQSTACK_K
#include<iostream>
#include"NODE.h"
using namespace std;
class SeqStack 
{
private:
	NODE *arr;//数组动态创建
	int top;//栈顶位置
	int size;//最多可储存的元素数目
public:
	//构造函数 初始化动态创建一个顺序栈
	SeqStack(int size);
	//获取压入栈中元素的个数
	int GetNum();
	//判断栈是否为空
	bool SeqStack_isempty();
	//将元素入栈
	void SeqStack_Push(pNODE p);
	//将元素出栈
	void SeqStack_Pop();
	//打印结点
	void print();
	//获取顶部结点
	pNODE GetTop();
	//赋值函数重载
	SeqStack& operator=(const SeqStack&c);
	//清空栈
	void Clear();
	pNODE GetValus();
};
#endif
