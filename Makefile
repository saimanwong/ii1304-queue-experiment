CC = gcc
CFLAGS = -Wall -pedantic -ansi -O2 -g -I.

SINGLY_LINKED_LIST = -DDATA_STRUCTURE=1 -DHELPER_FUNCTION=0
DOUBLY_LINKED_LIST = -DDATA_STRUCTURE=2 -DHELPER_FUNCTION=1
DOUBLY_LINKED_LIST_AVG = -DDATA_STRUCTURE=3 -DHELPER_FUNCTION=1
ARRAY_PRIORITY = -DDATA_STRUCTURE=4 -DHELPER_FUNCTION=0

SRCDIR = src



all : singly_linked_list \
	doubly_linked_list \
	doubly_linked_list_avg \
	array_priority

singly_linked_list : $(SRCDIR)/main.c $(SRCDIR)/queues.c
	$(CC) $(CFLAGS) $(SINGLY_LINKED_LIST) \
		$(SRCDIR)/main.c $(SRCDIR)/queues.c -o $@

doubly_linked_list : $(SRCDIR)/main.c $(SRCDIR)/queues.c
	$(CC) $(CFLAGS) $(DOUBLY_LINKED_LIST) \
		$(SRCDIR)/main.c $(SRCDIR)/queues.c -o $@

doubly_linked_list_avg : $(SRCDIR)/main.c $(SRCDIR)/queues.c
	$(CC) $(CFLAGS) $(DOUBLY_LINKED_LIST_AVG) \
		$(SRCDIR)/main.c $(SRCDIR)/queues.c -o $@

array_priority : $(SRCDIR)/main.c $(SRCDIR)/queues.c
	$(CC) $(CFLAGS) $(ARRAY_PRIORITY) \
		$(SRCDIR)/main.c $(SRCDIR)/queues.c -o $@

clean:
	rm -rf singly_linked_list
	rm -rf doubly_linked_list
	rm -rf doubly_linked_list_avg
	rm -rf array_priority
