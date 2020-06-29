#define _CRT_SECURE_NO_WARNINGS   //오델로 원본규칙 구현//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>
//오델로 원본규칙 구현//

char board[10][50] = { "  1 2 3 4 5 6 7 8","1 . . . . . . . .","2 . . . . . . . .","3 . . . . . . . .","4 . . . O X . . .","5 . . . X O . . .","6 . . . . . . . .","7 . . . . . . . .","8 . . . . . . . ." };
void put_stone(int, int); // 돌 놓기
int check_stone(int, int); //놓을 수 있는 위치 확인
void turn_stone(int, int); //돌 뒤집기
void swap(int); //돌 색깔 바꾸기
int cnt_black(); //흑돌 개수 세기
int cnt_white(); //백돌 개수 세기
void end(); //종료 
void point_clear(); // 포인트 초기화
void change(int); //숫자 바꾸기
int stone_color = 0;//0이면 흑 1이면 백
int flag1 = 0; //재입력 루프
int start = 0;
int check_pointR = 0;
int check_pointL = 0;
int check_pointU = 0;
int check_pointD = 0;
int check_pointRUx = 0;
int check_pointRUy = 0;
int check_pointLUx = 0;
int check_pointLUy = 0;
int check_pointRDx = 0;
int check_pointRDy = 0;
int check_pointLDx = 0;
int check_pointLDy = 0;
int com_x, com_y; //컴퓨터 랜덤 좌표

int main() {
	int i, j;
	srand((unsigned int)time(NULL));

	for (i = 0; i < 9; i++) {
		printf("%s\n", board[i]);
	} 
	printf("\n"); //초기 보드 상태
	int n = 1, x, y, b, w, select, out = 0, flag3 = 0, exit = 0;
	while (out==0) {
		printf("돌을 선택하세요(흑=0 / 백=1):");
		scanf("%d", &select);
		if (select) {
			printf("백을 선택하였습니다.\n");
			start = 1;//후수
			out = 1;
		}
		else {
			if (select==0) {
				printf("흑을 선택하였습니다.\n");
				start = 0;//선수
				out = 1;
			}
			else {
				printf("잘못 입력하였습니다. 다시 입력하세요.\n");
			}
		}
	}
	if (start) {
		printf("흑돌(X) 차례입니다.\t");
		b = cnt_black();
		w = cnt_white();
		printf("흑돌:%d 백돌:%d\n", b, w);
		printf("놓을 위치 (가로, 세로):");
		while (1) {
			com_x = rand() % 8 + 1; com_y = rand() % 8 + 1; //좌표생성을 함수로?
			if (board[com_y][2 * (com_x)] == '.') {
				if (check_stone(com_x, com_y)) {
					printf("%d %d\n", com_x, com_y);
					board[com_y][2 * (com_x)] = 'X';
					turn_stone(com_x, com_y);
					for (i = 0; i < 9; i++) {
						printf("%s\n", board[i]);
						}
					printf("\n"); //보드 출력 
					flag1 = 0; // 재입력x n증가
					point_clear();
					com_x = 0; com_y = 0;
					n++;
					swap(stone_color);
					break;
				}
			}
		}
	}
	else { change(start); }
	while (n <= 60){
		if (stone_color) {
			printf("백돌(O) 차례입니다.\t");
			b = cnt_black();
			w = cnt_white();
			printf("흑돌:%d 백돌:%d\n", b, w);
		}
		else { 
			printf("흑돌(X) 차례입니다.\t");
			b = cnt_black();
			w = cnt_white();
			printf("흑돌:%d 백돌:%d\n", b, w);
		}
		for (i = 1; i < 9; i++) { //놓을자리 있는지 확인
			for (j = 1; j < 9; j++) {
				if (board[i][2 * j] == '.') {
					if (check_stone(j, i)) { flag3 = 1; }
					point_clear();
				}
			}
		}
		if (flag3 == 1) {
			printf("놓을 위치 (가로, 세로):");
			if (start) {
				scanf("%d%d", &x, &y);
				printf("\n");
				put_stone(x, y);
				Sleep(1000);
			}
			else {
				while (1) {
					com_x = rand() % 8 + 1; com_y = rand() % 8 + 1; //좌표생성을 함수로?
					if (board[com_y][2 * (com_x)] == '.') {
						if (check_stone(com_x, com_y)) {
							printf("%d %d\n", com_x, com_y);
							if (stone_color) { //백돌 입력
								board[com_y][2 * (com_x)] = 'O';
								turn_stone(com_x, com_y);
								for (i = 0; i < 9; i++) {
									printf("%s\n", board[i]);
								}
								printf("\n"); // 보드 출력
								flag1 = 0; // 재입력x n증가
							}
							else { //흑돌 입력
								board[com_y][2 * (com_x)] = 'X';
								turn_stone(com_x, com_y);
								for (i = 0; i < 9; i++) {
									printf("%s\n", board[i]);
								}
								printf("\n"); //보드 출력 
								flag1 = 0; // 재입력x n증가
							}
							point_clear();
							com_x = 0; com_y = 0;
							break;
						}
					}
				}
			}
			if (flag1 == 0) {
				n++;
				point_clear();
				flag3 = 0;
				exit = 0;
				swap(stone_color);
				change(start);
			}
		}
		else { //둘다 놓을 곳 없으면 게임끝
			if (exit) { end(); break; }
			else {
				printf("둘 곳이 없습니다.\n");
				exit = 1;
				swap(stone_color);
				change(start);
			}
		}
	}
	if (exit==0) { end(); }
	system("pause");
}

