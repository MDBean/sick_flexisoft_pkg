#ifndef FLEXISOFT_DEFINE_H
#define FLEXISOFT_DEFINE_H

#define FX_LOCAl_STATUS_FX3_CPU	    01 , 0 , 0
#define FX_LOCAl_STATUS_XTIO_01	    01 , 0 , 1
#define FX_LOCAl_STATUS_XTIO_02	    01 , 0 , 2
#define FX_LOCAl_STATUS_STIO_03	    01 , 0 , 3
#define FX_LOCAl_STATUS_MOC_01	    01 , 0 , 4
#define FX_LOCAl_STATUS_GERP	    01 , 0 , 6
#define FX_LOCAl_STATUS_GENT	    01 , 0 , 7
#define FX_STATUS_INPUT_XTIO_01	    01 , 0 , 9
#define FX_STATUS_INPUT_XTIO_02	    01 , 0 , 10
#define FX_STATUS_INPUT_STIO_03	    01 , 0 , 11
#define FX_STATUS_INPUT_MOC_01	    01 , 0 , 12
#define FX_STATUS_INPUT_GERP	    01 , 0 , 14
#define FX_STATUS_INPUT_GENT	    01 , 0 , 15
#define FX_STATUS_OUTPUT_XTIO_01	    01 , 1 , 1
#define FX_STATUS_OUTPUT_XTIO_02	    01 , 1 , 2
#define FX_STATUS_OUTPUT_STIO_03	    01 , 1 , 3
#define FX_STATUS_OUTPUT_GERP	    01 , 1 , 6
#define FX_STATUS_OUTPUT_GENT	    01 , 1 , 7
#define FX_INP_EMC_FRONT	    01 , 2 , 0
#define FX_INP_EMC_BACK	    01 , 2 , 1
#define FX_INP_BT_START	    01 , 2 , 2
#define FX_INP_BT_RESET	    01 , 2 , 3
#define FX_INP_BT_STOP	    01 , 2 , 4
#define FX_INP_SW_KEY_BRAKE	    01 , 2 , 5
#define FX_INP_EDM_MC_LEFT	    01 , 2 , 8
#define FX_INP_EDM_MC_RIGHT	    01 , 2 , 9
#define FX_INP_ALM_LEFT	    01 , 2 , 10
#define FX_INP_ALM_RIGHT	    01 , 2 , 11
#define FX_INP_WARN_LEFT	    01 , 2 , 12
#define FX_INP_WARN_RIGHT	    01 , 2 , 13
#define FX_ENC_IN_SP_BOTH_00	    01 , 4 , 0
#define FX_ENC_IN_SP_BOTH_01	    01 , 4 , 1
#define FX_ENC_IN_SP_BOTH_02	    01 , 4 , 2
#define FX_ENC_IN_SP_BOTH_03	    01 , 4 , 3
#define FX_ENC_IN_SP_LEFT_00	    01 , 4 , 4
#define FX_ENC_IN_SP_LEFT_01	    01 , 4 , 5
#define FX_ENC_IN_SP_LEFT_02	    01 , 4 , 6
#define FX_ENC_IN_SP_LEFT_03	    01 , 4 , 7
#define FX_ENC_IN_SP_RIGHT_00	    01 , 4 , 8
#define FX_ENC_IN_SP_RIGHT_01	    01 , 4 , 9
#define FX_ENC_IN_SP_RIGHT_02	    01 , 4 , 10
#define FX_ENC_IN_SP_RIGHT_03	    01 , 4 , 11
#define FX_ENC_IN_DIR_FORWARD	    01 , 4 , 12
#define FX_ENC_IN_DIR_BACKWARD	    01 , 4 , 13
#define FX_ENC_IN_DIR_TURN	    01 , 4 , 14
#define FX_ENC_IN_STANDSTILL_ERROR	    01 , 4 , 15
#define FX_OUTP_OSSD_MOTOR	    01 , 5 , 0
#define FX_OUTP_DRIVE_STOP_MODE	    01 , 5 , 2
#define FX_OUTP_DRIVE_FWB_REV	    01 , 5 , 8
#define FX_OUTP_DRIVE_MB_FREE	    01 , 5 , 10
#define FX_OUTP_LED_START	    01 , 6 , 0
#define FX_OUTP_LED_RESET	    01 , 6 , 1
#define FX_OUTP_SPEAKER_BUZZER	    01 , 6 , 2
#define FX_OUTP_RESET_ALARM_LEFT	    01 , 6 , 4
#define FX_OUTP_RESET_ALARM_RIGHT	    01 , 6 , 5
#define FX_ENC_OUT_LIMIT_00	    01 , 7 , 0
#define fx_ENC_OUT_LIMIT_01	    01 , 7 , 1
#define FX_ENC_OUT_LIMIT_02	    01 , 7 , 2
#define FX_ENC_OUT_LIMIT_03	    01 , 7 , 3
#define FX_MS3_F_MODE_TRIG_SAFE	    01 , 8 , 0
#define FX_MS3_F_MODE_USE_CASE	    01 , 8 , 1
#define FX_MS3_F_MODE_SLEEP	    01 , 8 , 2
#define FX_MS3_F_FC_RS_DEVICE	    01 , 8 , 3
#define FX_MS3_F_FC_RS_NETWORK	    01 , 8 , 4
#define FX_MS3_F_FC_RS_SAFE_01	    01 , 8 , 5
#define FX_MS3_F_FC_RS_SAFE_02	    01 , 8 , 6
#define FX_MS3_F_FC_RS_SAFE_03	    01 , 8 , 7
#define FX_MS3_F_CASE_H	    01 , 8 , 8
#define FX_MS3_F_CASE_G	    01 , 8 , 9
#define FX_MS3_F_CASE_F	    01 , 8 , 10
#define FX_MS3_F_CASE_E	    01 , 8 , 11
#define FX_MS3_F_CASE_D	    01 , 8 , 12
#define FX_MS3_F_CASE_C	    01 , 8 , 13
#define FX_MS3_F_CASE_B	    01 , 8 , 14
#define FX_MS3_F_CASE_A	    01 , 8 , 15
#define FX_MS3_F_STT_READY	    01 , 9 , 0
#define FX_MS3_F_STT_STATUS	    01 , 9 , 1
#define FX_MS3_F_STT_SLEEP_ACTIVE	    01 , 9 , 2
#define FX_MS3_F_STT_DUST_WARN	    01 , 9 , 3
#define FX_MS3_F_STT_DUST_ERROR	    01 , 9 , 4
#define FX_MS3_F_STT_MS	    01 , 9 , 5
#define FX_MS3_F_STT_APPLICATION_ERROR	    01 , 9 , 6
#define FX_MS3_F_STT_DEVICE_ERROR	    01 , 9 , 7
#define FX_MS3_F_ST_COPS_01	    01 , 9 , 8
#define FX_MS3_F_ST_COPS_02	    01 , 9 , 9
#define FX_MS3_F_ST_COPS_03	    01 , 9 , 10
#define FX_MS3_F_ST_COPS_04	    01 , 9 , 11
#define FX_MS3_F_ST_COPNS_01	    01 , 9 , 12
#define FX_MS3_F_ST_COPNS_02	    01 , 9 , 13
#define FX_MS3_F_ST_COPNS_03	    01 , 9 , 14
#define FX_MS3_F_ST_COPNS_04	    01 , 9 , 15
#define FX_MS3_F_REQ_RS_COPS_01	    01 , 10 , 0
#define FX_MS3_F_REQ_RS_COPS_02	    01 , 10 , 1
#define FX_MS3_F_REQ_RS_COPS_03	    01 , 10 , 2
#define FX_MS3_F_REQ_RS_COPS_04	    01 , 10 , 3
#define FX_MS3_F_FIELD_POWER	    01 , 10 , 4
#define FX_MS3_F_FIELD_BRACKER	    01 , 10 , 5
#define FX_MS3_F_FIELD_WARNER	    01 , 10 , 6
#define FX_MS3_F_FIELD_DETECTER	    01 , 10 , 7
#define FX_MS3_F_MONITOR_H	    01 , 10 , 8
#define FX_MS3_F_MONITOR_G	    01 , 10 , 9
#define FX_MS3_F_MONITOR_F	    01 , 10 , 10
#define FX_MS3_F_MONITOR_E	    01 , 10 , 11
#define FX_MS3_F_MONITOR_D	    01 , 10 , 12
#define FX_MS3_F_MONITOR_C	    01 , 10 , 13
#define FX_MS3_F_MONITOR_B	    01 , 10 , 14
#define FX_MS3_F_MONITOR_A	    01 , 10 , 15
#define FX_MS3_B_MODE_TRIG_SAFE	    01 , 11 , 0
#define FX_MS3_B_MODE_USE_CASE	    01 , 11 , 1
#define FX_MS3_B_MODE_SLEEP	    01 , 11 , 2
#define FX_MS3_B_FC_RS_DEVICE	    01 , 11 , 3
#define FX_MS3_B_FC_RS_NETWORK	    01 , 11 , 4
#define FX_MS3_B_FC_RS_SAFE_01	    01 , 11 , 5
#define FX_MS3_B_FC_RS_SAFE_02	    01 , 11 , 6
#define FX_MS3_B_FC_RS_SAFE_03	    01 , 11 , 7
#define FX_MS3_B_CASE_H	    01 , 11 , 8
#define FX_MS3_B_CASE_G	    01 , 11 , 9
#define FX_MS3_B_CASE_F	    01 , 11 , 10
#define FX_MS3_B_CASE_E	    01 , 11 , 11
#define FX_MS3_B_CASE_D	    01 , 11 , 12
#define FX_MS3_B_CASE_C	    01 , 11 , 13
#define FX_MS3_B_CASE_B	    01 , 11 , 14
#define FX_MS3_B_CASE_A	    01 , 11 , 15
#define FX_MS3_B_STT_READY	    01 , 12 , 0
#define FX_MS3_B_STT_STATUS	    01 , 12 , 1
#define FX_MS3_B_STT_SLEEP_ACTIVE	    01 , 12 , 2
#define FX_MS3_B_STT_DUST_WARN	    01 , 12 , 3
#define FX_MS3_B_STT_DUST_ERROR	    01 , 12 , 4
#define FX_MS3_B_STT_MS	    01 , 12 , 5
#define FX_MS3_B_STT_APPLICATION_ERROR	    01 , 12 , 6
#define FX_MS3_B_STT_DEVICE_ERROR	    01 , 12 , 7
#define FX_MS3_B_ST_COPS_01	    01 , 12 , 8
#define FX_MS3_B_ST_COPS_02	    01 , 12 , 9
#define FX_MS3_B_ST_COPS_03	    01 , 12 , 10
#define FX_MS3_B_ST_COPS_04	    01 , 12 , 11
#define FX_MS3_B_ST_COPNS_01	    01 , 12 , 12
#define FX_MS3_B_ST_COPNS_02	    01 , 12 , 13
#define FX_MS3_B_ST_COPNS_03	    01 , 12 , 14
#define FX_MS3_B_ST_COPNS_04	    01 , 12 , 15
#define FX_MS3_B_REQ_RS_COPS_01	    01 , 13 , 0
#define FX_MS3_B_REQ_RS_COPS_02	    01 , 13 , 1
#define FX_MS3_B_REQ_RS_COPS_03	    01 , 13 , 2
#define FX_MS3_B_REQ_RS_COPS_04	    01 , 13 , 3
#define FX_MS3_B_FIELD_POWER	    01 , 13 , 4
#define FX_MS3_B_FIELD_BRACKER	    01 , 13 , 5
#define FX_MS3_B_FIELD_WARNER	    01 , 13 , 6
#define FX_MS3_B_FIELD_DETECTER	    01 , 13 , 7
#define FX_MS3_B_MONITOR_H	    01 , 13 , 8
#define FX_MS3_B_MONITOR_G	    01 , 13 , 9
#define FX_MS3_B_MONITOR_F	    01 , 13 , 10
#define FX_MS3_B_MONITOR_E	    01 , 13 , 11
#define FX_MS3_B_MONITOR_D	    01 , 13 , 12
#define FX_MS3_B_MONITOR_C	    01 , 13 , 13
#define FX_MS3_B_MONITOR_B	    01 , 13 , 14
#define FX_MS3_B_MONITOR_A	    01 , 13 , 15
#define FX_SAFE_GB_EMC	    01 , 15 , 0
#define FX_SAFE_GB_START	    01 , 15 , 1
#define FX_SAFE_GB_RESET	    01 , 15 , 2
#define FX_SAFE_GB_KEY_BRAKE	    01 , 15 , 3
#define FX_SAFE_GB_EDM_MC	    01 , 15 , 4
#define FX_SAFE_GB_ALM_M	    01 , 15 , 5
#define FX_SAFE_GB_WARN_M	    01 , 15 , 6
#define FX_SAFE_GB_EDM_ERROR	    01 , 15 , 7
#define FX_SAFE_GB_GEPR_OK	    01 , 15 , 8
#define FX_SAFE_GB_MS3_OK	    01 , 15 , 9
#define FX_SAFE_GB_ENC_OK	    01 , 15 , 10
#define FX_SAFE_GB_DRIVER_OK	    01 , 15 , 11
#define FX_SAFE_CASE_CTRL_00	    01 , 15 , 12
#define FX_SAFE_CASE_CTRL_01	    01 , 15 , 13
#define FX_SAFE_CASE_CTRL_02	    01 , 15 , 14
#define FX_SAFE_CASE_CTRL_03	    01 , 15 , 15
#define FX_SAFE_GB_MS3_F_OK	    01 , 16 , 0
#define FX_SAFE_GB_MS3_B_OK	    01 , 16 , 1
#define FX_SAFE_GB_DRIVER_LEFT_OK	    01 , 16 , 2
#define FX_SAFE_GB_DRIVER_RIGHT_OK	    01 , 16 , 3
#define FX_SAFE_IPC_LIMIT_00	    01 , 16 , 4
#define FX_SAFE_IPC_LIMIT_01	    01 , 16 , 5
#define FX_SAFE_IPC_LIMIT_02	    01 , 16 , 6
#define FX_SAFE_IPC_LIMIT_03	    01 , 16 , 7
#define FX_SAFE_GB_ERROR_SPEED	    01 , 16 , 8
#define FX_SAFE_FC_FLEXISOFT_READY	    01 , 17 , 0
#define FX_SAFE_FC_MOTOR_READY	    01 , 17 , 1
#define FX_SAFE_FC_POWER_MOTOR_READY	    01 , 17 , 2
#define FX_SAFE_FC_FIELD_STOP_OK	    01 , 17 , 3
#define FX_SAFE_FC_FIELD_DECE_OK	    01 , 17 , 4
#define FX_SAFE_FC_START_ENABLE	    01 , 17 , 5
#define FX_SAFE_FC_RESET_ENABLE	    01 , 17 , 6
#define FX_SAFE_FC_SAFE_BASE_OK	    01 , 17 , 7
#define FX_SAFE_FC_LOAD_ON_AGV	    01 , 17 , 8
#define FX_SAFE_FC_SAVE_FIELD	    01 , 17 , 9
#define FX_SAFE_FC_FORWARD_RELEASE	    01 , 17 , 10
#define FX_SAFE_FC_BACKWARD_RELEASE	    01 , 17 , 11
#define FX_SAFE_FC_DISABLE_FIELD_SPEED	    01 , 17 , 12
#define FX_SAFE_FC_RS_SYSTEM	    01 , 17 , 13
#define FX_SAFE_FC_RS_MS3	    01 , 17 , 14
#define FX_SAFE_FC_RS_DIRVE	    01 , 17 , 15
#define FX_SAFE_MODE_STANDSTLL	    01 , 19 , 0
#define FX_SAFE_MODE_HAND	    01 , 19 , 1
#define FX_SAFE_MODE_SCANMAP	    01 , 19 , 2
#define FX_SAFE_MODE_AUTOMATIC	    01 , 19 , 3
#define FX_SAFE_MODE_BYPASS	    01 , 19 , 4
#define FX_SAFE_FIELD_POWER	    01 , 20 , 0
#define FX_SAFE_FIELD_BRACKER	    01 , 20 , 1
#define FX_SAFE_FIELD_WARNER	    01 , 20 , 2
#define FX_SAFE_FIELD_DETECTER	    01 , 20 , 3
#define FX_SAFE_FIELD_COUNTOUR	    01 , 20 , 4
#define FX_SAFE_SP_AGV_00	    01 , 20 , 8
#define FX_SAFE_SP_AGV_01	    01 , 20 , 9
#define FX_SAFE_SP_AGV_02	    01 , 20 , 10
#define FX_SAFE_DIR_AGV_00	    01 , 20 , 12
#define FX_SAFE_DIR_AGV_01	    01 , 20 , 13
#define FX_SAFE_DIR_AGV_02	    01 , 20 , 14
#define FX_SAFE_DIR_AGV_03	    01 , 20 , 15
#define FX_SAFE_STATUS_PENDING	    01 , 22 , 8
#define FX_SAFE_STATUS_ACTIVE	    01 , 22 , 9
#define FX_SAFE_STATUS_SUCCEEDED	    01 , 22 , 10
#define FX_SAFE_STATUS_REJECTED	    01 , 22 , 11
#define FX_SAFE_STATUS_LOST	    01 , 22 , 12
#define FX_SAFE_STATE_EXECUTE	    01 , 23 , 0
#define FX_SAFE_STATE_CANCEL	    01 , 23 , 1
#define FX_SAFE_STATE_DONE	    01 , 23 , 2
#define FX_SAFE_CMD_INFO_BRAKE	    01 , 23 , 8


