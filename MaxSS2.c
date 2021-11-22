/*
这里比之前的最大子序列之和所多出来的地方就是需要提取出最大子序列的头和尾
这里用到了一个特别巧妙的参数，其实际功能是记录可能会出现的新的子序列的和的头，我管它叫 'magic'
这么说吧，如果 head 参数是记录目前存在的最大子序列的头，那么 magic 参数就是要记录下一个头，含有这个头的子序列一旦比之前的子序列还要打，那么此时就将 magic 的值赋予 head
至于说 tail 的值，就随着每次 max 的变动，一旦变动，此时加上去的数，就是 tail
*/
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
