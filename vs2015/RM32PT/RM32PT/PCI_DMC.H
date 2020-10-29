#ifndef _PCI_DMC_COMBINE_H
#define _PCI_DMC_COMBINE_H

#include "Type_def.h"

#if defined __cplusplus
extern "C" {
#endif


typedef struct  
{
	U16 NodeID;
	U16 SlotID;
	U16 BitNo;
	
}IO_Information;   //MotionBuffer


typedef struct  
{
	IO_Information IO_Info;
	U16 Value;
	
}IO_Set, *pIO_Set;	   //MotionBuffer



//Readme_Step_2


I16 _stdcall _DMC_01_open(I16* existcard);
I16 _stdcall _DMC_01_get_CardNo_seq(U16 CardNo_seq, U16 *CardNo);
void _stdcall _DMC_01_close();
I16 _stdcall _DMC_01_pci_initial(U16 CardNo);
I16 _stdcall _DMC_01_initial_bus(U16 CardNo);
I16 _stdcall _DMC_01_initial_bus2();
I16 _stdcall _DMC_01_start_ring(U16 CardNo, U8 RingNo);
I16 _stdcall _DMC_01_get_card_version(U16 CardNo, U16 *ver);
I16 _stdcall _DMC_01_get_devicetype(U16 CardNo, U16 NodeID, U16 SlotID, U32 *DeviceType, U32 *IdentityObject);
I16 _stdcall _DMC_01_get_device_table(U16 CardNo, U16* value);
I16 _stdcall _DMC_01_get_node_table(U16 CardNo, U32 *NodeIDTable);
I16 _stdcall _DMC_01_get_cycle_time(U16 CardNo, I32 *time);   //Internal DSP Math calculation time , Should be less then 1000us  

I16 _stdcall _DMC_01_reset_card(U16 CardNo);
I16 _stdcall _DMC_01_check_nodeno(U16 CardNo, U16 NodeID, U16 SlotID,U16 *exist);
I16 _stdcall _DMC_01_get_master_connect_status(U16 CardNo, U16 *Protocal);
I16 _stdcall _DMC_01_get_mailbox_Error(U16 CardNo, U32* error_cnt);
I16 _stdcall _DMC_01_get_mailbox_cnt(U16 CardNo, U32 *PC_cnt, U32 *DSP_cnt);
I16 _stdcall _DMC_01_get_dsp_cnt(U16 CardNo, U32 *int_cnt, U32 *main_cnt);
I16 _stdcall _DMC_01_set_dio_output(U16 CardNo, U16 On_Off);
I16 _stdcall _DMC_01_get_dio_output(U16 CardNo, U16 *On_Off);
I16 _stdcall _DMC_01_get_dio_input(U16 CardNo, U16 *On_Off);
I16 _stdcall _DMC_01_check_canopen_lock(U16 CardNo, U16 *lock);
I16 _stdcall _DMC_01_get_canopen_ret(U16 CardNo, U16* COBID, U8* value);
I16 _stdcall _DMC_01_send_message(U16 CardNo, U16 NodeID, U16 SlotID, U16 Index, U16 SubIdx, U16 DataType, U16 Value0, U16 Value1, U16 Value2, U16 Value3);
I16 _stdcall _DMC_01_send_message2(U16 CardNo, U16 NodeID, U16 SlotID, U16 Index, U16 SubIdx, U16 DataType, U16 Value0, U16 Value1, U16 Value2, U16 Value3);
I16 _stdcall _DMC_01_send_message3(U16 CardNo, U16 *Index, U16 *SubIdx, U16* DataType, U16 *Value0, U16 *Value1, U16 *Value2, U16 *Value3);
I16 _stdcall _DMC_01_send_message4(U16 CardNo, U16 NodeID, U16 SlotID, U16 Index, U16 SubIdx, U16 DataType, U16 Value0, U16 Value1, U16 Value2, U16 Value3);
I16 _stdcall _DMC_01_reset_sdo_choke(U16 CardNo);
I16 _stdcall _DMC_01_get_sdo_retry_history(U16 CardNo, U32 *cnt);
I16 _stdcall _DMC_01_read_message(U16 CardNo, U16 *Cmd, U16 *COBID, U16 *SubIdx, U16 *Value0, U16 *Value1, U16 *Value2, U16 *Value3);
I16 _stdcall _DMC_01_read_message2(U16 CardNo, U16 NodeID, U16 *Cmd, U16 *COBID, U16 *SubIdx, U16 *Value0, U16 *Value1, U16 *Value2, U16 *Value3, U16 *cnt);
I16 _stdcall _DMC_01_get_message(U16 CardNo, U16 NodeID, U16 SlotID, U16 Index, U16 SubIdx, U16 *Cmd, U16 *COBID, U16 *SubIndex, U16 *Value0, U16 *Value1, U16 *Value2, U16 *Value3);
I16 _stdcall _DMC_01_set_sdo_driver_speed_profile(U16 CardNo, U16 NodeID, U16 SlotID, U32 MaxVel, F64 acc, F64 dec);
I16 _stdcall _DMC_01_start_sdo_driver_r_move(U16 CardNo, U16 NodeID, U16 SlotID, I32 Distance);
I16 _stdcall _DMC_01_start_sdo_driver_a_move(U16 CardNo, U16 NodeID, U16 SlotID, I32 Position);
I16 _stdcall _DMC_01_start_sdo_driver_new_position_move(U16 CardNo, U16 NodeID, U16 SlotID, I32 Position, U16 abs_rel);
I16 _stdcall _DMC_01_set_home_config(U16 CardNo, U16 NodeID, U16 SlotID, U16 Mode, I32 offset, U16 lowSpeed, U16 highSpeed, F64 acc);
I16 _stdcall _DMC_01_set_home_move(U16 CardNo, U16 NodeID, U16 SlotID);
I16 _stdcall _DMC_01_set_home_config2(U16 CardNo, U16 NodeID, U16 SlotID, U16 Mode, I32 offset, U16 lowSpeed, U16 highSpeed, F64 acc);
I16 _stdcall _DMC_01_set_home_config_offset2(U16 CardNo,U16 NodeID ,U16 SlotID ,I32 offset);
I16 _stdcall _DMC_01_set_home_move2(U16 CardNo, U16 NodeID, U16 SlotID, U16 Mode);
I16 _stdcall _DMC_01_escape_home_move(U16 CardNo, U16 NodeID, U16 SlotID);
I16 _stdcall _DMC_01_ipo_set_svon(U16 CardNo, U16 NodeID,U16 SlotID, U16 ON_OFF);
I16 _stdcall _DMC_01_motion_cnt(U16 CardNo, U16 NodeID, U16 SlotID, U16 *pc_mc_cnt, U16 *dsp_mc_cnt);
I16 _stdcall _DMC_01_start_tr_move(U16 CardNo, U16 NodeID, U16 SlotID, I32 Dist, I32 StrVel, I32 MaxVel, F64 Tacc, F64 Tdec);
I16 _stdcall _DMC_01_start_sr_move(U16 CardNo, U16 NodeID, U16 SlotID, I32 Dist, I32 StrVel, I32 MaxVel, F64 Tacc, F64 Tdec);
I16 _stdcall _DMC_01_start_ta_move(U16 CardNo, U16 NodeID, U16 SlotID, I32 Dist, I32 StrVel, I32 MaxVel, F64 Tacc, F64 Tdec);
I16 _stdcall _DMC_01_start_sa_move(U16 CardNo, U16 NodeID, U16 SlotID, I32 Dist, I32 StrVel, I32 MaxVel, F64 Tacc, F64 Tdec);
I16 _stdcall _DMC_01_p_change(U16 CardNo, U16 NodeID,U16 SlotID, I32 NewPos);
//20160725
I16 _stdcall _DMC_01_p_change_multi_axes(U16 CardNo,U16 AxisNum ,U16* NodeID, U16* SlotID, I32 *position, I32 MaxVel, I32 EndVel, F64 Tacc, F64 Tdec, I16 Curve_mode);


I16 _stdcall _DMC_01_v_change(U16 CardNo, U16 NodeID, U16 SlotID, I32 NewSpeed, F64 sec);
I16 _stdcall _DMC_01_start_tr_move_2seg(U16 CardNo, U16 NodeID, U16 SlotID, I32 Dist, I32 Dist2, I32 StrVel, I32 MaxVel, I32 MaxVel2, F64 Tacc, F64 Tsec, F64 Tdec);
I16 _stdcall _DMC_01_start_sr_move_2seg(U16 CardNo, U16 NodeID, U16 SlotID, I32 Dist, I32 Dist2, I32 StrVel, I32 MaxVel, I32 MaxVel2, F64 Tacc, F64 Tsec, F64 Tdec);
I16 _stdcall _DMC_01_start_ta_move_2seg(U16 CardNo, U16 NodeID, U16 SlotID, I32 Dist, I32 Dist2, I32 StrVel, I32 MaxVel, I32 MaxVel2, F64 Tacc, F64 Tsec, F64 Tdec);
I16 _stdcall _DMC_01_start_sa_move_2seg(U16 CardNo, U16 NodeID, U16 SlotID, I32 Dist, I32 Dist2, I32 StrVel, I32 MaxVel, I32 MaxVel2, F64 Tacc, F64 Tsec, F64 Tdec);
I16 _stdcall _DMC_01_start_tr_move_2seg2(U16 CardNo, U16 NodeID, U16 SlotID, I32 Dist, I32 Dist2, I32 StrVel, I32 MaxVel, I32 MaxVel2, F64 Tacc, F64 Tsec, F64 Tdec);
I16 _stdcall _DMC_01_start_sr_move_2seg2(U16 CardNo, U16 NodeID, U16 SlotID, I32 Dist, I32 Dist2, I32 StrVel, I32 MaxVel, I32 MaxVel2, F64 Tacc, F64 Tsec, F64 Tdec);
I16 _stdcall _DMC_01_start_ta_move_2seg2(U16 CardNo, U16 NodeID, U16 SlotID, I32 Dist, I32 Dist2, I32 StrVel, I32 MaxVel, I32 MaxVel2, F64 Tacc, F64 Tsec, F64 Tdec);
I16 _stdcall _DMC_01_start_sa_move_2seg2(U16 CardNo, U16 NodeID, U16 SlotID, I32 Dist, I32 Dist2, I32 StrVel, I32 MaxVel, I32 MaxVel2, F64 Tacc, F64 Tsec, F64 Tdec);
I16 _stdcall _DMC_01_start_tr_move_xy(U16 CardNo, U16* NodeID, U16* SlotID, I32 DisX, I32 DisY, I32 StrVel, I32 MaxVel, F64 Tacc, F64 Tdec);
I16 _stdcall _DMC_01_start_sr_move_xy(U16 CardNo, U16* NodeID, U16* SlotID, I32 DisX, I32 DisY, I32 StrVel, I32 MaxVel, F64 Tacc, F64 Tdec);
I16 _stdcall _DMC_01_start_ta_move_xy(U16 CardNo, U16* NodeID, U16* SlotID, I32 DisX, I32 DisY, I32 StrVel, I32 MaxVel, F64 Tacc, F64 Tdec);
I16 _stdcall _DMC_01_start_sa_move_xy(U16 CardNo, U16* NodeID, U16* SlotID, I32 DisX, I32 DisY, I32 StrVel, I32 MaxVel, F64 Tacc, F64 Tdec);
I16 _stdcall _DMC_01_start_tr_arc_xy(U16 CardNo, U16* NodeID, U16* SlotID, I32 Center_X, I32 Center_Y, F64 Angle, I32 StrVel, I32 MaxVel, F64 Tacc, F64 Tdec);
I16 _stdcall _DMC_01_start_sr_arc_xy(U16 CardNo, U16* NodeID, U16* SlotID, I32 Center_X, I32 Center_Y, F64 Angle, I32 StrVel, I32 MaxVel, F64 Tacc, F64 Tdec);
I16 _stdcall _DMC_01_start_ta_arc_xy(U16 CardNo, U16* NodeID, U16* SlotID, I32 Center_X, I32 Center_Y, F64 Angle, I32 StrVel, I32 MaxVel, F64 Tacc, F64 Tdec);
I16 _stdcall _DMC_01_start_sa_arc_xy(U16 CardNo, U16* NodeID, U16* SlotID, I32 Center_X, I32 Center_Y, F64 Angle, I32 StrVel, I32 MaxVel, F64 Tacc, F64 Tdec);
I16 _stdcall _DMC_01_start_tr_arc2_xy(U16 CardNo, U16* NodeID, U16* SlotID, I32 End_X, I32 End_Y, F64 Angle, I32 StrVel, I32 MaxVel, F64 Tacc, F64 Tdec);
I16 _stdcall _DMC_01_start_sr_arc2_xy(U16 CardNo, U16* NodeID, U16* SlotID, I32 End_X, I32 End_Y, F64 Angle, I32 StrVel, I32 MaxVel, F64 Tacc, F64 Tdec);
I16 _stdcall _DMC_01_start_ta_arc2_xy(U16 CardNo, U16* NodeID, U16* SlotID, I32 End_X, I32 End_Y, F64 Angle, I32 StrVel, I32 MaxVel, F64 Tacc, F64 Tdec);
I16 _stdcall _DMC_01_start_sa_arc2_xy(U16 CardNo, U16* NodeID, U16* SlotID, I32 End_X, I32 End_Y, F64 Angle, I32 StrVel, I32 MaxVel, F64 Tacc, F64 Tdec);
I16 _stdcall _DMC_01_start_tr_arc3_xy(U16 CardNo, U16* NodeID, U16* SlotID, I32 Center_X, I32 Center_Y, I32 End_X, I32 End_Y, I16 Dir, I32 StrVel, I32 MaxVel, F64 Tacc, F64 Tdec);
I16 _stdcall _DMC_01_start_sr_arc3_xy(U16 CardNo, U16* NodeID, U16* SlotID, I32 Center_X, I32 Center_Y, I32 End_X, I32 End_Y, I16 Dir, I32 StrVel, I32 MaxVel, F64 Tacc, F64 Tdec);
I16 _stdcall _DMC_01_start_ta_arc3_xy(U16 CardNo, U16* NodeID, U16* SlotID, I32 Center_X, I32 Center_Y, I32 End_X, I32 End_Y, I16 Dir, I32 StrVel, I32 MaxVel, F64 Tacc, F64 Tdec);
I16 _stdcall _DMC_01_start_sa_arc3_xy(U16 CardNo, U16* NodeID, U16* SlotID, I32 Center_X, I32 Center_Y, I32 End_X, I32 End_Y, I16 Dir, I32 StrVel, I32 MaxVel, F64 Tacc, F64 Tdec);
I16 _stdcall _DMC_01_start_tr_move_xyz(U16 CardNo, U16* NodeID, U16* SlotID, I32 DisX, I32 DisY, I32 DisZ, I32 StrVel, I32 MaxVel, F64 Tacc, F64 Tdec);
I16 _stdcall _DMC_01_start_sr_move_xyz(U16 CardNo, U16* NodeID, U16* SlotID, I32 DisX, I32 DisY, I32 DisZ, I32 StrVel, I32 MaxVel, F64 Tacc, F64 Tdec);
I16 _stdcall _DMC_01_start_ta_move_xyz(U16 CardNo, U16* NodeID, U16* SlotID, I32 DisX, I32 DisY, I32 DisZ, I32 StrVel, I32 MaxVel, F64 Tacc, F64 Tdec);
I16 _stdcall _DMC_01_start_sa_move_xyz(U16 CardNo, U16* NodeID, U16* SlotID, I32 DisX, I32 DisY, I32 DisZ, I32 StrVel, I32 MaxVel, F64 Tacc, F64 Tdec);
I16 _stdcall _DMC_01_start_tr_heli_xy(U16 CardNo, U16* NodeID ,U16* SlotID, I32 Center_X, I32 Center_Y, I32 Depth, I32 Pitch, I16 Dir, I32 StrVel, I32 MaxVel, F64 Tacc, F64 Tdec);
I16 _stdcall _DMC_01_start_sr_heli_xy(U16 CardNo, U16* NodeID ,U16* SlotID, I32 Center_X, I32 Center_Y, I32 Depth, I32 Pitch, I16 Dir, I32 StrVel, I32 MaxVel, F64 Tacc, F64 Tdec);
I16 _stdcall _DMC_01_start_ta_heli_xy(U16 CardNo, U16* NodeID ,U16* SlotID, I32 Center_X, I32 Center_Y, I32 Depth, I32 Pitch, I16 Dir, I32 StrVel, I32 MaxVel, F64 Tacc, F64 Tdec);
I16 _stdcall _DMC_01_start_sa_heli_xy(U16 CardNo, U16* NodeID ,U16* SlotID, I32 Center_X, I32 Center_Y, I32 Depth, I32 Pitch, I16 Dir, I32 StrVel, I32 MaxVel, F64 Tacc, F64 Tdec);
I16 _stdcall _DMC_01_tv_move(U16 CardNo, U16 NodeID, U16 SlotID, I32 StrVel, I32 MaxVel, F64 Tacc, I16 Dir);
I16 _stdcall _DMC_01_sv_move(U16 CardNo, U16 NodeID, U16 SlotID, I32 StrVel, I32 MaxVel, F64 Tacc, I16 Dir);
I16 _stdcall _DMC_01_get_motion_error_code(U16 CardNo, U16 NodeID, U16 SlotID, I16* error_code);
I16 _stdcall _DMC_01_get_motion_error_cnt(U16 CardNo, U16 NodeID, U16 SlotID, I16* error_cnt);
I16 _stdcall _DMC_01_emg_stop(U16 CardNo, U16 NodeID, U16 SlotID);
I16 _stdcall _DMC_01_sd_stop(U16 CardNo, U16 NodeID, U16 SlotID, F64 Tdec);
I16 _stdcall _DMC_01_sd_abort(U16 CardNo, U16 NodeID, U16 SlotID, F64 Tdec);
I16 _stdcall _DMC_01_motion_done(U16 CardNo, U16 NodeID, U16 SlotID, U16 *MC_status);


I16 _stdcall _DMC_01_motion_status(U16 CardNo, U16 NodeID, U16 SlotID, U32 *MC_status);



I16 _stdcall _DMC_01_get_command(U16 CardNo, U16 NodeID, U16 SlotID, I32 *cmd);


I16 _stdcall _DMC_01_get_target_pos(U16 CardNo, U16 NodeID, U16 SlotID, I32 *pos);


I16 _stdcall _DMC_01_set_target_pos(U16 CardNo, U16 NodeID, U16 SlotID, I32 pos);//20150416
I16 _stdcall _DMC_01_get_current_speed(U16 CardNo, U16 NodeID, U16 SlotID, I32 *speed);


I16 _stdcall _DMC_01_set_position(U16 CardNo, U16 NodeID, U16 SlotID, I32 pos);
I16 _stdcall _DMC_01_set_command(U16 CardNo, U16 NodeID, U16 SlotID, I32 cmd);
I16 _stdcall _DMC_01_get_position(U16 CardNo, U16 NodeID,U16 SlotID, I32* pos);


I16 _stdcall _DMC_01_get_current_speed_rpm(U16 CardNo, U16 NodeID, U16 SlotID, I32 *rpm);


I16 _stdcall _DMC_01_get_buffer_length(U16 CardNo, U16 NodeID, U16 SlotID, U16 *bufferLength);


I16 _stdcall _DMC_01_set_gear(U16 CardNo, U16 NodeID, U16 SlotID, I16 numerator, I16 denominator, U16 Enable);
I16 _stdcall _DMC_01_set_gear2(U16 CardNo, U16 NodeID,U16 SlotID,F64 numerator,F64 denominator,U16 Enable);
I16 _stdcall _DMC_01_set_torque_mode(U16 CardNo, U16 NodeID, U16 SlotID, U32 slope);
I16 _stdcall _DMC_01_set_torque(U16 CardNo, U16 NodeID, U16 SlotID, I32 ratio);
I16 _stdcall _DMC_01_set_torque_stop(U16 CardNo, U16 NodeID, U16 SlotID, U16 stop);

I16 _stdcall _DMC_01_set_torque_velocity_limit(U16 CardNo, U16 NodeID, U16 SlotID, U32 velocity_limit);
I16 _stdcall _DMC_01_set_velocity_mode(U16 CardNo, U16 NodeID, U16 SlotID, F64 Tacc, F64 Tdec);
I16 _stdcall _DMC_01_set_velocity(U16 CardNo, U16 NodeID, U16 SlotID, I32 rpm);
I16 _stdcall _DMC_01_set_velocity_stop(U16 CardNo,U16 NodeID,U16 SlotID,U16 stop);

I16 _stdcall _DMC_01_set_velocity_torque_limit(U16 CardNo, U16 NodeID, U16 SlotID, U32 torque_limit);
I16 _stdcall _DMC_01_get_torque(U16 CardNo, U16 NodeID, U16 SlotID, I16 *torque);


I16 _stdcall _DMC_01_get_rpm(U16 CardNo, U16 NodeID, U16 SlotID, I16 *rpm);
I16 _stdcall _DMC_01_read_servo_parameter(U16 CardNo, U16 NodeID, U16 SlotID, U16 group, U16 idx, U32 *data);
I16 _stdcall _DMC_01_write_servo_parameter(U16 CardNo, U16 NodeID, U16 SlotID, U16 group, U16 idx, U32 data);
I16 _stdcall _DMC_01_set_ralm(U16 CardNo, U16 NodeID, U16 SlotID);
I16 _stdcall _DMC_01_set_ralm_servo_all(U16 CardNo);
I16 _stdcall _DMC_01_get_alm_code(U16 CardNo, U16 NodeID, U16 SlotID, U32 *alm_code);
I16 _stdcall _DMC_01_master_alm_code(U16 CardNo, U16* alm_code);
I16 _stdcall _DMC_01_slave_error(U16 CardNo, U16 NodeID, U16 SlotID, U16* alm_cnt);

I16 _stdcall _misc_app_get_circle_endpoint(I32 Start_X, I32 Start_Y ,I32 Center_X, I32 Center_Y, F64 Angle, I32* end_x, I32* end_y);
I16 _stdcall _misc_app_get_circle_center_point(I32 Start_X, I32 Start_Y, I32 End_x, I32 End_y, F64 Angle, I32 *Center_X, I32 *Center_Y);
I16 _stdcall _misc_set_record_debuging(U16 enable);
I16 _stdcall _misc_open_record_debuging_file(U16 CardNo, char *file_name, U16 open);
I16 _stdcall _misc_security(U32 OtherWord0, U32 OtherWord1, U32 SyntekWord0, U32 SyntekWord1, U32* Password0, U32* Password1, U32* Password2, U32* Password3);
I16 _stdcall _misc_slave_get_serialno(U16 CardNo, U16 NodeID, U16 SlotID, U32* SerialNO);
I16 _stdcall _misc_slave_check_verifykey(U16 CardNo, U16 NodeID, U16 SlotID, U32* VerifyKey, U16* Lock_state);
I16 _stdcall _misc_slave_check_userpassword(U16 CardNo, U16 NodeID, U16 SlotID, U32* Password_data, U16* Password_state);
I16 _stdcall _misc_slave_write_userpassword(U16 CardNo, U16 NodeID, U16 SlotID, U32* Password_data);
I16 _stdcall _misc_slave_write_verifykey(U16 CardNo, U16 NodeID, U16 SlotID, U32* VerifyKey);
I16 _stdcall _misc_slave_user_data_buffer_write(U16 CardNo, U16 NodeID, U16 SlotID, U16 Address, U32* Data);
I16 _stdcall _misc_slave_user_data_to_flash(U16 CardNo, U16 NodeID, U16 SlotID);
I16 _stdcall _misc_slave_user_data_buffer_read(U16 CardNo, U16 NodeID, U16 SlotID, U16 Address, U32* Data);
//I16 _stdcall _misc_app_get_spiral_endpoint(I32 start_X, I32 start_Y, I32 center_X, I32 center_Y, I32 spiral_interval, I32 spiral_angle, I32* end_x, I32* end_y);

I16 _stdcall _DMC_01_get_rm_input_value(U16 CardNo, U16 NodeID, U16 SlotID, U16 port, U16 *value);


I16 _stdcall _DMC_01_set_rm_input_filter(U16 CardNo, U16 NodeID, U16 SlotID, U16 port, U16 value);
I16 _stdcall _DMC_01_set_rm_input_filter_enable(U16 CardNo, U16 NodeID, U16 SlotID, U16 port, U16 enable);
I16 _stdcall _DMC_01_set_rm_output_value(U16 CardNo, U16 NodeID, U16 SlotID, U16 port, U16 value);
I16 _stdcall _DMC_01_get_rm_output_value(U16 CardNo, U16 NodeID, U16 SlotID, U16 port, U16* value);
I16 _stdcall _DMC_01_set_rm_output_value_error_handle(U16 CardNo, U16 NodeID, U16 SlotID, U16 port, U16 value);
I16 _stdcall _DMC_01_get_rm_output_value_error_handle(U16 CardNo, U16 NodeID, U16 SlotID, U16 port, U16* value);
I16 _stdcall _DMC_01_set_rm_output_active(U16 CardNo, U16 NodeID, U16 SlotID, U16 Enable);
I16 _stdcall _DMC_01_set_rm_mpg_axes_enable(U16 CardNo, U16 MasterNodeID, U16 MasterSlotID, U16* NodeID, U16* SlotID, U16 enable, U16 pulser_ratio, U32 *ratio, U32 *slop);
I16 _stdcall _DMC_01_set_rm_mpg_axes_enable2(U16 CardNo, U16 MasterNodeID, U16 MasterSlotID, U16* NodeID, U16* SlotID, U16 enable, U16 pulser_ratio, U32 *ratio, U32 *slop, U16 *denominator);
I16 _stdcall _DMC_01_set_rm_jog_axes_enable(U16 CardNo, U16 MasterNodeID, U16 MasterSlotID, U16* NodeID, U16* SlotID, U16 enable, U16 jog_mode, I32 *jog_speed, F64 *sec);
I16 _stdcall _DMC_01_command_buf_clear(U16 CardNo, U16 NodeID, U16 SlotID);
I16 _stdcall _DMC_01_buf_dwell(U16 CardNo, U16 NodeID,U16 SlotID, I32 dwell_cnt);
I16 _stdcall _DMC_01_sync_move(U16 CardNo);
I16 _stdcall _DMC_01_sync_move_config(U16 CardNo, U16 NodeID, U16 SlotID, I16 enable);
I16 _stdcall _DMC_01_set_soft_limit(U16 CardNo, U16 NodeID, U16 SlotID, I32 PLimit, I32 NLimit);
I16 _stdcall _DMC_01_enable_soft_limit(U16 CardNo, U16 NodeID, U16 SlotID, I16 Action);
I16 _stdcall _DMC_01_disable_soft_limit(U16 CardNo, U16 NodeID, U16 SlotID);
I16 _stdcall _DMC_01_get_soft_limit_status(U16 CardNo, U16 NodeID, U16 SlotID, U16* PLimit_sts, U16* NLimit_sts);
I16 _stdcall _DMC_01_get_slave_version(U16 CardNo, U16 NodeID, U16 SlotID, U16* version);
I16 _stdcall _DMC_01_get_slave_subversion(U16 CardNo, U16 NodeID, U16 SlotID, U16* SubVersion);
I16 _stdcall _DMC_01_set_monitor(U16 CardNo, U16 NodeID, U16 SlotID, U16 monitorw);
I16 _stdcall _DMC_01_get_monitor(U16 CardNo, U16 NodeID,U16 SlotID, U32 *value);
I16 _stdcall _DMC_01_get_servo_command(U16 CardNo, U16 NodeID, U16 SlotID, I32 *servo_cmd);
I16 _stdcall _DMC_01_get_servo_DI(U16 CardNo, U16 NodeID, U16 SlotID, U16 *servo_DI);
I16 _stdcall _DMC_01_get_servo_DO(U16 CardNo, U16 NodeID, U16 SlotID, U16 *servo_DO);
I16 _stdcall _DMC_01_set_trigger_buf_function(U16 CardNo, U16 NodeID, U16 SlotID, U16 enable);
I16 _stdcall _DMC_01_multi_axes_move(U16 CardNo,U16 AxisNum, U16* NodeID, U16* SlotID, I32 *DistArrary, I32 StrVel, I32 MaxVel, F64 Tacc, F64 Tdec, U16 m_curve, U16 m_r_a);  //m_curve1: T-Curve,2: S-Curve m_r_a0:rel 1:ab
I16 _stdcall _DMC_01_start_spiral_xy(U16 CardNo, U16* NodeID, U16* SlotID, I32 Center_X, I32 Center_Y, I32 spiral_interval, I32 spiral_angle, I32 StrVel, I32 MaxVel, F64 Tacc, F64 Tdec, U16 m_curve, U16 m_r_a);
I16 _stdcall _DMC_01_start_spiral2_xy(U16 CardNo, U16* NodeID, U16* SlotID, I32 center_x, I32 center_y, I32 end_x, I32 end_y, U16 dir, U16 circlenum, I32 StrVel, I32 MaxVel, F64 Tacc, F64 Tdec, U16 m_curve, U16 m_r_a);
I16 _stdcall _DMC_01_set_rm_04pi_ipulser_mode(U16 CardNo, U16 NodeID, U16 SlotID ,U16 mode);  //mode 0: AB phase 1:CW/CCW
I16 _stdcall _DMC_01_set_rm_04pi_opulser_mode(U16 CardNo, U16 NodeID, U16 SlotID, U16 mode);  //mode 0: AB phase 1:CW/CCW
I16 _stdcall _DMC_01_set_rm_04pi_svon_polarity(U16 CardNo, U16 NodeID, U16 SlotID, U16 polarity);  //polarity 0:Normal high  1:Normal low
I16 _stdcall _DMC_01_set_rm_04pi_DO2(U16 CardNo, U16 NodeID, U16 SlotID, U16 ON_OFF);

I16 _stdcall _DMC_01_set_rm_04pi_homing_ratio(U16 CardNo, U16 NodeID, U16 SlotID, U16 ratio);
I16 _stdcall _DMC_01_rm_04pi_get_MEL_polarity(U16 CardNo, U16 NodeID, U16 SlotID, U16 *data);
I16 _stdcall _DMC_01_rm_04pi_set_MEL_polarity(U16 CardNo, U16 NodeID, U16 SlotID, U16 inverse);
I16 _stdcall _DMC_01_rm_04pi_get_PEL_polarity(U16 CardNo, U16 NodeID, U16 SlotID, U16 *data);
I16 _stdcall _DMC_01_rm_04pi_set_PEL_polarity(U16 CardNo, U16 NodeID, U16 SlotID, U16 inverse);
I16 _stdcall _DMC_01_rm_04pi_md1_start_move(U16 CardNo, U16 NodeID, U16 SlotID, I32 Dist, I32 StrVel, I32 MaxVel, F64 Tacc, F64 Tdec, U16 m_curve, U16 m_r_a); //m_curve1: T-Curve,2: S-Curve m_r_a0:rel 1:ab
I16 _stdcall _DMC_01_rm_04pi_md1_v_move(U16 CardNo, U16 NodeID, U16 SlotID, I32 StrVel, I32 MaxVel, F64 Tacc, I16 dir, U16 m_curve);//Dir=1:----..Dir=0:++++
I16 _stdcall _DMC_01_rm_04pi_md1_start_line2(U16 CardNo, U16 NodeID, U16 *SlotID, I32 *Dist, I32 StrVel, I32 MaxVel, F64 Tacc, F64 Tdec, U16 m_curve, U16 m_r_a);
I16 _stdcall _DMC_01_rm_04pi_md1_start_arc(U16 CardNo, U16 NodeID, U16* SlotID, I32* Center, F64 Angle, I32 StrVel, I32 MaxVel, F64 Tacc, F64 Tdec, U16 m_curve, U16 m_r_a);
I16 _stdcall _DMC_01_rm_04pi_md1_start_line3(U16 CardNo, U16 NodeID, U16 *SlotID, I32 *Dist, I32 StrVel, I32 MaxVel, F64 Tacc, F64 Tdec, U16 m_curve, U16 m_r_a);
I16 _stdcall _DMC_01_rm_04pi_md1_start_line4(U16 CardNo, U16 NodeID, U16 *SlotID, I32 *Dist, I32 StrVel, I32 MaxVel, F64 Tacc, F64 Tdec, U16 m_curve, U16 m_r_a);
I16 _stdcall _DMC_01_rm_04pi_md1_start_arc2(U16 CardNo, U16 NodeID, U16* SlotID, I32* End, F64 Angle, I32 StrVel, I32 MaxVel, F64 Tacc, F64 Tdec, U16 m_curve, U16 m_r_a);
I16 _stdcall _DMC_01_rm_04pi_md1_start_arc3(U16 CardNo, U16 NodeID, U16* SlotID, I32* Center, I32* End, I16 dir, I32 StrVel, I32 MaxVel, F64 Tacc, F64 Tdec, U16 m_curve, U16 m_r_a);
I16 _stdcall _DMC_01_rm_04pi_md1_start_heli(U16 CardNo, U16 NodeID, U16* SlotID, I32* Center, I32 Depth, I32 Pitch, I16 dir, I32 StrVel, I32 MaxVel, F64 Tacc, F64 Tdec, U16 m_curve, U16 m_r_a);
I16 _stdcall _DMC_01_rm_04pi_md1_set_gear(U16 CardNo, U16 NodeID, U16 SlotID, I16 numerator, I16 denominator, U16 Enable);
I16 _stdcall _DMC_01_rm_04pi_md1_p_change(U16 CardNo, U16 NodeID, U16 SlotID, I32 NewPos);
I16 _stdcall _DMC_01_rm_04pi_md1_v_change(U16 CardNo, U16 NodeID,U16 SlotID, I32 NewSpeed, F64 sec);
I16 _stdcall _DMC_01_rm_04pi_md1_set_soft_limit(U16 CardNo, U16 NodeID, U16 SlotID, I32 PLimit, I32 NLimit, U16 Enable);
I16 _stdcall _DMC_01_rm_04pi_md1_get_soft_limit_status(U16 CardNo, U16 NodeID, U16 SlotID, U16* NLimit_status, U16* PLimit_status);
I16 _stdcall _DMC_01_rm_04pi_md1_set_sld(U16 CardNo, U16 NodeID, U16 SlotID, I16 enable, I16 sd_logic, I16 mode);
//I16 _stdcall _DMC_01_04pi_md1_get_mc_error_code(U16 CardNo, U16 NodeID, U16 SlotID, U16 *error_code);
I16 _stdcall _DMC_01_set_rm_04pi_ref_counter(U16 CardNo, U16 NodeID, U16 SlotID, U16 mode);  //mode 0: command 1:position
I16 _stdcall _DMC_01_rm_04PI_get_buffer(U16 CardNo, U16 NodeID, U16 SlotID, U16 *bufferLength);
I16 _stdcall _DMC_01_rm_04pi_md1_get_mc_error_code(U16 CardNo, U16 NodeID, U16 SlotID, U16 *error_code);
I16 _stdcall _DMC_01_link_interrupt(U16 CardNo, void ( __stdcall *callbackAddr)(U16 CardNo,U16 NodeID));
I16 _stdcall _DMC_01_set_int_factor(U16 CardNo, U16 NodeID, U16 int_factor);
I16 _stdcall _DMC_01_int_enable(U16 CardNo, U16 NodeID);
I16 _stdcall _DMC_01_get_int_count(U16 CardNo, U16 NodeID, U16 *count);
I16 _stdcall _DMC_01_int_disable(U16 CardNo, U16 NodeID);
I16 _stdcall _DMC_01_get_int_status(U16 CardNo, U16 NodeID, U16* event_int_status);
I16 _stdcall _DMC_01_read_security(U16 CardNo, U16 page, U16 *array);
I16 _stdcall _DMC_01_read_security_status(U16 CardNo, U16 *status);
I16 _stdcall _DMC_01_write_security_status(U16 CardNo, U16 status);//0:write protect,1:write enable
I16 _stdcall _DMC_01_write_security(U16 CardNo, U16 page, U16 *array);
I16 _stdcall _DMC_01_check_userpassword(U16 CardNo, U32* password_data, U16* password_state);
I16 _stdcall _DMC_01_write_userpassword(U16 CardNo, U32* password_data);
I16 _stdcall _DMC_01_check_verifykey(U16 CardNo, U32* VerifyKey, U16* state);
I16 _stdcall _DMC_01_write_verifykey(U16 CardNo, U32* verifykey);
I16 _stdcall _DMC_01_read_serialno(U16 CardNo, U32* SerialNo);
I16 _stdcall _DMC_01_rm_04da_set_output_value(U16 CardNo, U16 NodeID, U16 SlotID, U16 channelno, U16 value);
I16 _stdcall _DMC_01_rm_04da_get_return_code(U16 CardNo, U16 NodeID, U16 SlotID, U16 channelno, U16* returncode);
I16 _stdcall _DMC_01_rm_04da_set_output_range(U16 CardNo, U16 NodeID, U16 SlotID, U16 channelno, U16 range);
I16 _stdcall _DMC_01_rm_04da_set_output_enable(U16 CardNo, U16 NodeID, U16 SlotID, U16 channelno, U16 enable);
I16 _stdcall _DMC_01_rm_04da_set_output_overrange(U16 CardNo, U16 NodeID, U16 SlotID, U16 channelno, U16 on_off);
I16 _stdcall _DMC_01_rm_04da_set_output_error_clear(U16 CardNo, U16 NodeID, U16 SlotID, U16 channelno, U16 on_off);

I16 _stdcall _DMC_01_rm_04da_get_output_value(U16 CardNo, U16 NodeID, U16 SlotID, U16 channelno, U16 *value);
I16 _stdcall _DMC_01_rm_04da_set_output_error_handle(U16 CardNo, U16 NodeID, U16 SlotID, U16 channelno, U16 on_off);
I16 _stdcall _DMC_01_rm_04da_set_output_offset_value(U16 CardNo, U16 NodeID, U16 SlotID, U16 channelno, I16 value);
I16 _stdcall _DMC_01_rm_04da_get_output_offset_value(U16 CardNo, U16 NodeID, U16 SlotID, U16 channelno, I16* value);
I16 _stdcall _DMC_01_rm_04da_read_data(U16 CardNo, U16 NodeID, U16 SlotID, U16 channelno, U16* data);
I16 _stdcall _DMC_01_set_04ad_input_range(U16 CardNo, U16 NodeID, U16 SlotID, U16 channelno, U16 range);
I16 _stdcall _DMC_01_get_04ad_input_range(U16 CardNo, U16 NodeID, U16 SlotID, U16 channelno, U16 *range);
I16 _stdcall _DMC_01_set_04ad_conversion_time(U16 CardNo, U16 NodeID, U16 SlotID, U16 mode);
I16 _stdcall _DMC_01_get_04ad_conversion_time(U16 CardNo, U16 NodeID, U16 SlotID, U16* mode);
I16 _stdcall _DMC_01_get_04ad_data(U16 CardNo, U16 NodeID, U16 SlotID, U16 channelno, U16* value);

I16 _stdcall _DMC_01_get_04da_Output_range(U16 CardNo, U16 NodeID, U16 SlotID, U16 channelno, U16 *range);//20161003

//2018-09-04
I16 _stdcall _DMC_01_set_04ad_zero_scale(U16 CardNo, U16 NodeID, U16 SlotID, U16 channelno);

//2018-09-04
I16 _stdcall _DMC_01_get_04ad_zero_scale_status(U16 CardNo, U16 NodeID, U16 SlotID, U16 channelno, U16* status);

//2018-09-04
I16 _stdcall _DMC_01_set_04ad_full_scale(U16 CardNo, U16 NodeID, U16 SlotID, U16 channelno);

//2018-09-04
I16 _stdcall _DMC_01_get_04ad_full_scale_status(U16 CardNo, U16 NodeID, U16 SlotID, U16 channelno, U16* status);


I16 _stdcall _DMC_01_set_04ad_average_mode(U16 CardNo, U16 NodeID, U16 SlotID, U16 channelno, U16 mode);
I16 _stdcall _DMC_01_get_04ad_average_mode(U16 CardNo, U16 NodeID, U16 SlotID, U16 channelno, U16* mode);
I16 _stdcall _DMC_01_set_04ad_input_enable(U16 CardNo, U16 NodeID, U16 SlotID, U16 channelno, U16 ON_OFF);
I16 _stdcall _DMC_01_set_group(U16 CardNo, U16* NodeID, U16* SlotID, U16 NodeID_Num, U16 enable);
I16 _stdcall _DMC_01_speed_continue(U16 CardNo, U16 NodeID, U16 SlotID, U16 enable);
I16 _stdcall _DMC_01_speed_continue_mode(U16 CardNo, U16 NodeID, U16 SlotID, U16 mode);
I16 _stdcall _DMC_01_speed_continue_combine_ratio(U16 CardNo, U16 NodeID, U16 SlotID, U16 ratio);

I16 _stdcall _DMC_01_set_scurve_rate(U16 CardNo, U16 NodeID, U16 SlotID, U16 scurve_rate);
I16 _stdcall _DMC_01_enable_dda_mode(U16 CardNo, U16 enable);
I16 _stdcall _DMC_01_set_dda_data(U16 CardNo, I32* abs_pos);
I16 _stdcall _DMC_01_get_dda_cnt(U16 CardNo, U16* dda_cnt);
I16 _stdcall _DMC_01_feedrate_overwrite(U16 CardNo, U16 NodeID, U16 SlotID, U16 Mode, I32 New_Speed, F64 sec);
I16 _stdcall _DMC_01_start_v3_move(U16 CardNo, U16 NodeID, U16 SlotID, I32 Dist, I32 StrVel, I32 ConstVel, I32 EndVel, F64 Tphase1, F64 Tphase2, U16 m_curve, U16 m_r_a);
I16 _stdcall _DMC_01_start_v3_move_xy(U16 CardNo, U16* NodeID, U16* SlotID, I32 DisX, I32 DisY, I32 StrVel, I32 ConstVel, I32 EndVel, F64 Tphase1, F64 Tphase2, U16 m_curve, U16 m_r_a);
I16 _stdcall _DMC_01_start_v3_arc_xy(U16 CardNo, U16* NodeID, U16* SlotID, I32 Center_X, I32 Center_Y, F64 Angle, I32 StrVel, I32 ConstVel, I32 EndVel, F64 Tphase1, F64 Tphase2, U16 m_curve, U16 m_r_a);
I16 _stdcall _DMC_01_start_v3_arc2_xy(U16 CardNo, U16* NodeID, U16* SlotID, I32 End_X, I32 End_Y, F64 Angle, I32 StrVel, I32 ConstVel, I32 EndVel, F64 Tphase1, F64 Tphase2, U16 m_curve, U16 m_r_a);
I16 _stdcall _DMC_01_start_v3_arc3_xy(U16 CardNo, U16* NodeID, U16* SlotID, I32 Center_X, I32 Center_Y, I32 End_x, I32 End_y, I16 Dir, I32 StrVel, I32 ConstVel, I32 EndVel, F64 Tphase1, F64 Tphase2,U16 m_curve,U16 m_r_a);
I16 _stdcall _DMC_01_start_v3_move_xyz(U16 CardNo, U16* NodeID, U16* SlotID, I32 DisX, I32 DisY, I32 DisZ, I32 StrVel, I32 ConstVel, I32 EndVel, F64 Tphase1, F64 Tphase2, U16 m_curve, U16 m_r_a);
I16 _stdcall _DMC_01_start_v3_heli_xy(U16 CardNo, U16* NodeID, U16* SlotID, I32 Center_X, I32 Center_Y, I32 Depth, I32 Pitch, I16 Dir, I32 StrVel, I32 ConstVel, I32 EndVel, F64 Tphase1, F64 Tphase2, U16 m_curve,U16 m_r_a);
I16 _stdcall _DMC_01_start_v3_multi_axes(U16 CardNo, U16 AxisNum, U16* NodeID, U16* SlotID, I32 *DistArrary, I32 StrVel, I32 ConstVel, I32 EndVel, F64 Tphase1, F64 Tphase2, U16 m_curve, U16 m_r_a); //m_curve1: T-Curve,2: S-Curve m_r_a0:rel 1:abs
I16 _stdcall _DMC_01_start_v3_spiral_xy(U16 CardNo, U16* NodeID, U16* SlotID, I32 Center_X, I32 Center_Y, I32 spiral_interval, U32 spiral_angle, I32 StrVel, I32 ConstVel, I32 EndVel, F64 Tphase1, F64 Tphase2,U16 m_curve,U16 m_r_a);
I16 _stdcall _DMC_01_start_v3_spiral2_xy(U16 CardNo, U16* NodeID, U16* SlotID, I32 center_x, I32 center_y, I32 end_x, I32 end_y, U16 dir, U16 circlenum, I32 StrVel, I32 ConstVel, I32 EndVel, F64 Tphase1, F64 Tphase2,U16 m_curve,U16 m_r_a);
I16 _stdcall _DMC_01_get_fifo_cnt(U16 CardNo, U16* fifo_cnt);
I16 _stdcall _DMC_01_liner_speed_master(U16 CardNo, U16 NodeID, U16 SlotID, U16 Mode);
I16 _stdcall _DMC_01_enable_record_mode(U16 CardNo, U16 enable, U16 mode);

//2019-04-01
I16 _stdcall _DMC_01_get_enable_record_mode(U16 CardNo, U16* enable,U16* mode);

I16 _stdcall _DMC_01_get_record_data(U16 CardNo, U32* record_data);

I16 _stdcall _DMC_01_set_sd_time(U16 CardNo, U16 NodeID, U16 SlotID, F64 sd_dec);
I16 _stdcall _DMC_01_get_DLL_path(char *lpFilePath, U32 nSize, U32 *nLength);
I16 _stdcall _DMC_01_get_DLL_version(char *lpBuf, U32 nSize, U32 *nLength);
I16 _stdcall _DMC_01_get_DLL_path_Single(U16 CardNo, char *lpFilePath, U32 nSize, U32 *nLength);	
I16 _stdcall _DMC_01_get_DLL_version_Single(U16 CardNo, char *lpBuf, U32 nSize, U32 *nLength);	

I16 _stdcall _DMC_01_save_device_info(U16 CardNo, char *path);					
I16 _stdcall _DMC_01_compare_device_info(U16 CardNo, char *path, char *pathLog);	
I16 _stdcall _DMC_01_set_sld_stop(U16 CardNo, U16 NodeID, U16 SlotID, U16 enable);
I16 _stdcall _DMC_01_set_sld_mode(U16 CardNo, U16 NodeID, U16 SlotID, U16 mode);  //mode0:1 -> emg stop  //mode2: sd stop  //mode 3 velocity change to start velocit
I16 _stdcall _DMC_01_pdo_Rx_error(U16 CardNo, U16 NodeID, U16 SlotID, U32 *Rx_error1, U32 *Rx_error2, U16 set_get);  //set_get=0 read Rx_error1,Rx_error2 value,set_get=1 write Rx_error1,Rx_error2 value
I16 _stdcall _DMC_01_pdo_Tx_error(U16 CardNo, U16 NodeID, U16 SlotID, U32 *Tx_error, U16 set_get);
I16 _stdcall _DMC_01_pdo_Channel_error(U16 CardNo, U16 NodeID,U16 SlotID,U32 *ChannelA,U32 *ChannelB,U16 set_get);//2018-05-30


I16 _stdcall _DMC_01_start_v3_sphere_xyz(U16 CardNo, U16* NodeID, U16* SlotID, I32 pos1_x, I32 pos1_y, I32 pos1_z, I32 pos2_x, I32 pos2_y, I32 pos2_z, I32 StrVel, I32 MaxVel, I32 EndVel, F64 Tacc, F64 Tdec, U16 m_curve, U16 m_r_a);
I16 _stdcall _DMC_01_set_function_time(U16 CardNo, U32 ms1000);
I16 _stdcall _DMC_01_set_mc_fifo_mode(U16 CardNo, U16 mode);

I16 _stdcall _DMC_01_clear_dda_data(U16 CardNo);
I16 _stdcall _DMC_01_set_cam_pitch(U16 CardNo, U16 NodeID, U16 SlotID, I32 pitch);
I16 _stdcall _DMC_01_set_cam_org(U16 CardNo, U16 NodeID, U16 SlotID, I16 Dir, I32 orgpos);
I16 _stdcall _DMC_01_set_cam_enable(U16 CardNo, U16 NodeID, U16 SlotID, U16 on_off);
I16 _stdcall _DMC_01_set_cam_mode(U16 CardNo, U16 NodeID, U16 SlotID, U16 Mode);//Mode 0:Pitch_Bi Direction,Mode 1:Pitch one Direction 
I16 _stdcall _DMC_01_set_cam_table(U16 CardNo, U16 NodeID, U16 SlotID, I16 Dir, I32* table);
I16 _stdcall _DMC_01_set_cam_table2(U16 CardNo, U16 NodeID, U16 SlotID, I16 Dir, I32* table, I32 Num);
I16 _stdcall _DMC_01_set_dmc_mode(U16 CardNo, U16 NodeID, U16 SlotID);
I16 _stdcall _DMC_01_set_backlash(U16 CardNo, U16 NodeID, U16 SlotID, I16 enable);
I16 _stdcall _DMC_01_set_backlash_info(U16 CardNo, U16 NodeID, U16 SlotID, I16 backlash, U16 accstep, U16 contstep, U16 decstep);
I16 _stdcall _DMC_01_enable_electcam(U16 CardNo, U16 NodeID, U16 SlotID, U16 enable, U16 axisbit, U16 mode);



I16 _stdcall _DMC_01_get_gear(U16 CardNo, U16 NodeID, U16 SlotID, I16 *numerator, I16 *denominator, U16 *Enable);
I16 _stdcall _DMC_01_set_01ph_alm_polarity(U16 CardNo, U16 NodeID, U16 SlotID, U16 polarity);
I16 _stdcall _DMC_01_set_01ph_org_polarity(U16 CardNo, U16 NodeID, U16 SlotID, U16 polarity);


I16 _stdcall _DMC_01_set_compare_channel_position(U16 CardNo, U16 compare_channel, I32 position);
I16 _stdcall _DMC_01_get_compare_channel_position(U16 CardNo, U16 compare_channel, I32 *position);
I16 _stdcall _DMC_01_set_compare_ipulser_mode(U16 CardNo, U16 mode);
I16 _stdcall _DMC_01_set_compare_channel_direction(U16 CardNo, U16 compare_channel, U16 dir);
I16 _stdcall _DMC_01_set_compare_channel_trigger_time(U16 CardNo, U16 compare_channel, U32 time_us);
I16 _stdcall _DMC_01_set_compare_channel_one_shot(U16 CardNo, U16 compare_channel);
I16 _stdcall _DMC_01_set_compare_channel_source(U16 CardNo, U16 compare_channel,U16 source);
I16 _stdcall _DMC_01_channel0_position_cmp(U16 CardNo, I32 start, U16 dir, U16 interval, U32 trigger_cnt);
I16 _stdcall _DMC_01_channel0_position_cmp_by_gpio(U16 CardNo, U16 dir, U16 interval, I32 trigger_cnt);
I16 _stdcall _DMC_01_channel1_output_enable(U16 CardNo, U16 on_off);
I16 _stdcall _DMC_01_channel1_output_mode(U16 CardNo, U16 mode);
I16 _stdcall _DMC_01_channel1_get_io_status(U16 CardNo, U16* io_status);
I16 _stdcall _DMC_01_channel1_set_gpio_out(U16 CardNo, U16 on_off);
I16 _stdcall _DMC_01_channel1_get_fifo_status(U16 CardNo, U16* fifo_status);
I16 _stdcall _DMC_01_channel1_get_fifo_counter(U16 CardNo, U16* fifo_cnt);
I16 _stdcall _DMC_01_channel1_position_compare_table(U16 CardNo, I32* pos_table, U32 table_size);
I16 _stdcall _DMC_01_channel1_position_compare_table_level(U16 CardNo, I32* pos_table, U32* level_table, U32 table_size);
I16 _stdcall _DMC_01_channel1_position_compare_table_cnt(U16 CardNo, U32* cnt);
I16 _stdcall _DMC_01_set_compare_channel_polarity(U16 CardNo, U16 inverse); //0:Normal  1:Inverse
I16 _stdcall _DMC_01_channel1_position_re_compare_table(U16 CardNo);
I16 _stdcall _DMC_01_channel1_position_re_compare_table_level(U16 CardNo);
I16 _stdcall _DMC_01_set_compare_channel_enable(U16 CardNo, U16 compare_channel,U16 enable);


I16 _stdcall _DMC_01_get_v_change(U16 CardNo, U16 NodeID, U16 SlotID,I32 *New_Speed);

//2013.10.23
I16 _stdcall _DMC_01_set_position_ref_source(U16 CardNo, U16 NodeID, U16 SlotID, I16 ref_source);
I16 _stdcall _DMC_01_get_position_ref_source(U16 CardNo, U16 NodeID, U16 SlotID, I16 *ref_source);
I16 _stdcall _DMC_01_set_virtual_command(U16 CardNo, U16 NodeID, U16 SlotID, I32 virtual_command);
I16 _stdcall _DMC_01_get_virtual_command(U16 CardNo, U16 NodeID, U16 SlotID, I32 *virtual_command);

//2013.11.07
I16 _stdcall _DMC_01_set_virtual_position(U16 CardNo, U16 NodeID, U16 SlotID, I32 virtual_Position);
I16 _stdcall _DMC_01_disable_virtual_pos(U16 CardNo, U16 NodeID, U16 SlotID, U16 on_off);
I16 _stdcall _DMC_01_Set_Stepping_Move_rate(U16 CardNo, U16 NodeID, U16 SlotID, U8 MoveRatio);
//04-PI mode1: Speed will reduce cw/ccw Max Speed 200k/mratio,AB phase 500k/mratio,MoveRatio = 1~255


//2013.11.14
I16 _stdcall _DMC_01_set_pdo_mode(U16 CardNo, U16 NodeID,U16 SlotID,U16 Enable);

//2013.11.27
I16 _stdcall _DMC_01_set_feedrate_overwrite_rate(U16 CardNo, U16 NodeID, U16 SlotID, F64 feedrate);  


//20140120


//20140127
I16 _stdcall _DMC_01_MRAM_read_word(U32 offset, U16 *word_value);		//(HM1 MP1)_DMC_01_open 即可使用
I16 _stdcall _DMC_01_MRAM_write_word(U32 offset, U16 word_value);		//offset = 0~FFFF
I16 _stdcall _DMC_01_MRAM_read_dword(U32 offset, U32 *dword_value);
I16 _stdcall _DMC_01_MRAM_write_dword(U32 offset, U32 dword_value);


I16 _stdcall _DMC_01_set_ecam_repeat(U16 CardNo, U16 NodeID,U16 SlotID,I32 start_pos,I32 end_pos,U16 enable);
I16 _stdcall _DMC_01_set_limit_auto_ralm(U16 CardNo,U16 enable);


I16 _stdcall _DMC_01_start_v3_msbrline_move(U16 CardNo,U16 AxisNum, U16* NodeID,U16* SlotID,U16 ArcNodeBit,I32* DistArray,I32* DistArray2,U16 Mode,F64 Parameter,F64 SpdRatio,F64 Angle1,F64 Angle2,I32 StrVel,I32 ConstVel,I32 EndVel,F64 Tphase1,F64 Tphase2,U16 m_curve,U16 m_r_a);

I16 _stdcall _DMC_01_set_01_ph_inposition(U16 CardNo, U16 NodeID,U16 SlotID ,U16 poswindow_time,U32 poswindow);
I16 _stdcall _DMC_01_get_01_ph_inposition(U16 CardNo, U16 NodeID,U16 SlotID ,U16 *poswindow_time,U32 *poswindow);

//20140418

//20140505

//20140512
I16 _stdcall _DMC_01_set_ref_counter(U16 CardNo, U16 NodeID,U16 SlotID ,U16 mode);  //mode 0: command 1:position 


//20140530
I16 _stdcall _DMC_01_multi_table_V3_move(U16 CardNo, U16 MotionNum, U16 NodeID, U16 SlotID, I32 *Dist,I32 StrVel, I32 *ConstVel, I32 EndVel , F64 *Tphase, F64 Tdec, U16 m_curve, U16 m_r_a);

//20140709
I16 _stdcall _DMC_01_get_record_cnt(U16 CardNo, U16* Record_Cnt);

//20141205
I16 _stdcall _DMC_01_get_watchdog_cnt(U16 CardNo, U32 *watchdog_cnt);
I16 _stdcall _DMC_01_set_watchdog_cnt(U16 CardNo, U32 watchdog_cnt);
I16 _stdcall _DMC_01_get_watchdog_value(U16 CardNo, U32 *watchdog_value);
I16 _stdcall _DMC_01_set_watchdog_value(U16 CardNo, U32 watchdog_value);

//20141215
U16 _stdcall  DMCSMBox_Check(char *fmt, ...);

//20150120
I16 _stdcall _DMC_01_set_rm_04pi_md2_feedback_mode(U16 CardNo, U16 NodeID,U16 SlotID ,U16 mode);  //mode 0:With feedback 1:Without feedback

//20150407
I16 _stdcall _DMC_01_set_rm_04pi_home_config_Tdec(U16 CardNo,U16 NodeID ,U16 SlotID ,U32 Tdec, U32 enable);
I16 _stdcall _DMC_01_set_rm_04pi_Home_counter_Delay_time(U16 CardNo, U16 NodeID,U16 SlotID ,U16 Delay_time);

//20150522
I16 _stdcall _DMC_01_get_rm_04pi_home_config_Tdec(U16 CardNo,U16 NodeID ,U16 SlotID ,U16* Tdec, U16* enable);

//20150507

I16 _stdcall _DMC_01_set_dio_output_DW(U16 CardNo,U32 On_Off);
I16 _stdcall _DMC_01_get_dio_output_DW(U16 CardNo,U32 *On_Off);
I16 _stdcall _DMC_01_get_dio_input_DW(U16 CardNo,U32 *On_Off);

//20160512
I16 _stdcall _DMC_01_set_dio_output_DW_error_handle(U16 CardNo,U16 value);
//20160518
I16 _stdcall _DMC_01_get_dio_output_DW_error_handle(U16 CardNo,U16 *value);

//20150709


//20150710

//20150803
I16 _stdcall _DMC_01_start_v3_rline_xy(U16 CardNo, U16* NodeID, U16* SlotID, I32 Target_Pos1_X, I32 Target_Pos1_Y, I32 Target_Pos2_X, I32 Target_Pos2_Y, U16 Mode, F64 Parameter, I32 StrVel, I32 ConstVel, I32 EndVel, F64 Tacc, F64 Tdec, U16 Curve_Mode, U16 R_A_Mode);
I16 _stdcall _DMC_01_start_v3_rline_xyz(U16 CardNo, U16* NodeID, U16* SlotID, I32 Target_Pos1_X, I32 Target_Pos1_Y, I32 Target_Pos1_Z, I32 Target_Pos2_X, I32 Target_Pos2_Y, I32 Target_Pos2_Z, U16 Mode, F64 Parameter, I32 StrVel, I32 ConstVel, I32 EndVel, F64 Tacc, F64 Tdec, U16 Curve_Mode, U16 R_A_Mode);


//2015/1014 B02
I16 _stdcall _DMC_B02_qep_set_mode(U16 nCardNo, U8 nQepIndex, U8 nMode);
I16 _stdcall _DMC_B02_qep_set_inverse(U16 nCardNo, U8 nQepIndex, U8 bEnable);
I16 _stdcall _DMC_B02_qep_get_reload_counter(U16 nCardNo, U8 nQepIndex, I32* nCounter);
I16 _stdcall _DMC_B02_qep_set_reload_counter(U16 nCardNo, U8 nQepIndex, I32 nCounter);
I16 _stdcall _DMC_B02_qep_get_counter(U16 nCardNo, U8 nQepIndex, I32* nCounter);

// nStatus:bit# -> Pin: 0->9   nstatus:0->關閉 /1->開啟
I16 _stdcall _DMC_B02_gpio_software_control_status(U16 CardNo, U8 nPin, U8* nOnOff);
// nSetting:bit# -> Pin#: 0->9  nOnOff:0->關閉 /1->開啟
I16 _stdcall _DMC_B02_gpio_software_control_setting(U16 CardNo,U8 nPin, U8 nOnOff);

I16 _stdcall _DMC_B02_ipcmp_initial(U16 nCardNo, U8 nIpcmpIndex, U8 nQepIndex, U8 nGpioPin, U8 bInverse);
I16 _stdcall _DMC_B02_ipcmp_oneshot_time(U16 nCardNo, U8 nIpcmpIndex, U16 nPulseWidth);
I16 _stdcall _DMC_B02_ipcmp_software_trigger(U16 nCardNo, U8 nIpcmpIndex);
I16 _stdcall _DMC_B02_ipcmp_compare_position(U16 nCardNo, U8 nIpcmpIndex, I32 nStartPosition, U16 nInterval, U32 nCount, U8 nDir);
I16 _stdcall _DMC_B02_ipcmp_compare_trigger_count(U16 nCardNo, U8 nIpcmpIndex, U32* nCount);
I16 _stdcall _DMC_B02_ipcmp_compare_trigger_count_clear(U16 nCardNo, U8 nIpcmpIndex);

I16 _stdcall _DMC_B02_tpcmp_initial(U16 nCardNo, U8 nFifoIndex, U8 nQepIndex, U8 nGpioPin, U8 bInverse, U8 bInterrupt);
I16 _stdcall _DMC_B02_tpcmp_oneshot_time(U16 nCardNo, U8 nFifoIndex, U16 nPulseWidth);
I16 _stdcall _DMC_B02_tpcmp_software_trigger(U16 nCardNo, U8 nFifoIndex);
I16 _stdcall _DMC_B02_tpcmp_software_trigger_level(U16 nDeviceNo, U8 nFifoIndex, U8 bActive);
I16 _stdcall _DMC_B02_tpcmp_compare_position_table_reset(U16 nCardNo, U8 nFifoIndex);
I16 _stdcall _DMC_B02_tpcmp_compare_position_table(U16 nCardNo, U8 nFifoIndex, I32 nPositionTable[], U32 nTableSize);
I16 _stdcall _DMC_B02_tpcmp_compare_position_table_level(U16 nCardNo, U8 nFifoIndex, I32 nPositionTable[], U8 nLevelTable[], U32 nTableSize);
I16 _stdcall _DMC_B02_tpcmp_compare_trigger_count(U16 nCardNo, U8 nFifoIndex, U32* nCount);
I16 _stdcall _DMC_B02_tpcmp_compare_trigger_count_clear(U16 nCardNo, U8 nFifoIndex);

I16 _stdcall _DMC_B02_ext_io_get_input_value(U16 nCardNo, U8* nState);
I16 _stdcall _DMC_B02_ext_io_get_output_value(U16 nCardNo, U8* nState);
I16 _stdcall _DMC_B02_ext_io_set_output_value(U16 nCardNo, U8 nState);



//2015/11/06
//======LED=======
I16 _stdcall _DMC_01_Get_LED_Signal(U16 CardNo, U16 LedNo, U16 *OnOff);
I16 _stdcall _DMC_01_Set_LED_Signal(U16 CardNo, U16 LedNo, U16 OnOff);
//======GPIO=======MP1
I16 _stdcall _DMC_01_GPIO_Set_Type(U16 CardNo, U16 PortNo, U16 Type); //Type 0->RS422 1->RS485
I16 _stdcall _DMC_01_Get_GPIO_Input_Value(U16 CardNo, U16 *Value);
I16 _stdcall _DMC_01_Get_GPIO_Output_Value(U16 CardNo, U16 *Value);
I16 _stdcall _DMC_01_Set_GPIO_Output_Value(U16 CardNo, U16 Value);
I16 _stdcall _DMC_01_Set_GPIO_Output_error_handle(U16 CardNo, U16 Value);
I16 _stdcall _DMC_01_Get_GPIO_Output_error_handle(U16 CardNo, U16* Value);
I16 _stdcall _DMC_01_Get_BMC_fpga_version(U16 CardNo, U16* Value);//MP1-A12D 使用 //2018-3-19
I16 _stdcall _DMC_01_mp1_backlight_set(U16 CardNo, U16 nBrightness);//2019-05-28  背光
I16 _stdcall _DMC_01_mp1_backlight_get(U16 CardNo, U16* nBrightness);//2019-05-28  

//2015/11/19
I16 _stdcall _DMC_A02_mpg_get_poisition(U16 CardNo, I32* nValue);  //get 手輪的counter
I16 _stdcall _DMC_A02_mpg_fsm_get_lock_state(U16 CardNo, U8* nState);   // nState: [0]Unlock  [1]Lock  a02手輪的counter致能
I16 _stdcall _DMC_A02_mpg_get_io_state_enable(U16 CardNo, U8* nState);  // nState: [0]Disable  [1]Active 控制手輪pulse input 的閂鎖器
I16 _stdcall _DMC_A02_mpg_axis_get_io_state(U16 CardNo, U8* nState);// nState: [0]None  [1]Axis#0  [2]Axis#1  [3]Axis#2  [4]Axis#3  手輪軸選擇
I16 _stdcall _DMC_A02_mpg_axis_get_ratio_state(U16 CardNo, U8* nState);// nState: [0]None  [1]x1  [2]x10  [3]x100   手輪倍率選擇
I16 _stdcall _DMC_A02_set_mpg_axes_enable(U16 CardNo, U16* NodeID, U16* SlotID,U16 enable,U16 pulser_ratio,U32 *ratio,U32 *slop,U16 *denominator);
I16 _stdcall _DMC_A02_set_jog_axes_enable(U16 CardNo, U16* NodeID, U16* SlotID,U16 enable,U16 jog_mode,I32 *jog_speed,F64 *sec);  
//jog_mode0->6button 有效,1->手輪選擇軸,xbutton控制jog方向
I16 _stdcall _DMC_A02_get_jog_io_state(U16 CardNo, U16* nState);  
//Bit0: X+,Bit1: X-,Bit2: Y+,Bit3: Y-,Bit4: Z+,Bit5: Z-

//2017-10-02
I16 PASCAL _DMC_A02_set_mpg_axes_enable2(U16 CardNo, U16* NodeID, U16* SlotID,U16 enable,U16 pulser_ratio,U32 *ratio,U32 *slop,U16 *denominator);

//2018-09-13
I16 PASCAL _DMC_A02_set_mpg_axes_enable3(U16 CardNo, U16* NodeID, U16* SlotID, U16 enable, U16 pulser_ratio, U32 *ratio, U32 *slop, U32 *denominator);

//2017-10-17
I16 PASCAL _DMC_A02_get_mpg_axes_enable2(U16 CardNo, U16* Enable);

//2017-10-16
I16 PASCAL _DMC_A02_set_mpg_axes_extend(U16 CardNo,U16 AxisExtend);

//2017-10-17
I16 PASCAL _DMC_A02_get_mpg_axes_extend(U16 CardNo,U16* AxisNum);

//2017-10-17
I16 PASCAL _DMC_A02_mpg_axis_get_io_state2(U16 CardNo, U8* nState);
// nState: [0]None  [1]Axis#0  [2]Axis#1  [3]Axis#2  [4]Axis#3 ...[9]Axis#10  手輪軸選擇

//2017-10-17
I16 PASCAL _DMC_A02_mpg_axis_get_ratio_state2(U16 CardNo, U8* nState);
// nState: [0]None  [1]x1  [2]x10  [3]x100   手輪倍率選擇

//2017-11-16
I16 PASCAL _DMC_01_Set_MPG_AMF(U16 CardNo, I16 AMFNo, I16 AMFNum, U16 FilterNum, U16 Enable);

//2017-12-01 MP1-A12D 軟體手輪 B01
I16 PASCAL _DMC_Qep_set_mpg_axis_enable(U16 CardNo, U16 CompareChannel, U16 NodeID, U16 SlotID, U16 enable, U16 pulser_ratio, U32 ratio, U32 slop, U16 denominator);

//2017-12-01
I16 PASCAL _DMC_Qep_get_mpg_axis_enable(U16 CardNo, U16* CompareChannel, U16* NodeID, U16* SlotID, U16* enable, U16* pulser_ratio, U32* ratio, U32* slop, U16* denominator);

//2017-12-01
I16 PASCAL _DMC_Qep_get_mpg_axis_cnt(U16 CardNo, U16 compare_channel, I32* cnt);//B01 QEP

//2017-12-01
I16 PASCAL _DMC_Qep_set_mpg_clear(U16 CardNo ,U16 compare_channel);//B01 QEP clear




//20160113 B02 latch
I16 _stdcall _DMC_B02_ext_io_latch_initial(U16 nCardNo, U8 nExternalIoNo, U8 nSource, U8 nFilter);
I16 _stdcall _DMC_B02_ext_io_latch_function(U16 nCardNo, U8 nExternalIoNo, U8 bQep0, U8 bQep1, U8 bQep2, U8 bSw, U8 bH2L, U8 bL2H);
I16 _stdcall _DMC_B02_ext_io_latch_enable(U16 nCardNo, U8 nExternalIoNo, U8 bEnable);
I16 _stdcall _DMC_B02_latch_fifo_reset(U16 nCardNo, U8 bEnable);
I16 _stdcall _DMC_B02_latch_fifo_status(U16 nCardNo, U8* nStatus);
I16 _stdcall _DMC_B02_latch_fifo_size(U16 nCardNo, U8* nSize);
I16 _stdcall _DMC_B02_latch_fifo_get_qep_counter(U16 nCardNo, I32* nCounter, U8* nIoType, U8* nQepSource);


//20160121 (TableMotion) and (PVT) and (DDA Table2) and()
I16 _stdcall _DMC_01_set_axis_normalamf_enable(U16 CardNo, U16 NodeID, U16 SlotID, U16 filterTime, U16 enable);
I16 _stdcall _DMC_01_set_normalamf_enable(U16 CardNo, U16 afteramf_Num, U16 enable);

I16 _stdcall _DMC_01_start_tablemotion(U16 CardNo, U16 *NodeID, U16 *SlotID,I16 TableNo, I32 *PositionData,I32 DataSize,I16 AxisNum, I32 MaxVel, F64 Tacc_Tdec, U16 AMFNum, U16 cycle,U32 *Motion_No, I32 *IOCtl);
I16 _stdcall _DMC_01_start_tablemotion_buffer(U16 CardNo, U16 *NodeID, U16 *SlotID,I16 TableNo, I32 *PositionData,I32 DataSize,I16 AxisNum, I32 MaxVel, F64 Tacc_Tdec,U16 Single_Step_Enable, U32 *Motion_No, U16 AMFNum, I32 *IOCtl);

//2017-01-05
I16 _stdcall _DMC_01_start_tablemotion2(U16 CardNo, U16 *NodeID, U16 *SlotID,I16 TableNo, I32 *PositionData,I32 *MaxVelocity,I32 DataSize,I16 AxisNum, F64 Tacc_Tdec, U16 AMFNum, U16 cycle,U32 *Motion_No, I32 *IOCtl);
//2017-01-05
I16 _stdcall _DMC_01_start_tablemotion_buffer2(U16 CardNo, U16 *NodeID, U16 *SlotID,I16 TableNo, I32 *PositionData,I32 *MaxVelocity,I32 DataSize,I16 AxisNum, F64 Tacc_Tdec,U16 Single_Step_Enable, U32 *Motion_No, U16 AMFNum, I32 *IOCtl);

//2017-06-01
I16 _stdcall _DMC_01_start_tablemotion3(U16 CardNo, U16 *NodeID, U16 *SlotID,I16 TableNo, I32 *PositionData, I32 *Ref_Absolute_Pos,I32 *MaxVelocity,I32 DataSize,I16 AxisNum, F64 Tacc_Tdec, U16 AMFNum, U16 cycle,U32 *ArcBit, U32 *Motion_No, F64* Delay_CycleCount, U16 Abs_Mode,I32 *IOCtl);//2017-06-01

//2017-06-05
I16 _stdcall _DMC_01_start_tablemotion_buffer3(U16 CardNo, U16 *NodeID, U16 *SlotID,I16 TableNo, I32 *PositionData, I32 *Ref_Absolute_Pos,I32 *MaxVelocity,I32 DataSize,I16 AxisNum, F64 Tacc_Tdec, U16 Single_Step_Enable, U32 *ArcBit, U32 *Motion_No, F64* Delay_CycleCount,U16 AMFNum, U16 Abs_Mode,I32 *IOCtl);//2017-06-05 I32* Ref_Absolute_Pos, U32 *ArcBit, U16 Abs_Mode


I16 _stdcall _DMC_01_start_tablemotion_cyclemode(U16 CardNo,I16 TableNo);
I16 _stdcall _DMC_01_get_tablemotion_length(U16 CardNo,I16 TableNo,I32 *cnt);
I16 _stdcall _DMC_01_get_tablemotion_cycle(U16 CardNo,I16 TableNo,I32 *cycle);
I16 _stdcall _DMC_01_tablemotion_feedrate_overwrite(U16 CardNo,I16 TableNo, I32 ratio,F64 sec); 
I16 _stdcall _DMC_01_tablemotion_feedhold(U16 CardNo,I16 TableNo,  U16 On_Off,F64 sec);
I16 _stdcall _DMC_01_get_tablemotion_feedrate(U16 CardNo,I16 TableNo,I16 *feedrate);

I16 _stdcall _DMC_01_set_tablemotion_blending_ratio(U16 CardNo,I16 TableNo,  U32 Ratio);
//20160607
I16 _stdcall _DMC_01_get_tablemotion_current_speed(U16 CardNo,I16 TableNo, I32 *CurrentSpeed);

I16 _stdcall _DMC_01_set_dmc_cycle_int_count(U16 CardNo,U16 count);

I16 _stdcall _DMC_01_start_tablemotion_profile_planning(U16 CardNo, U16 *NodeID, U16 *SlotID,I16 TableNo, I32 *AccDec, I32 *PositionData,I32 DataSize,I16 AxisNum, I32 *MaxVel, F64 InitialVel_Ratio, I32 *IOCtl,U32 *Motion_No);//2016-10-25 F64 InitialVel_Ratio 2017-01-17 U32 *Motion_No
I16 _stdcall _DMC_01_start_tablemotion_profile_planning_para(U16 CardNo,I16 TableNo,I32 NanoSmoothDecectionLength,I32 RefTurnOnSpd ,I16 CurveDecectionFlag, I32 CurveDecectionLength, F64 CurveDecectionAngle, I32 ArcRefSpeed, I32 ArcRefRadius);

//2017-06-07
I16 _stdcall _DMC_01_start_tablemotion_profile_planning2(U16 CardNo, U16 *NodeID, U16 *SlotID,I16 TableNo, I32 *AccDec, I32 *PositionData, I32 *Ref_Absolute_Pos, I32 DataSize,I16 AxisNum, I32 *MaxVel, F64 InitialVel_Ratio, I32 *IOCtl, U32 *ArcBit, U32 *Motion_No, F64 *Delay_CycleCount, U16 Abs_Mode);//2017-06-07  I32 *Ref_Absolute_Pos , U32 *ArcBit, U16 Abs_Mode

//2018-08-31
I16 _stdcall _DMC_01_start_tableMotion_profileMode_data_flying_photography(U16 CardNo, I16 TableNo, I32 *PositionData, I32 DataSize, U16 *AxisArray, U16 *SlotArray, I32 *MaxVel, I32 *AccDecLimit, I32 Remain_Dist, I32 Stage2_Velocity, F64 InitialVel_Ratio, I32 *IOControl);

//2018-09-13
I16 _stdcall _DMC_01_start_tableMotion_profileMode_data_flying_position(U16 CardNo, I16 TableNo, I32* DataSize , I32* PositionData);




I16 _stdcall _DMC_01_start_tablemotion_profilemode(U16 CardNo,I16 TableNo);

I16 _stdcall _DMC_01_set_tablemotion_ioctl_mapping(U16 CardNo,I16 TableNo,U16 ionum ,U16 NodeID, U16 SlotID,U16 iobit);
//20160421
I16 _stdcall _DMC_01_Start_PVTComplete(U16 CardNo, U16 NodeID, U16 SlotID, F64 *Position, F64 *Time, F64 Str_Vel, F64 End_Vel, I32 MotionCnt,U16 m_r_a);
I16 _stdcall _DMC_01_Start_PVT(U16 CardNo, U16 NodeID, U16 SlotID,F64 *Position,F64 *Time, F64 *Velocity,I32 MotionCnt,U16 m_r_a);
I16 _stdcall _DMC_01_get_PVT_cnt(U16 CardNo, U16 NodeID, U16 SlotID,U32 *count);

//
I16 _stdcall _DMC_01_enable_dda_mode_group(U16 CardNo,U16 GroupNo, U16 enable);    
I16 _stdcall _DMC_01_set_dda_data_group(U16 CardNo,U16 GroupNo, U32* abs_pos);   
I16 _stdcall _DMC_01_get_dda_cnt_group(U16 CardNo,U16 GroupNo, U16* dda_cnt);    
I16 _stdcall _DMC_01_clear_dda_data_group(U16 CardNo,U16 GroupNo);

//20160205 DMC模式扭矩回home
I16 _stdcall _DMC_01_set_home_config_by_torque_limit(U16 CardNo,U16 NodeID,U16 SlotID ,U16 Mode,I32 offset,U16 lowSpeed,U16 highSpeed,F64 acc,U16 torque_ratio,U16 qualified_ms,U16 max_torque_ratio);

//20160318
I16 _stdcall _DMC_01_start_v3_heli_multi_axes_move(U16 CardNo, U16 AxisNum,U16* NodeID,U16* SlotID, I32 Center_X, I32 Center_Y,I32 *Dist, I32 Depth, I32 Pitch, I16 Dir, I32 StrVel, I32 ConstVel, I32 EndVel, F64 Tphase1, F64 Tphase2,U16 m_curve,U16 m_r_a);

//20160401(single bit)
I16 _stdcall _DMC_01_get_rm_input_single_value(U16 CardNo, U16 NodeID, U16 SlotID, U16 port, U16 bitno,U16 *value);
I16 _stdcall _DMC_01_get_rm_output_single_value(U16 CardNo, U16 NodeID, U16 SlotID, U16 port, U16 bitno, U16 *value);
I16 _stdcall _DMC_01_set_rm_output_single_value(U16 CardNo, U16 NodeID, U16 SlotID, U16 port, U16 bitno,U16 value);

//20160406
I16 _stdcall _DMC_01_set_dio_single_output(U16 CardNo, U16 bitno, U16 On_Off);
I16 _stdcall _DMC_01_get_dio_single_output(U16 CardNo, U16 bitno, U16 *On_Off);
I16 _stdcall _DMC_01_get_dio_single_input(U16 CardNo, U16 bitno, U16 *On_Off);


I16 _stdcall _DMC_01_set_dio_single_output_DW(U16 CardNo, U16 bitno, U32 On_Off);
I16 _stdcall _DMC_01_get_dio_single_output_DW(U16 CardNo, U16 bitno, U32 *On_Off);
I16 _stdcall _DMC_01_get_dio_single_input_DW(U16 CardNo, U16 bitno, U32 *On_Off);

//20160503 MP1 Security
I16 _stdcall _DMC_01_Security_Check_Verifykey(U16 CardNo, U32 VerifyKey[8]);
I16 _stdcall _DMC_01_Security_Get_Check_Verifykey_State(U16 CardNo, U16 *State);
I16 _stdcall _DMC_01_Security_Write_Verifykey(U16 CardNo, U32 VerifyKey[8]);
I16 _stdcall _DMC_01_Security_Get_Write_Verifykey_State(U16 CardNo, U16 *State);

I16 _stdcall _DMC_01_Security_Check_UserPassword(U16 CardNo, U32 Password[8]);
I16 _stdcall _DMC_01_Security_Get_Check_UserPassword_State(U16 CardNo, U16 *State);
I16 _stdcall _DMC_01_Security_Write_UserPassword(U16 CardNo, U32 Password[8]);
I16 _stdcall _DMC_01_Security_Get_Write_UserPassword_State(U16 CardNo, U16 *State);


//20160920
I16 _stdcall _DMC_01_Set_PID_Parameters(U16 CardNo,I16 PIDNo, F64 Proportional_Gain, F64 Integrat_Gain, F64 Dervative_Gain, F64 IntegratMax, F64 IntegratMin, F64 Command_Max, F64 Command_Min, F64 Feedback_Max, F64 Feedback_Min,I32 cycleTime);//20161014 add ,I32 cycleTime
I16 _stdcall _DMC_01_PID_Set_Source_Target_Info(U16 CardNo, U16 PIDNo, U16 OutputNodeNo, U16 OutputSlotNo, U16 OutputChannelNo ,U16 FeedbackNodeNo, U16 FeedbackSlotNo, U16 FeedbackChannelNo, U16 Enable);

//20160923
I16 _stdcall _DMC_01_PID_Set_DA_Vaule(U16 CardNo, U16 PIDNo ,F64 DA_Value);

//2016-11-15 for M-R
I16 _stdcall _DMC_01_set_pdo_Wdata(U16 CardNo, U16 NodeID, U16 slot, U16 Value0, U16 Value1, U16 Value2, U16 Value3);

//2016-11-15 for M-R
I16 _stdcall _DMC_01_get_pdo_Wdata(U16 CardNo, U16 NodeID, U16 slot, U16* Value0, U16* Value1, U16* Value2, U16* Value3);

//2016-11-15 for M-R Dword
I16 _stdcall _DMC_01_set_pdo_DWdata(U16 CardNo, U16 NodeID, U16 slot, U32 Value0, U32 Value1);

//2016-11-15 for M-R Dword
I16 _stdcall _DMC_01_get_pdo_DWdata(U16 CardNo, U16 NodeID, U16 slot, U32* Value0, U32* Value1);

//2016-11-22 
I16 _stdcall _DMC_01_start_multiarc(U16 CardNo,  U16 AxesNum, U16* NodeID, U16* SlotID, U16 ArcBit, U16 HelixBit, U16 ArcMode, I32 *CenterPoint, I32 *EndPoint, F64 Angle, I32 StrVel, I32 ConstVel, I32 EndVel, F64 Tacc, F64 Tdec, U16 Curve_mode, U16 AbsMode);

//2016-12-06
I16 _stdcall _DMC_01_set_command_mapping(U16 CardNo, U16 NodeID, U16 SlotID);

//2017-01-17
I16 _stdcall _DMC_01_Execute_Single_Step(U16 CardNo,I16 TableNo);

//2017-01-17
I16 _stdcall _DMC_01_Get_TableMotion_Now_MotionNo(U16 CardNo,I16 TableNo, U32 *MotionNo);

//2017-01-20
I16 _stdcall _DMC_01_TableMotion_Single_Step(U16 CardNo,I16 TableNo, U16 Enable);

//2017-02-10
I16 _stdcall _DMC_01_set_dio_input_trigger_mode(U16 CardNo, U16 trigger_mode);
//2017-02-10
I16 _stdcall _DMC_01_set_dio_input_int_enable(U16 CardNo, U16 Enable);
//2017-02-24
I16 _stdcall _DMC_01_get_dio_input_int_counter(U16 CardNo, U16* counter); 
//2017-02-24
I16 _stdcall _DMC_01_set_dio_input_int_counter_clear(U16 CardNo); 
//2017-03-01
I16 _stdcall _DMC_01_get_dio_input_int_status(U16 CardNo, U16* status);


//2017-02-14
I16 _stdcall _DMC_01_set_dio_input_level_emg(U16 CardNo, U16 Enable);
//2017-02-17
I16 _stdcall _DMC_01_set_dio_input_trigger_level(U16 CardNo, U16 level_mode);
//2017-02-17
I16 _stdcall _DMC_01_set_dio_input_level_emg_clear(U16 CardNo);
//2017-02-20
I16 _stdcall _DMC_01_get_dio_input_level_emg_status(U16 CardNo, U16* status);

//2017-03-10
I16 _stdcall _DMC_01_buffer_correlation_master_slave(U16 CardNo,U16 Slave_Node_Num,U16 Master_NodeID,U16* Slave_NodeID,U16 Slave_SlotID,I16 Enable);
//2017-03-13
I16 _stdcall _DMC_01_buffer_correlation_status(U16 CardNo,U16* Master_NodeID,U16* correlation_NodeID,U16* correlation_enable);

// 2017-03-16
I16 _stdcall _DMC_01_get_pdo_data16(U16 CardNo, U16 NodeID, U16 SlotID, U16 Index, U16 *Value);
I16 _stdcall _DMC_01_get_pdo_data32(U16 CardNo, U16 NodeID, U16 SlotID, U16 Index, U32 *Value);

// 2017-03-30
I16 _stdcall _DMC_01_reference_pos_move_config(U16 CardNo, U16 MasterNodeID, U16 MasterSlotID,U16 SlaveNodeID, U16 SlaveSlotID, I32 ReferencePos, I16 Dir);
I16 _stdcall _DMC_01_sd_stop_and_feedhold(U16 CardNo, U16 NodeID, U16 SlotID, F64 Tdec, U16 Mode);

// 2017-04-05
I16 _stdcall _DMC_01_set_svon_mode_of_operation(U16 CardNo, U16 NodeID, U16 SlotID, U16 Mode);

//2017-04-06 //RD 內部使用 量DSP時間
I16 _stdcall _DMC_01_get_dsp_time(U16 CardNo, I32 *t1_buf_work,I32 *t2_buf_work, I32 *t1_interpolation,I32 *t2_interpolation, I32 *t1_cal_pos,I32 *t2_cal_pos);

//2017-04-06 //RD 內部使用 量DSP時間
I16 _stdcall _DMC_01_set_dsp_time(U16 CardNo);


//2017-06-13
I16 _stdcall _DMC_01_set_dio_single_output_DW_trigger_time(U16 CardNo, U32 bitno, F64 time_s, U16 Enable);

//2017-06-13
I16 _stdcall _DMC_01_set_dio_single_output_DW_one_shot(U16 CardNo);

//2017-06-13
I16 _stdcall _DMC_01_get_dio_single_output_DW_trigger_status(U16 CardNo, U16* bitno, F64* time_s, U16* trigger_flag, U16* Enable);

//2017-06-16
I16 _stdcall _DMC_01_set_dio_single_input_DW_trigger_mode(U16 CardNo, U16 DI_bitno, U16 DO_bitno, U16 DO_polarity, U16 trigger_mode, U16 Enable);

//2017-06-16
I16 _stdcall _DMC_01_get_dio_single_input_DW_trigger_mode(U16 CardNo, U16* DI_bitno, U16* DO_bitno, U16* DO_polarity, U16* trigger_mode, U16* Enable);

//2017-06-16
I16 _stdcall _DMC_01_get_dio_single_input_DW_trigger_flag(U16 CardNo, U16* DI_trigger_flag);

//2018-11-23
I16 _stdcall _DMC_01_set_dio_single_output_DW_trigger_cycle(U16 CardNo, U32 bitno, U16 On_time, U16 Off_time, U16 times, U16 trigger_mode);


//2018-11-23
I16 _stdcall _DMC_01_set_dio_single_output_DW_trigger_enable(U16 CardNo, U16 enable);


//2017-10-31
I16 _stdcall _DMC_01_get_fpga_version(U16 CardNo, U16 *ver);

//2017-11-24
I16 _stdcall _DMC_01_Start_Move_Spiral_Circle(U16 CardNo, U16* NodeID, U16* SlotID, I32 center_x, I32 center_y, I32 spiral_interval, U32 spiral_angle ,I32 StrVel, I32 MaxVel, I32 EndVel, F64 Tacc, F64 Tdec, I16 Curve_mode, I16 m_r_a);

//2017-11-24
I16 _stdcall _DMC_01_Start_Move_Spiral2_Circle(U16 CardNo, U16* NodeID, U16* SlotID, I32 center_x, I32 center_y, I32 end_x, I32 end_y, U16 dir, U16 circlenum, I32 StrVel, I32 MaxVel, I32 EndVel, F64 Tacc, F64 Tdec, I16 Curve_mode, I16 m_r_a);

//2017-12-08
I16 _stdcall _DMC_01_ROUNDING(U16 CardNo, U16 Enable);

//2017-12-15
I16 _stdcall _DMC_01_feedrate_overwrite_read(U16 CardNo, U16 NodeID, U16 SlotID,U16* Mode, I32* New_Speed, F64* sec);

//2017-12-27
I16 _stdcall _DMC_01_MotionBuf_Set_Crd_Parameters(U16 CardNo, U16 TableNo, U16 AxisNum, U16 *AxisArray, I32 SycMaxVel, I32 SycMaxAcc, U16 S_Curve_Time, U16 Max_IO_Advance_Time, U16 SetOriginFlag, I32 *OriginPos);

//2017-12-27
I16 _stdcall _DMC_01_MotionBuf_Get_Crd_Parameters(U16 CardNo, U16 TableNo, U16 *AxisNum, U16 *AxisArray, I32 *SycMaxVel, I32 *SycMaxAcc, U16 *S_Curve_Time, U16 *Max_IO_Advance_Time, U16 *SetOriginFlag, I32 *OriginPos);

//2017-12-27
I16 _stdcall _DMC_01_MotionBuf_Line_MultiAxis(U16 CardNo, U16 TableNo, I32 *TargetPosition, I32 SynTargetVel, I32 SynEndVel, I32 SynAcc, U16 AbsMode, U16 FifoNo);

//2017-12-27
I16 _stdcall _DMC_01_MotionBuf_Line_MultiAxis_G00(U16 CardNo, U16 TableNo, I32 *TargetPosition, I32 SynTargetVel, I32 SynAcc, U16 AbsMode, U16 FifoNo);

//2017-12-27
I16 _stdcall _DMC_01_MotionBuf_Arc_Radius(U16 CardNo, U16 TableNo, U16 *Arc_Axis, I32 *Arc_TargetPosition, I32 Radius, U16 CircleDir ,I32 SynTargetVel , I32 SynEndVel, I32 SynAcc, U16 AbsMode, U16 FifoNo);

//2017-12-27
I16 _stdcall _DMC_01_MotionBuf_Arc_CenterPos(U16 CardNo, U16 TableNo, U16 *Arc_Axis, I32 *TargetPosition, I32 *CenterPos, U16 CircleDir ,I32 SynTargetVel , I32 SynEndVel, I32 SynAcc, U16 AbsMode, U16 FifoNo);

//2017-12-27
I16 _stdcall _DMC_01_MotionBuf_Set_LookAhead_Parameters(U16 CardNo, U16 TableNo, I32 RefSwerveSpd, U16 ArcSpdModify, I32 ArcRefSpeed, I32 ArcRefRadius,U16 FifoNo);

//2017-12-27
I16 _stdcall _DMC_01_MotionBuf_Start(U16 CardNo, U16 TableNo , U16 FifoNo);

//2017-12-27
I16 _stdcall _DMC_01_MotionBuf_Stop(U16 CardNo, U16 TableNo , U16 FifoNo, U16 Mode);

//2017-12-27
I16 _stdcall _DMC_01_MotionBuf_Get_Position(U16 CardNo, U16 TableNo ,I32 *Now_Position, I32 *Now_Position_org);

//2017-12-27
I16 _stdcall _DMC_01_MotionBuf_Get_Velocity(U16 CardNo, U16 TableNo ,I32 *CurrentSpeed);

//2017-12-27
I16 _stdcall _DMC_01_MotionBuf_Feedrate_Override(U16 CardNo, U16 TableNo ,F64 SynVelRatio);

//2017-12-27
I16 _stdcall _DMC_01_MotionBuf_Get_Motion_Status(U16 CardNo, U16 TableNo , U16 *Status,I32 *MD_BlockNum, U16 FifoNo);

//2017-12-27
I16 _stdcall _DMC_01_MotionBuf_Set_Stop_Deceleration(U16 CardNo, U16 TableNo ,I32 DecSmoothStop, I32 DecAbruptStop);

//2017-12-27
I16 _stdcall _DMC_01_MotionBuf_Get_Stop_Deceleration(U16 CardNo, U16 TableNo ,I32 *DecSmoothStop, I32 *DecAbruptStop);

//2017-12-27
I16 _stdcall _DMC_01_MotionBuf_SetUserSegNum(U16 CardNo, U16 TableNo ,I32 SegNum, U16 FifoNo);

//2017-12-27
I16 _stdcall _DMC_01_MotionBuf_GetUserSegNum(U16 CardNo, U16 TableNo ,I32 *SegNum, U16 FifoNo);

//2017-12-27
I16 _stdcall _DMC_01_MotionBuf_Clear_Buffer(U16 CardNo, U16 TableNo , U16 FifoNo);

//2017-12-27
I16 _stdcall _DMC_01_MotionBuf_Single_Step(U16 CardNo, U16 TableNo , U16 FifoNo, U16 Enable);

//2017-12-27
I16 _stdcall _DMC_01_MotionBuf_BufGear(U16 CardNo, U16 TableNo ,U16 GearAxisNo, I32 Distance, U16 FifoNo);

//2017-12-27
I16 _stdcall _DMC_01_MotionBuf_BufMove(U16 CardNo, U16 TableNo ,U16 AxisNo, I32 Distance, I32 TargetVel , I32 Acceleration, U16 AbsMode, U16 BufMove_Mode, U16 FifoNo);

//2017-12-27
I16 _stdcall _DMC_01_MotionBuf_IOControl(U16 CardNo, U16 TableNo , U16 IO_Control_Num , IO_Set* IO_Array, U16 FifoNo);

//2017-12-27
I16 _stdcall _DMC_01_MotionBuf_Advanced_IOControl(U16 CardNo, U16 TableNo , U16 IO_Control_Num , IO_Set* IO_Array, U16 Time, U16 Mode, U16 FifoNo);

//2017-12-27
I16 _stdcall _DMC_01_MotionBuf_Delay(U16 CardNo, U16 TableNo ,F64 DelayTime, U16 FifoNo);

//2017-12-27
I16 _stdcall _DMC_01_MotionBuf_Get_Remain_Buffer_Size(U16 CardNo, U16 TableNo ,I32 *RemainBufSize, U16 FifoNo);

//2017-12-27
I16 _stdcall _DMC_01_MotionBuf_SoftLimit_On(U16 CardNo, U16 TableNo, U16 CD_AxisNo, I16 LimitType, U16 Mode, U16 FifoNo);

//2017-12-27
I16 _stdcall _DMC_01_MotionBuf_SoftLimit_Off(U16 CardNo, U16 TableNo, U16 CD_AxisNo, I16 LimitType, U16 FifoNo);

//2018-03-01
I16 _stdcall _DMC_01_MotionBuf_Clear_Crd(U16 CardNo, U16 TableNo, U16 FifoNo);

//2018-03-27
I16 _stdcall _DMC_01_MotionBuf_Disable(U16 CardNo, U16 TableNo, U16 FifoNo);

//2018-05-07
I16 _stdcall _DMC_01_MotionBuf_Helix(U16 CardNo, U16 TableNo, U16 *Helix_Axis, I32 *CenterPos, I32 Depth, I32 Pitch, I16 HelixDir, I32 SynTargetVel, I32 SynEndVel, I32 SynAcc, U16 AbsMode, U16 FifoNo);

//2018-05-30
I16 _stdcall _DMC_01_MotionBuf_Line_MultiAxis2(U16 CardNo, U16 TableNo, U16 AxisNum, U16 *Line_Axis, I32 *TargetPosition, I32 SynTargetVel, I32 SynEndVel, I32 SynAcc, U16 AbsMode, U16 FifoNo);

//2018-05-30
I16 _stdcall _DMC_01_MotionBuf_Line_MultiAxis2_G00(U16 CardNo, U16 TableNo, U16 AxisNum, U16 *Line_Axis, I32 *TargetPosition, I32 SynTargetVel, I32 SynAcc, U16 AbsMode, U16 FifoNo);

//2018-06-04
I16 _stdcall _DMC_01_MotionBuf_Arc_MidPos(U16 CardNo, U16 TableNo, U16 *Arc_Axis, I32 *Arc_TargetPosition, I32 *Arc_MidTargetPosition, I32 SynTargetVel, I32 SynEndVel, I32 SynAcc, U16 AbsMode, U16 FifoNo);

//2018-06-04
I16 _stdcall _DMC_01_MotionBuf_MultiAxis_Arc1(U16 CardNo, U16 TableNo, U16 FollowAxisNum, U16 *Axis_Array, I32 *CenterPos, F64 Angle,U16 CircleDir, I32 *Follow_TargetPosition, I32 SynTargetVel, I32 SynEndVel, I32 SynAcc, U16 SpeedMode, U16 AbsMode, U16 FifoNo);

//2018-06-04
I16 _stdcall _DMC_01_MotionBuf_MultiAxis_Arc2(U16 CardNo, U16 TableNo, U16 FollowAxisNum, U16 *Axis_Array, I32 *Arc_TargetPosition, F64 Angle, U16 CircleDir, I32 *Follow_TargetPosition, I32 SynTargetVel, I32 SynEndVel, I32 SynAcc, U16 SpeedMode, U16 AbsMode, U16 FifoNo);

//2018-06-04
I16 _stdcall _DMC_01_MotionBuf_MultiAxis_Arc3(U16 CardNo, U16 TableNo, U16 FollowAxisNum, U16 *Axis_Array, I32 *Arc_TargetPosition, I32 *CenterPos, U16 CircleDir, I32 *Follow_TargetPosition, I32 SynTargetVel, I32 SynEndVel, I32 SynAcc, U16 SpeedMode, U16 AbsMode, U16 FifoNo);

//2018-06-04
I16 _stdcall _DMC_01_MotionBuf_MultiAxis_Arc4(U16 CardNo, U16 TableNo, U16 FollowAxisNum, U16 *Axis_Array, I32 *Arc_TargetPosition, I32 *Arc_MidPosition, I32 *Follow_TargetPosition, I32 SynTargetVel, I32 SynEndVel, I32 SynAcc, U16 SpeedMode, U16 AbsMode, U16 FifoNo);

//2018-07-10
I16 _stdcall _DMC_01_MotionBuf_Arc_follow(U16 CardNo, U16 TableNo, U16 AxesNum, U16 *AxisArray, U16 ArcMode, U16 *Arc_Axis_index, U16 master_axis_index, I32 *CenterPoint, I32 *EndPoint, F64 Angle, U16 Dir, I32 SynTargetVel, I32 SynEndVel, I32 SynAcc, U16 AbsMode, U16 FifoNo);

//2018-08-27
I16 _stdcall _DMC_01_MotionBuf_Set_G00_Check(U16 CardNo, U16 TableNo, U16 Check_Time, I32* Error_Range, U16 Enable);

//2018-08-28
I16 _stdcall _DMC_01_MotionBuf_Get_G00_Check(U16 CardNo, U16 TableNo, U16* Check_Time, I32* Error_Range, U16* Enable);

//2018-08-28
I16 _stdcall _DMC_01_MotionBuf_Get_G00_Check_Flag(U16 CardNo, U16 TableNo, U16* Check_G00_Flag);

//2018-08-29
I16 _stdcall _DMC_01_MotionBuf_Get_G00_Check_match(U16 CardNo, U16 TableNo, I32* feedback);


//2018-06-08 MP1 
I16 _stdcall _DMC_01_get_mp1_dio_input(U16 CardNo,U16 *On_Off);

//2018-06-08 MP1 
I16 _stdcall _DMC_01_get_mp1_dio_single_input(U16 CardNo, U16 bitno, U16 *On_Off);

//2018-06-01 MP1 弘亞衍生機種
I16 _stdcall _DMC_MP1_set_mpg_axis_enable(U16 CardNo, U16* NodeID, U16* SlotID, U16 enable, U16 pulser_ratio, U32* ratio, U32* slop, U32* denominator);

//2018-06-11 MP1 弘亞衍生機種
I16 _stdcall _DMC_MP1_get_mpg_axis_cnt(U16 CardNo, I32* cnt);//MP1 B01 QEP

//2018-06-11 MP1 弘亞衍生機種
I16 _stdcall _DMC_MP1_set_mpg_axis_clear(U16 CardNo);//MP1 B01 QEP clear

//2018-06-11 MP1 弘亞衍生機種
I16 _stdcall _DMC_MP1_get_mpg_axis_enable(U16 CardNo, U16* NodeID, U16* SlotID, U16* enable, U16* pulser_ratio, U32* ratio, U32* slop, U32* denominator);


//2018-07-17
I16 _stdcall _DMC_MP1_mpg_axis_get_io_state(U16 CardNo, U8* nState);

//2018-07-17
I16 _stdcall _DMC_MP1_mpg_axis_get_ratio_state(U16 CardNo, U8* nState);

//2018-07-04
I16 _stdcall _DMC_01_Start_Multi_Arc(U16 CardNo, U16 AxesNum, U16* AxisArray, U16* SlotID, I32* DistArray, U16 SpeedMode, U16 ArcMode, U16 *Axis_index, I32 *CenterPoint, I32 *EndPoint, F64 Angle, U16 Dir, I32 StrVel, I32 ConstVel, I32 EndVel, F64 Tacc, F64 Tdec, U16 Curve_mode, U16 AbsMode);


//2018-07-06
I16 _stdcall _DMC_01_Start_Arc_follow(U16 CardNo, U16 AxesNum, U16 *AxisArray,U16* SlotID, U16 ArcMode, U16 *Arc_Axis_index, U16 master_axis_index , I32 *CenterPoint, I32 *EndPoint, F64 Angle, U16 Dir, I32 StrVel, I32 ConstVel, I32 EndVel, F64 Tacc, F64 Tdec, U16 Curve_mode, U16 AbsMode);





//2D compare 2017-08-07-------------------------------------------------------
I16 _stdcall _DMC_B02_tpcmp_oneshot_time_2D(U16 nCardNo, U16 nPulseWidth);
I16 _stdcall _DMC_B02_tpcmp_initial_2D(U16 nCardNo, U8 nQepIndex_X, U8 nQepIndex_Y, U8 nGpioPin, U8 bInverse, U8 bInterrupt, U8 Dimension);//2017-08-04
I16 _stdcall _DMC_B02_tpcmp_software_trigger_2D(U16 nCardNo);
I16 _stdcall _DMC_B02_tpcmp_software_trigger_level_2D(U16 CardNo, U8 bActive);
I16 _stdcall _DMC_B02_tpcmp_compare_position_table_2D(U16 nCardNo,  I32 nPositionTable_X[], I32 nPositionTable_Y[], U32 nTableSize);	
I16 _stdcall _DMC_B02_tpcmp_compare_position_table_reset_2D(U16 nCardNo);
I16 _stdcall _DMC_B02_tpcmp_compare_position_table_level_2D(U16 nCardNo, I32 nPositionTable_X[], I32 nPositionTable_Y[], U8 nLevelTable[], U32 nTableSize);
I16 _stdcall _DMC_B02_tpcmp_compare_axis_dist_2D(U16 nCardNo, I32 nPositionTable_X, I32 nPositionTable_Y);
I16 _stdcall _DMC_B02_get_tpcmp_compare_axis_dist_2D(U16 nCardNo, I32* nPositionTable_X, I32* nPositionTable_Y);


//DSP Latch Data 2017-10-03
I16 _stdcall _DMC_B02_latch_fifo_get_qep_counter2(U16 nCardNo, I32* nCounter, U8* nIoType, U8* nQepSource, U32* nSize);//2017-10-02

I16 _stdcall _DMC_B02_latch_fifo_dsp_get_data_counter(U16 nCardNo, U32* nCounter);//2017-10-03

I16 _stdcall _DMC_B02_latch_fifo_dsp_data_counter_reset(U16 nCardNo);//2017-10-03

I16 _stdcall _DMC_B02_latch_fifo_dsp_data_clear(U16 nCardNo);//2017-10-03


//2018-01-22
I16 _stdcall _DMC_01_get_monitor_I32(U16 CardNo, U16 NodeID,U16 SlotID, I32 *value);





//----------------------------------------------------------------------------------特殊應用API

void _stdcall _DMC_01_get_cardtype_errorcode(U16 *returncode);
void _stdcall _DMC_01_clear_cardtype_errorcode(void);

I16 _stdcall _DMC_01_check_card_running(U16 CardNo, U16 *running);

I16 _stdcall _DMC_01_set_interrutp_buffer(U16 CardNo, U16 NodeID, U16 SlotID);

I16 _stdcall _DMC_01_set_torque_velocity_feed_forward(U16 CardNo, U16 NodeID, U16 SlotID, U32 velocity_feed_forward);

I16 _stdcall _DMC_01_set_velocity_torque_feed_forward(U16 CardNo,U16 NodeID, U16 SlotID, U32 torque_feed_forward);

I16 _stdcall _DMC_01_get_torque_multi_axes(U16 CardNo,U16 AxisNum,U16 *NodeID,U16 *SlotID,I16 *torque);//20160621 

I16 _stdcall _DMC_01_04pi_set_poweron(U16 CardNo, U16 NodeID, U16 SlotID, U16 ON_OFF);

I16 _stdcall _DMC_01_rm_04da_read_control_register(U16 CardNo, U16 NodeID, U16 SlotID, U16 channelno, U16* control_register_data);

I16 _stdcall _DMC_01_set_dec_acceleration(U16 CardNo, U16 NodeID, U16 SlotID, F64 pss);

I16 _stdcall _DMC_01_enable_switch_buffer(U16 CardNo, U16 enable);

I16 _stdcall _DMC_01_enable_axis_mode(U16 CardNo, U16 enable);

I16 _stdcall _DMC_01_set_cv_mode(U16 CardNo, U16 NodeID, U16 SlotID, U16 flag_const_v, U16 flag_dec_c);
I16 _stdcall _DMC_01_enable_ex_position(U16 CardNo, U16 NodeID, U16 SlotID, U16 enable);

I16 _stdcall _DMC_01_enable_always_monitorid(U16 CardNo, U16 enable);
I16 _stdcall _DMC_01_get_nrline_status(U16 CardNo, U16 NodeID, U16 SlotID, U16 *nrline_sts);

I16 _stdcall _DMC_01_get_rm_output_value_HPF(U16 CardNo, U16 NodeID, U16 SlotID, U16 port, U16 *value);
I16 _stdcall _DMC_01_set_rm_output_value_HPF(U16 CardNo, U16 NodeID, U16 SlotID, U16 port, U16 value);

I16 _stdcall _DMC_01_get_compare_channel_direction(U16 CardNo, U16 compare_channel, U16 *dir);//0:Normal  1:Inverse

I16 _stdcall _DMC_01_get_feedrate_overwrite(U16 CardNo, U16 NodeID, U16 SlotID,I32 *New_Speed);

I16 _stdcall _DMC_01_Get_Stepping_Move_rate(U16 CardNo, U16 NodeID, U16 SlotID, U8 *MoveRatio);


I16 _stdcall _DMC_01_set_mc_buffer(U16 CardNo,U16 status);   //buffer always enable 
I16 _stdcall _DMC_01_start_v3_multi_axes_arc(U16 CardNo,U16 AxisNum, U16* NodeID, U16* SlotID,I32 Center_X, I32 Center_Y, F64 Angle, I32 StrVel, I32 ConstVel, I32 EndVel, F64 Tphase1, F64 Tphase2,U16 m_curve,U16 m_r_a); //m_curve1: T-Curve,2: S-Curve m_r_a0:rel 1:abs;


//2013.12.31
I16 _stdcall _misc_app_get_ellipse_para(F64 x0,F64 y0,F64 x1,F64 y1,F64 x2,F64 y2,F64 *center_x,F64 *center_y,F64 *radius);

//20140120
I16 _stdcall _DMC_01_set_acc_dec_2_slop(U16 CardNo,U16 time_slop_enable);

I16 _stdcall _DMC_01_set_pr_mode(U16 CardNo,U16 NodeID, U16 SlotID);
I16 _stdcall _DMC_01_pdo_write_servo_parameter(U16 CardNo, U16 NodeID, U16 SlotID, U16 Group, U16 Index, U32 Data);

U8 _stdcall _DMC_01_LED_Switch(U8 LedNum,U8 Switch);

I16 _stdcall _DMC_01_Set_APICheck(U16 CardNo,U16 Mode);

I16 _stdcall _DMC_01_get_dsp_intext4cnt(U16 CardNo, U32 *tm0,U32 *tm1,U32 *tm2,U32 *tm3);
I16 _stdcall _DMC_01_pdo_check_servo_status(U16 CardNo, U16 NodeID, U16 SlotID, U16 *Status);
//20140418
I16 _stdcall _DMC_01_set_node_actmotion(U16 CardNo, U16 *NodeID, U16 num);
//20140505
I16 _stdcall _DMC_01_get_module_mode(U16 CardNo, U16 NodeID, U16 SlotID, U32* MC_Mode);

I16 _stdcall _DMC_01_set_slave_error_value(U16 CardNo,U16 times);
I16 _stdcall _DMC_01_set_adjoint_status(U16 CardNo, U32 adjoint_status);
I16 _stdcall _DMC_01_get_adjoint_status(U16 CardNo, U32 *adjoint_status);

//20150709
I16 _stdcall _DMC_01_start_prov_multi_axes_arc(U16 CardNo,U16 AxisNum, U16* NodeID, U16* SlotID,I32 Center_X, I32 Center_Y, F64 Angle, I32 StrVel, I32 ConstVel, I32 EndVel, F64 Tphase1, F64 Tphase2,U16 m_curve,U16 m_r_a);

//20150710
I16 _stdcall _DMC_01_get_last_error_node_no(U16 CardNo, U16* ErrorNode);

//2015/10/27
I16 _stdcall _DMC_01_set_digital_filter(U16 CardNo,U16 port,U16 value);  //value [0] 50 u (sec)	[1] 500 u (sec) [2] 1m (sec)	[3] 2m (sec)
I16 _stdcall _DMC_01_get_digital_filter(U16 CardNo,U16 port,U16 *value);  //value [0] 50 u (sec)	[1] 500 u (sec) [2] 1m (sec)	[3] 2m (sec)

I16 _stdcall _DMC_01_LED_Initial(U16 CardNo);

I16 _stdcall _DMC_A02_mpg_clear_poisition(U16 CardNo);//20160715


I16 _stdcall _DMC_B02_tpcmp_fifo_size(U16 nCardNo, U8 nFifoIndex, U32* nSize);
I16 _stdcall _DMC_B02_tpcmp_fifo_status(U16 nCardNo, U8 nFifoIndex, U8* nStatus);
I16 _stdcall _DMC_B02_tpcmp_compare_data_lock(U16 nCardNo, U8 nFifoIndex, U8* nLock);

//20160825
I16 _stdcall _DMC_01_get_dda_error_global(U16 CardNo, U32* error_global);


//2018-04-11
I16 _stdcall _DMC_01_set_rm_mpg_axes_enable3(U16 CardNo,U16 MasterNodeID,U16 MasterSlotID, U16* NodeID, U16* SlotID,U16 enable,U16 pulser_ratio,U32 *ratio,U32 *slop,U32 *denominator);

I16 _stdcall _DMC_01_get_model_type(U16 CardNo, U16* nModelType);//2018-05-15


//2019-03-28
I16 _stdcall _DMC_01_start_g31(U16 CardNo, U16 u16_Group, U16 AxisNum, U16* NodeID, U16* SlotID, I32 *DistArrary, I32 StrVel, I32 ConstVel, I32 EndVel, F64 Tphase1, F64 Tphase2,U16 m_curve,U16 m_r_a);


//2019-04-09
I16 _stdcall _DMC_01_G31_Set_Info(U16 CardNo, U16 u16_Group, U16 NodeID, U16 SlotID, U16 u16_DiPolarity, U16 u16_DiBitNo, F64 f64_McDec, U16 enable);
 
//2019-04-09
I16 _stdcall _DMC_01_G31_Get_Fbk(U16 CardNo, U16 u16_Group, U16 *pu16_State, I32 *pi32_Fbk, U16* enable);


//2019-05-24
I16 _stdcall _DMC_01_feedrate_overwrite2(U16 CardNo, U16 NodeID, U16 SlotID, U16 Mode, I32 New_Speed);


//2019-05-24
//========DI Motion Home========= 
I16 _stdcall _DMC_01_Remote_Limit_Config(U16 CardNo, U16 LimitNo, U16 AxisNodeID, U16 AxisSlotID, U16 DINodeID, U16 DISlotID, U16 PELBitNo, U16 NELBitNo, U16 ORGBitNo);

I16 _stdcall _DMC_01_Remote_Limit_Edge_Trigger_Level(U16 CardNo, U16 LimitNo, U16 PositiveLimt, U16 NegativeLimit, U16 HomeSensor);

I16 _stdcall _DMC_01_Remote_Limit_Enable(U16 CardNo, U16 LimitNo, U16 Enable);

//2019-07-09
I16 _stdcall _DMC_01_Remote_Limit_Status(U16 CardNo, U16 LimitNo, U16* PEL_Trigger_sts, U16* NEL_Trigger_sts, U16* ORG_Trigger_sts, I16* Motion_Dir, U16* Limit_Status);

I16 _stdcall _DMC_01_Home_Axis_Config(U16 CardNo, U16 HomeNo, U16 NodeID, U16 SlotID, U16 Mode, I32 Offset, U32 FirstVel, U32 SecondVel, F64 Tacc, U16 Dir, I32 Shift);

I16 _stdcall _DMC_01_Home_Move(U16 CardNo, U16 HomeNo, U16 u16_LimitNo, U16 Enable);

I16 _stdcall _DMC_01_Home_Status(U16 CardNo, U16 HomeNo, U16 *Status);


//2019-06-06
I16 _stdcall _DMC_01_set_rm_mpg_axes_amf_enable(U16 CardNo, U16 MasterNodeID, U16 MasterSlotID, U16* NodeID, U16* SlotID,U16 enable,U16 pulser_ratio,U32 *ratio,U32 *slop,U32 *denominator);


//2019-06-14
I16 _stdcall _DMC_01_set_tl(U16 CardNo,U16 NodeID,U16 SlotID, U16 Enable);


//2019-06-20
I16 _stdcall _DMC_01_change_pos_and_vel(U16 CardNo, U16 NodeID, U16 SlotID, I32 i32_TargetPos, I32 i32_TargetVel, F64 f64_TransTime); 


//2020-04-17
I16 _stdcall _DMC_Qep_set_axis_command_enable(U16 CardNo, U16* CompareChannel, U16* NodeID, U16* SlotID, U16* enable, U16 pulser_ratio, U32* ratio, U32* slop, U32* denominator);







//2018-06-11 
I16 _stdcall _DMC_01_word_write(U16 CardNo, U32 addr ,U16 value);

//2018-06-11 
I16 _stdcall _DMC_01_word_read(U16 CardNo, U32 addr ,U16* value);

//2018-11-30
I16 _stdcall _DMC_01_dword_write(U16 CardNo, U32 addr ,U32 value);

//2018-11-30
I16 _stdcall _DMC_01_dword_read(U16 CardNo, U32 addr ,U32* value);





#if defined __cplusplus
}
#endif

#endif