//NETWORK TO FLEXISOFT 01
#define IPC_SAFE_IPC_BT_START	    01 , 0 , 0
#define IPC_SAFE_IPC_BT_RESET	    01 , 0 , 1
#define IPC_SAFE_IPC_BT_KEY_BRAKE	    01 , 0 , 2
#define IPC_SAFE_FC_LOAD_ON_AGV	    01 , 1 , 0
#define IPC_SAFE_IPC_READY	    01 , 2 , 0
#define IPC_SAFE_IPC_RUN	    01 , 2 , 1
#define IPC_SAFE_IPC_STOP	    01 , 2 , 2
#define IPC_SAFE_IPC_PAUSE	    01 , 2 , 3
#define IPC_SAFE_CMD_RESTART_LASER	    01 , 3 , 0
#define IPC_SAFE_CMD_SAFETY_DEFUALT	    01 , 3 , 1
#define IPC_SAFE_CMD_BYPASS_SAFETY	    01 , 3 , 2
#define IPC_SAFE_CMD_MAPPING_SAFETY	    01 , 3 , 3
#define IPC_SAFE_CMD_BRAKE_OPEN	    01 , 4 , 0
#define IPC_SAFE_CMD_BRAKE_CLOSE	    01 , 4 , 1
#define IPC_SAFE_CMD_BATTERY_LOW	    01 , 4 , 2



