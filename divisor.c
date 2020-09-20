#include <stdio.h>

int main(void)
{
	int i;
	int a,b;
	int cnt=0;

	scanf("%d%d", &a,&b);
	for (i=1;i*i<=b;i++) {
		if (i*i>=a) cnt++;
	}
	printf("%d", b-a+1-cnt);
	return 0;
}