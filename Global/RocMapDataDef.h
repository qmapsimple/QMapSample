#ifndef PUBLICDATADEF_INCLUDE
#define PUBLICDATADEF_INCLUDE
#include <vector>
#include <string>
#include <QPoint>
using std::vector;
using std::string;

//����double��ԣ������ʾ�������㣬xΪ���ȣ�yΪγ�ȣ�zΪ�߶�
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

//����float���
struct  RocMap_CFPoint
{
	float x;
	float y;
};

//��������
struct RocMap_JBAttr
{ 
	int    nJBCode;  //������
	string  sJBName ;  //��������
};

//��������Ϣ
struct RocMap_POI_Info
{
	RocMap_CDPoint dPt;  //��γ������
	string   sName;   //����
	int nLevel;   //�ȼ�
};

//��������Ϣ
struct RocMap_LIN_Info
{
	vector<RocMap_CDPoint> vdPt;  //��γ������
	string  sName;   //����
	int nLevel;    //�ȼ�
};

struct C_Region_Info 
{
	vector<RocMap_CDPoint>  vdPt;  
};

//��������Ϣ
struct RocMap_REG_Info
{
	vector<C_Region_Info> vREGInfo;  //��γ������
	string  sName;   //����
	int nLevel;    //�ȼ�
	RocMap_CDPoint RegionCenterPt;  //�����ĵ�
};


typedef struct RocMapPoint
{//��ͼ��γ�ȵ�
	long  AE;     //����,������,����0.01��
	long  AN;     //γ��
	long  H;      //��,  ������
	
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

// ���ֵ�����Ϣϵͳ�еĵ�·�����ռ����ݽṹ	��һ����·��������Ϣ��
typedef struct RocMapRdInfo
{
	int                 nRdNum;				//��·�����м��ص�·�еı��
	string				strRdName;			//��·����
	unsigned char		RdClass;			//��·�ȼ�
	float				fRdLength;			//��·����   ��λ:km
	long				lRdFNode;			//��·�����
	long				lRdTNode;			//��·�յ���
	int				    nRdNodeNum;			//��·��������
	vector<RocMap_CDPoint>	RocMapRdNodePos;	//��·�����λ��  (һ����·�����нڵ�)
	
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

//һ��ͼ���ĵ�·��Ϣ��������γ�ȷ�Χ
typedef struct RocMapAtlasRdInfo
{
	//ͼ���ľ�γ�ȷ�Χ
	double fLeftTopL;  //���Ͼ���
	double fLeftTopB;	//����γ��
	double fRightBottomL; //���¾���
	double fRightBottomB; // ����γ��
	int nStartRdNum ;     //��ʼ��·���
	int nEndRdNum ;		  //��ֹ��·���

    RocMapRdsInfo RocMapRdInfos ; //һ��ͼ�������е�·��Ϣ

}RocMapAtlasRdInfo;

//////////////////////////////////////////////////////////////////////////
//���ݴ�����Ŀ��ı������
typedef struct FormaAttri
{
	unsigned short Strength;		//Ŀ�공���� ��λ:��
	double		   Course;			//����       ��λ:��
	unsigned short Length;			//����       ��λ:m
	unsigned short Width;			//���       ��λ:m
	double		   AxisAngle;		//����       ��λ:��
	
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
{//��ͼ��ʾ�ȼ�
	SHOW_LEVEL1,  //��ʾ�ȼ�1
	SHOW_LEVEL2,  //��ʾ�ȼ�2
	SHOW_LEVEL3,  //��ʾ�ȼ�3
	SHOW_LEVEL4,  //��ʾ�ȼ�4���������ͼ
	SHOW_WORLD_LEVEL,  //��ʾ�����ͼ�ȼ�
	SHOW_COUNTRY_LEVEL,  //��ʾȫ����ͼ�ȼ�
};

 //���ݴ����е�·�ϵ�Ŀ��״̬���ݽṹ
typedef struct RocMapRdTarSt
{
	__int64	 	 nRdTarT;				//Ŀ��ػ�ʱ��     ��λ:��
	double		 dRdTarDis2F;			//Ŀ�����������·���ĳ��� ��λ:km
	double		 dRdTarV;				//Ŀ��ʸ���ٶ�     ��λ:m/s
	double		 dRdTarOffRdDis;		//Ŀ���뿪��·���� ��λ:m
	string		 strRdTarRdID;			//Ŀ��������·���
	int          nChuiZuNumOnRd; 		//Ŀ���ڵ�·�ϴ�������·��ı��
	RocMap_CDPoint	 RocMapRdTarPos;	//Ŀ���ڵ�·�ϵĵ�������	
	RocMapRdInfo  RocMapRdTarRdInfo;	//Ŀ��������·��Ϣ
	
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

typedef struct RocMapRteInfo				   //·��
{
        unsigned int		nRocMapRdsNum;			   //·���еĵ�·����
	RocMapRdsInfo	vRocMapRteRdsInfo;	   //·���еĵ�·��Ϣ,��·��˳������ 
	
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
{//��ͼ����Ϣ
        QString csChildItemName; //��ͼ������
        bool bShow;  //��ͼ���Ƿ���ʾ
};
struct RocMap_LayerOrderInfo 
{
        QString csParentItemName;  //��ͼ������
	vector<RocMap_ChildLayerInfo> vChildLayerInfo;  //��ͼ������
};

struct RocMap_UserLayerInfo
{//�û��Զ���ͼ����Ϣ
        QString csName; //��ͼ������
        bool bShow;  //��ͼ���Ƿ���ʾ
        int nMinShowLevel;  //��С��ʾ�ȼ�
        int nMaxShowLevel;  //�����ʾ�ȼ�
};

#endif



