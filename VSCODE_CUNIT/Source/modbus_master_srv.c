/******************************************************************************
*
*        (c) COPYRIGHT 2014 Siemens Smart Infrastructure 
*
*                         FILE INFORMATION
*******************************************************************************
 * @file    modbus_master_srv
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
#include  "modbus_register_map.h"
#include  "modbus_master_srv.h"

#include  "modbus_crc16.h"
#include  <stdbool.h>
#include  <string.h>
#include  <stdio.h>
#define UNIT_TEST_ENABLED  (true)

//#include  "usart.h"
//#include  "FreeRTOS_ex.h"

///*******************************************************************************
// *Local  marco
// *******************************************************************************/
//#define MODBUS_RECV_TIMEOUT                      ((uint32_t)(2000))
//#define MODBUS_SEND_TIMEOUT                      ((uint32_t)(100))  
//#define MODBUS_SEMAPHORE_CLEAR()                 (xSemaphoreTake( binarySemNewCommFrameHandle, (uint32_t)(0)))
//#define MODBUS_SEMAPHORE_TAKE()                  (xSemaphoreTake( binarySemNewCommFrameHandle, MODBUS_RECV_TIMEOUT))
//#define MODBUS_UART_DMA_RECV_CNDTR()             ((uint16_t)(hdma_usart2_rx.Instance->NDTR))
//#define MODBUS_UART_ABORT_DMA_RECV()             (HAL_DMA_Abort(&hdma_usart2_rx))
//#define MODBUS_UART_OPEN_DMA_RECV(u16_recvSize)  (HAL_UART_Receive_DMA(&huart2, st_ModbusRecvArray.u8_msgResponseArray, u16_recvSize))
//#define MODBUS_UART_SEND(pu8_msg,u16_size)       (HAL_UART_Transmit(&huart2, pu8_msg, (uint16_t)(u16_size),MODBUS_SEND_TIMEOUT))
//#define MODBUS_UART_STOP_DMA_RECV()              (HAL_UART_DMAStop(&huart2))
///*******************************************************************************
// *Local functions declaration
// ******************************************************************************/
//static ModbusMasterException_e MODBUS_WaitingResponse(void);
static ModbusMasterException_e MODBUS_WriteRegistersMap(ModbusRegisterMap_st *st_regMapHandler, uint16_t u16_startAddress,uint8_t u8_numOfRegs,uint8_t *pu8_dataWrite);
static ModbusMasterException_e MODBUS_ReadRegistersMap(ModbusRegisterMap_st *st_regMapHandler, uint16_t u16_startAddress, uint8_t u8_numOfRegs, uint8_t *pu8_dataRead);
///*******************************************************************************
// *Local  typedef 
// *******************************************************************************/
// 
///*******************************************************************************
// *external function and variable(optional)
// *******************************************************************************/
//
///*******************************************************************************
// * global  variable 
// *******************************************************************************/
 ModbusRegisterMap_st st_modbusMapArr[]= {
   MODBUS_REGISTER_MAP_CONTENT
 };
//
ModbusMsg_st st_ModbusRecvArray = {0,{0}};


#ifdef UNIT_TEST_ENABLED
   void MODBUS_MasterWriteMultiAO_Uart_Recv_STUB1(uint16_t u16_WriteStartAddr, uint8_t u8_numOfReg )
   {
	  st_ModbusRecvArray.u8_msgResponseArray[0] = MODBUS_FACTORY_DEVICE_ADDRESS;
      st_ModbusRecvArray.u8_msgResponseArray[1] = MODBUS_FUNC_WRITE_MULTIPLE_REGISTERS;
	  st_ModbusRecvArray.u8_msgResponseArray[2] = (uint8_t)((u16_WriteStartAddr>>8)&((uint16_t)(0x00FFu))), 
      st_ModbusRecvArray.u8_msgResponseArray[3] = (uint8_t)(u16_WriteStartAddr&((uint16_t)(0x00FFu))), 
      st_ModbusRecvArray.u8_msgResponseArray[4] = 0x00u;
      st_ModbusRecvArray.u8_msgResponseArray[5] = u8_numOfReg;
	  st_ModbusRecvArray.u8_msgLen = 8u;
	  uint16_t u16_crc16Value = CRC16_Calculate( st_ModbusRecvArray.u8_msgResponseArray, st_ModbusRecvArray.u8_msgLen - 2u);
      st_ModbusRecvArray.u8_msgResponseArray[6] = (uint8_t)( (u16_crc16Value>>8)&((uint16_t)(0x00FFu)) );
      st_ModbusRecvArray.u8_msgResponseArray[7] = (uint8_t)( u16_crc16Value&((uint16_t)(0x00FFu)) );	
   }
