/*
* Copyright (c) 2013,���ӿ�ѧ�о�Ժ
* All rights reserved.
*
* �ļ����ƣ�IComCoorInterface.h
* ժ    Ҫ����������ϵת���ӿ��ļ�
*
*   �����ߣ�����
* �������ڣ�2013��10��23��
* ������ڣ�2013��10��23��
*
* �޸���  ���޸�������
* �޸���ʼ���ڣ�XXXX��XX��XX��
* �޸�������ڣ�XXXX��XX��XX��
* �޸�������������Ҫ�����Ը��ļ����޸����ݣ���������XX������XX��������* ����XX������XX������
*/

#ifndef COMCOORINTERFACE_H
#define COMCOORINTERFACE_H

#include "IPlugInterface.h"

#define ICOMCOORINTERFACE_NAME "ComCoorControl"

//��������ϵת���ӿ���,�ӿ�����ΪComCoorControl
class IComCoorInterface : public IPlugInterface
{
public:
    ////////////////////////////////////////////////////////////////
    // ������:LBH2ECEF
    // ����: pos-- ��ص���(��γ��)����ϵλ�ã�����γ���ߣ�
    // ����ֵ: ���Ŀռ�ֱ������ϵλ�ã�X��Y��Z��
    // ����˵��:��ص���(��γ��)����ϵ(LBH)-->���Ŀռ�ֱ������ϵ(ECEF)��
    ////////////////////////////////////////////////////////////////
    virtual struCartesianCoordPos LBH2ECEF(struGeogCoordPos pos)=0;


    ////////////////////////////////////////////////////////////////
    // ������:ECEF2LBH
    // ����: pos-- ���Ŀռ�ֱ������ϵλ�ã�X��Y��Z��
    // ����ֵ: ��ص���(��γ��)����ϵλ�ã�����γ���ߣ�
    // ����˵��:���Ŀռ�ֱ������ϵ(ECEF))-->��ص���(��γ��)����ϵ(LBH)
    ////////////////////////////////////////////////////////////////
    virtual struGeogCoordPos ECEF2LBH(struCartesianCoordPos pos)=0;


    ////////////////////////////////////////////////////////////////
    // ������:ENU2ECEF
    // ����: pos-- ����������ϵλ�ã�X��Y��Z��
    //      RadarStation--�ֲ��ο���λ�ã�����γ���ߣ�
    // ����ֵ: ���Ŀռ�ֱ������ϵλ�ã�X��Y��Z��
    // ����˵��:����������ϵ(ENU)-->���Ŀռ�ֱ������ϵ(ECEF)
    ////////////////////////////////////////////////////////////////
    virtual struCartesianCoordPos ENU2ECEF(struCartesianCoordPos pos, struGeogCoordPos RadarStation)=0;

    ////////////////////////////////////////////////////////////////
    // ������:ECEF2ENU
    // ����: pos-- ���Ŀռ�ֱ������ϵλ�ã�X��Y��Z��
    //      RadarStation--�ֲ��ο���λ�ã�����γ���ߣ�
    // ����ֵ: ����������ϵλ�ã�X��Y��Z��
    // ����˵��:���Ŀռ�ֱ������ϵ(ECEF)-->����������ϵ(ENU)
    ////////////////////////////////////////////////////////////////
    virtual struCartesianCoordPos ECEF2ENU(struCartesianCoordPos pos, struGeogCoordPos RadarStation)=0;


    ///////////////////////////////////////////////////////////////
    // ������:ECI2ECEF
    // ����: targetECI-- ���Ĺ�������ϵλ�ã�X��Y��Z��
    //      curTime-- ����任��ǰʱ�̣��꣬�£��գ�ʱ���֣��룩
    // ����ֵ: ���Ŀռ�ֱ������ϵλ�ã�X��Y��Z��
    // ����˵��:���Ĺ�������ϵ(ECI)-->���Ŀռ�ֱ������ϵ(ECEF)
    ////////////////////////////////////////////////////////////////
    virtual struCartesianCoordPos ECI2ECEF(struCartesianCoordPos targetECI, struTime curTime)=0;

