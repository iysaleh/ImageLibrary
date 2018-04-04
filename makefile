#ImageLibraryGUI.exe : main.o
#	link /out:ImageLibraryGUI.exe main.o

main.o : main.cpp
	g++ main.cpp imlib.cpp -o ImageLibraryGUI.exe -Wall `pkg-config --cflags --libs gtk+-3.0 gtkmm-3.0 sigc++-2.0`

clean : 
	rm -rf main.o ImageLibraryGUI.exe