#endif


/** 
 * @brief  This is function is used to write multiple analog output registers.
 * @param  [in] ui8WriteStartAddress: the start address of AO register that need to be written.
 * @param  [in] u8_numOfReg: the numbers of AO register that need to be written. 
 * @return ModbusMasterException_e.
 * @note   command code = 0x10.
 * @note   ui8WriteStartAddress:Must be a address registered in Modbus map table.
 * @note   u8_numOfReg:Not allow incomplete write of a entire variable(A variable may occupy multiple registers).
 */ 
ModbusMasterException_e MODBUS_MasterWriteMultiAO(uint16_t u16_WriteStartAddr, uint8_t u8_numOfReg )
{ 
  uint8_t      u8_dataLen = (uint8_t)(0u);
  U16Type_un   u16_crc16;
  uint16_t     u16_crc16Value = (uint16_t)(0u);
  ModbusMasterException_e e_ret = MODBUS_EX_NONE;
  uint8_t u8_msgRequestArray[MODBUS_MAX_MSG_FRAME_LEN] = { MODBUS_FACTORY_DEVICE_ADDRESS,                            /*Slave Address*/
                                                           MODBUS_FUNC_WRITE_MULTIPLE_REGISTERS,                     /*Command code*/
                                                           (uint8_t)((u16_WriteStartAddr>>8)&((uint16_t)(0x00FFu))),    /*Starting Address Hi*/
                                                           (uint8_t)(u16_WriteStartAddr&((uint16_t)(0x00FFu))),        /*Starting Address Lo */
                                                           0x00u,                                                    /*No. Hi */
                                                           u8_numOfReg,                                              /*No. Lo*/
                                                           u8_numOfReg*((uint8_t)(2u)),                              /*Byte Count*/
                                                           0x00u,                                                    /*...data Hi...*/
                                                           0x00u};                                                   /*...data Lo...*/
  /*Check data register length*/
  if( (u8_numOfReg*((uint8_t)(2u)) + ((uint8_t)(9u)) ) > MODBUS_MAX_MSG_FRAME_LEN )
  {
    e_ret = MODBUS_EX_ILLEGAL_DATA_VALUE;
    return e_ret;
  }
  e_ret = MODBUS_ReadRegistersMap( st_modbusMapArr, u16_WriteStartAddr, u8_numOfReg, &(u8_msgRequestArray[7]));
  if( e_ret != MODBUS_EX_NONE)
  {
    return e_ret;
  }
  /*Calculate the data length that need to calculate the query message CRC16 value*/
  u8_dataLen = ((uint8_t)(7))+ (u8_numOfReg*((uint8_t)(2u)));
  u16_crc16Value = CRC16_Calculate( u8_msgRequestArray, u8_dataLen);
  u8_msgRequestArray[u8_dataLen++] = (uint8_t)( (u16_crc16Value>>8)&((uint16_t)(0x00FFu)) );
  u8_msgRequestArray[u8_dataLen++] = (uint8_t)( u16_crc16Value&((uint16_t)(0x00FFu)) );

#ifndef UNIT_TEST_ENABLED
  MODBUS_SEMAPHORE_CLEAR();
  MODBUS_UART_ABORT_DMA_RECV();
  MODBUS_UART_STOP_DMA_RECV();
#endif 

  st_ModbusRecvArray.u8_msgLen = 0u;
  memset(st_ModbusRecvArray.u8_msgResponseArray, 0u, MODBUS_QUARTER_MAX_MSG_FRAME_LEN);

#ifdef UNIT_TEST_ENABLED
printf("\r\n>>>>Modbus request message:\r\n");
for(uint16_t i = 0; i < u8_dataLen; i++)
  printf("%x  ",u8_msgRequestArray[i]);
printf("\r\n");
#endif

#ifndef UNIT_TEST_ENABLED
   /*Turn on UART receiving mode*/
   if(HAL_OK != MODBUS_UART_OPEN_DMA_RECV(MODBUS_QUARTER_MAX_MSG_FRAME_LEN))
   {
     return MODBUS_EX_MASTER_HAL_BUSY; 
   }
   /*Send Modbus query message*/
   if(HAL_OK != MODBUS_UART_SEND(u8_msgRequestArray,(uint16_t)(u8_dataLen)))
   {
     return MODBUS_EX_MASTER_HAL_BUSY;
   } 
  
   /*Waiting for response message*/
   e_ret = MODBUS_WaitingResponse();
   if( MODBUS_EX_NONE != e_ret)
   {
     return e_ret;
   } 
   
   /*Calaculate recieved data length*/
   st_ModbusRecvArray.u8_msgLen = MODBUS_QUARTER_MAX_MSG_FRAME_LEN - MODBUS_UART_DMA_RECV_CNDTR();
#else
   MODBUS_MasterWriteMultiAO_Uart_Recv_STUB1(u16_WriteStartAddr, u8_numOfReg );
   printf("\r\n>>>>Modbus response message:\r\n");
   for(uint16_t j = 0; j < st_ModbusRecvArray.u8_msgLen; j++)
     printf("%x  ",st_ModbusRecvArray.u8_msgResponseArray[j]);
   printf("\r\n");
#endif

   /*Check received Modbus device address*/
   if(st_ModbusRecvArray.u8_msgResponseArray[0] != MODBUS_FACTORY_DEVICE_ADDRESS)
   {
     e_ret = MODBUS_EX_ILLEGAL_SLAVE_ADDRESS;
     return e_ret;   
   }
  
   /*Received Modbus data frame CRC16 verification*/
   u16_crc16.u8_bytesArray[0] = st_ModbusRecvArray.u8_msgResponseArray[st_ModbusRecvArray.u8_msgLen-(uint8_t)(1u)];
   u16_crc16.u8_bytesArray[1] = st_ModbusRecvArray.u8_msgResponseArray[st_ModbusRecvArray.u8_msgLen-(uint8_t)(2u)];
   if(u16_crc16.u16_value != CRC16_Calculate( st_ModbusRecvArray.u8_msgResponseArray, (st_ModbusRecvArray.u8_msgLen-(uint8_t)(2))))
   {
     e_ret = MODBUS_EX_ILLEGAL_CRC16_CHECK;
     return e_ret; 
   }  
 
   /*Check whether the slaver response data returns the fault function code*/
   if((st_ModbusRecvArray.u8_msgResponseArray[1]&MODBUS_FUNC_ERROR) == MODBUS_FUNC_ERROR)
   {
     e_ret = MODBUS_EX_SLAVER_ACKNOWLEDGE_ERROR;
     return e_ret; 
   }
   
   /*Received Modbus data frame function code verification*/
   if(st_ModbusRecvArray.u8_msgResponseArray[1] != MODBUS_FUNC_WRITE_MULTIPLE_REGISTERS)
   {
     e_ret = MODBUS_EX_ILLEGAL_FUNCTION;
     return e_ret;
   }
  
  return e_ret;
}

