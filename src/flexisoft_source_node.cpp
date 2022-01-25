
#include "sick_flexisoft_pkg/flexisoft_library.h"
#include <sick_flexisoft_pkg/flexisoft_define.h>

#include <agv_define/agv_action.h>
#include <agv_define/agvlib.h>
#include <sick_flexisoft_pkg/flexisoft_device_status.h>
#include <sick_flexisoft_pkg/safety_field_and_mode.h>
#include <sick_flexisoft_pkg/microscan3_field.h>
#include <sick_flexisoft_pkg/flexisoft_function_safety.h>
#include <sick_flexisoft_pkg/brake.h>
#include <mkt_action/Safety_Measurement.h>
#include <control_io_amax/io_digital.h>
#include <string>
#include <iostream>

clientSock *Flexisoft = new clientSock("192.168.1.11", 9101);

ros::Publisher flexisoft_device_status_pub;
ros::Publisher fx_ipc_action_status_pub;
ros::Publisher safety_field_and_mode_pub;
ros::Publisher microscan3_field_pub;
ros::Publisher flexisoft_function_safety_pub;
ros::Publisher flexisoft_brake_pub;
ros::Publisher mkt_safety_field_pub;

agv_define::agv_action agv_action_name;

sick_flexisoft_pkg::flexisoft_device_status flexisoft_device_status;
sick_flexisoft_pkg::safety_field_and_mode safety_field_and_mode;
sick_flexisoft_pkg::microscan3_field microscan3_field;
sick_flexisoft_pkg::flexisoft_function_safety flexisoft_function_safety;
sick_flexisoft_pkg::brake brake;
mkt_action::Safety_Measurement Safety_Measurement;
control_io_amax::io_digital io_digital;

void flexisoft_brake_function_pub();
void ipcFxActionStatusCallBack(const agv_define::agv_action &st_io_action)
{
    uint16_t st_io_action_Action = st_io_action.action;
    uint16_t st_io_action_State = st_io_action.state;
    uint16_t st_io_action_Status = agv_action_name.STATUS_SUCCEEDED;
    bool st_io_action_Load = false;
    float st_io_limit_trans = -0.14;
    float st_io_limit_theta = 0;
    bool *IPC_SAFE_SP_Limit;
    uint16_t st_speed_limit_SAFE_SP_Limit;

    agv_define::agv_action st_io_action_status;
    st_io_action_status = st_io_action;

    st_io_action_status.action = st_io_action_Action;
    st_io_action_status.status = st_io_action_Status;

    fx_ipc_action_status_pub.publish(st_io_action_status);
}
void controlBrakeCallBack(const sick_flexisoft_pkg::brake &st_controll_brake)
{
    uint8_t st_controll_brake_brake_mode= st_controll_brake.brake_mode;

    bool st_io_action_Load = false;
    uint16_t st_speed_limit_SAFE_SP_Limit;

    if(st_controll_brake_brake_mode==1){
        // Phanh
        Flexisoft->write_bit(IPC_SAFE_CMD_BRAKE_CLOSE,true);
        Flexisoft->write_bit(IPC_SAFE_CMD_BRAKE_OPEN,false);
        ROS_INFO("REQUEST CLOSE BRAKE");
    }else if(st_controll_brake_brake_mode==0){
        // Mo Phanh
        Flexisoft->write_bit(IPC_SAFE_CMD_BRAKE_CLOSE,false);
        Flexisoft->write_bit(IPC_SAFE_CMD_BRAKE_OPEN,true);
        ROS_INFO("REQUEST OPEN BRAKE");
    }
    Flexisoft->tcp_write(1);
flexisoft_brake_function_pub();

}
void batterLowCallBack(const control_io_amax::io_digital &st_battery_low){
    uint8_t st_battery_low_mode= st_battery_low.mode;
    if (st_battery_low.mode==1)
    {
       Flexisoft->write_bit(IPC_SAFE_CMD_BATTERY_LOW,true);
        ROS_WARN("flexisoft_source_node.cpp - BATTERY_LOW");
    }else if(st_battery_low.mode==0){
    Flexisoft->write_bit(IPC_SAFE_CMD_BATTERY_LOW,false);
    }
    Flexisoft->tcp_write(1);
}

