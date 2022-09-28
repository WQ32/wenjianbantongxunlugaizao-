//声明函数

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

// #define MAX 1000 

#define DEFAULT_SZ 3
#define MAX_NAME 20
#define	MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 20


enum Option
{
	EXIT, //0
	ADD,  //1
	DEL, 
	SERACH,
	MODIFY,
	SHOW,
	SORT,
	SAVE

};

struct PeoInFo                  //可以改成typedef struct PeoInfo ，再在末尾分号前加想要用的名字
{								//这样在后面引用时就不用处处都加struct PeoInfo,直接用定义的新名字
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
};

//通讯录类型
struct Contact
{
	
	struct PeoInFo *data;  
	//指针 - 用来指向要开辟的内存 - 自定义大小
	int size;
	//记录当前已经有的元素个数
	int capacity; 
	//当前通讯录的最大容量
};

//声明函数
//初始化通讯录的函数
void InitContact(struct Contact* ps);

//增加一个信息到通讯录
void AddContact(struct Contact* ps);

//打印通讯录中的信息
void ShowContact(const struct Contact* ps);

//删除指定的联系人
void DelContact(struct Contact* ps);

//查找指定的人的信息
void SerachContact(const struct Contact* ps);

//修改指定联系人
void ModifyContact(struct Contact* ps);

//写通讯录信息到文件中
void SaveContact(struct Contact* ps);

//加载通讯录信息
void LoadContact(struct Contact* ps);