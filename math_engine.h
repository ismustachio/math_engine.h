#pragma once

#include <math.h>

static float degrees_to_radians(float deg) {
	return deg * (M_PI / 180.0);
}

static float radians_to_degrees(float rad) {
	return rad * (180.0 / M_PI);
}

typedef struct rgb_t rgb_t;
struct rgb_t { float c[3]; };
extern rgb_t rgb_create(float r, float g, float b);
extern rgb_t rgb_from_array_create(float vals[3]);
extern rgb_t rgb_from_rgb_create(rgb_t c);
extern void rgb_initialize(rgb_t* rgb, float r, float g, float b);
extern rgb_t rgb_add(rgb_t v, rgb_t q);
extern rgb_t rgb_subtract(rgb_t v, rgb_t q);
extern rgb_t rgb_multiply(rgb_t v, rgb_t q);
extern rgb_t rgb_scale(rgb_t v, float s);
extern rgb_t rgb_divide(rgb_t v, float s);

typedef struct rgba_t rgba_t;
struct rgba_t { float c[4]; };
extern rgba_t rgba_create(float r, float g, float b, float a);
extern rgba_t rgba_from_array_create(float vals[4]);
extern rgba_t rgba_from_rgb_create(rgba_t c);
extern void rgba_initialize(rgba_t* rgba, float r, float g, float b, float a);
extern rgba_t rgba_add(rgba_t v, rgba_t q);
extern rgba_t rgba_subtract(rgba_t v, rgba_t q);
extern rgba_t rgba_multiply(rgba_t v, rgba_t q);
extern rgba_t rgba_scale(rgba_t v, float s);
extern rgba_t rgba_divide(rgba_t v, float s);


typedef struct vec2f_t vec2f_t;
struct vec2f_t { float n[2]; };

typedef struct vec3f_t vec3f_t;
struct vec3f_t { float n[3]; };

typedef struct vector4 vector4;
struct vector4 { float n[4]; };


#define X(vector) ((vector).n[0])
#define Y(vector) ((vector).n[1])
#define Z(vector) ((vector).n[2])
#define W(vector) ((vector).n[3])


// Vector2
static vec2f_t vec2f_create(float x, float y) {
	vec2f_t result = { .n = {x, y}, };

	return result;
}

static void vec2f_initialize(vec2f_t *v, float x, float y) {
	v->n[0] = x;
	v->n[1] = y;
}

static float vec2f_at(vec2f_t v, int i) {
	return v.n[i];
}

static vec2f_t vec2f_scale_add(vec2f_t v, float s) {
	vec2f_t result = { .n = { X(v) + s, Y(v) + s }, };

	return result;		
}

static vec2f_t vec2f_add(vec2f_t v, vec2f_t q) {
	vec2f_t result = { .n = { X(v) + X(q), Y(v) + Y(q)}, };

	return result;	
}

static vec2f_t vec2f_subtract(vec2f_t v, vec2f_t q) {
	vec2f_t result = { .n = { X(v) - X(q), Y(v) - Y(q) }, };

	return result;
}

static vec2f_t vec2f_scale_subtract(vec2f_t v, float s) {
	vec2f_t result = { .n = { X(v) - s, Y(v) - s }, };

	return result;		
}

static vec2f_t vec2f_scale(vec2f_t v, float s) {
	vec2f_t result = { .n = { X(v) * s, Y(v) * s }, };

	return result;		
}

static vec2f_t vec2f_divide(vec2f_t v, float s) {
	return vec2f_scale(v, 1.0 / s);
}

static float vec2f_length(vec2f_t v) {
  return sqrt(X(v) * X(v) + Y(v) * Y(v));
}

static vec2f_t vec2f_normalize(vec2f_t v) {
	return vec2f_scale(v, 1.0 / vector2_length(v));
}

static float vec2f_dot(vec2f_t v, vec2f_t q) {
	return X(v) * X(q) + Y(v) * Y(q);
}






// Vector3
static vec3f_t vec3f_create(float x, float y, float z) {
	vec3f_t result = { .n = {x, y, z},};

	return result;
}

static void vec3f_initialize(vec3f_t* v, float x, float y, float z) {
	v->n[0] = x;
	v->n[1] = y;
	v->n[2] = z;
}

static vec3f_t vec3f_scale_add(vec3f_t v, float s) {
	vec3f_t result = { .n = { X(v) + s, Y(v) + s, Z(v) + s }, };

	return result;		
}

