//反转链表

#include<stdio.h>
#include<stdlib.h>

typedef struct LNode {
	int data;
	struct LNode* next;
}Node,*List;

List createHead() {
	List head = (List)malloc(sizeof(Node));
	if (head == NULL)return;
	head->next = NULL;
	return head;
}

List createNode() {
	List newNode = (List)malloc(sizeof(Node));
	if (newNode == NULL)return;
	printf("请输入结点数值：");
	scanf_s("%d", &newNode->data);
	newNode->next = NULL;
	return newNode;
}

void addNode(List head, List newNode) {
	
		List temp = head;
		while (temp->next!=NULL)
		{
			temp = temp->next;
		}
		temp->next = newNode;
}

void printList(List head) {
		List temp = head;
		while (temp->next!=NULL)
		{
			temp = temp->next;
			printf("%d\t", temp->data);
		}
		printf("遍历完成！\n");
}

List reverse(List head) {
	if (head==NULL||head->next==NULL)
	{
		return head;
	}
	List newNode = reverse(head->next);
	head->next->next = head;

	head->next = NULL;
	return newNode;
}

int main() {
	List head = createHead();
	printf("%p", head);
	for (int i = 0; i < 5; i++)
	{
		List newNode = createNode();
		addNode(head, newNode);
	}
	printList(head);
	List newHead = (List)malloc(sizeof(Node));
	if (newHead == NULL)return;
	newHead->next = reverse(head->next);
	printList(newHead);
	
}

