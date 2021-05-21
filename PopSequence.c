#include <stdio.h>
#define MAX_SIZE 1001

typedef struct stack *STACK;
struct stack
{
    int data[MAX_SIZE];
    int top;
    int pushtimes;
    int maxSize;
};

int pushStack(STACK a, int m);
int popStack(STACK a);
int judgeGroup(int data[], int N, int M);

int main(){
    //Read
    int M;                  //max size of stack
    scanf("%d", &M);
    int N;                  //has N numbers need to be pushed
    scanf("%d", &N);
    int K;                  //has K lines
    scanf("%d", &K);
    int data[MAX_SIZE];
    int printGroup[MAX_SIZE];
    int printFlag = 0;
    //read the lines
    for(int i = 0; i < K; i++){
        for(int j = 0; j < N; j++){
            scanf("%d", &data[j]);
        }

        //data has a line
        int judge = judgeGroup(data, N, M);
        printGroup[i] = judge;
    }

    for(int i = 0; i < K; i++){
        if(printFlag)
            printf("\n");

        if(printGroup[i]){
            printf("YES");
            printFlag = 1;
        }else{
            printf("NO");
            printFlag = 1;
        }
    }
    return 0;
}

int judgeGroup(int data[], int N, int M){
    STACK a;
    a->maxSize = M;
    a->pushtimes = 0;
    a->top = -1;

    for(int i = 0; i < N; i++){
        //Stack is overflow
        if(data[i] > (M + i)){
            return 0;
        }

        //Push data
        while(a->pushtimes < data[i]){
            int pushflag = pushStack(a, a->pushtimes + 1);
            if(!pushflag)
                return 0;
            
        }

        //Pop data
        int item = popStack(a);
        if(item != data[i])
            return 0;
    }
}

int pushStack(STACK a, int m){
    //Is full
    if(a->top == a->maxSize-1)
        return 0;
    
    a->data[a->top + 1] = m;
    a->top++;
    a->pushtimes++;
    return 1;
}

int popStack(STACK a){
    //Is empty
    if(a->top == -1)
        return 0;

    a->top--;
    return a->data[a->top + 1];
}