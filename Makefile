CC=g++
CFLAGS=-std=c++17 -Wall -g

# The name of the source file that contains the hardcoded test cases
SIMPLE_TEST_MAIN=main.cpp

# Must set this to the name of the file that implements hash_list.h
HASH_LIST_SRC=hash_list.cpp

# The name of the resulting executable
APP=test

custom_tests:
	$(CC) $(CFLAGS) $(SIMPLE_TEST_MAIN) $(HASH_LIST_SRC) -o $(APP)	

instructor_tests: $(APP).o
	$(CC) $(CFLAGS) $^ $(HASH_LIST_SRC) -o $(APP)	

clean:
	rm -f $(APP)
	rm -f *.tar
