/*
* Copyright (c) 2013,电子科学研究院
* All rights reserved.
*
* 文件名称：IMap2DInterface.h
* 摘    要：二维地图接口头文件
*
*   创建者：刘筱
* 创建日期：2013年3月10日
* 完成日期：2013年10月13日
*
* 修改者  ：修改者名字
* 修改起始日期：XXXX年XX月XX日
* 修改完成日期：XXXX年XX月XX日
* 修改内容描述：简要描述对该文件的修改内容，如增加了XX方法、XX变量，修* 改了XX方法、XX变量。
*/

#ifndef IMAP2DINTERFACE_H
#define IMAP2DINTERFACE_H

#include <IPlugInterface.h>
#include <RocMapDataDef.h>

class IMap2DInterface:public IPlugInterface
{
public:
    //////////////////////////////////////////////////////////////////////////
            //地图基本操作 begin
    //////////////////////////////////////////////////////////////////////////
    //函数功能：刷新地图
    //输入参数：无
    //输出参数：无
    //返回值：无
    virtual void Refresh()=0;

    //函数功能: 地图漫游拖动
    //输入参数: 无
    //输出参数:无
    //返回值: 无
    virtual void Wander()=0;

    //函数功能: 地图漫游到指定点
    //输入参数: dPt：预漫游位置(经纬度)
    //输出参数:无
    //返回值: 无
    virtual void Wander(RocMap_CDPoint dPt)=0;

    //函数功能: 地图放大
    //输入参数: 无
    //输出参数:无
    //返回值: 无
    virtual void ZoomIn()=0;

    //函数功能: 地图以指定系数放大（缩放点为屏幕中心点）
    //输入参数: fZoomFactor：缩放系数(必须大于1)
    //输出参数:无
    //返回值: 无
    virtual void ZoomIn(float fZoomFactor)=0;

    //函数功能: 地图以指定系数、指定点放大
    //输入参数: fZoomFactor：缩放系数(必须大于1)；dPt：指定中心点(经纬度)
    //输出参数:无
    //返回值: 无
    virtual void ZoomIn(float fZoomFactor,RocMap_CDPoint dPt)=0;

    //函数功能: 地图缩小
    //输入参数: 无
    //输出参数:无
    //返回值: 无
    virtual void ZoomOut()=0;

    //函数功能: 地图以指定系数缩小（缩放点为屏幕中心点）
    //输入参数: fZoomFactor：缩放系数(必须小于1大于0)
    //输出参数:无
    //返回值: 无
    virtual void ZoomOut(float fZoomFactor)=0;

    //函数功能: 地图以指定系数、指定点缩小
    //输入参数: fZoomFactor：缩放系数(必须小于1大于0)；dPt：指定中心点(经纬度)
    //输出参数:无
    //返回值: 无
    virtual void ZoomOut(float fZoomFactor,RocMap_CDPoint dPt)=0;

    //函数功能: 地图恢复初始状态（初始位置和比例尺等）
    //输入参数: 无
    //输出参数:无
    //返回值: 无
    virtual void Back()=0;

    //函数功能:鼠标指针状态，恢复当前鼠标操作
    //输入参数: 无
    //输出参数:无
    //返回值: 无
    virtual void Pointer()=0;

    //函数功能:获取地图图层顺序
    //输入参数: 无
    //输出参数:vLayerOrderInfo：图层顺序信息
    //返回值: 无
    virtual void GetMapLayerOrder(vector<RocMap_LayerOrderInfo> &vLayerOrderInfo)=0;

    //函数功能:设置地图图层顺序(设置地图图层之前必须调用GetLayerOrder()获取原图层顺序后进行重新设置)
    //输入参数: vLayerOrderInfo：各图层名称数组
    //输出参数:无
    //返回值: 无
    virtual void SetMapLayerOrder(vector<RocMap_LayerOrderInfo> vLayerOrderInfo)=0;

