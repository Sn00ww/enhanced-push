CC			:= g++
SRCDIR 		:= src
BUILDDIR 	:= build
BINDIR 		:= bin
TARGET 		:= $(BINDIR)/push

SRCEXT 		:= cpp
SOURCES 	:= $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS 	:= $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))

CXXFLAGS	:= -Wall -Wextra -Werror -Wno-unused-parameter
CPPFLAGS	:= -I include
LDFLAGS		:= -L lib

$(TARGET): $(OBJECTS)
	@ echo "\033[1;32mCompiling project...\033[0m"
	@ mkdir -p $(BINDIR)
	@ echo "$(CC) $^ -o $(TARGET) $(LDFLAGS)"; $(CC) $^ -o $(TARGET) $(LDFLAGS)
	@ echo "\033[1;34m[OK] \033[1;32mCompiled project\033[0m\033[1;31m [$(TARGET)]\033[0m"

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@ mkdir -p $(BUILDDIR)
	@ echo "$(CC) $(CXXFLAGS) $(CPPFLAGS) -c -o $@ $<"; $(CC) $(CXXFLAGS) $(CPPFLAGS) -c -o $@ $<

clean:
	@ echo "\033[1;32mCleaning project...\033[0m"
	@ echo "$(RM) -r $(BUILDDIR) $(TARGET) $(BINDIR)"; $(RM) -r $(BUILDDIR) $(TARGET) $(BINDIR)
	@ echo "\033[1;34m[OK] \033[1;32mCleaned project\033[0m\033[1;31m [$(TARGET)]\033[0m"

tester:
	@ $(CC) $(CFLAGS) test/tester.cpp $(INC) $(LIB) -o bin/tester

re: clean $(TARGET)

.PHONY: clean
