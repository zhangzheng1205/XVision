// VisionBaseStruct.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "xvision.h"

//求直线交点
extern void IntersectionLinesFloat(LineFloat* line1, LineFloat* line2, PointFloat* intersection);

int main()
{
    LineFloat line1;
    line1.start.y = 168.61f;
    line1.start.x = 568.82f;
    line1.end.y = 887.63f;
    line1.end.x = 543.81f;
    LineFloat line2;
    line2.start.y = 173.18f;
    line2.start.x = 647.44f;
    line2.end.y = 790.82f;
    line2.end.x = 589.56f;
    PointFloat intersection1;
    IntersectionLinesFloat(&line1, &line2, &intersection1);

    LineFloat line3;
    line3.start.y = 0;
    line3.start.x = 0;
    line3.end.y = 0;
    line3.end.x = 100;
    LineFloat line4;
    line4.start.y = 1;
    line4.start.x = 0;
    line4.end.y = 1;
    line4.end.x = 200;
    PointFloat intersection2;
    IntersectionLinesFloat(&line3, &line4, &intersection2);

}
