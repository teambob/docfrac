LIB=libdox.a
TARGETS=test testtxt testhtml docfrac


CPPFLAGS=-c -O2 -Icore
#CPPFLAGS=-c -O2 -g -DENABLE_LOG_DEBUG

all: ${LIB} ${TARGETS}

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

install:
	install --owner=root --group=root --mode=0755 docfrac /usr/bin/docfrac
	install --owner=root --group=root --mode=0644 doc/docfrac.1 /usr/share/man/man1/docfrac.1


