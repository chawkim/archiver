CXX := g++
COMPILE_FLAGS := -std=c++20 -Wall -Wextra -o
LINK_FLAGS := 
SOURCE_FILES := main.cpp archiver.cpp
EXECUTABLE := arc

all: compile run

compile: ${SOURCE_FILES}
	${CXX} ${SOURCE_FILES} ${COMPILE_FLAGS} ${EXECUTABLE} ${LINK_FLAGS} 

run:
	./${EXECUTABLE}

clean: ${EXECUTABLE}
	rm ${EXECUTABLE}
	clear
