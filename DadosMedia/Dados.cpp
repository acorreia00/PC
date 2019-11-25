#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {

	float valor,soma = 0;
	FILE * fich;
	fich = fopen("dados.txt", "r");
	if (fich == NULL)printf("Nao Abriu");
	else{
		int i,n;
		fscanf(fich, "%d", &n);
		for (i = 0;i < n;i++) {
			fscanf(fich, "%f", &valor);

			soma = soma + valor;
		}
			fclose(fich);
			printf("Media = %f\n", soma/n);
		}
		system("pause");
		return 0;
}