void flexisoft_device_status_function_pub()
{

    flexisoft_device_status.fx_safe_gb_gepr_ok = Flexisoft->read_bit(FX_SAFE_GB_GEPR_OK);
    flexisoft_device_status.fx_safe_gb_ms3_f_ok = Flexisoft->read_bit(FX_SAFE_GB_MS3_F_OK);
    flexisoft_device_status.fx_safe_gb_ms3_b_ok = Flexisoft->read_bit(FX_SAFE_GB_MS3_B_OK);
    flexisoft_device_status.fx_safe_fc_field_stop_ok = Flexisoft->read_bit(FX_SAFE_FC_FIELD_STOP_OK);
    flexisoft_device_status.fx_safe_fc_field_dece_ok = Flexisoft->read_bit(FX_SAFE_FC_FIELD_DECE_OK);

    flexisoft_device_status.fx_safe_fc_motor_ready = Flexisoft->read_bit(FX_SAFE_FC_MOTOR_READY);
    flexisoft_device_status.fx_safe_fc_power_motor_ready = Flexisoft->read_bit(FX_SAFE_FC_POWER_MOTOR_READY);
    flexisoft_device_status.fx_safe_gb_driver_ok = Flexisoft->read_bit(FX_SAFE_GB_DRIVER_OK);
    flexisoft_device_status.fx_safe_gb_key_brake = Flexisoft->read_bit(FX_SAFE_GB_KEY_BRAKE);
    flexisoft_device_status.fx_safe_gb_alm_m = Flexisoft->read_bit(FX_SAFE_GB_ALM_M);
    flexisoft_device_status.fx_safe_gb_warn_m = Flexisoft->read_bit(FX_SAFE_GB_WARN_M);
    flexisoft_device_status.fx_safe_gb_edm_mc = Flexisoft->read_bit(FX_SAFE_GB_EDM_MC);
    flexisoft_device_status.fx_safe_gb_edm_error = Flexisoft->read_bit(FX_SAFE_GB_EDM_ERROR);

    
    flexisoft_device_status.fx_safe_fc_flexisoft_ready = Flexisoft->read_bit(FX_SAFE_FC_FLEXISOFT_READY);
    flexisoft_device_status.fx_safe_fc_safe_base_ok = Flexisoft->read_bit(FX_SAFE_FC_SAFE_BASE_OK);
    flexisoft_device_status.fx_safe_fc_start_enable = Flexisoft->read_bit(FX_SAFE_FC_START_ENABLE);
    flexisoft_device_status.fx_safe_fc_reset_enable = Flexisoft->read_bit(FX_SAFE_FC_RESET_ENABLE);
    flexisoft_device_status.fx_safe_gb_enc_ok = Flexisoft->read_bit(FX_SAFE_GB_ENC_OK);
    flexisoft_device_status.fx_safe_gb_emc = Flexisoft->read_bit(FX_SAFE_GB_EMC);
    flexisoft_device_status.fx_safe_fc_load_on_agv = Flexisoft->read_bit(FX_SAFE_FC_LOAD_ON_AGV);

    

    flexisoft_device_status_pub.publish(flexisoft_device_status);
}
void safety_field_and_mode_function_pub()
{

    safety_field_and_mode.fx_safe_mode = Flexisoft->read_half_byte(FX_SAFE_MODE_STANDSTLL);
    safety_field_and_mode.fx_safe_case_ctrl = Flexisoft->read_half_byte(FX_SAFE_CASE_CTRL_00);
    safety_field_and_mode.fx_safe_field = Flexisoft->read_half_byte(FX_SAFE_FIELD_POWER);
    safety_field_and_mode.fx_safe_ipc_limt = Flexisoft->read_half_byte(FX_SAFE_IPC_LIMIT_00);

    safety_field_and_mode_pub.publish(safety_field_and_mode);
}

