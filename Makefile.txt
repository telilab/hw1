PROJ = hw1
OBJS = solution.o homework1.o

CC = gcc
CFLAGS = -g -Wall
LIBS = -lstdc++

$(PROJ).exe : $(OBJS)
	$(CC) -o $@ $(OBJS) $(LIBS)


%.o : %.cpp solution.h
	$(CC) -c -o $@ $< $(CFLAGS) 

clean : 
	rm -f *.o $(PROJ).exe
