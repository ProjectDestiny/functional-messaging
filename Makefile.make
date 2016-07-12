
CFLAGS=-std=c++14 -stdlib=libc++
PROJECT_NAME=functional-messaging

# target: dependencies
# [tab] system command
all:
	g++ aesthetic-look.cpp -o messaging.out

# This section compiles each of the project files. A
base-receiver.o: base-receiver.cpp
	g++ $(CFLAGS) -c src/base-receiver.cpp

post-office.o: post-office.cpp
	g++ $(CFLAGS) -c src/post-office.cpp

test: post-office.o receiver.o base-receiver.o
	g++ $(CFLAGS) test.cpp post-office.o receiver.o base-receiver.o -o tests.out

# Could dynamically generate this list of tests by running a
# "add-test-file" script.
gtest-build:
	g++ ${CFLAGS} -isystem $(GTEST_DIR)/include -pthread \
		tests/tests-main.cpp \
		tests/receiver-tests.cpp \
		src/base-receiver.cpp \
		src/post-office.cpp \
		$(GTEST_DIR)/libgtest.a -o ${PROJECT_NAME}-tests.out

gtest-run:
	./${PROJECT_NAME}-tests.out

run-tests:
	./tests.out

clean :
	rm -f *.out *.o

# I'm thinking of a system that generates each of the parts of the
# build script independently, and then puts them all together.
# Then there would be a bash script that calls the right
# command from the make file.
