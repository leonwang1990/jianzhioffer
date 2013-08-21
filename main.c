#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <errno.h>
#include <string.h>
char* ReplaceSpace(char* str, char* restr);
void ReplaceSpacetest();
//////////////////////
typedef struct ListNode* Position;
struct ListNode{
	int m_value;
	Position p_next;
};
void AddToTail(Position* pHead, int value);
void RemoveNode(Position* pHead, int value);
void listtest();
///////////////////////
void ReversePrintList();
void IterativelyPrintList(Position pHead);
/////////////////////q-6
typedef struct BinTreeNode* BinTree;
typedef struct BinTreeNode* pChild;
struct BinTreeNode{
	int m_value;
	pChild pLeft;
	pChild pRight;
};
BinTree  ConstructBT(int* preorder,int* endpreorder, int* inorder,int* endinorder);
void RebuildBinTree();
void PreOrder(BinTree tree);
void InOrder(BinTree tree);
void PostOrder(BinTree tree);
////////////////////q-查找和排序算法
int partition(int* x,int start, int end);
void quicksort(int* x,int start, int end);
void insertsort(int* x,int start,int end);
void printx(int* x,int len);
void swap(int* x,int* y);
void bubblesort(int* x,int start,int end);
void merge(int* x, int* tmp,int start, int end);
void mergesort(int* x,int start, int end);
////////////////////q-11数值的整数次方
double Power(double base, int exponent);
double recurpower(double base, unsigned int exponent);
///////////////////q-12打印1到最大的n位数
void PrinttoMaxNDigits(int n);
void prints(char* str,int start, int end);
/////recursively
void recuPrinttoMaxNDigits(int n);
void recuPrints(char* str,int numdigits,int len);
int main(int argc, int** argv)
{
	//ReplaceSpacetest();
	//listtest();
	//ReversePrintList();
	//RebuildBinTree();
	//int x[]={1,2,7,8,9,3,4,5,6};
	//quicksort(x,0,8);
	//insertsort(x,0,8);
	//bubblesort(x,0,8);
	//mergesort(x,0,8);
	//printx(x,8);
	//double r;
	//r=pow(0,-5);
	//r=Power(0,-5);
	recuPrinttoMaxNDigits(3);
}
/////////////////////////q-12打印1到最大的n位数
////////q-12全排列递归版本
void recuPrinttoMaxNDigits(int n){
	//只需n位
	char* nstr=malloc(sizeof(char)*(n));
	//初始化为0
	memset(nstr,'0',n);
	//n-1是索引序号
	recuPrints(nstr,0,n-1);
}
//position 和end 是索引序号
void recuPrints(char* str,int position,int end){
	int  i;
	//base条件，当到达end+1时超出边界
	if (position == end+1 )
	{
		//必须递归到最后一位的时候才能输出
		prints(str,0,end);
		return;
	}
	for (i=0;i<=9;i++)
	{
		str[position]=i+'0';
		recuPrints(str,position+1,end);
	}
}
///////
void PrinttoMaxNDigits(int n){
	//nstr共n+1位字符，第一个字符nstr[0]作为标志位
	//当nstr[0]=1时，表示达到最大值999...9(n位)
	char* nstr=malloc(sizeof(char)*(n+1));
	int i;
	//初始化为0
	memset(nstr,'0',n+1);
	/*
	for (i=0;i<=n;i++)
		nstr[i]='0';
	*/
	//达到最大值前进行加1运算
	while (nstr[0]!='1')
	{
		//先打印字符串，在while结束前打印的话会打印出100..0
		prints(nstr,0,n);
		//在最后位加1，模拟正常的数字运算
		i=n;
		while (nstr[i]=='9')//遇到'9'时进位
		{
			nstr[i--]='0';
		}
		nstr[i]+=1;//进位结束
	}

}
void prints(char* str,int start, int end){
	int i=start;
	//跳过0字符
	while (str[i]=='0')
		i++;
	while (i<=end)
		printf("%c",str[i++]);
	printf(" ");
}
/////////////////////////q-11数值的整数次方
double Power(double base, int exponent){
	unsigned int absexpo;
	double result;
	//base==0.0 and exponent<0 无意义
	if ( (base-0.0) > -0.000001 &&	(base-0.0) < 0.000001 
		&& exponent < 0)
			perror("error");
	//exponent < 0 or >0
	if (exponent < 0)
		absexpo = (unsigned int) (-exponent);
	else
		absexpo = (unsigned int) (exponent);

	result = recurpower(base,absexpo);
	if (exponent < 0)
		result = 1.0/result;
	return result;
}
//递归计算整数次方，指数以无符号数表示（使用移位代替除2）
double recurpower(double base, unsigned int exponent){
	double result;
	if (exponent == 0)
		return 1;
	if (exponent == 1)
		return base;
	//考虑奇偶两种情况
	result=recurpower(base,exponent>>1);
	result *= result;
	if (exponent & 0x1 ==1 )
		result *=base;
	return result;
}
/////////////////////////q-查找和排序算法
//binaryfind
//hashfind
//bintreefind
void printx(int* x,int len){
	int i=0;
	while (i<=len)
		printf("%d ",x[i++]);
	printf("\n");
}
void swap(int* x,int* y){
	int tmp;
	tmp=*x;*x=*y;*y=tmp;
}
int partition(int* x,int start, int end){
	int index,pivot,small,i;
	index=rand()%(end-start)+start;
	swap(&x[index],&x[end]);
	pivot=x[end];
	small=start-1;
	i=start;
	for (i=start;i<end;i++)
	{
		if (x[i] < pivot)
			swap(&x[i],&x[++small]);
	}
	swap(&x[++small],&x[end]);
	return small;
	/*
	for (;;)
	{
		while (x[++i]<pivot)
			;
		while (x[--j]>pivot)
			;
		if (i < j)
			swap(&x[i],&x[j]);
		else
			break;
	}
	swap(&x[i],&x[end]);
	printf("%d:%d,%d--",start,end,index);
	printx(x,8);*/
}
void quicksort(int x[],int start, int end){
	int index;
	if (start==end)
		return;
	index=partition(x,start,end);
	if (index > start)
		quicksort(x,start,index-1);
	if (index < end)
		quicksort(x,index+1,end);
}
void insertsort(int* x,int start,int end){
	int i,j;
	for (i=0;i<=end;i++)
		//从后向前比较
		for (j=i;j>=0;j--)
			if (x[j]<x[j-1])
				swap(&x[j],&x[j-1]);
}
void bubblesort(int* x,int start,int end){
	int i,j;
	int indexmin;
	for (i=0;i<=end;i++)
	{
		indexmin=i;
		for (j=i;j<=end;j++)
		{
			if (x[j]<x[indexmin])
				indexmin=j;
		}
		swap(&x[i],&x[indexmin]);
	}
}
void merge(int* x, int* tmp,int start, int end){
	int mid;
	int i,j,index=start;
	if (end == start)
		return;
	mid= (start+end)/2;
	merge(x,tmp,start,mid);
	merge(x,tmp,mid+1,end);
	
	i=start;j=mid+1;
	while (i<=mid)
	{
		while (j<=end)
		{
			if (x[i]>x[j])
				tmp[index++]=x[j++];
			else
				break;
		}
		tmp[index++]=x[i++];
	}
}

