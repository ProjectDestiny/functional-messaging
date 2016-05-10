
CFLAGS=-std=c++14
# target: dependencies
# [tab] system command
all:
	g++ aesthetic-look.cpp -o messaging.out

receiver.o: receiver.cpp
	g++ $(CFLAGS) -c receiver.cpp

base-receiver.o: base-receiver.cpp
	g++ $(CFLAGS) -c base-receiver.cpp

post-office.o: post-office.cpp
	G++ $(CFLAGS) -c post-office.cpp

test: post-office.o receiver.o base-receiver.o
	g++ $(CFLAGS) test.cpp post-office.o receiver.o base-receiver.o -o tests.out

run-tests:
	./tests.out
