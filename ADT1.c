//单链表的实现

#include<stdio.h>
#include<stdlib.h>

//定义结构体
typedef struct LNode {
	int data;
	struct LNode* next;
}LNode,*ListNode;

//创建表头
ListNode createHead() {
	ListNode head = (ListNode)malloc(sizeof(LNode));
	head->next = NULL;
	return head;
}

//创建结点
ListNode createNode() {
	ListNode newNode = (ListNode)malloc(sizeof(LNode));
	printf("请输入结点数值：");
	scanf_s("%d", &newNode->data);
	newNode->next = NULL;
	return newNode;
}

//尾插法插入节点
void addNode(ListNode head,ListNode newNode) {

	ListNode temp = head;
	while (temp->next!=NULL)
	{
		temp = temp->next;
	}
	temp->next = newNode;
}

//删除指定位置的节点
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

//在指定位置插入结点
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

//打印链表
void printList(ListNode head) {
	ListNode temp = head;
	while (temp->next!=NULL)
	{
		temp = temp->next;
		printf("%d\t", temp->data);
	}
	printf("遍历完成！\n");
}

//销毁链表
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