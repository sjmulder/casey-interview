#include <stdio.h>
#include <string.h>

#define GRIDSZ	80

static char grid[GRIDSZ][GRIDSZ];

static void
print(void)
{
	int i;

	for (i=0; i < GRIDSZ; i++) {
		fwrite(grid[i], 1, GRIDSZ, stdout);
		fputc('\n', stdout);
	}
}

static void
plot(int x, int y)
{
	grid[y][x] = '#';
}

static void
plot_circle(int cx, int cy, int r)
{
	int x, y;

	for (x=0, y=r; x < y; x++)
	for (; y>=0; y--) {
		plot(cx+x, cy+y);
		plot(cx+x, cy-y);
		plot(cx-x, cy+y);
		plot(cx-x, cy-y);

		plot(cx+y, cy+x);
		plot(cx+y, cy-x);
		plot(cx-y, cy+x);
		plot(cx-y, cy-x);

		//print();
		//fgetc(stdin);

		if (x*x + (y-1)*(y-1) < r*r)
			break;
	}
}

int
main()
{
	memset(grid, ' ', sizeof(grid));
	plot_circle(GRIDSZ/2, GRIDSZ/2, GRIDSZ/2-2);
	print();

	return 0;
}
