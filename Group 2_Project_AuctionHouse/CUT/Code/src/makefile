
OBJS = main.o #Auction_main.o AuctionHouse_Bidder_Func.o AuctionHouse_Item_Func.o file_func.o Auction_day_func.o
CO = gcc -o
CC = gcc -c
AM = Auction_main.c
ABF = AuctionHouse_Bidder_Func.c
AIF = AuctionHouse_Item_Func.c
FF =  file_func.c
ADF = Auction_day_func.c
RM =  rm *.o

test: $(OBJS)
	$(CO)test$(OBJS)

main.o : main.c $(AH)
	$(CC) main.c
Auction_main.o : $(AM) $(AH)
	$(CC) $(AM)

AuctionHouse_Bidder_Func.o : $(ABF) $(AH)
	$(CC) $(ABF)

AuctionHouse_Item_Func.o : $(AIF) $(AH)
	$(CC) $(AIF)

file_func.o : $(FF) $(AH)
	$(CC) $(FF)

Auction_day_func.o : $(ADF) $(AH)
	$(CC) $(ADF)

clean:
	$(RM)
