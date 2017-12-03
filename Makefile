CC = gcc
CFLAGS = -Wall -pedantic -ansi -O2 -g -I.
MKDIR_P = mkdir -p
.PHONY: directories

SINGLY_LINKED_LIST = -DDATA_STRUCTURE=1 -DHELPER_FUNCTION=0 -DTEST_CORRECTNESS=0
DOUBLY_LINKED_LIST = -DDATA_STRUCTURE=2 -DHELPER_FUNCTION=1 -DTEST_CORRECTNESS=0
DOUBLY_LINKED_LIST_AVG = -DDATA_STRUCTURE=3 -DHELPER_FUNCTION=1 -DTEST_CORRECTNESS=0
ARRAY_PRIORITY = -DDATA_STRUCTURE=4 -DHELPER_FUNCTION=0 -DTEST_CORRECTNESS=0

SINGLY_LINKED_LIST_TEST_CORRECTNESS = -DDATA_STRUCTURE=1 -DHELPER_FUNCTION=0 -DTEST_CORRECTNESS=1
DOUBLY_LINKED_LIST_TEST_CORRECTNESS = -DDATA_STRUCTURE=2 -DHELPER_FUNCTION=1 -DTEST_CORRECTNESS=0
DOUBLY_LINKED_LIST_AVG_TEST_CORRECTNESS = -DDATA_STRUCTURE=3 -DHELPER_FUNCTION=1 -DTEST_CORRECTNESS=1
ARRAY_PRIORITY_TEST_CORRECTNESS = -DDATA_STRUCTURE=4 -DHELPER_FUNCTION=0 -DTEST_CORRECTNESS=1

SRCDIR = src
OBJDIR = obj

all : dir \
	$(OBJDIR)/singly_linked_list \
	$(OBJDIR)/doubly_linked_list \
	$(OBJDIR)/doubly_linked_list_avg \
	$(OBJDIR)/array_priority \
	$(OBJDIR)/singly_linked_list_test_correctness \
	$(OBJDIR)/doubly_linked_list_test_correctness \
	$(OBJDIR)/doubly_linked_list_avg_test_correctness \
	$(OBJDIR)/array_priority_test_correctness

$(OBJDIR)/singly_linked_list : $(SRCDIR)/main.c $(SRCDIR)/queues.c
	$(CC) $(CFLAGS) $(SINGLY_LINKED_LIST) \
		$(SRCDIR)/main.c $(SRCDIR)/queues.c -o $@

$(OBJDIR)/doubly_linked_list : $(SRCDIR)/main.c $(SRCDIR)/queues.c
	$(CC) $(CFLAGS) $(DOUBLY_LINKED_LIST) \
		$(SRCDIR)/main.c $(SRCDIR)/queues.c -o $@

$(OBJDIR)/doubly_linked_list_avg : $(SRCDIR)/main.c $(SRCDIR)/queues.c
	$(CC) $(CFLAGS) $(DOUBLY_LINKED_LIST_AVG) \
		$(SRCDIR)/main.c $(SRCDIR)/queues.c -o $@

$(OBJDIR)/array_priority : $(SRCDIR)/main.c $(SRCDIR)/queues.c
	$(CC) $(CFLAGS) $(ARRAY_PRIORITY) \
		$(SRCDIR)/main.c $(SRCDIR)/queues.c -o $@

$(OBJDIR)/singly_linked_list_test_correctness : $(SRCDIR)/main.c $(SRCDIR)/queues.c
	$(CC) $(CFLAGS) $(SINGLY_LINKED_LIST_TEST_CORRECTNESS) \
		$(SRCDIR)/main.c $(SRCDIR)/queues.c -o $@

$(OBJDIR)/doubly_linked_list_test_correctness : $(SRCDIR)/main.c $(SRCDIR)/queues.c
	$(CC) $(CFLAGS) $(DOUBLY_LINKED_LIST_TEST_CORRECTNESS) \
		$(SRCDIR)/main.c $(SRCDIR)/queues.c -o $@

$(OBJDIR)/doubly_linked_list_avg_test_correctness : $(SRCDIR)/main.c $(SRCDIR)/queues.c
	$(CC) $(CFLAGS) $(DOUBLY_LINKED_LIST_AVG_TEST_CORRECTNESS) \
		$(SRCDIR)/main.c $(SRCDIR)/queues.c -o $@

$(OBJDIR)/array_priority_test_correctness : $(SRCDIR)/main.c $(SRCDIR)/queues.c
	$(CC) $(CFLAGS) $(ARRAY_PRIORITY_TEST_CORRECTNESS) \
		$(SRCDIR)/main.c $(SRCDIR)/queues.c -o $@

dir: ${OBJDIR}

${OBJDIR}:
	${MKDIR_P} ${OBJDIR}

clean:
	rm -rf $(OBJDIR)/*
