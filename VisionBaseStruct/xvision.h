#pragma once

//-----------颜色

//RGB值
typedef struct RGBValue_struct {
    unsigned char B;     //The blue value of the color.
    unsigned char G;     //The green value of the color.
    unsigned char R;     //The red value of the color.
    unsigned char alpha; //The alpha value of the color, which represents extra information about a color image, such as gamma correction.
} RGBValue;

//-----------几何

//点
typedef struct Point_struct {
    int x; //The x-coordinate of the point.
    int y; //The y-coordinate of the point.
} Point;

//线
typedef struct Line_struct {
    Point start; //The coordinate location of the start of the line.
    Point end;   //The coordinate location of the end of the line.
} Line;

//矩阵
typedef struct Rect_struct {
    int top;    //Location of the top edge of the rectangle.
    int left;   //Location of the left edge of the rectangle.
    int height; //Height of the rectangle.
    int width;  //Width of the rectangle.
} Rect;

//旋转矩阵
typedef struct RotatedRect_struct {
    int    top;    //Location of the top edge of the rectangle before rotation.
    int    left;   //Location of the left edge of the rectangle before rotation.
    int    height; //Height of the rectangle.
    int    width;  //Width of the rectangle.
    double angle;  //The rotation, in degrees, of the rectangle.
} RotatedRect;

//闭合轮廓
typedef struct ClosedContour_struct {
    Point* points;    //The points that make up the closed contour.
    int    numPoints; //The number of points in the array.
} ClosedContour;

//开放轮廓
typedef struct OpenContour_struct {
    Point* points;    //The points that make up the open contour.
    int    numPoints; //The number of points in the array.
} OpenContour;

//圆环
typedef struct Annulus_struct {
    Point  center;      //The coordinate location of the center of the annulus.
    int    innerRadius; //The internal radius of the annulus.
    int    outerRadius; //The external radius of the annulus.
    double startAngle;  //The start angle, in degrees, of the annulus.
    double endAngle;    //The end angle, in degrees, of the annulus.
} Annulus;

//轮廓共同体
typedef union ContourUnion_union {
    Point* point;           //Use this member when the contour is of type IMAQ_POINT.
    Line* line;            //Use this member when the contour is of type IMAQ_LINE.
    Rect* rect;            //Use this member when the contour is of type IMAQ_RECT.
    Rect* ovalBoundingBox; //Use this member when the contour is of type IMAQ_OVAL.
    ClosedContour* closedContour;   //Use this member when the contour is of type IMAQ_CLOSED_CONTOUR.
    OpenContour* openContour;     //Use this member when the contour is of type IMAQ_OPEN_CONTOUR.
    Annulus* annulus;         //Use this member when the contour is of type IMAQ_ANNULUS.
    RotatedRect* rotatedRect;     //Use this member when the contour is of type IMAQ_ROTATED_RECT.
} ContourUnion;

typedef enum ContourType_enum {
    IMAQ_EMPTY_CONTOUR = 0,           //The contour is empty.
    IMAQ_POINT = 1,           //The contour represents a point.
    IMAQ_LINE = 2,           //The contour represents a line.
    IMAQ_RECT = 3,           //The contour represents a rectangle.
    IMAQ_OVAL = 4,           //The contour represents an oval.
    IMAQ_CLOSED_CONTOUR = 5,           //The contour represents a series of connected points where the last point connects to the first.
    IMAQ_OPEN_CONTOUR = 6,           //The contour represents a series of connected points where the last point does not connect to the first.
    IMAQ_ANNULUS = 7,           //The contour represents an annulus.
    IMAQ_ROTATED_RECT = 8,           //The contour represents a rotated rectangle.
    IMAQ_CONTOUR_TYPE_SIZE_GUARD = 0xFFFFFFFF
} ContourType;

