main.out: udp_client.o testing.o
	g++ -o main.out udp_client.o testing.o

testing.o: ./test_server/testing.cpp ./0_headers/test_server/testing.h
	g++ -g -c ./test_server/testing.cpp 

udp_client.o: udp_client.cpp
	g++ -g -c udp_client.cpp

clean:
	rm *.i *.o *.out