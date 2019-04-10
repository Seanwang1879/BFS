#include<stdio.h>
//数组表示法(领接矩阵实现)
#define MAXN  20

typedef struct{
	char vertec[MAXN];
	char arcs[MAXN][MAXN];
}ArrayGraph;


typedef struct node{
	int vertec;
	struct node *next;
}*NODE;

typedef struct{
	NODE front, rear;
}QueueGraph;

void InitQueue(QueueGraph *Q)
{
	NODE node = (NODE)malloc(sizeof(NODE));
	if(!node){
		return ;
	}
	Q->front = Q->rear = node;

	return ;
}

void push(QueueGraph *Q, char vertec)
{
	NODE node = (NODE)malloc(sizeof(NODE));
	if(!node){
		return ;
	}
	
	node->vertec = vertec;
	Q->rear->next = node;
	Q->rear = Q->rear->next;
	
	return ;
}

int pop(QueueGraph *Q)
{
	if(Q->front == Q->rear){
		return ; 
	}
	
	int data;
	NODE node;
	node = Q->front;
	Q->front = Q->front->next;

	data = node->vertec;
	free(node);
	
	return data;
}

void Init_G(ArrayGraph *G, int nums)
{
	int i,j;
	
	for(i=0; i<nums; i++){
		for(j=0; j<nums; j++){
			G->arcs[i][j] = 0;
		}
	}
	
	return ;
}

void Creat_G(ArrayGraph *G, int nums)
{
	int i, j;
	int k=0;

	while(k!=nums){
		scanf("%c",&G->vertec[k]);
	}
	for(i=0; i<nums; i++){
		for(j=i+1; j<nums; j++){
			scanf("%d%d", &G->arcs[i][j]);
			G->arcs[j][i] = G->arcs[i][j];
		}
	}
	
	return ;
}

void BFS(ArrayGraph *G, int nums, int start, int *visit)
{
	if(G!=NULL || nums<1 || start<0 || visit==NULL){
		return ;
	}

	int i;
	InitQueue *Q;
	visit[start] = 1;
	printf("this node is %c\n", G->vertec[start]);
	InitQueue(Q);
	push(Q, G->vertec[start]);
	while(Q->front != Q->rear){
		start = pop(G);

		for(i=0; i<nums; i++){
			if(G->arcs[start][i]!=0&&visit[i]==0){
				printf("this node is %c\n", G->vertec[i]);
				visit[i] = 1;
				push(Q, G->vertec[i]);
			}
		}
	}
	return ;
}

void main()
{
	ArrayGraph G;
	int visit[MAXN];
	int start;

	printf("please neter nums\n");
	scanf("%d", &nums);
	Init_G(&G, nums);
	Creat_G(&G, nums);

	printf("please neter start\n");
	scanf("%d", &start);
	BFS(&G, nums, start, visit);
	
	return ;
}