    //函数功能:设置地图子图层显隐
    //输入参数: csLayerName：图层名称; bShow：TRUE 显示，FALSE 隐藏
    //输出参数:无
    //返回值: 无
    virtual void SetMapLayerVisible(QString csLayerName,BOOL bShow)=0;

    //函数功能:创建用户自定义图层（如果已有该图层，则将此图层置为当前）
    //输入参数: csLayerName：图层名称
    //输出参数:无
    //返回值: 无
    virtual void CreateLayer(QString csLayerName)=0;

    //函数功能:设置用户自定义图层显隐
    //输入参数: csLayerName：图层名称; bShow：TRUE 显示，FALSE 隐藏
    //输出参数:无
    //返回值: 无
    virtual void SetLayerVisible(QString csLayerName,BOOL bShow)=0;

    //函数功能:获取地图图层顺序
    //输入参数: 无
    //输出参数:vLayerInfo：图层顺序信息
    //返回值: 无
    virtual void GetLayerOrder(vector<RocMap_UserLayerInfo> &vLayerInfo)=0;

    //函数功能:设置地图图层顺序(设置地图图层之前必须调用GetLayerOrder()获取原图层顺序后进行重新设置)
    //输入参数: vLayerInfo：各图层名称数组
    //输出参数:无
    //返回值: 无
    virtual void SetLayerOrder(vector<RocMap_UserLayerInfo> vLayerInfo)=0;

    //函数功能: 控制是否显示比例尺工具条
    //输入参数: bShow：TRUE 显示， FALSE 隐藏(默认为TRUE)
    //输出参数:无
    //返回值: 无
    virtual void ShowMapScaleBar(BOOL bShow)=0;

    //////////////////////////////////////////////////////////////////////////
            //地图基本操作 end
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
            //绘制、删除、管理要素 begin
    //////////////////////////////////////////////////////////////////////////

    /////////////////////////////////////////////////////////////////////////////////////////////
    //函数功能: 绘制线要素(默认样式：线宽为1个像素，样式为实线，颜色红色)
    //传入参数: strID：线的标识；vdPt：线上的点坐标（经纬度）
    //输出参数:无
    //返回值: 无
    /////////////////////////////////////////////////////////////////////////////////////////////
    virtual void DrawLine(const char* strID,vector<RocMap_CDPoint> vdPt)=0;

    //函数功能: 设置文本（包括点、线、面等要素label）样式(默认字体样式：字体为宋体，大小为14，颜色红色)
    //输入参数: font：字体样式(宋体,楷体_GB2312等); color：文本颜色
    //输入参数: bgcolor：背景颜色(默认RGB(-1,-1,-1)表示不填充); bgalpha：背景颜色透明度; bgoutlinecolor：背景轮廓线颜色(默认RGB(-1,-1,-1)表示不绘制轮廓线)
    //输出参数:无
    //返回值: 无
    virtual void SetTextStyle(QFont font = QFont("Times", 10, QFont::Bold),QColor color = QColor(255,0,0),QColor bgcolor = QColor(-1,-1,-1),
                                  float bgalpha = 0.5,QColor bgoutlinecolor = QColor(-1,-1,-1))=0;

    //函数功能: 控制文本是否允许拖动
    //输入参数: bDrag：TRUE 允许,FALSE 不允许(默认为FALSE)
    //输出参数:无
    //返回值: 无
    virtual void DragText(BOOL bDrag)=0;

    //函数功能: 绘制文本(默认字体样式：字体为宋体，大小为14，颜色红色)
    //输入参数: strID：文本ID; strContent：文本内容; dPt：点坐标(经纬度)
    //输出参数:无
    //返回值: 无
    virtual void DrawText(const char* strID,const char* strContent,RocMap_CDPoint dPt)=0;

