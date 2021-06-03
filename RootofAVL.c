#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode* Tree;
struct TreeNode{
    int value;
    Tree Left;
    Tree Right;
};

Tree insertNode(Tree t, int item);
Tree LLFix(Tree t);
Tree LRFix(Tree t);
Tree RRFix(Tree t);
Tree RLFix(Tree t);
int highTree(Tree t);
void freeTree(Tree t);

int main(){
    int N;
    int item;
    Tree t = NULL;
    scanf("%d", &N);
    if(N){
        for(int i = 0; i < N; i++){
            scanf("%d", &item);
            t = insertNode(t, item);
        }
        printf("%d", t->value);
        freeTree(t);
    }
    return 0;
}

Tree insertNode(Tree t, int item){

    //initialize the new node
    if(!t){
        t = (Tree)malloc(sizeof(struct TreeNode));
        t->value = item;
        t->Left = NULL;
        t->Right = NULL;
    }else{

        //be insertted in the right
        if(item > t->value){
            t->Right = insertNode(t->Right, item);

            if(highTree(t->Left) - highTree(t->Right) == -2){

                //RLFix
                if(item < t->Right->value)   t = RLFix(t);
                //RRFix
                else                        t = RRFix(t);
            }
        }else{

        //be insertted in the left
            t->Left = insertNode(t->Left, item);

            if(highTree(t->Left) - highTree(t->Right) == 2){

                //LLFix
                if(item < t->Left->value)   t = LLFix(t);
                //LRFix
                else                        t = LRFix(t);
            }
        }
    }
    
    return t;
}

int highTree(Tree t){
    int high;
    int Lhigh, Rhigh;

    if(!t)   return 0;

    Lhigh = highTree(t->Left);
    Rhigh = highTree(t->Right);
    high = (Lhigh > Rhigh) ? Lhigh : Rhigh;
    return (high + 1);
}

void freeTree(Tree t){
    if(t){
        freeTree(t->Left);
        freeTree(t->Right);
        free(t);
    }
    return;
}

Tree LLFix(Tree t){
    Tree root = t->Left;
    t->Left = root->Right;
    root->Right = t;
    return root;
}

Tree LRFix(Tree t){
    Tree root = t->Left->Right;
    t->Left->Right = root->Left;
    root->Left = t->Left;
    t->Left = root->Right;
    root->Right = t;
    return root;
}

Tree RRFix(Tree t){
    Tree root = t->Right;
    t->Right = root->Left;
    root->Left = t;
    return root;
}

Tree RLFix(Tree t){
    Tree root = t->Right->Left;
    t->Right->Left = root->Right;
    root->Right = t->Right;
    t->Right = root->Left;
    root->Left = t;
    return root;
}