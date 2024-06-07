#===============================================================================
# Directories
#===============================================================================

export SERVER_DIR = $(CURDIR)/server
export CLIENT_DIR = $(CURDIR)/client
export BINARIES_DIR = $(CURDIR)/bin

export BINARIES = $(BINARIES_DIR)/$(wildcard *.elf)

#===============================================================================
# Toolchain
#===============================================================================

export CC = gcc

#===============================================================================
# Toolchain Configuration
#===============================================================================

# Gcc flags.
export CFLAGS += -Wall -Wextra -Werror
export CFLAGS += -Winit-self -Wswitch-default -Werror
export CFLAGS += -Wshadow -Wuninitialized -Wlogical-op
export CFLAGS += -Wvla -Wredundant-decls
export CFLAGS += -pedantic-errors

.PHONY: all server client

all: clean makedir server client

server:
	$(MAKE) -C $(SERVER_DIR) all

client:
	$(MAKE) -C $(CLIENT_DIR) all

makedir:
	mkdir $(CURDIR)/bin

clean:
	rm -rf $(BINARIES)
