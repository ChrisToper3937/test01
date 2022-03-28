#include"D:\VSProgram\Test\ListQueue\LQueue.h"

int main() {

	LQueue* Q = (LQueue*)malloc(sizeof(LQueue));
	InitLQueue(Q);

	int choice=0;
	while (1)
	{
		menu();
		
		printf("\n");
		printf("请输入你的选择：");
		scanf_s("%d", &choice);

		switch (choice)
		{
		case 1: {
			printf("判断队列是否为空?\n");
			int n1 = IsEmptyLQueue(Q);
			if (n1)
			{
				printf("判断队列为空\n");
			}
			else
			{
				printf("判断队列不为空\n");
			}
			break;
		}
		case 2: {
			printf("请输入队列元素的值：");
			char data[100] ;
			scanf_s("%s", data,100);
			int n2 = EnLQueue(Q, (void*)(data));
			if (n2)
			{
				printf("入队成功\n");

			}
			else
			{
				printf("入队失败\n");

			}
			break;
		}
		case 3: {
			int n3 = DeLQueue(Q);
			if (n3)
			{
				printf("出队成功\n");

			}
			else
			{
				printf("出队失败\n");

			}
			break;
		}
		case 4: {
			printf("得到队头元素:\t");
			void* data = NULL;
			int n4= GetHeadLQueue(Q, data);
			if (n4)
			{
				printf("获取成功\n");
			}
			else
			{
				printf("获取失败\n");
			}
			break;
		}
		case 5: {
			printf("检测队列长度\n");
			int length = LengthLQueue(Q);
			if (length)
			{
				printf("获取成功\n");
			}
			else
			{
				printf("获取失败\n");
			}
			printf("队列长度为：%d\n", length);
			break;
		}
		case 6: {
			printf("清空栈\n");
			int n6 = ClearLQueue(Q);
			if (n6)
			{
				printf("清空成功\n");
			}
			else
			{
				printf("清空失败\n");
			}
			break;
		}
		case 7: {
			printf("销毁队列\n");
			int n7 = DestoryLQueue(Q);
			if (n7)
			{
				printf("销毁成功\n");
			}
			else
			{
				printf("销毁失败\n");
			}
			break;
		}
		case 8: {
			printf("打印队列：\n");
			void(*fun)(void*p)=NULL;
			fun = LPrint;
			TraverseLQueue(Q,fun);
			break;
		}
		case 9:
			exit(0);
			break;
		default:
			break;
		}
	}

	return 0;
}