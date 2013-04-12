LIB=libdox.a
TARGETS=test testtxt testhtml docfrac


CPPFLAGS=-c -O2 -Icore
#CPPFLAGS=-c -O2 -g -DENABLE_LOG_DEBUG

all: ${LIB} ${TARGETS} qt-docfrac

libdox.a:
	make -C core libdox.a

testhtml: testhtml.o
	g++ -o $@ $^ -Lcore -ldox

testtxt: testtxt.o
	g++ -o $@ $^ -Lcore -ldox

test: test.o
	g++ -o $@ $^ -Lcore -ldox

docfrac: main.o 
	g++ -o $@ $^ -Lcore -ldox

  
.PHONY: clean build install

clean:
	make -C core clean
	rm -f ${TARGETS} testhtml.o testtxt.o test.o main.o

build: clean all

install: all qt-install
	install --mode=0755 -d $(ROOT)/usr/bin
	install --mode=0755 docfrac $(ROOT)/usr/bin/docfrac
	install --mode=0755 -d $(ROOT)/usr/share/man/man1/
	gzip < doc/docfrac.1 > $(ROOT)/usr/share/man/man1/docfrac.1.gz
	chmod 0644 $(ROOT)/usr/share/man/man1/docfrac.1.gz

qt-docfrac:
	qmake qt-gui/Docfrac/Docfrac.pro -o qt-gui/Docfrac/Makefile PREFIX=$(ROOT)/usr
	make -C qt-gui/Docfrac

qt-install:
	make -C qt-gui/Docfrac install	
