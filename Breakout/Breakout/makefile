# makefile

all: breakout

breakout: Game.o Board.o gamePiece.o Parser.o Server.o main.o
	g++ -std=c++11  -o breakout Game.o Board.o gamePiece.o Parser.o Server.o main.o
	clear


Game.o:	Game.cpp
	g++ -c -std=c++11 Game.cpp Game.h
	
Board.o: Board.cpp Board.h Game.cpp
	g++ -c -std=c++11 Board.cpp Board.h Game.cpp
	

gamePiece.o: gamePiece.h gamePiece.cpp
	g++ -c -std=c++11 gamePiece.h gamePiece.cpp
	
Parser.o: Parser.h Parser.cpp Container.h
	g++ -c -std=c++11 Parser.h Parser.cpp Container.h
	
Server.o: Server.h Server.cpp 
	g++ -c -std=c++11 Server.h Server.cpp

main.o: main.cpp
    
	g++ -c -std=c++11 main.cpp

clean:
	rm *.o