//轮廓信息(点集合)
typedef struct ContourInfo_struct {
    ContourType type;         //The contour type.
    unsigned    numPoints;    //The number of points that make up the contour.
    Point* points;       //The points describing the contour.
    RGBValue    contourColor; //The contour color.
} ContourInfo;

//轮廓信息(几何)
typedef struct ContourInfo2_struct {
    ContourType  type;      //The contour type.
    RGBValue     color;     //The contour color.
    ContourUnion structure; //The information necessary to describe the contour in coordinate space.
} ContourInfo2;

//二维float类型点
typedef struct PointFloat_struct {
    float x; //The x-coordinate of the point.
    float y; //The y-coordinate of the point.
} PointFloat;

//线
typedef struct LineFloat_struct {
    PointFloat start; //The coordinate location of the start of the line.
    PointFloat end;   //The coordinate location of the end of the line.
} LineFloat;

//圆(局部)
typedef struct PartialCircle_struct {
    PointFloat center;     //Center of the circle.
    double     radius;     //Radius of the circle.
    double     startAngle; //Start angle of the fitted structure.
    double     endAngle;   //End angle of the fitted structure.
} PartialCircle;

//椭圆(局部)
typedef struct PartialEllipse_struct {
    PointFloat center;      //Center of the Ellipse.
    double     angle;       //Angle of the ellipse.
    double     majorRadius; //The length of the semi-major axis of the ellipse.
    double     minorRadius; //The length of the semi-minor axis of the ellipse.
    double     startAngle;  //Start angle of the fitted structure.
    double     endAngle;    //End angle of the fitted structure.
} PartialEllipse;

//二维double类型点
typedef struct PointDouble_struct {
    double x; //The x-coordinate of the point.
    double y; //The y-coordinate of the point.
} PointDouble;

//-----------坐标系

typedef struct StereoCoordPtFloat_struct {
    float x;     //x coordinate
    float y;     //y coordinate
} StereoCoordPtFloat;

typedef struct StereoPointDbl3D_struct {
    double x;   //x coordinate
    double y;   //y coordinate
    double z;   //z coordinate
} StereoPointDbl3D;

//标定点
typedef struct CalibrationPoints_struct {
    PointFloat* pixelCoordinates;     //The array of pixel coordinates.
    PointFloat* realWorldCoordinates; //The array of corresponding real-world coordinates.
    int         numCoordinates;       //The number of coordinates in both of the arrays.
} CalibrationPoints;

//坐标系转换
typedef struct CoordinateTransform_struct {
    Point initialOrigin; //The origin of the initial coordinate system.
    float initialAngle;  //The angle, in degrees, of the x-axis of the initial coordinate system relative to the image x-axis.
    Point finalOrigin;   //The origin of the final coordinate system.
    float finalAngle;    //The angle, in degrees, of the x-axis of the final coordinate system relative to the image x-axis.
} CoordinateTransform;

typedef enum AxisOrientation_enum {
    IMAQ_DIRECT = 0,           //The y-axis direction corresponds to the y-axis direction of the Cartesian coordinate system.
    IMAQ_INDIRECT = 1,           //The y-axis direction corresponds to the y-axis direction of an image.
    IMAQ_AXIS_ORIENTATION_SIZE_GUARD = 0xFFFFFFFF
} AxisOrientation;

typedef struct CoordinateSystem_struct {
    PointFloat      origin;          //The origin of the coordinate system.
    float           angle;           //The angle, in degrees, of the x-axis of the coordinate system relative to the image x-axis.
    AxisOrientation axisOrientation; //The direction of the y-axis of the coordinate reference system.
} CoordinateSystem;

typedef struct CoordinateTransform2_struct {
    CoordinateSystem referenceSystem;   //Defines the coordinate system for input coordinates.
    CoordinateSystem measurementSystem; //Defines the coordinate system in which the function should perform measurements.
} CoordinateTransform2;


//-------其他
typedef struct Range_struct {
    int minValue; //The minimum value of the range.
    int maxValue; //The maximum value of the range.
} Range;
