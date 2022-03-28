#include"D:\VSProgram\Test\ListQueue\LQueue.h"

/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitLQueue(LQueue* Q) {
	Node* head = (Node*)malloc(sizeof(Node));
	if (head == NULL)return;	
	Q->front = Q->rear = head;
	Q->front->next = NULL;
	printf("初始化成功!\n");
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
Status DestoryLQueue(LQueue* Q) {
	if (IsEmptyLQueue(Q) == TRUE)return FALSE;
	while (Q->front!=NULL)
	{
		Q->rear = Q->front->next;
		free(Q->front);
		Q->front = Q->rear;
	}
	return TRUE;
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue* Q) {
	if (Q->front->next==NULL)
	{
		return TRUE;
	}
	return FALSE;
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q e 队列指针Q,返回数据指针e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadLQueue(LQueue* Q) {
	if (IsEmptyLQueue(Q) == TRUE)return FALSE;
	void* temp = Q->front->next->data;
	LPrint(temp);
	return TRUE;
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue* Q) {
	if (IsEmptyLQueue(Q)==TRUE)return 0;
	Node* temp = Q->front;
	int count = 0;
	while (temp->next!=NULL)
	{
		temp = temp->next;
		count++;
	}
	return count;
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否为空
 */
Status EnLQueue(LQueue* Q, void* data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL)return FALSE;
	Node* temp = Q->front;

	newNode->data = data;
	newNode->next = NULL;

	if (IsEmptyLQueue(Q) == TRUE) {
		temp->next = newNode;
		Q->rear = newNode;
		return TRUE;
	}
	/*while (temp->next!=NULL)
	{
		temp = temp->next;
	}*/
	Node* behind = temp->next;
	temp->next = newNode;
	newNode->next = behind;
	Q->rear = newNode;
	return TRUE;
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue* Q) {
	if (IsEmptyLQueue(Q) == TRUE)return FALSE;
	Node* temp = Q->front->next;
	void* ptr = temp->data;
	LPrint(ptr);
	Q->front->next = temp->next;
	if (Q->rear = temp)Q->rear = temp;
	free(temp);
	return TRUE;
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
Status ClearLQueue(LQueue* Q) {
	if (IsEmptyLQueue(Q) == TRUE)return FALSE;
	Q->rear = Q->front;
	return TRUE;
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue* Q, void (*foo)(void* q)) {
	if (IsEmptyLQueue(Q) == TRUE)return FALSE;
	Node* temp = Q->front;
	while (temp->next!=NULL)
	{
		temp = temp->next;
		foo(temp->data);
	}
	return TRUE;
}

/**
 *  @name        : void LPrint(void *q)
 *    @description : 操作函数
 *    @param         q 指针q

 *  @notice      : None
 */
void LPrint(void* q) {
	char* ptr = (char*)q;
	printf("%s\n",ptr);
}

//菜单：
void menu() {
	printf("1.判断队列是否为空\n");
	printf("2.入队\n");
	printf("3.出队\n");
	printf("4.获取队头元素\n");
	printf("5.获取队列长度\n");
	printf("6.清空队列\n");
	printf("7.销毁队列\n");
	printf("8.打印队列\n");
	printf("9.退出\n");
}