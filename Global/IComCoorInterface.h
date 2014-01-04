/*
* Copyright (c) 2013,电子科学研究院
* All rights reserved.
*
* 文件名称：IComCoorInterface.h
* 摘    要：公共坐标系转换接口文件
*
*   创建者：刘筱
* 创建日期：2013年10月23日
* 完成日期：2013年10月23日
*
* 修改者  ：修改者名字
* 修改起始日期：XXXX年XX月XX日
* 修改完成日期：XXXX年XX月XX日
* 修改内容描述：简要描述对该文件的修改内容，如增加了XX方法、XX变量，修* 改了XX方法、XX变量。
*/

#ifndef COMCOORINTERFACE_H
#define COMCOORINTERFACE_H

#include "IPlugInterface.h"

#define ICOMCOORINTERFACE_NAME "ComCoorControl"

//公共坐标系转换接口类,接口名称为ComCoorControl
class IComCoorInterface : public IPlugInterface
{
public:
    ////////////////////////////////////////////////////////////////
    // 函数名:LBH2ECEF
    // 参数: pos-- 大地地理(经纬高)坐标系位置（经，纬，高）
    // 返回值: 地心空间直角坐标系位置（X，Y，Z）
    // 函数说明:大地地理(经纬高)坐标系(LBH)-->地心空间直角坐标系(ECEF)：
    ////////////////////////////////////////////////////////////////
    virtual struCartesianCoordPos LBH2ECEF(struGeogCoordPos pos)=0;


    ////////////////////////////////////////////////////////////////
    // 函数名:ECEF2LBH
    // 参数: pos-- 地心空间直角坐标系位置（X，Y，Z）
    // 返回值: 大地地理(经纬高)坐标系位置（经，纬，高）
    // 函数说明:地心空间直角坐标系(ECEF))-->大地地理(经纬高)坐标系(LBH)
    ////////////////////////////////////////////////////////////////
    virtual struGeogCoordPos ECEF2LBH(struCartesianCoordPos pos)=0;


    ////////////////////////////////////////////////////////////////
    // 函数名:ENU2ECEF
    // 参数: pos-- 东北天坐标系位置（X，Y，Z）
    //      RadarStation--局部参考点位置（经，纬，高）
    // 返回值: 地心空间直角坐标系位置（X，Y，Z）
    // 函数说明:东北天坐标系(ENU)-->地心空间直角坐标系(ECEF)
    ////////////////////////////////////////////////////////////////
    virtual struCartesianCoordPos ENU2ECEF(struCartesianCoordPos pos, struGeogCoordPos RadarStation)=0;

    ////////////////////////////////////////////////////////////////
    // 函数名:ECEF2ENU
    // 参数: pos-- 地心空间直角坐标系位置（X，Y，Z）
    //      RadarStation--局部参考点位置（经，纬，高）
    // 返回值: 东北天坐标系位置（X，Y，Z）
    // 函数说明:地心空间直角坐标系(ECEF)-->东北天坐标系(ENU)
    ////////////////////////////////////////////////////////////////
    virtual struCartesianCoordPos ECEF2ENU(struCartesianCoordPos pos, struGeogCoordPos RadarStation)=0;


    ///////////////////////////////////////////////////////////////
    // 函数名:ECI2ECEF
    // 参数: targetECI-- 地心惯性坐标系位置（X，Y，Z）
    //      curTime-- 坐标变换当前时刻（年，月，日，时，分，秒）
    // 返回值: 地心空间直角坐标系位置（X，Y，Z）
    // 函数说明:地心惯性坐标系(ECI)-->地心空间直角坐标系(ECEF)
    ////////////////////////////////////////////////////////////////
    virtual struCartesianCoordPos ECI2ECEF(struCartesianCoordPos targetECI, struTime curTime)=0;

    ///////////////////////////////////////////////////////////////
    // 函数名:ECEF2ECI
    // 参数: targetECEF-- 地心空间直角坐标系位置（X，Y，Z）
    //      curTime-- 坐标变换当前时刻（年，月，日，时，分，秒）
    // 返回值: 地心惯性坐标系位置（X，Y，Z）
    // 函数说明:地心空间直角坐标系(ECEF)-->地心惯性坐标系(ECI)
    ////////////////////////////////////////////////////////////////
    virtual struCartesianCoordPos ECEF2ECI(struCartesianCoordPos targetECEF, struTime curTime)=0;


    ///////////////////////////////////////////////////////////////
    // 函数名:ENU2ECEF_Vel
    // 参数: ENUVel-- 东北天坐标系速度（Vx，Vy，Vz）
    //      ReferencePos--局部参考点位置（经，纬，高）
    // 返回值: 地心空间直角坐标系速度（Vx，Vy，Vz）
    // 函数说明:东北天坐标系(ENU)速度-->地心空间直角坐标系(ECEF)速度
    ////////////////////////////////////////////////////////////////
    virtual struCartesianCoordVel ENU2ECEF_Vel(struCartesianCoordVel ENUVel, struGeogCoordPos ReferencePos)=0;

    ///////////////////////////////////////////////////////////////
    // 函数名:ECEF2ENU_Vel
    // 参数: ECEFVel-- 地心空间直角坐标系速度（Vx，Vy，Vz）
    //      ReferencePos--局部参考点位置（经，纬，高）
    // 返回值: 东北天坐标系速度（Vx，Vy，Vz）
    // 函数说明:地心空间直角坐标系(ECEF)速度-->东北天坐标系(ENU)速度
    ////////////////////////////////////////////////////////////////
    virtual struCartesianCoordVel ECEF2ENU_Vel(struCartesianCoordVel ECEFVel, struGeogCoordPos ReferencePos)=0;


    ///////////////////////////////////////////////////////////////
    // 函数名:ECI2ECEF_Vel
    // 参数: ECIPos-- 地心惯性坐标系位置（X，Y，Z）
    //       ECIVel-- 地心惯性坐标系速度（Vx，Vy，Vz）
    //       curTime-- 坐标变换当前时刻（年，月，日，时，分，秒）
    // 返回值: 地心空间直角坐标系速度（Vx，Vy，Vz）
    // 函数说明:地心惯性坐标系(ECI)速度-->地心空间直角坐标系(ECEF)速度
    ////////////////////////////////////////////////////////////////
    virtual struCartesianCoordVel ECI2ECEF_Vel(struCartesianCoordPos ECIPos, struCartesianCoordVel ECIVel, struTime curTime)=0;

    ///////////////////////////////////////////////////////////////
    // 函数名:ECEF2ECI_Vel
    // 参数: ECEFPos-- 地心空间直角坐标系位置（X，Y，Z）
    //       ECEFVel-- 地心空间直角坐标系速度（Vx，Vy，Vz）
    //       curTime-- 坐标变换当前时刻（年，月，日，时，分，秒）
    // 返回值: 地心惯性坐标系速度（Vx，Vy，Vz）
    // 函数说明:地心空间直角坐标系(ECEF)速度-->地心惯性坐标系(ECI)速度
    ////////////////////////////////////////////////////////////////
    virtual struCartesianCoordVel ECEF2ECI_Vel(struCartesianCoordPos ECEFPos, struCartesianCoordVel ECEFVel, struTime curTime)=0;

};

#endif // COMCOORINTERFACE_H
