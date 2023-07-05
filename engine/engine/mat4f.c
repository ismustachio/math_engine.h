#include "../engine.h"

#include <math.h>

mat4f_t mat4f_create(float n00, float n01, float n02, float n03,
	float n10, float n11, float n12, float n13,
	float n20, float n21, float n22, float n23,
	float n30, float n31, float n32, float n33) {
	mat4f_t m = { {
			{n00, n01, n02, n03},
			{n10, n11, n12, n13},
			{n20, n21, n22, n23},
			{n30, n31, n32, n33},
		}
	};
	return m;
}

mat4f_t mat4f_from_array_create(float e[4][4]) {
	mat4f_t m = { {
			{e[0][0], e[0][1], e[0][2], e[0][3]},
			{e[1][0], e[1][1], e[1][2], e[1][3]},
			{e[2][0], e[2][1], e[2][2], e[2][3]},
			{e[3][0], e[3][1], e[3][2], e[3][3]},
		}
	};
	return m;
}

mat4f_t mat4f_from_vec4f_create(vec4f_t e[4]) {
	mat4f_t m = { e[0], e[1], e[2], e[3] };
	return m;
}

mat4f_t mat4f_identity() {
	mat4f_t m = { {
			{1.0f, 0.0f, 0.0f, 0.0f},
			{0.0f, 1.0f, 0.0f, 0.0f},
			{0.0f, 0.0f, 1.0f, 0.0f},
			{0.0f, 0.0f, 0.0f, 1.0f},
		}
	};
	return m;
}

mat4f_t mat4f_multiply(mat4f_t a, mat4f_t b) {
	float n00 = a.e[0].n[0] * b.e[0].n[0] + a.e[1].n[0] * b.e[0].n[1] + a.e[2].n[0] * b.e[0].n[2] + a.e[3].n[0] * b.e[0].n[3];
	float n01 = a.e[0].n[0] * b.e[1].n[0] + a.e[1].n[0] * b.e[1].n[1] + a.e[2].n[0] * b.e[1].n[2] + a.e[3].n[0] * b.e[1].n[3];
	float n02 = a.e[0].n[0] * b.e[2].n[0] + a.e[1].n[0] * b.e[2].n[1] + a.e[2].n[0] * b.e[2].n[2] + a.e[3].n[0] * b.e[2].n[3];
	float n03 = a.e[0].n[0] * b.e[3].n[0] + a.e[1].n[0] * b.e[3].n[1] + a.e[2].n[0] * b.e[3].n[2] + a.e[3].n[0] * b.e[3].n[3];

	float n10 = a.e[0].n[1] * b.e[0].n[0] + a.e[1].n[1] * b.e[0].n[1] + a.e[2].n[1] * b.e[0].n[2] + a.e[3].n[1] * b.e[0].n[3];
	float n11 = a.e[0].n[1] * b.e[1].n[0] + a.e[1].n[1] * b.e[1].n[1] + a.e[2].n[1] * b.e[1].n[2] + a.e[3].n[1] * b.e[1].n[3];
	float n12 = a.e[0].n[1] * b.e[2].n[0] + a.e[1].n[1] * b.e[2].n[1] + a.e[2].n[1] * b.e[2].n[2] + a.e[3].n[1] * b.e[2].n[3];
	float n13 = a.e[0].n[1] * b.e[3].n[0] + a.e[1].n[1] * b.e[3].n[1] + a.e[2].n[1] * b.e[3].n[2] + a.e[3].n[1] * b.e[3].n[3];

	float n20 = a.e[0].n[2] * b.e[0].n[0] + a.e[1].n[2] * b.e[0].n[1] + a.e[2].n[2] * b.e[0].n[2] + a.e[3].n[2] * b.e[0].n[3];
	float n21 = a.e[0].n[2] * b.e[1].n[0] + a.e[1].n[2] * b.e[1].n[1] + a.e[2].n[2] * b.e[1].n[2] + a.e[3].n[2] * b.e[1].n[3];
	float n22 = a.e[0].n[2] * b.e[2].n[0] + a.e[1].n[2] * b.e[2].n[1] + a.e[2].n[2] * b.e[2].n[2] + a.e[3].n[2] * b.e[2].n[3];
	float n23 = a.e[0].n[2] * b.e[3].n[0] + a.e[1].n[2] * b.e[3].n[1] + a.e[2].n[2] * b.e[3].n[2] + a.e[3].n[2] * b.e[3].n[3];

	float n30 = a.e[0].n[3] * b.e[0].n[0] + a.e[1].n[3] * b.e[0].n[1] + a.e[2].n[3] * b.e[0].n[2] + a.e[3].n[3] * b.e[0].n[3];
	float n31 = a.e[0].n[3] * b.e[1].n[0] + a.e[1].n[3] * b.e[1].n[1] + a.e[2].n[3] * b.e[1].n[2] + a.e[3].n[3] * b.e[1].n[3];
	float n32 = a.e[0].n[3] * b.e[2].n[0] + a.e[1].n[3] * b.e[2].n[1] + a.e[2].n[3] * b.e[2].n[2] + a.e[3].n[3] * b.e[2].n[3];
	float n33 = a.e[0].n[3] * b.e[3].n[0] + a.e[1].n[3] * b.e[3].n[1] + a.e[2].n[3] * b.e[3].n[2] + a.e[3].n[3] * b.e[3].n[3];

	mat4f_t m = { {
			{n00, n01, n02, n03},
			{n10, n11, n12, n13},
			{n20, n21, n22, n23},
			{n30, n31, n32, n33},
		}
	};
	return m;
}

