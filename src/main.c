#include "base_include.h"

typedef struct Point
{
	float x;
	float y;
	Point *p;
} Point;

int main(int argc, char *argv[])
{
	FILE *in = fopen("data/input.txt", "r");
	float values[1024];
	int x;

	while (!feof(in))
	{
		fscanf(in, "%f", &values[x]);
		x++;
	}

	fclose(in);

	// Save point
	Point point[x];
	for (int j = 0; j < x; j++)
	{
		point[j].x = values[j];
		point[j].y = values[j+1];
	}

	float diffPoint[x/2];
	for (int i = 0; i < x / 2; i++)
	{
		diffPoint[i] = point[i].x - point[i].y;
	}


	for (int i = 0; i < x/2; i++)
	{
		printf("Point: %.1f\n", diffPoint[i]);
	}

	float a, b, d;
	/* for (int i = 0; i < (sizeof(diffPoint)/sizeof(*diffPoint))/2; i++)
	{
		a = pow(diffPoint[i], 2);
		b = pow(diffPoint[i+1], 2);
		d = sqrt(a+b);
		printf("Point: %.1f\n", d);
	} */

	printf("\nEnd program.\n");
	getchar();
	return 0;
}