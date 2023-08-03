TARGETS=	1-rect-copy.o \
		2-strcpy.o \
		3-flood-check \
		4-circle

ASM?=		nasm

CFLAGS+=	-Wall -Wextra
ASMFLAGS+=	-f elf64
LDFLAGS+=	-z noexecstack

all: ${TARGETS}

clean:
	rm -f ${TARGETS} *.o

3-flood-check: 3-flood-check.o 3-flood-check-x86_64.o
	${LINK.c} -o 3-flood-check 3-flood-check.o 3-flood-check-x86_64.o

.SUFFIXES: .asm

.asm.o:
	${ASM} ${ASMFLAGS} -o $@ $<

.PHONY: all clean