mat4f_t mat4f_rotate_x_make(float angle) {
	float c = cosf(angle);
	float s = sinf(angle);
	mat4f_t m = { {
			{1.0f, 0.0f, 0.0f, 0.0f},
			{0.0f, c, s, 0.0f},
			{0.0f, -s, c, 0.0f},
			{0.0f, 0.0f, 0.0f, 1.0f},
		}
	};
	return m;
}

mat4f_t mat4f_rotate_y_make(float angle) {
	float c = cosf(angle);
	float s = sinf(angle);
	mat4f_t m = { {
			{c, 0.0f, -s, 0.0f},
			{0.0f, 1.0f, 0.0f, 0.0f},
			{s, 0.0f, c, 0.0f},
			{0.0f, 0.0f, 0.0f, 1.0f},
		}
	};
	return m;
}

mat4f_t mat4f_rotate_z_make(float angle) {
	float c = cosf(angle);
	float s = sinf(angle);
	mat4f_t m = { {
			{c, s, 0.0f, 0.0f},
			{-s, c, 0.0f, 0.0f},
			{0.0f, 0.0f, 1.0f, 0.0f},
			{0.0f, 0.0f, 0.0f, 1.0f},
		}
	};
	return m;
}

mat4f_t mat4f_rotation_make(float angle, float x, float y, float z) {
	float c = cosf(angle);
	float s = sinf(angle);
	float d = 1.0f - c;
	float xd = x * d;
	float yd = y * d;
	float zd = z * d;
	float axay = xd * y;
	float axaz = xd * z;
	float ayaz = yd * z;
	mat4f_t m = { {
			{c + xd * x, axay - s * z, axaz + s * y, 0.0f},
			{axay + s * z, c + yd * y, ayaz - s * x, 0.0f},
			{axaz - s * y, ayaz + s * x, c + zd * z, 0.0f},
			{0.0f, 0.0f, 0.0f, 1.0f},
		}
	};

	return m;
}

mat4f_t mat4f_scale_x_make(float x) {
	mat4f_t m = { {
			{x, 0.0f, 0.0f, 0.0f},
			{0.0f, 1.0f, 0.0f, 0.0f},
			{0.0f, 0.0f, 1.0f, 0.0f},
			{0.0f, 0.0f, 0.0f, 1.0f},
		}
	};
	return m;
}

mat4f_t mat4f_scale_y_make(float y) {
	mat4f_t m = { {
			{1.0f, 0.0f, 0.0f, 0.0f},
			{0.0f, y, 0.0f, 0.0f},
			{0.0f, 0.0f, 1.0f, 0.0f},
			{0.0f, 0.0f, 0.0f, 1.0f},
		}
	};
	return m;
}

mat4f_t mat4f_scale_z_make(float z) {
	mat4f_t m = { {
			{1.0f, 0.0f, 0.0f, 0.0f},
			{0.0f, 1.0f, 0.0f, 0.0f},
			{0.0f, 0.0f, z, 0.0f},
			{0.0f, 0.0f, 0.0f, 1.0f},
		}
	};
	return m;
}

mat4f_t mat4f_scale_xyz_make(float x, float y, float z) {
	mat4f_t m = { {
			{x, 0.0f, 0.0f, 0.0f},
			{0.0f, y, 0.0f, 0.0f},
			{0.0f, 0.0f, z, 0.0f},
			{0.0f, 0.0f, 0.0f, 1.0f},
		}
	};
	return m;
}

