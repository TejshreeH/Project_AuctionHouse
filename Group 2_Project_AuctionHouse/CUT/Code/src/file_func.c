/*******************************************************************************************************************
 * * FILE NAME : file_func.c 
 *
 *
 * * DESCRIPTION : This file contains file handling functions which transfers the file into linked list 
 * 		   and linked list into the file
 *
 *
 * * FUNCTION NAME :  bidder_list_to_file(), item_list to file(), auction_list_to_file()
 * 		      bidder_file_to_list(), item_file_to_list(), auction_file_to_list()
 * 		      check_password();
 *
*******************************************************************************************************************/
#include <stdio.h>
#include <termios.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "auctionheader.h"

			/*Writes the contents of the linked list to Reg Bidder file*/

int bidder_list_to_file()
{

	fp=fopen("Reg_Bidder","w");
	for(ptr1=start1;(ptr1);ptr1= ptr1 ->next1)
	{
		fwrite(ptr1,sizeof(bder),1,fp);
	}
	fclose(fp);
}

			/*Writes the contents of the linked list to auction file*/

int auction_list_to_file()
{
	fp=fopen("auction","w");
	for(a_ptr=a_start;(a_ptr);(a_ptr)=a_ptr->a_next)
	{
		fwrite(a_ptr,sizeof(aday),1,fp);
	}
	fclose(fp);
}


			/*Reads the contents from the auction file to linked list*/

int auction_file_to_list()
{
	aday *a_last;
	if((fp=fopen("auction","r"))==NULL)
	{
		return(1);
        }
	a_new=(aday *)malloc(sizeof(aday));
	fread(a_new,sizeof(aday),1,fp);
	while(!feof(fp))
        {
		if(!a_start)
		{
			a_start=a_last=a_new;
			a_new->a_next=NULL;
		}
		else
		{
			a_last->a_next=a_new;
	         	a_last=a_new;
			a_new->a_next=NULL;
		}
	
		a_new=(aday *)malloc(sizeof(aday));
		fread(a_new,sizeof(aday),1,fp);
	}
}



			/*Reads the content from the Reg_Bidder file to linked list*/

int bidder_file_to_list()
{
	bder *last1;
	//FILE *fp;
	if((fp=fopen("Reg_Bidder", "r"))==NULL)
	{
		printf("\nBidder file doesn't exist");
		return(1);
	}
	new1=(bder *)malloc(sizeof(bder));
	fread(new1,sizeof(bder),1,fp);
	while(!feof(fp))
	{
		if(!start1)
		{
			start1=last1=new1;
			new1 ->next1=NULL;
		}
		else
		{
			last1 ->next1=new1;
		      	last1=new1;
			new1 ->next1=NULL;
		}
		new1=(bder *)malloc(sizeof(bder));
		fread(new1,sizeof(bder),1,fp);
	}
}



			/*Writes the contents of the linked list to Item_to_be_auctioned file*/


int item_list_to_file()
{
	fp=fopen("Item_to_be_auctioned","w");
	for(ptr=start;(ptr);ptr=ptr->next)
	{
		fwrite(ptr,sizeof(it),1,fp);
	}
	fclose(fp);
}



			/*Reads the content from the Item_to_be_auctioned file to linked list*/

int item_file_to_list()
{
	it *last;
	//FILE *fp
	if((fp=fopen("Item_to_be_auctioned","r"))==NULL)
	{
		printf("\nItem file not present");
		return(1);
	}
	item_new=(it *)malloc(sizeof(it));
	fread(item_new,sizeof(it),1,fp);
	while(!feof(fp))
	{
		if(!start)
		{
			start=last=item_new;
			item_new->next=NULL;
		}
		else
		{
			last->next=item_new;
			last=item_new;
			item_new->next=NULL;
		}
		item_new=(it *)malloc(sizeof(it));
		fread(item_new,sizeof(it),1,fp);
	}
}


			/*To add password functionality to the system */

ssize_t getpasswd (char **pw, size_t sz, int mask, FILE *fp)
{
	if (!pw || !sz || !fp)
	       	return -1;       /* validate input   */
#ifdef MAXPW
	if (sz > MAXPW)
	       	sz = MAXPW;
#endif
	if (*pw == NULL)
       	{              /* reallocate if no address */
		void *tmp = realloc (*pw, sz * sizeof **pw);
		if (!tmp)
			return -1;
		memset (tmp, 0, sz);    /* initialize memory to 0   */
		*pw =  (char*) tmp;
	}

	size_t idx = 0;         /* index, number of chars in read   */
	int c = 0;

	struct termios old_kbd_mode;    /* orig keyboard settings   */
	struct termios new_kbd_mode;

	if (tcgetattr (0, &old_kbd_mode)) { /* save orig settings   */
		fprintf (stderr, "%s() error: tcgetattr failed.\n", __func__);
		return -1;
	}   /* copy old to new */
	memcpy (&new_kbd_mode, &old_kbd_mode, sizeof(struct termios));

	new_kbd_mode.c_lflag &= ~(ICANON | ECHO);  /* new kbd flags */
	new_kbd_mode.c_cc[VTIME] = 0;
	new_kbd_mode.c_cc[VMIN] = 1;
	if (tcsetattr (0, TCSANOW, &new_kbd_mode))
       	{
		fprintf (stderr, "%s() error: tcsetattr failed.\n", __func__);
		return -1;
	}

	/* read chars from fp, mask if valid char specified */
	while (((c = fgetc (fp)) != '\n' && c != EOF && idx < sz - 1) || (idx == sz - 1 && c == 127))
	{
		if (c != 127) {
			if (31 < mask && mask < 127)    /* valid ascii char */
				fputc (mask, stdout);
			(*pw)[idx++] = c;
		}
		else if (idx > 0) {         /* handle backspace (del)   */
			if (31 < mask && mask < 127) {
				fputc (0x8, stdout);
				fputc (' ', stdout);
				fputc (0x8, stdout);
			}
			(*pw)[--idx] = 0;
		}
	}
	(*pw)[idx] = 0;   

	/* reset original keyboard  */
	if (tcsetattr (0, TCSANOW, &old_kbd_mode)) 
	{
		fprintf (stderr, "%s() error: tcsetattr failed.\n", __func__);
		return -1;
	}

	if (idx == sz-1 && c!='\n') /* warn if pw truncated */
		fprintf (stderr, " (%s() warning: truncated at %zu chars.)\n", __func__, sz - 1);

	return idx; /* number of chars in passwd    */
}


			/*..................Password Authentication....................*/

int check_Password()
{
	char pw[MAXPW]={0};
	char *p=pw;
	FILE *fp=stdin;
	ssize_t nchr=0;
	nchr=getpasswd(&p,MAXPW,'*',fp);
	printf("\n Enter password:");
	nchr=getpasswd(&p,MAXPW,'*',fp);
	if(strcmp(p,"Auction@")==0 || strcmp(p, "abc")==0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
