#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <string.h>

typedef struct {
	int fr, numA;
	float volts[1000];
}sinal;

sinal readTxt(char nomeFich[20]) {

	int a = 0;
	FILE* fich1, * fich2, * fich3;
	sinal input1, input2, input3;
	strcat(nomeFich, ".txt");
	fich1 = fopen(nomeFich, "r");
	/*fich2 = fopen("sinal2.txt", "r");
	fich3 = fopen("sinal3.txt", "r");*/
	if (fich1 == NULL) {
		printf("\nErro ao abrir o ficheiro sinal1\n");
		exit(1);
	}
	/*else if (fich2 == NULL) {
		printf("\nErro ao abrir o ficheiro sinal2\n");
		exit(1);
	}
	else if (fich3 == NULL) {
		printf("\nErro ao abrir o ficheiro sinal3\n");
		exit(1);
	}*/
	fscanf(fich1, "%d", &input1.fr);
	fscanf(fich1, "\n%d", &input1.numA);
	while (!feof(fich1)) {

		fscanf(fich1, "%d", &input1.volts[a]);
		a++;
	}

	fclose(fich1);

	return input1;
}

int meiaOnda() {
	int a=0;
	return a;
}

int ondaCompleta() {
	int a=0;
	return a;
}
/*sinal writeTxt() {
	FILE* ficheirosaida;
	sinal amostra1, amostra2;
	if (amostra1.numA != amostra2.numA) { //dif numero de amostras 
		printf("\n Numero de amostras dos sinais diferentes\n");
		exit(1);
	}//parar proj
	ficheirosaida = fopen("resultado.csv", "w");
	fprintf(ficheirosaida, "#Tempo    Entrada    Saída");
	return amostra1;
}*/

int userInterface(){
	int opcao = 0;
	setlocale(LC_ALL, " ");
	printf("1 - Abrir ficheiro de amostras\n");
	printf("2 - Aplicar retifica%c%co de meia onda\n", 135);
	printf("3 - Aplicar retifica%c%co de onda completa\n", 135);
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
	while (selector !=6) {
		int selector = 0;
		selector = userInterface();
		if (selector == 1) {
			printf("executada opcao %d\n", selector);
			printf("Escolha o nome do ficheiro a abrir\n");
			scanf("%s", &nome);
			//readTxt(name);
		}
		else if (selector == 2) {
			printf("executada opcao %d\n", selector);
			meiaOnda();
		}
		else if (selector == 3) {
			printf("executada opcao %d\n", selector);
			ondaCompleta();
		}
		else if (selector == 4) {
			printf("executada opcao %d\n", selector);
		}
		else if (selector == 5) {
			printf("Escolha o nome do ficheiro a guardar\n");
			scanf("%s", &nome);
			printf("executada opcao %d\n", selector);
		}
		else if (selector == 6) {
			exit(1);
		}
	}

}