mat4f_t mat4f_scale_with_vec3f_make(vec3f_t v) {
	mat4f_t m = { {
			{v.n[0], 0.0f, 0.0f, 0.0f},
			{0.0f, v.n[1], 0.0f, 0.0f},
			{0.0f, 0.0f, v.n[2], 0.0f},
			{0.0f, 0.0f, 0.0f, 1.0f},
		}
	};
	return m;
}

mat4f_t mat4f_rotation_with_vec3f_make(float angle, vec3f_t v) {
	float c = cosf(angle);
	float s = sinf(angle);
	float d = 1.0f - c;
	float xd = v.n[0] * d;
	float yd = v.n[1] * d;
	float zd = v.n[2] * d;
	float axay = xd * v.n[1];
	float axaz = xd * v.n[2];
	float ayaz = yd * v.n[2];
	mat4f_t m = { {
			{c + xd * v.n[0], axay - s * v.n[2], axaz + s * v.n[1], 0.0f},
			{axay + s * v.n[2], c + yd * v.n[1], ayaz - s * v.n[0], 0.0f},
			{axaz - s * v.n[1], ayaz + s * v.n[0], c + zd * v.n[2], 0.0f},
			{0.0f, 0.0f, 0.0f, 1.0f},
		}
	};

	return m;
}


mat4f_t mat4f_translation_make(float x, float y, float z) {
	mat4f_t m = { {
			{1.0f, 0.0f, 0.0f, x},
			{0.0f, 1.0f, 0.0f, y},
			{0.0f, 0.0f, 1.0f, z},
			{0.0f, 0.0f, 0.0f, 1.0f},
		}
	};
	return m;
}

mat4f_t mat4f_translation_with_vec3f_make(vec3f_t v) {
	mat4f_t m = { {
			{1.0f, 0.0f, 0.0f, v.n[0]},
			{0.0f, 1.0f, 0.0f, v.n[1]},
			{0.0f, 0.0f, 1.0f, v.n[2]},
			{0.0f, 0.0f, 0.0f, 1.0f},
		}
	};
	return m;
}


mat4f_t mat4f_perspective_make(float fov, float aspect_ratio, float near, float far) {
	mat4f_t m = { {
			{aspect_ratio * (1.0f / tanf(fov / 2.0f)), 0.0f, 0.0f, 0.0f},
			{0.0f, 1.0f / tanf(fov / 2.0f), 0.0f, 0.0f},
			{0.0f, 0.0f, far / (far - near), 1.0f },
			{0.0f, 0.0f, (-far * near) / (far - near), 0.0f},
		}
	};

	return m;
}

mat4f_t mat4f_look_at_make(float px, float py, float pz, float tx, float ty, float tz, float ux, float uy, float uz) {
	vec3f_t position = { px, py, pz };
	vec3f_t target = { tx, ty, tz };
	vec3f_t up = { ux, uy, uz };
	vec3f_t forward = vec3f_normalize(vec3f_subtract(target, position));
	vec3f_t right = vec3f_normalize(vec3f_cross_product(forward, vec3f_normalize(up)));
	vec3f_t upn = vec3f_cross_product(right, forward);
	forward = vec3f_negate(forward);

	mat4f_t m = { {
			{right.n[0], right.n[1], right.n[2], -vec3f_dot_product(right, position)},
			{upn.n[0], upn.n[1], upn.n[2], -vec3f_dot_product(upn, position)},
			{forward.n[0], forward.n[1], forward.n[2], -vec3f_dot_product(forward, position)},
			{0.0f, 0.0f, -1.0f, 0.0f},
		}
	};

	return m;
}

mat4f_t mat4f_look_at_with_vec3f_make(vec3f_t position, vec3f_t target, vec3f_t up) {
	vec3f_t forward = vec3f_normalize(vec3f_subtract(target, position));
	vec3f_t right = vec3f_normalize(vec3f_cross_product(forward, vec3f_normalize(up)));
	vec3f_t upn = vec3f_cross_product(right, forward);
	forward = vec3f_negate(forward);

	mat4f_t m = { {
			{right.n[0], right.n[1], right.n[2], -vec3f_dot_product(right, position)},
			{upn.n[0], upn.n[1], upn.n[2], -vec3f_dot_product(upn, position)},
			{forward.n[0], forward.n[1], forward.n[2], -vec3f_dot_product(forward, position)},
			{0.0f, 0.0f, -1.0f, 0.0f},
		}
	};

	return m;
}

