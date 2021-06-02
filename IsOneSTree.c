#include <stdio.h>
#include <stdlib.h>

typedef struct node *PNode;
typedef PNode Tree;
struct node
{
    /* the node in the Tree */
    int value;
    PNode Left;
    PNode Right;
    int falg;
};

Tree creatTree(int N);
Tree newNode(int item);
Tree insertNode(Tree tree, int item);
void setTreeNodeFlag(Tree tree);
int isSameTree(Tree tree, int N);
int check(Tree tree, int item);

int main(){

    int N = 1, L;
    int printFlag = 0;

    while(N){

        //read the N
        scanf("%d", &N);
        if(N){

            //read the L
            scanf("%d", &L);

            //bulid the Tree
            Tree tree;
            tree = creatTree(N);

            //judge the L lines
            for(int i = 0; i < L; i++){
                int result = isSameTree(tree, N);

                //Yes
                if(result){
                    if(printFlag){
                        printf("\n");
                    }

                    printf("Yes");
                    printFlag = 1;
                }else{
                    if(printFlag){
                        printf("\n");
                    }

                    printf("No");
                    printFlag = 1;
                }
            }
        }
    }

    return 0;
}

Tree insertNode(Tree tree, int item){
    if(!tree){
        tree = newNode(item);
    }else{
        if(item > tree->value){
            tree->Right = insertNode(tree->Right, item);
        }else{
            tree->Left = insertNode(tree->Left, item);
        }
    }
    return tree;
}

Tree newNode(int item){
    Tree t = (Tree)malloc(sizeof(struct node));
    t->Left = NULL;
    t->Right = NULL;
    t->value = item;
    return t;
}

Tree creatTree(int N){
    Tree T;
    int item;

    scanf("%d", &item);
    T = newNode(item);
    for(int i = 1; i < N; i++){
        scanf("%d", &item);
        T = insertNode(T, item);
    }
    return T;
}

int isSameTree(Tree tree, int N){
    int isSame = 1;
    int item;

    setTreeNodeFlag(tree);
    for(int i = 0; i < N; i++){
        scanf("%d", &item);
        if(isSame && !check(tree, item)){
            isSame = check(tree, item);
        }
        
    }

    return isSame;
}

void setTreeNodeFlag(Tree tree){
    if(tree){
        tree->falg = 0;
        setTreeNodeFlag(tree->Left);
        setTreeNodeFlag(tree->Right);
    }
    return;
}

int check(Tree tree, int item){
    if(tree->falg){
        if(item > tree->value)  check(tree->Right, item);
        else if(item < tree->value) check(tree->Left, item);
        else    return 0;
    }else{
        if(item == tree->value){
            tree->falg = 1;
            return 1;
        }else{
            return 0;
        }
    }
}