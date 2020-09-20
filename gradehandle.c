#include <stdio.h>
#define MAX 5

struct st_score
{
	int no;
	char name[30];
	int age;
	int kor; int eng; int tot;
};
void All_Print(struct st_score *p)
{
	int i;
	for (i=0;i<MAX;i++) {
		printf("no %d name %s age %d kor %d eng %d tot %d\n", p[i].no,p[i].name,p[i].age,p[i].kor,p[i].eng,p[i].tot);
	}
}

void One_Print(struct st_score *p)
{

}

void Data_Input(struct st_score *p)
{

}
void Data_Update(struct st_score *p)
{

}
void Name_Sort(struct st_score *p)
{

}
void Tot_Sort(struct st_score *p)
{

}

int Menu_Disp(void)
{
	int sel=0;
	printf("==== 신상 기록부 ===\n");
	printf(" 1) 전체출력 \n");
	printf(" 2) 개인출력 \n");
	printf(" 3) 개인정보입력 \n");
	printf(" 4) 개인정보수정 \n");
	printf(" 5) 이름순정렬 \n");
	printf(" 6) 성적순정렬 \n");
	printf("=================\n");
	printf(">>메뉴 선택? "); scanf("%d", &sel); return sel;
}

int main(void)
{
	int sel;
	struct st_score score[MAX]={ {1,"kim",25, 80, 90, 0},\
		{2, "lew",35, 70, 60, 0},{3, "hong",29, 80, 55,0},\
		{4, "lee", 44, 89, 79,0},{5, "park", 37, 50, 100,0} };
	for(;;)
	{
		//system("cls");
		sel=Menu_Disp();
		switch(sel)
		{
			case 1:All_Print(score);break;
			case 2:One_Print(score);break;
			case 3:Data_Input(score);break;
			case 4:Data_Update(score);break;
			case 5:Name_Sort(score);break;
			case 6:Tot_Sort(score);break;
			default:printf("다시입력해주세요\n");break;
		}
	}
	return 0;
}