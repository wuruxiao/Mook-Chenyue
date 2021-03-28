//
//  ReversingList.c
//  MooKChen
//
//  Created by Xiao on 2021/3/27.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node* NodePtrl;
struct Node{
    int flag;
    char headstr[6];
    int value;
    char tailstr[6];
    NodePtrl Next;
};
typedef NodePtrl List;

/*根据读入的结点数量建立一个带有头结点的单链表*/
List CreatList(int N);

/*将在堆上创建一个新的结点，插在指定结点的后面*/
void attachNode(NodePtrl* rear);

/*输入单链表*/
void printList(List L);

/*将各个结点通过首尾"address"按顺序连接起来*/
void sortList(List h, char* hstr);

/*交换两个结点的信息*/
void switchNode(NodePtrl last, NodePtrl rear);

/*对有序单链表进行最后的翻转排序*/
void reversingList(List h, int N, int n);

/*对翻转链表做前后字符串的修改工作，是前一结点的后字符串和后的前字符串一样*/
void correctList(List h);

int main() {
    char headstr[6];
    int N, n;
    List head;
    scanf("%s", headstr);
    scanf("%d", &N);
    scanf("%d", &n);
    
    head = CreatList(N);

    sortList(head, headstr);
    
    reversingList(head, N, n);
    correctList(head);
    printList(head);
    
    return 0;
}

List CreatList(int N){
    //定义头结点
    NodePtrl head = (NodePtrl)malloc(sizeof(struct Node));
    head->Next = NULL;
    head->flag = 0;
    
    NodePtrl rear = head;
    
    while(N--){
        attachNode(&rear);
    }
    return head;
}
void attachNode(NodePtrl* rear){
    //初始化新定义的结点，读入输入的信息结点
    NodePtrl t = (NodePtrl)malloc(sizeof(struct Node));
    t->flag = (*rear)->flag + 1;
    scanf("%s", t->headstr);
    scanf("%d", &t->value);
    scanf("%s", t->tailstr);
    t->Next = NULL;
    
    //连接
    (*rear)->Next = t;
    (*rear) = (*rear)->Next;
}

void printList(List L){
    NodePtrl l = L->Next;
    while(l){
        if(l->flag > 1)
            printf("\n");
        
        printf("%s %d %s", l->headstr, l->value, l->tailstr);
        l = l->Next;
    }
}

void sortList(List h, char* hstr){
    NodePtrl lastone = h->Next, rear = h->Next;
    
    //先找到首结点的位置,然后交换，是首结点就位
    while(1){
        if(strcmp(rear->headstr, hstr) == 0)
            break;
        rear = rear->Next;
    }
    switchNode(lastone, rear);
    
    //排序之后的结点
    rear = lastone->Next;
    while(rear != NULL){
        while(1){
            if(strcmp(rear->headstr, lastone->tailstr) == 0)
                break;
            rear = rear->Next;
        }
        if(lastone->flag + 1 != rear->flag){
            switchNode(lastone->Next, rear);
        }
        lastone = lastone->Next;
        rear = lastone->Next;
    }
}

void switchNode(NodePtrl last, NodePtrl rear){
//    struct Node{
//        int flag;  flag不需要改变
//        char headstr[6];   改变
//        int value;     改变
//        char tailstr[6];   改变
//        NodePtrl Next;   不需要改变
//    };
    
    char h[6], t[6];
    int v;
    
    v = last->value;
    last->value = rear->value;
    rear->value = v;
    
    strcpy(h, last->headstr);
    strcpy(last->headstr, rear->headstr);
    strcpy(rear->headstr, h);
    
    strcpy(t, last->tailstr);
    strcpy(last->tailstr, rear->tailstr);
    strcpy(rear->tailstr, t);
}

void reversingList(List h, int N, int n){
    int time = N / n;
    int begin = 1; int end = n;
    NodePtrl b; //begin
    NodePtrl e; //end
    
    while(time--){
        
        while(begin < end){
            b = h;
            e = h;
            
            while(1){//find the begin
                if(b->flag == begin)     break;
                b = b->Next;
            }
            while(1){//find the end
                if(e->flag == end)     break;
                e = e->Next;
            }
            
            switchNode(b, e);
            
            begin++;
            end--;
        }
        
        begin += n;
        end += n;
    }
}

void correctList(List h){
    NodePtrl m = h->Next;
    
    while(m->Next){
        strcpy(m->tailstr, m->Next->headstr);
        m = m->Next;
    }
    strcpy(m->tailstr, "-1");
}
