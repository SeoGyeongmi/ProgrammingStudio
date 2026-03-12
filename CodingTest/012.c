/*
신장(cm 단위)과 체중(kg 단위)를 입력받은 후, 비만 여부를 판정하여 출력하라.

단, 비만여부는 다음 비만도 수치가 25이상인 경우에 "비만"으로 판단한다.

비만도 수치 = 체중(kg) / (신장(m)의 제곱) 으로 계산한다.

이 때, 신장은 미터 단위로 환산해야 함을 유의하라.

변수는 다음과 같이 사용하라.

int height, weight; 		// 신장(cm), 체중(kg)
float bmi; 				// 비만도 수치 
*/
#include <stdio.h>

int main(){
    int height, weight; 
    float bmi; 	

    scanf("%d %d", &height, &weight);

    bmi = weight / (height*0.01*height*0.01);

    if(bmi>25) printf("Yes\n");
    else printf("No\n");
    // printf("%.1f\n", bmi);
    return 0;
}