PROJECT	:= plug-standard
VERSION := 0.0.1

SRCDIR	:= src
BUILDDIR:= build
OBJDIR 	:= $(BUILDDIR)/obj
BINDIR	:= $(BUILDDIR)/bin

SRCEXT	:= cpp
HEADEXT	:= h
OBJEXT	:= o

CC:=clang++

CWARN:=-Wall -Wextra -Weffc++ -Wcast-align -Wcast-qual -Wchar-subscripts\
-Wctor-dtor-privacy -Wempty-body -Wfloat-equal -Wformat-nonliteral\
-Wformat-security -Wformat=2 -Winline -Wnon-virtual-dtor -Woverloaded-virtual\
-Wpacked -Wpointer-arith -Wredundant-decls -Wsign-promo -Wstrict-overflow=2\
-Wswitch-default -Wswitch-enum -Wundef -Wunreachable-code -Wunused\
-Wvariadic-macros -Wno-missing-field-initializers -Wno-narrowing\
-Wno-old-style-cast -Wno-varargs -Werror

INCFLAGS:=-I$(SRCDIR)
CFLAGS:=-std=c++17 -fPIE $(CWARN) $(INCFLAGS)

CFORMAT  :=clang-format
FMTFLAGS :=--dry-run -Werror -ferror-limit=1

CTIDY     :=clang-tidy
TIDYCHECKS:=-*,clang-analyzer-*,cert-*
TIDYFLAGS :=--checks=$(TIDYCHECKS) --quiet --warnings-as-errors=*
TIDYFLAGS +=$(foreach flag, $(CFLAGS),--extra-arg=$(flag))

HEADERS := $(shell find $(SRCDIR) -type f -name "*.$(HEADEXT)")
SOURCES := $(shell find $(SRCDIR) -type f -name "*.$(SRCEXT)")
OBJECTS	:= $(patsubst $(SRCDIR)/%,$(OBJDIR)/%,$(SOURCES:.$(SRCEXT)=.$(OBJEXT)))

CHECKDIR :=$(BUILDDIR)/check
CHECKMAIN:=$(CHECKDIR)/main.cpp
CHECKFILE:=$(CHECKDIR)/check.cpp
CHECKINC :=$(patsubst $(SRCDIR)/%,%,$(HEADERS))

init:
	@mkdir -p $(OBJDIR)
	@mkdir -p $(BINDIR)
	@mkdir -p $(CHECKDIR)

all: $(OBJECTS)

remake: clean all

# Build source objects
$(OBJDIR)/%.$(OBJEXT): $(SRCDIR)/%.$(SRCEXT)
	@echo -n "Building $@ ... "
	@mkdir -p $(dir $@)
	@$(CTIDY) $(TIDYFLAGS) $<
	@$(CC) $(CFLAGS) $(INCFLAGS) -c $< -o $@
	@echo done!

$(CHECKMAIN): init
	@echo -n "Creating main checker file '$@' ... "
	@$(foreach inc, $(CHECKINC), echo \#include \"$(inc)\" >> $@;)
	@echo "int main() { return 0; }" >> $@
	@echo done!

$(CHECKFILE): init
	@echo -n "Creating checker file '$@' ... "
	@$(foreach inc, $(CHECKINC), echo \#include \"$(inc)\" >> $@;)
	@echo done!


compile_check: $(CHECKFILE) $(CHECKMAIN) $(OBJECTS)
	@echo "Checking compilation..."
	@$(CTIDY) $(TIDYFLAGS) $(CHECKFILE) $(CHECKMAIN)
	@$(CC) $(CFLAGS) $(INCFLAGS) $^ -o /dev/null
	@rm $(CHECKFILE) $(CHECKMAIN)
	@echo "Project compiled successfully"

format:
	@$(foreach header, $(HEADERS),\
		$(CFORMAT) -i $(header);)
	@$(foreach source, $(SOURCES),\
		$(CFORMAT) -i $(source);)

format_check:
	@$(foreach header, $(HEADERS),\
		$(CFORMAT) $(FMTFLAGS) $(header);)
	@$(foreach source, $(SOURCES),\
		$(CFORMAT) $(FMTFLAGS) $(source);)

check: clean compile_check format_check

clean:
	@rm -rf $(OBJDIR) $(BINDIR) $(CHECKDIR)

.PHONY: all remake clean cleaner check compile_check format_check init