/*******************************************************************************
 *Local  functions declaration
 *******************************************************************************/
static ModbusMasterException_e MODBUS_WriteRegistersMap(ModbusRegisterMap_st *st_regMapHandler, uint16_t u16_startAddress,uint8_t u8_numOfRegs,uint8_t *pu8_dataWrite)
{
  uint8_t      i,j,s,z;
  uint8_t      u8_varWordSize = (uint8_t)(0u);
  uint8_t      *pu8_varReg = NULL;
  uint16_t     u16_regAddr = u16_startAddress;
  uint8_t      *pu8_regTemp = NULL;
  
  /*u8_numOfRegs of registers need to assignment to the corresponding variables*/
  for( i = (uint8_t)(0u); i < u8_numOfRegs; i++ )              
  {
    for( j = (uint8_t)(0u); st_regMapHandler[j].u16_regStartAddr != MODBUS_REGISTER_END_TAG; j++ )
    {
      /*Find variable Modbus master register address in st_regMapHandler[] and check corresponding register access right*/
      if(( st_regMapHandler[j].u16_regStartAddr == u16_regAddr )&&\
         (( st_regMapHandler[j].e_regAccessRight == READ_ONLY )||( st_regMapHandler[j].e_regAccessRight == READ_WRITE ))) 
      {
        /*Get variable address that corresponding to Modbus master register address*/
        pu8_varReg = (uint8_t *)(st_regMapHandler[j].p_regVar); 

        /*Calculate variable size(Unit: word)*/
        u8_varWordSize = st_regMapHandler[j].u8_regVarSize>>1u;
        if( (i + u8_varWordSize) > u8_numOfRegs)
        {
          /*Errors:Incomplete assignment of variables*/
          return MODBUS_EX_ILLEGAL_DATA_ADDRESS;
        }
        
        /*Call register data threshold check callback*/
        if(st_regMapHandler[j].MODBUS_regThrCheckCallback != MODBUS_NONE_CALLBACK)
        {
          pu8_regTemp = &(pu8_dataWrite[i*2u]);
          if(st_regMapHandler[j].MODBUS_regThrCheckCallback(pu8_regTemp) != MODBUS_EX_NONE)
          {
            return MODBUS_EX_ILLEGAL_DATA_VALUE;
          }
        }
        
        /*Write Modbus response data into corresponding variable address*/
        z = (uint8_t)(0u);
		
#ifndef UNIT_TEST_ENABLED     
        vTaskSuspendAll();
#endif

        for( s = (uint8_t)(0u); s < u8_varWordSize; s++ )
        {
          pu8_varReg[z++] = pu8_dataWrite[ (i+s)*((uint8_t)(2u))+((uint8_t)(1u)) ];
          pu8_varReg[z++] = pu8_dataWrite[ (i+s)*((uint8_t)(2u)) ];
        }
		
#ifndef UNIT_TEST_ENABLED
        xTaskResumeAll();
#endif     
   
        /*i = the number of registers that finished writing */
        if(u8_varWordSize > 1u)
        {
          i += (u8_varWordSize - (uint8_t)(1u));
        }
        /*u16_regAddr = the next Modbus master register start address that will be written corresponding Modbus response data*/
        u16_regAddr += ((uint16_t)u8_varWordSize);
        
        /*Call register read/write callback*/
        if(st_regMapHandler[j].MODBUS_regFuncCallback != MODBUS_NONE_CALLBACK)
        {
          if( st_regMapHandler[j].MODBUS_regFuncCallback() != MODBUS_EX_NONE)
          {
            return MODBUS_EX_CALLBACK_RET_ERROR;
          }
        }
        break;/*Jump out of loop: for( j = (uint8_t)(0u); st_regMapHandler[j].u16_regStartAddr != MODBUS_REGISTER_END_TAG; j++ )*/
      }
    }
    if(st_regMapHandler[j].u16_regStartAddr == MODBUS_REGISTER_END_TAG)/*Not find register address in Modbus map list*/
    {
        /*Maybe there is a error register write start address*/
        return MODBUS_EX_ILLEGAL_DATA_ADDRESS;
    }
  }
  return MODBUS_EX_NONE;
}

