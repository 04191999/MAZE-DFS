#include"maze.h"
#include"SeqStack.h"
#include <stdlib.h> 
#include <time.h>
#include<iostream>
#include"CirSequence.h"
#include<vector>
#include<string>
using namespace cv;
using namespace std; 
extern int gap = 2;
//����ȫ�ֶ�ά����洢ÿ��Ѱ·�������ȼ�
extern int arr[2][4] = { 0 };
//����ȫ�ֱ��������ʼ���Թ�
extern vector<string> initcells(100);
//����ȫ�ֱ�������dfsѰ·���Թ���̬�仯
extern vector<string> tempcells(100);
//��Ѱ·˳������ά����
void Maze::CopyDir(int des[][4]) 
{
	int flag = this->dir.GetStart();
	int count = this->dir.GetSpin();
	for (int j = 0; j < 4; flag = (4+flag + count) % 4,j++)
	{
		des[0][j] =this->dir.GetSeq()[flag].i;
		des[1][j] = this->dir.GetSeq()[flag].j;
	};
}
//���Թ�������Ϊ��i��j���Ľ�����Ϊָ����ɫ
void Maze::DrawBlock(int row, int col, int height, int width,Scalar color) 
{
	Point p1 = Point(col*width + gap, row*height + gap);
	Point p2 = Point((col+1)*width - gap, (row+1)*height - gap);
	rectangle(this->image, p1, p2, color, -1);
};
//�ڳ�ʼ��ʱչʾ�Թ�ͼ
void Maze::DrawMaze()
{
	this->height = this->image.rows / this->rows;
	this->width = this->image.cols / this->columns;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (this->cells[i][j] == ' ')
				this->DrawBlock(i, j, height, width, way_color);
			else
				if (this->cells[i][j] == '0')
				this->DrawBlock(i, j, height, width, wall_color);
		}
		imshow("maze", this->image);
		waitKey(1);
	}
}
//cells�࿽��
void Maze::CellsCopy(vector<string>& des, vector<string>& source)
{
	des.clear();
	for (int i = 0; i <this->rows; i++)
		des.push_back(source[i]);
}
//��ӡ·��
void Maze::PrintPath()
{
	Path.print();
}
//��ӡ�Թ�ͼ
void Maze::PrintMap(SeqStack&sorce)
{
	pNODE p=sorce.GetValus();
	for (int k = 0; k <sorce.GetNum(); k++)
	{
			this->DrawBlock(p[k].i, p[k].j, height, width, pass_color);
			imshow("maze", this->image);
			waitKey(1);
	}
} 
//�жϵ㣨row��column���Ƿ����
bool Maze::Vaild(int row, int column)
{
	bool path = false;
	if (row >= 0 && row < rows&&column >= 0 && column < columns&&cells[row][column] == ' ')
		path = true;
	return path;
};
//����һ�����Ϊ��row��column����ͨ·
bool Maze::ExitMaze(int row, int column)
{
	bool done = false;
	if (Vaild(row, column))
	{
			cells[row][column] = 'B';
			this->DrawBlock(row,column, height, width, pass_color);
			imshow("maze", this->image);
			waitKey(100);
			pNODE p = new NODE;
			p->i = row;
			p->j = column;
			this->Path.SeqStack_Push(p);
			delete[]p;
		if ((row == this->end.i) && (column == this->end.j))
			done = true;
		else
		{
			done = ExitMaze(row+arr[0][0], column + arr[1][0]);
			if (!done)
				done=ExitMaze(row + arr[0][1], column+arr[1][1]);
			if (!done)
				done=ExitMaze(row+arr[0][2], column +arr[1][2]);
			if (!done)
				done=ExitMaze(row +arr[0][3], column+arr[1][3]);
		}
		if (done)
		{
			cells[row][column] = '*'; 
		}
		else
		{
			this->DrawBlock(row, column, height, width, way_color);
			imshow("maze", this->image);
			waitKey(100);
			this->Path.SeqStack_Pop();
		}
	}
	return done;
};
//Ѱ�����·��
void Maze::Slove()
{
	cout << "�������Թ����ĺ�����[0," << this->rows - 1 << "]�������꣺[0," << this->columns - 1 << "]";
	cin >> start.i >> start.j;
	cout << "�������Թ��յ�ĺ�����[0," << this->rows - 1 << "]�������꣺[0," << this->columns - 1 << "]";
	cin >> end.i >> end.j;
	if (  start.i<0|| start.i>this->rows - 1 ||start.j>this->columns - 1 || start.j < 0)
	
	{
		cout << "����Ƿ�������������" << endl;
		return;
	}
	//���ǰһ��Ѱ·��ջ��·��
	this->Path.Clear();
	//����Ѱ·˳��
	this->dir.AdjustSeq(this->start, this->end);
	//�洢Ѱ·˳������arr��
	this->CopyDir(arr);
	//����ʼ�����Թ��洢��cells��
	CellsCopy(cells,initcells);
	//�������յ���ɫ
	if (this->cells[this->start.i][this->start.j] == ' ' && this->cells[this->end.i][this->end.j] == ' ')
	{
		this->DrawBlock(this->start.i, this->start.j, height, width, start_end_color);
		this->DrawBlock(this->end.i, this->end.j, height, width, start_end_color);
		imshow("maze", this->image);
		waitKey(1000);
	}
	//����Ѱ·
	bool done = ExitMaze(start.i, start.j);
	CellsCopy(tempcells, cells);
	SeqStack temppath = this->Path; 
	SeqStack shortestpath= this->Path;
	static int count = 0;
	if (!done)
	{
		cout << "ʧ��" << endl;
		this->DrawBlock(this->start.i, this->start.j, height, width, way_color);
		this->DrawBlock(this->end.i, this->end.j, height, width, way_color);
		imshow("maze", this->image);
		waitKey(10);
		return;
	} 
	else
	{
		for (int i = 0; i < 2; i++)
		{
			cells[Path.GetTop()->i][Path.GetTop()->j] = ' ';
			this->DrawBlock(Path.GetTop()->i, Path.GetTop()->j, height, width, way_color);
			imshow("maze", this->image);
			waitKey(100);
			Path.SeqStack_Pop();
		}
		int tempi, tempj, prei = 0, prej=0;
		while (!Path.SeqStack_isempty())
		{
			tempi = Path.GetTop()->i;
			tempj = Path.GetTop()->j;
			CellsCopy(tempcells, cells);
		
			temppath = this->Path; 
			for(int j=0;j<4;j++)
			{                
				if(tempi + arr[0][j]== prei && tempj + arr[1][j]== prej)
					continue; 
				if (ExitMaze(tempi + arr[0][j], tempj + arr[1][j]))
				{
					count++;
					Path.GetTop()->i, Path.GetTop()->j;
					cout << "-----------------------------�ɹ�·��"<<count<<"--------------------------��" << endl;
					this->PrintMap(Path);
					this->Path.print();
					if (this->Path.GetNum() < shortestpath.GetNum())
						shortestpath.operator=(this->Path);
					int n = this->Path.GetNum() -temppath.GetNum();
					for (int m = 0; m < n; m++)
					{
						this->DrawBlock(Path.GetTop()->i, Path.GetTop()->j, height, width, way_color);
						imshow("maze", this->image);
						waitKey(1);
						Path.SeqStack_Pop();
					}
				}CellsCopy(cells, tempcells);
			}
			prei = tempi; prej = tempj;
			cells[Path.GetTop()->i][Path.GetTop()->j] = ' ';
			this->DrawBlock(Path.GetTop()->i, Path.GetTop()->j, height, width, way_color);
			imshow("maze", this->image);
			waitKey(1);
			Path.SeqStack_Pop();
		}
		this->Path = shortestpath;
		cout << "���·���ĳ���Ϊ��" <<shortestpath.GetNum()<< endl;
		this->PrintPath();
	}
}
Maze::Maze() :Path(SIZE)
{
		cout << "�Թ�����������";
		cin >> rows;
		cin >> columns;
		char *str = new char[columns];
		srand((unsigned)time(0));
		string cellstr;
		this->image = Mat::zeros(40 * this->rows, 40 * this->columns, CV_8UC3);
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				if ((rand() % 10) > 5)
				{
					str[j] = '0';
				}
				else
					str[j] = ' ';
			}
			cellstr = str;
			cells.push_back(cellstr);
		}
	this->CellsCopy(initcells, this->cells);
	this->DrawMaze();
};
