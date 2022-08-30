/*******************************************************************************************************************
 * * FILE NAME : AuctionHouse_Item_Func.c 
 *
 *
 * * DESCRIPTION : This file contains all the functions related to Item maintenance and displaying Bidder reports
 *
 *
 * * FUNCTION NAME : add_item(), edit_item(), del_item(), view_item(), display_item()
 *
*******************************************************************************************************************/
#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
#include "auctionheader.h"

			/********************** add_item() 
		 		 ADDS ITEM DETAILS TO THE Item_to_be_Auctioned FILE *******************/

int add_item()
{
	item_new=(it*)malloc(sizeof(it));
	while(1)
	{
		printf("\nEnter item code(Code should be in the range 100 to 200):\n");
		scanf("%d",&item_new->item_code);
		if(item_new->item_code <100 || item_new->item_code >200)
		{
			printf("Out of range");
			continue;
		}
		else
		{
			it *ptr;
			for(ptr=start;(ptr) && ptr -> item_code!=item_new->item_code;ptr= ptr->next);
			if (ptr)
			{
				printf("\n %d Item code already exists. Enter another item code",item_new->item_code);
				continue;
			}
			else
				break;
		}		
	}
	while(1)
	{
		printf("Enter item name:\n");
		scanf("%s",item_new->item_name);
		int len=strlen(item_new->item_name);
		if(len<5 || len>19)
		{
			printf("Invalid.And length should be in range 5-19\n");
			continue;
		}
		int flag=0;
		for(int i=0;item_new->item_name[i]!='\0';i++)
		{
			if(!isalpha(item_new->item_name[i]))
			{
				flag=1;
				break;
			}
		}
		if(flag==1)
		{
			printf("Name should have only alphabets\n");
			continue;
		}
		else
			break;
	}
	while(1)
	{
		printf("Enter Base price of item:\n");
		scanf("%lf",&item_new->item_price);
		if(item_new->item_price < 100)
		{
			printf("\nMinimum price of item should be 100 Rs.\n");
		}
		else
			break;
	}
	if(start==NULL)
	{
		start=item_new;
		item_new->next=NULL;
	}
	else if(item_new->item_code<start->item_code)
	{
		item_new->next=start;
		start=item_new;
	}
	else
	{ 
		for(ptr=start;(ptr)&&ptr->item_code<item_new->item_code;prev=ptr,ptr=ptr->next);
		prev->next=item_new;
		item_new->next=ptr;
	}
}



			/********************** edit_item() 
		 		 EDITS ITEM DETAILS FROM THE Item_to_be_Auctioned FILE *******************/

int edit_item()
{

	if(!start)
	{
		printf(" There are no items to dsiplay");
		return(1);
	}
	int menu;
	printf("Enter item code:\n");
	scanf("%d",&menu);
	for(ptr=start;(ptr) && (ptr->item_code !=menu);ptr=ptr->next);
	if(ptr==NULL)
	{
		printf("\n %d Item_code is not found",menu);
		return(1);
	}
	printf("\n\tOld item name is %s and base price is %lf",ptr->item_name,ptr->item_price);
	printf("\n\tEnter new item name and base price :\n");
	scanf("%s %lf",ptr->item_name,&ptr->item_price);

}



			/********************** del_item() 
		 		 DELETES ITEM DETAILS FROM THE Item_to_be_Auctioned FILE *******************/

int del_item()
{
	if(!start)
	{
		printf("\n\t No items to show\n");
		return(1);
	}
	int menu;
	printf("\n\tEnter the item code:");
	scanf("%d",&menu);
	if(menu==start->item_code)
	{
		ptr=start;
		start=start->next;
		free(ptr);
	}
	else
	{
		for(ptr=start;(ptr) && ptr->item_code!=menu;prev=ptr,ptr=ptr->next);
		if(ptr==NULL)
		{
			printf("\n\tItem ccode not found:");
			return(1);
		}
		prev->next=ptr->next;
		free(ptr);
	}
}


		/************************ view_item() 
		 		DISPLAY ITEM DETAILS FROM THE Item_to_be_Auctioned FILE *******************/

int view_item()
{
	if(start)
	{
		printf("\n\tITEM CODE             ITEM  NAME         ITEM BASE PRICE\n");
		for(it *ptr = start; (ptr); ptr=ptr->next)
		{
			printf("\n\t   %d        %15s                %5.2lf \n",ptr->item_code,ptr->item_name,ptr->item_price);
		}
	}
	else
	{
		printf("\n\tNo items are not in the list to show \n");
		return(1);
	}
}
		/******************      display_item() 
		DISPLAY ITEM RANDOMNLY FROM THE Item_to_be_Auctioned FILE FOR THE AUCTION DAY *******************/

int display_item(void)
{

	srand(time(0));
	int num;
	int lower = 100, upper = 110, count=5;
	if(!start)
	{
		printf("\n\tThere are no items to display.\n");
	}
	printf("ITEM CODE          ITEM NAME          ITEM PRICE\n");
	for(int i=0;i<count;i++)
	{		 
		num=(rand() % ( upper - lower + 1))+lower;
		it *ptr;
		for(ptr=start;(ptr) && ptr->item_code!=num;ptr=ptr->next);
		if(ptr)
		{
			printf("\n%d             %s              %lf\n",ptr->item_code,ptr->item_name,ptr->item_price);
		}
	}
}