int cnt_black() //흑돌세기
{
	int i, j, black=0;
	for (i = 1; i < 9; i++) {
		for (j = 2; j < 18; j += 2) {
			if (board[i][j] == 'X') black++;
		}
	}
	return black;
}

int cnt_white() //백돌세기
{
	int i, j, white = 0;
	for (i = 1; i < 9; i++) {
		for (j = 2; j < 18; j += 2) {
			if (board[i][j] == 'O') white++;
		}
	}
	return white;
}

void put_stone(int x, int y) 
{
		int i;
		if (board[y][2 * x] != '.') {
			printf("둘 수 없는 위치입니다. 다시 입력하세요.\n\n");
			flag1 = 1; //재입력 n 유지
		}
		else {
			if (check_stone(x,y)) {
				if (stone_color) { //백돌 입력
					board[y][2 * x] = 'O';
					turn_stone(x, y);
					for (i = 0; i < 9; i++) {
						printf("%s\n", board[i]);
					}
					printf("\n"); // 보드 출력
					flag1 = 0; // 재입력x n증가
				}
				else { //흑돌 입력
					board[y][2 * x] = 'X';
					turn_stone(x, y);
					for (i = 0; i < 9; i++) {
						printf("%s\n", board[i]);
					}
					printf("\n"); //보드 출력 
					flag1 = 0; // 재입력x n증가
				}
			}
			else {
				printf("둘 수 없는 위치입니다. 다시 입력하세요.\n\n");
				flag1 = 1; //재입력 n 유지
			}
		}
}

