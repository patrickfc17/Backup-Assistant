include .env

CC ?= gcc
EXECUTABLE = $(APP_NAME)-$(VERSION)

BUILDDIR = build
LIBDIR = lib
SRCDIR = src
INCLUDEDIR = include

define clean
	rm $(BUILDDIR)/*/*.o
	rmdir $(filter-out $(BUILDDIR)/$(EXECUTABLE),$(wildcard $(BUILDDIR)/*))
endef

.PHONY: all clean

all: $(APP_NAME)/$(EXECUTABLE)
	$(if $(CLEAN), $(call clean))
	valgrind --leak-check=full \
		--show-leak-kinds=all \
		--track-origins=yes \
		--verbose \
		--log-file=./valgrind-journalf.txt \
		./$(BUILDDIR)/$(EXECUTABLE)

clean:
	$(call clean)

$(APP_NAME)/$(EXECUTABLE): $(APP_NAME)/$(SRCDIR) $(APP_NAME)/$(LIBDIR)
	$(CC) -o $(BUILDDIR)/$(EXECUTABLE) $(wildcard $(BUILDDIR)/*/*.o)

$(APP_NAME)/$(SRCDIR): $(wildcard $(SRCDIR)/*.c)
	mkdir -p $(BUILDDIR)
	mkdir -p $(BUILDDIR)/$(SRCDIR)
	$(foreach FILE,$(subst .c,,$(wildcard $(SRCDIR)/*.c)),$(CC) -c $(FILE).c -o $(BUILDDIR)/$(FILE).o;)

$(APP_NAME)/$(LIBDIR): $(wildcard $(LIBDIR)/*.c)
	mkdir -p $(BUILDDIR)/$(LIBDIR)
	$(foreach FILE,$(subst .c,,$(wildcard $(LIBDIR)/*.c)),$(CC) -c $(FILE).c -o $(BUILDDIR)/$(FILE).o;)
