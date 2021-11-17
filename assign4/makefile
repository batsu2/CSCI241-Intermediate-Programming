#
# PROGRAM:    assign4
# PROGRAMMER: Bryan Butz
# LOGON ID:   z1836033
# DATE DUE:   3/8/2018
#

# Compiler variables
CCFLAGS = -Wall -std=c++11

# Rule to link object code files to create executable file
assign4: assign4.o Vector3.o
	g++ $(CCFLAGS) -o assign4 assign4.o Vector3.o
   
# Rules to compile source code files to object code
assign4.o: assign4.cpp Vector3.h
	g++ $(CCFLAGS) -c assign4.cpp
      
Verifier.o: Vector3.cpp Vector3.h
	g++ $(CCFLAGS) -c Vector3.cpp
         
# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assign4

