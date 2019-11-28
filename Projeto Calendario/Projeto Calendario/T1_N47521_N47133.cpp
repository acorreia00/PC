#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int bissexto(int ano, int mes) {					//Funcao para descobrir se o ano e bisexto ou nao
	int ctd = 0, b6 = 0;
	for (ctd = 0; ctd <= ano; ctd = ctd + 4) {
		b6++;
	}
	if (ano % 4 == 0 && mes <= 2) {
		b6 = b6 - 1;
	}
	return b6;

}
void matrix(int dias, int total) {					//Funcao matriz para organizar os dias todos e acertar com o primeiro dia do mes
	int mat[6][7], l, c, soma, fev;
	soma = 0;
	for (l = 0; l < 6; ++l) {
		printf("\n ");
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
	FILE* fich;
	fich = fopen("valores.txt", "a+");
	int mes, ano, total = 6, dias[12] = { 31 , 28 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31 }, mescontrol = 0, somam = 0, b6;
	do {
		printf("Introduza um ano e um mes:\n");		//Pedir valores ano e mes entre 2000-2099 e 1-12 respetivamente
		scanf_s("%d", &ano);
		scanf_s("%d", &mes);

	} while (!(mes >= 1 && mes <= 12 && ano >= 2000 && ano <= 2099));
	while (mescontrol < (mes - 1)) {
		somam = somam + dias[mescontrol];			//Somam e o total de dias ate ao mes escolhido dentro do ano escolhido
		mescontrol++;
	}
	ano = ano - 2000;								//Numero de anos desde 2000
	b6 = bissexto(ano, mes);						//Numero de dias 29/2 que ja passaram desde 2000
	total = (total + (ano * 365) + somam + b6);		//Numero de dias desde jan 2000 ate ao mes/ano escolhido
	total = total % 7;								//Em que dia da semana comeca o mes
	printf("\n\n");
	ano = ano + 2000;								//Ano para printar
	printf(" Calendario %d\\%d\n\n", ano, mes);
	printf(" Dom, Seg, Ter, Qua, Qui, Sex, Sab");
	if (ano % 4 == 0 && mes == 2) {
		dias[1] = 29;								//No caso do ano ser bisexto muda o total de dias de fevereiro para 29
	}
	matrix(dias[mes - 1], total);					//Printar Dias Calendario

	fprintf(fich, "%d/%d\n", mes, ano);
	fclose(fich);
}