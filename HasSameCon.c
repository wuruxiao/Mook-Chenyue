#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10
#define Null -1
struct node
{
    char ele;
    int left;
    int right;
}t1[MAXSIZE], t2[MAXSIZE];

int creatTree(struct node t[]);
int judgeIs(int root1, int root2);

int main(){

    //构建二叉树
    int root1 = creatTree(t1);
    int root2 = creatTree(t2);

    //判断两棵树是否同构
    if(judgeIs(root1, root2)){
        printf("Yes");
    }else{
        printf("No");
    }
    return 0;
}

int creatTree(struct node t[]){
    int m;
    scanf("%d", &m);
    if(m){
        int check[MAXSIZE];
        for(int i = 0; i < m; i++)  check[i] = 0;
        for(int i = 0; i < m; i++){

            char leftchar;
            char rightchar;
            scanf("\n%c %c %c", &t[i].ele, &leftchar, &rightchar);
            if(leftchar != '-'){
                t[i].left = leftchar - '0';
                check[t[i].left] = 1;
            }else{
                t[i].left = Null;
            }
            if(rightchar != '-'){
                t[i].right = rightchar - '0';
                check[t[i].right] = 1;
            }else{
                t[i].right = Null;
            }
        }

        for(int i = 0; i < m; i++){
            if(check[i] == 0)
                return i;
        }
    }

    return Null;
}

int judgeIs(int root1, int root2){

    //两个都是空的，认为是同构的
    if(root1 == Null && root2 == Null){
        return 1;
    }
    //一个是空的，一个不空
    if((root1 == Null && root2 != Null) || (root2 == Null && root1 != Null)){
        return 0;
    }
    //根就不一样
    if(t1[root1].ele != t2[root2].ele)  return 0;
    //根的左边空，右边判断
    if((t1[root1].left == Null) && (t2[root2].left == Null))
        return judgeIs(t1[root1].right, t2[root2].right);
    //根的右边空，左边判断
    if((t1[root1].right == Null) && (t2[root2].right == Null))
        return judgeIs(t1[root1].left, t2[root2].left);
    //一边是一样的
    if(((t1[root1].left != Null) && (t2[root2].left != Null)) &&
        (t1[t1[root1].left].ele == t1[t2[root2].left].ele))
        return (judgeIs(t1[root1].left, t2[root2].left) &&
                judgeIs(t1[root1].right, t2[root2].right));
    //左右两边相反的
    else{
        return (judgeIs(t1[root1].left, t2[root2].right) &&
                judgeIs(t1[root1].right, t2[root2].left));
    }
}