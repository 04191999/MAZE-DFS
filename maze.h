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
	//���캯��
	Maze();
	//�������·��
	void Slove();
	//��ӡ·��
	void PrintPath();
	//��ӡ�Թ�
	void PrintMap(SeqStack&sorce);
private:
	//��Ѱ·�����Ƶ�һ����ά����
	void CopyDir(int des[][4]);
	//�����������ȼ�
	CirSequence dir;
	//�Թ�ͼ�λ�,��ʾ
	Mat image;
	//�Թ�ͼ
	vector<string>cells; 
    //���񻮷ֺ��������
	int height, width;
	//�Թ�����������
	int rows, columns;
	//dfs����·����㣬�յ�
	NODE start, end;
    //����·��
	SeqStack Path;
	//�����Թ�
	void CellsCopy(vector<string>& des, vector<string>& source);
	//Ѱ·
	bool ExitMaze(int row, int column);
	//�жϽ���Ƿ��ͨ��
	bool Vaild(int row, int column);
	void DrawBlock(int row, int col, int height, int width, Scalar color);
	void DrawMaze();
	
};
#endif