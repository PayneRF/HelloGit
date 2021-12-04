/*******************************************************************************
*
*        (c) COPYRIGHT 2014 Siemens Smart Infrastructure
*
*                         FILE INFORMATION
********************************************************************************
 * @file    para_def
 * @brief 
 * @version 
 * @author  8690-1420
 * @date    2021-04-25 
 * @attention  
 * @note  
 *******************************************************************************/
 
#ifndef  PARA_DEF_H_ 
#define  PARA_DEF_H_ 
#include <stdint.h>
/********************************************************************************
 * Exported macros
 ********************************************************************************/
#define EF_MEM_TOKEN_INITIALIZED                        ((uint16_t)0x5aa5u) 
   
#define DEF_ATTACHED_DEVICE_UNKNOW                      (0u)
#define DEF_ATTACHED_DEVICE_RCD                         (1u)
#define DEF_ATTACHED_DEVICE_MCB                         (2u)
#define DEF_ATTACHED_DEVICE_SCD                         (3u)
#define DEF_ATTACHED_DEVICE_AFD                         (4u)
#define DEF_ATTACHED_DEVICE_RCBO                        (5u)
                                                        
#define DEF_DEVICE_VARIANT_RCA_ITALY                    (0xffu)//TBD
#define DEF_DEVICE_VARIANT_RCA_STANDARD                 (5u)
#define DEF_DEVICE_VARIANT_RCA_ENCHANCE                 (6u)
                                                        
#define DEF_TIME_DEFAULT                                (946681200UL)
#define DEF_TIME_SYNC_DEFAULT                           (0u)
#define DEF_TIME_SYNCHRONIZED                           (1u)
#define DEF_TIME_NOT_SYNCHRONIZED                       (2u)
                                                        
#define DEF_PRODUCTION_UNLOCKED                         (0u)
#define DEF_PRODUCTION_LOCKED                           (1u)
#define DEF_PRODUCTION_UNKNOW                           (65535u)
                                                        
#define DEF_COUNTER_VALUE_DEFAULT                       (0u)
#define DEF_COUNTER_ENABLED                             (1u)
#define DEF_COUNTER_DISABLED                            (0u)
                                                        
#define DEF_ARD_STATE_OK                                (0u)
#define DEF_ARD_STATE_IR_ERR_LOCK                       (1u)
#define DEF_ARD_STATE_EXHAUST_LOCK                      (2u)
#define DEF_ARD_STATE_RETRY_LOCK                        (3u)

#define DEF_RCD_STATE_UNKNOW                            (0u)
#define DEF_RCD_STATE_TEST_PASSED                       (1u)
#define DEF_RCD_STATE_TEST_FAILED_BY_MPD_NOT_TRIP       (2u)
#define DEF_RCD_STATE_TEST_FAILED_BY_TRIP_TIME          (3u)
#define DEF_RCD_STATE_TEST_FAILED_BY_CFG                (4u)
#define DEF_RCD_STATE_TEST_FAILED_BY_HANDLE_STATE       (5u)
#define DEF_RCD_STATE_TEST_FAILED_BY_MODE_SWITCH_STATE  (6u)
#define DEF_RCD_STATE_TEST_FAILED_BY_TRIP_ARM_STATE     (7u)
#define DEF_RCD_STATE_TEST_FAILED_BY_HW_FAULT           (8u)
 
#define DEF_IR_STATE_UNKNOW                            (0u) 
#define DEF_IR_STATE_RCD_TRIP_TEST_PASSED              (1u) 
#define DEF_IR_STATE_INDV_TEST_PASSED                  (2u)
#define DEF_IR_STATE_TEST_RESIS_ERROR                  (3u)
#define DEF_IR_STATE_TEST_RESIS_WARNING                (4u)
#define DEF_IR_STATE_TEST_FAILED_BY_CFG                (5u)
#define DEF_IR_STATE_TEST_FAILED_BY_HANDLE_STATE       (6u)
#define DEF_IR_STATE_TEST_FAILED_BY_MODE_SWITCH_STATE  (7u)
#define DEF_IR_STATE_TEST_FAILED_BY_L_N_REVERSED       (8u)
#define DEF_IR_STATE_TEST_FAILED_BY_CROSS_ZERO_DET     (9u)


#define DEF_MODE_SW_STATUS_UNKNOWN                     (0u)
#define DEF_MODE_SW_STATUS_LOCK                        (1u)
#define DEF_MODE_SW_STATUS_RCOFF                       (2u)
#define DEF_MODE_SW_STATUS_RCON                        (3u)
                                                       
