### VS2015中搭建Halcon C++环境
1.项目-属性-配置属性-配置管理器，将项目平台改为x64。(保存关闭再打开才会出现X64.user)

2.通用属性-VC++目录的包含目录：$(HALCONROOT)\include;$(HALCONROOT)\include\halconcpp;

3.通用属性-VC++目录的库目录$：(HALCONROOT)\lib\x64-win64;$(LibraryPath)

4.C/C++ 常规-附加包含目录：$(HALCONROOT)\include;$(HALCONROOT)\include\halconcpp;

5.链接器-常规-附加库目录：$(HALCONROOT)\lib\$(HALCONARCH);

6.[链接器]->[输入]->[附加依赖项]添加：halconcpp.lib


### VS2015建立一个基于对话框的MFC程序。

![](https://github.com/SubDragonzj/Industrial-Automation-CCD-PLC/blob/main/vs2015/images/window1.PNG)

一个picture control用于显示图像，两个button control，四个text control用于显示测量数据。
项目代码位于HalconCamera

##### 注：要将halcon.dll和halconcpp.dll拷贝到VS程序运行目录。(这两个文件在halcon安装目录)