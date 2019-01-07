ODIR = obj
SDIR = src
BDIR = bin
LDIR = lib
OUT = $(BDIR)/matrix.exe
CC = g++
INC = -Iinc
CFLAGS = -std=c++11 -g
LFLAGS = -mwindows -lopengl32 -lglu32

SOURCES = $(shell find $(SDIR) -name '*.cpp')
_OBJS = $(patsubst $(SDIR)/%.cpp, %.o, $(SOURCES))
OBJS = $(patsubst %,$(ODIR)/%,$(_OBJS))
LIBS = $(shell find $(LDIR) -name '*.lib')


$(ODIR)/%.o: $(SDIR)/%.cpp
	$(CC) -c $(INC) -o $@ $< $(CFLAGS)

$(OUT): $(OBJS)
	$(CC) -o $(OUT) $(OBJS) $(LIBS) $(LFLAGS)

clean:
	rm obj/*

test:
	./$(OUT) $(BDIR)/sample.txt
