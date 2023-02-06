all: proj3.exe 

project3.o: project3.cpp constants.h RowColumnClass.h ColorClass.h RectangleClass.h PatternClass.h ColorImageClass.h mainMenu.h colorSelect.h CheckCin.h
	g++ -std=c++98 -g -Wall -c project3.cpp -o project3.o

RowColumnClass.o: RowColumnClass.cpp RowColumnClass.h constants.h
	g++ -std=c++98 -g -Wall -c RowColumnClass.cpp -o RowColumnClass.o

ColorClass.o: ColorClass.cpp ColorClass.h constants.h
	g++ -std=c++98 -g -Wall -c ColorClass.cpp -o ColorClass.o

RectangleClass.o: RectangleClass.cpp RectangleClass.h constants.h ColorClass.h RowColumnClass.h
	g++ -std=c++98 -g -Wall -c RectangleClass.cpp -o RectangleClass.o

PatternClass.o: PatternClass.cpp PatternClass.h ColorClass.h constants.h RowColumnClass.h RectangleClass.h ColorImageClass.h
	g++ -std=c++98 -g -Wall -c PatternClass.cpp -o PatternClass.o

ColorImageClass.o: ColorImageClass.cpp ColorImageClass.h constants.h RowColumnClass.h ColorClass.h RectangleClass.h PatternClass.h
	g++ -std=c++98 -g -Wall -c ColorImageClass.cpp -o ColorImageClass.o

mainMenu.o: mainMenu.cpp mainMenu.h constants.h
	g++ -std=c++98 -g -Wall -c mainMenu.cpp -o mainMenu.o

colorSelect.o: colorSelect.cpp colorSelect.h
	g++ -std=c++98 -g -Wall -c colorSelect.cpp -o colorSelect.o

CheckCin.o: CheckCin.cpp CheckCin.h constants.h
	g++ -std=c++98 -g -Wall -c CheckCin.cpp -o CheckCin.o

proj3.exe: project3.o RowColumnClass.o ColorClass.o RectangleClass.o PatternClass.o ColorImageClass.o mainMenu.o colorSelect.o CheckCin.o  
	g++ -std=c++98 project3.o RowColumnClass.o ColorClass.o RectangleClass.o PatternClass.o ColorImageClass.o mainMenu.o colorSelect.o CheckCin.o -o proj3.exe

clean:
	rm -f *.o *.exe