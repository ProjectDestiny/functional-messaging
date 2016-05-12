
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
	g++ $(CFLAGS) -c post-office.cpp

test: post-office.o receiver.o base-receiver.o
	g++ $(CFLAGS) test.cpp post-office.o receiver.o base-receiver.o -o tests.out

gtest-build:
	g++ -isystem $(GTEST_DIR)/include -pthread gtest-sample.cpp $(GTEST_DIR)/libgtest.a \
        -o messaging-gtest.out

gtest-run:
	./messaging-gtest.out

run-tests:
	./tests.out

clean :
	rm -f *.out *.o	
