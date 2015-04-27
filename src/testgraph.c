#include "graph.h"

int main(int argc, char *argv[]){
	//initnodes();
	//initgui(argc, argv);
	//makegraph();
	setNodes();
	Graph = initialise();
	addedge(Graph,0,1,0,2);
	addedge(Graph,1,2,0,3);
	addedge(Graph,2,3,0,5);
	addedge(Graph,3,4,0,5);
	addedge(Graph,4,0,0,1);
	addedge(Graph,4,1,0,1);
	addedge(Graph,2,4,0,7);//matrix,nodes,node1,node2,directedness,weight
	printer(Graph);
	
	initnodes();
	initgui(argc, argv);
	setShowWeights(1);
	makegraph(Graph);
	
	gedge** krusc = initialise();
	krusc = kruscal(Graph);
	printer(krusc);
	//makegraph(krusc);
	
	/*
	printmtx(Graph);
	printf("\n\n");
	
	gedge** dijkstr;
	gedge** krusc;
	//i=0;
	//dijkstr=dijkstras(Graph,nodes);
	printf("\n");
	//printer(dijkstr,nodes);
	printf("\n");
	krusc = kruscal(Graph);
	printer(krusc);
	*/
    return 1;
}
