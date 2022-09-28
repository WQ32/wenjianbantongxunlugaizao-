// 测试

#include  "contact.h"

void menu()
{
	printf("**************************************************\n");
	printf("*********   1.add                2.del    ********\n");
	printf("*********   3.search             4.modify ********\n");
	printf("*********   5.show               6.sort   ********\n");
	printf("*********   7.save               0.exit   ********\n");
	printf("**************************************************\n");
}

int main()
{
	int input = 0;
	//创建通讯录
	//con就是通讯录，里边包含：1000的元素的数和size
	struct Contact con;
	//初始化通讯录
	InitContact(&con);
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case SERACH:
			SerachContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case SORT:
			break;
		case EXIT:
			//保存一下再销毁
			SaveContact(&con);
			//销毁通讯录-释放动态开辟的内存
			DestroyContact(&con);
			printf("退出通讯录\n");
			break;
		case SAVE:
			//写通讯录中的数据到文件中
			SaveContact(&con);
			break;
		default:
			printf("输入错误，请重新输入:\n");
			break;
		}
	} while (input);
	return 0;
}