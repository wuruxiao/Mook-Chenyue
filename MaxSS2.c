#include <stdio.h>
#define MAXSIZE 10000

int main(){

    //the number of the figures
    int K;

    int figures[MAXSIZE];

    scanf("%d", &K);

    if(K){

        int sum = 0;
        int max = -1;
        int head = 0;
        int tail = 0;
        int magic = 0;

        for(int i = 0; i < K; i++){
            scanf("%d", &figures[i]);

            sum += figures[i];

            if (max < sum)
            {
                /* new subquence */
                max = sum;
                tail = i;
                head = magic;
            }

            if (sum < 0)
            {
                sum = 0;
                magic = i + 1;
            }
            
        }

        if(max < 0){
            printf("0 %d %d", figures[0], figures[magic - 1]);
        }else{
            printf("%d %d %d", max, figures[head], figures[tail]);
        }
    }
    return 0;
}
