#include"maze.h"
#include<iostream>
#include <stdlib.h> 
#include"CirSequence.h"
#include<string>
using namespace cv;
using namespace std;
int main()
{
	namedWindow("maze");
	Maze a;
	a.Slove();
	cout << "�Ƿ���Ҫ����������ʼ�㣿����Ҫ������yes������������no:"<<endl;
	string instruction;
	cin >> instruction;
	if (instruction == "yes")
	while (1)
	{
		a.Slove();
		instruction.clear();
		cout << "�Ƿ���Ҫ����������ʼ�㣿����Ҫ������yes������������no:" << endl;
		cin >> instruction;
		if (instruction == "yes")
			continue;
		else 
			break;
	}
	destroyWindow("maze");
    system("pause");
	return 0;
}
















