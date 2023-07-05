#include "../engine.h"

#include <math.h>

mat3f_t matf3_create(float n00, float n01, float n02,
	float n10, float n11, float n12,
	float n20, float n21, float n22) {
	mat3f_t m = { {
			{n00, n01, n02},
			{n10, n11, n12},
			{n20, n21, n22},
		}
	};
	return m;
}

mat3f_t mat3f_from_array_create(float e[3][3]) {
	mat3f_t m = { {
			{e[0][0], e[0][1], e[0][2]},
			{e[1][0], e[1][1], e[1][2]},
		    {e[2][0], e[2][1], e[2][2]},
		}
	};
	return m;
}

mat3f_t mat3f_from_vec3f_create(vec3f_t e[3]) {
	mat3f_t m = { e[0], e[1], e[2] };
	return m;
}

mat3f_t mat3f_identity() {
	mat3f_t m = { {
			{1.0f, 0.0f, 0.0f},
			{0.0f, 1.0f, 0.0f},
			{0.0f, 0.0f, 1.0f},
		}
	};
	return m;
}

mat3f_t mat3f_multiply(mat3f_t m, mat3f_t q) {
	float n00 = m.e[0].n[0] * q.e[0].n[0] + m.e[0].n[1] * q.e[1].n[0] + m.e[0].n[2] * q.e[2].n[0];
	float n01 = m.e[0].n[0] * q.e[0].n[1] + m.e[0].n[1] * q.e[1].n[1] + m.e[0].n[2] * q.e[2].n[1];
	float n02 = m.e[0].n[0] * q.e[0].n[2] + m.e[0].n[1] * q.e[1].n[2] + m.e[0].n[2] * q.e[2].n[2];

	float n10 = m.e[0].n[0] * q.e[0].n[0] + m.e[0].n[1] * q.e[1].n[0] + m.e[0].n[2] * q.e[2].n[0];
	float n11 = m.e[0].n[0] * q.e[0].n[1] + m.e[0].n[1] * q.e[1].n[1] + m.e[0].n[2] * q.e[2].n[1];
	float n12 = m.e[0].n[0] * q.e[0].n[2] + m.e[0].n[1] * q.e[1].n[2] + m.e[0].n[2] * q.e[2].n[2];


	float n20 = m.e[0].n[0] * q.e[0].n[0] + m.e[0].n[1] * q.e[1].n[0] + m.e[0].n[2] * q.e[2].n[0];
	float n21 = m.e[0].n[0] * q.e[0].n[1] + m.e[0].n[1] * q.e[1].n[1] + m.e[0].n[2] * q.e[2].n[1];
	float n22 = m.e[0].n[0] * q.e[0].n[2] + m.e[0].n[1] * q.e[1].n[2] + m.e[0].n[2] * q.e[2].n[2];
	mat3f_t w = { {
			{n00, n01, n02},
			{n10, n11, n12},
			{n20, n21, n22},
		}
	};
	return w;
}

vec3f_t mat3f_vec3f_multiply(mat3f_t m, vec3f_t v) {
	float x = m.e[0].n[0] * v.n[0] + m.e[0].n[1] * v.n[1] + m.e[0].n[2] * v.n[2];
	float y = m.e[1].n[0] * v.n[0] + m.e[1].n[1] * v.n[1] + m.e[1].n[2] * v.n[2];
	float z = m.e[2].n[0] * v.n[0] + m.e[2].n[1] * v.n[1] + m.e[2].n[2] * v.n[2];
	vec3f_t q = { {x,y,z} };
	return q;
}

float mat3f_determinant(mat3f_t m) {
	return m.e[0].n[0] * (m.e[1].n[1] * m.e[2].n[2] - m.e[2].n[1] * m.e[1].n[2]) +
		m.e[1].n[0] * (m.e[2].n[1] * m.e[0].n[2] - m.e[0].n[1] * m.e[2].n[2]) +
		m.e[2].n[0] * (m.e[0].n[1] * m.e[1].n[2] - m.e[1].n[1] * m.e[0].n[2]);
}

mat3f_t mat3f_transpose(mat3f_t m) {
	float n00 = m.e[0].n[0];
	float n01 = m.e[1].n[0];
	float n02 = m.e[2].n[0];
	float n10 = m.e[0].n[1];
	float n11 = m.e[1].n[1];
	float n12 = m.e[2].n[1];
	float n20 = m.e[0].n[2];
	float n21 = m.e[1].n[2];
	float n22 = m.e[2].n[2];

	mat3f_t w = { {
			{n00, n01, n02},
			{n10, n11, n12},
			{n20, n21, n22},
		}
	};
	return w;
}