    ///////////////////////////////////////////////////////////////
    // ������:ECEF2ECI
    // ����: targetECEF-- ���Ŀռ�ֱ������ϵλ�ã�X��Y��Z��
    //      curTime-- ����任��ǰʱ�̣��꣬�£��գ�ʱ���֣��룩
    // ����ֵ: ���Ĺ�������ϵλ�ã�X��Y��Z��
    // ����˵��:���Ŀռ�ֱ������ϵ(ECEF)-->���Ĺ�������ϵ(ECI)
    ////////////////////////////////////////////////////////////////
    virtual struCartesianCoordPos ECEF2ECI(struCartesianCoordPos targetECEF, struTime curTime)=0;


    ///////////////////////////////////////////////////////////////
    // ������:ENU2ECEF_Vel
    // ����: ENUVel-- ����������ϵ�ٶȣ�Vx��Vy��Vz��
    //      ReferencePos--�ֲ��ο���λ�ã�����γ���ߣ�
    // ����ֵ: ���Ŀռ�ֱ������ϵ�ٶȣ�Vx��Vy��Vz��
    // ����˵��:����������ϵ(ENU)�ٶ�-->���Ŀռ�ֱ������ϵ(ECEF)�ٶ�
    ////////////////////////////////////////////////////////////////
    virtual struCartesianCoordVel ENU2ECEF_Vel(struCartesianCoordVel ENUVel, struGeogCoordPos ReferencePos)=0;

    ///////////////////////////////////////////////////////////////
    // ������:ECEF2ENU_Vel
    // ����: ECEFVel-- ���Ŀռ�ֱ������ϵ�ٶȣ�Vx��Vy��Vz��
    //      ReferencePos--�ֲ��ο���λ�ã�����γ���ߣ�
    // ����ֵ: ����������ϵ�ٶȣ�Vx��Vy��Vz��
    // ����˵��:���Ŀռ�ֱ������ϵ(ECEF)�ٶ�-->����������ϵ(ENU)�ٶ�
    ////////////////////////////////////////////////////////////////
    virtual struCartesianCoordVel ECEF2ENU_Vel(struCartesianCoordVel ECEFVel, struGeogCoordPos ReferencePos)=0;


    ///////////////////////////////////////////////////////////////
    // ������:ECI2ECEF_Vel
    // ����: ECIPos-- ���Ĺ�������ϵλ�ã�X��Y��Z��
    //       ECIVel-- ���Ĺ�������ϵ�ٶȣ�Vx��Vy��Vz��
    //       curTime-- ����任��ǰʱ�̣��꣬�£��գ�ʱ���֣��룩
    // ����ֵ: ���Ŀռ�ֱ������ϵ�ٶȣ�Vx��Vy��Vz��
    // ����˵��:���Ĺ�������ϵ(ECI)�ٶ�-->���Ŀռ�ֱ������ϵ(ECEF)�ٶ�
    ////////////////////////////////////////////////////////////////
    virtual struCartesianCoordVel ECI2ECEF_Vel(struCartesianCoordPos ECIPos, struCartesianCoordVel ECIVel, struTime curTime)=0;

    ///////////////////////////////////////////////////////////////
    // ������:ECEF2ECI_Vel
    // ����: ECEFPos-- ���Ŀռ�ֱ������ϵλ�ã�X��Y��Z��
    //       ECEFVel-- ���Ŀռ�ֱ������ϵ�ٶȣ�Vx��Vy��Vz��
    //       curTime-- ����任��ǰʱ�̣��꣬�£��գ�ʱ���֣��룩
    // ����ֵ: ���Ĺ�������ϵ�ٶȣ�Vx��Vy��Vz��
    // ����˵��:���Ŀռ�ֱ������ϵ(ECEF)�ٶ�-->���Ĺ�������ϵ(ECI)�ٶ�
    ////////////////////////////////////////////////////////////////
    virtual struCartesianCoordVel ECEF2ECI_Vel(struCartesianCoordPos ECEFPos, struCartesianCoordVel ECEFVel, struTime curTime)=0;

};

#endif // COMCOORINTERFACE_H