    //函数功能: 设置指定文本样式(默认字体样式：字体为宋体，高度为12，宽度为6，颜色红色，不包括设置点、线、面等要素label样式功能)
    //输入参数: font：字体样式(宋体,楷体_GB2312等)；color：文本颜色
    //输入参数: bgcolor：背景颜色(默认RGB(-1,-1,-1)表示不填充)；bgalpha：背景颜色透明度；bgoutlinecolor：背景轮廓线颜色(默认RGB(-1,-1,-1)表示不绘制轮廓线)
    //输出参数:无
    //返回值: 无
    virtual void SetTextStyle(const char* strID,QFont font = QFont("Times", 10, QFont::Bold),QColor color = QColor(255,0,0),
                                                            QColor bgcolor = QColor(-1,-1,-1),float bgalpha = 0.5,QColor bgoutlinecolor = QColor(-1,-1,-1))=0;

    //函数功能: 设置点样式(默认样式：点大小为1个像素，样式为方点，颜色红色)
    //输入参数: nSize：点的大小；color：点的颜色； cStyle：点的样式 (0 为方点，1为圆点)
    //输出参数:无
    //返回值: 无
    virtual void SetPointStyle(int nSize,QColor color, unsigned char cStyle)=0;

    //函数功能: 绘制点要素(默认样式：点大小为1个像素，样式为方点，颜色红色)
    //输入参数: strID：点的标识；dPt：点坐标(经纬度)
    //输出参数:无
    //返回值: 无
    virtual void DrawPoint(const char* strID,RocMap_CDPoint dPt)=0;

    //函数功能: 设置指定点样式(默认样式：点大小为1个像素，样式为方点，颜色红色)
    //输入参数: strID：点的标识；nSize：点的大小； color：点的颜色； cStyle：点的样式 (0 为方点，1为圆点)
    //输出参数:无
    //返回值: 无
    virtual void SetPointStyle(const char* strID,int nSize,QColor color, unsigned char cStyle)=0;

    //函数功能: 控制是否显示点要素标识
    //输入参数: bShow：TRUE 显示，FALSE 不显示;
    //输出参数:无
    //返回值: 无
    virtual void ShowPointLabel(BOOL bShow)=0;

    //函数功能：绘制点要素属性标识内容（如果需要改变label样式通过SetTextStyle()函数修改）
    //输入参数：strID：点要素的唯一标识; sContent：标识内容(内容中"\n"表示换行)
    //输出参数：无
    //返回值：无
    virtual void DrawPointLabel(const char* strID,QString sContent)=0;

    //函数功能: 控制点要素label是否允许鼠标拖动
    //输入参数: bDrag：TRUE 允许,FALSE 不允许(默认为FALSE)
    //输出参数:无
    //返回值: 无
    virtual void DragPointLabel(BOOL bDrag)=0;

    //函数功能: 是否显示指定点要素属性标识
    //输入参数: strID：点要素的唯一标识; bShow：TRUE 显示，FALSE 不显示
    //输出参数:无
    //返回值: 无
    virtual void ShowPointLabel(const char* strID,BOOL bShow)=0;

    //函数功能: 设置线样式(默认样式：线宽为1个像素，样式为实线，颜色红色)
    //输入参数: nWidth：线的粗细; color：线的颜色；cStyle：线的样式(0 实线，1 虚线 2 点线)
    //输出参数:无
    //返回值: 无
    virtual void SetLineStyle(int nWidth,QColor color,unsigned char cStyle)=0;


    //函数功能: 设置指定线样式(默认样式：线宽为1个像素，样式为实线，颜色红色)
    //输入参数: strID：线的标识；nWidth：线的粗细; color：线的颜色；cStyle：线的样式(0 实线，1 虚线 2 点线)
    //输出参数:无
    //返回值: 无
    virtual void SetLineStyle(const char* strID,int nWidth,QColor color,unsigned char cStyle)=0;

    //函数功能: 控制是否显示线要素标识
    //输入参数: bShow：TRUE 显示，FALSE 不显示;
    //输出参数:无
    //返回值: 无
    virtual void ShowLineLabel(BOOL bShow)=0;

