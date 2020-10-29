#ifndef _PCI_DMC_Err_H
#define _PCI_DMC_Err_H

//Readme_Step_3

//General
#define ERR_SameCardNumber			901		//卡號重複(所有軸卡卡號不能相同)
#define ERR_CardType				902		//此軸卡不支援此API
#define ERR_CantFindDLL				903		//此API與其對應的DLL連結失敗(沒有DLL或是DLL函式庫中沒有此函式)
#define ERR_SerchErrorCode			904		//此API的錯誤需使用_DMC_01_get_cardtype_errorcode來取得
#define ERR_NoCardFound				905		//找不到此軸卡
#define ERR_DLLinUse				910		//合併版DLL正被使用中
#define ERR_CantFindAB01			911		//找不到A01DLL
#define ERR_CantFindF01				912		//找不到F01DLL
#define ERR_CantFindDMCDLL			913		//找到A01、F01DLL

//PCI_DMC_A01 / PCI_DMC_B01  
#define ERR_NoError					0		//沒問題
#define ERR_B02_NO_ERROR			0           // <-- Replace with original error code#0
#define ERR_A02_NO_ERROR			0
#define ERR_FeedRate_Entry_Dec		1		//FeedRate overwrite 進入減速段,本指令不再變化速度,但下個指令將會新的速度變化
#define ERR_CardNoError				3		//卡號錯誤請確認卡片上的DIP Switch調整的號碼
#define ERR_bootmodeErr				5		//無法啟動DSP數位程序
#define ERR_downloadcode			6		//DSP Program Memory R/W Error
#define ERR_downloadinit			7		//DSP Data Memory R/W Error
#define ERR_PCI_boot_first			8		//使用此API需先啟動DSP數位程序  I16 PASCAL _DMC_01_pci_initial(U16 CardNo)
#define ERR_FeedRate_updata			9		//FeedRate overwrite 的值相同 
#define ERR_DSP_inside_calcu		10		//DSP memory float error
#define ERR_AxisNoError				11		//軸數目過大
#define ERR_IPO_First				12		//需要為IPO模式
#define ERR_Target_reach			13		//Mode 1 運行時,需Target到達
#define ERR_Servo_on_first			14		//需要先servo on 
#define ERR_MPG_Mode				15		//在手輪模式下無法清除位置
#define ERR_PDO_TG					16		//使用PDO模式下指令給模組,無法回傳收到
#define ERR_ConfigFileOpenError		17		//建立Debug Information檔案錯誤
#define ERR_Ctrl_value				18		//使用控制指令錯誤
#define ERR_Security_Fifo			19		//使用Security Fpga write Error
#define ERR_Security_Fifo_busy     	20		//使用Security Fpga busy
#define ERR_SpeedLimitError			21		//設定速度大於最大速度
#define ERR_Security_Page			22		//使用Security page 需要小於16
#define ERR_Slave_Security_op		23		//使用Security slave_operate 指令無效
#define ERR_channel_no				24		//channel no 錯誤
#define ERR_start_ring_first		25		//使用此API需先啟動DMCNet  I16 PASCAL _DMC_01_start_ring(U16 CardNo, U8 RingNo)
#define ERR_NodeIDError				26		//無此NodeID
#define ERR_MailBoxErr				27		//指令無法下達, DSP Busy
#define ERR_SdoData					28		//SDO Data送出但無回應,SDO Data Send Request ,But Without ACK
#define ERR_IOCTL					29		//作業系統無法處理此IRP
#define ERR_SdoSvonFirst			30		//使用SDO操作軸控時,需先Servo On
#define ERR_SlotIDError				31		//GA無此Slot號碼
#define ERR_PDO_First				32		//使用PDO指令需先將軸轉成PDO模式
#define ERR_Protocal_build			33		//Protocal,電氣尚未建立
#define ERR_Maching_TimeOut			34		//模組配對time Out
#define ERR_Maching_NG				35		//模組配對NG
#define ERR_Group_Num				36		//設定群組最大值為6組
#define ERR_Master_Alarm			37		//故障發生(通訊不良,Driver Alm)
#define ERR_Alarm_reset				38
#define ERR_Master_Security_Wr		40		//使用Security Master Write指令無效
#define ERR_Master_Security_Rd		41		//使用Security Master Read指令無效
#define ERR_Master_Security_Pw		42		//需要先輸入正確的password
#define ERR_NonSupport_CardVer		50		//使用主控卡的版本錯誤,請連繫代理商,購買正確主控卡
#define ERR_Compare_Source			51		//Ver Type : B Compare Source 選擇錯誤
#define ERR_Compare_Direction		52		//Compare的方向錯誤  dir需為1或0 1:ccw,0:cw
#define ERR_GetDLLPath				60
#define ERR_GetDLLVersion			61
#define ERR_GA_Port					62
#define ERR_04PISTOP_Timeout		70		//04PI Stop Fifo time out 
#define ERR_ServoSTOP_Timeout		71		//Servo Stop Fifo time out
#define ERR_04PISTOP_status			72		//04PI Stop MC_done not to Error
#define ERR_04PIHoming_err			73		//04PI Home status error
#define ERR_04PISdo_trans			74		//04PI sdo send but get data error
#define ERR_Rm_Port					75
//PCI_DMC_A02 / PCI_DMC_B02  
 
