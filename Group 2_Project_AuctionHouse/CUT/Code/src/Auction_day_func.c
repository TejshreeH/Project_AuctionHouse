/*******************************************************************************************************************
 * * FILE NAME : AuctionHouse_day_Func.c 
 *
 *
 * * DESCRIPTION : This file contains the function related to auction day functionality of the program 
 * 		   It also contains the thread and mutex Implementation function
 *
 *
 * * FUNCTION NAME : *auction() , auction_day()
 *
*******************************************************************************************************************/
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "auctionheader.h"

pthread_mutex_t accum_mutex=PTHREAD_MUTEX_INITIALIZER;//INITIALIZES THE MUTEX


		//This function is used to apply lock so that at one time only one bidder can bid

void *auction()
{

	auction_day();
}

		//This function have the functionality to let bidders bid for their prefferd items


int auction_day()
{
	aday *a_last;
	a_new = (aday*)calloc(1,sizeof(aday));
	double highest_bid;
	double amount, bid_pay;
	int bid=0, first_bid=0, second_bid=0, third_bid=0;
	while(1)
	{
		printf("\nEnter the item code for bidding :");
		scanf("%d", &a_new->item_code);
		if(start)
		{
			it *ptr;
			for(ptr=start;(ptr)&&ptr->item_code!=a_new->item_code;ptr=ptr->next);
			if(!ptr)
			{
				printf("\nEntered item code is invalid\n");
				continue;
			}
			else
			{
				strcpy(a_new->item_name,ptr->item_name);
				highest_bid=ptr->item_price;
				break;
			}
		}
	}
	for(int i=1;i<=3;i++)
	{
	pthread_mutex_lock(&accum_mutex);
		while(1)
		{
			printf("\nEnter bidder id :");
			scanf("%d", &bid);
			if (bid==0)
			{
				printf("Bidder id cannot be zero or blank.Enter the valid bidder id\n");
				continue;
			}
			bder *ptr;
			for(ptr=start1; (ptr) && ptr->bidder_id!=bid ;ptr=ptr->next1);
			if(!ptr)
			{
				printf("Entered bidder id is invalid. Enter the valid bidder id\n");
				continue;
			}
			else
			{
				if(i==1)
				{
					first_bid=bid;
					break;
				}
				else if(i==2)
				{
					if(bid==first_bid)
					{
						printf("Same bidder id cannot be accepted. Re-enter the bidder id. \n");
						continue;
					}
					else
					{
						second_bid=bid;
						break;
					}
						
				}
				else 
				{

					
					if(bid==first_bid || bid==second_bid)
					{
						printf("Same bidder id cannot be accepted. Re-ener the bidder id.\n");
						continue;
					}
					else
					{
						strcpy(a_new->bid_win_name,ptr->bidder_name);
						bid_pay=ptr->Security_Deposit;
						third_bid=bid;
						break;
					}
				}
			}
			}
		
	pthread_mutex_unlock(&accum_mutex);
		while(1)
		{
			if(i==1)
				printf("Base price of item starts from %lf ",highest_bid);
			printf("\nEnter the bidding amount: ");
			scanf("%lf", &amount);
			if (amount<highest_bid)
			{
				printf("Amount should be greater than %lf\n",highest_bid);
			       continue;
			}
			else
			{
				highest_bid=amount;
				break;
			}

	}
	}
	a_new->bidder_id=third_bid;
        a_new->bid_win_amount=highest_bid;
	if(bid_pay>highest_bid)
	{
		a_new->r_deposit=(bid_pay-highest_bid);
		a_new->bid_netpayable=0;
		printf("\n\tSecurity Deposit of bidder id %d is more than the payable amount so remaining security deposit is %7.2lf\n", third_bid, a_new->r_deposit);
	}
	else if(bid_pay==highest_bid)
	{
		a_new->bid_netpayable=(bid_pay-highest_bid);
		printf("\n\tSecurity deposit of winning bidder id %d is same as net payable amount so Net Payable amount is 0Rs.\n", third_bid);

	}
	else
		a_new->bid_netpayable=(highest_bid-bid_pay);
		a_new->r_deposit;
		printf("\n\tNet payable amount by the bidder is %7.2lf\n", a_new->bid_netpayable);
	printf("\n\tHighest bidding amount is %lf\n", a_new->bid_win_amount);
	if(!a_start)
	{
		a_start=a_last=a_new;
		a_new->a_next=NULL;
	}
	else
	{
		a_last->a_next=a_new;
		a_new->a_next=NULL;
		a_last=a_new;
	}

	
}

