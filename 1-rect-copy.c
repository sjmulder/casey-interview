void
rect_copy(
    char *src_buf, int src_stride,
    char *dst_buf, int dst_stride,
    int x0, int y0, int x1, int y1, int w, int h)
{
	int x, y;

	for (y=0; y<h; y++)
	for (x=0; x<w; x++) {
		dst_buf[dst_stride * (y1+y) + x1+x] =
		src_buf[src_stride * (y0+y) + x0+x];
	}
}