void microscan3_field_function_pub()
{

    microscan3_field.fx_ms3_f_case = Flexisoft->read_byte(FX_MS3_F_CASE_H);
    microscan3_field.fx_ms3_f_monitor = Flexisoft->read_byte(FX_MS3_F_MONITOR_H);

    microscan3_field.fx_ms3_f_case_sp = Flexisoft->read_half_byte(FX_MS3_F_CASE_H);
    microscan3_field.fx_ms3_f_case_dir = Flexisoft->read_half_byte(FX_MS3_F_CASE_D);
    microscan3_field.fx_ms3_f_field = Flexisoft->read_half_byte(FX_MS3_F_FIELD_POWER);

    string ms3_f_data_sp;
    uint8_t SAFE_SP_AGV_F = SSA(Flexisoft->read_half_byte(FX_MS3_F_CASE_H));
    switch (SAFE_SP_AGV_F)
    {
    case SAFE_SP_AGV_STANDSTILL:
        ms3_f_data_sp = "FRONT_SAFE_SP_AGV_STANDSTILL";
        break;
    case SAFE_SP_AGV_VERYSLOW:
        ms3_f_data_sp = "FRONT_SAFE_SP_AGV_VERYSLOW";
        break;
    case SAFE_SP_AGV_SLOW:
        ms3_f_data_sp = "FRONT_SAFE_SP_AGV_SLOW";
        break;
    case SAFE_SP_AGV_MEDIUM:
        ms3_f_data_sp = "FRONT_SAFE_SP_AGV_MEDIUM";
        break;
    case SAFE_SP_AGV_FAST:
        ms3_f_data_sp = "FRONT_SAFE_SP_AGV_FAST";
        break;
    case SAFE_SP_AGV_VERYFAST_00:
        ms3_f_data_sp = "FRONT_SAFE_SP_AGV_VERYFAST_00";
        break;
    case SAFE_SP_AGV_VERYFAST_08:
        ms3_f_data_sp = "FRONT_SAFE_SP_AGV_VERYFAST_08";
        break;
    case SAFE_SP_AGV_OVERSPEED:
        ms3_f_data_sp = "FRONT_SAFE_SP_AGV_OVERSPEED";
        break;

    default:
        break;
    }
    microscan3_field.ms3_f_data_sp = ms3_f_data_sp;

    string ms3_f_data_dir;
    uint8_t SAFE_DIR_AGV_F = SDA(Flexisoft->read_half_byte(FX_MS3_F_CASE_D));
    switch (SAFE_DIR_AGV_F)
    {
    case SAFE_DIR_AGV_BASE:
        ms3_f_data_dir = "FRONT_SAFE_DIR_AGV_BASE ";
        break;
    case SAFE_DIR_AGV_WIDE_L:
        ms3_f_data_dir = "FRONT_SAFE_DIR_AGV_WIDE_L ";
        break;
    case SAFE_DIR_AGV_NARRAOW_01_L:
        ms3_f_data_dir = "FRONT_SAFE_DIR_AGV_NARRAOW_01_L  ";
        break;
    case SAFE_DIR_AGV_WIDE_R:
        ms3_f_data_dir = "FRONT_SAFE_DIR_AGV_WIDE_R  ";
        break;
    case SAFE_DIR_AGV_NARROW_1_R:
        ms3_f_data_dir = "FRONT_SAFE_DIR_AGV_NARROW_1_R  ";
        break;
    case SAFE_DIR_AGV_TURN:
        ms3_f_data_dir = "FRONT_SAFE_DIR_AGV_TURN  ";
        break;
    case SAFE_DIR_AGV_NARROW_2_L:
        ms3_f_data_dir = "FRONT_SAFE_DIR_AGV_NARROW_2_L  ";
        break;
    case SAFE_DIR_AGV_NARROW_2_R:
        ms3_f_data_dir = "FRONT_SAFE_DIR_AGV_NARROW_2_R  ";
        break;
    case SAFE_DIR_AGV_LOAD_BASE:
        ms3_f_data_dir = "FRONT_SAFE_DIR_AGV_LOAD_BASE  ";
        break;
    case SAFE_DIR_AGV_LOAD_WIDE_L:
        ms3_f_data_dir = "FRONT_SAFE_DIR_AGV_LOAD_WIDE_L  ";
        break;
    case SAFE_DIR_AGV_LOAD_NARRAOW_01_L:
        ms3_f_data_dir = "FRONT_SAFE_DIR_AGV_LOAD_NARRAOW_01_L  ";
        break;
    case SAFE_DIR_AGV_LOAD_WIDE_R:
        ms3_f_data_dir = "FRONT_SAFE_DIR_AGV_LOAD_WIDE_R  ";
        break;
    case SAFE_DIR_AGV_LOAD_NARROW_1_R:
        ms3_f_data_dir = "FRONT_SAFE_DIR_AGV_LOAD_NARROW_1_R  ";
        break;
    case SAFE_DIR_AGV_LOAD_TURN:
        ms3_f_data_dir = "FRONT_SAFE_DIR_AGV_LOAD_TURN    ";
        break;
    case SAFE_DIR_AGV_LOAD_NARROW_2_L:
        ms3_f_data_dir = "FRONT_SAFE_DIR_AGV_LOAD_NARROW_2_L  ";
        break;
    case SAFE_DIR_AGV_LOAD_NARROW_2_R:
        ms3_f_data_dir = "FRONT_SAFE_DIR_AGV_LOAD_NARROW_2_R ";
        break;

    default:
        break;
    }
    microscan3_field.ms3_f_data_dir = ms3_f_data_dir;

    string fx_ms3_f_data_field;
    uint8_t SAFE_FIELD_F = SF(Flexisoft->read_half_byte(FX_MS3_F_FIELD_POWER));
    switch (SAFE_FIELD_F)
    {
    case SAFE_FIELD_DEFAULT:
        fx_ms3_f_data_field = "FRONT_SAFE_FIELD_DEFAULT";
        break;
    case SAFE_FIELD_POWER:
        fx_ms3_f_data_field = "FRONT_SAFE_FIELD_POWER";
        break;
    case SAFE_FIELD_BRACKER:
        fx_ms3_f_data_field = "FRONT_SAFE_FIELD_BRACKER";
        break;
    case SAFE_FIELD_WARNER:
        fx_ms3_f_data_field = "FRONT_SAFE_FIELD_WARNER";
        break;
    case SAFE_FIELD_DETECTER:
        fx_ms3_f_data_field = "FRONT_SAFE_FIELD_DETECTER";
        break;

    default:
        break;
    }
    microscan3_field.fx_ms3_f_data_field = fx_ms3_f_data_field;

    microscan3_field.data_empty = "              ==========            ";

    microscan3_field.fx_ms3_b_case = Flexisoft->read_byte(FX_MS3_B_CASE_H);
    microscan3_field.fx_ms3_b_monitor = Flexisoft->read_byte(FX_MS3_B_MONITOR_H);

    microscan3_field.fx_ms3_b_case_sp = Flexisoft->read_half_byte(FX_MS3_B_CASE_H);
    microscan3_field.fx_ms3_b_case_dir = Flexisoft->read_half_byte(FX_MS3_F_CASE_D);
    microscan3_field.fx_ms3_b_field = Flexisoft->read_half_byte(FX_MS3_B_FIELD_POWER);

    string ms3_b_data_sp;
    uint8_t SAFE_SP_AGV_B = SSA(Flexisoft->read_half_byte(FX_MS3_B_CASE_H));
    switch (SAFE_SP_AGV_B)
    {
    case SAFE_SP_AGV_STANDSTILL:
        ms3_b_data_sp = "BACK_SAFE_SP_AGV_STANDSTILL";
        break;
    case SAFE_SP_AGV_VERYSLOW:
        ms3_b_data_sp = "BACK_SAFE_SP_AGV_VERYSLOW";
        break;
    case SAFE_SP_AGV_SLOW:
        ms3_b_data_sp = "BACK_SAFE_SP_AGV_SLOW";
        break;
    case SAFE_SP_AGV_MEDIUM:
        ms3_b_data_sp = "BACK_SAFE_SP_AGV_MEDIUM";
        break;
    case SAFE_SP_AGV_FAST:
        ms3_b_data_sp = "BACK_SAFE_SP_AGV_FAST";
        break;
    case SAFE_SP_AGV_VERYFAST_00:
        ms3_b_data_sp = "BACK_SAFE_SP_AGV_VERYFAST_00";
        break;
    case SAFE_SP_AGV_VERYFAST_08:
        ms3_b_data_sp = "BACK_SAFE_SP_AGV_VERYFAST_08";
        break;
    case SAFE_SP_AGV_OVERSPEED:
        ms3_b_data_sp = "BACK_SAFE_SP_AGV_OVERSPEED";
        break;

    default:
        break;
    }
    microscan3_field.ms3_b_data_sp = ms3_b_data_sp;

    string ms3_b_data_dir;
    uint8_t SAFE_DIR_AGV_B = SDA(Flexisoft->read_half_byte(FX_MS3_B_CASE_D));
    switch (SAFE_DIR_AGV_B)
    {
    case SAFE_DIR_AGV_BASE:
        ms3_b_data_dir = "BACK_SAFE_DIR_AGV_BASE ";
        break;
    case SAFE_DIR_AGV_WIDE_L:
        ms3_b_data_dir = "BACK_SAFE_DIR_AGV_WIDE_L ";
        break;
    case SAFE_DIR_AGV_NARRAOW_01_L:
        ms3_b_data_dir = "BACK_SAFE_DIR_AGV_NARRAOW_01_L  ";
        break;
    case SAFE_DIR_AGV_WIDE_R:
        ms3_b_data_dir = "BACK_SAFE_DIR_AGV_WIDE_R  ";
        break;
    case SAFE_DIR_AGV_NARROW_1_R:
        ms3_b_data_dir = "BACK_SAFE_DIR_AGV_NARROW_1_R  ";
        break;
    case SAFE_DIR_AGV_TURN:
        ms3_b_data_dir = "BACK_SAFE_DIR_AGV_TURN  ";
        break;
    case SAFE_DIR_AGV_NARROW_2_L:
        ms3_b_data_dir = "BACK_SAFE_DIR_AGV_NARROW_2_L  ";
        break;
    case SAFE_DIR_AGV_NARROW_2_R:
        ms3_b_data_dir = "BACK_SAFE_DIR_AGV_NARROW_2_R  ";
        break;
    case SAFE_DIR_AGV_LOAD_BASE:
        ms3_b_data_dir = "BACK_SAFE_DIR_AGV_LOAD_BASE  ";
        break;
    case SAFE_DIR_AGV_LOAD_WIDE_L:
        ms3_b_data_dir = "BACK_SAFE_DIR_AGV_LOAD_WIDE_L  ";
        break;
    case SAFE_DIR_AGV_LOAD_NARRAOW_01_L:
        ms3_b_data_dir = "BACK_SAFE_DIR_AGV_LOAD_NARRAOW_01_L  ";
        break;
    case SAFE_DIR_AGV_LOAD_WIDE_R:
        ms3_b_data_dir = "BACK_SAFE_DIR_AGV_LOAD_WIDE_R  ";
        break;
    case SAFE_DIR_AGV_LOAD_NARROW_1_R:
        ms3_b_data_dir = "BACK_SAFE_DIR_AGV_LOAD_NARROW_1_R  ";
        break;
    case SAFE_DIR_AGV_LOAD_TURN:
        ms3_b_data_dir = "BACK_SAFE_DIR_AGV_LOAD_TURN    ";
        break;
    case SAFE_DIR_AGV_LOAD_NARROW_2_L:
        ms3_b_data_dir = "BACK_SAFE_DIR_AGV_LOAD_NARROW_2_L  ";
        break;
    case SAFE_DIR_AGV_LOAD_NARROW_2_R:
        ms3_b_data_dir = "BACK_SAFE_DIR_AGV_LOAD_NARROW_2_R ";
        break;

    default:
        break;
    }
    microscan3_field.ms3_b_data_dir = ms3_b_data_dir;

    string fx_ms3_b_data_field;
    uint8_t SAFE_FIELD_B = SF(Flexisoft->read_half_byte(FX_MS3_B_FIELD_POWER));
    switch (SAFE_FIELD_F)
    {
    case SAFE_FIELD_DEFAULT:
        fx_ms3_b_data_field = "BACK_SAFE_FIELD_DEFAULT";
        break;
    case SAFE_FIELD_POWER:
        fx_ms3_b_data_field = "BACK_SAFE_FIELD_POWER";
        break;
    case SAFE_FIELD_BRACKER:
        fx_ms3_b_data_field = "BACK_SAFE_FIELD_BRACKER";
        break;
    case SAFE_FIELD_WARNER:
        fx_ms3_b_data_field = "BACK_SAFE_FIELD_WARNER";
        break;
    case SAFE_FIELD_DETECTER:
        fx_ms3_b_data_field = "BACK_SAFE_FIELD_DETECTER";
        break;

    default:
        break;
    }
    microscan3_field.fx_ms3_b_data_field = fx_ms3_b_data_field;

    microscan3_field_pub.publish(microscan3_field);
}
void flexisoft_function_safety_function_pub()
{

    flexisoft_function_safety.fx_safe_fc_flexisoft_ready = Flexisoft->read_bit(FX_SAFE_FC_FLEXISOFT_READY);
    if (Flexisoft->read_bit(FX_SAFE_FC_FLEXISOFT_READY) == false)
    {
        if (Flexisoft->read_bit(FX_SAFE_FC_MOTOR_READY) == false)
        {

            flexisoft_function_safety.fx_safe_fc_motor_ready = "FX_SAFE_FC_MOTOR_READY_ERROR";
        }
        if (Flexisoft->read_bit(FX_SAFE_FC_POWER_MOTOR_READY) == false)
        {

            flexisoft_function_safety.fx_safe_fc_power_motor_ready = "FX_SAFE_FC_POWER_MOTOR_READY_ERROR";
        }
        if (Flexisoft->read_bit(FX_SAFE_FC_FIELD_STOP_OK) == false)
        {

            flexisoft_function_safety.fx_safe_fc_field_stop_ok = "FX_SAFE_FC_FIELD_STOP_OK_ERROR";
        }
        if (Flexisoft->read_bit(FX_SAFE_FC_FIELD_DECE_OK) == false)
        {

            flexisoft_function_safety.fx_safe_fc_field_dece_ok = "FX_SAFE_FC_FIELD_DECE_OK_ERROR";
        }
        if (Flexisoft->read_bit(FX_SAFE_FC_START_ENABLE) == false)
        {

            flexisoft_function_safety.fx_safe_fc_start_enable_data_error = "FX_SAFE_FC_START_ENABLE_ERROR";
        }
        if (Flexisoft->read_bit(FX_SAFE_FC_RESET_ENABLE) == false)
        {

            flexisoft_function_safety.fx_safe_fc_reset_enable_data_error = "FX_SAFE_FC_RESET_ENABLE_ERROR";
        }
        if (Flexisoft->read_bit(FX_SAFE_FC_SAFE_BASE_OK) == false)
        {

            flexisoft_function_safety.fx_safe_fc_safe_base_ok_data_error = "FX_SAFE_FC_SAFE_BASE_OK_ERROR";
        }
    }
    flexisoft_function_safety.fx_safe_fc_start_enable = Flexisoft->read_byte(FX_SAFE_FC_START_ENABLE);
    flexisoft_function_safety.fx_safe_fc_reset_enable = Flexisoft->read_byte(FX_SAFE_FC_RESET_ENABLE);
    flexisoft_function_safety.fx_safe_fc_safe_base_ok = Flexisoft->read_byte(FX_SAFE_FC_SAFE_BASE_OK);

    flexisoft_function_safety_pub.publish(flexisoft_function_safety);
}
void flexisoft_brake_function_pub(){
    Flexisoft->tcp_read(DATA_SET_01);
    
    bool fx_safe_cmd_info_brake = Flexisoft->read_bit(FX_SAFE_CMD_INFO_BRAKE);
    if(fx_safe_cmd_info_brake==false){
        // phanh dong
        brake.brake_mode = 1;
        ROS_INFO("flexisoft_source_node/BRAKE IS CLOSE AND SIGN IS: %d",fx_safe_cmd_info_brake);
    }else if(fx_safe_cmd_info_brake== true){
        // phanh mo
        brake.brake_mode = 0;
        ROS_INFO("flexisoft_source_node/BRAKE IS OPEN AND SIGN IS: %d",fx_safe_cmd_info_brake);
    }
    flexisoft_brake_pub.publish(brake);
}
void mkt_safety_field_function_pub(){
    Flexisoft->tcp_read(DATA_SET_01);
    bool Detecter = Flexisoft->read_bit(FX_SAFE_FIELD_DETECTER);
    bool Wanner =Flexisoft->read_bit(FX_SAFE_FIELD_WARNER);
    bool Braker =Flexisoft->read_bit(FX_SAFE_FC_FIELD_STOP_OK);
    bool Power =Flexisoft->read_bit(FX_SAFE_FIELD_POWER);


    Safety_Measurement.ns3.field_status={Detecter, Wanner, Braker, Power};
    Safety_Measurement.header.stamp=ros::Time::now();
    mkt_safety_field_pub.publish(Safety_Measurement);
}

