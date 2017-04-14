#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
 struct Vertex
 {
 	int data;
 	struct Edge *edgeList;
 	struct Vertex *nextVertex;
 	int isVisited;

 };
 struct Edge
 {
 	struct Vertex *vertex;
 	struct Edge *nextEdge;
 	int weight;
 };
struct Edge *returnMinEdge(struct Vertex *vertex);

struct Vertex *addVertex(struct Vertex **start,int value);
void addEdge(struct Vertex **start,struct Vertex *v1,struct Vertex *v2,int weight);
struct Vertex *returnVertexAddress(struct Vertex **start,int value);

int main(int argc, char *argv[]) {

	struct Vertex *start=NULL;
struct Vertex* v0=addVertex(&start,0);
struct Vertex *v1=addVertex(&start,1);
struct Vertex *v2=addVertex(&start,2);
struct Vertex *v3=addVertex(&start,3);
struct Vertex *v4=addVertex(&start,4);
struct Vertex *v5=addVertex(&start,5);


           addEdge(&start,v0,v1,4);
           addEdge(&start,v0, v2, 2);
            addEdge(&start,v1,v3,5);
           addEdge(&start,v2,v3,8);
           addEdge(&start,v2, v1, 1);
           addEdge(&start,v2, v4, 10);
           addEdge(&start,v3,v4,2);
           addEdge(&start,v3,v5,6);
           addEdge(&start,v4, v5, 3);
           print(start);
            prims(&start);
            //printf("\n %d",v5->cost);
	return 0;
}

void prims(struct Vertex **start)
{
    struct Vertex *curr=*start;
    int n=0;
    while(curr != NULL)
    {
    n++;
    curr->isVisited=0;
    curr=curr->nextVertex;

    }
    curr=*start;

    int count=0;
    while(count < n -1)
    {
        curr->isVisited=1;
        struct Edge *min=returnMinEdge(curr);
        printf("\n {%d,%d} = %d",curr->data,min->vertex->data,min->weight);
        curr=min->vertex;
        count++;
    }

}
struct Edge *returnMinEdge(struct Vertex *vertex)
{


    struct Edge *curr=vertex->edgeList;
    struct Edge *minEdge=vertex->edgeList;
    while(minEdge->vertex->isVisited==1)
    {
        minEdge=minEdge->nextEdge;
    }
    while(curr != NULL)
    {
        if(curr->weight < minEdge->weight && curr->vertex->isVisited == 0)
        {
            minEdge=curr;
        }
        curr=curr->nextEdge;
    }
    return minEdge;

}


struct Vertex *addVertex(struct Vertex **start,int value)
{
	struct Vertex *temp=(struct Vertex *)malloc(sizeof(struct Vertex));
	temp->data=value;
	temp->edgeList=NULL;
	temp->nextVertex=NULL;


	if((*start)==NULL)
	{
		*start=temp;
	}
	else
	{
		struct Vertex *current=*start;
		while(current->nextVertex!=NULL)
		{
			current=current->nextVertex;
		}
		current->nextVertex=temp;
	}
	return temp;

}

void addEdge(struct Vertex **start,struct Vertex *v1,struct Vertex *v2,int weight)
{
	struct Edge *temp=(struct Edge *)malloc(sizeof(struct Edge));
	temp->vertex=v2;
	temp->weight=weight;
	temp->nextEdge=NULL;

		struct Vertex *vertex=v1;

	if( vertex->edgeList ==NULL)
	{
	vertex->edgeList=temp;
	}
	else
	{

		struct Edge *current=vertex->edgeList;
		while(current->nextEdge !=NULL)
		{

			current=current->nextEdge;
		}
		current->nextEdge=temp;
	}


	struct Vertex *vertex2=v2;

	struct Edge *temp2=(struct Edge *)malloc(sizeof(struct Edge));
	temp2->weight=weight;
	temp2->vertex=v1;
	temp2->nextEdge=NULL;


	if( vertex2->edgeList ==NULL)
	{
	vertex2->edgeList=temp2;
	}
	else
	{
		struct Edge *current=vertex2->edgeList;
		while(current->nextEdge !=NULL)
		{
			current=current->nextEdge;
		}
		current->nextEdge=temp2;
	}

}

void print(struct Vertex *start)
{
	struct Vertex *currV=start;
	while(currV!=NULL)
	{
		printf(" \n %d | ",currV->data);
		struct Edge *edge=currV->edgeList;
		while(edge!=NULL)
		{
			printf(" {%d,%d} ",edge->vertex->data,edge->weight);
			edge=edge->nextEdge;
		}
		currV=currV->nextVertex;
	}
}

