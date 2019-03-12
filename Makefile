CC := g++
CXXFLAGS=-Wall -pedantic -std=c++11

# Use with `make opt=1` to optimize code
ifdef opt
	CXXFLAGS += -O3
	LDFLAGS += -O3
else
	CXXFLAGS += -g
	LDFLAGS += -g
endif


# Folders
SRCDIR := src
BUILDDIR := build
OBJDIR := $(BUILDDIR)/obj


all: init pathfinder socialgathering

maps: init $(addprefix $(OBJDIR)/,maps.o Graph.o Node.o Edge.o)
	$(CC) $(LDFLAGS) -o $(BUILDDIR)/$@ $(filter-out init,$^)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(CXXFLAGS) -c -o $@ $<


.PHONY: init
init:
	@mkdir -p $(OBJDIR)

.PHONY: clean
clean:
	@rm -rf $(BUILDDIR)
