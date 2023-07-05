#include "../engine.h"

#include <math.h>

vec3f_t vec3f_create(float x, float y, float z) {
	vec3f_t v = { {x, y, z} };
	return v;
}

vec3f_t vec3f_from_array_create(float elems[3]) {
	vec3f_t v = { {elems[0], elems[1], elems[2]}};
	return v;
}

vec3f_t vec3f_add(vec3f_t v, vec3f_t q) {
	vec3f_t w = { {v.n[0] + q.n[0], v.n[1] + q.n[1], v.n[2] + q.n[2]} };
	return w;
}

vec3f_t vec3f_subtract(vec3f_t v, vec3f_t q) {
	vec3f_t w = { {v.n[0] - q.n[0], v.n[1] - q.n[1], v.n[2] - q.n[2]}};
	return w;
}

vec3f_t vec3f_negate(vec3f_t v) {
	vec3f_t w = { {-v.n[0], -v.n[1], -v.n[2]}};
	return w;
}

vec3f_t vec3f_normalize(vec3f_t v) {
	float m = 1.0f / vec3f_magntitude(v);
	vec3f_t q = { {v.n[0] * m, v.n[1] * m, v.n[2] * m}};
	return q;
}

vec3f_t vec3f_scale(vec3f_t v, float s) {
	vec3f_t q = { {v.n[0] * s, v.n[1] * s, v.n[2] * s} };
	return q;
}

void vec3f_initialize(vec3f_t* v, float x, float y, float z) {
	v->n[0] = x;
	v->n[1] = y;
	v->n[2] = z;
}

float vec3f_magntitude(vec3f_t v) {
	return sqrtf(v.n[0] * v.n[0] + v.n[1] * v.n[1] + v.n[2] * v.n[2]);
}


float vec3f_dot_product(vec3f_t v, vec3f_t q) {
	return v.n[0] * q.n[0] + v.n[1] * q.n[1] + v.n[2] * q.n[2];
}

vec3f_t vec3f_cross_product(vec3f_t v, vec3f_t q) {
	vec3f_t w = { {v.n[1] * q.n[2] - v.n[2] * q.n[1], v.n[2] * q.n[0] - v.n[0] * q.n[2], v.n[0] * q.n[1] - v.n[1] * q.n[0]}};
	return w;
}

vec3f_t vec3f_abs(vec3f_t v) {
	vec3f_t w = { {fabsf(v.n[0]), fabsf(v.n[1]), fabsf(v.n[2])}};
	return w;
}

vec3f_t vec3f_ceil(vec3f_t v) {
	vec3f_t w = { {ceilf(v.n[0]), ceilf(v.n[1]), ceilf(v.n[2])} };
	return w;
}

vec3f_t vec3f_floor(vec3f_t v) {
	vec3f_t w = { {floorf(v.n[0]), floorf(v.n[1]), floorf(v.n[2])} };
	return w;
}

float vec3f_min_component(vec3f_t v) {
	float min = v.n[0];
	if (v.n[1] < min) {
		min = v.n[1];
	}
	if (v.n[2] < min) {
		min = v.n[2];
	}

	return min;
}

float vec3f_max_component(vec3f_t v) {
	float min = v.n[0];
	if (v.n[1] > min) {
		min = v.n[1];
	}
	if (v.n[2] > min) {
		min = v.n[2];
	}

	return min;
}

float vec3f_horizontal_product(vec3f_t v) {
	return v.n[0] * v.n[1] * v.n[2];
}