static ModbusMasterException_e MODBUS_ReadRegistersMap(ModbusRegisterMap_st *st_regMapHandler, uint16_t u16_startAddress, uint8_t u8_numOfRegs, uint8_t *pu8_dataRead)
 {
   uint8_t      i,j,s,z = (uint8_t)(0u);
   uint8_t      u8_varWordSize = (uint8_t)(0u);
   uint8_t      *pu8_varReg = NULL;
   uint16_t     u16_regAddr = u16_startAddress; 
   
   /*u8_numOfRegs of registers need to assignment to Modbus query message payload*/ 
   for( i = (uint8_t)(0u); i < u8_numOfRegs; i++ )              
   {
     for( j = (uint8_t)(0u); st_regMapHandler[j].u16_regStartAddr != MODBUS_REGISTER_END_TAG; j++ )
     {
       /*Find variable Modbus master register address in st_regMapHandler[] and check corresponding register access right*/ 
       if(( st_regMapHandler[j].u16_regStartAddr == u16_regAddr )&&\
          (( st_regMapHandler[j].e_regAccessRight == WRITE_ONLY )||( st_regMapHandler[j].e_regAccessRight == READ_WRITE ))) 
       {
         /*Get variable address*/
         pu8_varReg = (uint8_t *)(st_regMapHandler[j].p_regVar);                     
         /*Calculate variable size(Unit: word)*/
         u8_varWordSize = st_regMapHandler[j].u8_regVarSize>>1u;
        
         if((i + u8_varWordSize) > u8_numOfRegs)
         {
           /*Incomplete read of a variable*/
           return MODBUS_EX_ILLEGAL_DATA_ADDRESS; 
         }
 
         /*Call register data threshold check callback*/
         if(st_regMapHandler[j].MODBUS_regThrCheckCallback != MODBUS_NONE_CALLBACK)
         {
           if(st_regMapHandler[j].MODBUS_regThrCheckCallback(pu8_varReg) != MODBUS_EX_NONE)
           {
             return MODBUS_EX_ILLEGAL_DATA_VALUE;
           }
         }
		 
#ifndef UNIT_TEST_ENABLED
         vTaskSuspendAll();
#endif
         /*Write variable value to Modbus query message payload*/
         for(s = (uint8_t)(0); s < u8_varWordSize; s++)
         {
           pu8_dataRead[z++] = pu8_varReg[ s*((uint8_t)(2u))+((uint8_t)(1u)) ];
           pu8_dataRead[z++] = pu8_varReg[ s*((uint8_t)(2u)) ];
         }
		 
#ifndef UNIT_TEST_ENABLED
         xTaskResumeAll();
#endif
         
         /*i = the number of registers that finished writing */
         if(u8_varWordSize > 1u)
         {
           i += (u8_varWordSize - (uint8_t)(1u));
         }
         /*u16_regAddr = the next Modbus master register start address that will be written to corresponding Modbus query message payload*/
         u16_regAddr += ((uint16_t)u8_varWordSize);
 
         /*Call register read/write callback*/
         if(st_regMapHandler[j].MODBUS_regFuncCallback != MODBUS_NONE_CALLBACK)
         {
           if( st_regMapHandler[j].MODBUS_regFuncCallback() != MODBUS_EX_NONE)
           {
             return MODBUS_EX_CALLBACK_RET_ERROR;
           }
         }
         
         break;/*Jump out of loop: for( j = (uint8_t)(0u); st_regMapHandler[j].u16_regStartAddr != MODBUS_REGISTER_END_TAG; j++ )*/
       }
     }
     
     if(st_regMapHandler[j].u16_regStartAddr == MODBUS_REGISTER_END_TAG)/*Not find register address in Modbus map list*/
     {
         /*Maybe there is a error register read start address*/
         return MODBUS_EX_ILLEGAL_DATA_ADDRESS;
     }
   }
   return MODBUS_EX_NONE;
 }
   