void mergesort(int* x,int start, int end){
	int* tmp;
	int i;
	tmp=malloc(sizeof(x)*sizeof(x[0]));
	merge(x,tmp,start,end);

	//tmp->x
	for (i=0;i<=end;i++)
		x[i]=tmp[i];
	//free(tmp);
}
///////////////////////////q-6重建二叉树
void RebuildBinTree(){
	int preorder[8]={1,2,4,7,3,5,6,8};
	int inorder[8]={4,7,2,1,5,3,8,6};
	BinTree tree;
	tree=ConstructBT(preorder,preorder+7,
		inorder,inorder+7);
	printf("preorder:");
	PreOrder(tree);
	printf("inorder:");
	InOrder(tree);
	printf("postorder:");
	PostOrder(tree);
}
void PreOrder(BinTree tree){
	if (tree==NULL)
		return;
	printf("%d ",tree->m_value);
	PreOrder(tree->pLeft);
	PreOrder(tree->pRight);
}
void InOrder(BinTree tree){
	if (tree==NULL)
		return;
	InOrder(tree->pLeft);
	printf("%d ",tree->m_value);
	InOrder(tree->pRight);
}
void PostOrder(BinTree tree){
	if (tree==NULL)
		return;
	PostOrder(tree->pLeft);
	PostOrder(tree->pRight);
	printf("%d ",tree->m_value);
}
BinTree ConstructBT(int* preorder,int* endpreorder,
	int* inorder,int* endinorder){
	int rootvalue=preorder[0];
	int indexofroot;
	BinTree root=malloc(sizeof(struct BinTreeNode));
	root->m_value=rootvalue;
	root->pLeft=root->pRight=NULL;
	//base情况，只有一个元素时返回
	if (inorder==endinorder)
	{
		return root;
	}
	//find rootvalue in inorder
	indexofroot=0;
	while (inorder[indexofroot]!=rootvalue)
		indexofroot++;
	//左子树存在的情况
	if (indexofroot>0)
	{
		root->pLeft=ConstructBT(preorder+1,preorder+indexofroot,
			inorder,inorder+indexofroot-1);
	}
	//右子树存在的情况
	if (indexofroot<endinorder-inorder)
	{
		root->pRight=ConstructBT(preorder+indexofroot+1,endpreorder,
			inorder+indexofroot+1,endinorder);
	}
	return root;
}
///////////////////////////q-5
void ReversePrintList(){
	Position pHead;
	int i;
	pHead=NULL;
	for (i=0;i<10;i++)
	{
		AddToTail(&pHead,i);
	}
	IterativelyPrintList(pHead);
}
void IterativelyPrintList(Position pHead){
	if (pHead==NULL)
		return;
	if(pHead->p_next!=NULL)
		IterativelyPrintList(pHead->p_next);
	printf("%d ",pHead->m_value);
}
///////////////////////////q-4
void listtest(){
	Position pHead;
	pHead=NULL;
	AddToTail(&pHead,4);
	AddToTail(&pHead,5);
	RemoveNode(&pHead,4);
	RemoveNode(&pHead,5);
	AddToTail(&pHead,5);
}
void RemoveNode(Position* pHead, int value){
	Position pNode;
	Position p;
	if (*pHead == NULL || pHead==NULL)
		return;
	if ((*pHead)->m_value==value)
	{
		p=(*pHead)->p_next;//保存删除节点的下一个节点指针
		free(*pHead);///释放删除节点
		*pHead=p;
		return;
	}
	pNode=*pHead;
	///删除一个节点后，需要获得该节点的前一个节点的指针，所以要以pNode->p_next->m_value的形式检测。
	//在此之前要检测*pHead节点的值是否符合条件
	while (pNode->p_next!=NULL && pNode->p_next->m_value!=value)
		pNode=pNode->p_next;
	//pNode->p_next==NULL时pNode指向链表最后一个节点，此时最后一个节点的值已被检测过，
	//在上一个循环pNode->p_next指向最后节点，pNode->p_next->m_value即为最后节点的值
	if (pNode->p_next!=NULL)
	{
		p=pNode->p_next;
		pNode->p_next=p->p_next;
		free(p);
	}

}
//使用LoistNde** pHead作为参数，是为了当新建第一个节点时可以有效的给pHead赋值，类似于传值和传指针的区别
void AddToTail(Position* pHead, int value){
	Position pNode;
	Position p;
	pNode=malloc(sizeof(struct ListNode));
	if(pNode==NULL)
		perror("bad malloc");
	pNode->m_value=value;
	pNode->p_next=NULL;

	if (*pHead==NULL)
	{
		*pHead=pNode;///传指针LoistNde** pHead的作用在此
	} 
	else
	{
		p=*pHead;
		while (p->p_next!=NULL)
			p=p->p_next;
		p->p_next=pNode;
	}
}

///////////////////////
void ReplaceSpacetest(){
	char str[20]="we are  happy.";
	char* restr="%20";
	ReplaceSpace(str,restr);
	printf("%s",str);
}
char* ReplaceSpace(char* str, char* restr){
	int spacecount=0;
	char* p1=str;
	char* p2;
	//char* newstr;
	int i=0;
	int j=0;
	int rsize;
	//统计空格数，p1最后指向str的'\0'
	while (*p1 != '\0')
	{
		if (*p1 == ' ')
			spacecount++;
		p1++;
	}
	//计算新串的长度，不计'\0'
	rsize=(strlen(str)+(strlen(restr)-1)*spacecount)*sizeof(char);
	//newstr= (char*)realloc(str,rsize);///realloc出错！！！！堆错误
	//assert(str);
	//if (str == NULL)
		//return NULL;
	//p2指向新串的'\0'位置，第一个复制的是老串的'\0'到新串的'\0'位置
	p2=str+rsize;
	for (i=0;i<spacecount;i++)
	{
		//复制每个单词
		while (*p1!=' ')
			*p2--=*p1--;
		p1--;//跳过空格
		//填充restr
		j=strlen(restr);
		while(j>0)
			*p2--=restr[--j];
	}
}
