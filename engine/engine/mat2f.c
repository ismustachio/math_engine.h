#include "../engine.h"

mat2f_t mat2f_create(float n00, float n01, float n10, float n11) {
	mat2f_t m = { {{n00, n01},
				   {n10, n11}} };
	return m;
}

mat2f_t mat2f_from_array_create(float e[2][2]) {
	mat2f_t m = { {{e[0][0], e[0][1]},
				   {e[1][0], e[1][1]}}};
	return m;
}

mat2f_t mat2f_from_vec2f_create(vec2f_t e[2]) {
	mat2f_t m = { {e[0], e[1]} };
	return m;
}

void mat2f_initialize(mat2f_t* m, float n00, float n01, float n10, float n11) {
	m->e[0].n[0] = n00;
	m->e[0].n[1] = n01;
	m->e[1].n[0] = n10;
	m->e[1].n[1] = n11;
}

mat2f_t mat2f_identity() {
	mat2f_t m = { {{1.0f, 0.0f},
				   {0.0f, 1.0f}} };
	return m;
}

mat2f_t mat2f_transpose(mat2f_t m) {
	mat2f_t q = { m.e[1], m.e[0] };
	return q;
}

mat2f_t mat2f_inverse(mat2f_t m) {
	mat2f_t q = { {{m.e[1].n[1], -m.e[0].n[1]},
				   {-m.e[1].n[0], m.e[0].n[0]}}};

	return q;
}

mat2f_t mat2f_scale_make(float x, float y) {
	mat2f_t m = { {{x, 0.0f},
				   {0.0f, y}} };
	return m;
}

mat2f_t mat2f_multiply(mat2f_t m, mat2f_t q) {
	mat2f_t o = { {{m.e[0].n[0] * q.e[0].n[0] + m.e[0].n[1] * q.e[1].n[0], m.e[0].n[0] * q.e[0].n[1] + m.e[0].n[1] * q.e[1].n[1]},
				   {m.e[1].n[0] * q.e[0].n[0] + m.e[1].n[1] * q.e[1].n[0], m.e[1].n[0] * q.e[0].n[1] + m.e[1].n[1] * q.e[1].n[1]}} };
	return o;
}