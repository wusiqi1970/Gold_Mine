CC=g++

OBJS=main.o Cart_Point.o Cart_Vector.o Game_Object.o Game_Command.o Gold_Mine.o Miner.o Model.o Person.o Town_Hall.o View.o Soldier.o Inspector.o

default: PA4

PA4: $(OBJS)
	$(CC) -o PA4 $(OBJS) 

Cart_Vector.o: Cart_Vector.cpp Cart_Vector.h
	$(CC) -c Cart_Vector.cpp -o Cart_Vector.o 
	
Cart_Point.o: Cart_Point.cpp Cart_Point.h Cart_Vector.h
	$(CC) -c Cart_Point.cpp -o Cart_Point.o 

Game_Object.o: Game_Object.cpp Game_Object.h Cart_Point.h Cart_Vector.h
	$(CC) -c Game_Object.cpp -o Game_Object.o 

Gold_Mine.o: Gold_Mine.cpp Gold_Mine.h Game_Object.h Cart_Point.h
	$(CC) -c Gold_Mine.cpp -o Gold_Mine.o 

Miner.o: Miner.cpp Miner.h Person.h Game_Object.h Gold_Mine.h Town_Hall.h Cart_Point.h Cart_Vector.h
	$(CC) -c Miner.cpp -o Miner.o 

Model.o: Model.cpp Model.h Game_Object.h Soldier.h Person.h Town_Hall.h Gold_Mine.h Miner.h View.h
	$(CC) -c Model.cpp -o Model.o 

Town_Hall.o: Town_Hall.cpp Town_Hall.h Game_Object.h Cart_Point.h
	$(CC) -c Town_Hall.cpp -o Town_Hall.o 

View.o: View.cpp View.h Game_Object.h Cart_Point.h
	$(CC) -c View.cpp -o View.o 

Person.o: Person.cpp Person.h Game_Object.h Cart_Point.h Cart_Vector.h Town_Hall.h Gold_Mine.h
	$(CC) -c Person.cpp -o Person.o


Game_Command.o: Game_Command.cpp Game_Command.h Model.h Game_Object.h Person.h Town_Hall.h Gold_Mine.h Miner.h
	$(CC) -c Game_Command.cpp -o Game_Command.o

Soldier.o: Soldier.cpp Soldier.h Person.h Game_Object.h Gold_Mine.h Town_Hall.h Cart_Point.h Cart_Vector.h  
	$(CC) -c Soldier.cpp -o Soldier.o

main.o: main.cpp Cart_Point.h Cart_Vector.h Game_Command.h Gold_Mine.h Miner.h Model.h Person.h Town_Hall.h Game_Object.h View.h
	$(CC) -c main.cpp

Inspector.o: Inspector.cpp
	$(CC) -c Inspector.cpp -o Inspector.o


clean: 
	rm $(OBJS) PA4

