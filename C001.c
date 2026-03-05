#include <stdio.h>

int main() {
    /*
    V자 찍기

    1 10(시작점이 1(1+0), 끝점이 size*2)
    2 9(시작점이 2(1+1), 끝점이 size*2-1)
    3 8(시작점이 3(1+2), 끝점이 size*2-2)
    4 7(시작점이 4(1+3), 끝점이 size*2-3)
    5 6(시작점이 5(1+4), 끝점이 size*2-4)

    기본은 공백을 찍는 것, 별을 찍을때는 
    */
    int size;
    scanf("%d", &size);

    // 맨 위 브이자
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size * 2; j++) {
            if (j == i || j == size * 2 - 1 - i) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    
    // 몸통
    for(int i=0; i<size; i++){
        for(int j=0; j<size*2; j++){
            printf("*");
        }
        printf("\n");
    }

    // 브이 몸통?
    /*
    점점 범위를 좁혀가는 것
    */
    for(int i=0; i<size; i++){
        for(int j=0; j<size*2; j++){
            if(j<i || j>size*2-1-i){
                printf(" ");
            }
            else 
                printf("*");
        }
        printf("\n");
    }
    // 마지막 바닥
    for(int i=0; i<size*2; i++)
        printf("*");
    printf("\n");
    return 0;
}