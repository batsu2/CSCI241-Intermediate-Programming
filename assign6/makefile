#
# PROGRAM:    assign6
# PROGRAMMER: Bryan Butz
# LOGON ID:   z1836033
# DATE DUE:   4/10/2018
#

# Compiler variables
CCFLAGS = -Wall -std=c++11

# Rule to link object code files to create executable file
assign6: assign6.o
	g++ $(CCFLAGS) -o assign6 assign6.o 
   
# Rules to compile source code files to object code
assign6.o: assign6.cpp
	g++ $(CCFLAGS) -c assign6.cpp
	         
# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assign6

