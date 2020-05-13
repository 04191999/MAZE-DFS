#include"SeqStack.h"
#include<iostream>
using namespace std;
void SeqStack::SeqStack_Push(pNODE p) {
	if (this->top == size - 1)
	{
		cout << "Õ»ÒÑÂú";
		cout << endl;
		return;
	};
	this->top++;
	this->arr[top] = *p;
	arr[top].i = p->i;
	arr[top].j = p->j;
};
bool SeqStack::SeqStack_isempty() {
	if (this->top == -1)
	{
		 return true;
	};
	if (this->top > -1)
	{
		return false;
	}
};
int SeqStack::GetNum() 
{
	return this->top + 1; 
}
void SeqStack::print()
{
	int m = 0;
	if (!this->SeqStack_isempty())
		while (1) {

			cout << "<" << arr[m].i << "," << arr[m].j << ">";
			m++;
			if (m > top) {
				cout << endl; return;
			}
		}; 
}
void SeqStack::SeqStack_Pop() 
{
	if (this->top == -1)
	{
		cout << "Õ»ÒÑ¿Õ";

		cout << endl;

		return;
	};
	this->top--;
};
void SeqStack::Clear() {
	while (!this->SeqStack_isempty())
		this->SeqStack_Pop();

};
pNODE SeqStack::GetValus() 
{
	pNODE p = new NODE[this->GetNum()];
	int m = 0;
	if (!this->SeqStack_isempty())
		while (1)
		{
			p[m].i = arr[m].i;
			p[m].j = arr[m].j;
			m++;
			if (m > top)
			 break ;
		};
	return p;
}
SeqStack& SeqStack::operator=(const SeqStack&c)
{
	this->size = c.size;
	this->top = c.top;
	this->arr = new NODE[c.size];
	for (int i = 0; i < size; i++)
	{
		this->arr[i].i = c.arr[i].i;
		this->arr[i].j = c.arr[i].j;
	}
	return *this;
}
pNODE SeqStack::GetTop()
{
	if (top >= 0)
		return &arr[top];
}
SeqStack::SeqStack(int size = SIZE) :size(SIZE)
{
	this->top = -1;
	this->arr = new NODE[SIZE];
};

