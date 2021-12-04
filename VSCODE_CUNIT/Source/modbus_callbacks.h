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
 
#ifndef  MODBUS_CALLBACKS_H_ 
#define  MODBUS_CALLBACKS_H_ 
#include "modbus_master_srv.h"
/********************************************************************************
 * Exported macros
 ********************************************************************************/



/********************************************************************************
 * Exported typedefs 
 *******************************************************************************/



/********************************************************************************
 * Exported variables
 ********************************************************************************/



/*********************************************************************************
 * Exported functions
 ********************************************************************************/
ModbusMasterException_e MODBUS_CallbackCommLedState(void);
ModbusMasterException_e MODBUS_CallbackRemoteControl(void);
ModbusMasterException_e MODBUS_IdentAttachedDeviceCallback(void);
ModbusMasterException_e MODBUS_IdentDeviceVariantCallback(void);
ModbusMasterException_e MODBUS_ProductionLockStaCallback(void);
ModbusMasterException_e MODBUS_MechOperaCyclesCallback(void);
ModbusMasterException_e MODBUS_MechOperaCyclesCfgCallback(void);
ModbusMasterException_e MODBUS_CntTripCyclesCallback(void);
ModbusMasterException_e MODBUS_CntTripCyclesCfgCallback(void);
ModbusMasterException_e MODBUS_CntRcdTestCyclesCallback(void);
ModbusMasterException_e MODBUS_CntRcdTestCyclesCfgCallback(void);
ModbusMasterException_e MODBUS_ArdStateCallback(void);
ModbusMasterException_e MODBUS_RcdTestStateCallback(void);
ModbusMasterException_e MODBUS_IrTestStateCallback(void);
ModbusMasterException_e MODBUS_RcaModeStateCallback(void);
ModbusMasterException_e MODBUS_RcaHandleStateCallback(void);
ModbusMasterException_e MODBUS_CfgArdFirstDelayTimeCallback(void);
ModbusMasterException_e MODBUS_CfgASecondDelayTimeCallback(void);
ModbusMasterException_e MODBUS_CfgAThirdDelayTimeCallback(void);
ModbusMasterException_e MODBUS_Cfg2ndAttemptDelayTimeCallback(void);
ModbusMasterException_e MODBUS_CfgArdCtrlCallback(void);
ModbusMasterException_e MODBUS_CfgIrCtrlCallback(void);
ModbusMasterException_e MODBUS_CfgRcdCtrlCallback(void);
ModbusMasterException_e MODBUS_CfgRcdSelectiveTypeCallback(void);
ModbusMasterException_e MODBUS_CfgAutoTestStartUtcCallback(void);
ModbusMasterException_e MODBUS_CfgAutoTestIntervalCallback(void);
ModbusMasterException_e MODBUS_CallbackRemoteControl(void);
ModbusMasterException_e MODBUS_CallbackCommLedState(void);
void MODBUS_InitDataExchange(void);
/*********************************************************************************
 *inline functions 
 ********************************************************************************/




#endif    /*MODBUS_CALLBACKS_H_*/

/*****************************************************************************************
 *End of file 
 ****************************************************************************************/