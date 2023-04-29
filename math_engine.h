#pragma once

#include <math.h>

static float degrees_to_radians(float deg) {
	return deg * (M_PI / 180.0);
}

static float radians_to_degrees(float rad) {
	return rad * (180.0 / M_PI);
}

typedef struct rgb rgb;
struct rgb { float c[3]; };

typedef struct rgba rgba;
struct rgba { float c[4]; };

#define create_color(T, ...) T ## _init(__VA_ARGS__)
#define C(color, i) ((color).n[i])
#define R(color) ((color).c[0])
#define G(color) ((color).c[1])
#define B(color) ((color).c[2])
#define A(color) ((color).c[3])

static rgb rgb_init(float r, float g, float b) {
  rgb result = { { r, g, b } };

  return result;
}

static rgb rgb_add(rgb v, rgb q) {
  return create_color(rgb, R(v) + R(q), G(v) + G(q), B(v) + B(q));
}

static rgb rgb_subtract(rgb v, rgb q) {
  return create_color(rgb, R(v) - R(q), G(v) - G(q), B(v) - B(q));
}

static rgb rgb_mult(rgb v, rgb q) {
  return create_color(rgb, R(v) * R(q), G(v) * G(q), B(v) * B(q));
}

static rgb rgb_scale(rgb v, float s) {
  return create_color(rgb, R(v) * s, G(v) * s, B(v) * s);
}

static rgb rgb_divide(rgb v, float s) {
  s = 1.0 / s;
  return create_color(rgb, R(v) * s, G(v) * s, B(v) * s);
}

typedef struct vector2 vector2;
struct vector2 { float n[2]; };

typedef struct vector3 vector3;
struct vector3 { float n[3]; };

typedef struct vector4 vector4;
struct vector4 { float n[4]; };


#define create_vector(T, ...) T ## _init(__VA_ARGS__)
#define V(vector, i) ((vector).n[i])
#define X(vector) ((vector).n[0])
#define Y(vector) ((vector).n[1])
#define Z(vector) ((vector).n[2])
#define W(vector) ((vector).n[3])


// Vector2

static vector2 vector2_init(float x, float y) {
	vector2 result = { .n = {x, y}, };

	return result;
}

static vector2 vector2_scale_add(vector2 v, float s) {
	vector2 result = { .n = { X(v) + s, Y(v) + s }, };

	return result;		
}

static vector2 vector2_add(vector2 v, vector2 q) {
	vector2 result = { .n = { X(v) + X(q), Y(v) + Y(q)}, };

	return result;	
}

static vector2 vector2_subtract(vector2 v, vector2 q) {
	vector2 result = { .n = { X(v) - X(q), Y(v) - Y(q) }, };

	return result;
}

static vector2 vector2_scale_subtract(vector2 v, float s) {
	vector2 result = { .n = { X(v) - s, Y(v) - s }, };

	return result;		
}

static vector2 vector2_scale(vector2 v, float s) {
	vector2 result = { .n = { X(v) * s, Y(v) * s }, };

	return result;		
}

static vector2 vector2_divide(vector2 v, float s) {
	return vector2_scale(v, 1.0 / s);
}

static float vector2_length(vector2 v) {
  return sqrt(X(v) * X(v) + Y(v) * Y(v));
}

static vector2 vector2_normalize(vector2 v) {
	return vector2_scale(v, 1.0 / vector2_length(v));
}

static float vector2_dot(vector2 v, vector2 q) {
	return X(v) * X(q) + Y(v) * Y(q);
}






// Vector3

static vector3 vector3_init(float x, float y, float z) {
	vector3 result = { .n = {x, y, z},};

	return result;
}

static vector3 vector3_scale_add(vector3 v, float s) {
	vector3 result = { .n = { X(v) + s, Y(v) + s, Z(v) + s }, };

	return result;		
}

static vector3 vector3_add(vector3 v, vector3 q) {
	vector3 result = { .n = { X(v) + X(q), Y(v) + Y(q), Z(v) + Z(q) }, };

	return result;	
}

static vector3 vector3_subtract(vector3 v, vector3 q) {
	vector3 result = { .n = { X(v) - X(q), Y(v) - Y(q), Z(v) - Z(q) }, };

	return result;	
}

static vector3 vector3_scale_subtract(vector3 v, float s) {
	vector3 result = { .n = { X(v) - s, Y(v) - s, Z(v) - s }, };

	return result;
}

static vector3 vector3_scale(vector3 v, float s) {
	vector3 result = { .n = { X(v) * s, Y(v) * s, Z(v) * s }, };

	return result;		
}

static vector3 vector3_divide(vector3 v, float s) {
	return vector3_scale(v, 1.0 / s);
}

static float vector3_length(vector3 v) {
	return sqrt(X(v) * X(v) + Y(v) * Y(v) + Z(v) * Z(v));
}

static vector3 vector3_cross(vector3 v, vector3 q) {
	return create_vector(vector3,
			     Y(v) * Z(q) - Z(v) * Y(q),
			     Z(v) * X(q) - X(v) * Z(q),
			     X(v) * Y(q) - Y(v) * X(q));
}

static vector3 vector3_normalize(vector3 v) {
	return vector3_scale(v, 1.0 / vector3_length(v));
}


static float vector3_dot(vector3 v, vector3 q) {
	return X(v) * X(q) + Y(v) * Y(q) + Z(v) * Z(q);
}

static vector3 vector3_negate(vector3 v) {
	return create_vector(vector3, -v.n[0], -v.n[1], -v.n[2]);
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

static matrix4 matrix4_look_at(vector3 position, vector3 target, vector3 up) {
	
	vector3 forward = vector3_normalize(vector3_subtract(target, position));
	vector3 right = vector3_normalize(vector3_cross(forward, vector3_normalize(up)));
	vector3 upn = vector3_cross(right, forward);

	return create_matrix(matrix4, X(right), Y(right), Z(right), -vector3_dot(right, position),
			     X(upn), Y(upn), Z(upn), -vector3_dot(upn, position),
			     -X(forward), -Y(forward), -Z(forward), vector3_dot(forward, position),
			     0.0, 0.0, 0.0, 1.0);
}