int check_stone(int x, int y) //돌이 인접한지 확인
{ 
	int i, flag2 = 0, flag2_1=0; //놓을수 있는 위치인지 확인
	if (stone_color) {
		if (board[y][2 * (x + 1)] == 'X') {
			for (i = x + 2; i < 9; i++) {
				if (board[y][2 * i] == 'O') { check_pointR = i; break; }
			}
			for (i = x + 1; i < check_pointR; i++) {
				if (board[y][2 * i] == 'X') { flag2 = 1; }
				else { flag2 = 0; break; }
			}
			flag2_1 += flag2;
			if (flag2 == 0) check_pointR = 0;
			flag2 = 0;
		} //오른쪽
		if (board[y][2 * (x - 1)] == 'X') {
			for (i = x - 2; i > 0; i--) {
				if (board[y][2 * i] == 'O') { check_pointL = i; break; }
			}
			if (check_pointL != 0) {
				for (i = x - 1; i > check_pointL; i--) {
					if (board[y][2 * i] == 'X') { flag2 = 1; }
					else { flag2 = 0; break; }
				}
			}
			flag2_1 += flag2;
			if (flag2 == 0) check_pointL = 0;
			flag2 = 0;
		} //왼쪽
		if (board[y + 1][2 * x] == 'X') {
			for (i = y + 2; i < 9; i++) {
				if (board[i][2 * x] == 'O') { check_pointD = i; break; }
			}
			for (i = y + 1; i < check_pointD; i++) {
				if (board[i][2 * x] == 'X') { flag2 = 1; }
				else { flag2 = 0; break; }
			}
			flag2_1 += flag2;
			if (flag2 == 0) check_pointD = 0;
			flag2 = 0;
		} //아래
		if (board[y - 1][2 * x] == 'X') {
			for (i = y - 2; i > 0; i--) {
				if (board[i][2 * x] == 'O') { check_pointU = i; break; }
			}
			if (check_pointU != 0) {
				for (i = y - 1; i > check_pointU; i--) {
					if (board[i][2 * x] == 'X') { flag2 = 1; }
					else { flag2 = 0; break; }
				}
			}
			flag2_1 += flag2;
			if (flag2 == 0) check_pointU = 0;
			flag2 = 0;
		} //위
		if (board[y + 1][2 * (x + 1)] == 'X') {
			int j = y + 2, k = x + 2;
			while (j<9 && k<9) {
				if (board[j][2 * k] == 'O') { check_pointRDy = j; check_pointRDx = k; break; }
				j++; k++;
			}
			int l = y + 1, m = x + 1;
			while (l < check_pointRDy && m < check_pointRDx) {
				if (board[l][2 * m] == 'X') { flag2 = 1; }
				else { flag2 = 0; break; }
				l++; m++;
			}
			flag2_1 += flag2;
			if (flag2 == 0) {
				check_pointRDx = 0; check_pointRDy = 0;
			}
			flag2 = 0;
		} //오른쪽 아래
		if (board[y + 1][2 * (x - 1)] == 'X') {
			int j = y + 2, k = x - 2;
			while (j<9 && k>0) {
				if (board[j][2 * k] == 'O') { check_pointLDy = j; check_pointLDx = k; break; }
				j++; k--;
			}
			if (check_pointLDx != 0) {
				int l = y + 1, m = x - 1;
				while (l < check_pointLDy && m > check_pointLDx) {
					if (board[l][2 * m] == 'X') { flag2 = 1; }
					else { flag2 = 0; break; }
					l++; m--;
				}
			}
			flag2_1 += flag2;
			if (flag2 == 0) {
				check_pointLDx = 0; check_pointLDy = 0;
			}
			flag2 = 0;
		} //왼쪽 아래
		if (board[y - 1][2 * (x + 1)] == 'X') {
			int j = y - 2, k = x + 2;
			while (j>0 && k<9) {
				if (board[j][2 * k] == 'O') { check_pointRUy = j; check_pointRUx = k; break; }
				j--; k++;
			}
			if (check_pointRUy != 0) {
				int l = y - 1, m = x + 1;
				while (l > check_pointRUy && m < check_pointRUx) {
					if (board[l][2 * m] == 'X') { flag2 = 1; }
					else { flag2 = 0; break; }
					l--; m++;
				}
			}
			flag2_1 += flag2;
			if (flag2 == 0) {
				check_pointRUx = 0; check_pointRUy = 0;
			}
			flag2 = 0;
		} //오른쪽 위
		if (board[y - 1][2 * (x - 1)] == 'X') {
			int j = y - 2, k = x - 2;
			while (j>0 && k>0) {
				if (board[j][2 * k] == 'O') { check_pointLUy = j; check_pointLUx = k; break; }
				j--; k--;
			}
			if (check_pointLUy != 0 && check_pointLUx != 0) {
				int l = y - 1, m = x - 1;
				while (l > check_pointLUy && m > check_pointLUx) {
					if (board[l][2 * m] == 'X') { flag2 = 1; }
					else { flag2 = 0; break; }
					l--; m--;
				}
			}
			flag2_1 += flag2;
			if (flag2 == 0) {
				check_pointLUx = 0; check_pointLUy = 0;
			}
			flag2 = 0;
		} //왼쪽 위
	}
	else {
		if (board[y][2 * (x + 1)] == 'O') {
			for (i = x + 2; i < 9; i++) {
				if (board[y][2 * i] == 'X') { check_pointR = i; break; }
			}
			for (i = x + 1; i < check_pointR; i++) {
				if (board[y][2 * i] == 'O') { flag2 = 1; }
				else { flag2 = 0; break; }
			}
			flag2_1 += flag2;
			if (flag2 == 0) check_pointR = 0;
			flag2 = 0;
		} //오른쪽
		if (board[y][2 * (x - 1)] == 'O') {
			for (i = x - 2; i > 0; i--) {
				if (board[y][2 * i] == 'X') { check_pointL = i; break; }
			}
			if (check_pointL != 0) {
				for (i = x - 1; i > check_pointL; i--) {
					if (board[y][2 * i] == 'O') { flag2 = 1; }
					else { flag2 = 0; break; }
				}
			}
			flag2_1 += flag2;
			if (flag2 == 0) check_pointL = 0;
			flag2 = 0;
		} //왼쪽
		if (board[y + 1][2 * x] == 'O') {
			for (i = y + 2; i < 9; i++) {
				if (board[i][2 * x] == 'X') { check_pointD = i; break; }
			}
			for (i = y + 1; i < check_pointD; i++) {
				if (board[i][2 * x] == 'O') { flag2 = 1; }
				else { flag2 = 0; break; }
			}
			flag2_1 += flag2;
			if (flag2 == 0) check_pointD = 0;
			flag2 = 0;
		} //아래
		if (board[y - 1][2 * x] == 'O') {
			for (i = y - 2; i > 0; i--) {
				if (board[i][2 * x] == 'X') { check_pointU = i; break; }
			}
			if (check_pointU != 0) {
				for (i = y - 1; i > check_pointU; i--) {
					if (board[i][2 * x] == 'O') { flag2 = 1; }
					else { flag2 = 0; break; }
				}
			}
			flag2_1 += flag2;
			if (flag2 == 0) check_pointU = 0;
			flag2 = 0;
		} //위
		if (board[y + 1][2 * (x + 1)] == 'O') {
			int j = y + 2, k = x + 2;
			while (j<9 && k<9) {
				if (board[j][2 * k] == 'X') { check_pointRDy = j; check_pointRDx = k; break; }
				j++; k++;
			}
			int l = y + 1, m = x + 1;
			while (l < check_pointRDy && m < check_pointRDx) {
				if (board[l][2 * m] == 'O') { flag2 = 1; }
				else { flag2 = 0; break; }
				l++; m++;
			}
			flag2_1 += flag2;
			if (flag2 == 0) {
				check_pointRDx = 0; check_pointRDy = 0;
			}
			flag2 = 0;
		} //오른쪽 아래
		if (board[y + 1][2 * (x - 1)] == 'O') {
			int j = y + 2, k = x - 2;
			while (j<9 && k>0) {
				if (board[j][2 * k] == 'X') { check_pointLDy = j; check_pointLDx = k; break; }
				j++; k--;
			}
			if (check_pointLDx != 0) {
				int l = y + 1, m = x - 1;
				while (l < check_pointLDy && m > check_pointLDx) {
					if (board[l][2 * m] == 'O') { flag2 = 1; }
					else { flag2 = 0; break; }
					l++; m--;
				}
			}
			flag2_1 += flag2;
			if (flag2 == 0) {
				check_pointLDx = 0; check_pointLDy = 0;
			}
			flag2 = 0;
		} //왼쪽 아래
		if (board[y - 1][2 * (x + 1)] == 'O') {
			int j = y - 2, k = x + 2;
			while (j>0 && k<9) {
				if (board[j][2 * k] == 'X') { check_pointRUy = j; check_pointRUx = k; break; }
				j--; k++;
			}
			if (check_pointRUy != 0) {
				int l = y - 1, m = x + 1;
				while (l > check_pointRUy && m < check_pointRUx) {
					if (board[l][2 * m] == 'O') { flag2 = 1; }
					else { flag2 = 0; break; }
					l--; m++;
				}
			}
			flag2_1 += flag2;
			if (flag2 == 0) {
				check_pointRUx = 0; check_pointRUy = 0;
			}
			flag2 = 0;
		} //오른쪽 위
		if (board[y - 1][2 * (x - 1)] == 'O') {
			int j = y - 2, k = x - 2;
			while (j>0 && k>0) {
				if (board[j][2 * k] == 'X') { check_pointLUy = j; check_pointLUx = k; break; }
				j--; k--;
			}
			if (check_pointLUy != 0 && check_pointLUx != 0) {
				int l = y - 1, m = x - 1;
				while (l > check_pointLUy && m > check_pointLUx) {
					if (board[l][2 * m] == 'O') { flag2 = 1; }
					else { flag2 = 0; break; }
					l--; m--;
				}
			}
			flag2_1 += flag2;
			if (flag2 == 0) {
				check_pointLUx = 0; check_pointLUy = 0;
			}
			flag2 = 0;
		} //왼쪽 위
	}
	return flag2_1;
}