static vec3f_t vec3f_add(vec3f_t v, vec3f_t q) {
	vec3f_t result = { .n = { X(v) + X(q), Y(v) + Y(q), Z(v) + Z(q) }, };

	return result;	
}

static vec3f_t vec3f_subtract(vec3f_t v, vec3f_t q) {
	vec3f_t result = { .n = { X(v) - X(q), Y(v) - Y(q), Z(v) - Z(q) }, };

	return result;	
}

static vec3f_t vec3f_scale_subtract(vec3f_t v, float s) {
	vec3f_t result = { .n = { X(v) - s, Y(v) - s, Z(v) - s }, };

	return result;
}

static vec3f_t vec3f_scale(vec3f_t v, float s) {
	vec3f_t result = { .n = { X(v) * s, Y(v) * s, Z(v) * s }, };

	return result;		
}

static vec3f_t vec3f_divide(vec3f_t v, float s) {
	return vec3f_scale(v, 1.0 / s);
}

static float vec3f_length(vec3f_t v) {
	return sqrt(X(v) * X(v) + Y(v) * Y(v) + Z(v) * Z(v));
}

static vec3f_t vec3f_cross(vec3f_t v, vec3f_t q) {
	return ve3f_create(
			     Y(v) * Z(q) - Z(v) * Y(q),
			     Z(v) * X(q) - X(v) * Z(q),
			     X(v) * Y(q) - Y(v) * X(q));
}

static vec3f_t vec3f_normalize(vec3f_t v) {
	return vec3f_scale(v, 1.0 / vec3f_length(v));
}


static float vec3f_dot(vec3f_t v, vec3f_t q) {
	return X(v) * X(q) + Y(v) * Y(q) + Z(v) * Z(q);
}

static vec3f_t vec3f_negate(vec3f_t v) {
	return vec3f_create(vec3f_t, -v.n[0], -v.n[1], -v.n[2]);
}


// Vector4

static vector4 vector4_init(float x, float y, float z, float w) {
	vector4 result = { .n = {x, y, z, w},};

	return result;
}

static vector4 vector4_scale(vector4 v, float s) {
	vector4 result = { .n = { X(v) * s, Y(v) * s, Z(v) * s, W(v) * s }, };

	return result;		
}

static vector4 vector4_scale_add(vector4 v, float s) {
	vector4 result = { .n = { X(v) + s, Y(v) + s, Z(v) + s, W(v) + s }, };

	return result;		
}

static vector4 vector4_divide(vector4 v, float s) {
	return vector4_scale(v, 1.0 / s);
}

static vector4 vector4_add(vector4 v, vector4 q) {
	vector4 result = { .n = { X(v) + X(q), Y(v) + Y(q), Z(v) + Z(q), W(v) + W(q) }, };

	return result;
}

static vector4 vector4_subtract(vector4 v, vector4 q) {
	vector4 result = { .n = { X(v) - X(q), Y(v) - Y(q), Z(v) - Z(v), W(v) - W(q) }, };

	return result;	
}

static vector4 vector4_scale_subtract(vector4 v, float s) {
	vector4 result = { .n = { X(v) - s, Y(v) - s, Z(v) - s, W(v) - s }, };

	return result;
}


static float vector4_length(vector4 v) {
	return sqrt(X(v) * X(v) + Y(v) * Y(v) + Z(v) * Z(v) + W(v) * W(v));
}

static vector4 vector4_normalize(vector4 v) {
	return vector4_scale(v, 1.0 / vector4_length(v));
}

static float vector4_dot(vector4 v, vector4 q) {
	return X(v) * X(q) + Y(v) * Y(q) + Z(v) * Z(q) + W(v) * W(q);
}


// Matrix
typedef struct matrix2 matrix2;
struct matrix2 { float e[2][2]; };

typedef struct matrix3 matrix3;
struct matrix3 { float e[3][3]; };

typedef struct matrix4 matrix4;
struct matrix4 { float e[4][4]; };


