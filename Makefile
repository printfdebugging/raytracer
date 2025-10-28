SRCDIR	= source
INCDIR	= include
OBJDIR	= build

CC		=  ccache g++
CFLAGS	= -g -O0 -std=c++20 -Wall -Wextra -static -I$(INCDIR) 
LFLAGS	= 
APPEXE	= $(OBJDIR)/exe
IMAGE   = $(OBJDIR)/image.ppm


SRC_FILES = $(shell find $(SRCDIR) -name '*.cpp')
OBJ_FILES = $(patsubst $(SRCDIR)%.cpp,$(OBJDIR)%.o,$(SRC_FILES))

$(APPEXE) : $(OBJ_FILES)
	$(CC) $(CFLAGS) $(LFLAGS) -o $@ $^

$(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean :
	rm -rf $(OBJDIR)

run : $(APPEXE)
	$(APPEXE) > $(IMAGE)
	[ -f "$(IMAGE)" ] && feh $(IMAGE)
