//实现双向链表

#include<stdio.h>
#include<stdlib.h>

//初始化结构体
typedef struct DualNode {
	int data;
	struct DualNode* prior;
	struct DualNode* next;
}DualNode,*DualList;

//创建头结点
DualList createList() {
	DualList head = (DualList)malloc(sizeof(DualNode));
	if (head == NULL)return;
	head->prior = head->next = NULL;
	return head;
}

//创建结点
DualList createNode() {
	DualList newNode = (DualList)malloc(sizeof(DualNode));
	if (newNode == NULL)return;
	printf("请输入结点的值：");
	scanf_s("%d", &newNode->data);
	newNode->prior = newNode->next = NULL;
	return newNode;
}

//尾插法插入结点
void addNode(DualList head) {
		DualList temp = head;
		while (temp->next)
		{
			temp = temp->next;
		}
		DualList newNode = createNode();
		temp->next = newNode;
		newNode->prior = temp;
		printf("添加完毕\n");
}

//删除结点
void deleteNode(DualList head, int index) {
	DualList temp = head;
	if (temp->next == NULL) {
		printf("表为空，无法删除");
		return;
	}
	for (int i = 0; i <=index; i++)
	{
		temp = temp->next;
	}
	temp->prior->next = temp->next;
	temp->next->prior = temp->prior;
	free(temp);
	printf("删除成功\n");
}

//打印节点
void printList(DualList head) {
	DualList temp = head;
	while (temp->next)
	{
		temp = temp->next;
		printf("%d\t", temp->data);
		
	}
	printf("打印完成\n");
}

//简单的测试功能
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