#define ERR_QEP_INDEX				75		// QEP
#define ERR_GPIO_OUTPUT_SIZE		76		// GPIO
#define ERR_IPCMP_INDEX				77		// IPCMP
#define ERR_IPCMP_MPC_DATA_TYPE		78      // It will never happened (internal use)
#define ERR_TPCMP_FIFO_INDEX		79		// TPCMP
#define ERR_TPCMP_QEP_SOURCE		80
#define ERR_TPCMP_TABLE_NO_DATA		81      // Input table empty
#define ERR_TPCMP_TABLE_OUT_OF_RANGE 82		// Input table size is large than TPCMP max. size
#define ERR_TPCMP_TABLE_OVERFLOW	83      // Input table size is large than TPCMP FIFO remainder size
 
#define ERR_EXTIO_RANGE				84		// EXT. IO
#define ERR_EXTIO_LATCH_TYPE		85           // It will never happened (internal use)
 
#define ERR_LATCH_FIFO_EMPTY		86		// Latch FIFO
#define ERR_LATCH_FIFO_INVALID_DATA	87
/////A02
#define ERR_GPIO_PORTNO				100		//GPIO_OUT/GPIO_IN
#define ERR_JOG_AXISNO				101		//JOG_CTNL
#define ERR_A02_MPG_Enable			102		//A02 手輪已致能,無法重覆致能
#define ERR_A02_JOG_Enable			103		//A02 JOG 已致能,無法重覆致能


#define ERR_RangeError 				112		//設定軸的號碼錯誤  不用加,因為軸的判別加在NodeID
#define ERR_MotionBusy 				114		//Motion 指令重疊
#define ERR_SpeedError 				116		//最大速度設置為0 
#define ERR_AccTimeError 			117		//加減速時大於1000秒
#define ERR_PitchZero 				124		//Helix pitch參數等於0,無法運動



#define ERR_BufferFull 				127		//運動指令Buffer己滿
#define ERR_PathError				128		//運動指令錯誤
#define	ERR_NoSupportMode   		130		//不支援速度變化
#define	ERR_FeedHold_support		132		//Feedhold Stop 啟動,無法接受新指令 
#define	ERR_SDStop_On				133		//執行減速指令, 無法接受新指令
#define	ERR_VelChange_supper		134		//模式1.Feedhold,2.同動指令3.減速指令,無法執行速度變化功能
#define	ERR_Command_set				135		//無法連續執行FeedHold的功能
#define	ERR_sdo_message_choke		136		//Sdo指令回傳有誤,請檢查網路線接線是否OK
#define	ERR_VelChange_buff_feedhold	137		//Feed Hold  功能必須先致能 ,無法速度變化
#define	ERR_VelChange_sync_move		138		//目前軸卡正在等待同動指令,無法速度變化
#define	ERR_VelChange_SD_On			139		//目前軸卡正在執行減速指令,無法速度變化
#define	ERR_P_Change_Mode			140		//單軸點對點模式 加速段,速度等於0,非單軸點對點模式
#define	ERR_BufferLength			141		//當模式在 _Path_p_change,_Path_velocity_change_onfly, _Path_Start_Move_2seg時 Buffer Length 需要為0
#define	ERR_2segMove_Dist			142		//距離需要同向
#define	ERR_CenterMatch				143		//經過反向運算圓心要一致
#define	ERR_EndMatch				144		//經過反向運算圓心要一致
#define	ERR_AngleCalcu				145		//經過計算角度錯誤
#define	ERR_RedCalcu				146		//經過半徑錯誤
#define	ERR_GearSetting				147		//Gear的分子或分母為0
#define	ERR_CamTable				148		// Table Setting First Arrary Point Error設定table不能到負值table[-1]沒有這種設定
#define	ERR_AxesNum					149		// 多軸設定值必須要兩軸以上
#define	ERR_SpiralPos				150		// 最終位置會到達螺旋圓心
#define	ERR_SpeedMode_Slave			151		// 在速度連續時使用的Slave軸,無法執行Motion指令
#define	ERR_SpeedMode_SlaveSet		152		// 設定軸的虛擬必須在軸的前半部
#define	ERR_VelChange_high 			153		// 設定值速度改變過大或是改變sec過長
#define	ERR_Backlash_step 			154		// accstep+contstep+decstep需小於100
#define	ERR_Backlash_status			155		//設定時motion done必需為0且buffer length必需為0	
#define	ERR_DistOver				156		//輸入Dist超過TotalDist

