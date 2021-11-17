#
# PROGRAM:    assign9
# PROGRAMMER: Bryan Butz
# LOGON ID:   z1836033
# DATE DUE:   4/2/18
#

# Compiler variables
CCFLAGS = -Wall -std=c++11

# Rule to link object code files to create executable file
assign9: assign9.o Shape.o Circle.o Rectangle.o Triangle.o
	g++ $(CCFLAGS) -o assign9 assign9.o Shape.o Circle.o Rectangle.o Triangle.o

# Rules to compile source code files to object code
assign9.o: assign9.cpp Shape.h
	g++ $(CCFLAGS) -c assign9.cpp

Shape.o: Shape.cpp Shape.h
	g++ $(CCFLAGS) -c Shape.cpp

Circle.o: Circle.cpp Circle.h
	g++ $(CCFLAGS) -c Circle.cpp

Rectangle.o: Rectangle.cpp Rectangle.h
	g++ $(CCFLAGS) -c Rectangle.cpp
	
Triangle.o: Triangle.cpp Triangle.h
	g++ $(CCFLAGS) -c Triangle.cpp

Shape.h: Circle.h Rectangle.h Triangle.h

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assign9