#define DEF_HANDLE_STATUS_UNKNOWN                      (0u)
#define DEF_HANDLE_STATUS_MANUAL_OFF                   (1u)
#define DEF_HANDLE_STATUS_MANUAL_ON                    (2u)
#define DEF_HANDLE_STATUS_RST_MOFF                     (3u)
#define DEF_HANDLE_STATUS_REMOTE_ON                    (4u)
#define DEF_HANDLE_STATUS_REMOTE_OFF                   (5u)
#define DEF_HANDLE_STATUS_ARD_ON                       (6u)
#define DEF_HANDLE_STATUS_TRIP_OFF                     (7u)
                                                       
#define DEF_CMD_NULL                                   (0u)
#define DEF_CMD_COMM_ON                                (1u)
#define DEF_CMD_COMM_OFF                               (2u)
#define DEF_CMD_COMM_RCD_TEST                          (3u)
#define DEF_CMD_COMM_IR_TEST                           (4u)
#define DEF_CMD_COMM_RST_MOFF                          (5u)
#define DEF_CMD_COMM_PROD_RST                          (6u)
#define DEF_CMD_ELEC_ON                                (7u)
#define DEF_CMD_ELEC_OFF                               (8u)
#define DEF_CMD_ELEC_RCD_TEST                          (9u)
#define DEF_CMD_ELEC_IR_TEST                           (10u)
#define DEF_CMD_ELEC_RST_MOFF                          (11u)
                                                       
#define DEF_CMD_COMM_WRITE_NULL                        (0u)
#define DEF_CMD_COMM_WRITE_ON                          (1u)
#define DEF_CMD_COMM_WRITE_OFF                         (2u)
#define DEF_CMD_COMM_WRITE_RCD_TEST                    (3u)
#define DEF_CMD_COMM_WRITE_IR_TEST                     (4u)
#define DEF_CMD_COMM_WRITE_RST_MOFF                    (5u)
#define DEF_CMD_COMM_WRITE_PROD_RST                    (6u)
#define DEF_CMD_COMM_WRITE_ENDING                      (DEF_CMD_COMM_WRITE_PROD_RST)
 
//////#define DEF_CMD_STATE_IDLE                       (0u)
//////#define DEF_CMD_STATE_IN_PROGRESS                (1u)
//////#define DEF_CMD_STATE_SUCCESS                    (2u)
//////#define DEF_CMD_STATE_FAILURE                    (3u)
 
#define DEF_CFG_ARD_MIN_DELAY_TIME                     (10u)  
#define DEF_CFG_ARD_MAX_DELAY_TIME                     (1800u)   
#define DEF_CFG_DEFAULT_FIRST_ATTEMPT_TIME_DELAY       (10u) 
#define DEF_CFG_DEFAULT_SECOND_ATTEMPT_TIME_DELAY      (60u) 
#define DEF_CFG_DEFAULT_THIRD_ATTEMPT_TIME_DELAY       (600u) 
#define DEF_CFG_DEFAULT_2ND_ATTEMPT_TIME_DELAY         (0u) 
#define DEF_CFG_DEFAULT_2ND_ATTEMPT_DISABLE            (DEF_CFG_DEFAULT_2ND_ATTEMPT_TIME_DELAY)
                                                       
#define DEF_CFG_ARD_DISABLED                           (0u)
#define DEF_CFG_ARD_DISABLED_AFTER_IR_WARNING          (1u)
#define DEF_CFG_ARD_ENABLED_AFTER_IR_WARNING           (2u)
                                                       
#define DEF_CFG_IR_DISABLED                            (0u)
#define DEF_CFG_IR_ENABLED_WITH_1POLE                  (1u)
#define DEF_CFG_IR_ENABLED_WITH_3POLE                  (2u)
                                                       
#define DEF_CFG_RCD_DISABLED                           (0u)
#define DEF_CFG_RCD_30MA_8KOM                          (1u)
#define DEF_CFG_RCD_30MA_12KOM                         (2u)
#define DEF_CFG_RCD_30MA_16KOM                         (3u)
#define DEF_CFG_RCD_100MA_2_5KOM                       (4u)
#define DEF_CFG_RCD_100MA_5KOM                         (5u)
#define DEF_CFG_RCD_100MA_8KOM                         (6u)
#define DEF_CFG_RCD_300MA_2_5KOM                       (7u)
#define DEF_CFG_RCD_300MA_5KOM                         (8u)
#define DEF_CFG_RCD_300MA_8KOM                         (9u)

#define DEF_CFG_RCD_NO_SELECTIVE_TYPE                  (0u)
#define DEF_CFG_RCD_SELECTIVE_TYPE                     (1u)

