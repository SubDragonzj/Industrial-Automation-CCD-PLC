'''
                   GNU LESSER GENERAL PUBLIC LICENSE
                       Version 3, 29 June 2007

 Copyright (C) 2017 - 2018 Richard.Hu <http://fsf.org/>
 Everyone is permitted to copy and distribute verbatim copies
 of this license document, but changing it is not allowed.


  This version of the GNU Lesser General Public License incorporates
the terms and conditions of version 3 of the GNU General Public
License, supplemented by the additional permissions listed below.

  0. Additional Definitions.

  As used herein, "this License" refers to version 3 of the GNU Lesser
General Public License, and the "GNU GPL" refers to version 3 of the GNU
General Public License.

  "The Library" refers to a covered work governed by this License,
other than an Application or a Combined Work as defined below.

  An "Application" is any work that makes use of an interface provided
by the Library, but which is not otherwise based on the Library.
Defining a subclass of a class defined by the Library is deemed a mode
of using an interface provided by the Library.

  A "Combined Work" is a work produced by combining or linking an
Application with the Library.  The particular version of the Library
with which the Combined Work was made is also called the "Linked
Version".

  The "Minimal Corresponding Source" for a Combined Work means the
Corresponding Source for the Combined Work, excluding any source code
for portions of the Combined Work that, considered in isolation, are
based on the Application, and not on the Linked Version.

  The "Corresponding Application Code" for a Combined Work means the
object code and/or source code for the Application, including any data
and utility programs needed for reproducing the Combined Work from the
Application, but excluding the System Libraries of the Combined Work.

  1. Exception to Section 3 of the GNU GPL.

  You may convey a covered work under sections 3 and 4 of this License
without being bound by section 3 of the GNU GPL.

  2. Conveying Modified Versions.

  If you modify a copy of the Library, and, in your modifications, a
facility refers to a function or data to be supplied by an Application
that uses the facility (other than as an argument passed when the
facility is invoked), then you may convey a copy of the modified
version:

   a) under this License, provided that you make a good faith effort to
   ensure that, in the event an Application does not supply the
   function or data, the facility still operates, and performs
   whatever part of its purpose remains meaningful, or

   b) under the GNU GPL, with none of the additional permissions of
   this License applicable to that copy.

  3. Object Code Incorporating Material from Library Header Files.

  The object code form of an Application may incorporate material from
a header file that is part of the Library.  You may convey such object
code under terms of your choice, provided that, if the incorporated
material is not limited to numerical parameters, data structure
layouts and accessors, or small macros, inline functions and templates
(ten or fewer lines in length), you do both of the following:

   a) Give prominent notice with each copy of the object code that the
   Library is used in it and that the Library and its use are
   covered by this License.

   b) Accompany the object code with a copy of the GNU GPL and this license
   document.

  4. Combined Works.

  You may convey a Combined Work under terms of your choice that,
taken together, effectively do not restrict modification of the
portions of the Library contained in the Combined Work and reverse
engineering for debugging such modifications, if you also do each of
the following:

   a) Give prominent notice with each copy of the Combined Work that
   the Library is used in it and that the Library and its use are
   covered by this License.

   b) Accompany the Combined Work with a copy of the GNU GPL and this license
   document.

   c) For a Combined Work that displays copyright notices during
   execution, include the copyright notice for the Library among
   these notices, as well as a reference directing the user to the
   copies of the GNU GPL and this license document.

   d) Do one of the following:

       0) Convey the Minimal Corresponding Source under the terms of this
       License, and the Corresponding Application Code in a form
       suitable for, and under terms that permit, the user to
       recombine or relink the Application with a modified version of
       the Linked Version to produce a modified Combined Work, in the
       manner specified by section 6 of the GNU GPL for conveying
       Corresponding Source.

       1) Use a suitable shared library mechanism for linking with the
       Library.  A suitable mechanism is one that (a) uses at run time
       a copy of the Library already present on the user's computer
       system, and (b) will operate properly with a modified version
       of the Library that is interface-compatible with the Linked
       Version.

   e) Provide Installation Information, but only if you would otherwise
   be required to provide such information under section 6 of the
   GNU GPL, and only to the extent that such information is
   necessary to install and execute a modified version of the
   Combined Work produced by recombining or relinking the
   Application with a modified version of the Linked Version. (If
   you use option 4d0, the Installation Information must accompany
   the Minimal Corresponding Source and Corresponding Application
   Code. If you use option 4d1, you must provide the Installation
   Information in the manner specified by section 6 of the GNU GPL
   for conveying Corresponding Source.)

  5. Combined Libraries.

  You may place library facilities that are a work based on the
Library side by side in a single library together with other library
facilities that are not Applications and are not covered by this
License, and convey such a combined library under terms of your
choice, if you do both of the following:

   a) Accompany the combined library with a copy of the same work based
   on the Library, uncombined with any other library facilities,
   conveyed under the terms of this License.

   b) Give prominent notice with the combined library that part of it
   is a work based on the Library, and explaining where to find the
   accompanying uncombined form of the same work.

  6. Revised Versions of the GNU Lesser General Public License.

  The Free Software Foundation may publish revised and/or new versions
of the GNU Lesser General Public License from time to time. Such new
versions will be similar in spirit to the present version, but may
differ in detail to address new problems or concerns.

  Each version is given a distinguishing version number. If the
Library as you received it specifies that a certain numbered version
of the GNU Lesser General Public License "or any later version"
applies to it, you have the option of following the terms and
conditions either of that published version or of any later version
published by the Free Software Foundation. If the Library as you
received it does not specify a version number of the GNU Lesser
General Public License, you may choose any version of the GNU Lesser
General Public License ever published by the Free Software Foundation.

  If the Library as you received it specifies that a proxy can decide
whether future versions of the GNU Lesser General Public License shall
apply, that proxy's public statement of acceptance of any version is
permanent authorization for you to choose that version for the
Library.

Use package from: https://github.com/dathlin/HslCommunication

'''

import string
import uuid
import socket
import struct
import threading
import datetime
import random
from time import sleep
from enum import Enum

class StringResources:
	'''系统的资源类'''
	@staticmethod
	def ConnectedFailed():
		return "连接失败"
	@staticmethod
	def UnknownError():
		return "未知错误"
	@staticmethod
	def ErrorCode():
		return "错误代号"
	@staticmethod
	def TextDescription():
		return "文本描述"
	@staticmethod
	def ExceptionMessage():
		return "错误信息："
	@staticmethod
	def ExceptionStackTrace():
		return "错误堆栈："
	@staticmethod
	def ExceptopnTargetSite():
		return "错误方法："
	@staticmethod
	def ExceprionCustomer():
		return "用户自定义方法出错："
	@staticmethod
	def TokenCheckFailed():
		return "令牌检查错误。"
	@staticmethod
	def SuccessText():
		return "Success"
	@staticmethod
	def NotSupportedDataType():
		return "输入的类型不支持，请重新输入"
	# Modbus相关
	@staticmethod
	def ModbusTcpFunctionCodeNotSupport():
		return "不支持的功能码"
	@staticmethod
	def ModbusTcpFunctionCodeOverBound():
		return "读取的数据越界"
	@staticmethod
	def ModbusTcpFunctionCodeQuantityOver():
		return "读取长度超过最大值"
	@staticmethod
	def ModbusTcpFunctionCodeReadWriteException():
		return "读写异常"
	@staticmethod
	def ModbusTcpReadCoilException():
		return "读取线圈异常"
	@staticmethod
	def ModbusTcpWriteCoilException():
		return "写入线圈异常"
	@staticmethod
	def ModbusTcpReadRegisterException():
		return "读取寄存器异常"
	@staticmethod
	def ModbusTcpWriteRegisterException():
		return "写入寄存器异常"
	@staticmethod
	def ModbusAddressMustMoreThanOne():
		return "地址值在起始地址为1的情况下，必须大于1"
	@staticmethod
	def MelsecPleaseReferToManulDocument():
		return "请查看三菱的通讯手册来查看报警的具体信息"
	@staticmethod
	def MelsecReadBitInfo():
		return "读取位变量数组只能针对位软元件，如果读取字软元件，请调用Read方法"
	@staticmethod
	def OmronStatus0():
		return "通讯正常"
	@staticmethod
	def OmronStatus1():
		return "消息头不是FINS"
	@staticmethod
	def OmronStatus2():
		return "数据长度太长"
	@staticmethod
	def OmronStatus3():
		return "该命令不支持"
	@staticmethod
	def OmronStatus20():
		return "超过连接上限"
	@staticmethod
	def OmronStatus21():
		return "指定的节点已经处于连接中"
	@staticmethod
	def OmronStatus22():
		return "尝试去连接一个受保护的网络节点，该节点还未配置到PLC中"
	@staticmethod
	def OmronStatus23():
		return "当前客户端的网络节点超过正常范围"
	@staticmethod
	def OmronStatus24():
		return "当前客户端的网络节点已经被使用"
	@staticmethod
	def OmronStatus25():
		return "所有的网络节点已经被使用"

class OperateResult:
	'''结果对象类，可以携带额外的数据信息'''
	def __init__(self, err = 0, msg = ""):
		self.ErrorCode = err
		self.Message = msg
	# 是否成功的标志
	IsSuccess = False
	# 操作返回的错误消息
	Message = StringResources.SuccessText()
	# 错误码
	ErrorCode = 0
	# 返回显示的文本
	def ToMessageShowString( self ):
		'''获取错误代号及文本描述'''
		return StringResources.ErrorCode() + ":" + str(self.ErrorCode) + "\r\n" + StringResources.TextDescription() + ":" + self.Message
	def CopyErrorFromOther(self, result):
		'''从另一个结果类中拷贝错误信息'''
		if result != None:
			self.ErrorCode = result.ErrorCode
			self.Message = result.Message
	@staticmethod
	def CreateFailedResult( result ):
		'''创建一个失败的结果对象'''
		failed = OperateResult()
		failed.ErrorCode = result.ErrorCode
		failed.Message = result.Message
		return failed
	@staticmethod
	def CreateSuccessResult(Content1=None,Content2=None,Content3=None,Content4=None,Content5=None,Content6=None,Content7=None,Content8=None,Content9=None,Content10=None):
		'''创建一个成功的对象'''
		success = OperateResult()
		success.IsSuccess = True
		success.Message = StringResources.SuccessText()
		if(Content2 == None and Content3 == None and Content4 == None and Content5 == None and Content6 == None and Content7 == None and Content8 == None and Content9 == None and Content10 == None) :
			success.Content = Content1
		else:
			success.Content1 = Content1
			success.Content2 = Content2
			success.Content3 = Content3
			success.Content4 = Content4
			success.Content5 = Content5
			success.Content6 = Content6
			success.Content7 = Content7
			success.Content8 = Content8
			success.Content9 = Content9
			success.Content10 = Content10
		return success

