/////////////////    Adjcency Matrix Implementation     //////////////////////
#include<stdio.h>
#include<stdlib.h>

//---------------------------------------------------------------------------//

typedef struct adjmtx{
	int Weight;							//please initialise 
	int Visited;						//	"		"
	}adjmtx;
	
typedef struct dijkstras{
	int origin;
	int weight;
	}dijk;

typedef struct kruscals{
	int x;
	int y;
	int Weight;
	}kruscals;
	
typedef struct ll{
	struct ll*next;
	int current;
	int previous;
	}ll;
	
//---------------------------------------------------------------------------//
/*
  Function Initialise the Adjcency matrix;
  
  ::Note This is a complete MATRIX based implementation
   
  initialing a matrix and returning a double pointer
  to traverse first move to holder[node1][node2]
*/

adjmtx** initialise(int nodes){
	adjmtx** holder;
	holder = malloc(sizeof(adjmtx*)*nodes);
		if (holder == NULL) return;	
	
	int i,j;
	for(i=0;i<nodes;i++){
		holder[i]=malloc(sizeof(adjmtx)*nodes);
		for(j=0;j<nodes;j++){
			holder[i][j].Weight=-1;
			holder[i][j].Visited=0;
			}
		}
	return holder;
	}
	
/* Function Add Edge on the adjcency matrix  */

void addedge(adjmtx** holder,int nodes,int node1,int node2,int directed,int weight){
	if(node1>=nodes||node2>=nodes)
		return;
	holder[node1][node2].Weight = weight;
	if(directed==0){
		holder[node2][node1].Weight = weight;
		}
	}
		
	
/* Function Delete Edge  */

void deledge(adjmtx** holder,int nodes,int node1,int node2,int directed){
	if(node1>=nodes||node2>=nodes)
		return;	
	holder[node1][node2].Weight = -1;
	if(directed==0)
		holder[node2][node1].Weight = -1;
	}
	
// Function Print in list form 
void printmtx(adjmtx** holder,int nodes){
	int i,j;
	for(i=0;i<nodes;i++){
		for(j=0;j<nodes;j++){
			if(holder[i][j].Weight!=-1){
				if(holder[i][j].Weight==holder[j][i].Weight){
					if(j>i)
						printf("%d<---%d--->%d\n",i,holder[i][j].Weight,j);
					}				
				else
					printf("%d----%d--->%d\n",i,holder[i][j].Weight,j);
				}
			}
		}
	}
// debug print matrix
void printer(adjmtx** matrix, int nodes){
	int i,j;
	for(i=0;i<nodes;i++){
		for(j=0;j<nodes;j++){
			if(matrix[i][j].Weight!=-1)
				printf("%2d",matrix[i][j].Weight);
			else printf("--");
			}
		printf("\n");
		}
	}

// int has been visited
int visited(adjmtx** matrix,int nodes,int node){
	int i;
	for(i=0;i<nodes;i++){
		if(matrix[node][i].Visited!=0)
			return 0;
		}
	return 1;
	}	
