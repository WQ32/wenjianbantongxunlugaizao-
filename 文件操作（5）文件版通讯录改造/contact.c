//ʵ�ֺ�������
//1.���1000�����ѵ���Ϣ
// ���֣��绰���Ա�סַ������
// 2.���Ӻ�����Ϣ
// 3.ɾ��ָ�����ֵĺ�����Ϣ
// 4.���Һ�����Ϣ
// 5.�޸ĺ�����Ϣ
// 6.��ӡ������Ϣ
// 7.����

#include "contact.h"

void CheckCapacity(struct Contact* ps);

void LoadContact(struct Contact* ps)
{
	struct PeoInFo tmp = { 0 };
	FILE* pfread = fopen("contact.dat", "rb");
	if (pfread == NULL)
	{
		printf("����ʧ�ܡ���");
		printf("LoadContact::%s\n", strerror(errno));
		return;
	}
	//��ȡ�ļ�������ڳ�ʼ��ͨѶ¼��
	while(fread(&tmp, sizeof(struct PeoInFo),1, pfread))
	{
		CheckCapacity(ps);
		ps->data[ps->size] = tmp;
		ps->size++;
	}
	//�ر��ļ�
	fclose(pfread);
	pfread = NULL;
}

void InitContact(struct Contact* ps)
{
	//����ͨѶ¼���ֻ��0��Ԫ��
	// memset(ps->data, 0, sizeof(ps->data));
	//����
	ps->data = (struct PeoInFo*)malloc(DEFAULT_SZ * sizeof(struct PeoInFo));
	ps->size = 0;
	ps->capacity = DEFAULT_SZ;
	//���ļ����Ѿ���ŵ�ͨѶ¼�е���Ϣ������ͨѶ¼��
	LoadContact(ps);
}

void CheckCapacity(struct Contact* ps)
{
	if (ps->size == ps->capacity)
	{
		//����
		struct PeoInFo* ptr = realloc(ps->data, (ps->capacity + 2) * sizeof(struct PeoInFo));
		if (ptr != NULL)
		{
			printf("���ݳɹ�\n");
		}
		else
		{
			printf("����ʧ�ܡ���\n");
		}
	}
}
void AddContact(struct Contact* ps)
{
	//��⵱ǰͨѶ¼������
	//1. ������ˣ������ӿռ�
	//2. ���������ɶ�¶�����
	CheckCapacity(ps);
	//��������
	printf("����������:>");
	scanf("%s", ps->data[ps->size].name);
	printf("����������:>");
	scanf("%d", &(ps->data[ps->size].age));  //����,Ҫȡ��ַ
	printf("�������Ա�:>");
	scanf("%s", ps->data[ps->size].sex);
	printf("������绰:>");
	scanf("%s", ps->data[ps->size].tele);
	printf("�������ַ:>");
	scanf("%s", ps->data[ps->size].addr);
	ps->size++;
	printf("��ӳɹ�\n");

}

void ShowContact(const struct Contact* ps)
{
	if (ps->size == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
	}
	else
	{
		int i = 0;
		//����
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "סַ");
		//����
		for (i = 0; i < ps->size; i++)
		{
			printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
				ps->data[i].name,
				ps->data[i].age,
				ps->data[i].sex,
				ps->data[i].tele,
				ps->data[i].addr);
		}
	}
}

//��static��ָ�������ֻ������ļ���ʹ��
static int FindByName(const struct Contact* ps, char name[MAX_NAME]) 
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (0 == strcmp(ps->data[i].name,name))
		{
			return i;
		}
	}
	return -1; //�Ҳ��������
}

void DelContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("������Ҫɾ�����˵�����:>");
	scanf("%s", name);
	//1. ����Ҫɾ��������ʲôλ��
	//�ҵ��˷�����������Ԫ�ص��±�
	//�Ҳ������� -1
	int pos = FindByName(ps, name);
	if (pos == -1)
	{
		printf("Ҫɾ�����˲����ڡ���");
	}
	//2. ɾ��
	else
	{
		//ɾ������
		int j = 0;
		for (j = pos; j < ps->size - 1; j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
		printf("ɾ���ɹ�!\n");
	}
}

void SerachContact(const struct Contact* ps)
{
	char name[MAX_NAME];
	printf("������Ҫ���ҵ��˵�����:>");
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (pos == -1)
	{
		printf("����δ�����ҵ�����");
	}
	else
	{
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "סַ");
		printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
			ps->data[pos].name,
			ps->data[pos].age,
			ps->data[pos].sex,
			ps->data[pos].tele,
			ps->data[pos].addr);
	}
}

void ModifyContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("������Ҫ�޸��˵�����:>");
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (pos == -1)
	{
		printf("����������ˡ���\n");
	}
	else
	{
		printf("����������:>");
		scanf("%s", ps->data[pos].name);
		printf("����������:>");
		scanf("%d", &(ps->data[pos].age));
		printf("�������Ա�:>");
		scanf("%s", ps->data[pos].sex);
		printf("������绰:>");
		scanf("%s", ps->data[pos].tele);
		printf("�������ַ:>");
		scanf("%s", ps->data[pos].addr);

		printf("�޸����\n");
	}
}

void DestroyContact(struct Contact* ps)
{
	free(ps->data);
	ps->data = NULL;
}

void SaveContact(struct Contact* ps)
{
	FILE* pfwrite = fopen("contact.dat", "wb");
	if (pfwrite == NULL)
	{
		printf("����ʧ�ܡ���\n");
		printf("SaveContact::%s\n", strerror(errno));  //ǰ��Ӻ�����ָʾ���ⱨ��
		return;   //void���ܷ���0�������
	}
	//д��Ϣ���ļ�
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		fwrite(&(ps->data[i]), sizeof(struct PeoInFo), 1, pfwrite);
	}

	//�ر��ļ�
	fclose(pfwrite);
	pfwrite = NULL;
}