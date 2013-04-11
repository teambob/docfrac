READER_OBJ=ReaderInterface.o RtfReader.o RtfCommand.o HtmlReader.o\
 HtmlCharacterMap.o HtmlCommand.o HtmlTag.o TextReader.o
WRITER_OBJ=WriterInterface.o TextWriter.o HtmlWriter.o HtmlWriter.o RtfWriter.o
HELPER_OBJ=UnicodeCharacter.o Style.o RtfStyle.o DebugLog.o Colour.o
OBJ=WriterFactory.o ReaderFactory.o ${HELPER_OBJ} ${READER_OBJ} ${WRITER_OBJ}
LIB=libdox.a


CPPFLAGS=-c -O2
#CPPFLAGS=-c -O2 -g -DENABLE_LOG_DEBUG

all: ${LIB}

libdox.a: ${OBJ}
	rm -f $@
	ar -Pcr $@ $^

  
.PHONY: clean build install

clean:
	rm -f ${OBJ} ${LIB} 

build: clean all

install:
	install --owner=root --group=root --mode=0755 docfrac /usr/bin/docfrac
	install --owner=root --group=root --mode=0644 doc/docfrac.1 /usr/share/man/man1/docfrac.1


