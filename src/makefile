# Compile Source

#===============================================================================
# Artifacts
#===============================================================================

# C Source Files
SRC_C = $(wildcard ./*.c)

# Object Files
OBJ = $(SRC_C:.c=.o)

# Binaries Files
ELF = $(OBJ:.o=.elf)

#===============================================================================
# Toolchain Configuration
#===============================================================================

export CFLAGS += -I $(INCLUDE_DIR)

#===============================================================================
# Run Rules
#===============================================================================

all: librarie $(OBJ) $(ELF)

librarie:
	$(MAKE) -C libc all

%.elf: %.o
	$(CC) $(CFLAGS) $<  -L$(LIBRARIE_DIR) -l:lib.a -o $(BINARIES_DIR)/$@ 

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	$(MAKE) -C libc clean
	rm -rf $(OBJ)