typedef enum SAFE_CASE_CTRL
{
    SAFE_CASE_CTRL_00 = 1,
    SAFE_CASE_CTRL_01 = 2,
    SAFE_CASE_CTRL_02 = 4,
    SAFE_CASE_CTRL_03 = 8,

} SCC;

typedef enum SAFE_IPC_LIMIT
{
    SAFE_IPC_LIMIT_STANDSTILL = 1,
    SSAFE_IPC_LIMIT_VERYSLOW = 2,
    SAFE_IPC_LIMIT_SLOW = 3,
    SAFE_IPC_LIMIT_MEDIUM = 4,
    SAFE_IPC_LIMIT_FAST = 5,
    SAFE_IPC_LIMIT_VERYFAST_00 = 6,
    SAFE_IPC_LIMIT_VERYFAST_08 = 7,
    SAFE_IPC_LIMIT_OVERSPEED = 8,

} SIL;

typedef enum SAFE_MODE
{
    SAFE_MODE_STANDSTLL = 1,
    SAFE_MODE_HAND = 2,
    SAFE_MODE_SCANMAP = 4,
    SAFE_MODE_AUTOMATIC = 8,
    SAFE_MODE_BYPASS = 16,

} SM;
typedef enum SAFE_FIELD
{
    SAFE_FIELD_DEFAULT = 15,
    SAFE_FIELD_POWER = 0,
    SAFE_FIELD_BRACKER = 1,
    SAFE_FIELD_WARNER = 3,
    SAFE_FIELD_DETECTER = 7,
    SAFE_FIELD_COUNTOUR = 31,

} SF;