/*/// Dijkstras Algorithm
adjmtx** dijkstras(adjmtx** matrix,int nodes){
	int i,j,k;	
	int current;
	int previous;
	ll* queue= NULL;
	adjmtx** output = initialise(nodes);
	dijk* array=malloc(sizeof(dijk)*nodes);
	for(i=0;i<nodes;i++){
		array[i].weight=100000000;// setting to a relative infinity
		array[i].origin=0;
		}
	// add zero to the queue	
	array[0].weight=0;
	array[0].origin=0;
	// algo
	add(&queue,0,0);	//FIXME basically add 0,0 to the queue , then go into the do while, there run the if condition i.e. ignore self edge/ edge to the previous node, and only bother changing the dijkstras array id theres a reduction in lenght, if reduction in lenght add the next node into the queue and keep evaluating till the queue is empty then let the arrray to matrix function which is working properly do the rest ,, the non commented dijkstras has a bug 
	printf("lelele");
	do{
	current = queue->current;
	previous= queue->previous;
	for(i=0;i<nodes;i++){
		if((i!= current)&&(i!= previous)&&(array[i].weight>array[current].weight+matrix[current][i].Weight)){
			array[i].weight = array[current].weight+matrix[current][i].Weight;
			array[i].origin = current;
			add(&queue,i,current);
			}	
		}
	delete(&queue);
	}
	while(notempty(queue));
	// compile return adjcency matrix	
	for(j=1;j<nodes;j++){	
		output[(array[j].origin)][j].Weight=matrix[(array[j].origin)][j].Weight;
		}
	return output;
	}

*/
/// Dijkstras Algorithm
adjmtx** dijkstras(adjmtx** matrix,int nodes){
	int i,j,k;	
	adjmtx** output = initialise(nodes);
	dijk* array=malloc(sizeof(dijk)*nodes);
	for(i=0;i<nodes;i++){
		array[i].weight=100000000;// setting to a relative infinity
		array[i].origin=0;
		}
		
	array[0].weight=0;
	array[0].origin=0;

	for(i=0;i<nodes;i++){
		for(j=0;j<nodes;j++){
			if(i!=j&& matrix[i][j].Weight!=-1){	
				if(array[j].weight>array[i].weight+matrix[i][j].Weight){
					array[j].weight = array[i].weight+matrix[i][j].Weight;
					array[j].origin = i;
					}
				}
			}
		}
	// compile return adjcency matrix	
	for(j=1;j<nodes;j++){	
		output[(array[j].origin)][j].Weight=matrix[(array[j].origin)][j].Weight;
		}
	return output;
	}

	
//// Kruscals Algorithm
adjmtx** kruscal(adjmtx** matrix,int nodes){
	int i,j,k=0;
	kruscals* array = malloc(sizeof(kruscals)*(nodes*nodes));
	for(i=0;i<nodes*nodes;i++){
		array[i].x=-1;
		array[i].y=-1;
		array[i].Weight=-1;
		}		
	// collect edges
	k=0;
	for(i=0;i<nodes;i++){
		for(j=0;j<nodes;j++){
			if(matrix[i][j].Weight!=-1){
				array[k].x=i;
				array[k].y=j;
				array[k].Weight=matrix[i][j].Weight;
				k++;
				}
			}
		}
	//sort edges
	kruscals temp;
	for(i=0;array[i].Weight!=-1;i++){
		for(j=i+1;array[j].Weight!=-1;j++){
			if(array[j].Weight<array[i].Weight){
				temp = array[j];
				array[j]=array[i];
				array[i]=temp;
				}
			}
		}
	//rebuild new adjcency matrix
	adjmtx** output = initialise(nodes);
	//output[array[0].x][array[0].y].Visited=1;
	//output[array[0].x][array[0].y].Weight=array[0].Weight;
	for(i=0;array[i].Weight!=-1;i++){
		if(visited(output,nodes,array[i].y)*visited(output,nodes,array[i].x)==1){ // FIXME THE OPERATOR LOGIC INSIDE
			output[array[i].x][array[i].y].Visited=1;
			output[array[i].x][array[i].y].Weight=array[i].Weight;
			}
		}
	return output;
	}


//// main();

int main (){
	int nodes=5,i=0,j=19,k=0,l=1;
	adjmtx** Graph = initialise(nodes);
	adjmtx** dijkstr;
	adjmtx** krusc;
	addedge(Graph,nodes,0,1,0,1);
	addedge(Graph,nodes,1,2,0,3);
	addedge(Graph,nodes,2,3,0,5);
	addedge(Graph,nodes,3,4,0,5);
	addedge(Graph,nodes,4,0,0,1);
	addedge(Graph,nodes,4,1,0,1);
	addedge(Graph,nodes,2,4,0,7);//matrix,nodes,node1,node2,directedness,weight
	printmtx(Graph,nodes);
	deledge(Graph,nodes,4,3,1);
	printer(Graph,nodes);
	printf("\n\n");
	//i=0;
	//deledge(Graph,nodes,i,j,k);//matrix,nodes,node1,node2,directedness
	dijkstr=dijkstras(Graph,nodes);
	printf("\n");
	printer(dijkstr,nodes);
	printf("\n");
	krusc = kruscal(Graph,nodes);
	printer(krusc,nodes);
	return 1;
	}

