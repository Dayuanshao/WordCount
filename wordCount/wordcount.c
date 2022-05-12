#include <stdio.h>
#include <stdlib.h>
#include <direct.h>

void characterCount()
{
	FILE* file = fopen("myTest.txt", "r");
	int charactercount = 0;//����ͳ���ַ���
	char c = ' '; //���ڽ��մ��ļ����ȡ���ַ�
	c = fgetc(file);
	while (c != EOF) //EOF��Ϊ�ļ�������־��������EOF��Ϊ�ļ�������־���ļ�
	{
		charactercount++;
		c = fgetc(file);
	}
	printf("ͳ�Ƴ��ַ�����:%d", charactercount);
	fclose(file);//ʹ������ͷſռ�
}

void wordCount()
{
	FILE* file = fopen("myTest.txt", "r");
	int wordcount = 0;//����ͳ�Ƶ�����Ŀ
	char c = ' ';//���ڽ��մ��ļ����ȡ���ַ�
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
	printf("ͳ�Ƴ����ʹ���:%d", wordcount);
	fclose(file);
}
int main(int argc, char* argv[]) //main����ֻ�������ֲ���
{
	if ((strcmp(argv[1], "-c") == 0) && (strcmp(argv[2], "myTest.txt") == 0))//��char�����±�Ϊ1ʱָ���һ������
		characterCount();
	if ((strcmp(argv[1], "-w") == 0) && (strcmp(argv[2], "myTest.txt") == 0))
		wordCount();
	return 0;
}