void turn_stone(int x, int y) 
{
	int i;
	if (stone_color) { //백돌로 뒤집기
		if (check_pointR != 0) {
			for (i = x + 1; i < check_pointR; i++) {
				board[y][2 * i] = 'O';
			}
		} //오른쪽
		if (check_pointL != 0) {
			for (i = x - 1; i > check_pointL; i--) {
				board[y][2 * i] = 'O';
			}
		} //왼쪽
		if (check_pointD != 0) {
			for (i = y + 1; i < check_pointD; i++) {
				board[i][2 * x] = 'O';
			}
		} //아래
		if (check_pointU != 0) {
			for (i = y - 1; i > check_pointU; i--) {
				board[i][2 * x] = 'O';
			}
		} //위
		if (check_pointRDx != 0) {
			int j = y + 1, k = x + 1;
			while (j < check_pointRDy && k < check_pointRDx) {
				board[j][2 * k] = 'O';
				j++; k++;
			}
		} //오른쪽 아래
		if (check_pointLDx != 0) {
			int j = y + 1, k = x - 1;
			while (j < check_pointLDy && k > check_pointLDx) {
				board[j][2 * k] = 'O';
				j++; k--;
			}
		} //왼쪽 아래
		if (check_pointRUx != 0) {
			int j = y - 1, k = x + 1;
			while (j > check_pointRUy && k < check_pointRUx) {
				board[j][2 * k] = 'O';
				j--; k++;
			}
		} //오른쪽 위
		if (check_pointLUx != 0) {
			int j = y - 1, k = x - 1;
			while (j > check_pointLUy && k > check_pointLUx) {
				board[j][2 * k] = 'O';
				j--; k--;
			}
		} //왼쪽 위
	}
	else { //흑돌로 뒤집기
		if (check_pointR != 0) {
			for (i = x + 1; i < check_pointR; i++) {
				board[y][2 * i] = 'X';
			}
		} //오른쪽
		if (check_pointL != 0) {
			for (i = x - 1; i > check_pointL; i--) {
				board[y][2 * i] = 'X';
			}
		} //왼쪽
		if (check_pointD != 0) {
			for (i = y + 1; i < check_pointD; i++) {
				board[i][2 * x] = 'X';
			}
		} //아래
		if (check_pointU != 0) {
			for (i = y - 1; i > check_pointU; i--) {
				board[i][2 * x] = 'X';
			}
		} //위
		if (check_pointRDx != 0) {
			int j = y + 1, k = x + 1;
			while (j < check_pointRDy && k < check_pointRDx) {
				board[j][2 * k] = 'X';
				j++; k++;
			}
		} //오른쪽 아래
		if (check_pointLDx != 0) {
			int j = y + 1, k = x - 1;
			while (j < check_pointLDy && k > check_pointLDx) {
				board[j][2 * k] = 'X';
				j++; k--;
			}
		} //왼쪽 아래
		if (check_pointRUx != 0) {
			int j = y - 1, k = x + 1;
			while (j > check_pointRUy && k < check_pointRUx) {
				board[j][2 * k] = 'X';
				j--; k++;
			}
		} //오른쪽 위
		if (check_pointLUx != 0) {
			int j = y - 1, k = x - 1;
			while (j > check_pointLUy && k > check_pointLUx) {
				board[j][2 * k] = 'X';
				j--; k--;
			}
		} //왼쪽 위
	}
}

void swap(int a) 
{
	if (a == 0) stone_color = 1;
	else stone_color = 0;
}

void end()
{
	int b, w;
	printf("게임을 종료합니다.\n");
	b = cnt_black();
	w = cnt_white();
	printf("흑돌:%d 백돌:%d\n", b, w);
	if (b == w) printf("무승부입니다.\n");
	else {
		if (b > w) printf("흑이 승리하였습니다.\n");
		if (b < w) printf("백이 승리하였습니다.\n");
	} //승리 표시
}

void point_clear() 
{
	check_pointR = 0;
	check_pointL = 0;
	check_pointU = 0;
	check_pointD = 0;
	check_pointRUx = 0;
	check_pointRUy = 0;
	check_pointLUx = 0;
	check_pointLUy = 0;
	check_pointRDx = 0;
	check_pointRDy = 0;
	check_pointLDx = 0;
	check_pointLDy = 0;
}

void change(int a) 
{
	if (a == 0) start= 1;
	else start= 0;
}