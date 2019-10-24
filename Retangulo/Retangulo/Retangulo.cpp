#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(){

		float comp,larg,area,perim;
		printf("Quais sao as dimensoes do retangulo[Comprimento e Largura]\n");
		scanf_s(" %f%f", &comp, &larg);
		area = comp * larg;
		perim = 2 * (comp + larg);
		printf("O rectangulo com o comprimento %f e a largura %f tem uma area igual %f e um perimetro igual a %f\n", comp, larg, area, perim);
		printf("\n\n\n");
		system("pause");
		return 0;
}