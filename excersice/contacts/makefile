cc = g++

ifeq ($(OS), Windows_NT)
	#Windows stuff
else
	#Linux stuff
endif

appname = app.exe
$(appname) : people.o contact.o ui.o app.o
	$(cc) -o app.exe people.o contact.o ui.o app.o

people.o : people.h people.cpp
	$(cc) -c people.cpp
contact.o : people.h contact.h contact.cpp
	$(cc) -c contact.cpp
ui.o : people.h contact.h ui.h ui.cpp
	$(cc) -c -std=c++11 ui.cpp
app.o : people.h contact.h ui.h app.cpp
	$(cc) -c -std=c++11 app.cpp

.PHONY : clean
clean:
	-$(RM) $(appname) people.o contact.o app.o