#ifdef UNIT_TEST_ENABLED

uint32_t UNITEST_ModbusRegMapWrite_TestCase1(void)
{
   uint8_t u8_IdentFwVerBot[10] = {'D',1,1,1,1,1,1,1,1,0};
   ModbusMasterException_e e_ret = MODBUS_EX_NONE;
   e_ret = MODBUS_WriteRegistersMap(st_modbusMapArr, MB_REG_ADDR_FW_BLT_VER,(5u),u8_IdentFwVerBot);
   if(e_ret != MODBUS_EX_NONE)
   {
	   printf("Test successfully passed1!\r\n");
	   return (uint32_t)e_ret;
   }
   return (uint32_t)MODBUS_EX_NONE;
}

uint32_t UNITEST_ModbusRegMapWrite_TestCase2(void)
{
   u32_dateTimeUtc = 64u;
   ModbusMasterException_e e_ret = MODBUS_EX_NONE;
   e_ret = MODBUS_WriteRegistersMap(st_modbusMapArr, MB_REG_ADDR_DATE_TIME_UTC,(2u),(uint8_t *)(&u32_dateTimeUtc));
   if(e_ret != MODBUS_EX_NONE)
   {
	   return (uint32_t)e_ret;
   }
   uint32_t u32_temp = 0u;
   e_ret = MODBUS_ReadRegistersMap(st_modbusMapArr, MB_REG_ADDR_DATE_TIME_UTC,(2u),(uint8_t *)(&u32_temp));
   if(e_ret != MODBUS_EX_NONE)
   {
	   return (uint32_t)e_ret;
   }
   
   if(u32_dateTimeUtc != u32_temp)
   {
	   return 0xffffffffu;
   }
   
   printf("Test successfully passed2!\r\n");
   return (uint32_t)MODBUS_EX_NONE;
}

uint32_t UNITEST_ModbusWriteMultiAO_TestCase3(void)
{
   ModbusMasterException_e e_ret = MODBUS_EX_NONE;
   e_ret = MODBUS_MasterWriteMultiAO(MB_REG_ADDR_FW_BLT_VER, 5u );
   
   if(e_ret != MODBUS_EX_NONE)
   {
	   return (uint32_t)e_ret;
   }
   printf("Test successfully passed3!\r\n");
   return (uint32_t)MODBUS_EX_NONE;
}

#endif   

//static ModbusMasterException_e MODBUS_WaitingResponse(void)
//{ 
//  ModbusMasterException_e e_ret = MODBUS_EX_NONE;
//  
//  if(MODBUS_SEMAPHORE_TAKE() != pdTRUE)
//  {  
//    e_ret = MODBUS_EX_SLAVER_ACKNOWLEDGE_TIMEOUT;
//  }
//  
//  MODBUS_UART_ABORT_DMA_RECV();
//  /*No data received or Waiting timeout*/
//  return e_ret; 
//}



/*****************************************************************************************
 *End of file 
 *****************************************************************************************/