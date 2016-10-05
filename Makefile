# Makefile for Library
CXXFLAGS = -g

all: div main
rebuild: div clean main
main: Main.o Controller.o View.o Shop.o Robot.o Part.o Arm.o Battery.o Head.o Locomotor.o Torso.o Customer.o Associate.o Order.o
	$(CXX) $(CXXFLAGS) Main.o Controller.o View.o Shop.o Robot.o Part.o Arm.o Battery.o Head.o Locomotor.o Torso.o Order.o Customer.o Associate.o   
main.o: main.cpp Controller.hpp Shop.hpp
	$(CXX) $(CXXFLAGS) -c Main.cpp
Controller.o: Controller.cpp Controller.hpp View.o Shop.o Robot.o Associate.o Customer.o Order.o globals.hpp Date.hpp Status.hpp
	$(CXX) $(CXXFLAGS) -c controller.cpp
View.o: View.cpp View.hpp globals.hpp std_lib_facilities.h Shop.hpp
	$(CXX) $(CXXFLAGS) -c View.cpp
Shop.o: Shop.cpp Shop.hpp std_lib_facilities.h Robot.hpp Customer.hpp Associate.hpp Part.hpp Order.hpp
	$(CXX) $(CXXFLAGS) -c Shop.cpp
Order.o: Order.cpp Order.hpp std_lib_facilities.h Robot.hpp Date.hpp Status.hpp Customer.hpp Associate.hpp 
	$(CXX) $(CXXFLAGS) -c Order.cpp 
Associate.o: Associate.cpp Associate.hpp std_lib_facilities.h
	$(CXX) $(CXXFLAGS) -c Associate.cpp
Customer.o: Customer.cpp Customer.hpp std_lib_facilities.h
	$(CXX) $(CXXFLAGS) -c Customer.cpp
Robot.o: Robot.cpp Robot.hpp Part.hpp std_lib_facilities.h 
	$(CXX) $(CXXFLAGS) -c Robot.cpp
Part.o: Part.cpp Part.hpp std_lib_facilities.h  
	$(CXX) $(CXXFLAGS) -c Part.cpp
Arm.o: Arm.cpp Arm.hpp Part.hpp
	$(CXX) $(CXXFLAGS) -c Arm.cpp
Battery.o: Battery.cpp Battery.hpp Part.hpp
	$(CXX) $(CXXFLAGS) -c Battery.cpp
Head.o: Head.cpp Head.hpp Part.hpp
	$(CXX) $(CXXFLAGS) -c Head.cpp
Locomotor.o: Locomotor.cpp Locomotor.hpp Part.hpp
	$(CXX) $(CXXFLAGS) -c Locomotor.cpp
Torso.o: Torso.cpp Torso.hpp Part.hpp Arm.hpp Battery.hpp Head.hpp Locomotor.hpp
	$(CXX) $(CXXFLAGS) -c Torso.cpp

clean:
	rm -f *.o a.out
div:
	# 'X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-'
	# '-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X'
	# 'X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-'
	# '-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X'