class INetMessage:
	'''数据消息的基本基类'''
	def ProtocolHeadBytesLength(self):
		'''协议头数据长度，也即是第一次接收的数据长度'''
		return 0
	def GetContentLengthByHeadBytes(self):
		'''二次接收的数据长度'''
		return 0
	def CheckHeadBytesLegal(self,toke):
		'''令牌检查是否成功'''
		return False
	def GetHeadBytesIdentity(self):
		'''获取头子节里的消息标识'''
		return 0

	HeadBytes = bytes(0)
	ContentBytes = bytes(0)
	SendBytes = bytes(0)

class S7Message (INetMessage):
	'''西门子s7协议的消息接收规则'''
	def ProtocolHeadBytesLength(self):
		'''协议头数据长度，也即是第一次接收的数据长度'''
		return 4
	def GetContentLengthByHeadBytes(self):
		'''二次接收的数据长度'''
		if self.HeadBytes != None:
			return self.HeadBytes[2]*256 + self.HeadBytes[3]-4
		else:
			return 0
	def CheckHeadBytesLegal(self,token):
		'''令牌检查是否成功'''
		if self.HeadBytes != None:
			if self.HeadBytes[0] == 0x03 and self.HeadBytes[1] == 0x00:
				return True
			else:
				return False
		else:
			return False

class DataFormat(Enum):
	'''应用于多字节数据的解析或是生成格式'''
	ABCD = 0
	BADC = 1
	CDAB = 2
	DCBA = 3

class ByteTransform:
	'''数据转换类的基础，提供了一些基础的方法实现.'''
	DataFormat = DataFormat.DCBA

	def TransBool(self, buffer, index ):
		'''将buffer数组转化成bool对象'''
		return ((buffer[index] & 0x01) == 0x01)
	def TransBoolArray(self, buffer, index, length ):
		'''将buffer数组转化成bool数组对象，需要转入索引，长度'''
		data = bytearray(length)
		for i in range(length):
			data[i]=buffer[i+index]
		return SoftBasic.ByteToBoolArray( data, length * 8 )

	def TransByte( self, buffer, index ):
		'''将buffer中的字节转化成byte对象，需要传入索引'''
		return buffer[index]
	def TransByteArray( self, buffer, index, length ):
		'''将buffer中的字节转化成byte数组对象，需要传入索引'''
		data = bytearray(length)
		for i in range(length):
			data[i]=buffer[i+index]
		return data

	def TransInt16( self, buffer, index ):
		'''从缓存中提取short结果'''
		data = self.TransByteArray(buffer,index,2)
		return struct.unpack('<h',data)[0]
	def TransInt16Array( self, buffer, index, length ):
		'''从缓存中提取short数组结果'''
		tmp = []
		for i in range(length):
			tmp.append( self.TransInt16( buffer, index + 2 * i ))
		return tmp

	def TransUInt16(self, buffer, index ):
		'''从缓存中提取ushort结果'''
		data = self.TransByteArray(buffer,index,2)
		return struct.unpack('<H',data)[0]
	def TransUInt16Array(self, buffer, index, length ):
		'''从缓存中提取ushort数组结果'''
		tmp = []
		for i in range(length):
			tmp.append( self.TransUInt16( buffer, index + 2 * i ))
		return tmp
	
	def TransInt32(self, buffer, index ):
		'''从缓存中提取int结果'''
		data = self.ByteTransDataFormat4(self.TransByteArray(buffer,index,4))
		return struct.unpack('<i',data)[0]
	def TransInt32Array(self, buffer, index, length ):
		'''从缓存中提取int数组结果'''
		tmp = []
		for i in range(length):
			tmp.append( self.TransInt32( buffer, index + 4 * i ))
		return tmp

	def TransUInt32(self, buffer, index ):
		'''从缓存中提取uint结果'''
		data = self.ByteTransDataFormat4(self.TransByteArray(buffer,index,4))
		return struct.unpack('<I',data)[0]
	def TransUInt32Array(self, buffer, index, length ):
		'''从缓存中提取uint数组结果'''
		tmp = []
		for i in range(length):
			tmp.append( self.TransUInt32( buffer, index + 4 * i ))
		return tmp
	
	def TransInt64(self, buffer, index ):
		'''从缓存中提取long结果'''
		data = self.ByteTransDataFormat8(self.TransByteArray(buffer,index,8))
		return struct.unpack('<q',data)[0]
	def TransInt64Array(self, buffer, index, length):
		'''从缓存中提取long数组结果'''
		tmp = []
		for i in range(length):
			tmp.append( self.TransInt64( buffer, index + 8 * i ))
		return tmp
	
	def TransUInt64(self, buffer, index ):
		'''从缓存中提取ulong结果'''
		data = self.ByteTransDataFormat8(self.TransByteArray(buffer,index,8))
		return struct.unpack('<Q',data)[0]
	def TransUInt64Array(self, buffer, index, length):
		'''从缓存中提取ulong数组结果'''
		tmp = []
		for i in range(length):
			tmp.append( self.TransUInt64( buffer, index + 8 * i ))
		return tmp
	
	def TransSingle(self, buffer, index ):
		'''从缓存中提取float结果'''
		data = self.ByteTransDataFormat4(self.TransByteArray(buffer,index,4))
		return struct.unpack('<f',data)[0]
	def TransSingleArray(self, buffer, index, length):
		'''从缓存中提取float数组结果'''
		tmp = []
		for i in range(length):
			tmp.append( self.TransSingle( buffer, index + 4 * i ))
		return tmp
	
	def TransDouble(self, buffer, index ):
		'''从缓存中提取double结果'''
		data = self.ByteTransDataFormat8(self.TransByteArray(buffer,index,8))
		return struct.unpack('<d',data)[0]
	def TransDoubleArray(self, buffer, index, length):
		'''从缓存中提取double数组结果'''
		tmp = []
		for i in range(length):
			tmp.append( self.TransDouble( buffer, index + 8 * i ))
		return tmp

	def TransString( self, buffer, index, length, encoding ):
		'''从缓存中提取string结果，使用指定的编码'''
		data = self.TransByteArray(buffer,index,length)
		return data.decode(encoding)

	def BoolArrayTransByte(self, values):
		'''bool数组变量转化缓存数据，需要传入bool数组'''
		if (values == None): return None
		return SoftBasic.BoolArrayToByte( values )
	def BoolTransByte(self, value):
		'''bool变量转化缓存数据，需要传入bool值'''
		return self.BoolArrayTransByte([value])

	def ByteTransByte(self, value ):
		'''byte变量转化缓存数据，需要传入byte值'''
		buffer = bytearray(1)
		buffer[0] = value
		return buffer

	def Int16ArrayTransByte(self, values ):
		'''short数组变量转化缓存数据，需要传入short数组'''
		if (values == None) : return None
		buffer = bytearray(len(values) * 2)
		for i in range(len(values)):
			buffer[(i*2): (i*2+2)] = struct.pack('<h',values[i])
		return buffer
	def Int16TransByte(self, value ):
		'''short数组变量转化缓存数据，需要传入short值'''
		return self.Int16ArrayTransByte([value])

	def UInt16ArrayTransByte(self, values ):
		'''ushort数组变量转化缓存数据，需要传入ushort数组'''
		if (values == None) : return None
		buffer = bytearray(len(values) * 2)
		for i in range(len(values)):
			buffer[(i*2): (i*2+2)] = struct.pack('<H',values[i])
		return buffer
	def UInt16TransByte(self, value ):
		'''ushort变量转化缓存数据，需要传入ushort值'''
		return self.UInt16ArrayTransByte([value])

	def Int32ArrayTransByte(self, values ):
		'''int数组变量转化缓存数据，需要传入int数组'''
		if (values == None) : return None
		buffer = bytearray(len(values) * 4)
		for i in range(len(values)):
			buffer[(i*4): (i*4+4)] = self.ByteTransDataFormat4(struct.pack('<i',values[i]))
		return buffer
	def Int32TransByte(self, value ):
		'''int变量转化缓存数据，需要传入int值'''
		return self.Int32ArrayTransByte([value])

	def UInt32ArrayTransByte(self, values ):
		'''uint数组变量转化缓存数据，需要传入uint数组'''
		if (values == None) : return None
		buffer = bytearray(len(values) * 4)
		for i in range(len(values)):
			buffer[(i*4): (i*4+4)] = self.ByteTransDataFormat4(struct.pack('<I',values[i]))
		return buffer
	def UInt32TransByte(self, value ):
		'''uint变量转化缓存数据，需要传入uint值'''
		return self.UInt32ArrayTransByte([value])

	def Int64ArrayTransByte(self, values ):
		'''long数组变量转化缓存数据，需要传入long数组'''
		if (values == None) : return None
		buffer = bytearray(len(values) * 8)
		for i in range(len(values)):
			buffer[(i*8): (i*8+8)] = self.ByteTransDataFormat8(struct.pack('<q',values[i]))
		return buffer
	def Int64TransByte(self, value ):
		'''long变量转化缓存数据，需要传入long值'''
		return self.Int64ArrayTransByte([value])

	def UInt64ArrayTransByte(self, values ):
		'''ulong数组变量转化缓存数据，需要传入ulong数组'''
		if (values == None) : return None
		buffer = bytearray(len(values) * 8)
		for i in range(len(values)):
			buffer[(i*8): (i*8+8)] = self.ByteTransDataFormat8(struct.pack('<Q',values[i]))
		return buffer
	def UInt64TransByte(self, value ):
		'''ulong变量转化缓存数据，需要传入ulong值'''
		return self.UInt64ArrayTransByte([value])

	def FloatArrayTransByte(self, values ):
		'''float数组变量转化缓存数据，需要传入float数组'''
		if (values == None) : return None
		buffer = bytearray(len(values) * 4)
		for i in range(len(values)):
			buffer[(i*4): (i*4+4)] = self.ByteTransDataFormat4(struct.pack('<f',values[i]))
		return buffer
	def FloatTransByte(self, value ):
		'''float变量转化缓存数据，需要传入float值'''
		return self.FloatArrayTransByte([value])

	def DoubleArrayTransByte(self, values ):
		'''double数组变量转化缓存数据，需要传入double数组'''
		if (values == None) : return None
		buffer = bytearray(len(values) * 8)
		for i in range(len(values)):
			buffer[(i*8): (i*8+8)] = self.ByteTransDataFormat8(struct.pack('<d',values[i]))
		return buffer
	def DoubleTransByte(self, value ):
		'''double变量转化缓存数据，需要传入double值'''
		return self.DoubleArrayTransByte([value])

	def StringTransByte(self, value:str, encoding:str ):
		'''使用指定的编码字符串转化缓存数据，需要传入string值及编码信息'''
		return value.encode(encoding)

	def ByteTransDataFormat4(self, value, index = 0 ):
		'''反转多字节的数据信息'''
		buffer = bytearray(4)
		if self.DataFormat == DataFormat.ABCD:
			buffer[0] = value[index + 3]
			buffer[1] = value[index + 2]
			buffer[2] = value[index + 1]
			buffer[3] = value[index + 0]
		elif self.DataFormat == DataFormat.BADC:
			buffer[0] = value[index + 2]
			buffer[1] = value[index + 3]
			buffer[2] = value[index + 0]
			buffer[3] = value[index + 1]
		elif self.DataFormat == DataFormat.CDAB:
			buffer[0] = value[index + 1]
			buffer[1] = value[index + 0]
			buffer[2] = value[index + 3]
			buffer[3] = value[index + 2]
		elif self.DataFormat == DataFormat.DCBA:
			buffer[0] = value[index + 0]
			buffer[1] = value[index + 1]
			buffer[2] = value[index + 2]
			buffer[3] = value[index + 3]
		return buffer

	def ByteTransDataFormat8(self, value, index = 0 ):
		'''反转多字节的数据信息'''
		buffer = bytearray(8)
		if self.DataFormat == DataFormat.ABCD:
			buffer[0] = value[index + 7]
			buffer[1] = value[index + 6]
			buffer[2] = value[index + 5]
			buffer[3] = value[index + 4]
			buffer[4] = value[index + 3]
			buffer[5] = value[index + 2]
			buffer[6] = value[index + 1]
			buffer[7] = value[index + 0]
		elif self.DataFormat == DataFormat.BADC:
			buffer[0] = value[index + 6]
			buffer[1] = value[index + 7]
			buffer[2] = value[index + 4]
			buffer[3] = value[index + 5]
			buffer[4] = value[index + 2]
			buffer[5] = value[index + 3]
			buffer[6] = value[index + 0]
			buffer[7] = value[index + 1]
		elif self.DataFormat == DataFormat.CDAB:
			buffer[0] = value[index + 1]
			buffer[1] = value[index + 0]
			buffer[2] = value[index + 3]
			buffer[3] = value[index + 2]
			buffer[4] = value[index + 5]
			buffer[5] = value[index + 4]
			buffer[6] = value[index + 7]
			buffer[7] = value[index + 6]
		elif self.DataFormat == DataFormat.DCBA:
			buffer[0] = value[index + 0]
			buffer[1] = value[index + 1]
			buffer[2] = value[index + 2]
			buffer[3] = value[index + 3]
			buffer[4] = value[index + 4]
			buffer[5] = value[index + 5]
			buffer[6] = value[index + 6]
			buffer[7] = value[index + 7]
		return buffer