    //函数功能：绘制线要素属性标识内容（如果需要改变label样式通过SetTextStyle()函数修改）
    //输入参数：strID：唯一标识; sContent：标识内容(内容中"\n"表示换行)
    //输出参数：无
    //返回值：无
    virtual void DrawLineLabel(const char* strID,QString sContent)=0;

    //函数功能: 控制线要素label是否允许拖动
    //输入参数: bDrag： TRUE 允许,FALSE 不允许(默认为FALSE)
    //输出参数:无
    //返回值: 无
    virtual void DragLineLabel(BOOL bDrag)=0;

    //函数功能: 是否显示指定线要素属性标识
    //输入参数: strID：线要素的唯一标识; bShow：TRUE 显示，FALSE 不显示
    //输出参数:无
    //返回值: 无
    virtual void ShowLineLabel(const char* strID,BOOL bShow)=0;

    //函数功能: 设置面要素样式(默认样式：轮廓线宽1个像素，轮廓线颜色红色，填充颜色绿色，不透明)
    //输入参数: outlinecolor：轮廓线颜色；fillcolor：面填充颜色(如果为RGB(-1,-1,-1)则表示不填充);
    //输入参数: outlinewidth：轮廓线宽度；alpha：面透明度(值在0.0-1.0之间)
    //输出参数:无
    //返回值: 无
    virtual void SetRegionStyle(int outlinewidth,QColor outlinecolor,QColor fillcolor,float alpha)=0;

    //函数功能: 绘制面要素(默认样式：轮廓线宽1个像素，轮廓线颜色红色，填充颜色绿色，不透明)
    //输入参数: strID：面ID； strName：面名称；vdPt：线上的点坐标（经纬度）
    //输出参数:无
    //返回值: 无
    virtual void DrawRegion(const char* strID,vector<RocMap_CDPoint> vdPt)=0;

    //函数功能: 设置指定面要素样式(默认样式：轮廓线宽1个像素，轮廓线颜色红色，填充颜色绿色，不透明)
    //输入参数: strID：面ID；outlinecolor：轮廓线颜色：fillcolor 面填充颜色(如果为RGB(-1,-1,-1)则表示不填充)
    //输入参数: outlinewidth：轮廓线宽度; alpha：面透明度(值在0.0-1.0之间)
    //输出参数:无
    //返回值: 无
    virtual void SetRegionStyle(const char* strID,int outlinewidth,QColor outlinecolor,QColor fillcolor,float alpha)=0;

    //函数功能: 控制是否显示面要素标识
    //输入参数: bShow：TRUE 显示，FALSE 不显示;
    //输出参数:无
    //返回值: 无
    virtual void ShowRegionLabel(BOOL bShow)=0;

    //函数功能：绘制面要素属性标识内容（如果需要改变label样式通过SetTextStyle()函数修改）
    //输入参数：strID：唯一标识; sContent：标识内容(内容中"\n"表示换行)
    //输出参数：无
    //返回值：无
    virtual void DrawRegionLabel(const char* strID,QString sContent)=0;

    //函数功能: 控制面要素label是否允许拖动
    //输入参数: bDrag：TRUE 允许,FALSE 不允许(默认为FALSE)
    //输出参数:无
    //返回值: 无
    virtual void DragRegionLabel(BOOL bDrag)=0;

    //函数功能: 是否显示指定面要素属性标识
    //输入参数: strID：唯一标识; bShow：TRUE 显示，FALSE 不显示
    //输出参数:无
    //返回值: 无
    virtual void ShowRegionLabel(const char* strID,BOOL bShow)=0;

    //函数功能: 设置扇形要素样式(默认样式：轮廓线宽1个像素，轮廓线颜色红色，不填充，不透明)
    //输入参数: outlinewidth：轮廓线宽度；outlinecolor：轮廓线颜色；fillcolor：面填充颜色(如果为RGB(-1,-1,-1)则表示不填充)
    //输入参数: alpha；面透明度(值在0.0-1.0之间)
    //输出参数:无
    //返回值: 无
    virtual void SetSectorStyle(int outlinewidth,QColor outlinecolor,QColor fillcolor,float alpha)=0;