int main(int argc, char **argv)
{

    ros::init(argc, argv, "safety_function");
    ros::NodeHandle nh;

    //sick_flexisoft_pkg::SAFE_SP_AGV SAFE_SP_AGV;

    flexisoft_device_status_pub = nh.advertise<sick_flexisoft_pkg::flexisoft_device_status>("/flexisoft_device_status", 10);
    safety_field_and_mode_pub = nh.advertise<sick_flexisoft_pkg::safety_field_and_mode>("/safety_field_and_mode", 10);
    microscan3_field_pub = nh.advertise<sick_flexisoft_pkg::microscan3_field>("/microscan3_field", 10);
    flexisoft_function_safety_pub = nh.advertise<sick_flexisoft_pkg::flexisoft_function_safety>("/flexisoft_function_safety", 10);

    fx_ipc_action_status_pub = nh.advertise<agv_define::agv_action>("/fx_ipc_action_status", 10);

    flexisoft_brake_pub = nh.advertise<sick_flexisoft_pkg::brake>("/flexisoft_brake", 10);

    mkt_safety_field_pub = nh.advertise<mkt_action::Safety_Measurement>("/mkt_safety_field", 10);

    ros::Subscriber ipc_fx_action_status_sub = nh.subscribe("ipc_fx_action_status", 10, ipcFxActionStatusCallBack);
    ros::Subscriber control_brake_sub = nh.subscribe("control_brake", 10, controlBrakeCallBack);
    ros::Subscriber battery_low_sub = nh.subscribe("battery_low", 10, batterLowCallBack);

    ros::Rate loop_rate(30);
    while (ros::ok())
    {
        if (!Flexisoft->connected)
        {
            Flexisoft->connect();
            ROS_INFO("FLEXISOFT CONNECTING....");
        }
        while (ros::ok() && Flexisoft->connected)
        {
            /* code */

            Flexisoft->tcp_read(DATA_SET_01);
            flexisoft_device_status_function_pub();
            safety_field_and_mode_function_pub();
            microscan3_field_function_pub();
            flexisoft_function_safety_function_pub();
            mkt_safety_field_function_pub();
            

            Flexisoft->tcp_write_all();
            // sleep(1);
            // cout << "running" << endl;
            // ROS_INFO("FLEXISOFT IS RUNNING......");
            ros::spinOnce();
            loop_rate.sleep();

            /*         while (Flexisoft->connected)
        {
            cout<<"running----------------------------"<<endl;
           Flexisoft->connect();
           sleep(1);
        } */
        }
        loop_rate.sleep();
        ros::spinOnce();
    }
    Flexisoft->disconnect();
    ros::spin();
    delete (Flexisoft);

    return 0;
}