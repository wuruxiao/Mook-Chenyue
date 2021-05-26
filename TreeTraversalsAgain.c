/*
一，程序的思路如下：
    堆栈输入实际上包含了两种二叉树的遍历方法，即前序遍历和中序遍历
    Push是前序，即1 2 3 4 5 6
    Pop是中序，即3 2 4 1 6 5
    而我们要做到就是已知两种遍历求后序遍历的情况
    方法就不细说了前序第一个元素就是根节点，从中序序列中找到根节点，之前的就是左子树，之后的就是右子树，对左右子树进行递归循环即可
二。实际上本题用C++语言来编写简单好看，但本人还没学习C++，所以程序较为繁琐
    但其实，只要理解了题目到底要干什么，对遍历操作有基本的认识，就可以做题了
*/
#include <stdio.h>
#include <string.h>
#define MAXSIZESTR 4
#define MAXSIZE 30

int flag = 0;
void PrintPost(int Preorder[], int Inorder[], int N);

int main()
{

    int N, Preorder[MAXSIZE], PreorderT[MAXSIZE], Inorder[MAXSIZE];
    char str[MAXSIZESTR + 1];   int item;
    int i, Prei = 0, Ini = 0, PreiT = 0;

    scanf("%d", &N);
    if(N)
    {
        for(i = 0; i < 2*N; i++)
        {
            scanf("\n%s", str);
            if(strcmp(str, "Push") == 0)
            {
                scanf(" %d", &item);
                Preorder[Prei++] = item;
                PreorderT[PreiT++] = item;
            }
            else
            {
                Inorder[Ini++] = PreorderT[--PreiT];
            }
        }
    }

    PrintPost(Preorder, Inorder, N);

    return 0;
}

void PrintPost(int Preorder[], int Inorder[], int N)
{
    int Root, i, j;
    int P[MAXSIZE], I[MAXSIZE];
    if(N)
    {
        for(i = 0; i < N; i++)
    {
        P[i] = Preorder[i];
        I[i] = Inorder[i];
    }
    int Pleft[MAXSIZE], Ileft[MAXSIZE], Nleft;
    int Pright[MAXSIZE], Iright[MAXSIZE], Nright;
    Root = P[0];
    for(i = 0; i < N; i++)
    {
        if(I[i] == Root)
        {
            break;
        }
    }
    Nleft = i;  Nright = N-i-1;
    for(j = 0; j < Nleft; j++)
    {
        Pleft[j] = P[j+1];
        Ileft[j] = I[j];
    }
    for(j = 0; j < Nright; j++)
    {
        Pright[j] = P[j + Nleft + 1];
        Iright[j] = I[j + Nleft + 1];
    }
    PrintPost(Pleft, Ileft, Nleft);
    PrintPost(Pright, Iright, Nright);
    if(flag)
    {
        printf(" ");
    }
    printf("%d", Root);
    flag = 1;
    }
    return;
}
