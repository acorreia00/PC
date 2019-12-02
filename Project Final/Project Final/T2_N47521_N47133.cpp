#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <string.h>
#define MAX_INPUT 1500

typedef struct {
	int fr, numA;
	float *volts[];
}sinal;

sinal readTxt(char nome[25]) {
	int a = 0;
	FILE* fich1;
	sinal input1 = (sinal*)malloc(sizeof(input1.numA));	strcat(nome, ".txt");
	fich1 = fopen(nome, "r");

	if (fich1 == NULL) {
		printf("\nErro ao abrir o ficheiro sinal1\n");
		exit(EXIT_FAILURE);
	}

	fscanf(fich1, "%d", &input1.fr);
	fscanf(fich1, "%d", &input1.numA);

	for (int i = input1.numA, index = 0;i;i--, index++) {
		fscanf(fich1, "%f", &(input1.volts[index]));
		printf("%d\n", index);
	}
	fclose(fich1);
	return input1;
}

sinal* meiaOnda(sinal* fich1) {
	input1.volts[];
	for (int i = 0;i == ;i++) {


	};
	return volts[];
}

/*sinal* ondaCompleta(sinal* fich1) {
	sinal* numActd;

	for (ctd=0; numA->ctd;
	printf();

	return ;
}*/

sinal* writeTxt(char nome[25]) {
	FILE* ficheirosaida;
	sinal* amostra1, amostra2;
	if (amostra1->numA != amostra2.numA) { //dif numero de amostras 
		printf("\n Numero de amostras dos sinais diferentes\n");
		exit(1);
	}//parar proj
	ficheirosaida = fopen("resultado.csv", "a+");
	fprintf(ficheirosaida, "#Tempo    Entrada    Saída");
	return amostra1;
}

int userInterface() {
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
	sinal* fich1;
	do {

		selector = userInterface();
		if (selector == 1) {
			printf("executada opcao %d\n", selector);
			printf("Escolha o nome do ficheiro a abrir\n");
			scanf("%s", &nome);
			fich1 = readTxt(nome);
		}
		else if (selector == 2) {
			printf("executada opcao %d\n", selector);
			meiaOnda(fich1);
		}
		else if (selector == 3) {
			printf("executada opcao %d\n", selector);
			//ondaCompleta(fich1);
		}
		else if (selector == 4) {
			printf("executada opcao %d\n", selector);
		}
		else if (selector == 5) {
			printf("Escolha o nome do ficheiro a guardar\n");
			scanf("%s", &nome);
			fich1 = writeTxt(nome);
		}
		else if (selector == 6) {
			exit(1);
		}
	} while (selector > 0 && selector < 6);
	free(fich1);
}
