# variables
CXXFLAGS := -std=c++11

# executable file to create and its dependancies
prog.exe : driver.o galeShapley.o
	g++ -std=c++11 -o prog driver.o galeShapley.o

# file dependencies
driver.o : galeShapley.h
	g++ -std=c++11 -c driver.cpp
galeShapley.o : galeShapley.h
	g++ -std=c++11 -c galeShapley.cpp


# files to remove
clean:
	del driver.o galeShapley.o 
	del prog.exe
