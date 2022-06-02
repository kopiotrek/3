output: main.o ttt.o 
	g++ main.o ttt.o -g -o main.out

main.o: main.cpp
	g++ -c -g main.cpp

ttt.o: ttt.cpp
	g++ -c -g ttt.cpp

clean:
	rm *.o main.out