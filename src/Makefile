CC=g++
LIBS=

volimage: driver.o volimage.o
	$(CC) -o volimage driver.o volimage.o $(LIBS)

driver.o: driver.cpp
	$(CC) -c -o driver.o driver.cpp  $(LIBS)

volimage.o: volimage.cpp volimage.h
	$(CC) -c -o volimage.o volimage.cpp  $(LIBS)

clean:
	rm -f ./*.o
	rm volimage

run:
	./volimage