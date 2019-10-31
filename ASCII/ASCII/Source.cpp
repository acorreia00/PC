#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main() {
	int i,ascii=32;
	printf("Tabela ASCII - Codigos 32 a 127\n");
	for (i = 1;i <= 96;i++) {
				printf("%3d-%c ", i+31, ascii);
				ascii++;
				if (i % 8 == 0) {
					printf("\n");
				}
	}
		printf("\n\nTabela ASCII - Codigos 128 a 255\n");
		for (i = 97;i <= 224;i++) {
			printf("%3d-%c ", i + 31, ascii);
			ascii++;
			if (i % 8 == 0) {
				printf("\n");
		}
	}
		printf("\n\n\n");
		system("pause");
		return 0;
}