#include "stdio.h"
#include "stdlib.h"

typedef int elememtType;

typedef struct node {
	int data;
	struct node *next;
}LNode, *linkList;

linkList init() {
	linkList p, q = NULL, head = NULL;
	elememtType e;
	printf("请输入添加到链表中的数据,0表示结束\n");
	scanf("%d", &e);
	while (e) {
		if (!e) {
			break;
		}
		p = (linkList)malloc(sizeof(LNode));
		p->data = e;
		p->next = NULL;
		if (head == NULL) {
			head = q = p;
		}
		else {
			q->next = p;
			q = p;
		}
		scanf("%d", &e);
	}
	printf("链表创建成功\n");
	return head;

}


linkList search(linkList list, elememtType data) {
	linkList p;
	p = list;
	while (p) {
		if (p->data == data) {
			break;
		}
		p = p->next;
	}
	return p;
}



void insert(linkList p, elememtType data) {
	linkList q;
	q = (linkList)malloc(sizeof(LNode));
	q->data = data;
	q->next = p->next;
	p->next = q;

}


void update(linkList p, elememtType data) {
	p->data = data;
}

void del(linkList *list, linkList p) {
	linkList q;
	if (*list == p) {
		*list = p->next;
		free(p);
	}
	else {
		for (q = *list; q->next != NULL; q = q->next) {
			if (q->next == p) {
				q->next = p->next;
				free(p);
			}
		}
	}
}


void destroy(linkList *list) {
	linkList p, q;
	p = *list;
	while (p) {
		q = p->next;
		free(p);
		p = q;
	}
	*list = NULL;
	printf("数据删除成功\n");
}

void printList(linkList p) {

	if (p == NULL) {
		printf("没有数据\n");
	}

	while (p) {
		printf("%d\n", p->data);
		p = p->next;
	}
}

void printMenu() {
	printf("c:创建\n");
	printf("i:插入数据\n");
	printf("s:查找数据\n");
	printf("u:更新数据\n");
	printf("d:删除单条数据\n");
	printf("D:删除所有数据\n");
	printf("p:打印数据\n");
	printf("m:显示菜单\n");
	printf("q:退出\n");
}

int main()
{
	char s;
	linkList list = NULL;
	linkList p = NULL;
	elememtType data, newData;
	printMenu();
	while (1) {
		s = getchar();
		if (s == 'q') {
			printf("程序即将退出");
			break;
		}
		switch (s)
		{
		case 'c':
			list = init();
			break;
		case 'i':
			printf("请输入新增加的数据,如11,22\n");
			scanf("%d,%d", &data, &newData);
			p = search(list, data);
			insert(p, newData);
			break;
		case 's':
			printf("请输入需要查找的数据");
			scanf("%d", &data);
			p = search(list, data);
			if (p) {
				printf("查找数据成功，数据为%d\n", p->data);
			}
			else {
				printf("数据不存在\n");
			}
			break;
		case 'u':
			printf("请输入要替换的数据,如11,90\n");
			scanf("%d,%d", &data, &newData);
			p = search(list, data);
			update(list, newData);
			break;
		case 'd':
			printf("请输入要删除的数据");
			scanf("%d", &data);
			p = search(list, data);
			del(&list, p);
			break;
		case 'D':
			destroy(&list);
			break;
		case 'p':
			printList(list);
			break;
		case 'm':
			printMenu();
			break;
		default:
			break;;
		}
	}
	system("pause");
}

