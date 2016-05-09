
# target: dependencies
# [tab] system command
all:
	g++ aesthetic-look.cpp -o messaging.out

test:
	g++ test.cpp receiver.cpp base-receiver.cpp -o tests.out
