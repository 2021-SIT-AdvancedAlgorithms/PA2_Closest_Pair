// There is nothing to implement further here.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include <sys/time.h>

#include "kernel.h"

enum e_implementation_type {
	eit_naive, eit_daq, eit_count
};

static const char* implementation_type_name[eit_count] = {
	"Naive",
	"Divide and Conquer"
};

enum e_dimension {
	ed_0d, ed_1d, ed_2d, ed_3d
};

static implementation_1d_t implementations_1d[eit_count] = {
	get_closest_pair_1d_naive,
	get_closest_pair_1d_daq
};

static implementation_2d_t implementations_2d[eit_count] = {
	get_closest_pair_2d_naive,
	get_closest_pair_2d_daq
};

static implementation_3d_t implementations_3d[eit_count] = {
	get_closest_pair_3d_naive,
	get_closest_pair_3d_daq
};

void run(float* points, int n_points, enum e_implementation_type implementation_type, enum e_dimension dimension){
	float a[3], b[3];
	float min_distance;

	printf("Getting closest pair of points in %dD space by the %s algorithm\n", dimension, implementation_type_name[implementation_type]);

	struct timeval start;
	gettimeofday(&start, NULL);

	switch (dimension) {
	case ed_1d:
		min_distance = implementations_1d[implementation_type](
				(vec1_t*)a,
				(vec1_t*)b,
				(const vec1_t*)points,
				n_points);
		break;
	case ed_2d:
		min_distance = implementations_2d[implementation_type](
				(vec2_t*)a,
				(vec2_t*)b,
				(const vec2_t*)points,
				n_points);
		break;
	case ed_3d:
		min_distance = implementations_3d[implementation_type](
				(vec3_t*)a,
				(vec3_t*)b,
				(const vec3_t*)points,
				n_points);
		break;
	}

	struct timeval end;
	gettimeofday(&end, NULL);

	printf("a:");
	for (int i = 0; i < dimension; ++i) {
		printf(" %f", a[i]);
	}
	printf("\n");

	printf("b:");
	for (int i = 0; i < dimension; ++i) {
		printf(" %f", b[i]);
	}
	printf("\n");

	printf("min_distance: %f\n", min_distance);

	printf("elapsed time: %lf\n", ((end.tv_sec + end.tv_usec * 0.000001) - (start.tv_sec + start.tv_usec * 0.000001)));
}

int main(int argc, char** argv)
{
	if (argc != 3) {
		fprintf(stderr, "usage: ./closest-pair <n|daq> <1d|2d|3d>\n");
		exit(1);
	}

	enum e_implementation_type implementation_type;
	enum e_dimension dimension;

	if (strcmp(argv[1], "n") == 0) {
		implementation_type = eit_naive;
	} else if (strcmp(argv[1], "daq") == 0) {
		implementation_type = eit_daq;
	} else {
		fprintf(stderr, "Invalid arguments : implementation type.\n");
		exit(1);
	}

	if (strcmp(argv[2], "1d") == 0) {
		dimension = ed_1d;
	} else if (strcmp(argv[2], "2d") == 0) {
		dimension = ed_2d;
	} else if (strcmp(argv[2], "3d") == 0) {
		dimension = ed_3d;
	} else {
		fprintf(stderr, "Invalid arguments : dimension.\n");
		exit(1);
	}

	int n_points;
	scanf("%d", &n_points);

	float* points = malloc(sizeof(float) * dimension * n_points);

	srandom(0xdeadbeef);

	for (int i = 0; i < n_points; ++i) {
		for (int j = 0; j < dimension; ++j) {
			points[dimension*i + j] = (float)random() / RAND_MAX;
		}
	}

	run(points, n_points, implementation_type, dimension);

	free(points);

	return 0;
}

