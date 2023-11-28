# Macros
COMPILER  = g++
DEBUG  = -g

# Default target: app (creates executable app)
app: term.o TermArrayList.o app.o TermDblLinkList.o TermSTLObjList.o
        $(COMPILER) -o app term.o TermArrayList.o TermDblLinkList.o TermSTLObjList.o app.o $(DEBUG)

#testLL.o: DblLink.h testLL.cpp
#       g++ testLL.cpp -c

#testll: DblLink.h testLL.cpp
#       g++ testLL.cpp -o testLL

term.o:  term.cpp term.h
        $(COMPILER) -c term.cpp $(DEBUG)

TermDblLinkList.o: term.h TermDblLinkList.cpp TermDblLinkList.h TermList.h
        $(COMPILER) -c TermDblLinkList.cpp $(DEBUG)

TermArrayList.o:  term.h TermArrayList.cpp TermArrayList.h TermList.h
        $(COMPILER) -c TermArrayList.cpp $(DEBUG)

TermSTLObjList.o: term.h TermSTLObjList.cpp TermSTLObjList.h TermList.h
        $(COMPILER) -c TermSTLObjList.cpp $(DEBUG)

app.o:  TermArrayList.h TermList.h TermSTLObjList.h TermDblLinkList.h app.cpp
        $(COMPILER) -c app.cpp $(DEBUG)

clean:
        rm -rf *.o app app.exe