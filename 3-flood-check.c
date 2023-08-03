#include <stdio.h>
#include <stdint.h>
#include <assert.h>

/* defined in 3-flood-check-x86_64.asm */
int flood_check_x86_64(uint8_t pattern, uint8_t target);

int
flood_check_1(uint8_t pattern, uint8_t target)
{
	return (pattern << 6 |
	        pattern << 4 |
	        pattern << 2 |
	        pattern) == target;
}

int
flood_check_2(uint8_t pattern, uint8_t target)
{
	return ((pattern & 3) << 6 |
	        (pattern & 3) << 4 |
	        (pattern & 3) << 2 |
	        (pattern & 3)) == target;
}

static void
test(int (*flood_check_fn)(uint8_t, uint8_t))
{
	assert(flood_check_fn(0x0, 0x00) == 1);
	assert(flood_check_fn(0x2, 0xAA) == 1);
	assert(flood_check_fn(0x3, 0xAA) == 0);
}

int
main()
{
	test(flood_check_1);
	test(flood_check_2);
	test(flood_check_x86_64);

	printf("tests passing!\n");
	return 0;
}
