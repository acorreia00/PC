#include <stdio.h>
#include <stdlib.h>


int main() {

	int mes, i, ano, dias, diasmes[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	do {
		printf("Indique um mes\n");
		scanf(" %d", &mes);
		printf("Indique um ano\n");
		scanf(" %d", &ano);
	} while (mes<1 || mes>12 || ano<2000 || ano>2099);
	printf("Calendario de %d/%d: \n\nDom, Seg, Ter, Qua, Qui, Sex, Sab\n", mes, ano);
	dias = diasmes[mes - 1];
	for (i = 1; i <= dias; i++) {
		printf("%d", i);
		if (i % 7 == 0) {
			printf("\n");
		}
	}
}