    //函数功能：绘制扇形(默认样式：轮廓线宽1个像素，轮廓线颜色红色，不填充，不透明)
    //输入参数：strID：扇形ID；dPt：圆心经纬度坐标(经纬度)；fRadius：半径（单位：公里）
    //输入参数：fBeginAngle：起始角度（正北为零，顺时针为正）；fAngleScope：扇形角度范围(如果是360度，则是绘制圆形)
    //输出参数：无
    //返回值：无
    virtual void DrawSector(const char* strID,RocMap_CDPoint dPt,float fRadius,float fBeginAngle,float fAngleScope)=0;

    //函数功能：绘制扇形(默认样式：轮廓线宽1个像素，轮廓线颜色红色，不填充，不透明),不考虑投影
    //输入参数：strID：扇形ID；dPt：圆心经纬度坐标(经纬度)；fRadius：半径（单位：公里）
    //输入参数：fBeginAngle：起始角度（正北为零，顺时针为正）；fAngleScope：扇形角度范围(如果是360度，则是绘制圆形)
    //输出参数：无
    //返回值：无
    virtual void DrawSectorbyXY(const char* strID,RocMap_CDPoint dPt,float fRadius,float fBeginAngle,float fAngleScope)=0;

    //函数功能: 设置指定扇形要素样式(默认样式：轮廓线宽1个像素，轮廓线颜色红色，不填充，不透明)
    //输入参数: strID：扇形ID；outlinewidth：轮廓线宽度；outlinecolor：轮廓线颜色；fillcolor：面填充颜色(如果为RGB(-1,-1,-1)则表示不填充)
    //输入参数: alpha：面透明度(值在0.0-1.0之间)
    //输出参数:无
    //返回值: 无
    virtual void SetSectorStyle(const char* strID,int outlinewidth,QColor outlinecolor,QColor fillcolor,float alpha)=0;

    //函数功能: 控制是否显示扇形要素标识
    //输入参数: bShow：TRUE 显示，FALSE 不显示;
    //输出参数:无
    //返回值: 无
    virtual void ShowSectorLabel(BOOL bShow)=0;

    //函数功能：绘制扇形要素属性标识内容（如果需要改变label样式通过SetTextStyle()函数修改）
    //输入参数：strID：唯一标识；sContent：标识内容(内容中"\n"表示换行)
    //输出参数：无
    //返回值：无
    virtual void DrawSectorLabel(const char* strID,QString sContent)=0;

    //函数功能: 控制扇形要素label是否允许拖动
    //输入参数: bDrag：TRUE 允许,FALSE 不允许(默认为FALSE)
    //输出参数:无
    //返回值: 无
    virtual void DragSectorLabel(BOOL bDrag)=0;

    //函数功能: 是否显示指定扇形要素属性标识
    //输入参数: strID：唯一标识; bShow：TRUE 显示，FALSE 不显示
    //输出参数:无
    //返回值: 无
    virtual void ShowSectorLabel(const char* strID,BOOL bShow)=0;

    //函数功能: 设置椭圆要素样式(默认样式：轮廓线宽1个像素，轮廓线颜色红色，不填充，不透明)
    //输入参数: outlinewidth：轮廓线宽度; outlinecolor：轮廓线颜色; fillcolor：面填充颜色(如果为RGB(-1,-1,-1)则表示不填充)
    //输入参数: alpha：面透明度(值在0.0-1.0之间)
    //输出参数:无
    //返回值: 无
    virtual void SetEllipseStyle(int outlinewidth,QColor outlinecolor,QColor fillcolor,float alpha)=0;

