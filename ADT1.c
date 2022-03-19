//�������ʵ��

#include<stdio.h>
#include<stdlib.h>

//����ṹ��
typedef struct LNode {
	int data;
	struct LNode* next;
}LNode,*ListNode;

//������ͷ
ListNode createHead() {
	ListNode head = (ListNode)malloc(sizeof(LNode));
	head->next = NULL;
	return head;
}

//�������
ListNode createNode() {
	ListNode newNode = (ListNode)malloc(sizeof(LNode));
	printf("����������ֵ��");
	scanf_s("%d", &newNode->data);
	newNode->next = NULL;
	return newNode;
}

//β�巨����ڵ�
void addNode(ListNode head,ListNode newNode) {

	ListNode temp = head;
	while (temp->next!=NULL)
	{
		temp = temp->next;
	}
	temp->next = newNode;
}

//ɾ��ָ��λ�õĽڵ�
void delete(ListNode head,  int index) {
	ListNode move = head->next;
	for (int  i = 1; i <= index; i++)
	{
		move = move->next;
		head = head->next;
	}
	head->next = move->next;
	free(move);
}

//��ָ��λ�ò�����
void insert(ListNode head,  int index) {
	ListNode temp = head->next;
	ListNode newNode = createNode();
	for (int i = 0; i <= index; i++)
	{
		temp = temp->next;
		head = head->next;
	}
	head->next = newNode;
	newNode->next = temp;
}

//��ӡ����
void printList(ListNode head) {
	ListNode temp = head;
	while (temp->next!=NULL)
	{
		temp = temp->next;
		printf("%d\t", temp->data);
	}
	printf("������ɣ�\n");
}

//��������
void deleteList(ListNode head) {
	ListNode front,behind;
	behind = head->next;
	while (behind!=NULL)
	{
		front = behind->next;
		free(behind);
		behind = front;
	}
	head = NULL;
}


int main() {
	ListNode head = createHead();
	for (int i = 0; i < 5; i++)
	{
		ListNode newNode = createNode();
		addNode(head, newNode);
	}
	printList(head);
	delete(head, 2);
	printList(head);
	insert(head,  2);
	printList(head);
	return 0;
}