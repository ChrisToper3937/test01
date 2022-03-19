//ʵ��˫������

#include<stdio.h>
#include<stdlib.h>

typedef struct DualNode {
	int data;
	struct DualNode* prior;
	struct DualNode* next;
}DualNode,*DualList;

DualList createList() {
	DualList head = (DualList)malloc(sizeof(DualNode));
	if (head == NULL)return;
	head->prior = head->next = NULL;
	return head;
}

DualList createNode() {
	DualList newNode = (DualList)malloc(sizeof(DualNode));
	if (newNode == NULL)return;
	printf("���������ֵ��");
	scanf_s("%d", &newNode->data);
	newNode->prior = newNode->next = NULL;
	return newNode;
}

void addNode(DualList head) {
		DualList temp = head;
		while (temp->next)
		{
			temp = temp->next;
		}
		DualList newNode = createNode();
		temp->next = newNode;
		newNode->prior = temp;
		printf("������\n");
}

void insertNode(DualList head, int index) {
	
	printf("����ɹ�\n");
}

void deleteNode(DualList head, int index) {
	DualList temp = head;
	if (temp->next == NULL) {
		printf("��Ϊ�գ��޷�ɾ��");
		return;
	}
	for (int i = 0; i <=index; i++)
	{
		temp = temp->next;
	}
	temp->prior->next = temp->next;
	temp->next->prior = temp->prior;
	free(temp);
	printf("ɾ���ɹ�\n");
}

void printList(DualList head) {
	DualList temp = head;
	while (temp->next)
	{
		temp = temp->next;
		printf("%d\t", temp->data);
		
	}
	printf("��ӡ���\n");
}

int main() {

	DualList head = createList();
	for (int i = 0; i < 5; i++)
	{
		addNode(head);
	}
	printList(head);
	deleteNode(head, 3);
	printList(head);
	return 0;
}