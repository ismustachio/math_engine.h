#include "../engine.h"


rgbaf_t rgbaf_create(float r, float g, float b, float a) {
	rgbaf_t o = { { r, g, b, a } };

	return o;
}

rgbaf_t rgbaf_from_array_create(float vals[4]) {
	rgbaf_t rgb = { { vals[0], vals[1], vals[2], vals[3]}};
	return rgb;
}

rgbaf_t rgbaf_from_rgba_create(rgbaf_t c) {
	rgbaf_t rgb = { { c.c[0], c.c[1], c.c[2], c.c[3]}};
	return rgb;
}

void rgbaf_initialize(rgbaf_t* rgba, float r, float g, float b, float a) {
	rgba->c[0] = r;
	rgba->c[1] = g;
	rgba->c[2] = b;
	rgba->c[3] = a;
}

rgbaf_t rgbaf_add(rgbaf_t v, rgbaf_t q) {
	return rgbaf_create(v.c[0] + q.c[0], v.c[1] + q.c[1], v.c[2] + q.c[2], v.c[3] + q.c[3]);
}

rgbaf_t rgbaf_subtract(rgbaf_t v, rgbaf_t q) {
	return rgbaf_create(v.c[0] - q.c[0], v.c[1] - q.c[1], v.c[2] - q.c[2], v.c[3] - q.c[3]);
}

rgbaf_t rgbaf_multiply(rgbaf_t v, rgbaf_t q) {
	return rgbaf_create(v.c[0] * q.c[0], v.c[1] * q.c[1], v.c[2] * q.c[2], v.c[3] * q.c[3]);
}

rgbaf_t rgbaf_scale(rgbaf_t v, float s) {
	return rgbaf_create(v.c[0] * s, v.c[1] * s, v.c[2] * s, v.c[3] * s);
}

rgbaf_t rgbaf_divide(rgbaf_t v, float s) {
	s = 1.0f / s;
	return rgbaf_create(v.c[0] * s, v.c[1] * s, v.c[2] * s, v.c[3] * s);
}
