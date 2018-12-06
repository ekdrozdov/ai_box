ODIR = obj
SDIR = src
BDIR = bin
OUT = $(BDIR)/matrix.exe
CC = g++
INC = -Iinc
CFLAGS = -std=c++11

SOURCES = $(shell find $(SDIR) -name '*.cpp')
_OBJS = $(patsubst $(SDIR)/%.cpp, %.o, $(SOURCES))
OBJS = $(patsubst %,$(ODIR)/%,$(_OBJS))


$(ODIR)/%.o: $(SDIR)/%.cpp
	$(CC) -c $(INC) -o $@ $< $(CFLAGS)

$(OUT): $(OBJS)
	$(CC) -o $(OUT) $(OBJS)



clean:
	rm obj/*

test:
	./$(OUT) $(BDIR)/sample.txt