#define create_matrix(T, ...) T ## _init(__VA_ARGS__)
#define M(matrix, i, j) ((matrix).e[j][i])
#define matrix_skew(T, ...) T ## _skew(__VA_ARGS__)
#define matrix_reflection(T, ...) T ## _reflection(__VA_ARGS__)
#define matrix_involution(T, ...) T ## _involution(__VA_ARGS__)
#define matrix_scaleV(T, ...) T ## _scaleV(__VA_ARGS__)
#define matrix_scale(T, ...) T ## _scale(__VA_ARGS__)
#define matrix_translation(T, ...) T ## _translation(__VA_ARGS__)
#define matrix_rotation_y(T, ...) T ## _rotation_y(__VA_ARGS__)
#define matrix_rotation(T, ...) T ## _rotation(__VA_ARGS__)
#define matrix_rotation_x(T, ...) T ## _rotation_x(__VA_ARGS__)
#define matrix_rotation_z(T, ...) T ## _rotation_z(__VA_ARGS__)

#define matrix2_identity { {{1.0, 0.0},		\
			{0.0, 1.0},		\
				},		\
			}			\

#define matrix3_identity { {{1.0, 0.0, 0.0},	\
			{0.0, 1.0, 0.0},	\
			{0.0, 0.0, 1.0},	\
				},		\
			}			\

#define matrix4_identity { {{1.0, 0.0, 0.0, 0.0},	\
			{0.0, 1.0, 0.0, 0.0},		\
			{0.0, 0.0, 1.0, 0.0},		\
			{0.0, 0.0, 0.0, 1.0},		\
				},			\
			}				\

// Matrix2
static matrix2 matrix2_init(float n00, float n01, float n10, float n11) {
	matrix2 result = { .e = { 
			{n00, n10}, 
			{n01, n11},
		},
	};

	return result;
}


// Matrix3
static matrix3 matrix3_init(float n00, float n01, float n02,
			    float n10, float n11, float n12,
			    float n20, float n21, float n22) {
	matrix3 result = { .e = { {n00, n10, n20}, 
				  {n01, n11, n21},
				  {n02, n12, n22},
		},
	};

	return result;
}


// Matrix4
static matrix4 matrix4_init(float n00, float n01, float n02, float n03,
			    float n10, float n11, float n12, float n13,
			    float n20, float n21, float n22, float n23,
			    float n30, float n31, float n32, float n33) {
	matrix4 result = { .e = { 
			{n00, n10, n20, n30},
			{n01, n11, n21, n31},
			{n02, n12, n22, n32},
			{n03, n13, n23, n33},
		},
	};

	return result;
}

static matrix4 matrix4_rotation_x(float deg) {
	float c = cos(deg);
	float s = sin(deg);
	return create_matrix(matrix4, 1.0, 0.0, 0.0, 0.0,
			     0.0, c,   -s,  0.0,
			     0.0, s,   c,   0.0,
			     0.0, 0.0, 0.0, 1.0);
}

static matrix4 matrix4_rotation_y(float deg) {
	float c = cos(deg);
	float s = sin(deg);
	return create_matrix(matrix4, c,   0.0, -s,  0.0,
			     0.0, 1.0, 0.0, 0.0,
			     s,   0.0, c,   0.0,
			     0.0, 0.0, 0.0, 1.0);
}

static matrix4 matrix4_rotation_z(float deg) {
	float c = cos(deg);
	float s = sin(deg);
	return create_matrix(matrix4, c,   -s,   0.0, 0.0,
			     s,  c,   0.0, 0.0,
			     0.0, 0.0, 1.0, 0.0,
			     0.0, 0.0, 0.0, 1.0);
}

static matrix4 matrix4_rotation(float deg, float x, float y, float z) {
	float c = cos(deg);
	float s = sin(deg);
	float d = 1.0 - c;
	float xd = x * d;
	float yd = y * d;
	float zd = z * d;
	float axay = xd * y;
	float axaz = xd * z;
	float ayaz = yd * z;
	return create_matrix(matrix4, c + xd * x, axay - s * z, axaz + s * y, 0.0,
			     axay + s * z, c + yd * y, ayaz - s * x, 0.0,
			     axaz - s * y, ayaz + s * x, c + zd * z, 0.0,
			     0.0, 0.0, 0.0, 1.0);
}

static matrix4 matrix4_translation(float x, float y, float z) {
	return create_matrix(matrix4, 1.0, 0.0, 0.0, x,
			     0.0, 1.0, 0.0, y,
			     0.0, 0.0, 1.0, z,
			     0.0, 0.0, 0.0, 1.0);
}

