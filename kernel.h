#ifndef KERNEL_H_
#define KERNEL_H_

typedef float vec1_t;

typedef struct vec2 {
	float x, y;
} vec2_t;

typedef struct vec3 {
	float x, y, z;
} vec3_t;

float get_closest_pair_1d_naive(vec1_t* a, vec1_t* b,
		const vec1_t* points, const int n_points);

float get_closest_pair_2d_naive(vec2_t* a, vec2_t* b,
		const vec2_t* points, const int n_points);

float get_closest_pair_3d_naive(vec3_t* a, vec3_t* b,
		const vec3_t* points, const int n_points);

float get_closest_pair_1d_daq(vec1_t* a, vec1_t* b,
		const vec1_t* points, const int n_points);

float get_closest_pair_2d_daq(vec2_t* a, vec2_t* b,
		const vec2_t* points, const int n_points);

float get_closest_pair_3d_daq(vec3_t* a, vec3_t* b,
		const vec3_t* points, const int n_points);

typedef float (*implementation_1d_t)(vec1_t* a, vec1_t* b,
		const vec1_t* points, const int n_points);

typedef float (*implementation_2d_t)(vec2_t* a, vec2_t* b,
		const vec2_t* points, const int n_points);

typedef float (*implementation_3d_t)(vec3_t* a, vec3_t* b,
		const vec3_t* points, const int n_points);

#endif // KERNEL_H_
