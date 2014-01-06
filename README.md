### 简介

iObjects-Extentions是SuperMap iObjects .NET 7C的扩展功能包，它致力于通过扩展iObjects 的方式给用户提供更多的便捷功能。现在集成了Brutile项目提供的web地图对接功能，以及SuperMap V5缓存的读写类，下面通过应用截图展现所提供的功能。


### 通过[BruTile](http://brutile.codeplex.com/)访问OpenStreetMaps并叠加UDB矢量数据
[Demo程序下载](http://pan.baidu.com/s/1GgsHn)
<p></p>
![TileLayerDemo:OpenStreetMaps叠加UDB矢量数据显示效果](http://h.hiphotos.bdimg.com/album/s%3D1300%3Bq%3D90/sign=9092a6419c2f07085b052e03d91483e8/2cf5e0fe9925bc314b24b5965cdf8db1cb137046.jpg "OpenStreetMaps+UDB")


### 将web数据预缓存为V5缓存
![提供的将web数据预缓存为V5缓存](http://a.hiphotos.bdimg.com/album/s%3D1100%3Bq%3D90/sign=f763797972cf3bc7ec00c9ede13081d0/730e0cf3d7ca7bcb9a2c425bbc096b63f624a86b.jpg "预缓存")

完成下载后在桌面中的查看效果
![桌面中的查看效果](http://e.hiphotos.bdimg.com/album/s%3D1400%3Bq%3D90/sign=5fab72b9fe039245a5b5e50bb7a49fb3/1b4c510fd9f9d72afc3c9469d62a2834349bbb6e.jpg "桌面中的查看效果")

在预缓存的过程中使用了该功能包中[CacheWriter](https://github.com/SuperMap/iObjects-Extentions/blob/master/SuperMap.iObjects.Extension/CacheWriter.cs)类提供的V5缓存写能力，需要自行生产V5缓存的朋友可以通过该类来完成。同时在渲染的过程中我们也使用了[CacheReader](https://github.com/SuperMap/iObjects-Extentions/blob/master/SuperMap.iObjects.Extension/CacheReader.cs)类，实现V5缓存的自行渲染。

注意，iObjects 7C中还未包含将ProCoordSys对象输出到制定版本的XML接口，保存的sci文件在CoordinateReferenceSystem节点上存在不兼容的地方，需手动替换一下。这里使用的多为Sphere Mercator投影，可以使用[530004投影文件](https://github.com/SuperMap/iObjects-Extentions/blob/master/SuperMap.iObjects.Extension/prj_530004.xml)文件中的节点替换sci文件中的内容，此后即可在SuperMap GIS 7C和6R产品中使用了。

### BruTileLayer桌面插件
基于iObjects-Extentions开发的桌面插件，能够访问Google,Bing，OpenStreetMaps，iServer Rest地图服务等web数据。[下载](http://pan.baidu.com/s/129g0T)
<p></p>
![插件功能](http://c.hiphotos.bdimg.com/album/s%3D1400%3Bq%3D90/sign=bf6b565592ef76c6d4d2ff2fad26c68b/b151f8198618367a8002fba92c738bd4b31ce53f.jpg "插件功能")
![BruTileLayer桌面插件](http://b.hiphotos.bdimg.com/album/s%3D1300%3Bq%3D90/sign=f856676e6259252da717190704ab384a/8694a4c27d1ed21b2f5bab91af6eddc451da3f37.jpg "桌面插件")


### 