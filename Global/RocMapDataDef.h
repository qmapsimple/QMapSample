#ifndef PUBLICDATADEF_INCLUDE
#define PUBLICDATADEF_INCLUDE
#include <vector>
#include <string>
#include <QPoint>
using std::vector;
using std::string;

//定义double点对；如果表示大地坐标点，x为经度，y为纬度，z为高度
struct  RocMap_CDPoint
{
	double x;
	double y;
	double z;
	
	RocMap_CDPoint()
	{
	}
	
	RocMap_CDPoint(double initX, double initY,double initZ = 0.0)
	{
		x = initX;
		y = initY;
		z = initZ;
	}
        void operator = (const QPoint& pt)
	{
                x = pt.x();
                y = pt.y();
		z = 0.0;
	};	
        bool operator == (const RocMap_CDPoint& pt)
	{
		if (x == pt.x && y==pt.y && z==pt.z)
		{
                        return true;
		}
		else
                        return false;
	};	
        bool operator != (const RocMap_CDPoint& pt)
	{
		if (x != pt.x || y!=pt.y || z!=pt.z)
		{
                        return true;
		}
		else
                        return false;
	};	
};

typedef vector<RocMap_CDPoint> RocMap_CDPoints ;

//定义float点对
struct  RocMap_CFPoint
{
	float x;
	float y;
};

//军标属性
struct RocMap_JBAttr
{ 
	int    nJBCode;  //军标编号
	string  sJBName ;  //军标名称
};

//点数据信息
struct RocMap_POI_Info
{
	RocMap_CDPoint dPt;  //经纬度坐标
	string   sName;   //名称
	int nLevel;   //等级
};

//线数据信息
struct RocMap_LIN_Info
{
	vector<RocMap_CDPoint> vdPt;  //经纬度坐标
	string  sName;   //名称
	int nLevel;    //等级
};

struct C_Region_Info 
{
	vector<RocMap_CDPoint>  vdPt;  
};

//面数据信息
struct RocMap_REG_Info
{
	vector<C_Region_Info> vREGInfo;  //经纬度坐标
	string  sName;   //名称
	int nLevel;    //等级
	RocMap_CDPoint RegionCenterPt;  //面中心点
};


typedef struct RocMapPoint
{//地图经纬度点
	long  AE;     //经度,长整型,精度0.01秒
	long  AN;     //纬度
	long  H;      //高,  精度米
	
	RocMapPoint()
	{
		AE = 0;
		AN = 0;
		H = 0;
	};
	~RocMapPoint() {};
	RocMapPoint(long lAE, long lAN, long lH)
	{
		AE = lAE;
		AN = lAN;
		H = lH;
	};
	RocMapPoint(long lAE, long lAN)
	{
		AE = lAE;
		AN = lAN;
		H = 0;
	};
	RocMapPoint(const RocMapPoint& temp)
	{
		AE = temp.AE;
		AN = temp.AN;
		H = temp.H;
	};
        void operator= (const RocMapPoint& temp)
	{
		AE = temp.AE;
		AN = temp.AN;
		H = temp.H;
	};
        bool operator== (const RocMapPoint& temp)
	{
		if (AE == temp.AE && AN == temp.AN && H == temp.H) 
		{
                        return true;
		}
		else
                        return false;
	};
}RocMapPoint;

// 数字地形信息系统中的道路基础空间数据结构	（一条道路的所有信息）
typedef struct RocMapRdInfo
{
	int                 nRdNum;				//道路在所有加载道路中的编号
	string				strRdName;			//道路名称
	unsigned char		RdClass;			//道路等级
	float				fRdLength;			//道路长度   单位:km
	long				lRdFNode;			//道路起点编号
	long				lRdTNode;			//道路终点编号
	int				    nRdNodeNum;			//道路坐标点个数
	vector<RocMap_CDPoint>	RocMapRdNodePos;	//道路坐标点位置  (一条道路的所有节点)
	
	RocMapRdInfo() 
	{                                                         
		nRdNum        = 0 ;
		strRdName	  = "" ;
		RdClass	  = 0 ; 
		fRdLength	  = 0. ;
		lRdFNode	  = 0 ;
		lRdTNode	  = 0 ;
		nRdNodeNum	  = 0 ;
	};
	RocMapRdInfo(const RocMapRdInfo& temp)
	{
		nRdNum        = temp.nRdNum ;
		strRdName	  = temp.strRdName ;
		RdClass	  = temp.RdClass ;
		fRdLength	  = temp.fRdLength ;
		lRdFNode	  = temp.lRdFNode ;
		lRdTNode	  = temp.lRdTNode ;
		nRdNodeNum	  = temp.nRdNodeNum ;
		RocMapRdNodePos = temp.RocMapRdNodePos ;
	};

	~RocMapRdInfo() {};
	
        void operator = (const RocMapRdInfo& temp)
	{
		nRdNum        = temp.nRdNum ;
		strRdName	  = temp.strRdName;
		RdClass	  = temp.RdClass;
		fRdLength	  = temp.fRdLength;
		lRdFNode	  = temp.lRdFNode;
		lRdTNode	  = temp.lRdTNode;
		nRdNodeNum	  = temp.nRdNodeNum;
		RocMapRdNodePos = temp.RocMapRdNodePos;
	}
	
}RocMapRdInfo;

typedef vector<RocMapRdInfo> RocMapRdsInfo;

//一个图幅的道路信息，包括经纬度范围
typedef struct RocMapAtlasRdInfo
{
	//图幅的经纬度范围
	double fLeftTopL;  //左上经度
	double fLeftTopB;	//左上纬度
	double fRightBottomL; //右下经度
	double fRightBottomB; // 右下纬度
	int nStartRdNum ;     //起始道路编号
	int nEndRdNum ;		  //终止道路编号

    RocMapRdsInfo RocMapRdInfos ; //一个图幅的所有道路信息

}RocMapAtlasRdInfo;