class RegularByteTransform(ByteTransform):
	'''常规的字节转换类'''
	def __init__(self):
		return

class ReverseBytesTransform(ByteTransform):
	'''字节倒序的转换类'''
	def TransInt16(self, buffer, index ):
		'''从缓存中提取short结果'''
		data = self.TransByteArray(buffer,index,2)
		return struct.unpack('>h',data)[0]
	def TransUInt16(self, buffer, index ):
		'''从缓存中提取ushort结果'''
		data = self.TransByteArray(buffer,index,2)
		return struct.unpack('>H',data)[0]
	def TransInt32(self, buffer, index ):
		'''从缓存中提取int结果'''
		data = self.TransByteArray(buffer,index,4)
		return struct.unpack('>i',data)[0]
	def TransUInt32(self, buffer, index ):
		'''从缓存中提取uint结果'''
		data = self.TransByteArray(buffer,index,4)
		return struct.unpack('>I',data)[0]
	def TransInt64(self, buffer, index ):
		'''从缓存中提取long结果'''
		data = self.TransByteArray(buffer,index,8)
		return struct.unpack('>q',data)[0]
	def TransUInt64(self, buffer, index ):
		'''从缓存中提取ulong结果'''
		data = self.TransByteArray(buffer,index,8)
		return struct.unpack('>Q',data)[0]
	def TransSingle(self, buffer, index ):
		'''从缓存中提取float结果'''
		data = self.TransByteArray(buffer,index,4)
		return struct.unpack('>f',data)[0]
	def TransDouble(self, buffer, index ):
		'''从缓存中提取double结果'''
		data = self.TransByteArray(buffer,index,8)
		return struct.unpack('>d',data)[0]
	
	def Int16ArrayTransByte(self, values ):
		'''short数组变量转化缓存数据，需要传入short数组 -> bytearray'''
		if (values == None) : return None
		buffer = bytearray(len(values) * 2)
		for i in range(len(values)):
			buffer[(i*2): (i*2+2)] = struct.pack('>h',values[i])
		return buffer
	def UInt16ArrayTransByte(self, values ):
		'''ushort数组变量转化缓存数据，需要传入ushort数组 -> bytearray'''
		if (values == None) : return None
		buffer = bytearray(len(values) * 2)
		for i in range(len(values)):
			buffer[(i*2): (i*2+2)] = struct.pack('>H',values[i])
		return buffer
	def Int32ArrayTransByte(self, values ):
		'''int数组变量转化缓存数据，需要传入int数组 -> bytearray'''
		if (values == None) : return None
		buffer = bytearray(len(values) * 4)
		for i in range(len(values)):
			buffer[(i*4): (i*4+4)] = struct.pack('>i',values[i])
		return buffer
	def UInt32ArrayTransByte(self, values ):
		'''uint数组变量转化缓存数据，需要传入uint数组 -> bytearray'''
		if (values == None) : return None
		buffer = bytearray(len(values) * 4)
		for i in range(len(values)):
			buffer[(i*4): (i*4+4)] = struct.pack('>I',values[i])
		return buffer
	def Int64ArrayTransByte(self, values ):
		'''long数组变量转化缓存数据，需要传入long数组 -> bytearray'''
		if (values == None) : return None
		buffer = bytearray(len(values) * 8)
		for i in range(len(values)):
			buffer[(i*8): (i*8+8)] = struct.pack('>q',values[i])
		return buffer
	def UInt64ArrayTransByte(self, values ):
		'''ulong数组变量转化缓存数据，需要传入ulong数组 -> bytearray'''
		if (values == None) : return None
		buffer = bytearray(len(values) * 8)
		for i in range(len(values)):
			buffer[(i*8): (i*8+8)] = struct.pack('>Q',values[i])
		return buffer
	def FloatArrayTransByte(self, values ):
		'''float数组变量转化缓存数据，需要传入float数组 -> bytearray'''
		if (values == None) : return None
		buffer = bytearray(len(values) * 4)
		for i in range(len(values)):
			buffer[(i*4): (i*4+4)] = struct.pack('>f',values[i])
		return buffer
	def DoubleArrayTransByte(self, values ):
		'''double数组变量转化缓存数据，需要传入double数组 -> bytearray'''
		if (values == None) : return None
		buffer = bytearray(len(values) * 8)
		for i in range(len(values)):
			buffer[(i*8): (i*8+8)] = struct.pack('>d',values[i])
		return buffer

