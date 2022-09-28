//��������

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

struct PeoInFo                  //���Ըĳ�typedef struct PeoInfo ������ĩβ�ֺ�ǰ����Ҫ�õ�����
{								//�����ں�������ʱ�Ͳ��ô�������struct PeoInfo,ֱ���ö����������
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
};

//ͨѶ¼����
struct Contact
{
	
	struct PeoInFo *data;  
	//ָ�� - ����ָ��Ҫ���ٵ��ڴ� - �Զ����С
	int size;
	//��¼��ǰ�Ѿ��е�Ԫ�ظ���
	int capacity; 
	//��ǰͨѶ¼���������
};

//��������
//��ʼ��ͨѶ¼�ĺ���
void InitContact(struct Contact* ps);

//����һ����Ϣ��ͨѶ¼
void AddContact(struct Contact* ps);

//��ӡͨѶ¼�е���Ϣ
void ShowContact(const struct Contact* ps);

//ɾ��ָ������ϵ��
void DelContact(struct Contact* ps);

//����ָ�����˵���Ϣ
void SerachContact(const struct Contact* ps);

//�޸�ָ����ϵ��
void ModifyContact(struct Contact* ps);

//дͨѶ¼��Ϣ���ļ���
void SaveContact(struct Contact* ps);

//����ͨѶ¼��Ϣ
void LoadContact(struct Contact* ps);