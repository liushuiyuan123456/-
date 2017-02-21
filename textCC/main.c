#include <stdio.h>
#include <stdlib.h>//栈的顺序存储结构，用一维数组实现
#define OK 1
#define ERROR -1
#define TRUE 1
#define FALSE 0
#define MAXSIZE 10
typedef int Status;
typedef int ElemType;
typedef struct {
    ElemType data[MAXSIZE];
    int top;//栈顶指针
}Stack;



typedef  struct {
    ElemType *elem;
    int length;
    
}SSTable;

int Search_seq(SSTable *ST,int key){
    
    int i = 0;
    
    while (i < ST->length && ST->elem[i] != key) {
        
        i++;
        
   
        
    }
    
    if (i >= ST->length) {
        return 0;
    }else{
        return i+1;
    }
}

typedef int ketType;
typedef int InfoType;

typedef struct {
    ketType key;
    InfoType otherInfo;
    
}RedType;


typedef struct {
    RedType r[MAXSIZE + 1];
    int length;
    
}SqList;

void print(SqList *L){
    
    int i;
    
    for (i = 1; i <= L->length; i++) {
        
        printf("%d,%d\n",L->r[i].key,L->r[i].otherInfo);
    }
    
}


void InsertSort(SqList *L){
    int i,j;
    for (i = 2; i <= (*L).length ; ++i) {
        
        if(L->r[i].key < L->r[i-1].key){
            L->r[0] = L->r[i];//赋给首元素
            for (j = i - 1; L->r[0].key < L->r[j].key; --j) {
                L->r[j+1] = L->r[j];//记录后移
                
                
//                print(L);
            }
            L->r[j+1] = L->r[0];

        }
        
        
    }
    
}
//int SelectMinKey(SqList *L,int i);


int SelectMinKey(SqList *L,int i)
{
    int min;
    int j,k;
    k = i;
    min = L->r[i].key;
    for (j = i+1; j < L->length; j++) {
        if (L->r[j].key < min) {
            k = j;
            min = L->r[j].key;
        }
    }
    
    return k;
}

void XuanZeSort(SqList *L){
    for (int i = 1; i < L->length; i++) {
        
        RedType t;

        int j =  SelectMinKey(L, i);
        
        if (i != j) {
            
            t=(*L).r[i];
            
            (*L).r[i]=(*L).r[j];
            
            (*L).r[j]=t;
        }
    }
    
}

void MaoPaoSort(SqList *L){
    
    int i,j;
    
    for ( i = 1; i < L->length; i++) {
    
        for (j = i; j < L->length; j++) {
        
            
            if (L->r[j].key >= L->r[j+1].key) {
               int temp = L->r[j+1].key;
                L->r[j+1].key = L->r[j].key;
                L->r[j].key =temp;
                
            }
            
            
        }
        
    }
    
    
}
//1. 初始化
Status InitStack(Stack *S){
    int i;
    for(i=0;i<MAXSIZE;i++)
        S->data[i]=NULL;
    S->top=-1;
    return OK;
}
//2. 创建一个长度为n的堆栈
Status CreateStack(Stack *S,int n)
{
    if(n>MAXSIZE || n<1)
 {
    printf("输入长度有误！/n");
    return ERROR;
  }
    //        srand(time(0));
    int i;
    for(i=0;i<n;i++)
    {
        S->data[i]=rand()%100+1;
    }
    S->top=n-1;
    return OK;
}

//3. 压栈操作
Status push(Stack *S,ElemType e)
{
    if(MAXSIZE-1==S->top)
    { printf("栈已满/n");
      return ERROR;
    }    //栈顶指向的元素有值
    ++(S->top);
    S->data[S->top]=e;
    return OK;
}



//4. 出栈
Status pop(Stack *S,ElemType *e){//将栈顶元素出栈，传给e
    if(-1==S->top)
    {
        printf("栈为空！/n");
        return ERROR;
    }
    *e=S->data[S->top];
    --(S->top);
    return OK;
}

void conversion(){
    Stack S;
    int N;
    InitStack(&S);
    scanf("%d",&N);
    
    while (N) {
        push(&S, N % 8);
        N = N/8;
    }
    
    while(OK==pop(&S,&N))
    {
        getchar();
        printf("%d\n",N);
    }
}



int main(){
 /*
    Stack S;
    int i,n,e;
    if(OK!=InitStack(&S)){printf("初始化失败！");return ERROR;
    }
    printf("输入初始化栈的长度n=");
    scanf("%d",&n);
    
    if(OK==CreateStack(&S,n))
    {
          for(i=0;i<=S.top;i++)
       {
         printf("%d\n",S.data[i]);
       }
    }
    
    
    printf("\n输入想要插入栈的值");
    while(1==scanf("%d",&e)){
       if(ERROR==push(&S,e))
       {
           break;
       }
       else
       {
        for(i=0;i<=S.top;i++)
            
        printf("%d\n",S.data[i]);}
    }
    
    
    
    printf("\n接下来测试出栈！栈中的元素依次出栈/n");
    while(OK==pop(&S,&e))
    {
        getchar();
        printf("%d\n",e);
    }
    
    */
    
//    conversion();
    
    
    RedType d[5] = {
        
        { 49, 1}, { 38, 2}, { 65, 3}, { 97, 4},
        
        { 76, 5}
    };
    
    SqList L;
    
    int i;
    
    
    for (i = 0; i < 5; i++) {
        
        L.r[i+1] = d[i];
        
        L.length = 5;
    }
    
    printf("排序前:\n");
    print(&L);
    
    
    XuanZeSort(&L);
    
    printf("排序后:\n");
    print(&L);
    return 0;
};
