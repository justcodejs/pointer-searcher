#include "base_include.h"

typedef struct Point {
	double x; // Asse X
	double y; // Asse Y
} Point;

int main(int argc, char *argv[]) {
	FILE *in = fopen("data/input.txt", "r");
	double values[1024];
	int x = 0;

	while (!feof(in)) {
		fscanf(in, "%lf", &values[x]);
		x++;
	}

	fclose(in);

	// Save point
	Point point[x];
	int _x = 0;
	int _y = 1;

	for (int j = 0; j < x; j++) {
		point[j].x = values[j + _x];
		point[j].y = values[j + _y];

		_x++;
		_y++;
	}

	double diffPoint[x/2];
	int i = 0;
	int _i = 1;

	while ((i+_i) != x/2) {
		diffPoint[i] = point[i].x - point[i + _i].x;
		diffPoint[i + _i] = point[i].y - point[i + _i].y;
		i++;
	}
	
	double a, b, d;

	for (int i = 0; i < (sizeof(diffPoint)/sizeof(*diffPoint))/2; i++) {
		a = diffPoint[i] * diffPoint[i];
		b = diffPoint[i+1] * diffPoint[i+1];
		d = a + b;
		printf("Distance of p1 and p2 is: %.5f\n", sqrt(d));
	}

	printf("\nEnd program.\n");
	return 0;
}