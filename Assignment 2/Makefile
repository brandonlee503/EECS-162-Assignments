CC	=	g++
OUTPUT	=	assignment2
	
OBJECTS	=	CARD.o	DECK.o	PLAYER.o	GAME.o

#Link the object files together
${OUTPUT}	:	$(OBJECTS)
	$(CC)	$(OBJECTS)	-g	-o	${OUTPUT}

%.o	:	%.cpp
	$(CC)	-c	$<
	
clean:
	rm	-f	*.o	$(OUTPUT)
