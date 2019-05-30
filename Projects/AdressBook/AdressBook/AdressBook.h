#ifndef _ADRESSBOOK_H_
#define _ADRESSBOOK_H_

#include<stdio.h>
#include<errno.h>
#include<string.h>
#include<stdlib.h>

#define NAME_SIZE 32
#define TEL_SIZE 15
#define ADDR_SIZE 256

#define DEFAULT 5
typedef struct person//�˽ṹ��
{
	char name[NAME_SIZE];
	char sex;//'f','m'
	unsigned char age;
	char telephone[TEL_SIZE];
	char address[ADDR_SIZE];
}person_t,*person_p,**person_pp;

typedef struct//ͨѶ¼�ṹ��
{
	int cap;//�������
	int size;//��ǰ������
	person_t plist[0];
}contact_t, *contact_p;
void Menu();

void InitAdressBook(contact_t **pct);
void ShowAdressBook();
void DestoryAdressBook(contact_p ct);
void ClearAdressBook();
void SortAdressBook();

void AddAdressBook(contact_p ct);
void DelAdressBook();
void SearchAdressBook();
void ModAdressBook()


#endif
