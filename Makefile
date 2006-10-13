READER_OBJ=ReaderInterface.o RtfReader.o RtfCommand.o HtmlReader.o\
 HtmlCharacterMap.o
WRITER_OBJ=WriterInterface.o TextWriter.o HtmlWriter.o HtmlWriter.o RtfWriter.o
HELPER_OBJ=UnicodeCharacter.o Style.o RtfStyle.o debug.o
OBJ=DoxFactory.o DoxInterface.o ${HELPER_OBJ} ${READER_OBJ} ${WRITER_OBJ}
LIB=libdox.a
TARGETS=test testtxt testhtml docfrac

CPPFLAGS=-c -g -Os

all: ${LIB} ${TARGETS}

libdox.a: ${OBJ}
	rm -f $@
	ar -Pcr $@ $^

testhtml: testhtml.o libdox.a
	gcc -o $@ $^ -lstdc++

testtxt: testtxt.o libdox.a
	gcc -o $@ $^ -lstdc++

test: test.o libdox.a
	gcc -o $@ $^ -lstdc++

docfrac: main.o libdox.a
	gcc -o $@ $^ -lstdc++

  
.PHONY: clean build install

clean:
	rm -f ${OBJ} ${LIB} ${TARGETS} testhtml.o testtext.o test.o main.o

build: clean all

install:
	install --owner=root --group=root --mode=0755 docfrac /usr/bin/docfrac
	install --owner=root --group=root --mode=0644 doc/docfrac.1 /usr/share/man/man1/docfrac.1


