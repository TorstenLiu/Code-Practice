//��ϰ1
struct s1
{
	char c1;
	int i;//4
	char c2;
};
printf("%d\n", sizeof(struct s1));//1+3+4+1 ����4�ı��� +2=12

//��ϰ2
struct s2
{
	char c1;
	char c2;//ƫ������СΪ1������ֱ�Ӵ洢
	int i;//4
};
printf("%d\n", sizeof(struct s2));//1+1+4 ����4�ı���  +2=8

//��ϰ3
struct s3
{
	double d;//8
	char c;
	int i;
};
printf("%d\n", sizeof(struct s3));//8+1+3+4=16 ��8�ı���

//��ϰ4���ṹ��Ƕ�ף�
struct s3
{
	double d;//8
	char c;
	int i;
};
struct s4
{
	char c1;
	struct s3 s3;//��������Ϊ8
	double a;
};
printf("%d\n", sizeof(struct s4));//1+7+16+8=32