//////////////////////////////////////////////////////////////////////////
//数据处理中目标的编队属性
typedef struct FormaAttri
{
	unsigned short Strength;		//目标车辆数 单位:辆
	double		   Course;			//航向       单位:度
	unsigned short Length;			//长度       单位:m
	unsigned short Width;			//宽度       单位:m
	double		   AxisAngle;		//轴向       单位:度
	
	FormaAttri() 
	{
		Strength        = 0;
		Course			= 0.;
		Length			= 0;
		Width			= 0;
		AxisAngle       = 0.;
	};
	FormaAttri(const FormaAttri& temp)
	{
		Strength        = temp.Strength;
		Course			= temp.Course;
		Length			= temp.Length;
		Width			= temp.Width;
		AxisAngle       = temp.AxisAngle;
	};
	~FormaAttri() {};
        void operator = (const FormaAttri& temp)
	{
		Strength        = temp.Strength;
		Course			= temp.Course;
		Length			= temp.Length;
		Width			= temp.Width;
		AxisAngle       = temp.AxisAngle;
	};
}FormaAttri;

enum Map_Show_Level
{//地图显示等级
	SHOW_LEVEL1,  //显示等级1
	SHOW_LEVEL2,  //显示等级2
	SHOW_LEVEL3,  //显示等级3
	SHOW_LEVEL4,  //显示等级4，即世界地图
	SHOW_WORLD_LEVEL,  //显示世界地图等级
	SHOW_COUNTRY_LEVEL,  //显示全国地图等级
};

 //数据处理中道路上的目标状态数据结构
typedef struct RocMapRdTarSt
{
	__int64	 	 nRdTarT;				//目标截获时间     单位:秒
	double		 dRdTarDis2F;			//目标距离所处道路起点的长度 单位:km
	double		 dRdTarV;				//目标矢量速度     单位:m/s
	double		 dRdTarOffRdDis;		//目标离开道路距离 单位:m
	string		 strRdTarRdID;			//目标所处道路编号
	int          nChuiZuNumOnRd; 		//目标在道路上垂足插入道路后的编号
	RocMap_CDPoint	 RocMapRdTarPos;	//目标在道路上的地理坐标	
	RocMapRdInfo  RocMapRdTarRdInfo;	//目标所处道路信息
	
	RocMapRdTarSt() 
	{
		nRdTarT			= 0;
		dRdTarDis2F		= 0.;
		dRdTarV			= 0.;
		dRdTarOffRdDis	= 0.;
		strRdTarRdID	= "";
		nChuiZuNumOnRd = 0 ;
	};
	RocMapRdTarSt(const RocMapRdTarSt& temp)
	{
		nRdTarT			= temp.nRdTarT;
		dRdTarDis2F		= temp.dRdTarDis2F;
		dRdTarV			= temp.dRdTarV;
		dRdTarOffRdDis	= temp.dRdTarOffRdDis;
		strRdTarRdID	= temp.strRdTarRdID;
		RocMapRdTarPos	= temp.RocMapRdTarPos;
		RocMapRdTarRdInfo = temp.RocMapRdTarRdInfo;
		nChuiZuNumOnRd = temp.nChuiZuNumOnRd ;
	};
	~RocMapRdTarSt() {};
        void operator = (const RocMapRdTarSt& temp)
	{
		nRdTarT			= temp.nRdTarT;
		dRdTarDis2F		= temp.dRdTarDis2F;
		dRdTarV			= temp.dRdTarV;
		dRdTarOffRdDis	= temp.dRdTarOffRdDis;
		strRdTarRdID	= temp.strRdTarRdID;
		RocMapRdTarPos	= temp.RocMapRdTarPos;
		RocMapRdTarRdInfo = temp.RocMapRdTarRdInfo;
		nChuiZuNumOnRd = temp.nChuiZuNumOnRd ;
	};
	
}RocMapRdTarSt;	//stateRdTar

typedef vector<RocMapRdTarSt> RocMapRdTarSts;  //stateRdTarV;

typedef struct RocMapRteInfo				   //路径
{
        unsigned int		nRocMapRdsNum;			   //路径中的道路个数
	RocMapRdsInfo	vRocMapRteRdsInfo;	   //路径中的道路信息,道路按顺序排列 
	
	RocMapRteInfo() 
	{
		nRocMapRdsNum = 0;  
	};
	RocMapRteInfo(const RocMapRteInfo& temp)
	{
		nRocMapRdsNum = temp.nRocMapRdsNum;
		vRocMapRteRdsInfo = temp.vRocMapRteRdsInfo ;
	};
	~RocMapRteInfo() {};
        void operator = (const RocMapRteInfo& temp)
	{
		nRocMapRdsNum = temp.nRocMapRdsNum;
		vRocMapRteRdsInfo = temp.vRocMapRteRdsInfo;
	};	
}RocMapRteInfo;

typedef vector<RocMapRteInfo> RocMapRtesInfo;

struct RocMap_ChildLayerInfo 
{//子图层信息
        QString csChildItemName; //子图层名称
        bool bShow;  //此图层是否显示
};
struct RocMap_LayerOrderInfo 
{
        QString csParentItemName;  //父图层名称
	vector<RocMap_ChildLayerInfo> vChildLayerInfo;  //子图层名称
};

struct RocMap_UserLayerInfo
{//用户自定义图层信息
        QString csName; //子图层名称
        bool bShow;  //此图层是否显示
        int nMinShowLevel;  //最小显示等级
        int nMaxShowLevel;  //最大显示等级
};

#endif