mat4f_t mat4f_inverse(mat4f_t m) {
	vec3f_t a = { { m.e[0].n[0], m.e[0].n[1], m.e[0].n[2] } };
	vec3f_t b = { { m.e[1].n[0], m.e[1].n[1], m.e[1].n[2] } };
	vec3f_t c = { { m.e[2].n[0], m.e[2].n[1], m.e[2].n[2] } };
	vec3f_t d = { { m.e[3].n[0], m.e[3].n[1], m.e[3].n[2] } };

	float x = m.e[0].n[3];
	float y = m.e[1].n[3];
	float z = m.e[2].n[3];
	float w = m.e[3].n[3];

	vec3f_t s = vec3f_cross_product(a, b);
	vec3f_t t = vec3f_cross_product(d, c);
	vec3f_t u = vec3f_subtract(vec3f_scale(a, y), vec3f_scale(b, x));
	vec3f_t v = vec3f_subtract(vec3f_scale(c, w), vec3f_scale(d, z));

	float inv_det = 1.0f / (vec3f_dot_product(s, v) + vec3f_dot_product(t, u));
	s = vec3f_scale(s, inv_det);
	t = vec3f_scale(t, inv_det);
	u = vec3f_scale(u, inv_det);
	v = vec3f_scale(v, inv_det);

	vec3f_t r0 = vec3f_scale(vec3f_add(vec3f_cross_product(b, v), t), y);
	vec3f_t r1 = vec3f_scale(vec3f_subtract(vec3f_cross_product(v, a), t), x);
	vec3f_t r2 = vec3f_scale(vec3f_add(vec3f_cross_product(d, u), s), w);
	vec3f_t r3 = vec3f_scale(vec3f_add(vec3f_cross_product(u, c), s), z);

	mat4f_t o = { {
			{r0.n[0], r0.n[1], r0.n[2], -vec3f_dot_product(b, t)},
			{r1.n[0], r1.n[1], r1.n[2], vec3f_dot_product(a, t)},
			{r2.n[0], r2.n[1], r2.n[2], -vec3f_dot_product(d, s)},
			{r3.n[0], r3.n[1], r3.n[2], vec3f_dot_product(c, s)},
		}
	};
	return o;
}

mat4f_t mat4f_transpose(mat4f_t m) {
	float n00 = m.e[0].n[0];
	float n01 = m.e[1].n[0];
	float n02 = m.e[2].n[0];
	float n03 = m.e[3].n[0];

	float n10 = m.e[0].n[1];
	float n11 = m.e[1].n[1];
	float n12 = m.e[2].n[1];
	float n13 = m.e[3].n[1];

	float n20 = m.e[0].n[2];
	float n21 = m.e[1].n[2];
	float n22 = m.e[2].n[2];
	float n23 = m.e[3].n[2];

	float n30 = m.e[0].n[3];
	float n31 = m.e[1].n[3];
	float n32 = m.e[2].n[3];
	float n33 = m.e[3].n[3];

	mat4f_t w = { {
			{n00, n01, n02, n03},
			{n10, n11, n12, n13},
			{n20, n21, n22, n23},
			{n30, n31, n32, n33},
		}
	};
	return w;
}

vec4f_t mat4f_vec4f_multiply(mat4f_t m, vec4f_t v) {
	float x = m.e[0].n[0] * v.n[0] + m.e[1].n[0] * v.n[1] + m.e[2].n[0] * v.n[2] + m.e[3].n[0] * v.n[3];
	float y = m.e[0].n[1] * v.n[0] + m.e[1].n[1] * v.n[1] + m.e[2].n[1] * v.n[2] + m.e[3].n[1] * v.n[3];
	float z = m.e[0].n[2] * v.n[0] + m.e[1].n[2] * v.n[1] + m.e[2].n[2] * v.n[2] + m.e[3].n[2] * v.n[3];
	float w = m.e[0].n[3] * v.n[0] + m.e[1].n[3] * v.n[1] + m.e[2].n[3] * v.n[2] + m.e[3].n[3] * v.n[3];

	vec4f_t q = { {x, y, z, w} };
	return q;
}

vec4f_t mat4f_vec4f_with_perspective_divide_multiply(mat4f_t m, vec4f_t v) {
	vec4f_t q = mat4f_vec4f_multiply(m, v);
	if (q.n[3] != 0.0f) {
		q.n[0] /= q.n[3];
		q.n[1] /= q.n[3];
		q.n[2] /= q.n[3];
	}
	return q;
}