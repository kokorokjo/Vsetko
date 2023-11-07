#program name
PROGRAM = player
#build file
OBJDIR = build

#c++ compiler
CC = g++
CFLAGS = -o3 -std=gnu++20 -Wall -Wextra -Wpedantic
CSOURCES := $(wildcard *.cpp)
HSOURCES := $(wildcard *.h)
COBJECTS := $(CSOURCES:%.cpp=$(OBJDIR)/%.o)

#linker
LINKER = g++
LFLAGS =

# colors
Color_Off = '\033[0m'
Black = '\033[1;30m'
Red = '\033[1;31m'
Green = '\033[1;32m'
Yellow = '\033[1;33m'
Blue = '\033[1;34m'
Purple = '\033[1;35m'
Cyan = '\033[1;36m'
White = '\033[1;37m'

all: $(PROGRAM) $(PROGRAM).tar.gz

$(PROGRAM): $(COBJECTS) $(NOBJECTS)
	@$(LINKER) $(COBJECTS) $(NOBJECTS) -o $@ $(LFLAGS)
	@echo -e $(Yellow)"Linking complete!"$(Color_Off)

$(COBJECTS): $(OBJDIR)/%.o : %.cpp
	@mkdir -p $(OBJDIR)
	@echo -e $(Blue)"C++ compiling "$(Purple)$<$(Color_Off)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo -e $(Blue)"C++ compiled "$(Purple)$<$(Blue)" successfully!"$(Color_Off)

$(PROGRAM).tar.gz: $(CSOURCES) Makefile
	@echo -e $(Green)"Making tar for submit..."$(Color_Off)
	@tar -czf $@ $(CSOURCES) $(HSOURCES) Makefile
	@echo -e $(Green)"Tar successfully created!"$(Color_Off)

.PHONY: clean all run

run: $(PROGRAM)
	@./$<

clean:
	@rm -f $(PROGRAM) $(COBJECTS) $(PROGRAM).tar.gz
	@echo -e $(Cyan)"Cleaning Complete!"$(Color_Off)

