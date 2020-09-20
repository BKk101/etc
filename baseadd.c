#include <stdio.h>
#include <string.h>

char Number[] = "0123456789ABCDEF";

int convert_d(int base, char * num)
{
	int i,j;
	int sum = 0;

	for (i=0;i<strlen(num);i++) {
		j = -1;
		while(num[i] != Number[++j]);
		sum += j;
		sum *= base;
	}
	return sum / base;
}

void convert_b(int base, int num, char * str)
{
	char temp[11];
	int i,j;

	for (i=0;num != 0;i++) {
		temp[i] = Number[num % base];
		num /= base;
	}
	j = 0;
	while (--i >= 0) {
		str[j++] = temp[i];
	}
	str[j] = '\0';
}

int main(void)
{
	int base;
	int dec;
	char num[11];
	char a[10],b[10];

	printf(">>>> N진법연산 <<<<\n");
	printf("2 ~ 16 진법 입력 : ");
	scanf("%d", &base);
	printf("operand1 : ");
	scanf("%s", a);
	printf("operand2 : ");
	scanf("%s", b);
	dec = convert_d(base, a) + convert_d(base, b);
	convert_b(base, dec, num);
	printf("10진법 => %d, %d진법 => %s\n", dec,base,num);
	return 0;
}