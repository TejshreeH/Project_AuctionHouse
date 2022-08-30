#include <stdio.h>
#include <ctype.h>
#include <stddef.h>
#include "auctionheader.h"
#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"
#include "CUnit/Automated.h"
#include "CUnit/Console.h"
#include "AuctionHouse_Item_Func.c"
#include "AuctionHouse_Bidder_Func.c"

int init_suite(void) 
{ 
	return 0;    //To Initialize the suite
}

int clean_suite(void) 
{
       	return 0;   //To uninitialize the suite after Unit Testing
}

void test_display_item(void)         //our test function 1
{
	CU_ASSERT(display_item()==0);
	CU_ASSERT(display_item()==0);
}

void test_auction_day(void)        //our test function 2
{
	CU_ASSERT(display_bidding_report()==0);
	CU_ASSERT(display_bidding_report()==0);
}
int main (void)     // Main function
{

	CU_pSuite pSuite1,pSuite2 = NULL;

	// Initialize CUnit test registry
	if (CUE_SUCCESS != CU_initialize_registry())
		return CU_get_error();

	// Add suite1 to registry
	pSuite1 = CU_add_suite("Basic_Test_Suite1", init_suite, clean_suite);
	if (pSuite1 == NULL) 
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	// add test1 to suite1
	if ((NULL == CU_add_test(pSuite1, "\n\n……… Testing Display item function……..\n\n", test_display_item)))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	//add test 2 to suite2
	if ((NULL == CU_add_test(pSuite1, "\n\n……… Testing Auction day function……..\n\n", test_auction_day)))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	CU_basic_run_tests();// OUTPUT to the screen

	CU_cleanup_registry();//Cleaning the Registry
	
	return CU_get_error();

}
