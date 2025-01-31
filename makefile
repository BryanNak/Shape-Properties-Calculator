program: shapePropertiesCalculator.o
	g++ shapePropertiesCalculator.o -o program

shapePropertiesCalculator.o: shapePropertiesCalculator.cpp
	g++ -c shapePropertiesCalculator.cpp 
