CC=g++
LIBS=

volimage: driver.o 
	$(CC) -o volimage driver.o $(LIBS)

driver.o: driver.cpp
	$(CC) -c -o driver.o driver.cpp  $(LIBS)

clean:
	rm -f ./*.o
	rm volimage

run:
	./volimage