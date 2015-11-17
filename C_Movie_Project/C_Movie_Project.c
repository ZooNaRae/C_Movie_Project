#define _CRT_SECURE_NO_WARNING//2012���̻�

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Printmenu();
void Insert();
void Screen(int screen, int time);
void Information(char username[6]);
void Delete(char deletename[6]);

char movie_name[5][20] = {{"�ظ�����"},{"���ͽ��ڶ�"},{"���� ã����"},{"�õ庸��"},{"��Ű���"}};
char timetable[5][10] = {{"9:00"}, {"12:00"}, {"15:00"}, {"18:00"}, {"21:00"}};

typedef struct _user {
	char name[6];
	int moviename;
	int movietime;
	int num;
	int seton;
}user;

typedef struct _time {
	struct _user book[8][8];
}time;

typedef struct _movie {
	struct _time movietime[5];
}movie;

movie movie_s[5];

void main() {
	int menu, i, j, a, time;
	char username[6];
	char deletename[6];

	while(1) {
		system("cls");
		Printmenu();
		scanf("%d" ,&menu);
		if(menu == 1 || menu ==2 || menu ==3 || menu == 4) {
			switch(menu) {
			case 1:
				Insert();
				break;
			case 2:
				printf("���� ����Һ��� ������ �˷��ּ���\n");
				scanf("%s", &deletename);
				Delete(deletename);
				break;
			case 3:
				printf("�������� ������ �˷��ּ���\n");
				scanf("%s", &username);
				Information(username);
				break;
			case 4:
				exit(1);
				break;
			}
		} else {
			printf("1~4 ������ ���ڸ� �Է����ּ���\n");
		}
		
		getchar();
		getchar();
	}
}

void Printmenu() {
	printf("=========================\n");
	printf("1. �¼� ����\n");
	printf("2. ���� ���\n");
	printf("3. ���� ���� ���\n");
	printf("4. ����\n");
	printf("==========================\n");
	printf("�޴��� ���� �ϼ��� : \n");	
}

void Insert() {
	int i, j, time;
	int row, num;
	for(i = 0; i < 5; i++) {
		printf("%d %s\n",i + 1, movie_name[i]);
	}
	printf("��ȭ�� �����ϼ���\n");
	scanf("%d", &j);
	for(i = 0; i < 5; i++) {
		printf("%d %s\n",i + 1, timetable[i]);
	}
	printf("��ȭ �ð��� �����ϼ���\n");
	scanf("%d", &time);
	Screen(j-1, time-1);
	printf("�¼��� �����ϼ��� : �� ��\n");
	scanf("%d %d", &row, &num);
	movie_s[j-1].movietime[time-1].book[row-1][num-1].seton = 1;
	printf("������ ������ �Է��ϼ���\n");
	scanf("%s", &movie_s[j-1].movietime[time-1].book[row-1][num-1].name);
	movie_s[j-1].movietime[time-1].book[row-1][num-1].moviename = (j - 1);
	movie_s[j-1].movietime[time-1].book[row-1][num-1].movietime = (time - 1);
	movie_s[j-1].movietime[time-1].book[row-1][num-1].num = 1;//�� ��ġ���� ������ ����� �ִٰ� ǥ��
	printf("���� �Ϸ�\n");
}

void Screen(int screen, int time){
	int i, j;
	char k[7]={'1','2','3','4','5','6','7'};
	printf("======screen=======\n");
	printf(" 1 2 3 4 5 6 7 8 \n");
	for(i = 0; i < 7; i++) {
		printf("%c",k[i]);
		for(j = 0; j < 8; j++) {
			if(movie_s[screen].movietime[time].book[i][j].seton == 0) {
				printf("��"); 
			}
			else if(movie_s[screen].movietime[time].book[i][j].seton == 2) {
				printf("��");
				movie_s[screen].movietime[time].book[i][j].seton = 1;
			}
			else{
				printf("��");
			}
		}
		printf("\n");
	}
	getchar();
}

void Information(char *username) {
	int i, j, result, a, time;
	int t = 1;//������ ��ܿ� ���ٰ� ����
	for(a = 0; a < 5; a++) {
		for(time = 0; time < 5; time++) {
			for(i = 0; i < 8; i++) {
				for(j = 0; j < 8; j++) {
					result = strcmp(movie_s[a].movietime[time].book[i][j].name, username);
					if(result == 0 && movie_s[a].movietime[time].book[i][j].num == 1) {
						movie_s[a].movietime[time].book[i][j].seton = 2;//���� �ڸ��� ��ĥ�� ���� ǥ���ϰ� ��
						Screen(a, time);
						printf("%s���� �����Ͻ� %s�� %s ��ȭ �Դϴ�.\n",movie_s[a].movietime[time].book[i][j].name, movie_name[movie_s[a].movietime[time].book[i][j].moviename], timetable[movie_s[a].movietime[time].book[i][j].moviename]);
						printf("%s���� ���� �¼��� %d�� %d�� �Դϴ�.\n", movie_s[a].movietime[time].book[i][j].name, i + 1, j + 1);
						t = 0;
					}
				}
			}
	   }
	}
	if(t == 1) {
		printf("������ ������ �����ϴ�.\n");
	}
}

void Delete(char *deletename) {
	int i, j, result, a, time;
	int t = 1;//������ ��ܿ� ���ٰ� ����
	for(a = 0; a < 5; a++) {
		for(time = 0; time < 5; time++) {
			for(i = 0; i < 8; i++) {
				for(j = 0; j < 8; j++) {
					result = strcmp(movie_s[a].movietime[time].book[i][j].name, deletename);
					if(result == 0 && movie_s[a].movietime[time].book[i][j].num == 1) {
						movie_s[a].movietime[time].book[i][j].seton = 0;
						movie_s[a].movietime[time].book[i][j].num = 0;//������ ������ ���ٰ� ǥ��
						printf("%s���� ������ ��ҵǾ����ϴ�.\n", movie_s[a].movietime[time].book[i][j].name);
						t = 0;//�����ڰ� �־� ���� ��Ұ� �Ȱ��̹Ƿ� �ִٰ� ǥ��(t = 0)
					}
					else {}
				}
			}
		}
	}
	if(t == 1) {
		printf("������ ��ܿ� �����ϴ�.\n");
	}
}
