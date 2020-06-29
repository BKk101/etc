#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
	printf("프린세스 메이커");
	getchar();
	printf("\n당신은 무보수로 세상을 구한 용사.\n");
	printf("\n마왕을 무찌른 후 한가롭게 백수생활을 즐기고 있었다.\n");
	printf("\n\"님아 헬프요!\"\n");
	printf("\n어느 날 여신이 찾아왔다.\n");
	printf("\n\"굴다리 밑에서 주운 아이인데... 요즘 천계도 형편이 어려워서ㅠ.ㅠ 1년만 맡아 주세요?\"\n");
	printf("\n당신은 자타공인 여신의 가호를 받는 용사!\n");
	printf("\n호구용사의 미덕은 도움이 필요한 사람을 외면하지 않는것.\n");
	printf("\n보상은 쥐뿔도 없겠지만 잘 키워 보기로 한다...\n");
	getchar();

	int i, M = 500, H = 20, I = 20, S = 20, St = 0, n = 0, flag1 = 0, flag2 = 0, flag3 = 0, It[3] = { 0 };
	srand((unsigned int)time(NULL)); int tmp = 0;
	i = 1;
	while(i<=20){
		printf("==============================\n");
		printf("%d주차 상태\n",i);
		printf("\t소지금  : %dG\n", M);
		printf("\t체력    : %d\n", H + 300 * It[0] + 50 * It[1]);
		printf("\t지능    : %d\n", I + 50 * It[0] + 50 * It[1] + 100 * It[2]);
		printf("\t감수성  : %d\n", S + 50 * It[0] + 50 * It[1] + 100 * It[2]);
		printf("\t스트레스: %d\n", St);
		printf("\t아이템  : %s%s%s\n", (It[0])?"용사의 검":"", (It[1])?" 현자의 돌":"", (It[2])?" 마법전서":"");
		printf("==============================\n");
		printf("\t1. 아르바이트 (능력치 약간 상승, 골드 획득, 스트레스 보통)\n");
		printf("\t2. 교육       (능력치 상승, 골드 소비, 스트레스 약간)\n");
		printf("\t3. 무사수행   (능력치 상승, 골드 획득, 아이템 획득, 스트레스 심함)\n");
		printf("\t4. 휴식       (스트레스 약간 하락)\n");
		printf("\t5. 바캉스     (스트레스 많이 하락, 골드 소비)\n");
		printf("\t6. 종료       (다음주로...)\n");
		printf("==============================\n");
		while (flag1==0) {
			printf("이번 주의 스케줄은?:");
			scanf("%d", &n);
			printf("\n");
			switch (n) {
			case 1:
				printf("\t아르바이트\n");
				printf("==============================\n");
				printf("\t1) 사냥터   (성공률50%% 체력+15 지능+1 감수성-5 스트레스+30 보수200G)\n");
				printf("\t2) 농장     (성공률60%% 체력+10 지능-1 감수성-1 스트레스+10 보수50G)\n");
				printf("\t3) 레스토랑 (성공률70%% 체력+1  지능-1 감수성+3 스트레스+12 보수80G)\n");
				printf("\t4) 미술관   (성공률90%% 체력-5  지능+3 감수성+5 스트레스+5  보수30G)\n");
				printf("\t5) 취소\n");
				printf("==============================\n");
				while (flag2 == 0) {
					printf("어떤 아르바이트를 합니까?");
					scanf("%d", &n);
					switch (n) {
					case 1:
						printf("\n사냥터에 갑니다.\n");
						printf("\t체력     +15\n");
						H += 15;
						printf("\t지능     +1\n");
						I += +1;
						printf("\t감수성   -5\n");
						S += -5;
						printf("\t스트레스 +30\n");
						St += 30;
						if (rand() % 100 + 1 <= 50) {
							printf("아르바이트 성공! 보수로 200G를 받았습니다.\n");
							M += 200;
						}
						else {
							printf("아르바이트 실패! 보수를 받지 못했습니다.T.T\n");
						}
						flag2 = 1;
						break;
					case 2:
						printf("\n농장일을 돕습니다.\n");
						printf("\t체력     +10\n");
						H += 10;
						printf("\t지능     -1\n");
						I += -1;
						printf("\t감수성   -1\n");
						S += -1;
						printf("\t스트레스 +10\n");
						St += 10;
						if (rand() % 100 + 1 <= 60) {
							printf("아르바이트 성공! 보수로 50G를 받았습니다.\n");
							M += 50;
						}
						else {
							printf("아르바이트 실패! 보수를 받지 못했습니다.T.T\n");
						}
						flag2 = 1;
						break;
					case 3:
						printf("\n레스토랑일을 돕습니다.\n");
						printf("\t체력     +1\n");
						H += 1;
						printf("\t지능     -1\n");
						I += -1;
						printf("\t감수성   +3\n");
						S += 3;
						printf("\t스트레스 +12\n");
						St += 12;
						if (rand() % 100 + 1 <= 70) {
							printf("아르바이트 성공! 보수로 80G를 받았습니다.\n");
							M += 80;
						}
						else {
							printf("아르바이트 실패! 보수를 받지 못했습니다.T.T\n");
						}
						flag2 = 1;
						break;
					case 4:
						printf("\n미술관일을 돕습니다.\n");
						printf("\t체력     -5\n");
						H += -5;
						printf("\t지능     +3\n");
						I += 3;
						printf("\t감수성   +5\n");
						S += 5;
						printf("\t스트레스 +5\n");
						St += 5;
						if (rand() % 100 + 1 <= 90) {
							printf("아르바이트 성공! 보수로 30G를 받았습니다.\n");
							M += 30;
						}
						else {
							printf("아르바이트 실패! 보수를 받지 못했습니다.T.T\n");
						}
						flag2 = 1;
						break;
					case 5://취소
						flag2 = 1;
						flag3 = 1;
						break;						   //flag변수를 두개
					default:
						printf("\n잘못 입력하였습니다.\n");
						flag2 = 1;
						flag3 = 1;
						break;
					}
				}
				flag1 = 1;
				break;
			case 2:
				printf("\t   교육\n");
				printf("==============================\n");
				printf("\t1) 검술  (체력+20 지능-1 감수성-2  스트레스+10 수업료150G)\n");
				printf("\t2) 문학  (체력-2  지능+5 감수성+10 스트레스+5  수업료300G)\n");
				printf("\t3) 미술  (체력-3  지능+3 감수성+20 스트레스+5  수업료500G)\n");
				printf("\t4) 취소\n");
				printf("==============================\n");
				while (flag2 == 0) {
					printf("어떤 교육을 받습니까?");
					scanf("%d", &n);
					switch (n) {
					case 1:
						if (M < 150) {
							printf("\n소지금이 부족합니다.\n");
							flag2 = 1;
							flag3 = 1;
							break;
						}
						printf("\n검술 교육을 받았습니다.\n");
						printf("\t체력     +20\n");
						H += 20;
						printf("\t지능     -1\n");
						I += -1;
						printf("\t감수성   -2\n");
						S += -2;
						printf("\t스트레스 +10\n");
						St += 10;
						printf("\t수업료   -150G\n");
						M += -150;
						flag2 = 1;
						break;
					case 2:
						if (M < 300) {
							printf("\n소지금이 부족합니다.\n");
							flag2 = 1;
							flag3 = 1;
							break;
						}
						printf("\n문학 교육을 받았습니다.\n");
						printf("\t체력     -2\n");
						H += -2;
						printf("\t지능     +5\n");
						I += 5;
						printf("\t감수성   +10\n");
						S += 10;
						printf("\t스트레스 +5\n");
						St += 5;
						printf("\t수업료   -300G\n");
						M += -300;
						flag2 = 1;
						break;
					case 3:
						if (M < 500) {
							printf("\n소지금이 부족합니다.\n");
							flag2 = 1;
							flag3 = 1;
							break;
						}
						printf("\n미술 교육을 받았습니다.\n");
						printf("\t체력     -3\n");
						H += -3;
						printf("\t지능     +3\n");
						I += 3;
						printf("\t감수성   +20\n");
						S += 20;
						printf("\t스트레스 +5\n");
						St += 5;
						printf("\t수업료   -500G\n");
						M += -500;
						flag2 = 1;
						break;
					case 4://취소
						flag2 = 1;
						flag3 = 1;
						break;						  
					default:
						printf("\n잘못 입력하였습니다.\n");
						flag2 = 1;
						flag3 = 1;
						break;
					}
				}
				flag1 = 1;
				break;
			case 3:
				printf("        무사수행\n");
				printf("==============================\n");
				printf("\t성공시: 체력+30~50 지능+20~30 감수성+5~100 스트레스+50\n");
				printf("\t실패시: 체력-20~30 지능 -5~10 감수성-5~10  스트레스+80\n");
				printf("==============================\n");
				printf("무사수행을 떠나겠습니까?\n");
				printf("1) 네\t 2) 아니오\n");
				printf("입력:");
				scanf("%d", &n);
				switch (n) {
				case 1:
					if (rand() % 100 + 1 <= 40) {
						printf("무사수행을 성공적으로 다녀왔습니다.\n");
						tmp = rand() % 21 + 30;
						printf("\t체력     +%d\n", tmp);
						H += tmp;
						tmp = rand() % 11 + 10;
						printf("\t지능     +%d\n", tmp);
						I += tmp;
						tmp = rand() % 96 + 5;
						printf("\t감수성   +%d\n", tmp);
						S += tmp;
						tmp = 0;
						printf("\t스트레스 +50\n");
						St += 50;
						if (rand() % 100 + 1 <= 5 && It[0]==0) {
							printf("용사의 검을 획득하였습니다! 빠밤!\n"); //기본능력치에 바로 더해진다!!
							printf("\t체력     +300\n");
							printf("\t지능     +50\n");
							printf("\t감수성   +50\n");
							It[0] = 1;
						}
						if (rand() % 100 + 1 <= 30 && It[1]==0) {
							printf("현자의 돌을 획득하였습니다! 빠밤!\n");
							printf("\t체력     +50\n");
							printf("\t지능     +50\n");
							printf("\t감수성   +50\n");
							It[1] = 1;
						}
						if (rand() % 100 + 1 <= 20 && It[2]==0) {
							printf("마법전서를 획득하였습니다! 빠밤!\n");
							printf("\t체력     +0\n");
							printf("\t지능     +100\n");
							printf("\t감수성   +100\n");
							It[2] = 1;
						}
					}
					else {
						printf("무사수행에 실패하고 돌아왔습니다.\n");
						tmp = rand() % 11 + 20;
						printf("\t체력     -%d\n", tmp);
						H += -tmp;
						tmp = rand() % 6 + 5;
						printf("\t지능     -%d\n", tmp);
						I += -tmp;
						tmp = rand() % 6 + 5;
						printf("\t감수성   -%d\n", tmp);
						S += -tmp;
						tmp = 0;
						printf("\t스트레스 +80\n");
						St += 80;
					}
					break;
				case 2:
					flag3 = 1;
				default:
					printf("\n잘못 입력하였습니다.\n");
					flag3 = 1;
				}
				flag1 = 1;
				break;
			case 4:
				printf("휴식을 취하겠습니까? (스트레스 -30)\n");
				printf("1) 네\t 2) 아니오\n");
				printf("입력:");
				scanf("%d", &n);
				switch (n) {
				case 1:
					printf("\n휴식을 취합니다.\n");
					printf("\t스트레스 -30\n");
					St += -30;
					break;
				case 2:
					flag3 = 1;
				default:
					printf("\n잘못 입력하였습니다.\n");
					flag3 = 1;
				}
				flag1 = 1;
				break;
			case 5:
				while (flag2 == 0) {
					printf("바캉스를 떠나겠습니까? (스트레스 -80 비용200G)\n");
					printf("1) 네\t 2) 아니오\n");
					printf("입력:");
					scanf("%d", &n);
					switch (n) {
					case 1:
						if (M < 200) {
							printf("\n소지금이 부족합니다.\n");
							flag2 = 1;
							flag3 = 1;
							break;
						}
						printf("\n바캉스를 떠납니다.\n");
						printf("\t스트레스 -80\n");
						St += -80;
						printf("\t소지금   -200G\n");
						M += -200;
						flag2 = 1;
						break;
					case 2:
						flag2 = 1;
						flag3 = 1;
					default:
						printf("\n잘못 입력하였습니다.\n");
						flag2 = 1;
						flag3 = 1;
					}	
				}
				flag1 = 1;
				break;
			case 6:
				printf("다음주로 넘어갑니다.\n");
				flag1 = 1;
				break;
			default:
				printf("잘못 입력하였습니다.\n");
				flag1 = 1;
				flag3 = 1;
				break;
			}
		}
		if (H < 0) H = 0; if (I < 0) I = 0; if (S < 0) S = 0; if (St < 0) St = 0; //능력치 범위
		if (St >= 100) {
			printf("\n스트레스를 너무 많이 주셨군요! 아이가 가출했습니다.\n");
			printf("\n4주가 지나 아이가 돌아왔습니다.\n");
			St = 0;
			if(i<=16) i += 4;
			else { i = 21; }
		}
		else if (flag3 == 0) { i++; }
		flag1 = 0; flag2 = 0; flag3 = 0; n = 0;//flag 변수 초기화 시키기
		printf("\n");
	};
	H = H + 300 * It[0] + 50 * It[1];
	I = I + 50 * It[0] + 50 * It[1] + 100 * It[2];
	S = S + 50 * It[0] + 50 * It[1] + 100 * It[2];
	printf("약속했던 %d주가 지났습니다.\n\n", i - 1);
	printf("\t결과\n");
	printf("==============================\n");
	printf("\t체력    : %d\n", H);
	printf("\t지능    : %d\n", I);
	printf("\t감수성  : %d\n", S);
	printf("==============================\n");
	printf("\n당신의 아들(딸)은 훌륭하게 성장해서... 두둥!\n\n");
	//getchar();
	//system("pause");
	int job = 0;
	if (H >= 250 && I >= 100 && S <= 100) { job = 1; }//용사
	if (H >= 70 && I >= 70 && S >= 200) { job = 2; }//예술가
	if (H >= 50 && I >= 200 && S >= 70) { job = 3; }//학자
	if (H >= 150 && I >= 150 && S >= 150) { job = 4; }//여왕
	switch (job) {
	case 0:
		printf("\"%s\"가 되었습니다.!\n", "노동자");
		break;
	case 1:
		printf("\"%s\"가 되었습니다.!\n", "전설의 용사");
		break;
	case 2:
		printf("\"%s\"가 되었습니다.!\n", "예술가");
		break;
	case 3:
		printf("\"%s\"가 되었습니다.!\n", "학자");
		break;
	case 4:
		printf("\"%s\"이 되었습니다.!\n", "여왕");
		break;
	}
	//엔딩 추가
	printf("\n");
	system("pause");
	return 0;
}