    //函数功能：绘制椭圆(默认样式：轮廓线宽1个像素，轮廓线颜色红色，不填充，不透明)
    //输入参数：strID：椭圆ID；dCenterPt：椭圆中心点经纬度坐标(经纬度)
    //输入参数：fLRadius：长半轴长度（单位：公里）；fSRadius：短半轴长度（单位：公里）；fAngle：旋转角度（与正北方向顺时针夹角）
    //输出参数：无
    //返回值：无
    virtual void DrawEllipse(const char* strID,RocMap_CDPoint dCenterPt,float fLRadius,float fSRadius,float fAngle)=0;

    //函数功能: 设置指定椭圆要素样式(默认样式：轮廓线宽1个像素，轮廓线颜色红色，不填充，不透明)
    //输入参数: strID：椭圆ID；outlinewidth：轮廓线宽度; outlinecolor：轮廓线颜色; fillcolor：面填充颜色(如果为RGB(-1,-1,-1)则表示不填充)
    //输入参数: alpha：面透明度(值在0.0-1.0之间)
    //输出参数:无
    //返回值: 无
    virtual void SetEllipseStyle(const char* strID,int outlinewidth,QColor outlinecolor,QColor fillcolor,float alpha)=0;

    //函数功能: 控制是否显示椭圆要素标识
    //输入参数: bShow：TRUE 显示，FALSE 不显示;
    //输出参数:无
    //返回值: 无
    virtual void ShowEllipseLabel(BOOL bShow)=0;

    //函数功能：绘制椭圆要素属性标识内容（如果需要改变label样式通过SetTextStyle()函数修改）
    //输入参数：strID：唯一标识; sContent：标识内容(内容中"\n"表示换行)
    //输出参数：无
    //返回值：无
    virtual void DrawEllipseLabel(const char* strID,QString sContent)=0;

    //函数功能: 控制椭圆要素label是否允许拖动
    //输入参数: bDrag：TRUE 允许,FALSE 不允许(默认为FALSE)
    //输出参数:无
    //返回值: 无
    virtual void DragEllipseLabel(BOOL bDrag)=0;

    //函数功能: 是否显示指定椭圆要素属性标识
    //输入参数: strID：唯一标识; bShow：TRUE 显示，FALSE 不显示
    //输出参数:无
    //返回值: 无
    virtual void ShowEllipseLabel(const char* strID,BOOL bShow)=0;

    //函数功能：通过实体ID删除实体（预留接口，暂无功能）
    //输入参数：strID：要删除的实体的ID；cSort：要删除的实体的种类，0：军标；1：扇形；2：多边形/曲线；3：线； 4：点；5：文本；6：椭圆
    //输出参数：无
    //返回值：无
    virtual void  DelObjectbyID( const char* strID, unsigned char cSort)=0;

    //函数功能：删除指定类别的所有实体（预留接口，暂无功能）
    //输入参数：cSort：要删除的实体的种类，0：军标；1：扇形；2：多边形/曲线；3：线； 4：点；5：文本；6：椭圆
    //输出参数：无
    //返回值：无
    virtual void  DelObjectbySort( unsigned char cSort)=0;

    //函数功能：清屏（删除所有实体,预留接口，暂无功能）
    //输入参数：无
    //输出参数：无
    //返回值：无
    virtual void  ClearAll()=0;

    //////////////////////////////////////////////////////////////////////////
            //绘制、删除、管理要素 end
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    //军标操作功能 begin
    //////////////////////////////////////////////////////////////////////////

    /////////////////////////////////////////////////////////////////////////////////////////////
    //函数功能: 绘制军标
    //输入参数: strID： 军标的唯一标识；strName： 军标名称；color： 军标颜色
    //输入参数: jbcode： 军标代码；dPt： 军标位置（经纬度）
    //输出参数:无
    //返回值: 无
    ////////////////////////////////////////////////////////////////////////////////////////////
    virtual void DrawMiliMark(const char* strID,const char* strName,int jbcode,RocMap_CDPoint dPt,QColor color)=0;

    //功能：设定所有军标大小(在绘制军标前调用此接口)
    //输入参数：fScale：缩放比例（大于1 表示放大；小于1 表示缩小）
    //输出参数：无
    //返回值：无
    virtual void SetMiliMarkScale(float fScale)=0;

