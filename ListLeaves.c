#include <stdio.h>
#define MAXSIZE 10
#define Null -1

struct node{
    int left;
    int right;
}T[MAXSIZE];

struct quence
{
    int data[MAXSIZE];
    int head;
    int size;
}Q;


//Create the tree; Return the root
int creatTree(struct node T[], int n);
void printResult(int n, int root);

int main(){

    int root;
    int n;
    scanf("%d", &n);
    Q.size = 0; Q.head = -1;

    //Create the tree
    root = creatTree(T, n);

    //make the quence and print the result
    printResult(n, root);

    //Print the result
    return 0;
}

void printResult(int n, int root){
    int printFlag = 0;
    //初始化队列，将第一个加进去
    Q.data[0] = root;
    Q.head++;
    Q.size++;

    //While the quence is not empty
    while (Q.size != 0)
    {
        //pop
        int popnumber = Q.data[Q.head];

        if((T[popnumber].left == Null) &&
            (T[popnumber].right == Null)){
            if(printFlag)   printf(" ");
            printf("%d", popnumber);
            printFlag = 1;
        }

        Q.head++;
        Q.size--;

        //push
        if(T[popnumber].left != Null){
            
            Q.data[Q.head + Q.size] = T[popnumber].left;
            Q.size++;
        }
        if(T[popnumber].right != Null){
            
            Q.data[Q.head + Q.size] = T[popnumber].right;
            Q.size++;
        }
    }
    
}

int creatTree(struct node T[], int n){
    int root = Null;
    int check[MAXSIZE];
    if(n){
        for(int i = 0; i < n; i++)  check[i] = 0;
        for(int i = 0; i < n; i++){
            char cl;
            char cr;
            scanf("\n%c %c", &cl, &cr);

            //cl
            if(cl != '-'){
                T[i].left = cl - '0';
                check[T[i].left] = 1;
            }else{
                T[i].left = Null;
            }
            //cr
            if(cr != '-'){
                T[i].right = cr - '0';
                check[T[i].right] = 1;
            }else{
                T[i].right = Null;
            }
        }
        for(int i = 0; i < n; i++){
            if(check[i] == 0){
                root = i;
                break;
            }
        }
        return root;
    }

    return Null;
}