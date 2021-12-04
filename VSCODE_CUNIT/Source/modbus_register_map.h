/*******************************************************************************
*
*        (c) COPYRIGHT 2014 Siemens Smart Infrastructure
*
*                         FILE INFORMATION
********************************************************************************
 * @file    modbus_callbacks
 * @brief 
 * @version 
 * @author  8690-1420
 * @date    2021-07-23 
 * @attention  
 * @note  
 *******************************************************************************/
 
#ifndef  MODBUS_REGISTER_MAP_H_ 
#define  MODBUS_REGISTER_MAP_H_  

#include  "para_def.h"
#include  "modbus_callbacks.h"   
#include  "modbus_master_srv.h"
/********************************************************************************
 * Exported macros
 ********************************************************************************/

//02 03 24 ff 00 01 be f9
#define MB_REG_ADDR_OFFSET                                                          (0x0001u) 

#define MB_REG_ADDR_FW_BLT_VER                                                      (0x0040u - MB_REG_ADDR_OFFSET)  
#define MB_REG_ADDR_FW_APP_VER                                                      (0x0045u - MB_REG_ADDR_OFFSET)  
#define MB_REG_ADDR_ATTACHED_DEVICE                                                 (0x006Fu - MB_REG_ADDR_OFFSET) 
#define MB_REG_ADDR_DEVICE_VARIANTS                                                 (0x0070u - MB_REG_ADDR_OFFSET) 
#define MB_REG_ADDR_DATE_TIME_UTC                                                   (0x0400u - MB_REG_ADDR_OFFSET)                                        
#define MB_REG_ADDR_DATE_TIME_SYNC_STATE                                            (0x0433u - MB_REG_ADDR_OFFSET) 
#define MB_REG_ADDR_PROD_LOCK_STATE                                                 (0x0881u - MB_REG_ADDR_OFFSET) 
#define MB_REG_ADDR_ALARM_STATE                                                     (0x0A00u - MB_REG_ADDR_OFFSET)
#define MB_REG_ADDR_MECH_OPERA_CYCLES                                               (0x0A21u - MB_REG_ADDR_OFFSET)
#define MB_REG_ADDR_MECH_OPERA_CYCLES_CFG                                           (0x0A23u - MB_REG_ADDR_OFFSET)
#define MB_REG_ADDR_CNT_TRIP_CYCLES                                                 (0x0A2Au - MB_REG_ADDR_OFFSET)   
#define MB_REG_ADDR_CNT_TRIP_CYCLES_CFG                                             (0x0A2Cu - MB_REG_ADDR_OFFSET) 
#define MB_REG_ADDR_CNT_RCD_TEST                                                    (0x0A4Du - MB_REG_ADDR_OFFSET) 
#define MB_REG_ADDR_CNT_RCD_TEST_CFG                                                (0x0A4Fu - MB_REG_ADDR_OFFSET) 
#define MB_REG_ADDR_PARAM_AUTOMATIC_RECLOSING_DEVICE_STATE                          (0x0A4Au - MB_REG_ADDR_OFFSET) 
#define MB_REG_ADDR_PARAM_RESIDUAL_CURRENT_DEVICE_TEST_STATE                        (0x0A4Bu - MB_REG_ADDR_OFFSET) 
#define MB_REG_ADDR_PARAM_INSULATION_RESISTANCE_TEST_STATE                          (0x0A4Cu - MB_REG_ADDR_OFFSET) 
#define MB_REG_ADDR_TEMPERATURE                                                     (0x0C00u - MB_REG_ADDR_OFFSET) 
#define MB_REG_ADDR_REMOTE_CONTROL_AUXILIARY_MODE_STATE                             (0x0C27u - MB_REG_ADDR_OFFSET) 
#define MB_REG_ADDR_REMOTE_CONTROL_AUXILIARY_HANDLE_STATE                           (0x0C28u - MB_REG_ADDR_OFFSET) 
#define MB_REG_ADDR_CONF_AUTOMATIC_RECLOSING_DEVICE_FIRST_ATTEMPT_TIME_DELAY        (0x0E5Du - MB_REG_ADDR_OFFSET)
#define MB_REG_ADDR_CONF_AUTOMATIC_RECLOSING_DEVICE_SECOND_ATTEMPT_TIME_DELAY       (0x0E5Eu - MB_REG_ADDR_OFFSET)
#define MB_REG_ADDR_CONF_AUTOMATIC_RECLOSING_DEVICE_THIRD_ATTEMPT_TIME_DELAY        (0x0E5Fu - MB_REG_ADDR_OFFSET)
#define MB_REG_ADDR_CONF_AUTOMATIC_RECLOSING_DEVICE_2ND_ATTEMPT_TIME_DELAY          (0x0E60u - MB_REG_ADDR_OFFSET)
#define MB_REG_ADDR_CONF_AUTOMATIC_RECLOSING_DEVICE_CONTROL                         (0x0E61u - MB_REG_ADDR_OFFSET)   
#define MB_REG_ADDR_CONF_INSULATION_RESISTANCE_TEST_CONTROL                         (0x0E62u - MB_REG_ADDR_OFFSET)       
#define MB_REG_ADDR_CONF_RESIDUAL_CURRENT_DEVICE_TEST_CONTROL                       (0x0E63u - MB_REG_ADDR_OFFSET)       
#define MB_REG_ADDR_CONF_RESIDUAL_CURRENT_DEVICE_SELECTIVE_TYPE                     (0x0E64u - MB_REG_ADDR_OFFSET)       
#define MB_REG_ADDR_CONF_AUTO_TEST_START_TIME                                       (0x0E65u - MB_REG_ADDR_OFFSET)       
#define MB_REG_ADDR_CONF_AUTO_TEST_INTERVAL                                         (0x0E67u - MB_REG_ADDR_OFFSET)      
#define MB_REG_ADDR_CMD_REMOTE_CONTROL_AUXILIARY_REMOTE_CONTROL                     (0x0E68u - MB_REG_ADDR_OFFSET)        
#define MB_REG_ADDR_RESIDUAL_CURRENT_DEVICE_SELF_TEST_TRIPPING_TIME                 (0x2500u - MB_REG_ADDR_OFFSET)        
#define MB_REG_ADDR_RESIDUAL_CURRENT_DEVICE_SELF_TEST_TRIPPING_CURRENT              (0x2502u - MB_REG_ADDR_OFFSET)        
#define MB_REG_ADDR_RESIDUAL_CURRENT_DEVICE_TEST_VOLTAGE                            (0x2504u - MB_REG_ADDR_OFFSET)              
#define MB_REG_ADDR_INSULATION_RESISTANCE_TEST_VALUE_N_PE                           (0x2506u - MB_REG_ADDR_OFFSET)                       
#define MB_REG_ADDR_INSULATION_RESISTANCE_TEST_VALUE_L1_PE                          (0x2507u - MB_REG_ADDR_OFFSET)                        
#define MB_REG_ADDR_INSULATION_RESISTANCE_TEST_VALUE_L2_PE                          (0x2508u - MB_REG_ADDR_OFFSET)                        
#define MB_REG_ADDR_INSULATION_RESISTANCE_TEST_VALUE_L3_PE                          (0x2509u - MB_REG_ADDR_OFFSET)                       
#define MB_REG_ADDR_INSULATION_RESISTANCE_TEST_VOLTAGE                              (0x250Au - MB_REG_ADDR_OFFSET)                           
#define MB_REG_ADDR_COM_RCA_MCU_RESET_INFO                                          (0x250Cu - MB_REG_ADDR_OFFSET)                        
#define MB_REG_ADDR_COM_RCA_LED_CURRENT_STATUS                                      (0x2512u - MB_REG_ADDR_OFFSET) 
#define MB_REG_ADDR_CMD_RCA_HOST_MCU_EVENT_HAPPENED                                 (0x2513u - MB_REG_ADDR_OFFSET)

