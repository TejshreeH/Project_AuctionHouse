/*******************************************************************************************************************
 * * FILE NAME : Auction_main.c
 *
 *
 * * DESCRIPTION : This is the main menu file which contains main function all the functions related to the program.
 *
 * * Revision History:
 * 	DATE				NAME 				REASON
 *-----------------------------------------------------------------------------------------------------------------
 *    25/08/2022			Tejshree Hirudkar		Creation of file
 *    29/08/2022			parlapalli Nithya Sree		Modified some parts of code
*******************************************************************************************************************/

#include <stdio.h>          
#include <string.h>
#include <stdbool.h>
#include <pthread.h>
#include <stddef.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include "auctionheader.h" //user defined reader file which contains the function declaration and structures unsigned
#include "AuctionHouse_Item_Func.c"
#include "AuctionHouse_Bidder_Func.c"
#include "Auction_day_func.c"
#include "file_func.c"

				//Main function

int main()
{
	a_start=NULL;
	start1=NULL;
	start=NULL;
	bidder_file_to_list();
	item_file_to_list();
	auction_file_to_list();

	int res_Status=0;
	pthread_t thread1;

	system("read a");
	system("clear");

	printf("\n          WELCOME TO ONLINE AUCTION HOUSE        \n");
	bool exit =false;
	while (!exit)
	{
		int menu_choice;
		printf("\n\t1. Bidder Data\n\t2. Item Maintenance\n\t3. Display items to be auctioned for the week\n\t4. Auction Day\n\t5. Display Bidding Report\n\t6. Exit\n");
		printf("\n\tEnter choice - ");
		scanf("%d", &menu_choice);
		switch(menu_choice)
		{
			case 1:
				{
					res_Status=check_Password();
					if(res_Status==1)
					{
						printf("\n\tInvalid password\n");
						return(EXIT_FAILURE);
					}
					else
					{
						int bidder_choice=0;
						while(bidder_choice!=5)
						{
							printf("\n\t1.Add bidder\n\t2.Edit Bidder\n\t3.Delete Bidder\n\t4.View Bidder List\n\t5.Return to main menu\n");
							printf("\n\tEnter choice - ");
							scanf("%d",&bidder_choice);
							switch(bidder_choice) 
							{
								case 1: add_bidder();
									break;
								case 2: edit_bidder();
									break;
								case 3: del_bidder();
									break;
								case 4: view_bidder(); 
								       	break;
								case 5: break;
								default:printf("\n\tInvalid option\n");
							}
						}
						continue;
					}
				              
		}

			case 2:
				{


					res_Status=check_Password();
					if(res_Status==1)
				        {
						printf("\n\tInvalid password\n");
						return(EXIT_FAILURE);
					}
					else
				        {
					int item_choice=0;
					while(item_choice!=5)
					{
						printf("\n\t1.Add Item\n\t2.Edit Item\n\t3.Delete Item\n\t4.View Item\n\t5 Return to main menu\n");
						printf("\n\tEnter choice - ");
						scanf("%d",&item_choice);
						switch(item_choice)
						{
							case 1: add_item();
								break;
							case 2: edit_item();
								break;
							case 3: del_item();
								break;
							case 4: view_item();
								break;
							case 5: break;
							default:printf("\n\tInvalid option\n");
						}
					}
					
					continue;
					}
				}

			case 3:display_item();
			       break;
			case 4:display_item();
			       pthread_create(&thread1,NULL,auction,NULL);
			       pthread_join(thread1,NULL);
			       printf("Thread run successfully..\n");
			       break;
			case 5:display_bidding_report();
			       break;
			case 6:exit=true;
			       break;
			default:printf("\n\tInvalid option\n");
		}
system("read a");
system("clear");
	
}
	if(start1)
		bidder_list_to_file();
	if(start)
		item_list_to_file();
	if(a_start)
		auction_list_to_file();
}
