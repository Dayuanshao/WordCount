#include <stdio.h>
#include <stdlib.h>
#include <direct.h>

void characterCount()
{
	FILE* file = fopen("myTest.txt", "r");
	int charactercount = 0;//用于统计字符数
	char c = ' '; //用于接收从文件里读取的字符
	c = fgetc(file);
	while (c != EOF) //EOF作为文件结束标志，这种以EOF作为文件结束标志的文件
	{
		charactercount++;
		c = fgetc(file);
	}
	printf("统计出字符共有:%d", charactercount);
	fclose(file);//使用完后释放空间
}

void wordCount()
{
	FILE* file = fopen("myTest.txt", "r");
	int wordcount = 0;//用于统计单词数目
	char c = ' ';//用于接收从文件里读取的字符
	int flag = 0;
	c = fgetc(file);
	printf("%c", c);
	while (c != EOF)
	{
		if (c == ' ' || c == ',')
		{
			flag = 0;
			c = fgetc(file);
		}
		else
		{
			if (flag == 0)
			{
				wordcount++;
				flag = 1;
			}
			c = fgetc(file);
		}
	}
	printf("统计出单词共有:%d", wordcount);
	fclose(file);
}
int main(int argc, char* argv[]) //main函数只有这两种参数
{
	if ((strcmp(argv[1], "-c") == 0) && (strcmp(argv[2], "myTest.txt") == 0))//当char数字下标为1时指向第一个参数
		characterCount();
	if ((strcmp(argv[1], "-w") == 0) && (strcmp(argv[2], "myTest.txt") == 0))
		wordCount();
	return 0;
}
