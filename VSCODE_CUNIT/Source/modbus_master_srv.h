/*******************************************************************************
*
*        (c) COPYRIGHT 2014 Siemens Smart Infrastructure
*
*                         FILE INFORMATION
********************************************************************************
* @file    modbus_master_srv
* @brief 
* @version 
* @author  8690-1420
* @date    2021-04-25 
* @attention  
* @note  
*******************************************************************************/

#ifndef  MODBUS_MASTER_SRV_H_ 
#define  MODBUS_MASTER_SRV_H_ 

 
/********************************************************************************
* Exported macros
********************************************************************************/
static inline uint16_t MODBUS_SwapEndian(uint16_t u16_data) {return ( u16_data << 8u )|( u16_data >> 8u );}

#ifdef MODBUS_BIG_ENDIAN
static inline uint16_t MODBUS_MatchEndian(uint16_t u16_data) {return u16_data;}
#else
static inline uint16_t MODBUS_MatchEndian(uint16_t u16_data) {return MODBUS_SwapEndian( u16_data );}
#endif

#define MODBUS_MAX_MSG_FRAME_LEN                  ( 0xFFu )
#define MODBUS_HALF_MAX_MSG_FRAME_LEN             ( MODBUS_MAX_MSG_FRAME_LEN>>1u )
#define MODBUS_QUARTER_MAX_MSG_FRAME_LEN          ( MODBUS_MAX_MSG_FRAME_LEN>>2u )

#define MODBUS_ADDRESS_BROADCAST                  ( 0u )   /*! Modbus broadcast address. */
#define MODBUS_ADDRESS_MIN                        ( 1u )   /*! Smallest possible slave address. */
#define MODBUS_ADDRESS_MAX                        ( 247u ) /*! Biggest possible slave address. */
#define MODBUS_FUNC_NONE                          (  0u )
#define MODBUS_FUNC_READ_COILS                    (  1u )
#define MODBUS_FUNC_READ_DISCRETE_INPUTS          (  2u )
#define MODBUS_FUNC_WRITE_SINGLE_COIL             (  5u )
#define MODBUS_FUNC_WRITE_MULTIPLE_COILS          ( 15u )
#define MODBUS_FUNC_READ_HOLDING_REGISTER         (  3u )  /*Read Single or Multi AO Register command*/
#define MODBUS_FUNC_READ_INPUT_REGISTER           (  4u )  /*Read Single or Multi AI Register command*/
#define MODBUS_FUNC_WRITE_REGISTER                (  6u )  /*Write Single AO Register command*/
#define MODBUS_FUNC_WRITE_MULTIPLE_REGISTERS      ( 16u )  /*Write Multi AO Register command*/
#define MODBUS_FUNC_READWRITE_MULTIPLE_REGISTERS  ( 23u )
#define MODBUS_FUNC_DIAG_READ_EXCEPTION           (  7u )
#define MODBUS_FUNC_DIAG_DIAGNOSTIC               (  8u )
#define MODBUS_FUNC_DIAG_GET_COM_EVENT_CNT        ( 11u )
#define MODBUS_FUNC_DIAG_GET_COM_EVENT_LOG        ( 12u )
#define MODBUS_FUNC_OTHER_REPORT_SLAVEID          ( 17u )
#define MODBUS_FUNC_ERROR                         ( 128u )

#define MODBUS_FACTORY_DEVICE_ADDRESS             ( 2u ) /*The factory modbus device address*/
#define MODBUS_NONE_CALLBACK                      (NULL)
#define MODBUS_NONE_TOKEN_ID                      (NULL) 
#define MODBUS_DEFUALT_VALUE_UNDEF                (0xffffffff)
#define MODBUS_REGISTER_END_TAG                   (0xffffu) 
/********************************************************************************
* Exported typedefs 
*******************************************************************************/

