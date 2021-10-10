#include <math.h>
#include <float.h>

#include "kernel.h"

float get_closest_pair_1d_naive(vec1_t* a, vec1_t* b,
		const vec1_t* points, const int n_points) {
	float min_distance = FLT_MAX;

	for (int i = 0; i < n_points; ++i) {
		for (int j = 0; j < n_points; ++j) {
			if (i == j)
				continue;

			float diff = fabs(points[i] - points[j]);

			if (diff < min_distance) {
				*a = points[i];
				*b = points[j];

				min_distance = diff;
			}
		}
	}

	return min_distance;
}

float get_closest_pair_1d_daq(vec1_t* a, vec1_t* b,
		const vec1_t* points, const int n_points) {
	float min_distance = FLT_MAX;

	// TODO: Fill this!
	
	return min_distance;
}

float get_closest_pair_2d_naive(vec2_t* a, vec2_t* b,
		const vec2_t* points, const int n_points) {
	float min_distance_sq = FLT_MAX;

	for (int i = 0; i < n_points; ++i) {
		for (int j = 0; j < n_points; ++j) {
			if (i == j)
				continue;

			float x_diff = points[i].x - points[j].x;
			float y_diff = points[i].y - points[j].y;

			float diff = x_diff*x_diff + y_diff*y_diff;

			if (diff < min_distance_sq) {
				*a = points[i];
				*b = points[j];
				
				min_distance_sq = diff;
			}
		}
	}
	
	return sqrtf(min_distance_sq);
}

float get_closest_pair_2d_daq(vec2_t* a, vec2_t* b,
		const vec2_t* points, const int n_points) {
	float min_distance_sq = FLT_MAX;

	// TODO: Fill this!
	
	return sqrtf(min_distance_sq);
}

float get_closest_pair_3d_naive(vec3_t* a, vec3_t* b,
		const vec3_t* points, const int n_points) {
	float min_distance_sq = FLT_MAX;

	for (int i = 0; i < n_points; ++i) {
		for (int j = 0; j < n_points; ++j) {
			if (i == j)
				continue;

			float x_diff = points[i].x - points[j].x;
			float y_diff = points[i].y - points[j].y;
			float z_diff = points[i].z - points[j].z;

			float diff = x_diff*x_diff + y_diff*y_diff + z_diff*z_diff;

			if (diff < min_distance_sq) {
				*a = points[i];
				*b = points[j];
				
				min_distance_sq = diff;
			}
		}
	}

	return sqrtf(min_distance_sq);
}

float get_closest_pair_3d_daq(vec3_t* a, vec3_t* b,
		const vec3_t* points, const int n_points) {
	float min_distance_sq = FLT_MAX;

	// TODO: Fill this!
	
	return sqrtf(min_distance_sq);
}