mat3f_t mat3f_inverse(mat3f_t m) {
	vec3f_t a = m.e[0];
	vec3f_t b = m.e[1];
	vec3f_t c = m.e[2];

	vec3f_t r0 = vec3f_cross_product(b, c);
	vec3f_t r1 = vec3f_cross_product(c, a);
	vec3f_t r2 = vec3f_cross_product(a, b);

	float inv_det = 1.0f / vec3f_dot_product(r2, c);

	mat3f_t q = { {
			{r0.n[0] * inv_det, r0.n[1] * inv_det, r0.n[2] * inv_det},
			{r1.n[0] * inv_det, r1.n[1] * inv_det, r1.n[2] * inv_det},
			{r2.n[0] * inv_det, r2.n[1] * inv_det, r2.n[2] * inv_det},
		}
	};

	return q;
}

mat3f_t mat3f_reflection_with_vec3f_make(vec3f_t v) {
	float x = v.n[0] * -2.0f;
	float y = v.n[1] * -2.0f;
	float z = v.n[2] * -2.0f;
	float axay = x * v.n[1];
	float axaz = x * v.n[2];
	float ayaz = y * v.n[2];

	float n00 = x * v.n[0] + 1.0f;
	float n01 = axay;
	float n02 = axaz;
	float n10 = axay;
	float n11 = y * v.n[1] + 1.0f;
	float n12 = ayaz;
	float n20 = axaz;
	float n21 = ayaz;
	float n22 = z * v.n[2] + 1.0f;

	mat3f_t m = { {
			{n00, n01, n02},
			{n10, n11, n12},
			{n20, n21, n22},
		}
	};
	return m;
}

mat3f_t mat3f_involution_make(float x, float y, float z) {
	float xx = x * 2.0f;
	float yy = y * 2.0f;
	float zz = z * 2.0f;
	float axay = xx * y;
	float axaz = xx * z;
	float ayaz = yy * z;

	float n00 = xx * x - 1.0f;
	float n01 = axay;
	float n02 = axaz;
	float n10 = axay;
	float n11 = yy * y - 1.0f;
	float n12 = ayaz;
	float n20 = axaz;
	float n21 = ayaz;
	float n22 = zz * z - 1.0f;

	mat3f_t m = { {
			{n00, n01, n02},
			{n10, n11, n12},
			{n20, n21, n22},
		}
	};
	return m;
}

mat3f_t mat3f_involution_with_vec3f_make(vec3f_t v) {
	float xx = v.n[0] * 2.0f;
	float yy = v.n[1] * 2.0f;
	float zz = v.n[2] * 2.0f;
	float axay = xx * v.n[1];
	float axaz = xx * v.n[2];
	float ayaz = yy * v.n[2];

	float n00 = xx * v.n[0] - 1.0f;
	float n01 = axay;
	float n02 = axaz;
	float n10 = axay;
	float n11 = yy * v.n[1] - 1.0f;
	float n12 = ayaz;
	float n20 = axaz;
	float n21 = ayaz;
	float n22 = zz * v.n[2] - 1.0f;

	mat3f_t m = { {
			{n00, n01, n02},
			{n10, n11, n12},
			{n20, n21, n22},
		}
	};
	return m;
}

mat3f_t mat3f_scale_xyz_make(float sx, float sy, float sz) {
	mat3f_t m = { {
			{sx, 0.0f, 0.0f},
			{0.0f, sy, 0.0f},
			{0.0f, 0.0f, sz},
		}
	};
	return m;
}

mat3f_t mat3f_scale_with_factor_and_vec3f_make(float s, vec3f_t a) {
	s -= 1.0f;
	float x = a.n[0] * s;
	float y = a.n[1] * s;
	float z = a.n[2] * s;
	float axay = x * a.n[1];
	float axaz = x * a.n[2];
	float ayaz = y * a.n[2];

	float n00 = x * a.n[0] + 1.0f;
	float n01 = axay;
	float n02 = axaz;
	float n10 = axay;
	float n11 = y * a.n[1] + 1.0f;
	float n12 = ayaz;
	float n20 = axaz;
	float n21 = ayaz;
	float n22 = z * a.n[2] + 1.0f;

	mat3f_t m = { {
			{n00, n01, n02},
			{n10, n11, n12},
			{n20, n21, n22},
		}
	};
	return m;
}

mat3f_t mat3f_skew_with_vec3fs_make(float angle, vec3f_t a, vec3f_t b) {
	angle = tanf(angle);
	float x = a.n[0] * angle;
	float y = a.n[1] * angle;
	float z = a.n[2] * angle;

	float n00 = x * b.n[0] + 1.0f;
	float n01 = x * b.n[1];
	float n02 = x * b.n[2];
	float n10 = y * b.n[0];
	float n11 = y * b.n[1] + 1.0f;
	float n12 = y * b.n[2];
	float n20 = z * b.n[0];
	float n21 = z * b.n[1];
	float n22 = z * b.n[2] + 1.0f;

	mat3f_t m = { {
			{n00, n01, n02},
			{n10, n11, n12},
			{n20, n21, n22},
		}
	};
	return m;
}