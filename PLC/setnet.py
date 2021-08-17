import wmi

def setnet():
    print ('正在修改IP,请稍候...')
    wmiService = wmi.WMI()
    colNicConfigs = wmiService.Win32_NetworkAdapterConfiguration(IPEnabled=True)
    
    if len(colNicConfigs)<1:
        print ('没有找到可用的网络适配器')
        exit()
    
    #获取以太网
    objNicConfig = colNicConfigs[0]
    
    #内网配置
    arrIPAddresses =['192.168.2.10']
    arrSubnetMasks =['255.255.255.0']
    arrDefaultGateways =['192.168.2.1']
    arrGatewayCostMetrics =[1]
    arrDNSServers =[]
    
    #设置IP 子网掩码 
    returnValue = objNicConfig.EnableStatic(IPAddress= arrIPAddresses,SubnetMask= arrSubnetMasks)
    if returnValue[0]==0:
        print ('设置IP成功')
    elif returnValue[0]==1:
        print ('设置IP成功')
    else:
        print ('修改IP失败: IP设置发生错误')
        exit()
    
    #设置默认网关
    returnValue = objNicConfig.SetGateways(DefaultIPGateway= arrDefaultGateways,GatewayCostMetric= arrGatewayCostMetrics)
    if returnValue[0]==0:
        print ('设置网关成功')
    elif returnValue[0]==1:
        print ('设置网关成功')
    else:
        print ('修改IP失败: 默认网关设置发生错误')
        exit()
    
    #设置DNS
    returnValue = objNicConfig.SetDNSServerSearchOrder(DNSServerSearchOrder= arrDNSServers)
    if returnValue[0]==0:
        print ('设置DNS成功')
    elif returnValue[0]==1:
        print ('设置DNS成功')
    else:
        print ('修改IP失败: DNS设置发生错误')
        exit()