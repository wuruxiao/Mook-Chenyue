#include<stdio.h>

int main(){

    //the num of figures
    int K;

    int max = 0;
    
    //read the K
    scanf("%d", &K);

    if(K){
        //write in the figures
        int figure;
        int sum = 0;
        for(int i = 0; i < K; i++){
            scanf("%d", &figure);

            sum += figure;

            //keep the max is max
            max = (sum > max) ? sum : max;

            //if sum is negtive, reset the sum
            sum = (sum < 0) ? 0 : sum;
        }

        //ourput
        printf("%d", max);
    }
    return 0;
}