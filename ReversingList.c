#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100001

typedef struct node *data;
struct node
{
    int head;
    int num;
    int tail;
};

void readData(data List[], int N);
int sequenGroup(data List[], int N, int head);
void reverseGroup(data List[], int N, int k);
void printGroup(data List[], int N);
void switchNode(data List[], int i, int j);

int main()
{
    data List[MAX_SIZE];
    int head = 0;
    scanf("%d", &head);
    int N = 0;
    scanf("%d", &N);
    int k = 0;
    scanf("%d", &k);
    int newN = N;

    //read the data
   if (N)
    {
        /* when N >0 read the data */
        readData(List, N);

        /* make the node in the group sequential */
        newN = sequenGroup(List, N, head);

        /* reverse the group */
        reverseGroup(List, newN, k);

    }
    printGroup(List, newN);

    return 0;
}

void readData(data List[], int N){

    //make N nodes
    for(int i = 1; i <= N; i++){
        data node_ = (data)malloc(sizeof(struct node));
        scanf("%d", &node_->head);
        scanf("%d", &node_->num);
        scanf("%d", &node_->tail);
        List[i] = node_;
    }
}

void printGroup(data List[], int N){
    for(int i = 1; i <= N; i++){
        if(List[i]->tail == -1)
            printf("%05d %d -1\n", List[i]->head, List[i]->num);
        else
            printf("%05d %d %05d\n", List[i]->head, List[i]->num, List[i]->tail);
    }
}

void switchNode(data List[], int i, int j){
    data a = List[i];
    List[i] = List[j];
    List[j] = a;
}

int sequenGroup(data List[], int N, int head){

    int flag = 1;
    int i = 1;
    while (flag)
    {
        /* find the head node */
        if(List[i]->head == head){
            switchNode(List, i, 1);
            flag = 0;
        }
        i++;
    }

    i = 2;
    while(i < N){
        //找到应该在第 i 个位置上的结点，并交换位置
        for(int j = i; j<=N; j++){
            if(List[i-1]->tail == List[j]->head){
                switchNode(List, i, j);
                break;
            }
        }
        i++;
    }

    //遍历整个数组，看看有没有多余的结点
    for(int i = 1; i <= N; i++){
        if(i == N)  return N;
        if(List[i]->tail == List[i+1]->head){
            continue;
        }else{
            return (i);
        }
    }
    
}

void reverseGroup(data List[], int N, int k){
    //定义有多少组结点需要做处理，k个为一组
    int num = N/k;

    for(int i = 1; i <= num; i++){//i是组号
        //一组一组翻转
        //每组需要交换几对数据
        for(int j = 1; j < (k / 2) + 1; j++){//j是组中的顺序位
            int lastOne = (i - 1) * k + j;
            int nextOne = (i - 1) * k + k + 1 - j;
            switchNode(List, lastOne, nextOne);

        }
    }

    //到这里就已经翻转好了，但只是中间的数据处理好了，还要将头和尾处理好
    for(int i = 1; i < N; i++){
        List[i]->tail = List[i+1]->head;
    }
    List[N]->tail = -1;
}
