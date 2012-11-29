CPP = g++
SRC = simple_run.cpp
OUT = web
CPPFLAGS = # -O2 -Wall
LDFLAGS =

all: build run

build: $(SRC)
	@echo Compiling $(basename $<)...
	$(CPP) $(CPPFLAGS) $(SRC) -o $(OUT) $(LDFLAGS)

run:
	./$(OUT)

install: build
	sudo cp $(OUT) /usr/bin

uninstall:
	sudo rm -rf /usr/bin/$(OUT)

clean:
	rm -rf *.dSYM
