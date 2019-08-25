#include "xvision.h"

//求直线交点
void IntersectionLinesFloat(LineFloat* line1, LineFloat* line2, PointFloat * intersection)
{
    float ka, kb;

    //求直线斜率
    ka = (line1->end.y - line1->start.y) / (line1->end.x - line1->start.x);
    kb = (line2->end.y - line2->start.y) / (line2->end.x - line2->start.x);

    intersection->x = (ka * line1->start.x - line1->start.y - kb * line2->start.x + line2->start.y) / (ka - kb);
    intersection->y = (ka * kb * (line1->start.x - line2->start.x) + ka * line2->start.y - kb * line1->start.y) / (ka - kb);

}
