#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {

	FILE * fich1, *fich2;
	fich1 = fopen("entrada.txt", "r");
	fich2 = fopen("saida.txt", "w");
	if (fich1 == NULL || fich2 == NULL) {

		printf("Nao foi possivel abrir os 2 ficheiros\n");
		exit(1);
	}
	float x,y;
	while (!feof(fich1) ){
		fscanf(fich1, "%f", &x);
		y = sin(x * M_PI / 180);
		fprintf(fich2, "%8.3f;%8.3f\n", x, y);
	}
	fclose(fich1);
	fclose(fich2);
}