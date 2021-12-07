#include <stdio.h>
#include <stdlib.h> 
#include "Source/para_def.h"
#include "Source/modbus_master_srv.h"
#include "Source/modbus_register_map.h"

#include <Basic.h>
#include <Console.h>
#include <CUnit.h>
#include <TestDB.h>


////////////////////////////////////////////


void test_process_1(void)
{
	CU_ASSERT(MODBUS_MasterWriteMultiAO(MB_REG_ADDR_FW_BLT_VER, 5u ) == MODBUS_EX_NONE);
}
 
void test_process_2(void)
{
	CU_ASSERT(MODBUS_MasterWriteMultiAO(MB_REG_ADDR_FW_BLT_VER, 4u ) == MODBUS_EX_NONE);
	printf(">>>%d\r\n",MODBUS_MasterWriteMultiAO(MB_REG_ADDR_FW_BLT_VER, 4u ));
}
 
void test_process_3(void)
{
	CU_ASSERT(MODBUS_MasterWriteMultiAO(MB_REG_ADDR_FW_APP_VER, 5u ) == MODBUS_EX_NONE);
}

void test_process_4(void)
{
	CU_ASSERT(MODBUS_MasterWriteMultiAO(MB_REG_ADDR_FW_APP_VER, 4u ) == MODBUS_EX_NONE);
	printf(">>>%d\r\n",MODBUS_MasterWriteMultiAO(MB_REG_ADDR_FW_BLT_VER, 4u ));
}
 
CU_TestInfo tests[] = {
    {"test 1", test_process_1 },
    {"test 2", test_process_2 },
    {"test 3", test_process_3 },
	{"test 4", test_process_4 },
    CU_TEST_INFO_NULL
};
 
/* suite init */
int suite_init(void)
{
	return 0;
}
 
int suite_clean(void)
{
	return 0;
}
 
void suite_setup(void)
{

}
 
void suite_teardown(void)
{

}
 
CU_SuiteInfo suites[] = {
    {"suite 1", suite_init, suite_clean, suite_setup, suite_teardown, tests},
    CU_SUITE_INFO_NULL
};

int main(){
	CU_ErrorCode err;
 
	/* init */
	printf("init\n");
	err = CU_initialize_registry();
	if( err ){
		printf("CU_initialize_registry: %d\n", err);
		return err;
	}
 
	/* add suites and tests */
	printf("add suites and tests\n");
	err = CU_register_suites(suites);
	if( err )
	{
		printf("CU_register_suites: %d\n", err);
	}
	CU_pTestRegistry reg = CU_get_registry();
	printf("CU_get_registry: %d/%d/%u\n", reg->uiNumberOfSuites, reg->uiNumberOfTests, (long)reg->pSuite);
 
	/* run auto */
	printf("run auto\n");
	/**** Automated Mode *****************/
	CU_set_output_filename("TestProcess");
	CU_list_tests_to_file();
	CU_automated_run_tests();
	//************************************/
 
	printf("run basic\n");
	/***** Basice Mode *******************/
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	//************************************/
 
	/*****Console Mode ********************
	CU_console_run_tests();
	/************************************/		
	
	/* end */
	printf("end\n");
	CU_cleanup_registry();
	err = CU_get_error();
	if( err )
	{
		printf("error: %d", err);
	}
	return err;
}