# Compile clients

#===============================================================================
# Artifacts
#===============================================================================

# C Source Files
READER_SRC_C = $(wildcard reader/*.c)
SENDER_SRC_C = $(wildcard sender/*.c)

export CFLAGS += -I include

#===============================================================================
# Toolchain Configuration
#===============================================================================

all: client_sender client_reader

client_sender:
	$(CC) $(CFLAGS) $(SENDER_SRC_C) -o $(BINARIES_DIR)/sender.elf 

client_reader:
	$(CC) $(CFLAGS) $(READER_SRC_C) -o $(BINARIES_DIR)/reader.elf 
