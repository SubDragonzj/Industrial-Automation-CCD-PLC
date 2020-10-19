### 一、Halcon生成标定文件
利用gen_caltab函数生成标定文件，其中XNum和YNum是标定板点数，MarkDist是两点中心距离单位m(米)，
DiameterRatio是标记点直径与两点距离之比。

![](https://github.com/SubDragonzj/Industrial-Automation-CCD-PLC/blob/main/images/gen_caltab.PNG)

我使用的标定板：(某宝买的)
标定板上圆的直径1mm，两点中心距2mm。

![](https://github.com/SubDragonzj/Industrial-Automation-CCD-PLC/blob/main/images/calibration_bord.PNG)

打开新的calibration：
描述文件选择gen_caltab函数生成的.descr文件。单个像素宽和高填入你的传感器参数(我的传感器为2.2x2.2μm)，焦距是镜头焦距(定焦)。

![](https://github.com/SubDragonzj/Industrial-Automation-CCD-PLC/blob/main/images/calibration01.PNG)

标定选项中采集你标定板的各种位姿的图像，设一张为参考位姿(比较清晰端正的)，然后标定。
在采集图像中，打光很重要！标定时的打光要与后期测量使用的打光保持一致。

![](https://github.com/SubDragonzj/Industrial-Automation-CCD-PLC/blob/main/images/calibration02.PNG)

在结果中将相机参数与位姿保存：

![](https://github.com/SubDragonzj/Industrial-Automation-CCD-PLC/blob/main/images/calibration03.PNG)

### 二、Halcon建立Measure
标定文件选择上一步保存的相机参数与位姿：

![](https://github.com/SubDragonzj/Industrial-Automation-CCD-PLC/blob/main/images/measure01.PNG)

绘制线段试测标定圆点直径：
测量结果为0.95mm，误差为0.05mm(可调整标定板与打光，直到标定出结果在自己需要的误差范围内)

![](https://github.com/SubDragonzj/Industrial-Automation-CCD-PLC/blob/main/images/measure02.PNG)

在代码生成中可插入代码。然后再导出为自己需要的开发语言(我用的是C++)
