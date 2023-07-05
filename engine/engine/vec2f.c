#include "../engine.h"

#include <math.h>

vec2f_t vec2f_create(float x, float y) {
	vec2f_t v = { { x, y} };
	return v;
}

vec2f_t vec2f_from_array_create(float elems[2]) {
	vec2f_t v = { { elems[0], elems[1] } };
	return v;
}

void vec2f_initialize(vec2f_t* v, float x, float y) {
	v->n[0] = x;
	v->n[1] = y;
}

vec2f_t vec2f_add(vec2f_t v, vec2f_t q) {
	vec2f_t w = { { v.n[0] + q.n[0], v.n[1] + q.n[1] }};
	return w;
}

vec2f_t vec2f_subtract(vec2f_t v, vec2f_t q) {
	vec2f_t w = { { v.n[0] - q.n[0], v.n[1] - q.n[1] } };
	return w;
}

float vec2f_dot_product(vec2f_t v, vec2f_t q) {
	return v.n[0] * q.n[0] + v.n[1] * q.n[1];
}

float vec2f_cross_product(vec2f_t v, vec2f_t q) {
	return v.n[0] * q.n[1] - v.n[1] * q.n[0];
}

vec2f_t vec2f_normalize(vec2f_t v) {
	float m = 1.0f / vec2f_magntitude(v);
	vec2f_t w = { { v.n[0] * m, v.n[1] * m } };
	return w;
}

float vec2f_magntitude(vec2f_t v) {
	return sqrtf(v.n[0] * v.n[0] + v.n[1] * v.n[1]);
}

vec2f_t vec2f_scale(vec2f_t v, float s) {
	vec2f_t w = { { v.n[0] * s, v.n[1] * s}};
	return w;
}

vec2f_t vec2f_abs(vec2f_t v) {
	vec2f_t w = { { fabs(v.n[0]), fabs(v.n[1])} };
	return w;
}

vec2f_t vec2f_ceil(vec2f_t v) {
	vec2f_t w = { { ceilf(v.n[0]), ceilf(v.n[1])} };
	return w;
}

vec2f_t vec2f_floor(vec2f_t v) {
	vec2f_t w = { { floorf(v.n[0]), floorf(v.n[1])} };
	return w;
}

float vec2f_min_component(vec2f_t v) {
	float min = v.n[0];
	if (v.n[1] < min) {
		min = v.n[1];
	}
	
	return min;
}

float vec2f_max_component(vec2f_t v) {
	float max = v.n[0];
	if (v.n[1] > max) {
		max = v.n[1];
	}

	return max;
}

float vec2f_horizontal_product(vec2f_t v) {
	return v.n[0] * v.n[1];
}