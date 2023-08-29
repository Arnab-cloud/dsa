#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int val;
	struct node *next;
}node;

typedef struct graph
{
	int num;
	node** adjList;
}graph;

node* createNode(int val)
{
	node* new = (node*)malloc(sizeof(node));
	new->val = val;
	new->next = NULL;
	return new;
}

graph* createGraph(int numVertices)
{
	graph* newGraph = (graph*)malloc(sizeof(graph));
	
	newGraph->num = numVertices;
	newGraph->adjList = (node**)malloc(sizeof(node*)*numVertices);
	for(int i=0; i<numVertices; i++)
		newGraph->adjList[i] = NULL;
	
	return newGraph;
}

void addEdge(graph* G, int src, int dest)
{
	node* newNode = createNode(dest);
	newNode->next = G->adjList[src];
	G->adjList[src] = newNode;
	
	newNode = createNode(src);
	newNode->next = G->adjList[dest];
	G->adjList[dest] = newNode;
}

void printGraph(graph* G)
{
	for(int i=0; i<G->num; i++)
	{
		node* temp = G->adjList[i];
		printf("Adjacency list of vertex %d:\n", i+1);
		while(temp)
		{	
			printf("%d -> ", temp->val);
			temp = temp->next;
		}
		printf("NULL\n");
	}
}

void freeLinkedList(node* head)
{
	if(head)
	{
		freeLinkedList(head->next);
		free(head);
	}	
}

void freeGraph(graph* G)
{
	for(int i=0; i<G->num; i++)
		freeLinkedList(G->adjList[i]);
	free(G->adjList);
	free(G);	
}

int main()
{
	graph* G = createGraph(6);
	
	addEdge(G, 0, 1);
	/*addEdge(G, 0, 2);
	addEdge(G, 1, 2);
	addEdge(G, 1, 4);
	addEdge(G, 1, 3);
	addEdge(G, 2, 4);
	addEdge(G, 3, 4);
	addEdge(G, 4, 6);
	addEdge(G, 5, 1);
	*/
	addEdge(G, 5, 6);
			
	printGraph(G);
	
	freeGraph(G); 
	return 0;
}
