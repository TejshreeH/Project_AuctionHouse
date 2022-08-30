#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "auctionheader.h"


/**********************************************add_bidder() Adds Bidder details to the Reg_Bidder file********************************************/


int add_bidder()

{
	new1=(bder*)malloc(sizeof(bder));
	while(1)
	{
		printf("\nEnter Bidder id (ID should be in the range 100 to 200):\n");
		scanf("%d",&new1->bidder_id);
		if(new1->bidder_id<100 || new1->bidder_id>200)
		{
			printf("\nOut of range\n");
			continue;
		}
		if(start1)
		{
			bder *ptr;
			for(ptr=start1;(ptr)  && ptr->bidder_id!=new1->bidder_id;ptr=ptr->next1);
			if(ptr)
			{
				printf("\n %d Bidder id already exists. Enter other Bidder id",new1->bidder_id);
				continue;
			}
else
				break;
		}
	}
	while(1)
	{
		printf("\nEnter Bidder name:\n");
		scanf("%s",new1->bidder_name);
		int len=strlen(new1->bidder_name);
			if(len<5 || len>19)
			{
				printf("\nInvalid length should be in range 5-19\n");
				continue;
			}
			int flag=0;
			for(int i=0;new1->bidder_name[i]!='\0';i++)
			{
				if(!isalpha(new1->bidder_name[i]))
				{
					flag=1;
					break;
				}
			}
			if(flag==1)
			{
				printf("\nName should have only alphabets\n");
				continue;
			}
			else
				break;
	}

	while(1)
	{

		printf("\nEnter bidder pan no:\n");
		scanf("%s", new1->bidder_pan);
		int len=strlen(new1->bidder_pan);
			if(len!=6)
			{
				printf("\nPAN card should have 6 characters\n");
				continue;
			}
			int flag=0;
			for(int i=0;new1->bidder_pan[i]!='\0';i++)
			{
				if(islower(new1->bidder_pan[i]))
				{
					flag=1;
					break;
				}
			}
			if(flag==1)
			{
				printf("\nPAN no. should only contain UPPERCASE characters\n");
				continue;
			}
			else
				break;
	}
	while(1)
	{
		printf("\nEnter Deposit status:[y/n]\n");
		scanf("%s",&new1->Deposit_status);
			int len=sizeof(new1->Deposit_status);
			if(len!=1)
			{
				printf("\nDeposit status should be either y or n\n");
				continue;
			}
			
			if(new1->Deposit_status=='y' || new1->Deposit_status=='n')
			{
				break;
			}
			else
			{
				printf("\nDeposit status should be either y or n\n");
				continue;
			}
	
	}
	while(1)
	{
		printf("\nEnter Security Deposit:\n");
		scanf("%lf",&new1->Security_Deposit);
			if(new1->Security_Deposit < 100)
			{
				printf("\n\tMinimum security deposit should be 100 Rs.\n");
				continue;
			}
			else
				break;
		
	}

		if(start1==NULL)
		{
			start1=new1;
			new1->next1=NULL;
		}
		else if(new1->bidder_id<start1->bidder_id)
		{
			new1->next1=start1;
			start1=new1;
		}
		else
		{
			for(ptr1=start1;(ptr1) && ptr1->bidder_id<new1->bidder_id;prev1=ptr1,ptr1=ptr1->next1);
			prev1->next1=new1;
			new1->next1=ptr1;
		}
}



/*****************************************view_bidder() Display the  Bidder details from  Reg_Bidder file*****************************************/

int view_bidder()
{
	if(start1)
	{
		printf("\nBIDDER ID             BIDDER NAME           BIDDER PAN       DEPOSIT STATUS         SECURITY DEPOSIT\n");
		for(bder *ptr = start1; (ptr); ptr=ptr->next1)
		{
			printf("\n   %d        %15s        %20s        %10c          %15lf\n",ptr->bidder_id,ptr->bidder_name,ptr->bidder_pan,ptr->Deposit_status,ptr->Security_Deposit);
		}
	}
	else
	{
		printf("Bidder list not exist");
		return(1);
	}
}

/*****************************************edit_bidder() Edit the  Bidder details from  Reg_Bidder file********************************************/

int edit_bidder()

{
	if(!start1)
	{

		printf("\n\tBidder file is empty\n");
		return(1);
	}
	int menu;
	printf("Enter bidder id:\n");
	scanf("%d",&menu);
	for(ptr1=start1;(ptr1)&&(ptr1->bidder_id!=menu);ptr1=ptr1->next1);
	if(ptr1==NULL)
	{
		printf("\n%d bidder id not found\n",menu);
		return(1);
	}
	else{
		printf("\n\tOld bidder name is  %s  and bidder pan number is %s \n",ptr1->bidder_name,ptr1->bidder_pan);
		printf("\n\tEnter new bidder name and bidder pan number :");
		scanf("%s %s",ptr1->bidder_name,ptr1->bidder_pan);
		return(1);
	}
}

/*****************************************del_bidder() Delete the  Bidder details from  Reg_Bidder file*******************************************/

int del_bidder()
{
	if(!start1)
	{

		printf("\n\t Bidder file is empty\n");
		return(1);
	}
	int menu;
	printf("\n\tEnter the bidder id:");
	scanf("%d",&menu);
	if(menu==start1->bidder_id)
	{
		ptr1=start1;
		start1=start1->next1;
		free(ptr1);
	}
	else
	{
		for(ptr1=start1;(ptr1) &&ptr1->bidder_id!=menu;prev1=ptr1,ptr1=ptr1->next1);
		if(ptr1==NULL)
		{
			printf("\n\tBidder not found\n");
			return(1);
		}
		prev1->next1=ptr1->next1;
		free(ptr1);
	}

}



/**********************************************display_bidding_report() displays the winner details********************************************/

int display_bidding_report()
{

	if(a_start)
	{
		printf("\n                       BIDDING REPORT                             \n");
		printf("\nITEM CODE     ITEM NAME     BIDDING WINNER         BIDDING AMOUNT\n");
		for(aday *ptr = a_start; (ptr); ptr=ptr->a_next)
		{
			printf("\n%d         %s            %s                 %lf\n",ptr->item_code,ptr->item_name,ptr->bid_win_name,ptr->bid_win_amount);
		}
	}
}
