// VisionBaseStruct.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "xvision.h"

//求直线交点
extern void IntersectionLinesFloat(LineFloat* line1, LineFloat* line2, PointFloat* intersection);

int main()
{
    LineFloat line1;
    line1.start.x = 168.61;
    line1.start.y = 568.82;
    line1.end.x = 887.63;
    line1.end.y = 543.81;
    LineFloat line2;
    line2.start.x = 173.18;
    line2.start.y = 647.44;
    line2.end.x = 790.82;
    line2.end.y = 589.56;
    PointFloat intersection;
    IntersectionLinesFloat(&line1, &line2, &intersection);

    
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
