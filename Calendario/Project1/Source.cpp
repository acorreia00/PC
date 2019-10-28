#include<stdio.h>
#include<stdlib.h>


void matrix(int dias, int total) {
	int mat[6][7], l, c, soma;
	soma = 0;
	for (l = 0; l < 6; ++l) {
		printf("\n");
		for (c = 0; c < 7; ++c) {
			soma++;
			mat[l][c] = soma;
			if (l == 1) {
				switch (total) {
				case 6: printf("   ");
				case 5: printf("   ");
				case 4: printf("   ");
				case 3: printf("   ");
				case 2: printf("   ");
				case 1: printf("   ");
				case 0: printf("%02d ", mat[l][c]);
				}
				c = 6;
			}
			else if (soma < dias + 1) {
				printf(" %02d ", mat[l][c]);
			}
			else{
				break;
			}
		}
	}
}


int main() {
	int mes, ano, total = 6, dias[12] = { 31 , 28 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31 }, mescontrol=0, soma=0;
	do {
		printf("Introduza 1 ano e 1 mes\n");
		scanf_s("%d", &ano);
		scanf_s("%d", &mes);

	} while (!(mes >= 1 && mes <= 12 && ano >= 2000 && ano <= 2099));
	while (mescontrol < (mes - 1)) {
		soma = soma + dias[mescontrol];
		mescontrol++;
		ano = ano - 2000;
		total = total + (ano * 365) + soma;
		total = total % 7;
		printf("\n\n");
		ano = ano + 2000;
		printf(" Calendario %d/%d\n\n", ano, mes);
		printf(" Dom Seg Ter Qua Qui Sex Sab");

		matrix(dias[mes - 1], total);


		return 0;

	}
}