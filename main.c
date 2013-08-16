#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
char* ReplaceSpace(char* str, char* restr);
int main(int argc, int** argv)
{
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
