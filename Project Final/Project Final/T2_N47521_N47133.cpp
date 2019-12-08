#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <string.h>

typedef struct {
	int fr, numA;
	float *volts;
}sinal;

sinal readTxt(char nome[25]) {

	int a = 0;
	FILE* fich1;
	sinal input1;
	strcat(nome, ".txt");
	fich1 = fopen(nome, "r");
	if (fich1 == NULL) {
		printf("\nErro ao abrir o ficheiro sinal1\n");
		exit(1);
	}

	fscanf(fich1, "%d", &input1.fr);
	fscanf(fich1, "%d", &input1.numA);
	input1.volts = (float*)malloc(input1.numA * sizeof(float));
	for (a=0; a<=input1.numA; a++){
		fscanf(fich1, "%f", &input1.volts[a]);
		printf("%d\n", a);
	}
	fclose(fich1);
	return input1;
}

sinal meiaOnda(sinal fich1) {
	int ctd = 0;
	sinal saida;
	saida.numA = fich1.numA;
	saida.volts = (float*)malloc(saida.numA * sizeof(float));
	for (ctd = 0;fich1.numA > ctd; ctd++) {
		if (fich1.volts[ctd] > 0) {
			saida.volts[ctd] = fich1.volts[ctd];
		}
		else {
			saida.volts[ctd] = 0;
		}
	}
	return saida;
}

sinal ondaCompleta(sinal fich1) {
	int ctd=0;
	sinal saida;
	saida.numA = fich1.numA;
	printf("\n\n%d\n\n", saida.numA);
	printf("\n\n%d\n\n", fich1.numA);
	saida.volts = (float*)malloc(saida.numA * sizeof(float));
	for (ctd = 0;fich1.numA >= ctd; ctd++) {
		if (fich1.volts[ctd] > 0) {
			saida.volts[ctd] = fich1.volts[ctd];
			printf("%d\n", ctd);
		}
		else {
			saida.volts[ctd] = -fich1.volts[ctd];
			printf("%d\n", ctd);
		}
	}
	return saida;
}

void writeTxt(char nome[25], sinal fich1, sinal saida) {
	FILE* ficheirosaida;
	int fr, ctd;
	float temp, ctdt = 0;
	if (fich1.numA != saida.numA) { //dif numero de amostras 
		printf("\n Numero de amostras dos sinais diferentes\n");
		exit(1);
	}//parar proj
	fr = fich1.fr;
	temp = (1 / (float)fr);
	
	strcat(nome, ".txt");
	ficheirosaida = fopen(nome,"w");
	fprintf(ficheirosaida, "#Tempo    Entrada    Saída\n");
	for (ctd = 0; ctd <= fich1.numA; ctd++) {
		fprintf(ficheirosaida, "%01f    %01f     %01f\n", ctdt, fich1.volts[ctd], saida.volts[ctd]);
		
		
		printf("02%f\n", ctdt);
		ctdt = temp * ctd;
	}
	fclose(ficheirosaida);
}

int userInterface(){
	int opcao = 0;
	setlocale(LC_ALL, "");
	printf("1 - Abrir ficheiro de amostras\n");
	printf("2 - Aplicar retifica%c%co de meia onda\n", 'ç', 'ã');
	printf("3 - Aplicar retifica%c%co de onda completa\n", 'ç', 'ã');
	printf("4 - Aplicar filtro RC\n");
	printf("5 - Guardar ficheiro de resultados\n");
	printf("6 - Sair do programa\n");
	scanf("%d", &opcao);
	while (opcao >= 7 || opcao < 0) {
		printf("op%c%co invalida introduza 1 nova ", 'ç', 'ã');
		scanf("%d", &opcao);
	}
	return opcao;
}


int main() {
	
	char nome[25];
	int selector = 0;
	sinal fich1, saida, meia;
	do{

		selector = userInterface();
		if (selector == 1) {
			printf("executada opcao %d\n", selector);
			printf("Escolha o nome do ficheiro a abrir\n");
			scanf("%s", &nome);
			fich1=readTxt(nome);
		}
		else if (selector == 2) {
			printf("executada opcao %d\n", selector);
			saida=meiaOnda(fich1);
		}
		else if (selector == 3) {
			printf("executada opcao %d\n", selector);
			saida=ondaCompleta(fich1);
		}
		else if (selector == 4) {
			printf("executada opcao %d\n", selector);
		}
		else if (selector == 5) {
			printf("Escolha o nome do ficheiro a guardar\n");
			scanf("%s", &nome);
			writeTxt(nome,fich1,saida);
		}
		else if (selector == 6) {
			exit(1);
		}
	}while (selector > 0 && selector < 6);
}

