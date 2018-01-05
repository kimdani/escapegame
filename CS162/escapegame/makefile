CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
LDFLAGS = -lboost_date_time

OBJS = DarkRoom.o CardKeyRoom.o Room24.o Room76.o PowerRoom.o StartRoom.o ExitRoom.o Room.o Inventory.o Player.o Play.o main.o

SRCS = DarkRoom.cpp CardKeyRoom.cpp Room24.cpp Room76.cpp PowerRoom.cpp StartRoom.cpp ExitRoom.cpp Room.cpp Inventory.cpp Player.cpp Play.cpp main.cpp

HEADERS = DarkRoom.hpp CardKeyRoom.hpp Room24.hpp Room76.hpp PowerRoom.hpp StartRoom.hpp ExitRoom.hpp Room.hpp Inventory.hpp Player.hpp Play.hpp

all: escapegame

escapegame: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o escapegame
    
${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)
    
clean:
	rm *o escapegame
