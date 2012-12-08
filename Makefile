CPP = g++
SRC = demo.cpp
OUT = demo
CPPFLAGS =
LDFLAGS =

all: build

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
