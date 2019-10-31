#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>


int bissexto(int ano, int mes) {
	int ctd = 0, b6 = 0;
	for (ctd = 0; ctd <= ano; ctd = ctd + 4) {
		b6++;
	}
	if (ano % 4 == 0 && mes <= 2) {
		b6 = b6 - 1;
	}
	return b6;

}
void matrix(int dias, int total) {
	int mat[6][7], l, c, soma, fev;
	soma = 0;
	for (l = 0; l < 6; ++l) {
		printf("\n");
		for (c = 0; c < 7; ++c) {
			soma++;
			mat[l][c] = soma;
			if (l == 0) {
				switch (total) {
				case 6: printf("                               01"), soma = 1;break;
				case 5: printf("                          01   02"), soma = 2;break;
				case 4: printf("                     01   02   03"), soma = 3;break;
				case 3: printf("                01   02   03   04"), soma = 4;break;
				case 2: printf("           01   02   03   04   05"), soma = 5;break;
				case 1: printf("      01   02   03   04   05   06"), soma = 6;break;
				case 0: printf(" 01   02   03   04   05   06   07"), soma = 7;break;
				}
				c = 6;
			}

			else if (soma < dias + 1) {
				printf(" %02d  ", mat[l][c]);
			}
			else {
				break;
			}
		}
	}
}
int main() {
	int mes, ano, total = 6, dias[12] = { 31 , 28 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31 }, mescontrol = 0, soma = 0, b6;
	do {
		printf("Introduza um ano e um mes:\n");
		scanf_s("%d", &ano);
		scanf_s("%d", &mes);

	} while (!(mes >= 1 && mes <= 12 && ano >= 2000 && ano <= 2099));
	while (mescontrol < (mes - 1)) {
		soma = soma + dias[mescontrol];
		mescontrol++;
	}
	ano = ano - 2000;
	b6 = bissexto(ano, mes);
	total = (total + (ano * 365) + soma + b6);
	total = total % 7;
	printf("\n\n");
	ano = ano + 2000;
	printf(" Calendario %d\\%d\n\n", ano, mes);
	printf(" Dom, Seg, Ter, Qua, Qui, Sex, Sab");
	if (ano % 4 == 0 && mes == 2) {
		dias[1] = 29;
	}
	matrix(dias[mes - 1], total);

	system("pause");
	return 0;
}