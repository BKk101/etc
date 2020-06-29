#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct KMost {
	char words[52];
	int times;
}KMost;

typedef struct KMost_list { //연관도 계산할때 사용
	KMost words_frequent[20]; 
}KMost_list;

void read_num(FILE* ifp, int* num);
double words_cmp(KMost_list, KMost_list, int);

int main() {
	FILE *ifp_DocList, *ofp_Words, *ofp_KMost, *ifp_file;
	ifp_DocList = fopen("DocList.txt", "r");
	if (ifp_DocList == NULL) {
		printf("입력파일이 개방되지 않았습니다.\n");
		return -1;
	}
	ofp_Words = fopen("Words.txt", "w");
	if (ofp_Words == NULL) {
		printf("출력파일이 개방되지 않았습니다.\n");
		return -1;
	}
	ofp_KMost = fopen("KMost.txt", "w");
	if (ofp_KMost == NULL) {
		printf("출력파일이 개방되지 않았습니다.\n");
		return -1;
	}
	int num_info[2] = { 0 }, i;
	read_num(ifp_DocList, num_info); //숫자 저장
	 //제목 읽어서 title_list에 저장
	
	char title[22] = { 0 };
	char title_list[100][22] = { 0 }; //문서갯수 최대값
	for (i = 0; i < num_info[0]; i++) {
		fgets(title, sizeof(title), ifp_DocList);
		if (title[strlen(title) - 1] == '\n') title[strlen(title) - 1] = '\0';//개행문자 제거
		strcpy(title_list[i], title);
		memset(title, 0, 30);
	}

	char buffer[52] = { 0 }, ch; //임시변수 
	int space=0;
	i = 0;
	while (i < num_info[0]) 
	{
		sprintf(buffer, "%s", title_list[i]); // 문서리스트에 있는 파일 열기
		ifp_file = fopen(buffer, "r");
		if (ifp_file == NULL) {
			printf("입력파일이 개방되지 않았습니다.\n");
			return -1;
		}
		memset(buffer, 0, sizeof(buffer));

		sprintf(buffer, "%c%s%c", '<', title_list[i], '>'); //제목입력
		fputs(buffer, ofp_Words);
		fputc('\n', ofp_Words);
		memset(buffer, 0, sizeof(buffer));
		
		do { //내용 입력
			ch = fgetc(ifp_file);
			if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z') {
				if (space) fputc('\n', ofp_Words); 
				if (ch >= 'a' && ch <= 'z') fputc(ch - 32, ofp_Words);
				else fputc(ch, ofp_Words);
				space = 0;
			}
			else space = 1;
		} while (ch != EOF);
		fclose(ifp_file); //파일 닫기
		memset(buffer, 0, sizeof(buffer));
		fprintf(ofp_Words, "\n");
		i++; space = 0;
		if (i < num_info[0]) fprintf(ofp_Words, "\n");
	}
	fclose(ifp_DocList); 
	fclose(ofp_Words);

	//출력2 시작
	ofp_Words = fopen("Words.txt", "r");
	KMost_list kmost_list[100] = { 0 };
	KMost words_list[1000] = { 0 };//문서 하나당 한개
	int k=0, words_num; //단어갯수 저장
	while(k<num_info[0])  //타이틀 수만큼 반복
	{
		words_num = 0; i = 0;
		do { // 단어를 words_list에 저장
			fgets(buffer, sizeof(buffer), ofp_Words);
			if (strchr(buffer, '<') != '\0') fputs(buffer, ofp_KMost); //제목이면 KMost에 출력
			else if (strcmp(buffer, "\n") == 0 || strcmp(buffer, "\0") == 0) { memset(buffer, 0, sizeof(buffer)); break; }
			else {
				if (buffer[strlen(buffer) - 1] == '\n') { buffer[strlen(buffer) - 1] = '\0'; }
				strcpy(words_list[i].words, buffer);
				words_num++;
				i++;
			}
			memset(buffer, 0, sizeof(buffer));
		} while (1);

		int cmp, j = 0; i = 0; // 빈도수 세기
		while (i < words_num)
		{
			while (j < words_num)
			{
				cmp = strcmp(words_list[i].words, words_list[j].words);
				if (cmp == 0) words_list[i].times++;
				j++;
			}
			j = 0;
			i++;
		}
	
		int flag1, max, i_num, l=0; //최빈값 찾고 words_frequent에 저장
		while (l < num_info[1]) {
			if (l > words_num) break;
			max = 0;
			for (i = 0; i < words_num; i++) {
				if (words_list[i].times >= max) {
					max = words_list[i].times;
					i_num = i;
				}
			}
			j = 0; flag1 = 0;
			while (strcmp(kmost_list[k].words_frequent[j].words,"\0")!=0) {
				cmp = strcmp(words_list[i_num].words, kmost_list[k].words_frequent[j].words);
				if (cmp == 0) { flag1 = 1; break; }
				else j++;		
			}
			if (flag1 == 0) { 
				kmost_list[k].words_frequent[j] = words_list[i_num];
				l++; 
			}
			memset(&words_list[i_num], 0, sizeof(words_list[i_num]));
		}

		for (i = 0; i < num_info[1]; i++) {  //words_frequent 출력
			if (i > words_num) break;
			fprintf(ofp_KMost, "%s\t%d\n", kmost_list[k].words_frequent[i].words, kmost_list[k].words_frequent[i].times);
		}
		memset(words_list, 0, sizeof(words_list));
		k++;
		if (k < num_info[0]) fprintf(ofp_KMost, "\n");
	}
	//파일 닫기
	fclose(ofp_Words);
	fclose(ofp_KMost);

	//출력3 시작
	int j = 1; i = 0;
	double accord;
	while (strcmp(title_list[i],"\0") != 0) {
		while (strcmp(title_list[j], "\0") != 0) {
			accord = words_cmp(kmost_list[i], kmost_list[j], num_info[1]);
			printf("%s\t%s\t%.2lf\n", title_list[i], title_list[j], accord / num_info[1]);
			j++;
		}
		i++;
		j = i + 1;
	}
	system("pause");
	return 0;
}

void read_num(FILE* ifp, int* num) 
{
	char check_end;
	fscanf(ifp, "%d %d", &num[0], &num[1]);
	while (1) {
		check_end = fgetc(ifp);
		if (check_end == '\n') break;
	}
}

double words_cmp(KMost_list A, KMost_list B, int num) 
{
	int i = 0, j = 0;
	double accord = 0;
	while (i<num) {
		while (j<num) {
			if (A.words_frequent[i].words[0] == '\0' && B.words_frequent[i].words[0] == '\0') break;
			else if (strcmp(A.words_frequent[i].words, B.words_frequent[j].words) == 0) accord++;
			j++;
		}
		i++; j = 0;
	}
	return accord;
}