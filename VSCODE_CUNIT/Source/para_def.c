/******************************************************************************
*
*        (c) COPYRIGHT 2014 Siemens Smart Infrastructure 
*
*                         FILE INFORMATION
*******************************************************************************
 * @file    para_def
 * @brief 
 * @version 
 * @author  8690-1420
 * @date    2021-04-25 
 * @attention  
 * @note  
 ******************************************************************************/


/*******************************************************************************
 * header includes 
 *******************************************************************************/
#include  "para_def.h"
/*******************************************************************************
 *Local  marco
 *******************************************************************************/


/*******************************************************************************
 *Local  typedef 
 *******************************************************************************/


/*******************************************************************************
 *external function and variable(optional)
 *******************************************************************************/
static void DEF_ParameterProdInit(void);

/*******************************************************************************
 *Local functions declaration
 ******************************************************************************/


/*******************************************************************************
 * global  variable 
 *******************************************************************************/

uint16_t u16_flashInitToken = 0u;//Indicate flash has been init

uint8_t u8_arrayIdentFwVerBot[10] = {
  VERSIONINFO_VER_TYPE,
  VERSIONINFO_MAJOR_VER,
  VERSIONINFO_MINOR_VER,
  VERSIONINFO_UPDATE_CNT,
  VERSIONINFO_PATCH_CNT,
  VERSIONINFO_FEAT_INC,
  VERSIONINFO_SYS_CNT,
  VERSIONINFO_RESERVE,
  VERSIONINFO_BUILD_CNT,
  0xFFu
}; 
uint8_t  u8_arrayIdentFwVerApp[10] = {
  VERSIONINFO_VER_TYPE,
  VERSIONINFO_MAJOR_VER,
  VERSIONINFO_MINOR_VER,
  VERSIONINFO_UPDATE_CNT,
  VERSIONINFO_PATCH_CNT,
  VERSIONINFO_FEAT_INC,
  VERSIONINFO_SYS_CNT,
  VERSIONINFO_RESERVE,
  VERSIONINFO_BUILD_CNT,
  0xFFu
};   
uint16_t u16_identAttachedDevice = DEF_ATTACHED_DEVICE_UNKNOW;   
uint16_t u16_identDeviceVariant = DEF_DEVICE_VARIANT_RCA_ENCHANCE;
uint32_t u32_dateTimeUtc = DEF_TIME_DEFAULT;
uint16_t u16_dateTimeSynSta = DEF_TIME_SYNC_DEFAULT;   
uint16_t u16_productionLockSta = DEF_PRODUCTION_UNLOCKED;     
uint32_t u32_alarmSta;
uint32_t u32_mechOperaCycles = DEF_COUNTER_VALUE_DEFAULT;
uint16_t u16_mechOperaCyclesCfg=DEF_COUNTER_ENABLED;
uint32_t u32_cntTripCycles = DEF_COUNTER_VALUE_DEFAULT;
uint16_t u16_cntTripCyclesCfg=DEF_COUNTER_ENABLED;
uint32_t u32_cntRcdTestCycles=DEF_COUNTER_VALUE_DEFAULT;
uint16_t u16_cntRcdTestCyclesCfg=DEF_COUNTER_ENABLED;
uint16_t u16_ardState = DEF_ARD_STATE_OK;
uint16_t u16_rcdTestState = DEF_RCD_STATE_UNKNOW;
uint16_t u16_irTestState = DEF_IR_STATE_UNKNOW;
uint32_t u32_temperature = 0;
uint16_t u16_rcaModeState = DEF_MODE_SW_STATUS_UNKNOWN; 
uint16_t u16_rcaHandleState = DEF_HANDLE_STATUS_UNKNOWN;
 
uint16_t u16_cfgArdFirstDelayTime = DEF_CFG_DEFAULT_FIRST_ATTEMPT_TIME_DELAY;
uint16_t u16_cfgASecondDelayTime = DEF_CFG_DEFAULT_SECOND_ATTEMPT_TIME_DELAY;
uint16_t u16_cfgAThirdDelayTime = DEF_CFG_DEFAULT_THIRD_ATTEMPT_TIME_DELAY;
uint16_t u16_cfg2ndAttemptDelayTime = DEF_CFG_DEFAULT_2ND_ATTEMPT_DISABLE;

uint16_t u16_cfgArdCtrl = DEF_CFG_ARD_DISABLED;
uint16_t u16_cfgIrCtrl = DEF_CFG_IR_DISABLED;
uint16_t u16_cfgRcdCtrl = DEF_CFG_RCD_DISABLED; 

uint16_t u16_cfgRcdSelectiveType = DEF_CFG_RCD_NO_SELECTIVE_TYPE;

uint32_t u32_cfgAutoTestStartUtc = 0u;
uint16_t u16_cfgAutoTestInterval = DEF_AUTO_TEST_INTERVAL_NEVER;
uint16_t u16_cmdRcaRemoteCtrl = DEF_CMD_NO_ACTION;
uint32_t u32_rcdTestTripTime = 0xffffffff;
uint32_t u32_rcdTestTripCurrent = 0u;
uint32_t u32_rcdTestVoltage = 0u;
uint16_t u16_resistanceNtoPe = 0u;
uint16_t u16_resistanceL1toPe = 0u;
uint16_t u16_resistanceL2toPe = 0u;
uint16_t u16_resistanceL3toPe = 0u;
uint32_t u32_irTestVoltage = 0u;
uint8_t  u8_arrayRcaResetInfo[12] = {0};						
uint16_t u16_commLedCurrentState = 2u;//no network
uint16_t u16_cmdRcaNewEventHappened = 0u;

/*******************************************************************************
 *Local  variable
 *******************************************************************************/


/*******************************************************************************
 *Public  functions 
 ******************************************************************************/
uint16_t PARA_GetCommLedCurrentStateValue(void)
{
  return u16_commLedCurrentState;
}
 
/**
******************************************************************************************     
*  @brief       
******************************************************************************************
*  @param       
*  @param       
*  @return      
******************************************************************************************
*  @note
******************************************************************************************
*/



/*******************************************************************************
 *Local  functions declaration
 *******************************************************************************/



/*****************************************************************************************
 *End of file 
 *****************************************************************************************/