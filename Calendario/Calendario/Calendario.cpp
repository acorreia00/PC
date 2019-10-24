#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int main() {

	int mes, ano, diasmes[] = {31,28,31,30,31,30,31,31,30,31,30,31};
	do {
		printf("Indique um mes\n");
		scanf(" %d", &mes);
		printf("Indique um ano\n");
		scanf(" %d", &ano);
	} while (mes < 1 || mes>12 || ano < 2000 || ano>2099);
		printf("Dom, Seg, Ter, Qua, Qui, Sex, Sab\n");

}