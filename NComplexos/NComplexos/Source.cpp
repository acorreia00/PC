#include <stdio.h>
#include <stdlib.h>

typedef struct {
	float re;
	float iw;
}complexo;

void ecomplexo(complexo c) {
	printf("%g + %gj\n", c.re, c.iw);
}

complexo somaComplexos(complexo c1, complexo c2) {

	complexo R;
	R.re = c1.re + c2.re;
	R.iw = c1.iw + c2.iw;
	return R;
}

complexo MultComplexos(complexo c1, complexo c2) {

	complexo r;
	r.re = c1.re * c2.re - c1.iw * c2.iw;
	r.iw = c1.iw * c2.re + c1.re * c2.iw;
	return r;
}

int main() {
	complexo z1, z2, c;
	complexo k = { 7,-1 };
	z1.re = 16;
	z1.iw = 2;
	z2.re = 5;
	z2.iw = -2;
	c.re = 4;
	c.iw = 1;
	ecomplexo(z1);
	ecomplexo(z2);
	ecomplexo(c);
	ecomplexo(k);
}