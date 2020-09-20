#include <stdio.h>
 
int main(void)
{
    double s,e;
	double temp;
	double sum=0;
	int i;

	for (i=0;i<5;i++) {
		scanf("%lf%lf", &s,&e);
		temp = e-s>1 ? (e-s>5 ? 4 : e-s-1) : 0;
		sum += temp;
	}
	sum *= 10000;
	if (sum >= 150000) sum *= 0.95;
	else if (sum <= 50000) sum *= 1.05;
	printf("%d", (int)sum);
	return 0;
}