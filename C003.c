#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int findRoom(int persons[5]);
void printReport(char mn[10][20], int mr[10], int mc, char wn[10][20], int wr[10], int wc);

int main(){
    int menu;
    int w_people[5]={0};
    int m_people[5]={0};
    char mn[10][20];
    int mr[10];
    int mc=0;
    char wn[10][20];
    int wr[10];
    int wc=0;

    srand((unsigned)time(NULL));

    printf("===========================================\n");
    printf("생활관 호실 배정 프로그램\n");
    printf("===========================================\n");

    while(1){
        printf("메뉴 : 1. 남학생 등록 2. 여학생 등록 0. 종료 > ");
        scanf("%d", &menu);

        if(menu==1){
            int isfull=1;
            for(int i=0; i<5; i++){
                if(m_people[i]<2){
                    isfull=0;
                    break;
                }
            }
            if(isfull){
                printf("남은 방이 없음\n");
                continue;
            }
            printf("학생 이름은? > ");
            scanf("%s", mn[mc]);
            int room=findRoom(m_people);
            if(room==0){ printf("남은 방이 없음\n"); continue; }
            mr[mc]=100+room;
            m_people[room-1]++;
            mc++;
            printf("%s 학생 %d호실 배정되었습니다.\n", mn[mc-1], mr[mc-1]);
        }
        else if(menu==2){
            int isfull=1;
            for(int i=0; i<5; i++){
                if(w_people[i]<2){
                    isfull=0;
                    break;
                }
            }
            if(isfull){
                printf("남은 방이 없음\n");
                continue;
            }
            printf("학생 이름은? > ");
            scanf("%s", wn[wc]);
            int room=findRoom(w_people);
            if(room==0){ printf("남은 방이 없음\n"); continue; }
            wr[wc]=200+room;
            w_people[room-1]++;
            wc++;
            printf("%s 학생 %d호실 배정되었습니다.\n", wn[wc-1], wr[wc-1]);
        }
        else if(menu==0){
            printReport(mn, mr, mc, wn, wr, wc);
            break;
        }
    }
    return 0;
}

int findRoom(int persons[5]){
    int i, r;
    for(i=0; i<5; i++){
        if(persons[i]<2) {
            break;
        }
    }
    if(i==5) return 0;
    r=rand()%5;
    while(persons[r]>=2){
        r=rand()%5;
    }
    return r+1;
}

void printReport(char mn[10][20], int mr[10], int mc, char wn[10][20], int wr[10], int wc){
    printf("===========================================\n");
    printf("생활관 호실 배정 결과는 다음과 같습니다.\n");
    printf("===========================================\n");

    printf("남학생 명단 (%d명)\n", mc);
    for(int i=0; i<mc; i++){
        printf("%d. %s [%d호]\n", i+1, mn[i], mr[i]);
    }

    printf("\n여학생 명단 (%d명)\n", wc);
    for(int i=0; i<wc; i++){
        printf("%d. %s [%d호]\n", i+1, wn[i], wr[i]);
    }

    printf("\n호실별 배정 명단\n");
    for(int r=101; r<=105; r++){
        printf("%d호: ", r);
        for(int i=0; i<mc; i++){
            if(mr[i]==r)
                printf("%s ", mn[i]);
        }
        printf("\n");
    }
    for(int r=201; r<=205; r++){
        printf("%d호: ", r);
        for(int i=0; i<wc; i++){
            if(wr[i]==r)
                printf("%s ", wn[i]);
        }
        printf("\n");
    }
}