class ReverseWordTransform(ByteTransform):
	'''按照字节错位的数据转换类'''
	def __init__(self):
		'''初始化方法，重新设置DataFormat'''
		self.DataFormat = DataFormat.ABCD
	
	IsStringReverse = False

	def ReverseBytesByWord( self, buffer, index, length ):
		'''按照字节错位的方法 -> bytearray'''
		if buffer == None: return None
		data = self.TransByteArray(buffer,index,length)
		for i in range(len(data)//2):
			data[i*2+0],data[i*2+1]= data[i*2+1],data[i*2+0]
		return data
	def ReverseAllBytesByWord( self, buffer ):
		'''按照字节错位的方法 -> bytearray'''
		return self.ReverseBytesByWord(buffer,0,len(buffer))
	def TransInt16( self, buffer, index ):
		'''从缓存中提取short结果'''
		data = self.ReverseBytesByWord(buffer,index,2)
		return struct.unpack('<h',data)[0]
	def TransUInt16(self, buffer, index ):
		'''从缓存中提取ushort结果'''
		data = self.ReverseBytesByWord(buffer,index,2)
		return struct.unpack('<H',data)[0]
	def TransString( self, buffer, index, length, encoding ):
		'''从缓存中提取string结果，使用指定的编码'''
		data = self.TransByteArray(buffer,index,length)
		if self.IsStringReverse:
			return self.ReverseAllBytesByWord(data).decode(encoding)
		else:
			return data.decode(encoding)
	
	def Int16ArrayTransByte(self, values ):
		'''short数组变量转化缓存数据，需要传入short数组'''
		buffer = super().Int16ArrayTransByte(values)
		return self.ReverseAllBytesByWord(buffer)
	def UInt16ArrayTransByte(self, values ):
		'''ushort数组变量转化缓存数据，需要传入ushort数组'''
		buffer = super().UInt16ArrayTransByte(values)
		return self.ReverseAllBytesByWord(buffer)
	def StringTransByte(self, value, encoding ):
		'''使用指定的编码字符串转化缓存数据，需要传入string值及编码信息'''
		buffer = value.encode(encoding)
		buffer = SoftBasic.BytesArrayExpandToLengthEven(buffer)
		if self.IsStringReverse:
			return self.ReverseAllBytesByWord( buffer )
		else:
			return buffer

class ByteTransformHelper:
	'''所有数据转换类的静态辅助方法'''
	@staticmethod
	def GetBoolResultFromBytes( result, byteTransform ):
		'''将指定的OperateResult类型转化'''
		try:
			if result.IsSuccess:
				return OperateResult.CreateSuccessResult(byteTransform.TransBool(result.Content , 0 ))
			else:
				return OperateResult.CreateFailedResult(result)
		except Exception as ex:
			return OperateResult( msg = "数据转化失败，源数据：" + SoftBasic.ByteToHexString( result.Content ) + " 消息：" + str(ex))
	@staticmethod
	def GetByteResultFromBytes( result, byteTransform ):
		'''将指定的OperateResult类型转化'''
		try:
			if result.IsSuccess:
				return OperateResult.CreateSuccessResult(byteTransform.TransByte(result.Content , 0 ))
			else:
				return OperateResult.CreateFailedResult(result)
		except Exception as ex:
			return OperateResult( msg = "数据转化失败，源数据：" + SoftBasic.ByteToHexString( result.Content ) + " 消息：" + str(ex))
	@staticmethod
	def GetInt16ResultFromBytes( result, byteTransform ):
		'''将指定的OperateResult类型转化'''
		try:
			if result.IsSuccess:
				return OperateResult.CreateSuccessResult(byteTransform.TransInt16(result.Content , 0 ))
			else:
				return OperateResult.CreateFailedResult(result)
		except Exception as ex:
			return OperateResult( msg = "数据转化失败，源数据：" + SoftBasic.ByteToHexString( result.Content ) + " 消息：" + str(ex))
	@staticmethod
	def GetUInt16ResultFromBytes( result, byteTransform ):
		'''将指定的OperateResult类型转化'''
		try:
			if result.IsSuccess:
				return OperateResult.CreateSuccessResult(byteTransform.TransUInt16(result.Content , 0 ))
			else:
				return OperateResult.CreateFailedResult(result)
		except Exception as ex:
			return OperateResult( msg = "数据转化失败，源数据：" + SoftBasic.ByteToHexString( result.Content ) + " 消息：" + str(ex))
	@staticmethod
	def GetInt32ResultFromBytes( result, byteTransform ):
		'''将指定的OperateResult类型转化'''
		try:
			if result.IsSuccess:
				return OperateResult.CreateSuccessResult(byteTransform.TransInt32(result.Content , 0 ))
			else:
				return OperateResult.CreateFailedResult(result)
		except Exception as ex:
			return OperateResult( msg = "数据转化失败，源数据：" + SoftBasic.ByteToHexString( result.Content ) + " 消息：" + str(ex))
	@staticmethod
	def GetUInt32ResultFromBytes( result, byteTransform ):
		'''将指定的OperateResult类型转化'''
		try:
			if result.IsSuccess:
				return OperateResult.CreateSuccessResult(byteTransform.TransUInt32(result.Content , 0 ))
			else:
				return OperateResult.CreateFailedResult(result)
		except Exception as ex:
			return OperateResult( msg = "数据转化失败，源数据：" + SoftBasic.ByteToHexString( result.Content ) + " 消息：" + str(ex))
	@staticmethod
	def GetInt64ResultFromBytes( result, byteTransform ):
		'''将指定的OperateResult类型转化'''
		try:
			if result.IsSuccess:
				return OperateResult.CreateSuccessResult(byteTransform.TransInt64(result.Content , 0 ))
			else:
				return OperateResult.CreateFailedResult(result)
		except Exception as ex:
			return OperateResult( msg = "数据转化失败，源数据：" + SoftBasic.ByteToHexString( result.Content ) + " 消息：" + str(ex))
	@staticmethod
	def GetUInt64ResultFromBytes( result, byteTransform ):
		'''将指定的OperateResult类型转化'''
		try:
			if result.IsSuccess:
				return OperateResult.CreateSuccessResult(byteTransform.TransUInt64(result.Content , 0 ))
			else:
				return OperateResult.CreateFailedResult(result)
		except Exception as ex:
			return OperateResult( msg = "数据转化失败，源数据：" + SoftBasic.ByteToHexString( result.Content ) + " 消息：" + str(ex))
	@staticmethod
	def GetSingleResultFromBytes( result, byteTransform ):
		'''将指定的OperateResult类型转化'''
		try:
			if result.IsSuccess:
				return OperateResult.CreateSuccessResult(byteTransform.TransSingle(result.Content , 0 ))
			else:
				return OperateResult.CreateFailedResult(result)
		except Exception as ex:
			return OperateResult( msg = "数据转化失败，源数据：" + SoftBasic.ByteToHexString( result.Content ) + " 消息：" + str(ex))
	@staticmethod
	def GetDoubleResultFromBytes( result, byteTransform ):
		'''将指定的OperateResult类型转化'''
		try:
			if result.IsSuccess:
				return OperateResult.CreateSuccessResult(byteTransform.TransDouble(result.Content , 0 ))
			else:
				return OperateResult.CreateFailedResult(result)
		except Exception as ex:
			return OperateResult( msg = "数据转化失败，源数据：" + SoftBasic.ByteToHexString( result.Content ) + " 消息：" + str(ex))
	@staticmethod
	def GetStringResultFromBytes( result, byteTransform ):
		'''将指定的OperateResult类型转化'''
		try:
			if result.IsSuccess:
				return OperateResult.CreateSuccessResult(byteTransform.TransString(result.Content , 0, len(result.Content), 'ascii' ))
			else:
				return OperateResult.CreateFailedResult(result)
		except Exception as ex:
			return OperateResult( msg = "数据转化失败，源数据：" + SoftBasic.ByteToHexString( result.Content ) + " 消息：" + str(ex))

class DeviceAddressBase:
	'''所有设备通信类的地址基础类'''
	Address = 0
	def AnalysisAddress( self, address ):
		'''解析字符串的地址'''
		self.Address = int(address)

class SoftBasic:
	'''系统运行的基础方法，提供了一些基本的辅助方法'''
	@staticmethod
	def GetSizeDescription(size):
		'''获取指定数据大小的文本描述字符串'''
		if size < 1000:
			return str(size) + " B"
		elif size < (1000 * 1000):
			data = float(size) / 1024
			return '{:.2f}'.format(data) + " Kb"
		elif size < (1000 * 1000 * 1000):
			data = float(size) / 1024 / 1024
			return '{:.2f}'.format(data) + " Mb"
		else:
			data = float(size) / 1024 / 1024 / 1024
			return '{:.2f}'.format(data) + " Gb"
	@staticmethod
	def ByteToHexString(inBytes,segment=' '):
		'''将字节数组转换成十六进制的表示形式，需要传入2个参数，数据和分隔符，该方法还存在一点问题'''
		str_list = []
		for byte in inBytes:
			str_list.append('{:02X}'.format(byte))
		if segment != None: 
			return segment.join(str_list)
		else:
			return ''.join(str_list)
	@staticmethod
	def ByteToBoolArray( InBytes, length ):
		'''从字节数组中提取bool数组变量信息'''
		if InBytes == None:
			return None
		if length > len(InBytes) * 8:
			length = len(InBytes) * 8
		buffer = []
		for  i in range(length):
			index = i // 8
			offect = i % 8

			temp = 0
			if offect == 0 : temp = 0x01
			elif offect == 1 : temp = 0x02
			elif offect == 2 : temp = 0x04
			elif offect == 3 : temp = 0x08
			elif offect == 4 : temp = 0x10
			elif offect == 5 : temp = 0x20
			elif offect == 6 : temp = 0x40
			elif offect == 7 : temp = 0x80

			if (InBytes[index] & temp) == temp:
				buffer.append(True)
			else:
				buffer.append(False)
		return buffer
	@staticmethod
	def BoolArrayToByte( array ):
		'''从bool数组变量变成byte数组'''
		if (array == None) : return None

		length = 0
		if len(array) % 8 == 0:
			length = int(len(array) / 8)
		else:
			length = int(len(array) / 8) + 1
		buffer = bytearray(length)

		for i in range(len(array)):
			index = i // 8
			offect = i % 8

			temp = 0
			if offect == 0 : temp = 0x01
			elif offect == 1 : temp = 0x02
			elif offect == 2 : temp = 0x04
			elif offect == 3 : temp = 0x08
			elif offect == 4 : temp = 0x10
			elif offect == 5 : temp = 0x20
			elif offect == 6 : temp = 0x40
			elif offect == 7 : temp = 0x80

			if array[i] : buffer[index] += temp
		return buffer
	@staticmethod
	def HexStringToBytes( hex ):
		'''将hex字符串转化为byte数组'''
		return bytes.fromhex(hex)
	@staticmethod
	def BytesArrayExpandToLengthEven(array):
		'''扩充一个整型的数据长度为偶数个'''
		if len(array) % 2 == 1:
			array.append(0)
		return array
	@staticmethod
	def IsTwoBytesEquel( b1, start1, b2, start2, length ):
		'''判断两个字节的指定部分是否相同'''
		if b1 == None or b2 == None: return False
		for ii in range(length):
			if b1[ii+start1] != b2[ii+start2]: return False
		return True
	@staticmethod
	def TokenToBytes( token ):
		'''将uuid的token值转化成统一的bytes数组，方便和java，C#通讯'''
		buffer = bytearray(token.bytes)
		buffer[0],buffer[1],buffer[2],buffer[3] = buffer[3],buffer[2],buffer[1],buffer[0]
		buffer[4],buffer[5] = buffer[5],buffer[4]
		buffer[6],buffer[7] = buffer[7],buffer[6]
		return buffer
	@staticmethod
	def ArrayExpandToLength( value, length ):
		'''将数组扩充到指定的长度'''
		buffer = bytearray(length)
		if len(value) >= length:
			buffer[0:] = value[0:len(value)]
		else:
			buffer[0:len(value)] = value
		return buffer
	@staticmethod
	def ArrayExpandToLengthEven( value ):
		'''将数组扩充到偶数的长度'''
		if len(value) % 2 == 0:
			return value
		else:
			buffer = bytearray(len(value)+1)
			buffer[0:len(value)] = value
			return value
	@staticmethod
	def StringToUnicodeBytes( value ):
		'''获取字符串的unicode编码字符'''
		if value == None: return bytearray(0)

		buffer = value.encode('utf-16')
		if len(buffer) > 1 and buffer[0] == 255 and buffer[1] == 254:
			buffer = buffer[2:len(buffer)]
		return buffer
	@staticmethod
	def GetUniqueStringByGuidAndRandom():
		'''获取一串唯一的随机字符串，长度为20，由Guid码和4位数的随机数组成，保证字符串的唯一性'''
		return SoftBasic.ByteToHexString(SoftBasic.TokenToBytes(uuid.uuid1()), None) + str(random.randint(12, 20))

class NetworkBase:
	'''网络基础类的核心'''
	Token = uuid.UUID('{00000000-0000-0000-0000-000000000000}')
	CoreSocket = socket.socket()
	def Receive(self,socket,length):
		'''接收固定长度的字节数组'''
		totle = 0
		data = bytearray()
		try:
			while totle < length:
				data.extend(socket.recv(length-totle))
				totle += len(data)
			return OperateResult.CreateSuccessResult(data)
		except Exception as e:
			result = OperateResult()
			result.Message = str(e)
			return result
	def Send(self,socket,data):
		'''发送消息给套接字，直到完成的时候返回'''
		try:
			socket.send(data)
			return OperateResult.CreateSuccessResult()
		except Exception as e:
			return OperateResult( msg = str(e))

	def CreateSocketAndConnect(self,ipAddress,port,timeout = 10000):
		'''创建一个新的socket对象并连接到远程的地址，默认超时时间为10秒钟'''
		try:
			socketTmp = socket.socket()
			socketTmp.connect((ipAddress,port))
			return OperateResult.CreateSuccessResult(socketTmp)
		except Exception as e:
			return OperateResult( msg = str(e))
	def ReceiveMessage( self, socket, timeOut, netMsg ):
		'''接收一条完整的数据，使用异步接收完成，包含了指令头信息'''
		result = OperateResult()
		headResult = self.Receive( socket, netMsg.ProtocolHeadBytesLength() )
		if headResult.IsSuccess == False:
			result.CopyErrorFromOther(headResult)
			return result
		netMsg.HeadBytes = headResult.Content
		if netMsg.CheckHeadBytesLegal( SoftBasic.TokenToBytes(self.Token) ) == False:
			# 令牌校验失败
			if socket != None: socket.close()
			result.Message = StringResources.TokenCheckFailed()
			return result

		contentLength = netMsg.GetContentLengthByHeadBytes( )
		if contentLength == 0:
			netMsg.ContentBytes = bytearray(0)
		else:
			contentResult = self.Receive( socket, contentLength )
			if contentResult.IsSuccess == False:
				result.CopyErrorFromOther( contentResult )
				return result
			netMsg.ContentBytes = contentResult.Content
		
		if netMsg.ContentBytes == None: netMsg.ContentBytes = bytearray(0)
		result.Content = netMsg
		result.IsSuccess = True
		return result

class NetworkDoubleBase(NetworkBase):
	'''支持长连接，短连接两个模式的通用客户端基类'''
	byteTransform = ByteTransform()
	ipAddress = "127.0.0.1"
	port = 10000
	isPersistentConn = False
	isSocketError = False
	receiveTimeOut = 10000
	isUseSpecifiedSocket = False
	interactiveLock = threading.Lock()
	iNetMessage = INetMessage()
	
	def SetPersistentConnection( self ):
		'''在读取数据之前可以调用本方法将客户端设置为长连接模式，相当于跳过了ConnectServer的结果验证，对异形客户端无效'''
		self.isPersistentConn = True
	def ConnectServer( self ):
		'''切换短连接模式到长连接模式，后面的每次请求都共享一个通道'''
		self.isPersistentConn = True
		result = OperateResult( )
		# 重新连接之前，先将旧的数据进行清空
		if self.CoreSocket != None: 
			self.CoreSocket.close()

		rSocket = self.CreateSocketAndInitialication( )
		if rSocket.IsSuccess == False:
			self.isSocketError = True
			rSocket.Content = None
			result.Message = rSocket.Message
		else:
			self.CoreSocket = rSocket.Content
			result.IsSuccess = True
		return result
	def ConnectClose( self ):
		'''在长连接模式下，断开服务器的连接，并切换到短连接模式'''
		result = OperateResult( )
		self.isPersistentConn = False

		self.interactiveLock.acquire()
		# 额外操作
		result = self.ExtraOnDisconnect( self.CoreSocket )
		# 关闭信息
		if self.CoreSocket != None : self.CoreSocket.close()
		self.CoreSocket = None
		self.interactiveLock.release( )
		return result
	

	# 初始化的信息方法和连接结束的信息方法，需要在继承类里面进行重新实现
	def InitializationOnConnect( self, socket ):
		'''连接上服务器后需要进行的初始化操作'''
		return OperateResult.CreateSuccessResult()
	def ExtraOnDisconnect( self, socket ):
		'''在将要和服务器进行断开的情况下额外的操作，需要根据对应协议进行重写'''
		return OperateResult.CreateSuccessResult()
	
	def GetAvailableSocket( self ):
		'''获取本次操作的可用的网络套接字'''
		if self.isPersistentConn :
			# 如果是异形模式
			if self.isUseSpecifiedSocket :
				if self.isSocketError:
					return OperateResult( msg = '连接不可用' )
				else:
					return OperateResult.CreateSuccessResult( self.CoreSocket )
			else:
				# 长连接模式
				if self.isSocketError or self.CoreSocket == None :
					connect = self.ConnectServer( )
					if connect.IsSuccess == False:
						self.isSocketError = True
						return OperateResult( msg = connect.Message )
					else:
						self.isSocketError = False
						return OperateResult.CreateSuccessResult( self.CoreSocket )
				else:
					return OperateResult.CreateSuccessResult( self.CoreSocket )
		else:
			# 短连接模式
			return self.CreateSocketAndInitialication( )

	def CreateSocketAndInitialication( self ):
		'''连接并初始化网络套接字'''
		result = self.CreateSocketAndConnect( self.ipAddress, self.port, 10000 )
		if result.IsSuccess:
			# 初始化
			initi = self.InitializationOnConnect( result.Content )
			if initi.IsSuccess == False:
				if result.Content !=None : result.Content.close( )
				result.IsSuccess = initi.IsSuccess
				result.CopyErrorFromOther( initi )
		return result

	def ReadFromCoreSocketServer( self, socket, send ):
		'''在其他指定的套接字上，使用报文来通讯，传入需要发送的消息，返回一条完整的数据指令'''
		read = self.ReadFromCoreServerBase( socket, send )
		if read.IsSuccess == False: return OperateResult.CreateFailedResult( read )

		# 拼接结果数据
		Content = bytearray(len(read.Content1) + len(read.Content2))
		if len(read.Content1) > 0 : 
			Content[0:len(read.Content1)] = read.Content1
		if len(read.Content2) > 0 : 
			Content[len(read.Content1):len(Content)] = read.Content2
		return OperateResult.CreateSuccessResult( Content )

	def ReadFromCoreServer( self, send ):
		'''使用底层的数据报文来通讯，传入需要发送的消息，返回一条完整的数据指令'''
		result = OperateResult( )
		self.interactiveLock.acquire()
		# 获取有用的网络通道，如果没有，就建立新的连接
		resultSocket = self.GetAvailableSocket( )
		if resultSocket.IsSuccess == False:
			self.isSocketError = True
			self.interactiveLock.release()
			result.CopyErrorFromOther( resultSocket )
			return result

		read = self.ReadFromCoreSocketServer( resultSocket.Content, send )
		if read.IsSuccess :
			self.isSocketError = False
			result.IsSuccess = read.IsSuccess
			result.Content = read.Content
			result.Message = StringResources.SuccessText
			# string tmp2 = BasicFramework.SoftBasic.ByteToHexString( result.Content, '-' )
		else:
			self.isSocketError = True
			result.CopyErrorFromOther( read )

		self.interactiveLock.release()
		if self.isPersistentConn==False:
			if resultSocket.Content != None:
				resultSocket.Content.close()
		return result
		
	def ReadFromCoreServerBase( self, socket, send ):
		'''使用底层的数据报文来通讯，传入需要发送的消息，返回最终的数据结果，被拆分成了头子节和内容字节信息'''
		self.iNetMessage.SendBytes = send
		sendResult = self.Send( socket, send )
		if sendResult.IsSuccess == False:
			if socket!= None : socket.close( )
			return OperateResult.CreateFailedResult( sendResult )

		# 接收超时时间大于0时才允许接收远程的数据
		if (self.receiveTimeOut >= 0):
			# 接收数据信息
			resultReceive = self.ReceiveMessage(socket, 10000, self.iNetMessage)
			if resultReceive.IsSuccess == False:
				socket.close( )
				return OperateResult( msg = "Receive data timeout: " + str(self.receiveTimeOut ) + " Msg:"+ resultReceive.Message)
			return OperateResult.CreateSuccessResult( resultReceive.Content.HeadBytes, resultReceive.Content.ContentBytes )
		else:
			return OperateResult.CreateSuccessResult( bytearray(0), bytearray(0) )

	def GetBoolResultFromBytes( self, result ):
		'''将指定的OperateResult类型转化'''
		return ByteTransformHelper.GetBoolResultFromBytes( result, self.byteTransform)
	def GetByteResultFromBytes( self, result ):
		'''将指定的OperateResult类型转化'''
		return ByteTransformHelper.GetByteResultFromBytes( result, self.byteTransform)
	def GetInt16ResultFromBytes( self, result ):
		'''将指定的OperateResult类型转化'''
		return ByteTransformHelper.GetInt16ResultFromBytes( result, self.byteTransform)
	def GetUInt16ResultFromBytes( self, result ):
		'''将指定的OperateResult类型转化'''
		return ByteTransformHelper.GetUInt16ResultFromBytes( result, self.byteTransform)
	def GetInt32ResultFromBytes( self, result ):
		'''将指定的OperateResult类型转化'''
		return ByteTransformHelper.GetInt32ResultFromBytes( result, self.byteTransform )
	def GetUInt32ResultFromBytes( self, result ):
		'''将指定的OperateResult类型转化'''
		return ByteTransformHelper.GetUInt32ResultFromBytes( result, self.byteTransform )
	def GetInt64ResultFromBytes( self, result ):
		'''将指定的OperateResult类型转化'''
		return ByteTransformHelper.GetInt64ResultFromBytes( result, self.byteTransform )
	def GetUInt64ResultFromBytes( self, result ):
		'''将指定的OperateResult类型转化'''
		return ByteTransformHelper.GetUInt64ResultFromBytes( result, self.byteTransform )
	def GetSingleResultFromBytes( self, result ):
		'''将指定的OperateResult类型转化'''
		return ByteTransformHelper.GetSingleResultFromBytes( result, self.byteTransform )
	def GetDoubleResultFromBytes( self, result ):
		'''将指定的OperateResult类型转化'''
		return ByteTransformHelper.GetDoubleResultFromBytes( result, self.byteTransform )
	def GetStringResultFromBytes( self, result ):
		'''将指定的OperateResult类型转化'''
		return ByteTransformHelper.GetStringResultFromBytes( result, self.byteTransform )

class NetworkDeviceBase(NetworkDoubleBase):
	'''设备类的基类，提供了基础的字节读写方法'''
	# 单个数据字节的长度，西门子为2
	WordLength = 1
	def Read( self, address, length ):
		'''从设备读取原始数据'''
		return OperateResult( )
	def Write( self, address, value ):
		'''将原始数据写入设备'''
		return OperateResult()
	def ReadInt16( self, address, length = None ):
		'''读取设备的short类型的数据'''
		if(length == None):
			return self.GetInt16ResultFromBytes( self.Read( address, self.WordLength ) )
		else:
			read = self.Read(address,length*self.WordLength)
			if read.IsSuccess == False:
				return OperateResult.CreateFailedResult(read)
			return OperateResult.CreateSuccessResult(self.byteTransform.TransInt16Array(read.Content,0,length))
	def ReadUInt16( self, address, length = None ):
		'''读取设备的ushort数据类型的数据'''
		if length == None:
			return self.GetUInt16ResultFromBytes(self.Read(address,self.WordLength))
		else:
			read = self.Read(address,length*self.WordLength)
			if read.IsSuccess == False:
				return OperateResult.CreateFailedResult(read)
			return OperateResult.CreateSuccessResult(self.byteTransform.TransUInt16Array(read.Content,0,length))
	def ReadInt32( self, address, length = None ):
		'''读取设备的int类型的数据'''
		if length == None:
			return self.GetInt32ResultFromBytes( self.Read( address, 2 * self.WordLength ) )
		else:
			read = self.Read(address,2*length*self.WordLength)
			if read.IsSuccess == False:
				return OperateResult.CreateFailedResult(read)
			return OperateResult.CreateSuccessResult(self.byteTransform.TransInt32Array(read.Content,0,length))
	def ReadUInt32( self, address, length = None ):
		'''读取设备的uint数据类型的数据'''
		if length == None:
			return self.GetUInt32ResultFromBytes(self.Read(address,2 * self.WordLength))
		else:
			read = self.Read(address,2*length*self.WordLength)
			if read.IsSuccess == False:
				return OperateResult.CreateFailedResult(read)
			return OperateResult.CreateSuccessResult(self.byteTransform.TransUInt32Array(read.Content,0,length))
	def ReadFloat( self, address, length = None ):
		'''读取设备的float类型的数据'''
		if length == None:
			return self.GetSingleResultFromBytes( self.Read( address, 2 * self.WordLength ) )
		else:
			read = self.Read(address,2*length*self.WordLength)
			if read.IsSuccess == False:
				return OperateResult.CreateFailedResult(read)
			return OperateResult.CreateSuccessResult(self.byteTransform.TransSingleArray(read.Content,0,length))
	def ReadInt64( self, address, length = None ):
		'''读取设备的long类型的数组'''
		if length == None:
			return self.GetInt64ResultFromBytes( self.Read( address, 4 * self.WordLength) )
		else:
			read = self.Read(address,4*length*self.WordLength)
			if read.IsSuccess == False:
				return OperateResult.CreateFailedResult(read)
			return OperateResult.CreateSuccessResult(self.byteTransform.TransInt64Array(read.Content,0,length))
	def ReadUInt64( self, address, length = None ):
		'''读取设备的long类型的数组'''
		if length == None:
			return self.GetUInt64ResultFromBytes( self.Read( address, 4 * self.WordLength) )
		else:
			read = self.Read(address,4*length*self.WordLength)
			if read.IsSuccess == False:
				return OperateResult.CreateFailedResult(read)
			return OperateResult.CreateSuccessResult(self.byteTransform.TransUInt64Array(read.Content,0,length))
	def ReadDouble( self, address, length = None ):
		'''读取设备的long类型的数组'''
		if length == None:
			return self.GetDoubleResultFromBytes( self.Read( address, 4 * self.WordLength) )
		else:
			read = self.Read(address,4*length*self.WordLength)
			if read.IsSuccess == False:
				return OperateResult.CreateFailedResult(read)
			return OperateResult.CreateSuccessResult(self.byteTransform.TransDoubleArray(read.Content,0,length))
	def ReadString( self, address, length ):
		return self.GetStringResultFromBytes( self.Read( address, length ) )
	
	def WriteInt16( self, address, value ):
		'''向设备中写入short数据或是数组，返回是否写入成功'''
		if type(value) == list:
			return self.Write( address, self.byteTransform.Int16ArrayTransByte( value ) )
		else:
			return self.WriteInt16( address, [value] )
	def WriteUInt16( self, address, value ):
		'''向设备中写入short数据或是数组，返回是否写入成功'''
		if type(value) == list:
			return self.Write( address, self.byteTransform.UInt16ArrayTransByte( value ) )
		else:
			return self.WriteUInt16( address, [value] )
	def WriteInt32( self, address, value ):
		'''向设备中写入int数据，返回是否写入成功'''
		if type(value) == list:
			return self.Write( address, self.byteTransform.Int32ArrayTransByte(value) )
		else:
			return self.WriteInt32( address, [value])
	def WriteUInt32( self, address, value):
		'''向设备中写入uint数据，返回是否写入成功'''
		if type(value) == list:
			return self.Write( address, self.byteTransform.UInt32ArrayTransByte(value) )
		else:
			return self.WriteUInt32( address, [value] )
	def WriteFloat( self, address, value ):
		'''向设备中写入float数据，返回是否写入成功'''
		if type(value) == list:
			return self.Write( address, self.byteTransform.FloatArrayTransByte(value) )
		else:
			return self.WriteFloat(address, [value])
	def WriteInt64( self, address, value ):
		'''向设备中写入long数据，返回是否写入成功'''
		if type(value) == list:
			return self.Write( address,  self.byteTransform.Int64ArrayTransByte(value))
		else:
			return self.WriteInt64( address, [value] )
	def WriteUInt64( self, address, value ):
		'''向设备中写入ulong数据，返回是否写入成功'''
		if type(value) == list:
			return self.Write( address,  self.byteTransform.UInt64ArrayTransByte(value))
		else:
			return self.WriteUInt64( address, [value] )
	def WriteDouble( self, address, value ):
		'''向设备中写入double数据，返回是否写入成功'''
		if type(value) == list:
			return self.Write( address, self.byteTransform.DoubleArrayTransByte(value) )
		else:
			return self.WriteDouble( address, [value] )
	def WriteString( self, address, value, length = None ):
		'''向设备中写入string数据，编码为ascii，返回是否写入成功'''
		if length == None:
			return self.Write( address, self.byteTransform.StringTransByte( value, 'ascii' ) )
		else:
			return self.Write( address, SoftBasic.ArrayExpandToLength(self.byteTransform.StringTransByte( value, 'ascii' ), length))
	def WriteUnicodeString( self, address, value, length = None):
		'''向设备中写入string数据，编码为unicode，返回是否写入成功'''
		if length == None:
			temp = SoftBasic.StringToUnicodeBytes(value)
			return self.Write( address, temp )
		else:
			temp = SoftBasic.StringToUnicodeBytes(value)
			temp = SoftBasic.ArrayExpandToLength( temp, length * 2 )
			return self.Write( address, temp )


# 西门子的数据类
class SiemensPLCS(Enum):
	'''西门子PLC的类对象'''
	S1200 = 0
	S300 = 1
	S1500 = 2
	S200Smart = 3
class SiemensS7Net(NetworkDeviceBase):
	'''一个西门子的客户端类，使用S7协议来进行数据交互'''
	CurrentPlc = SiemensPLCS.S1200
	plcHead1 = bytearray([0x03,0x00,0x00,0x16,0x11,0xE0,0x00,0x00,0x00,0x01,0x00,0xC0,0x01,0x0A,0xC1,0x02,0x01,0x02,0xC2,0x02,0x01,0x00])
	plcHead2 = bytearray([0x03,0x00,0x00,0x19,0x02,0xF0,0x80,0x32,0x01,0x00,0x00,0x04,0x00,0x00,0x08,0x00,0x00,0xF0,0x00,0x00,0x01,0x00,0x01,0x01,0xE0])
	plcOrderNumber = bytearray([0x03,0x00,0x00,0x21,0x02,0xF0,0x80,0x32,0x07,0x00,0x00,0x00,0x01,0x00,0x08,0x00,0x08,0x00,0x01,0x12,0x04,0x11,0x44,0x01,0x00,0xFF,0x09,0x00,0x04,0x00,0x11,0x00,0x00])
	plcHead1_200smart = bytearray([0x03,0x00,0x00,0x16,0x11,0xE0,0x00,0x00,0x00,0x01,0x00,0xC1,0x02,0x10,0x00,0xC2,0x02,0x03,0x00,0xC0,0x01,0x0A])
	plcHead2_200smart = bytearray([0x03,0x00,0x00,0x19,0x02,0xF0,0x80,0x32,0x01,0x00,0x00,0xCC,0xC1,0x00,0x08,0x00,0x00,0xF0,0x00,0x00,0x01,0x00,0x01,0x03,0xC0])
	def __init__(self, siemens, ipAddress = "127.0.0.1"):
		'''实例化一个西门子的S7协议的通讯对象并指定Ip地址'''
		self.WordLength = 2
		self.ipAddress = ipAddress
		self.port = 102
		self.CurrentPlc = siemens
		self.iNetMessage = S7Message()
		self.byteTransform = ReverseBytesTransform()

		if siemens == SiemensPLCS.S1200:
			self.plcHead1[21] = 0
		elif siemens == SiemensPLCS.S300:
			self.plcHead1[21] = 2
		elif siemens == SiemensPLCS.S1500:
			self.plcHead1[21] = 0
		elif siemens == SiemensPLCS.S200Smart:
			self.plcHead1 = self.plcHead1_200smart
			self.plcHead2 = self.plcHead2_200smart
		else:
			self.plcHead1[18] = 0
	@staticmethod
	def CalculateAddressStarted( address = "M0" ):
		'''计算特殊的地址信息'''
		if address.find('.') >= 0:
			temp = address.split(".")
			return int(temp[0]) * 8 + int(temp[1])
		else:
			return int( address ) * 8
	@staticmethod
	def AnalysisAddress( address = 'M0' ):
		'''解析数据地址，解析出地址类型，起始地址，DB块的地址'''
		result = OperateResult( )
		try:
			result.Content3 = 0
			if address[0] == 'I':
				result.Content1 = 0x81
				result.Content2 = SiemensS7Net.CalculateAddressStarted( address[1:] )
			elif address[0] == 'Q':
				result.Content1 = 0x82
				result.Content2 = SiemensS7Net.CalculateAddressStarted( address[1:] )
			elif address[0] == 'M':
				result.Content1 = 0x83
				result.Content2 = SiemensS7Net.CalculateAddressStarted( address[1:] )
			elif address[0] == 'D' or address[0:2] == "DB":
				result.Content1 = 0x84
				adds = address.split(".")
				if address[1] == 'B':
					result.Content3 = int( adds[0][2:] )
				else:
					result.Content3 = int( adds[0][1:] )
				result.Content2 = SiemensS7Net.CalculateAddressStarted( address[ (address.find( '.' ) + 1):]) 
			elif address[0] == 'T':
				result.Content1 = 0x1D
				result.Content2 = SiemensS7Net.CalculateAddressStarted( address[1:] )
			elif address[0] == 'C':
				result.Content1 = 0x1C
				result.Content2 = SiemensS7Net.CalculateAddressStarted( address[1:] )
			elif address[0] == 'V':
				result.Content1 = 0x84
				result.Content3 = 1
				result.Content2 = SiemensS7Net.CalculateAddressStarted( address[1:] )
			else:
				result.Message = StringResources.NotSupportedDataType()
				result.Content1 = 0
				result.Content2 = 0
				result.Content3 = 0
				return result
		except Exception as ex:
			result.Message = str(ex)
			return result

		result.IsSuccess = True
		return result
	@staticmethod
	def BuildReadCommand( address, length ):
		'''生成一个读取字数据指令头的通用方法'''
		if address == None : raise Exception( "address" )
		if length == None : raise Exception( "count" )
		if len(address) != len(length) : raise Exception( "两个参数的个数不统一" )
		if len(length) > 19 : raise Exception( "读取的数组数量不允许大于19" )

		readCount = len(length)
		_PLCCommand = bytearray(19 + readCount * 12)
		# ======================================================================================
		_PLCCommand[0] = 0x03                                                # 报文头
		_PLCCommand[1] = 0x00
		_PLCCommand[2] = len(_PLCCommand) // 256                           # 长度
		_PLCCommand[3] = len(_PLCCommand) % 256
		_PLCCommand[4] = 0x02                                                # 固定
		_PLCCommand[5] = 0xF0
		_PLCCommand[6] = 0x80
		_PLCCommand[7] = 0x32                                                # 协议标识
		_PLCCommand[8] = 0x01                                                # 命令：发
		_PLCCommand[9] = 0x00                                                # redundancy identification (reserved): 0x0000;
		_PLCCommand[10] = 0x00                                               # protocol data unit reference; it’s increased by request event;
		_PLCCommand[11] = 0x00
		_PLCCommand[12] = 0x01                                               # 参数命令数据总长度
		_PLCCommand[13] = (len(_PLCCommand) - 17) // 256
		_PLCCommand[14] = (len(_PLCCommand) - 17) % 256
		_PLCCommand[15] = 0x00                                               # 读取内部数据时为00，读取CPU型号为Data数据长度
		_PLCCommand[16] = 0x00
		# =====================================================================================
		_PLCCommand[17] = 0x04                                               # 读写指令，04读，05写
		_PLCCommand[18] = readCount                                    # 读取数据块个数

		for ii in range(readCount):
			#===========================================================================================
			# 指定有效值类型
			_PLCCommand[19 + ii * 12] = 0x12
			# 接下来本次地址访问长度
			_PLCCommand[20 + ii * 12] = 0x0A
			# 语法标记，ANY
			_PLCCommand[21 + ii * 12] = 0x10
			# 按字为单位
			_PLCCommand[22 + ii * 12] = 0x02
			# 访问数据的个数
			_PLCCommand[23 + ii * 12] = length[ii] // 256
			_PLCCommand[24 + ii * 12] = length[ii] % 256
			# DB块编号，如果访问的是DB块的话
			_PLCCommand[25 + ii * 12] = address[ii].Content3 // 256
			_PLCCommand[26 + ii * 12] = address[ii].Content3 % 256
			# 访问数据类型
			_PLCCommand[27 + ii * 12] = address[ii].Content1
			# 偏移位置
			_PLCCommand[28 + ii * 12] = address[ii].Content2 // 256 // 256 % 256
			_PLCCommand[29 + ii * 12] = address[ii].Content2 // 256 % 256
			_PLCCommand[30 + ii * 12] = address[ii].Content2 % 256

		return OperateResult.CreateSuccessResult( _PLCCommand )
	@staticmethod
	def BuildBitReadCommand( address ):
		'''生成一个位读取数据指令头的通用方法'''
		analysis = SiemensS7Net.AnalysisAddress( address )
		if analysis.IsSuccess == False : return OperateResult.CreateFailedResult( analysis )

		_PLCCommand = bytearray(31)
		# 报文头
		_PLCCommand[0] = 0x03
		_PLCCommand[1] = 0x00
		# 长度
		_PLCCommand[2] = len(_PLCCommand) // 256
		_PLCCommand[3] = len(_PLCCommand) % 256
		# 固定
		_PLCCommand[4] = 0x02
		_PLCCommand[5] = 0xF0
		_PLCCommand[6] = 0x80
		_PLCCommand[7] = 0x32
		# 命令：发
		_PLCCommand[8] = 0x01
		# 标识序列号
		_PLCCommand[9] = 0x00
		_PLCCommand[10] = 0x00
		_PLCCommand[11] = 0x00
		_PLCCommand[12] = 0x01
		# 命令数据总长度
		_PLCCommand[13] = (len(_PLCCommand) - 17) // 256
		_PLCCommand[14] = (len(_PLCCommand) - 17) % 256

		_PLCCommand[15] = 0x00
		_PLCCommand[16] = 0x00

		# 命令起始符
		_PLCCommand[17] = 0x04
		# 读取数据块个数
		_PLCCommand[18] = 0x01

		#===========================================================================================
		# 读取地址的前缀
		_PLCCommand[19] = 0x12
		_PLCCommand[20] = 0x0A
		_PLCCommand[21] = 0x10
		# 读取的数据时位
		_PLCCommand[22] = 0x01
		# 访问数据的个数
		_PLCCommand[23] = 0x00
		_PLCCommand[24] = 0x01
		# DB块编号，如果访问的是DB块的话
		_PLCCommand[25] = analysis.Content3 // 256
		_PLCCommand[26] = analysis.Content3 % 256
		# 访问数据类型
		_PLCCommand[27] = analysis.Content1
		# 偏移位置
		_PLCCommand[28] = analysis.Content2 // 256 // 256 % 256
		_PLCCommand[29] = analysis.Content2 // 256 % 256
		_PLCCommand[30] = analysis.Content2 % 256

		return OperateResult.CreateSuccessResult( _PLCCommand )
	@staticmethod
	def BuildWriteByteCommand( address, data ):
		'''生成一个写入字节数据的指令'''
		if data == None : data = bytearray(0)
		analysis = SiemensS7Net.AnalysisAddress( address )
		if analysis.IsSuccess == False : return OperateResult.CreateFailedResult(analysis)

		_PLCCommand = bytearray(35 + len(data))
		_PLCCommand[0] = 0x03
		_PLCCommand[1] = 0x00
		# 长度
		_PLCCommand[2] = (35 + len(data)) // 256
		_PLCCommand[3] = (35 + len(data)) % 256
		# 固定
		_PLCCommand[4] = 0x02
		_PLCCommand[5] = 0xF0
		_PLCCommand[6] = 0x80
		_PLCCommand[7] = 0x32
		# 命令 发
		_PLCCommand[8] = 0x01
		# 标识序列号
		_PLCCommand[9] = 0x00
		_PLCCommand[10] = 0x00
		_PLCCommand[11] = 0x00
		_PLCCommand[12] = 0x01
		# 固定
		_PLCCommand[13] = 0x00
		_PLCCommand[14] = 0x0E
		# 写入长度+4
		_PLCCommand[15] = (4 + len(data)) // 256
		_PLCCommand[16] = (4 + len(data)) % 256
		# 读写指令
		_PLCCommand[17] = 0x05
		# 写入数据块个数
		_PLCCommand[18] = 0x01
		# 固定，返回数据长度
		_PLCCommand[19] = 0x12
		_PLCCommand[20] = 0x0A
		_PLCCommand[21] = 0x10
		# 写入方式，1是按位，2是按字
		_PLCCommand[22] = 0x02
		# 写入数据的个数
		_PLCCommand[23] = len(data) // 256
		_PLCCommand[24] = len(data) % 256
		# DB块编号，如果访问的是DB块的话
		_PLCCommand[25] = analysis.Content3 // 256
		_PLCCommand[26] = analysis.Content3 % 256
		# 写入数据的类型
		_PLCCommand[27] = analysis.Content1
		# 偏移位置
		_PLCCommand[28] = analysis.Content2 // 256 // 256 % 256
		_PLCCommand[29] = analysis.Content2 // 256 % 256
		_PLCCommand[30] = analysis.Content2 % 256
		# 按字写入
		_PLCCommand[31] = 0x00
		_PLCCommand[32] = 0x04
		# 按位计算的长度
		_PLCCommand[33] = len(data) * 8 // 256
		_PLCCommand[34] = len(data) * 8 % 256

		_PLCCommand[35:] = data

		return OperateResult.CreateSuccessResult(_PLCCommand)
	@staticmethod
	def BuildWriteBitCommand( address, data ):
		analysis = SiemensS7Net.AnalysisAddress( address )
		if analysis.IsSuccess == False : return OperateResult.CreateFailedResult(analysis)

		buffer = bytearray(1)
		if data == True : buffer[0] = 0x01

		_PLCCommand = bytearray(35 + len(buffer))
		_PLCCommand[0] = 0x03
		_PLCCommand[1] = 0x00
		# 长度
		_PLCCommand[2] = (35 + len(buffer)) // 256
		_PLCCommand[3] = (35 + len(buffer)) % 256
		# 固定
		_PLCCommand[4] = 0x02
		_PLCCommand[5] = 0xF0
		_PLCCommand[6] = 0x80
		_PLCCommand[7] = 0x32
		# 命令 发
		_PLCCommand[8] = 0x01
		# 标识序列号
		_PLCCommand[9] = 0x00
		_PLCCommand[10] = 0x00
		_PLCCommand[11] = 0x00
		_PLCCommand[12] = 0x01
		# 固定
		_PLCCommand[13] = 0x00
		_PLCCommand[14] = 0x0E
		# 写入长度+4
		_PLCCommand[15] = (4 + len(buffer)) // 256
		_PLCCommand[16] = (4 + len(buffer)) % 256
		# 命令起始符
		_PLCCommand[17] = 0x05
		# 写入数据块个数
		_PLCCommand[18] = 0x01
		_PLCCommand[19] = 0x12
		_PLCCommand[20] = 0x0A
		_PLCCommand[21] = 0x10
		# 写入方式，1是按位，2是按字
		_PLCCommand[22] = 0x01
		# 写入数据的个数
		_PLCCommand[23] = len(buffer) // 256
		_PLCCommand[24] = len(buffer) % 256
		# DB块编号，如果访问的是DB块的话
		_PLCCommand[25] = analysis.Content3 // 256
		_PLCCommand[26] = analysis.Content3 % 256
		# 写入数据的类型
		_PLCCommand[27] = analysis.Content1
		# 偏移位置
		_PLCCommand[28] = analysis.Content2 // 256 // 256
		_PLCCommand[29] = analysis.Content2 // 256
		_PLCCommand[30] = analysis.Content2 % 256
		# 按位写入
		_PLCCommand[31] = 0x00
		_PLCCommand[32] = 0x03
		# 按位计算的长度
		_PLCCommand[33] = len(buffer) // 256
		_PLCCommand[34] = len(buffer) % 256

		_PLCCommand[35:] = buffer
		
		return OperateResult.CreateSuccessResult(_PLCCommand)

	def InitializationOnConnect( self, socket ):
		'''连接上服务器后需要进行的二次握手操作'''
		# msg = SoftBasic.ByteToHexString(self.plcHead1, ' ')
		# 第一次握手
		read_first = self.ReadFromCoreServerBase( socket, self.plcHead1 )
		if read_first.IsSuccess == False : return read_first

		# 第二次握手
		read_second = self.ReadFromCoreServerBase( socket, self.plcHead2 )
		if read_second.IsSuccess == False : return read_second

		# 返回成功的信号
		return OperateResult.CreateSuccessResult( )
	def ReadOrderNumber( self ):
		'''从PLC读取订货号信息'''
		read = self.ReadFromCoreServer( self.plcOrderNumber )
		if read.IsSuccess == False : return OperateResult.CreateFailedResult( read )

		return OperateResult.CreateSuccessResult( read.Content[71:92].decode('ascii') )
	def __ReadBase( self, address, length ):
		'''基础的读取方法，外界不应该调用本方法'''
		command = SiemensS7Net.BuildReadCommand( address, length )
		if command.IsSuccess == False : return command

		read = self.ReadFromCoreServer( command.Content )
		if read.IsSuccess == False : return read

		# 分析结果
		receiveCount = 0
		for i in range(len(length)):
			receiveCount += length[i]

		if len(read.Content) >= 21 and read.Content[20] == len(length) :
			buffer = bytearray(receiveCount)
			kk = 0
			ll = 0
			ii = 21
			while ii < len(read.Content):
				if ii + 1 < len(read.Content):
					if read.Content[ii] == 0xFF and read.Content[ii + 1] == 0x04:
						# 有数据
						buffer[ll : ll + length[kk]] = read.Content[ii+4 : ii+4+length[kk]]
						ii += length[kk] + 3
						ll += length[kk]
						kk += 1
				ii += 1
			return OperateResult.CreateSuccessResult( buffer )
		else :
			result = OperateResult()
			result.ErrorCode = read.ErrorCode
			result.Message = "数据块长度校验失败"
			return result
	
	def Read( self, address, length ):
		'''从PLC读取数据，地址格式为I100，Q100，DB20.100，M100，T100，C100以字节为单位'''
		if type(address) == list and type(length) == list:
			addressResult = []
			for i in range(length):
				tmp = SiemensS7Net.AnalysisAddress( address[i] )
				if tmp.IsSuccess == False : return OperateResult.CreateFailedResult( addressResult[i] )

				addressResult.append( tmp )
			return self.__ReadBase( addressResult, length )
		else:
			addressResult = SiemensS7Net.AnalysisAddress( address )
			if addressResult.IsSuccess == False : return OperateResult.CreateFailedResult( addressResult )

			bytesContent = bytearray()
			alreadyFinished = 0
			while alreadyFinished < length :
				readLength = min( length - alreadyFinished, 200 )
				read = self.__ReadBase( [ addressResult ], [ readLength ] )
				if read.IsSuccess == True :
					bytesContent.extend( read.Content )
				else:
					return read

				alreadyFinished += readLength
				addressResult.Content2 += readLength * 8

			return OperateResult.CreateSuccessResult( bytesContent )
	def __ReadBitFromPLC( self, address ):
		'''从PLC读取数据，地址格式为I100，Q100，DB20.100，M100，以位为单位'''
		# 指令生成
		command = SiemensS7Net.BuildBitReadCommand( address )
		if command.IsSuccess == False : return OperateResult.CreateFailedResult( command )

		# 核心交互
		read = self.ReadFromCoreServer( command.Content )
		if read.IsSuccess == False : return read

		# 分析结果
		receiveCount = 1
		if len(read.Content) >= 21 and read.Content[20] == 1 :
			buffer = bytearray(receiveCount)
			if 22 < len(read.Content) :
				if read.Content[21] == 0xFF and read.Content[22] == 0x03:
					# 有数据
					buffer[0] = read.Content[25]
			return OperateResult.CreateSuccessResult( buffer )
		else:
			result = OperateResult()
			result.ErrorCode = read.ErrorCode
			result.Message = "数据块长度校验失败"
			return result
	def ReadBool( self, address ):
		'''读取指定地址的bool数据'''
		return self.GetBoolResultFromBytes( self.__ReadBitFromPLC( address ) )
	def ReadByte( self, address ):
		'''读取指定地址的byte数据'''
		return self.GetByteResultFromBytes( self.Read( address, 1 ) )
	def __WriteBase( self, entireValue ):
		'''基础的写入数据的操作支持'''
		write = self.ReadFromCoreServer( entireValue )
		if write.IsSuccess == False : return write

		if (len(write.Content)) ==  20 or 21 :
			return OperateResult.CreateSuccessResult( )

		if write.Content[len(write.Content) - 1] != 0xFF :
			# 写入异常
			return OperateResult( msg = "写入数据异常", err = write.Content[write.Content.Length - 1])
		else:
			return OperateResult.CreateSuccessResult( )
	def Write( self, address, value ):
		'''将数据写入到PLC数据，地址格式为I100，Q100，DB20.100，M100，以字节为单位'''
		command = self.BuildWriteByteCommand( address, value )
		if command.IsSuccess == False : return command

		return self.__WriteBase( command.Content )
	def WriteBool( self, address, value ):
		'''写入PLC的一个位，例如"M100.6"，"I100.7"，"Q100.0"，"DB20.100.0"，如果只写了"M100"默认为"M100.0'''
		# 生成指令
		command = SiemensS7Net.BuildWriteBitCommand( address, value )
		if command.IsSuccess == False : return command

		return self.__WriteBase( command.Content )
	def WriteByte( self, address, value ):
		'''向PLC中写入byte数据，返回值说明'''
		return self.Write( address, [value] )

	# 热启动
	def BuildHotStartCommand(self):
		_PLCCommand = bytearray([0x03, 0x00, 0x00, 0x25,
            0x02, 0xf0, 0x80, 0x32,
            0x01, 0x00, 0x00, 0x0c,
            0x00, 0x00, 0x14, 0x00,
            0x00, 0x28, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00,
            0xfd, 0x00, 0x00, 0x09,
            0x50, 0x5f, 0x50, 0x52,
            0x4f, 0x47, 0x52, 0x41,
            0x4d])
		return OperateResult.CreateSuccessResult(_PLCCommand)
	def HotStart(self):
		command = self.BuildHotStartCommand()
		return self.__WriteBase( command.Content )
	
	#冷启动
	def BuildColdStartCommand(self):
		_PLCCommand = bytearray([0x03, 0x00, 0x00, 0x27,
            0x02, 0xf0, 0x80, 0x32,
            0x01, 0x00, 0x00, 0x0f,
            0x00, 0x00, 0x16, 0x00,
            0x00, 0x28, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00,
            0xfd, 0x00, 0x02, 0x43,
            0x20, 0x09, 0x50, 0x5f,
            0x50, 0x52, 0x4f, 0x47,
            0x52, 0x41, 0x4d])
		return OperateResult.CreateSuccessResult(_PLCCommand)
	def ColdStart(self):
		command = self.BuildColdStartCommand()
		return self.__WriteBase( command.Content )
	
	# PLC 停止
	def BuildPLCStopCommand(self):
		_PLCCommand = bytearray([0x03, 0x00, 0x00, 0x21,
            0x02, 0xf0, 0x80, 0x32,
            0x01, 0x00, 0x00, 0x0e,
            0x00, 0x00, 0x10, 0x00,
            0x00, 0x29, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x09,
            0x50, 0x5f, 0x50, 0x52,
            0x4f, 0x47, 0x52, 0x41,
            0x4d])
		return OperateResult.CreateSuccessResult(_PLCCommand)
	def PLC_Stop(self):
		command = self.BuildPLCStopCommand()
		return self.__WriteBase( command.Content )