#define MODBUS_REGISTER_MAP_CONTENT \
{ &u8_arrayIdentFwVerBot      , (uint8_t)sizeof(u8_arrayIdentFwVerBot),      MB_REG_ADDR_FW_BLT_VER                                                , WRITE_ONLY,  MODBUS_DEFUALT_VALUE_UNDEF,                MODBUS_NONE_TOKEN_ID,     MODBUS_NONE_CALLBACK, MODBUS_NONE_CALLBACK},\
{ &u8_arrayIdentFwVerApp      , (uint8_t)sizeof(u8_arrayIdentFwVerApp),      MB_REG_ADDR_FW_APP_VER                                                , WRITE_ONLY,  MODBUS_DEFUALT_VALUE_UNDEF,                MODBUS_NONE_TOKEN_ID,     MODBUS_NONE_CALLBACK, MODBUS_NONE_CALLBACK},\
{ &u16_identAttachedDevice    , (uint8_t)sizeof(u16_identAttachedDevice),    MB_REG_ADDR_ATTACHED_DEVICE                                           , READ_ONLY,   DEF_ATTACHED_DEVICE_UNKNOW,                "identAttachedDevice",    MODBUS_NONE_CALLBACK, MODBUS_NONE_CALLBACK},\
{ &u16_identDeviceVariant     , (uint8_t)sizeof(u16_identDeviceVariant),     MB_REG_ADDR_DEVICE_VARIANTS                                           , READ_ONLY,   DEF_DEVICE_VARIANT_RCA_ENCHANCE,           "identDeviceVariant",     MODBUS_NONE_CALLBACK, MODBUS_NONE_CALLBACK},\
{ &u32_dateTimeUtc            , (uint8_t)sizeof(u32_dateTimeUtc),            MB_REG_ADDR_DATE_TIME_UTC                                             , READ_WRITE,  MODBUS_DEFUALT_VALUE_UNDEF,                MODBUS_NONE_TOKEN_ID,     MODBUS_NONE_CALLBACK, MODBUS_NONE_CALLBACK},\
{ &u16_dateTimeSynSta         , (uint8_t)sizeof(u16_dateTimeSynSta ),        MB_REG_ADDR_DATE_TIME_SYNC_STATE                                      , READ_ONLY,   MODBUS_DEFUALT_VALUE_UNDEF,                MODBUS_NONE_TOKEN_ID,     MODBUS_NONE_CALLBACK, MODBUS_NONE_CALLBACK},\
{ &u16_productionLockSta      , (uint8_t)sizeof(u16_productionLockSta),      MB_REG_ADDR_PROD_LOCK_STATE                                           , READ_ONLY,   DEF_PRODUCTION_UNLOCKED,                   "productionLockSta",      MODBUS_NONE_CALLBACK, MODBUS_NONE_CALLBACK},\
{ &u32_alarmSta               , (uint8_t)sizeof(u32_alarmSta),               MB_REG_ADDR_ALARM_STATE                                               , READ_WRITE,  MODBUS_DEFUALT_VALUE_UNDEF,                MODBUS_NONE_TOKEN_ID,     MODBUS_NONE_CALLBACK, MODBUS_NONE_CALLBACK},\
{ &u32_mechOperaCycles        , (uint8_t)sizeof(u32_mechOperaCycles),        MB_REG_ADDR_MECH_OPERA_CYCLES                                         , READ_WRITE,  DEF_COUNTER_VALUE_DEFAULT,                 "mechOperaCycles",        MODBUS_NONE_CALLBACK, MODBUS_NONE_CALLBACK},\
{ &u16_mechOperaCyclesCfg     , (uint8_t)sizeof(u16_mechOperaCyclesCfg),     MB_REG_ADDR_MECH_OPERA_CYCLES_CFG                                     , READ_ONLY,   DEF_COUNTER_ENABLED,                       "mechOperaCyclesCfg",     MODBUS_NONE_CALLBACK, MODBUS_NONE_CALLBACK},\
{ &u32_cntTripCycles          , (uint8_t)sizeof(u32_cntTripCycles),          MB_REG_ADDR_CNT_TRIP_CYCLES                                           , READ_WRITE,  DEF_COUNTER_VALUE_DEFAULT,                 "cntTripCycles",          MODBUS_NONE_CALLBACK, MODBUS_NONE_CALLBACK},\
{ &u16_cntTripCyclesCfg       , (uint8_t)sizeof(u16_cntTripCyclesCfg),       MB_REG_ADDR_CNT_TRIP_CYCLES_CFG                                       , READ_ONLY,   DEF_COUNTER_ENABLED,                       "cntTripCyclesCfg",       MODBUS_NONE_CALLBACK, MODBUS_NONE_CALLBACK},\
{ &u32_cntRcdTestCycles       , (uint8_t)sizeof(u32_cntRcdTestCycles),       MB_REG_ADDR_CNT_RCD_TEST                                              , READ_WRITE,  DEF_COUNTER_VALUE_DEFAULT,                 "cntRcdTestCycles",       MODBUS_NONE_CALLBACK, MODBUS_NONE_CALLBACK},\
{ &u16_cntRcdTestCyclesCfg    , (uint8_t)sizeof(u16_cntRcdTestCyclesCfg),    MB_REG_ADDR_CNT_RCD_TEST_CFG                                          , READ_ONLY,   DEF_COUNTER_ENABLED,                       "cntRcdTestCyclesCfg",    MODBUS_NONE_CALLBACK, MODBUS_NONE_CALLBACK},\
{ &u16_ardState               , (uint8_t)sizeof(u16_ardState),               MB_REG_ADDR_PARAM_AUTOMATIC_RECLOSING_DEVICE_STATE                    , WRITE_ONLY,  DEF_ARD_STATE_OK,                          "ardState",               MODBUS_NONE_CALLBACK, MODBUS_NONE_CALLBACK},\
{ &u16_rcdTestState           , (uint8_t)sizeof(u16_rcdTestState),           MB_REG_ADDR_PARAM_RESIDUAL_CURRENT_DEVICE_TEST_STATE                  , WRITE_ONLY,  DEF_RCD_STATE_UNKNOW,                      "rcdTestState",           MODBUS_NONE_CALLBACK, MODBUS_NONE_CALLBACK},\
{ &u16_irTestState            , (uint8_t)sizeof(u16_irTestState),            MB_REG_ADDR_PARAM_INSULATION_RESISTANCE_TEST_STATE                    , WRITE_ONLY,  DEF_IR_STATE_UNKNOW,                       "irTestState" ,           MODBUS_NONE_CALLBACK, MODBUS_NONE_CALLBACK},\
{ &u32_temperature            , (uint8_t)sizeof(u32_temperature),            MB_REG_ADDR_TEMPERATURE                                               , READ_ONLY,   MODBUS_DEFUALT_VALUE_UNDEF,                MODBUS_NONE_TOKEN_ID,     MODBUS_NONE_CALLBACK, MODBUS_NONE_CALLBACK},\
{ &u16_rcaModeState           , (uint8_t)sizeof(u16_rcaModeState),           MB_REG_ADDR_REMOTE_CONTROL_AUXILIARY_MODE_STATE                       , WRITE_ONLY,  DEF_MODE_SW_STATUS_UNKNOWN,                "rcaModeState",           MODBUS_NONE_CALLBACK, MODBUS_NONE_CALLBACK},\
{ &u16_rcaHandleState         , (uint8_t)sizeof(u16_rcaHandleState),         MB_REG_ADDR_REMOTE_CONTROL_AUXILIARY_HANDLE_STATE                     , WRITE_ONLY,  DEF_HANDLE_STATUS_UNKNOWN,                 "rcaHandleState",         MODBUS_NONE_CALLBACK, MODBUS_NONE_CALLBACK},\
{ &u16_cfgArdFirstDelayTime   , (uint8_t)sizeof(u16_cfgArdFirstDelayTime),   MB_REG_ADDR_CONF_AUTOMATIC_RECLOSING_DEVICE_FIRST_ATTEMPT_TIME_DELAY  , READ_ONLY,   DEF_CFG_DEFAULT_FIRST_ATTEMPT_TIME_DELAY,  "cfgArdFirstDelayTime",   MODBUS_NONE_CALLBACK, MODBUS_NONE_CALLBACK},\
{ &u16_cfgASecondDelayTime    , (uint8_t)sizeof(u16_cfgASecondDelayTime),    MB_REG_ADDR_CONF_AUTOMATIC_RECLOSING_DEVICE_SECOND_ATTEMPT_TIME_DELAY , READ_ONLY,   DEF_CFG_DEFAULT_SECOND_ATTEMPT_TIME_DELAY, "cfgASecondDelayTime",    MODBUS_NONE_CALLBACK, MODBUS_NONE_CALLBACK},\
{ &u16_cfgAThirdDelayTime     , (uint8_t)sizeof(u16_cfgAThirdDelayTime),     MB_REG_ADDR_CONF_AUTOMATIC_RECLOSING_DEVICE_THIRD_ATTEMPT_TIME_DELAY  , READ_ONLY,   DEF_CFG_DEFAULT_THIRD_ATTEMPT_TIME_DELAY,  "cfgAThirdDelayTime",     MODBUS_NONE_CALLBACK, MODBUS_NONE_CALLBACK},\
{ &u16_cfg2ndAttemptDelayTime , (uint8_t)sizeof(u16_cfg2ndAttemptDelayTime), MB_REG_ADDR_CONF_AUTOMATIC_RECLOSING_DEVICE_2ND_ATTEMPT_TIME_DELAY    , READ_ONLY,   DEF_CFG_DEFAULT_2ND_ATTEMPT_DISABLE,       "cfg2ndAttemptDelayTime", MODBUS_NONE_CALLBACK, MODBUS_NONE_CALLBACK},\
{ &u16_cfgArdCtrl             , (uint8_t)sizeof(u16_cfgArdCtrl ),            MB_REG_ADDR_CONF_AUTOMATIC_RECLOSING_DEVICE_CONTROL                   , READ_ONLY,   DEF_CFG_ARD_DISABLED,                      "cfgArdCtrl",             MODBUS_NONE_CALLBACK, MODBUS_NONE_CALLBACK},\
{ &u16_cfgIrCtrl              , (uint8_t)sizeof(u16_cfgIrCtrl),              MB_REG_ADDR_CONF_INSULATION_RESISTANCE_TEST_CONTROL                   , READ_ONLY,   DEF_CFG_IR_DISABLED,                       "cfgIrCtrl",              MODBUS_NONE_CALLBACK, MODBUS_NONE_CALLBACK},\
{ &u16_cfgRcdCtrl             , (uint8_t)sizeof(u16_cfgRcdCtrl),             MB_REG_ADDR_CONF_RESIDUAL_CURRENT_DEVICE_TEST_CONTROL                 , READ_ONLY,   DEF_CFG_RCD_DISABLED,                      "cfgRcdCtrl",             MODBUS_NONE_CALLBACK, MODBUS_NONE_CALLBACK},\
{ &u16_cfgRcdSelectiveType    , (uint8_t)sizeof(u16_cfgRcdSelectiveType),    MB_REG_ADDR_CONF_RESIDUAL_CURRENT_DEVICE_SELECTIVE_TYPE               , READ_ONLY,   DEF_CFG_RCD_NO_SELECTIVE_TYPE,             "cfgRcdSelectiveType",    MODBUS_NONE_CALLBACK, MODBUS_NONE_CALLBACK},\
{ &u32_cfgAutoTestStartUtc    , (uint8_t)sizeof(u32_cfgAutoTestStartUtc),    MB_REG_ADDR_CONF_AUTO_TEST_START_TIME                                 , READ_ONLY,   DEF_TIME_DEFAULT,                          "cfgAutoTestStartUtc",    MODBUS_NONE_CALLBACK, MODBUS_NONE_CALLBACK},\
{ &u16_cfgAutoTestInterval    , (uint8_t)sizeof(u16_cfgAutoTestInterval),    MB_REG_ADDR_CONF_AUTO_TEST_INTERVAL                                   , READ_ONLY,   DEF_AUTO_TEST_INTERVAL_NEVER,              "cfgAutoTestInterval",    MODBUS_NONE_CALLBACK, MODBUS_NONE_CALLBACK},\
{ &u16_cmdRcaRemoteCtrl       , (uint8_t)sizeof(u16_cmdRcaRemoteCtrl),       MB_REG_ADDR_CMD_REMOTE_CONTROL_AUXILIARY_REMOTE_CONTROL               , READ_WRITE,  MODBUS_DEFUALT_VALUE_UNDEF,                MODBUS_NONE_TOKEN_ID,     MODBUS_NONE_CALLBACK, MODBUS_NONE_CALLBACK},\
{ &u32_rcdTestTripTime        , (uint8_t)sizeof(u32_rcdTestTripTime),        MB_REG_ADDR_RESIDUAL_CURRENT_DEVICE_SELF_TEST_TRIPPING_TIME           , WRITE_ONLY,  MODBUS_DEFUALT_VALUE_UNDEF,                MODBUS_NONE_TOKEN_ID,     MODBUS_NONE_CALLBACK, MODBUS_NONE_CALLBACK},\
{ &u32_rcdTestTripCurrent     , (uint8_t)sizeof(u32_rcdTestTripCurrent),     MB_REG_ADDR_RESIDUAL_CURRENT_DEVICE_SELF_TEST_TRIPPING_CURRENT        , WRITE_ONLY,  MODBUS_DEFUALT_VALUE_UNDEF,                MODBUS_NONE_TOKEN_ID,     MODBUS_NONE_CALLBACK, MODBUS_NONE_CALLBACK},\
{ &u32_rcdTestVoltage         , (uint8_t)sizeof(u32_rcdTestVoltage),         MB_REG_ADDR_RESIDUAL_CURRENT_DEVICE_TEST_VOLTAGE                      , WRITE_ONLY,  MODBUS_DEFUALT_VALUE_UNDEF,                MODBUS_NONE_TOKEN_ID,     MODBUS_NONE_CALLBACK, MODBUS_NONE_CALLBACK},\
{ &u16_resistanceNtoPe        , (uint8_t)sizeof(u16_resistanceNtoPe),        MB_REG_ADDR_INSULATION_RESISTANCE_TEST_VALUE_N_PE                     , WRITE_ONLY,  MODBUS_DEFUALT_VALUE_UNDEF,                MODBUS_NONE_TOKEN_ID,     MODBUS_NONE_CALLBACK, MODBUS_NONE_CALLBACK},\
{ &u16_resistanceL1toPe       , (uint8_t)sizeof(u16_resistanceL1toPe),       MB_REG_ADDR_INSULATION_RESISTANCE_TEST_VALUE_L1_PE                    , WRITE_ONLY,  MODBUS_DEFUALT_VALUE_UNDEF,                MODBUS_NONE_TOKEN_ID,     MODBUS_NONE_CALLBACK, MODBUS_NONE_CALLBACK},\
{ &u16_resistanceL2toPe       , (uint8_t)sizeof(u16_resistanceL2toPe),       MB_REG_ADDR_INSULATION_RESISTANCE_TEST_VALUE_L2_PE                    , WRITE_ONLY,  MODBUS_DEFUALT_VALUE_UNDEF,                MODBUS_NONE_TOKEN_ID,     MODBUS_NONE_CALLBACK, MODBUS_NONE_CALLBACK},\
{ &u16_resistanceL3toPe       , (uint8_t)sizeof(u16_resistanceL3toPe),       MB_REG_ADDR_INSULATION_RESISTANCE_TEST_VALUE_L3_PE                    , WRITE_ONLY,  MODBUS_DEFUALT_VALUE_UNDEF,                MODBUS_NONE_TOKEN_ID,     MODBUS_NONE_CALLBACK, MODBUS_NONE_CALLBACK},\
{ &u32_irTestVoltage          , (uint8_t)sizeof(u32_irTestVoltage),          MB_REG_ADDR_INSULATION_RESISTANCE_TEST_VOLTAGE                        , WRITE_ONLY,  MODBUS_DEFUALT_VALUE_UNDEF,                MODBUS_NONE_TOKEN_ID,     MODBUS_NONE_CALLBACK, MODBUS_NONE_CALLBACK},\
{ u8_arrayRcaResetInfo        , (uint8_t)sizeof(u8_arrayRcaResetInfo),       MB_REG_ADDR_COM_RCA_MCU_RESET_INFO                                    , READ_WRITE,  MODBUS_DEFUALT_VALUE_UNDEF,                MODBUS_NONE_TOKEN_ID,     MODBUS_NONE_CALLBACK, MODBUS_NONE_CALLBACK},\
{ &u16_commLedCurrentState    , (uint8_t)sizeof(u16_commLedCurrentState),    MB_REG_ADDR_COM_RCA_LED_CURRENT_STATUS                                , READ_ONLY,   DEF_LED_INIT_STATE,                        "commLedCurrentState",    MODBUS_NONE_CALLBACK, MODBUS_NONE_CALLBACK},\
{ &u16_cmdRcaNewEventHappened , (uint8_t)sizeof(u16_cmdRcaNewEventHappened), MB_REG_ADDR_CMD_RCA_HOST_MCU_EVENT_HAPPENED                           , READ_ONLY,   MODBUS_DEFUALT_VALUE_UNDEF,                MODBUS_NONE_TOKEN_ID,     MODBUS_NONE_CALLBACK, MODBUS_NONE_CALLBACK},\
{ NULL                        , (uint8_t)0u,                                 MODBUS_REGISTER_END_TAG                                               , READ_ONLY,   MODBUS_DEFUALT_VALUE_UNDEF,                MODBUS_NONE_TOKEN_ID,     MODBUS_NONE_CALLBACK, MODBUS_NONE_CALLBACK}

/********************************************************************************
 * Exported typedefs 
 *******************************************************************************/



/********************************************************************************
 * Exported variables
 ********************************************************************************/



/*********************************************************************************
 * Exported functions
 ********************************************************************************/
 

/*********************************************************************************
 *inline functions 
 ********************************************************************************/




#endif    /*MODBUS_CALLBACKS_H_*/

/*****************************************************************************************
 *End of file 
 ****************************************************************************************/