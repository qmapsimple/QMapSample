#ifndef COORDCONVERTDATASTRUCT_H
#define COORDCONVERTDATASTRUCT_H

// ʱ��ṹ��
typedef struct struTime
{
        double Year;   // ��
        double Month;  // ��
        double Day;    // ��
        double Hour;   // ʱ
        double Minute; // ��
        double Second; // ��
}struTime;

// ��ص�����γ�ߣ�����ϵλ�ýṹ��
typedef struct struGeogCoordPos
{
        double Longitude;  // ���ȣ���λ���ȣ���Χ��-180~180
        double Latitude;   // γ�ȣ���λ���ȣ���Χ��-90~90
        double Height;     // �߶ȣ���λ��km����Χ��>=0
} struGeogCoordPos;

// �ռ�ֱ�ǣ��ѿ���������ϵλ�ýṹ��
typedef struct  struCartesianCoordPos
{
        double X;   // ��λ��km
        double Y;   // ��λ��km
        double Z;   // ��λ��km
} struCartesianCoordPos;

// �ռ�ֱ�ǣ��ѿ���������ϵ�ٶȽṹ��
typedef struct  struCartesianCoordVel
{
        double Vx;   // ��λ��km/s
        double Vy;   // ��λ��km/s
        double Vz;   // ��λ��km/s
} struCartesianCoordVel;

// ������ϵλ�ýṹ��
typedef struct  struSphereCoordPos
{
        double Radius;     // ����࣬��λ��km��>=0km
        double Azimuth;    // ��λ�ǣ���λ���ȣ�����Ϊ0��˳ʱ��0~360��
        double Elevation;  // ����(�ߵͽ�)����λ���ȣ���ֵ��ʾ�ֲ�ˮƽ�����ϣ���ֵ��ʾ�ֲ�ˮƽ������
} struSphereCoordPos;

// ��������̬�ǽṹ��
typedef struct  struCraftAttitude
{
        double ElevationAngle;  // �����ǣ���λ����
        double RollAngle;       // �����ǣ���ת�ǡ�ת���ǣ�����λ����
        double YawAngle;        // ƫ���ǣ���λ����
} struCraftAttitude;

// ���������й����λ�ò����ṹ�壬����������б�ʾ���λ�õ������Ƕ�
typedef struct  struSatOrbitPara
{
        double PeriapsisAngle;      // ���ص���ǣ���λ����
        double OrbitalInclination;  // �����ǣ�  ��λ����
        double RightAscension;      // ������ྭ����λ����
} struSatOrbitPara;

// �ػ�������״�(GBPAR)RUV��������ϵλ�ýṹ��
typedef struct  struGBPARRUVMeasure
{
        double Radius;           //����࣬��λ����
        double uDerectionCos;    //��������u=x/R
        double vDerectionCos;    //��������v=y/R
} struGBPARRUVMeasure;

// ����ǣ���ʾ������״���������ϵ�붫��������ϵ�ļнǹ�ϵ
typedef struct  struArrayPlaneAngle
{
        double ArrayAz;        // ���淽λ�ǣ���λ����
        double ArrayEl;        // ���温���ǣ���λ����
} struArrayPlaneAngle;

// �첨���Ӿ��״�(OTHR)��������ϵ�ṹ��
typedef struct  struOTHRMeasure
{
        double Radius;           // ����࣬��λ��km
        double PlaneAzimuth;     // �淽λ�ǣ���λ����
} struOTHRMeasure;

// OTHR��������ϵλ�ýṹ��
typedef struct  struOTHRGeogPolar
{
        double PolarDistance;         // ���࣬��λ��km
        double DerectionAngle;        // ����ǣ���λ����
} struOTHRGeogPolar;

// OTHR��������ϵת����������ϵ�ĺ�����������ṹ��
typedef struct  struOTHRMeasure2GeogPolarInput
{
        double TargetH;               // Ŀ��߶ȣ���λ��km
        double SWaveIonosphereH;      // ���䲨�����߶ȣ���λ��km
        double RWaveIonosphereH;      // �ز������߶ȣ���λ��km
        double SRDistance;            // �״﷢�������ջ�֮��ľ��룬��λ��km
} struOTHRMeasure2GeogPolarInput;

// OTHR��������ϵת��ECEF����ϵ�ĺ�����������ṹ��
typedef struct  struOTHRMeasure2ECEFInput
{
        struOTHRMeasure2GeogPolarInput InlineInputPara;  // OTHR���⵽OTHR��������ϵ��ת�������ṹ��
        double ThetaAngle;                               // �״����ֱ������ϵ�붫��������ϵ�ļнǣ���OTHR����ʱ��׼�߷�����ָ������ļнǣ���λ����
        struGeogCoordPos RadarStation;                   // �״�վ��ص�������
} struOTHRMeasure2ECEFInput;

// �������ϵͳ(SBIRS)��������ϵ�ṹ��
typedef struct  struSBIRSMeasure
{
        double Azimuth;    // ��λ�ǣ���λ����
        double Elevation;  // ����(�ߵͽ�)����λ����
} struSBIRSMeasure;

// ������������ϵ��ECEF����ϵ��ת�������еĲ����ṹ��
typedef struct struLaunchPara
{
        double AstroLongitude;        // ��������ľ��ȣ���λ����
        double AstroLatitude;         // ���������γ�ȣ���λ����
        double AstroLaunchAz;         // ���ķ��䷽λ�ǣ���λ����
} struLaunchPara;

// ECEFλ������ֵ���Э������
typedef	struct struErrorAnalysisResult
{
        double Mean[3][1];  //��ֵ��
        double Cov[3][3];   //Э������
}struErrorAnalysisResult;

//�ȷ���
typedef struct struDegMinSec
{
    int nDeg;//��
    int nMin;//��
    double dSec;//��
}struDegMinSec;

#endif // COORDCONVERTDATASTRUCT_H
