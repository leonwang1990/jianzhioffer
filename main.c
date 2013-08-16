#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


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
/////////////////////
int main(int argc, int** argv)
{
	//ReplaceSpacetest();
	//listtest();
}
///////////////////////////
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
