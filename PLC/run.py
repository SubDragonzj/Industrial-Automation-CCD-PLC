from siemens_package import SiemensS7Net
from siemens_package import SiemensPLCS
import time
import os
import math


siemens = SiemensS7Net(SiemensPLCS.S200Smart, "192.168.2.1")

if siemens.ConnectServer().IsSuccess == True:       #调用此函数后，与PLC为长连接
	read1 = siemens.ReadBool("M30.0")               #读取 当PLC M30.0置位
	if read1.Content == True:
		with open ('status.txt', 'w') as f_status:  #与C++互通时状态标志文件
			f_status.close()
		if os.path.exists('distance.txt') == True:  #读取尺寸文件
			distance = open('distance.txt').read()
			if distance != "":
				with open('distance.txt', 'r') as f_distance:
					times = 0
					for line in f_distance:
						times += 1
						print (line)
						if times == 1:
							x1 = line
						if times == 2:
							x2 = line
							avg1 = (float(x1) - float(x2)) / 2  #计算需补正的值
							pause1 = math.ceil(avg1*1000)       #将物理尺寸转换为脉冲
							siemens.WriteInt32("V510",pause1)   #将脉冲写入PLC的V存储区
						if times == 3:	
							y1 = line
						if times == 4:
							y2 = line
							avg2 = (float(y1) - float(y2)) / 2
							pause2 = math.ceil(avg2*1000)
							siemens.WriteInt32("V520",pause2)
							f_distance.close()
							if os.path.exists('distance.txt') == True:
								os.remove('distance.txt')
							if os.path.exists('status.txt') == True:
								os.remove('status.txt')
							siemens.WriteBool("M30.0",False)