static matrix4 matrix4_scale_x(float x) {
	return create_matrix(matrix4, x,   0.0, 0.0, 0.0,
			     0.0, 1.0, 0.0, 0.0,
			     0.0, 0.0, 1.0, 0.0,
			     0.0, 0.0, 0.0, 1.0);
}

static matrix4 matrix4_scale_y(float y) {
	return create_matrix(matrix4, 1.0,   0.0, 0.0, 0.0,
			     0.0, y, 0.0, 0.0,
			     0.0, 0.0, 1.0, 0.0,
			     0.0, 0.0, 0.0, 1.0);
}

static matrix4 matrix4_scale_z(float z) {
	return create_matrix(matrix4, 1.0, 0.0, 0.0, 0.0,
			     0.0, 1.0, 0.0, 0.0,
			     0.0, 0.0, z,   0.0,
			     0.0, 0.0, 0.0, 1.0);
}

static matrix4 matrix4_scale(float x, float y, float z) {
	return create_matrix(matrix4, x,   0.0, 0.0, 0.0,
			     0.0, y,   0.0, 0.0,
			     0.0, 0.0, z,   0.0,
			     0.0, 0.0, 0.0, 1.0);
}

static matrix4 matrix4_add(matrix4 m, matrix4 q) {
	return create_matrix(matrix4,
			     M(m, 0, 0) + M(q, 0, 0), M(m, 1, 0) + M(q, 1, 0),
			     M(m, 2, 0) + M(q, 2, 0), M(m, 3, 0) + M(q, 3, 0),
			     M(m, 0, 1) + M(q, 0, 1), M(m, 1, 1) + M(q, 1, 1),
			     M(m, 2, 1) + M(q, 2, 1), M(m, 3, 1) + M(q, 3, 1),
			     M(m, 0, 2) + M(q, 0, 2), M(m, 1, 2) + M(q, 1, 2),
			     M(m, 2, 2) + M(q, 2, 2), M(m, 3, 2) + M(q, 3, 2),
			     M(m, 0, 3) + M(q, 0, 3), M(m, 1, 3) + M(q, 1, 3),
			     M(m, 2, 3) + M(q, 2, 3), M(m, 3, 3) + M(q, 3, 3));
}

static matrix4 matrix4_subtract(matrix4 m, matrix4 q) {
	return create_matrix(matrix4,
			     M(m, 0, 0) - M(q, 0, 0), M(m, 1, 0) - M(q, 1, 0),
			     M(m, 2, 0) - M(q, 2, 0), M(m, 3, 0) - M(q, 3, 0),
			     M(m, 0, 1) - M(q, 0, 1), M(m, 1, 1) - M(q, 1, 1),
			     M(m, 2, 1) - M(q, 2, 1), M(m, 3, 1) - M(q, 3, 1),
			     M(m, 0, 2) - M(q, 0, 2), M(m, 1, 2) - M(q, 1, 2),
			     M(m, 2, 2) - M(q, 2, 2), M(m, 3, 2) - M(q, 3, 2),
			     M(m, 0, 3) - M(q, 0, 3), M(m, 1, 3) - M(q, 1, 3),
			     M(m, 2, 3) - M(q, 2, 3), M(m, 3, 3) - M(q, 3, 3));
}

