#pragma once
#ifndef NODE_H
#define NODE_H
#include<math.h>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/objdetect/objdetect.hpp>
#include<opencv2/imgproc/types_c.h>
using namespace cv;
typedef struct NODE
{
	int i=0, j=0;
}*pNODE;
const Scalar wall_color(100, 200, 200);
const Scalar way_color(30, 70, 20);
const Scalar pass_color(300, 150, 100);
const Scalar start_end_color(120, 100, 100);
const int SIZE = 10000;
#endif // !NODE_H