typedef enum
{
  READ_ONLY,                /*!< Read register values and pass to protocol stack. */
  READ_WRITE,                /*!< Update register values. */
  WRITE_ONLY
}ModbusRegisterMode_e;

 
typedef enum
{
  MDOBUS_SLAVER_EX_NONE                  = 0x00,
  MDOBUS_SLAVER_EX_ILLEGAL_FUNCTION      = 0x01,
  MDOBUS_SLAVER_EX_ILLEGAL_DATA_ADDRESS  = 0x02,
  MDOBUS_SLAVER_EX_ILLEGAL_DATA_VALUE    = 0x03,
  MDOBUS_SLAVER_EX_SLAVE_DEVICE_FAILURE  = 0x04,
  MDOBUS_SLAVER_EX_ACKNOWLEDGE           = 0x05,
  MDOBUS_SLAVER_EX_SLAVE_BUSY            = 0x06,
  MDOBUS_SLAVER_EX_MEMORY_PARITY_ERROR   = 0x08,
  MDOBUS_SLAVER_EX_GATEWAY_PATH_FAILED   = 0x0A,
  MDOBUS_SLAVER_EX_GATEWAY_TGT_FAILED    = 0x0B
}ModbusSlaverException_e;

typedef enum
{
  MODBUS_EX_NONE                         = 0x00,
  MODBUS_EX_ILLEGAL_FUNCTION             = 0x01,
  MODBUS_EX_ILLEGAL_DATA_ADDRESS         = 0x02,
  MODBUS_EX_ILLEGAL_DATA_VALUE           = 0x03,
  MODBUS_EX_ILLEGAL_SLAVE_ADDRESS        = 0x04,
  MODBUS_EX_ILLEGAL_CRC16_CHECK          = 0x05,
  MODBUS_EX_SLAVER_ACKNOWLEDGE_TIMEOUT   = 0x06,
  MODBUS_EX_MASTER_HAL_BUSY              = 0x07,
  MODBUS_EX_CALLBACK_RET_ERROR           = 0x08,
  MODBUS_EX_SLAVER_ACKNOWLEDGE_ERROR     = 0x09
}ModbusMasterException_e;


typedef struct {
  void                         *p_regVar;	 /**<Pointer to Variable*/
  const uint8_t                u8_regVarSize;    /**<Variable size*/
  const uint16_t               u16_regStartAddr; /**<Master register MODBUS start address*/
  const ModbusRegisterMode_e   e_regAccessRight; /**<Master register read and write attributes*/
  const uint32_t               u32_valDefault;
  char                         *pc_tokenID;
  ModbusMasterException_e      (*MODBUS_regThrCheckCallback)(uint8_t *pu8_regData);  
  ModbusMasterException_e      (*MODBUS_regFuncCallback)(void); /**<Function callback*/
}ModbusRegisterMap_st;

typedef union
{
  uint16_t u16_value;
  uint8_t  u8_bytesArray[2];
}U16Type_un;

typedef struct
{
  uint8_t u8_msgLen;
  uint8_t u8_msgResponseArray[MODBUS_MAX_MSG_FRAME_LEN];
}ModbusMsg_st;

/********************************************************************************
* Exported variables
********************************************************************************/


/*********************************************************************************
* Exported functions
********************************************************************************/
void MODBUS_Init(void);
ModbusMasterException_e MODBUS_MasterReadAO(uint16_t u16_readStartAddr, uint8_t u8_numOfReg);
ModbusMasterException_e MODBUS_MasterReadAI(uint16_t u16_readStartAddr, uint8_t u8_numOfReg);
ModbusMasterException_e MODBUS_MasterWriteSingleAO(uint16_t u16_writeAddr,uint8_t u8_numOfReg);
ModbusMasterException_e MODBUS_MasterWriteMultiAO(uint16_t u16_WriteStartAddr, uint8_t u8_numOfReg );
/*********************************************************************************
*inline functions 
********************************************************************************/




#endif    /*MODBUS_MASTER_SRV_H_*/

/*****************************************************************************************
*End of file 
****************************************************************************************/