#define		ERR_PVTDataError				160	//PVT motion 輸入的Data有誤
#define		ERR_PVTModeError				161	//不支援PVT模式
#define		ERR_PVTChannel					162	//channel 必需小於支援PVT的軸數 
#define     ERR_TM_DATA_Axis				163	//Table Motion 資料軸數超過最大值 
#define		ERR_TM_CYCLE_DATA				164	//Table Motion 循環次數不等於1時，起始點和末點不同
#define     ERR_TM_DATA_SIZE				165	//資料個數超過上限
#define     ERR_AMFNum						166	//濾波超過2道或小於1道
#define		ERR_TM_INACTIVE					167	//Table Motion 啟動中
#define		ERR_TM_BUFFER_FULL				168	//此次新增資料會超過Buffer大小

#define		ERR_ECAM_DATA_NUM				169	//ECAM資料個數錯誤
#define     ERR_ECAM_LENGTH					170	//ECAM導程(L) <= 0
#define		ERR_ECAM_INDEX					171	//ECAM起始Index錯誤
#define     ERR_DISENGAGE					172  //ECAM脫離時機設置錯誤
#define		ERR_VELOCITY_PERCENT			173	//ECAM速度建表，區域百分比錯誤	
#define     ERR_CONSTRUCT_MODE				174	//ECAM速度建表，模式填錯(非 0 or 1 or 2)
#define		ERR_DISENGAGE_PARA				175	//ECAM脫離參數未設置
#define		ERR_CUTLENGTH					176	//ECAM自動飛剪切長設置錯誤(太長或太短)
#define		ERR_REGION						177	//ECAM自動飛剪區域設置錯誤(剩餘的等待區角度 > S-Curve 角度)
#define		ERR_VELOCITY_SCURVE				178	//ECAM速度建表，S-Curve 區域設置錯誤(超過停止區大小)
#define		ERR_GEARNUM						179	//ECAM齒輪數目錯誤(有小數點或是為0)
#define		ERR_KnifeNUm					180	//ECAM刀具數目 < 1
#define		ERR_MASTER_SOURCE				181	//ECAM主軸來源設置錯誤
#define		ERR_HOLDING_AREA				182	//ECAM等待區角度太大

#define		ERR_TP_CIRCLE_DATA				190	//3點走圓，資料輸入錯誤(三點共線)	
#define		ERR_AMF_ENABLE					193	//AMF已啟動	
#define		ERR_AMF_Time					194	//濾波時間超出範圍	
#define		ERR_SPEED_RATIO					195	//Table Motion 預改變的速度百分比太大	
#define		ERR_MOTION_DONE					196	//已Motion Done，不能在加入資料
#define		ERR_TM_SD_STOP					197	//Table Motion SD STOP 中
#define		ERR_TM_FEEDRATE_OVERWRITE		198  //Table Motion FeedRate Overwrite 中 
#define		ERR_IO_NUMBER					199	//超過最大IO數量
#define		ERR_PROFILE_MODE_ENABLE			200	//TableMotion 速度規劃模式已啟動
#define		ERR_NOT_TM_CYCLE_MODE			201 //不是TableMotion Cycle
#define		ERR_NONE_ANALYSIS				202	//Profile mode 尚未分析
#define		ERR_OVER_TABLE_NUM				203	//超過最Table數目


//20160121 PCI_DMC.dll ERR Code 200號改600號
#define Compare_Cards_Not_Equal						601		//比對結果─軸卡資訊(卡號、數量)不符
#define Compare_Nodes_Not_Equal						602		//比對結果─站號資訊(數量)不符
#define Compare_Node_ID_Not_Equal					603		//比對結果─站號資訊(站號)不符
#define Compare_Node_Device_Type_Not_Equal			604		//比對結果─模組資訊(模組第二分類)不符
#define Compare_Node_Identity_Object_Not_Equal		605		//比對結果─模組資訊(模組第一分類)不符
#define Compare_File_Path_NULL						606		//檔案路徑錯誤
#define Compare_File_Open_Fail						607		//檔案開啟失敗(請確定路徑輸入正確)
#define Compare_File_Not_Exist						608		//檔案不存在

