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
		p=(*pHead)->p_next;//����ɾ���ڵ����һ���ڵ�ָ��
		free(*pHead);///�ͷ�ɾ���ڵ�
		*pHead=p;
		return;
	}
	pNode=*pHead;
	///ɾ��һ���ڵ����Ҫ��øýڵ��ǰһ���ڵ��ָ�룬����Ҫ��pNode->p_next->m_value����ʽ��⡣
	//�ڴ�֮ǰҪ���*pHead�ڵ��ֵ�Ƿ��������
	while (pNode->p_next!=NULL && pNode->p_next->m_value!=value)
		pNode=pNode->p_next;
	//pNode->p_next==NULLʱpNodeָ���������һ���ڵ㣬��ʱ���һ���ڵ��ֵ�ѱ�������
	//����һ��ѭ��pNode->p_nextָ�����ڵ㣬pNode->p_next->m_value��Ϊ���ڵ��ֵ
	if (pNode->p_next!=NULL)
	{
		p=pNode->p_next;
		pNode->p_next=p->p_next;
		free(p);
	}

}
//ʹ��LoistNde** pHead��Ϊ��������Ϊ�˵��½���һ���ڵ�ʱ������Ч�ĸ�pHead��ֵ�������ڴ�ֵ�ʹ�ָ�������
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
		*pHead=pNode;///��ָ��LoistNde** pHead�������ڴ�
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
	//ͳ�ƿո�����p1���ָ��str��'\0'
	while (*p1 != '\0')
	{
		if (*p1 == ' ')
			spacecount++;
		p1++;
	}
	//�����´��ĳ��ȣ�����'\0'
	rsize=(strlen(str)+(strlen(restr)-1)*spacecount)*sizeof(char);
	//newstr= (char*)realloc(str,rsize);///realloc�����������Ѵ���
	//assert(str);
	//if (str == NULL)
		//return NULL;
	//p2ָ���´���'\0'λ�ã���һ�����Ƶ����ϴ���'\0'���´���'\0'λ��
	p2=str+rsize;
	for (i=0;i<spacecount;i++)
	{
		//����ÿ������
		while (*p1!=' ')
			*p2--=*p1--;
		p1--;//�����ո�
		//���restr
		j=strlen(restr);
		while(j>0)
			*p2--=restr[--j];
	}
}