static matrix4 matrix4_mult(matrix4 m, matrix4 q) {
	return create_matrix(matrix4,
			     M(m, 0, 0) * M(q, 0, 0) + M(m, 0, 1) * M(q, 1, 0) + M(m, 0, 2) * M(q, 2, 0) + M(m, 0, 3) * M(q, 3, 0),
			     M(m, 0, 0) * M(q, 0, 1) + M(m, 0, 1) * M(q, 1, 1) + M(m, 0, 2) * M(q, 2, 1) + M(m, 0, 3) * M(q, 3, 1),
			     M(m, 0, 0) * M(q, 0, 2) + M(m, 0, 1) * M(q, 1, 2) + M(m, 0, 2) * M(q, 2, 2) + M(m, 0, 3) * M(q, 3, 2),
			     M(m, 0, 0) * M(q, 0, 3) + M(m, 0, 1) * M(q, 1, 3) + M(m, 0, 2) * M(q, 2, 3) + M(m, 0, 3) * M(q, 3, 3),
			     M(m, 1, 0) * M(q, 0, 0) + M(m, 1, 1) * M(q, 1, 0) + M(m, 1, 2) * M(q, 2, 0) + M(m, 1, 3) * M(q, 3, 0),
			     M(m, 1, 0) * M(q, 0, 1) + M(m, 1, 1) * M(q, 1, 1) + M(m, 1, 2) * M(q, 2, 1) + M(m, 1, 3) * M(q, 3, 1),
			     M(m, 1, 0) * M(q, 0, 2) + M(m, 1, 1) * M(q, 1, 2) + M(m, 1, 2) * M(q, 2, 2) + M(m, 1, 3) * M(q, 3, 2),
			     M(m, 1, 0) * M(q, 0, 3) + M(m, 1, 1) * M(q, 1, 3) + M(m, 1, 2) * M(q, 2, 3) + M(m, 1, 3) * M(q, 3, 3),
			     M(m, 2, 0) * M(q, 0, 0) + M(m, 2, 1) * M(q, 1, 0) + M(m, 2, 2) * M(q, 2, 0) + M(m, 2, 3) * M(q, 3, 0),
			     M(m, 2, 0) * M(q, 0, 1) + M(m, 2, 1) * M(q, 1, 1) + M(m, 2, 2) * M(q, 2, 1) + M(m, 2, 3) * M(q, 3, 1),
			     M(m, 2, 0) * M(q, 0, 2) + M(m, 2, 1) * M(q, 1, 2) + M(m, 2, 2) * M(q, 2, 2) + M(m, 2, 3) * M(q, 3, 2),
			     M(m, 2, 0) * M(q, 0, 3) + M(m, 2, 1) * M(q, 1, 3) + M(m, 2, 2) * M(q, 2, 3) + M(m, 2, 3) * M(q, 3, 3),
			     M(m, 3, 0) * M(q, 0, 0) + M(m, 3, 1) * M(q, 1, 0) + M(m, 3, 2) * M(q, 2, 0) + M(m, 3, 3) * M(q, 3, 0),
			     M(m, 3, 0) * M(q, 0, 1) + M(m, 3, 1) * M(q, 1, 1) + M(m, 3, 2) * M(q, 2, 1) + M(m, 3, 3) * M(q, 3, 1),
			     M(m, 3, 0) * M(q, 0, 2) + M(m, 3, 1) * M(q, 1, 2) + M(m, 3, 2) * M(q, 2, 2) + M(m, 3, 3) * M(q, 3, 2),
			     M(m, 3, 0) * M(q, 0, 3) + M(m, 3, 1) * M(q, 1, 3) + M(m, 3, 2) * M(q, 2, 3) + M(m, 3, 3) * M(q, 3, 3));
}												

static matrix4 matrix4_orthographic_projection(float left, float right, float bottom, float top, float near_distance, float far_distance) {
	return create_matrix(matrix4, 2.0 / (right - left), 0.0, 0.0, -(right + left) / (right - left),
			     0.0, 2.0 / (top - bottom), 0.0, -(top + bottom) / (top - bottom),
			     0.0, 0.0,  -2.0 / (far_distance - near_distance), 	-(far_distance + near_distance) / (far_distance - near_distance),
			     0.0, 0.0, 0.0, 1.0); 	
}


static matrix4 matrix4_perspective(float fov, float aspect_ratio, float near, float far) {
	float s = tan(0.5 * fov) * near;
	float right = aspect_ratio * s;
	float left = -right;
	float top = s;
	float bottom = -top;
	return create_matrix(matrix4, (2.0 * near) / (right - left), 0.0, (right + left) / (right - left), 0.0,
			     0.0, (2.0 * near) / (top - bottom), (top + bottom) / (top - bottom), 0.0,
			     0.0, 0.0, -(far + near) / (far - near),    -2.0 * far * near / (far - near),
			     0.0, 0.0, -1.0, 0.0);
}

static matrix4 matrix4_look_at(vec3f_t position, vec3f_t target, vec3f_t up) {
	
	vec3f_t forward = vector3_normalize(vector3_subtract(target, position));
	vec3f_t right = vector3_normalize(vector3_cross(forward, vector3_normalize(up)));
	vec3f_t upn = vector3_cross(right, forward);

	return create_matrix(matrix4, X(right), Y(right), Z(right), -vector3_dot(right, position),
			     X(upn), Y(upn), Z(upn), -vector3_dot(upn, position),
			     -X(forward), -Y(forward), -Z(forward), vector3_dot(forward, position),
			     0.0, 0.0, 0.0, 1.0);
}
