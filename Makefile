include .env

BUILDDIR = build
APPNAME = backup-assistant
VERSION = 1.0
EXECUTABLE = $(BUILDDIR)/$(APPNAME)-$(VERSION)

default:
	mkdir -p $(BUILDDIR)
	make $1 start

start: main.o
	$(CC) -o $(EXECUTABLE) $(wildcard $(BUILDDIR)/*.o)
	$(if $(CLEAN), rm $(wildcard $(BUILDDIR)/*.o))
	./$(EXECUTABLE)

main.o: src/main.c
	$(CC) -c $< -o $(BUILDDIR)/$@
