#  program1
CXX = g++
CXXFLAGS = -std=c++11 -I/usr/include/boost
LDFLAGS = -lboost_date_time

program1: program1.o
	$(CXX) -o program1 program1.o $(LDFLAGS)

program1.o: program1.cpp
	$(CXX) $(CXXFLAGS) -c program1.cpp

clean:
	rm -f *.o program1

#  program2
CXX = g++
CXXFLAGS = -std=c++11
LDFLAGS = -lsqlite3

program2: program2.o
	$(CXX) -o program2 program2.o $(LDFLAGS)

program2.o: program2.cpp
	$(CXX) $(CXXFLAGS) -c program2.cpp

clean:
	rm -f *.o program2 example.db
