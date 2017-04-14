#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
 struct Vertex
 {
 	int data;
 	struct Edge *edgeList;
 	struct Vertex *nextVertex;
 	int isVisited;
 	int cost;
 };
 struct Edge
 {
 	struct Vertex *vertex;
 	struct Edge *nextEdge;
 	int weight;
 };
struct Vertex *minCostEdge(struct Vertex *v);
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
            dijkstras(&start);

            //printf("\n %d",v5->cost);
	return 0;
}



void dijkstras(struct Vertex **src)
        {
           struct Vertex *curr = *src;
            int n=0;
            while (curr != NULL)
            {
                n++; // counting number of vertices
                curr->cost = 99;  // 99 means is infinity
                curr->isVisited=0;
                curr = curr->nextVertex;
            }

            (*src)->cost = 0; // jahan se start kar rahe hain us jagha ka distance 0 rakhengy q k us jgha se us jgha k ahi koi distance nhe hoga

            int count = 0;
            curr=*src;
           // curr.isVisited = true;
            while (count < n-1)
            {
                curr->isVisited = 1;
                struct Edge *edge = curr->edgeList;

                while (edge != NULL)
                {
                    if ((curr->cost + edge->weight) < edge->vertex->cost && edge->vertex->cost != 0 && edge->vertex->isVisited==0)
                    {
                        edge->vertex->cost = curr->cost + edge->weight;

                    }
                    edge = edge->nextEdge;
                }

                curr = minCostEdge(curr);
                printf("\n cost of %d is %d",curr->data,curr->cost);
                count++;
            }


        }

         struct Vertex *minCostEdge(struct Vertex *v)
        {
            struct Vertex *curr = v;
            struct Edge *edge = curr->edgeList;
           struct Vertex *min=edge->vertex;
            if (min->cost == 0) min = edge->nextEdge->vertex;
            while (min->isVisited == 1)//edge.nextEdge.vertex;
            {
                edge = edge->nextEdge;
                min = edge->vertex;
            }
                while (edge != NULL)
            {
                if ( edge->vertex->cost <= min->cost && edge->vertex->isVisited == 0 && edge->vertex->cost != 0)
                {
                    min = edge->vertex;

                }
                edge = edge->nextEdge;
            }
            return min;

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
			printf(" %d ",edge->vertex->data);
			edge=edge->nextEdge;
		}
		currV=currV->nextVertex;
	}
}
struct Vertex *returnVertexAddress(struct Vertex **start,int value)
{
	struct Vertex *curr=*start;
	while(curr!=NULL)
	{
		if(curr->data == value)
		return curr;

		curr=curr->nextVertex;
	}
	return NULL;
}
