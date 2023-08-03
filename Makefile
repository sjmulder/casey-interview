TARGETS=	1-rect-copy.o \
		2-strcpy.o \
		3-flood-check.o \
		3-flood-check-x86_64.o \
		4-circle

ASM?=		nasm

CFLAGS+=	-Wall -Wextra
ASMFLAGS+=	-f elf64

all: ${TARGETS}

clean:
	rm -f ${TARGETS} *.o

.SUFFIXES: .asm

.asm.o:
	${ASM} ${ASMFLAGS} -o $@ $<

.PHONY: all clean
