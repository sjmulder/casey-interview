#include <stdint.h>

int
flood_check(uint8_t pattern, uint8_t target)
{
	return !(((pattern & 3) << 6 |
	          (pattern & 3) << 4 |
	          (pattern & 3) << 2 |
	          (pattern & 3)) ^ target);
}
