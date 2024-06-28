#===============================================================================
# Directories
#===============================================================================

export SOURCE_DIR = $(CURDIR)/src
export INCLUDE_DIR = $(CURDIR)/include
export BINARIES_DIR = $(CURDIR)/bin
export LIBRARIE_DIR = $(CURDIR)/lib

export BINARIES = $(BINARIES_DIR)/$(wildcard *.elf)

#===============================================================================
# Toolchain
#===============================================================================

export CC = gcc
export AR = ar

#===============================================================================
# Toolchain Configuration
#===============================================================================

# Gcc flags.
export CFLAGS += -Wall -Wextra -Werror
export CFLAGS += -Winit-self -Wswitch-default -Werror
export CFLAGS += -Wshadow -Wuninitialized -Wlogical-op
export CFLAGS += -Wvla -Wredundant-decls

# Ar flags.
export ARFLAGS = rcs

#===============================================================================
# Run Rules
#===============================================================================

.PHONY: all server client

all: clean makedir source

source:
	$(MAKE) -C $(SOURCE_DIR) all

makedir:
	mkdir $(CURDIR)/bin
	mkdir $(CURDIR)/lib

clean:
	$(MAKE) -C $(SOURCE_DIR) clean
	rm -rf $(BINARIES_DIR)
	rm -rf $(LIBRARIE_DIR)
