#ifndef AUCTIONHEADER_H
#define AUCTIONHEADER_H

FILE *fp;
#define MAXPW 32

typedef struct bidder
{
	int bidder_id;
	char bidder_name[20];
	char bidder_pan[20];
	char Deposit_status;
	double Security_Deposit;
	struct bidder *next1;
}bder;
bder *ptr1,*start1,*prev1,*new1;


typedef struct item
{
	char item_name[20];
	double item_price;
	int item_code;
	struct item *next;
}it;
it *ptr,*start,*prev,*item_new;


typedef struct auction
{
	int item_code;
	char item_name[20];
	int bidder_id;
	char bid_win_name[20];
	double bid_win_amount;
	double bid_netpayable;
	double r_deposit;
	struct auction *a_next;
}aday;
aday *a_ptr, *a_new, *a_start,*a_prev;


int add_bidder();
int edit_bidder();
int view_bidder();
int del_bidder();


int add_item();
int edit_item();
int del_item();
int view_item();

int display_item(void);


int display_bidding_report();


int auction_day();

void *auction();

ssize_t getpasswd (char **pw, size_t sz, int mask, FILE *fp);
int check_Password();


int bidder_list_to_file();
int bidder_file_to_list();

int item_list_to_file();
int item_file_to_list();


int auction_list_to_file();
int auction_file_to_list();


#endif
