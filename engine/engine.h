#pragma once

typedef struct rgbf_t rgbf_t;
struct rgbf_t { float c[3]; };
extern rgbf_t rgbf_create(float r, float g, float b);
extern rgbf_t rgbf_from_array_create(float vals[3]);
extern rgbf_t rgbf_from_rgb_create(rgbf_t c);
extern void rgbf_initialize(rgbf_t* rgb, float r, float g, float b);
extern rgbf_t rgbf_add(rgbf_t v, rgbf_t q);
extern rgbf_t rgbf_subtract(rgbf_t v, rgbf_t q);
extern rgbf_t rgbf_multiply(rgbf_t v, rgbf_t q);
extern rgbf_t rgbf_scale(rgbf_t v, float s);
extern rgbf_t rgbf_divide(rgbf_t v, float s);

typedef struct rgbaf_t rgbaf_t;
struct rgbaf_t { float c[4]; };
extern rgbaf_t rgbaf_create(float r, float g, float b, float a);
extern rgbaf_t rgbaf_from_array_create(float vals[4]);
extern rgbaf_t rgbaf_from_rgba_create(rgbaf_t c);
extern void rgbaf_initialize(rgbaf_t* rgba, float r, float g, float b, float a);
extern rgbaf_t rgbaf_add(rgbaf_t v, rgbaf_t q);
extern rgbaf_t rgbaf_subtract(rgbaf_t v, rgbaf_t q);
extern rgbaf_t rgbaf_multiply(rgbaf_t v, rgbaf_t q);
extern rgbaf_t rgbaf_scale(rgbaf_t v, float s);
extern rgbaf_t rgbaf_divide(rgbaf_t v, float s);


typedef struct vec2f_t vec2f_t;
struct vec2f_t { float n[2]; };
extern vec2f_t vec2f_create(float x, float y);
extern vec2f_t vec2f_from_array_create(float elems[2]);
extern vec2f_t vec2f_add(vec2f_t v, vec2f_t q);
extern vec2f_t vec2f_subtract(vec2f_t v, vec2f_t q);
extern vec2f_t vec2f_normalize(vec2f_t v);
extern vec2f_t vec2f_scale(vec2f_t v, float s);
extern void vec2f_initialize(vec2f_t* v, float x, float y);
extern float vec2f_dot_product(vec2f_t v, vec2f_t q);
extern float vec2f_cross_product(vec2f_t v, vec2f_t q);
extern float vec2f_magntitude(vec2f_t v);
extern vec2f_t vec2f_abs(vec2f_t v);
extern vec2f_t vec2f_ceil(vec2f_t v);
extern vec2f_t vec2f_floor(vec2f_t v);
extern float vec2f_min_component(vec2f_t v);
extern float vec2f_max_component(vec2f_t v);
extern float vec2f_horizontal_product(vec2f_t v);
extern vec2f_t vec2f_project(vec2f_t v, vec2f_t q);
extern vec2f_t vec2f_reject(vec2f_t v, vec2f_t q);



typedef struct vec3f_t vec3f_t;
struct vec3f_t { float n[3]; };
extern vec3f_t vec3f_create(float x, float y, float z);
extern vec3f_t vec3f_from_array_create(float elems[3]);
extern vec3f_t vec3f_add(vec3f_t v, vec3f_t q);
extern vec3f_t vec3f_subtract(vec3f_t v, vec3f_t q);
extern vec3f_t vec3f_normalize(vec3f_t v);
extern vec3f_t vec3f_negate(vec3f_t v);
extern vec3f_t vec3f_scale(vec3f_t v, float s);
extern vec3f_t vec3f_cross_product(vec3f_t v, vec3f_t q);
extern vec3f_t vec3f_abs(vec3f_t v);
extern vec3f_t vec3f_ceil(vec3f_t v);
extern vec3f_t vec3f_floor(vec3f_t v);
extern void vec3f_initialize(vec3f_t* v, float x, float y, float z);
extern float vec3f_dot_product(vec3f_t v, vec3f_t q);
extern float vec3f_magntitude(vec3f_t v);
extern float vec3f_min_component(vec3f_t v);
extern float vec3f_max_component(vec3f_t v);
extern float vec3f_horizontal_product(vec3f_t v);



typedef struct vec4f_t vec4f_t;
struct vec4f_t { float n[4]; };
extern vec3f_t vec4f_to_vec3f_convert(vec4f_t v);
extern vec2f_t vec4f_to_vec2f_convert(vec4f_t v);
extern vec4f_t vec4f_position_from_vec3f_convert(vec4f_t v);
extern vec4f_t vec4f_position_from_vec2f_convert(vec4f_t v);



typedef struct vec2i_t vec2i_t;
struct vec2i_t { int n[2]; };

typedef struct vec3i_t vec3i_t;
struct vec3i_t { int n[3]; };