    //函数功能: 是否显示所有军标航迹(默认不显示)
    //输入参数: bShow：TRUE 显示，FALSE 不显示
    //输出参数:无
    //返回值: 无
    virtual void SetMiliMarkHJShow(BOOL bShow)=0;


    //函数功能: 设置所有军标航迹最大长度(在绘制军标前调用此接口)
    //输入参数: strID：军标的标识；nLength：最大长度(默认为500点)
    //输出参数:无
    //返回值: 无
    virtual void SetHJLength(int nLength)=0;

    //函数功能: 设置军标是否可以编辑
    //输入参数: bEdit：TRUE 允许,FALSE 不允许(默认为FALSE)
    //输出参数:无
    //返回值: 无
    virtual void SetMiliMarkEdit(BOOL bEdit)=0;

    //函数功能: 控制军标显隐
    //输入参数: bShow：TRUE 显示，FALSE 不显示
    //输出参数:无
    //返回值: 无
    virtual void SetMiliMarkShow(BOOL bShow)=0;


    //函数功能: 控制指定军标显隐（调用此接口时必须已经绘制ID为strID的军标）
    //输入参数: strID：军标的唯一标识; bShow：TRUE 显示，FALSE 不显示
    //输出参数:无
    //返回值: 无
    virtual void SetMiliMarkShow(const char* strID,BOOL bShow)=0;


    //函数功能: 设置军标属性标识内容样式
    //输入参数: strID：军标ID; font：字体样式(宋体,楷体_GB2312等); color：文本颜色
    //输入参数: bgcolor：背景颜色(RGB(-1,-1,-1)表示不填充)；bgalpha：背景颜色透明度；bgoutlinecolor：背景轮廓线颜色(RGB(-1,-1,-1)表示不绘制轮廓线)
    //输出参数:无
    //返回值: 无
    virtual void SetMiliMarkLabelStyle(const char* strID,QFont font = QFont("Times", 10, QFont::Bold),QColor color = QColor(255,0,0),QColor bgcolor = QColor(-1,-1,-1),
                                              QColor bgoutlinecolor = QColor(-1,-1,-1),float bgalpha = 0.5)=0;

    //函数功能: 控制是否显示军标标识（在绘制军标标识内容前调用此接口）
    //输入参数: bShow：TRUE 显示，FALSE 不显示;
    //输出参数:无
    //返回值: 无
    virtual void SetMiliMarkLabelShow(BOOL bShow)=0;

    //函数功能：绘制ID为strID军标的属性标识内容（调用此接口时必须已经绘制ID为strID的军标）
    //输入参数：strID：军标ID；sContent：军标标识内容(内容中"\n"表示换行)
    //输出参数：无
    //返回值：无
    virtual void DrawMiliMarkLabel(const char* strID,QString sContent)=0;

    //函数功能: 是否显示指定军标属性标识（调用此接口时必须已经绘制ID为strID的军标）
    //输入参数: strID：军标的唯一标识；bShow：TRUE 显示，FALSE 不显示
    //输出参数:无
    //返回值: 无
    virtual void SetMiliMarkLabelShow(const char* strID,BOOL bShow)=0;

    //函数功能: 设置指定军标航迹最大长度（调用此接口时必须已经绘制ID为strID的军标）
    //输入参数: strID：军标的标识；nLength：最大长度(默认为500点)
    //输出参数:无
    //返回值: 无
    virtual void SetHJLength(const char* strID,int nLength)=0;

    //函数功能: 控制是否显示军标航迹(默认不显示)（调用此接口时必须已经绘制ID为strID的军标）
    //输入参数: strID：军标的标识；bShow：TRUE 显示，FALSE 不显示
    //输出参数:无
    //返回值: 无
    virtual void SetMiliMarkHJShow(const char* strID,BOOL bShow)=0;

