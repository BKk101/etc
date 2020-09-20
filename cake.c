#include <stdio.h>

int main(void)
{
    int a1,a2;
	int b1,b2;
	int temp;

	scanf("%d%d", &a1,&a2);
	scanf("%d%d", &b1,&b2);

	temp = a1;
	a1 = a1 > a2 ? a1 : a2;
	a2 = temp > a2 ? a2 : temp;
	temp = b1;
	b1 = b1 > b2 ? b1 : b2;
	b2 = temp > b2 ? b2 : temp;
	if (a1 > b1) {
		if (b1 > a2 && b2 < a2) printf("cross");
		else printf("not cross");
	}
	else {
		if (a1 > b2 && a2 < b2) printf("cross");
		else printf("not cross");
	}
    return 0;
}