#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {

	FILE* fich;
	fich = fopen("exemplo.txt", "w");   /*r Read / w Write / a Append / (rw Read / r+ Write)*/
	fprintf(fich, "Linha1\n");
	fprintf(fich, "10*43 = %d\n", 10 * 43);
	fprintf(fich, "Linha 3\n");
	fclose(fich);
}