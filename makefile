OBJS = heapsort.o heap.o DlinkList.o treenode.o listnode.o

heapsort: $(OBJS)
	gcc -Wall -g $(OBJS) -o heapsort
	
heapsort.o: heapsort.c heap.h treenode.h
	gcc -Wall -g -c heapsort.c
	
heap.o: heap.c DlinkList.h
	gcc -Wall -g -c heap.c
	
DlinkList.o: DlinkList.c listnode.h
	gcc -Wall -g -c DlinkList.c
	
clean:
	rm -f *.o
	
run: heapsort
	heaport -d inst1
	
