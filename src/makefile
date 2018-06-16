IDIR =../include
CC=g++
CFLAGS=-I$(IDIR) -std=c++11 -g -lstdc++ -lgsl -lgslcblas `pkg-config --cflags --libs opencv`

ODIR=obj
LDIR =../lib

LIBS=-lm

_DEPS = Convertion.h InputOutput.h GLCM.h KNN.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ1 = FeatureSelection.o GLCM.o Convertion.o InputOutput.o
OBJ1 = $(patsubst %,$(ODIR)/%,$(_OBJ1))

_OBJ2 = Classify.o GLCM.o Convertion.o InputOutput.o KNN.o
OBJ2 = $(patsubst %,$(ODIR)/%,$(_OBJ2))

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

selection: $(OBJ1)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

classify: $(OBJ2)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)	

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 