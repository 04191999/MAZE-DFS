#pragma once
#ifndef MAZE_H
#define MAZE_H
#include<string>
#include<iostream>
#include<vector>
#include"SeqStack.h"
#include"CirSequence.h"
#include<opencv2\core\core.hpp>
#include<opencv2\highgui.hpp>
using namespace std; 
class Maze {	
public :
	//构造函数
	Maze();
	//搜索最短路径
	void Slove();
	//打印路径
	void PrintPath();
	//打印迷宫
	void PrintMap(SeqStack&sorce);
private:
	//将寻路方向复制到一个二维数组
	void CopyDir(int des[][4]);
	//搜索方向优先级
	CirSequence dir;
	//迷宫图形化,显示
	Mat image;
	//迷宫图
	vector<string>cells; 
    //网格划分后的行列数
	int height, width;
	//迷宫行数、列数
	int rows, columns;
	//dfs搜索路径起点，终点
	NODE start, end;
    //搜索路径
	SeqStack Path;
	//复制迷宫
	void CellsCopy(vector<string>& des, vector<string>& source);
	//寻路
	bool ExitMaze(int row, int column);
	//判断结点是否可通过
	bool Vaild(int row, int column);
	void DrawBlock(int row, int col, int height, int width, Scalar color);
	void DrawMaze();
	
};
#endif