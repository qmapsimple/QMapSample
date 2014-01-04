#ifndef COORDCONVERTDATASTRUCT_H
#define COORDCONVERTDATASTRUCT_H

// 时间结构体
typedef struct struTime
{
        double Year;   // 年
        double Month;  // 月
        double Day;    // 日
        double Hour;   // 时
        double Minute; // 分
        double Second; // 秒
}struTime;

// 大地地理（经纬高）坐标系位置结构体
typedef struct struGeogCoordPos
{
        double Longitude;  // 经度，单位：度，范围：-180~180
        double Latitude;   // 纬度，单位：度，范围：-90~90
        double Height;     // 高度，单位：km，范围：>=0
} struGeogCoordPos;

// 空间直角（笛卡尔）坐标系位置结构体
typedef struct  struCartesianCoordPos
{
        double X;   // 单位：km
        double Y;   // 单位：km
        double Z;   // 单位：km
} struCartesianCoordPos;

// 空间直角（笛卡尔）坐标系速度结构体
typedef struct  struCartesianCoordVel
{
        double Vx;   // 单位：km/s
        double Vy;   // 单位：km/s
        double Vz;   // 单位：km/s
} struCartesianCoordVel;

// 球坐标系位置结构体
typedef struct  struSphereCoordPos
{
        double Radius;     // 径向距，单位：km，>=0km
        double Azimuth;    // 方位角，单位：度，正北为0，顺时针0~360度
        double Elevation;  // 仰角(高低角)，单位：度，正值表示局部水平面以上，负值表示局部水平面以下
} struSphereCoordPos;

// 飞行器姿态角结构体
typedef struct  struCraftAttitude
{
        double ElevationAngle;  // 俯仰角，单位：度
        double RollAngle;       // 滚动角（滚转角、转动角），单位：度
        double YawAngle;        // 偏航角，单位：度
} struCraftAttitude;

// 航天器运行轨道的位置参数结构体，即轨道根数中表示轨道位置的三个角度
typedef struct  struSatOrbitPara
{
        double PeriapsisAngle;      // 近地点幅角，单位：度
        double OrbitalInclination;  // 轨道倾角，  单位：度
        double RightAscension;      // 升交点赤经，单位：度
} struSatOrbitPara;

// 地基相控阵雷达(GBPAR)RUV量测坐标系位置结构体
typedef struct  struGBPARRUVMeasure
{
        double Radius;           //径向距，单位：度
        double uDerectionCos;    //方向余弦u=x/R
        double vDerectionCos;    //方向余弦v=y/R
} struGBPARRUVMeasure;

// 阵面角，表示相控阵雷达阵面坐标系与东北天坐标系的夹角关系
typedef struct  struArrayPlaneAngle
{
        double ArrayAz;        // 阵面方位角，单位：度
        double ArrayEl;        // 阵面俯仰角，单位：度
} struArrayPlaneAngle;

// 天波超视距雷达(OTHR)量测坐标系结构体
typedef struct  struOTHRMeasure
{
        double Radius;           // 径向距，单位：km
        double PlaneAzimuth;     // 面方位角，单位：度
} struOTHRMeasure;

// OTHR地理极坐标系位置结构体
typedef struct  struOTHRGeogPolar
{
        double PolarDistance;         // 极距，单位：km
        double DerectionAngle;        // 方向角，单位：度
} struOTHRGeogPolar;

// OTHR量测坐标系转换地理极坐标系的函数输入参量结构体
typedef struct  struOTHRMeasure2GeogPolarInput
{
        double TargetH;               // 目标高度，单位：km
        double SWaveIonosphereH;      // 发射波电离层高度，单位：km
        double RWaveIonosphereH;      // 回波电离层高度，单位：km
        double SRDistance;            // 雷达发射机与接收机之间的距离，单位：km
} struOTHRMeasure2GeogPolarInput;

// OTHR量测坐标系转换ECEF坐标系的函数输入参量结构体
typedef struct  struOTHRMeasure2ECEFInput
{
        struOTHRMeasure2GeogPolarInput InlineInputPara;  // OTHR量测到OTHR地理极坐标系的转换参数结构体
        double ThetaAngle;                               // 雷达地理直角坐标系与东北天坐标系的夹角，即OTHR部署时瞄准线方向与指北方向的夹角，单位：度
        struGeogCoordPos RadarStation;                   // 雷达站大地地理坐标
} struOTHRMeasure2ECEFInput;

// 天基红外系统(SBIRS)量测坐标系结构体
typedef struct  struSBIRSMeasure
{
        double Azimuth;    // 方位角，单位：度
        double Elevation;  // 仰角(高低角)，单位：度
} struSBIRSMeasure;

// 导弹发射坐标系到ECEF坐标系的转换矩阵中的参数结构体
typedef struct struLaunchPara
{
        double AstroLongitude;        // 发射点天文经度，单位：度
        double AstroLatitude;         // 发射点天文纬度，单位：度
        double AstroLaunchAz;         // 天文发射方位角，单位：度
} struLaunchPara;

// ECEF位置误差均值阵和协方差阵
typedef	struct struErrorAnalysisResult
{
        double Mean[3][1];  //均值阵
        double Cov[3][3];   //协方差阵
}struErrorAnalysisResult;

//度分秒
typedef struct struDegMinSec
{
    int nDeg;//度
    int nMin;//分
    double dSec;//秒
}struDegMinSec;

#endif // COORDCONVERTDATASTRUCT_H
