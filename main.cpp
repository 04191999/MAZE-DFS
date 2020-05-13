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
	cout << "是否需要重新设置起始点？若需要请输入yes，否则请输入no:"<<endl;
	string instruction;
	cin >> instruction;
	if (instruction == "yes")
	while (1)
	{
		a.Slove();
		instruction.clear();
		cout << "是否需要重新设置起始点？若需要请输入yes，否则请输入no:" << endl;
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
