typedef struct mat2f_t mat2f_t;
struct mat2f_t { vec2f_t e[2]; };
extern mat2f_t mat2f_create(float n00, float n01, float n10, float n11);
extern mat2f_t mat2f_from_array_create(float e[2][2]);
extern mat2f_t mat2f_from_vec2f_create(vec2f_t e[2]);
extern mat2f_t mat2f_identity();
extern mat2f_t mat2f_multiply(mat2f_t m, mat2f_t q);
extern mat2f_t mat2f_vec2f_multiply(mat2f_t m, vec2f_t v);
extern void mat2f_initialize(mat2f_t* m, float n00, float n01, float n10, float n11);
extern mat2f_t mat2f_transpose(mat2f_t m);
extern mat2f_t mat2f_inverse(mat2f_t m);
extern mat2f_t mat2f_shearing_x_make(float k);
extern mat2f_t mat2f_shearing_y_make(float k);
extern mat2f_t mat2f_rotation_make(float angle, float x, float y);
extern mat2f_t mat2f_rotate_x_make(float angle);
extern mat2f_t mat2f_rotate_y_make(float angle);
extern mat2f_t mat2f_scale_make(float x, float y);
extern mat2f_t mat2f_stretch_x_make(float k);
extern mat2f_t mat2f_stretch_y_make(float k);
extern mat2f_t mat2f_squeeze_make(float k);
extern mat2f_t mat2f_translation_make(float x, float y);



typedef struct mat3f_t mat3f_t;
struct mat3f_t { vec3f_t e[3]; };
extern mat3f_t matf3_create(float n00, float n01, float n02,
	float n10, float n11, float n12,
	float n20, float n21, float n22);
extern mat3f_t mat3f_from_array_create(float e[3][3]);
extern mat3f_t mat3f_from_vec3f_create(vec3f_t e[3]);
extern mat3f_t mat3f_identity();
extern mat3f_t mat3f_multiply(mat3f_t m, mat3f_t q);
extern mat3f_t mat3f_inverse(mat3f_t m);
extern mat3f_t mat3f_transpose(mat3f_t m);
extern vec3f_t mat3f_vec3f_multiply(mat3f_t m, vec3f_t v);
extern float mat3f_determinant(mat3f_t m);
extern mat3f_t mat3f_reflection_with_vec3f_make(vec3f_t v);
extern mat3f_t mat3f_involution_make(float x, float y, float z);
extern mat3f_t mat3f_involution_with_vec3f_make(vec3f_t v);
extern mat3f_t mat3f_scale_xyz_make(float sx, float sy, float sz);
extern mat3f_t mat3f_scale_with_factor_and_vec3f_make(float s, vec3f_t a);
extern mat3f_t mat3f_skew_with_vec3fs_make(float angle, vec3f_t a, vec3f_t b);


typedef struct mat4f_t mat4f_t;
struct mat4f_t { vec4f_t e[4]; };
extern mat4f_t mat4f_create(float n00, float n01, float n02, float n03,
	float n10, float n11, float n12, float n13,
	float n20, float n21, float n22, float n23,
	float n30, float n31, float n32, float n33);
extern mat4f_t mat4f_from_array_create(float e[4][4]);
extern mat4f_t mat4f_from_vec4f_create(vec4f_t e[4]);
extern mat4f_t mat4f_multiply(mat4f_t m, mat4f_t q);
extern vec4f_t mat4f_vec4f_multiply(mat4f_t m, vec4f_t v);
extern vec4f_t mat4f_vec4f_with_perspective_divide_multiply(mat4f_t m, vec4f_t v);
extern vec3f_t mat4f_vec3f_multiply(mat4f_t m, vec3f_t v);
extern mat4f_t mat4f_identity();
extern mat4f_t mat4f_multiply(mat4f_t a, mat4f_t b);
extern mat4f_t mat4f_inverse(mat4f_t m);
extern mat4f_t mat4f_transpose(mat4f_t m);
extern mat4f_t mat4f_rotate_x_make(float angle);
extern mat4f_t mat4f_rotate_y_make(float angle);
extern mat4f_t mat4f_rotate_z_make(float angle);
extern mat4f_t mat4f_shearing_make(float x, float y, float z);
extern mat4f_t mat4f_scale_x_make(float x);
extern mat4f_t mat4f_scale_y_make(float y);
extern mat4f_t mat4f_scale_z_make(float z);
extern mat4f_t mat4f_scale_with_vec3f_make(vec3f_t v);
extern mat4f_t mat4f_scale_xyz_make(float x, float y, float z);
extern mat4f_t mat4f_rotation_make(float angle, float x, float y, float z);
extern mat4f_t mat4f_rotation_with_vec3f_make(float angle, vec3f_t v);
extern mat4f_t mat4f_perspective_make(float fov, float aspect_ratio, float near, float far);
extern mat4f_t mat4f_translation_make(float x, float y, float z);
extern mat4f_t mat4f_translation_with_vec3f_make(vec3f_t v);
extern mat4f_t mat4f_look_at_make(float px, float py, float pz, float tx, float ty, float tz, float ux, float uy, float uz);
extern mat4f_t mat4f_look_at_with_vec3f_make(vec3f_t position, vec3f_t target, vec3f_t up);