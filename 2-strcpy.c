#include <string.h>

void 
strcpy_v1(char *src, char *dst)
{
	size_t len, i;

	len = strlen(src);

	for (i=0; i < len; i++)
		dst[i] = src[i];
	
	dst[len] = '\0';
}

void 
strcpy_v2(char *src, char *dst)
{
	size_t len=0, i;

	for (i=0; src[i] != '\0'; i++)
		len++;
	for (i=0; i < len; i++)
		dst[i] = src[i];

	dst[len] = '\0';
}

void 
strcpy_v3(char *src, char *dst)
{
	size_t i;

	for (i=0; src[i] != '\0'; i++)
		dst[i] = src[i];

	dst[i] = '\0';
}

void 
strcpy_v4(char *src, char *dst)
{
	while (*src != '\0') {
		*dst = *src;
		src++;
		dst++;
	}

	*dst = '\0';
}

void 
strcpy_v5(char *src, char *dst)
{
	while (*src)
		*dst++ = *src++;

	*dst = '\0';
}
