#include "../engine.h"


rgbf_t rgbf_create(float r, float g, float b) {
	rgbf_t a = { { r, g, b } };
	return a;
}

rgbf_t rgbf_from_array_create(float vals[3]) {
	rgbf_t rgb = { { vals[0], vals[1], vals[2]} };
	return rgb;
}

rgbf_t rgbf_from_rgb_create(rgbf_t c) {
	rgbf_t rgb = { { c.c[0], c.c[1], c.c[2]}};
	return rgb;
}

void rgbf_initialize(rgbf_t* rgb, float r, float g, float b) {
	rgb->c[0] = r;
	rgb->c[1] = g;
	rgb->c[2] = b;
}

rgbf_t rgbf_add(rgbf_t v, rgbf_t q) {
	return rgbf_create(v.c[0] + q.c[0], v.c[1] + q.c[1], v.c[2] + q.c[2]);
}

rgbf_t rgbf_subtract(rgbf_t v, rgbf_t q) {
	return rgbf_create(v.c[0] - q.c[0], v.c[1] - q.c[1], v.c[2] - q.c[2]);
}

rgbf_t rgbf_multiply(rgbf_t v, rgbf_t q) {
	return rgbf_create(v.c[0] * q.c[0], v.c[1] * q.c[1], v.c[2] * q.c[2]);
}

rgbf_t rgbf_scale(rgbf_t v, float s) {
	return rgbf_create(v.c[0] * s, v.c[1] * s, v.c[2] * s);
}

rgbf_t rgbf_divide(rgbf_t v, float s) {
	s = 1.0f / s;
	return rgbf_create(v.c[0] * s, v.c[1] * s, v.c[2] * s);
}
