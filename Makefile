# Platform-specific path separator
ifeq ($(OS), Windows_NT)
	SEPARATOR = \\
else
	SEPARATOR = /
endif

# Directories
ROOT_DIR := .
SRC_DIR := $(ROOT_DIR)$(SEPARATOR)src
OBJ_DIR := $(ROOT_DIR)$(SEPARATOR)obj
INCLUDE_DIR := $(ROOT_DIR)$(SEPARATOR)include
LIB_DIR := $(ROOT_DIR)$(SEPARATOR)lib
BIN_DIR := $(ROOT_DIR)$(SEPARATOR)bin
EXAMPLES_DIR := $(ROOT_DIR)$(SEPARATOR)examples

# Platform-specific, path separator, commands & executable extensions
ifeq ($(OS), Windows_NT)
    MKDIR_CMD := powershell -Command "\
	if (-not (Test-Path '$(OBJ_DIR)')) { Write-Host 'make: Creating obj directory'; \
	New-Item -ItemType Directory -Force -Path '$(OBJ_DIR)' | Out-Null }; \
	if (-not (Test-Path '$(LIB_DIR)')) { Write-Host 'make: Creating lib directory'; \
	New-Item -ItemType Directory -Force -Path '$(LIB_DIR)' | Out-Null }; \
	if (-not (Test-Path '$(BIN_DIR)')) { Write-Host 'make: Creating bin directory'; \
	New-Item -ItemType Directory -Force -Path '$(BIN_DIR)' | Out-Null }"
    RM_CMD := powershell -Command "\
	if (Test-Path '$(OBJ_DIR)') { Write-Host 'make: Deleting build directory'; \
	Remove-Item -Recurse -Force '$(OBJ_DIR)' }; \
	if (Test-Path '$(LIB_DIR)') { Write-Host 'make: Deleting lib directory'; \
	Remove-Item -Recurse -Force '$(LIB_DIR)' }; \
	if (Test-Path '$(BIN_DIR)') { Write-Host 'make: Creating bin directory'; \
	Remove-Item -Recurse -Force '$(BIN_DIR)' };"
	EXEC_SUFFIX = .exe
else
	MKDIR_CMD := mkdir -p $(OBJ_DIR) $(LIB_DIR) $(BIN_DIR)
	RM_CMD := rm -rf $(OBJ_DIR) $(LIB_DIR) $(BIN_DIR) $(EXEC)
	EXEC_SUFFIX =
endif

# Compiler and flags
CC := gcc
CFLAGS := -I$(INCLUDE_DIR) -I$(EXAMPLES_DIR) -pthread

# Source files
MAIN_SRC = $(ROOT_DIR)$(SEPARATOR)main.c
ASSERT_SRC = $(SRC_DIR)$(SEPARATOR)x-assert.c
ASSERT_EXAMPLES_SRC = $(EXAMPLES_DIR)$(SEPARATOR)x-assert-examples.c

# Object files
MAIN_OBJ := $(OBJ_DIR)$(SEPARATOR)main.o 
ASSERT_OBJ := $(LIB_DIR)$(SEPARATOR)x-assert.o
ASSERT_EXAMPLES_OBJ = $(OBJ_DIR)$(SEPARATOR)x-assert-examples.o
OBJS += $(MAIN_OBJ)
OBJS += $(ASSERT_OBJ)
OBJS += $(ASSERT_EXAMPLES_OBJ)

# Final executable
EXEC := $(BIN_DIR)$(SEPARATOR)main$(EXEC_SUFFIX)

#Targets and dependencies
$(EXEC): $(OBJS)
	@echo make: Linking executable '$(EXEC)'
	@$(CC) $(CFLAGS) $(OBJS) -o $@

$(MAIN_OBJ): $(MAIN_SRC)
	@$(MKDIR_CMD)
	@echo make: Compiling 'main.c'
	@$(CC) $(CFLAGS) -c $(MAIN_SRC) -o $@

$(ASSERT_OBJ): $(ASSERT_SRC)
	@$(MKDIR_CMD)
	@echo make: Compiling 'x-assert.c'
	@$(CC) $(CFLAGS) -c $(ASSERT_SRC) -o $@

$(ASSERT_EXAMPLES_OBJ): $(ASSERT_EXAMPLES_SRC)
	@$(MKDIR_CMD)
	@echo make: Compiling 'x-assert-examples.c'
	@$(CC) $(CFLAGS) -c $(ASSERT_EXAMPLES_SRC) -o $@

# Phony targets
.PHONY: all clean run print

all: $(EXEC)

clean:
	@$(RM_CMD)

run:
	@$(EXEC)