typedef enum SAFE_SP_AGV
{
    SAFE_SP_AGV_STANDSTILL = 0,
    SAFE_SP_AGV_VERYSLOW = 1,
    SAFE_SP_AGV_SLOW = 2,
    SAFE_SP_AGV_MEDIUM = 3,
    SAFE_SP_AGV_FAST = 4,
    SAFE_SP_AGV_VERYFAST_00 = 5,
    SAFE_SP_AGV_VERYFAST_08 = 6,
    SAFE_SP_AGV_OVERSPEED = 7,

} SSA;

typedef enum SAFE_DIR_AGV
{
    SAFE_DIR_AGV_BASE = 0,
    SAFE_DIR_AGV_WIDE_L = 1,
    SAFE_DIR_AGV_NARRAOW_01_L = 2,
    SAFE_DIR_AGV_WIDE_R = 3,
    SAFE_DIR_AGV_NARROW_1_R = 4,
    SAFE_DIR_AGV_TURN = 5,
    SAFE_DIR_AGV_NARROW_2_L = 6,
    SAFE_DIR_AGV_NARROW_2_R = 7,
    SAFE_DIR_AGV_LOAD_BASE = 8,
    SAFE_DIR_AGV_LOAD_WIDE_L = 9,
    SAFE_DIR_AGV_LOAD_NARRAOW_01_L = 10,
    SAFE_DIR_AGV_LOAD_WIDE_R = 11,
    SAFE_DIR_AGV_LOAD_NARROW_1_R = 12,
    SAFE_DIR_AGV_LOAD_TURN = 13,
    SAFE_DIR_AGV_LOAD_NARROW_2_L = 14,
    SAFE_DIR_AGV_LOAD_NARROW_2_R = 15,

} SDA;

#endif
