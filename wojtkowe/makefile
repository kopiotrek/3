output: main.o Plansza.o 
	g++ main.o Plansza.o -g -o main.out

main.o: main.cpp
	g++ -c -g main.cpp

Plansza.o: Plansza.cpp
	g++ -c -g Plansza.cpp

clean:
	rm *.o main.out