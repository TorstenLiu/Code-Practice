//1.
char *myString()
{
	char buffer[6] = { 0 };
	char *s = "hello world";
	for (int i = 0; i < sizeof(buffer) - 1; i++)
	{
		buffer[i] = *(s + i);
	}
	return buffer;
}
int main()
{
	char * buffer = myString();
	printf("%s\n", buffer);//���Ϊ�����̵����ֵ����ΪbufferΪ�ֲ����飬����������ᱻ�ջ�
	system("pause");
	return 0;
}

//2.
int main()
{
	char a[1000];
	int i;
	for (i = 0; i < 1000; i++)
	{
		a[i] = (char)(-1 - i);
	}
	printf("%d\n", strlen(a));//255
	system("pause");
	return 0;
}