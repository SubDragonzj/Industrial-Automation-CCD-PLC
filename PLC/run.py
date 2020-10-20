from siemens_package import SiemensS7Net
from siemens_package import SiemensPLCS

siemens = SiemensS7Net(SiemensPLCS.S200Smart, "192.168.2.1")

def WriteBool(address, value):
	siemens.WriteBool(address, value)

def WriteInt32(address, value):
	siemens.WriteInt32(address, value)

def ReadBool(address):
	read1 = siemens.ReadBool(address)
	if read1.Content == True:
		return 1
	else:
		return 0