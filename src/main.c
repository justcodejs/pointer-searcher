#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define HEIGHT 2
#define WIDTH  2

typedef struct Point
{
	float x;
	float y;
} Point;

void getPoints(char _nameFileInput[]);

int main(int argc, char *argv[])
{
	getPoints("data/input.txt");

	return 0;
}

void getPoints(char _nameFileInput[])
{
	FILE *in = fopen(_nameFileInput, "r");
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
		diffPoint[i] = point[i].x - point[i+1].y;
	}

	for (int i = 0; i < (sizeof(diffPoint)/sizeof(*diffPoint))/2; i++)
	{
		float a = pow(diffPoint[i], 2);
		float b = pow(diffPoint[i+1], 2);
		float d = sqrt(a+b);
		printf("Point: %.1f\n", d);
	}
}