//PCI_DMC_F01

//main
#define ERR_NotCardFound							301		//無此卡號或尚未Initial
#define ERR_CardInitial								302		//Initial失敗
#define ERR_MemoryAccess_Failed						303		//記憶體讀寫失敗
#define ERR_MemoryOutOfRange						304		//記憶體使用超過Range
#define	ERR_UartTxIsBusy							305		//Uart Tx is busy
#define	ERR_UartRxError								306		//Uart Rx 讀取錯誤
#define	ERR_UartRxIsNotReady						307		//Uart Rx 尚未準備完成
#define ERR_NotSupportFunc							308		//不支援此Function
#define ERR_NoNodeFound								309		//站號設置錯誤
#define	ERR_APIInputError							310		//API參數輸入錯誤(超出限定值)
#define ERR_SDOFailed								311		//SDO傳送失敗
#define ERR_SDOBusy									312		//SDO忙碌中 / SDO同時有兩個指令被寫入
#define ERR_APITypeErr								313		//此模組不支援此API
#define ERR_ScaleFailed								314		//AD校正失敗
#define ERR_F_BufferFull							315		//MailBox_Buffer已滿
#define ERR_ConnectErr								316		//通訊連線異常
#define ERR_MBWordChFailed							317		//MailBox同時有兩個指令寫入
#define ERR_MailBoxFailed							318		//MailBox傳送失敗
#define ERR_CantResetCard							319		//無法ResetCard
#define ERR_PDOFailed								320		//PDO未回應
#define ERR_MBCmding								321		//MailBox正在處理指令
#define ERR_SVOFF									322		//此動作需Servo On方可執行
#define ERR_DriverError								323		//此動作因DriverErr無法執行，請先執行Ralm
#define ERR_ConnReset_Failed						324		//初始化重置失敗
#define ERR_F01SlotIDError							325		//此裝置不支援Slot或輸入的Slot編號超出範圍
#define ERR_UartData_NoMatch						326		//Download Code讀取Uart的資料時，回傳無法符合正確值
#define ERR_SVON									327		//此動作需Servo Off方可執行
#define ERR_Mpg_Already_On							328		//此軸已經致能手輪、Jog或DDA功能，其餘功能暫時無法使用
#define ERR_MpgNumber_Over							329		//手輪或Jog致能數量已達上限(最大3組)
#define ERR_Mpg_Data_Failed							330		//手輪或Jog資料傳遞失敗
#define ERR_DDA_Buffer_Full							331		//DDA Buffer已滿
#define ERR_F_Slave_Security_op						332		//Slave Secutiry寫入失敗		
#define ERR_F_Security_Page							333		//Page超過設置
#define ERR_F_GetDLLPath							334		//找不到DLL路徑
#define ERR_F_GetDLLVersion							335		//找不到DLL版本訊息
#define F_Compare_File_Open_Fail					336		//檔案開啟失敗(請確定路徑輸入正確)	
#define F_Compare_File_Not_Exist					337		//檔案不存在
#define F_Compare_Cards_Not_Equal					338		//比對結果─軸卡資訊(卡號、數量)不符
#define F_Compare_File_Path_NULL					339		//檔案路徑錯誤
#define F_Compare_Node_ID_Not_Equal					340		//比對結果─站號資訊(站號)不符
#define F_Compare_Node_Device_Type_Not_Equal		341		//比對結果─模組資訊(模組第二分類)不符
#define F_Compare_Node_Identity_Object_Not_Equal	342		//比對結果─模組資訊(模組第一分類)不符
#define F_Compare_Nodes_Not_Equal					343		//比對結果─站號資訊(數量)不符
#define ERR_SecurityNoRet							344		//Security傳送結果未回傳
#define ERR_SDORetTimeOut							345		//SDO回傳時間過長
#define ERR_Uart_Connect_Fail						346		//Uart通訊失敗
#define ERR_CardNum_SetError						347	//卡號設置錯誤
#define ERR_Target_Reached							348	//無正確停止
#define ERR_NoF02Found								349	//找不到F02卡的序號
#define ERR_MCHSecurity								350	//F02 Security Error


#define ERR_UseGetError								399		//系統型錯誤, 需使用_DMC_01_master_alm_code讀取錯誤碼
//sub if main = 99
#define ERR_sub_NoError				0		//此卡號所對應之軸卡沒有發生錯誤
#define ERR_sub_CantConnect			1		//DMC通訊連結無法生成
#define ERR_sub_SDOFailed			2		//SDO傳送失敗
#define ERR_sub_CantReset			3		//無法重置通訊

#endif