    //功能：设定军标旋转角度（调用此接口时必须已经绘制ID为strID的军标）
    //输入参数：strID：军标ID； fAngle：旋转角度（与正北方向夹角,逆时针旋转）
    //输出参数：无
    //返回值：无
    virtual void SetMiliMarkAngle(const char* strID,float fAngle)=0;

    //功能：设定军标大小（调用此接口时必须已经绘制ID为strID的军标）
    //输入参数：strID：军标ID； fScale：缩放比例（>1 表示放大；<1 表示缩小）
    //输出参数：无
    //返回值：无
    virtual void SetMiliMarkScale(const char* strID,float fScale)=0;

    //函数功能：获取军标名称和军标代号
    //输入参数：无
    //输出参数：军标属性
    //返回值：无
    virtual void GetMiliMarkInfo(vector<RocMap_JBAttr> &vJBAttr)=0;


    //////////////////////////////////////////////////////////////////////////
    //地图量算功能 begin
    //////////////////////////////////////////////////////////////////////////

    //函数功能: 获取当前地图比例尺
    //输入参数:无
    //输出参数:无
    //返回值: 比例尺
    virtual float GetMapScale()=0;

    //函数功能: 获取当前影像的LOD等级
    //输入参数:无
    //输出参数:无
    //返回值: LOD等级
    virtual int GetLodLevel()=0;

    //函数功能: 获取多个点之间的距离，鼠标直接在屏幕上测距时使用
    //输入参数:无
    //输出参数:无
    //返回值: 无
    virtual void GetDistance()=0;

    //函数功能: 获取多点之间距离
    //输入参数:vdPt：点集（经纬度）
    //输出参数:无
    //返回值: 距离值(单位：公里)
    virtual float GetDistance(vector<RocMap_CDPoint> vdPt)=0;

    //函数功能: 计算区域面积，鼠标直接在屏幕上测面积时使用
    //输入参数: 无
    //输出参数:无
    //返回值: 无
    virtual void GetArea()=0;

    //函数功能: 获取多点组成区域面积
    //输入参数:vdPt：点集（经纬度）
    //输出参数:无
    //返回值: 面积(单位：平方公里)
    virtual float GetArea(vector<RocMap_CDPoint> vdPt)=0;

    //函数功能: 计算两点连线角度与正北方向夹角，鼠标直接在屏幕上测角度时使用
    //输入参数: 无
    //输出参数:无
    //返回值: 无
    virtual void GetAngle()=0;

    //函数功能: 计算两点连线角度与正北方向夹角
    //输入参数: dPt0： 起点经纬度； dPt1： 终点经纬度；
    //输出参数:无
    //返回值: 角度值(度)
    virtual float GetAngle(RocMap_CDPoint dPt0,RocMap_CDPoint dPt1)=0;

    //函数功能: 根据经纬度获取高度
    //输入参数: dPt：经纬度
    //输出参数: 无
    //返回值:高度值
    virtual float GetHeight(RocMap_CDPoint dPt)=0;

    //函数功能: 屏幕坐标转经纬高
    //输入参数: pt：屏幕坐标
    //输出参数: 地理信息(经纬高)
    //返回值:无
    virtual void XYtoLB(QPoint pt,RocMap_CDPoint& dPt)=0;

    //函数功能: 经纬度转屏幕坐标
    //输入参数: dPt 经纬度
    //输出参数: 无
    //返回值:屏幕坐标
    virtual QPoint LBtoXY(RocMap_CDPoint dPt)=0;

    //函数功能：推算下一点大地坐标
    //输入参数：dSrcPt：参考点大地坐标；fAngle：计算点与参考点的正北夹角 (单位:度)；fDist：计算点和参考点的距离，单位：公里
    //输出参数：dObjPt：推算后的点大地坐标
    //返回值：TRUE：成功；FALSE：失败
    virtual BOOL GetGeoPoint(RocMap_CDPoint dSrcPt,float fAngle,float fDist,RocMap_CDPoint& dObjPt)=0;
};


#endif // IMAP2DINTERFACE_H
