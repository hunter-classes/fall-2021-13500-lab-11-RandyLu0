main: main.o profile.o network.o
	g++ -o main main.o profile.o network.o
tests: tests.o profile.o network.o
	g++ -o tests tests.o profile.o network.o
main.o: profile.h main.cpp network.h
	g++ -c main.cpp
tests.o: profile.h tests.cpp network.h
	g++ -c tests.cpp
profile.o: profile.h profile.cpp
	g++ -c profile.cpp
network.o: network.cpp network.h profile.h
	g++ -c network.cpp
clean:
	rm -f main.o tests.o profile.o network.o