#define DEF_AUTO_TEST_INTERVAL_NEVER                   (0u)
#define DEF_AUTO_TEST_INTERVAL_ONCE                    (1u)  //ERROR need modify datapoint
#define DEF_AUTO_TEST_INTERVAL_1HOUR                   (2u)
#define DEF_AUTO_TEST_INTERVAL_2HOURS                  (3u)
#define DEF_AUTO_TEST_INTERVAL_4HOURS                  (4u)
#define DEF_AUTO_TEST_INTERVAL_8HOURS                  (5u)
#define DEF_AUTO_TEST_INTERVAL_12HOURS                 (6u)
#define DEF_AUTO_TEST_INTERVAL_24HOURS                 (7u)
#define DEF_AUTO_TEST_INTERVAL_7DAYS                   (8u)
#define DEF_AUTO_TEST_INTERVAL_14DAYS                  (9u)
#define DEF_AUTO_TEST_INTERVAL_30DAYS                  (10u)
#define DEF_AUTO_TEST_INTERVAL_60DAYS                  (11u)
#define DEF_AUTO_TEST_INTERVAL_90DAYS                  (12u)
#define DEF_AUTO_TEST_INTERVAL_180DAYS                 (13u)
 
#define DEF_CMD_NO_ACTION                      (0u)
#define DEF_CMD_REMOTE_COM_ON                  (1u)
#define DEF_CMD_REMOTE_COM_OFF                 (2u)
#define DEF_CMD_REMOTE_COM_RCD_TEST            (3u)
#define DEF_CMD_REMOTE_COM_IR_TEST             (4u)
#define DEF_CMD_REMOTE_COM_RESET_MOFF          (5u)
#define DEF_CMD_REMOTE_COM_RESET_MCU           (6u)

#define DEF_LED_INIT_STATE                     (1u)
//Format "V10000001"; should be displayed as "V1.0.0.0_0.0.0.1"
#define VERSIONINFO_VER_TYPE                           ('D')
#define VERSIONINFO_MAJOR_VER                          (01)
#define VERSIONINFO_MINOR_VER                          (00)
#define VERSIONINFO_UPDATE_CNT                         (00)
#define VERSIONINFO_PATCH_CNT                          (00)
#define VERSIONINFO_FEAT_INC                           (31)
#define VERSIONINFO_SYS_CNT                            (02)
#define VERSIONINFO_RESERVE                            (00)
#define VERSIONINFO_BUILD_CNT                          (02)   
/********************************************************************************
 * Exported typedefs 
 *******************************************************************************/
 
/********************************************************************************
 * Exported variables
 ********************************************************************************/
extern uint16_t u16_flashInitToken;
extern uint8_t u8_arrayIdentFwVerBot[10];
extern uint8_t  u8_arrayIdentFwVerApp[10];
extern uint16_t u16_identAttachedDevice;
extern uint16_t u16_identDeviceVariant;
extern uint32_t u32_dateTimeUtc;
extern uint16_t u16_dateTimeSynSta;
extern uint16_t u16_productionLockSta;
extern uint32_t u32_alarmSta;
extern uint32_t u32_mechOperaCycles;
extern uint16_t u16_mechOperaCyclesCfg;
extern uint32_t u32_cntTripCycles;
extern uint16_t u16_cntTripCyclesCfg;
extern uint32_t u32_cntRcdTestCycles;
extern uint16_t u16_cntRcdTestCyclesCfg;
extern uint16_t u16_ardState;
extern uint16_t u16_rcdTestState;
extern uint16_t u16_irTestState;
extern uint32_t u32_temperature;
extern uint16_t u16_rcaModeState;
extern uint16_t u16_rcaHandleState;
extern uint16_t u16_cfgArdFirstDelayTime;
extern uint16_t u16_cfgASecondDelayTime;
extern uint16_t u16_cfgAThirdDelayTime;
extern uint16_t u16_cfg2ndAttemptDelayTime;
extern uint16_t u16_cfgArdCtrl;
extern uint16_t u16_cfgIrCtrl;
extern uint16_t u16_cfgRcdCtrl;
extern uint16_t u16_cfgRcdSelectiveType;
extern uint32_t u32_cfgAutoTestStartUtc;
extern uint16_t u16_cfgAutoTestInterval;
extern uint16_t u16_cmdRcaRemoteCtrl;
extern uint32_t u32_rcdTestTripTime;
extern uint32_t u32_rcdTestTripCurrent;
extern uint32_t u32_rcdTestVoltage;
extern uint16_t u16_resistanceNtoPe;
extern uint16_t u16_resistanceL1toPe;
extern uint16_t u16_resistanceL2toPe;
extern uint16_t u16_resistanceL3toPe;
extern uint32_t u32_irTestVoltage;
extern uint8_t  u8_arrayRcaResetInfo[12];						
extern uint16_t u16_commLedCurrentState;
extern uint16_t u16_cmdRcaNewEventHappened;

/*********************************************************************************
 * Exported functions
 ********************************************************************************/
uint16_t PARA_GetCommLedCurrentStateValue(void);


/*********************************************************************************
 *inline functions 
 ********************************************************************************/




#endif    /*PARA_DEF_H_*/

/*****************************************************************************************
 *End of file 
 ****************************************************************************************/