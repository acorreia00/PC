#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include<locale.h>
typedef struct {
	int fr, numA;
	float volts[1000];
}sinal;

sinal readTxt() {

	int a = 0;
	FILE* fich1, * fich2, * fich3;
	sinal input;
	fich1 = fopen("sinal.txt", "r");
	fich2 = fopen("sinal2.txt", "r");
	fich3 = fopen("sinal3.txt", "r");
	if (fich1 == NULL) {
		printf("\nErro ao abrir o ficheiro sinal1\n");
		exit(1);
	}
	else if (fich2 == NULL) {
		printf("\nErro ao abrir o ficheiro sinal2\n");
		exit(1);
	}
	else if (fich3 == NULL) {
		printf("\nErro ao abrir o ficheiro sinal3\n");
		exit(1);
	}
	fscanf(fich1, "%d", &input.fr);
	fscanf(fich1, "\n%d", &input.numA);
	while (!feof(fich1)) {

		fscanf(fich1, "%d", &input.volts[a]);
		a++;
	}

	fclose(fich1);

	return input;
}

sinal writeTxt() {
	FILE* ficheirosaida;
	sinal amostra1, amostra2;
	if (amostra1.numA != amostra2.numA) { //dif numero de amostras 
		printf("\n Numero de amostras dos sinais diferentes\n");
		return;
	}//parar proj
	ficheirosaida = fopen("resultado.csv", "w");
	fprintf(ficheirosaida, "#Tempo    Entrada    Saída");

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
	int selector = 0;
	selector = userInterface();
	if (selector == 1) {
		printf("executada opcao %d", selector);
	}
	else if (selector == 2) {
		printf("executada opcao %d", selector);
	}
	else if (selector == 3) {
		printf("executada opcao %d", selector);
	}
	else if (selector == 4) {
		printf("executada opcao %d", selector);
	}
	else if (selector == 5) {
		printf("executada opcao %d", selector);
	}
	else if (selector == 6) {
		printf("executada opcao %d", selector);
		exit(1);
	}
}