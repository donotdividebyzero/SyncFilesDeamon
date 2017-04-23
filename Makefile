CC := g++
SRCDIR := src
BUILDDIR := build
TARGET := Daemon
SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
CFLAGS := -o4 -g
LIB := -pthread -std=c++11
INC := -I include

$(TARGET): $(OBJECTS)
	@echo " Linking..."
	@echo " $(CC) $(CFLAGS) $(LIB) -o $(TARGET) $^"; $(CC) $(CFLAGS) $(LIB) -o $(TARGET) $^

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	@echo " $(CC) $(CFLAGS) $(LIB) $(INC) -c -o $@ $<"; $(CC) $(CFLAGS) $(LIB) $(INC) -c -o $@ $<

clean:
	@echo " Cleaning...";
	@echo " $(RM) -r $(BUILDDIR) $(TARGET)"; $(RM) -r $(BUILDDIR) $(TARGET)

.PHONY: clean
