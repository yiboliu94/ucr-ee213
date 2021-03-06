/************************************************************
  	parse_func.c
  	containing parsing functions for SPICE netlist parser example.

Author(s):
   	Shi, Guoyong  2015
 
	Course material for "Introduction to EDA", 2015
   	Dept of Micro/Nano-electronics
   	Shanghai Jiao Tong University (SJTU)
************************************************************/

#ifdef MATLAB
#include "mex.h"
#endif

#include "parse_func.h"
#include "Symbol_Table.h"

// Global variables defined for the parser utility functions
int nRes;
int nCap;
int nInd;
int nVsrc;
int nIsrc;
int nVCCS;


void Init_parse_util()
{
	nRes = 0;
	nCap = 0;
	nInd = 0;
	nVsrc = 0;
	nIsrc = 0;
	nVCCS = 0;
}

void ParseRes(char *name, char *node1, char *node2, double value)
{
	int numnodes;
	Node_Entry **nodelist;
	
	printf("[Resistor parsed ...]\n");
	printf("   name=%s, node+=%s, node-=%s, R=%e\n", name, node1, node2, value);
	nRes++;

	// Save the device, nodes, value info to the symbol tables.
	// Please write your own code here ...
	numnodes=2;
	nodelist=(Node_Entry **)malloc(numnodes*sizeof(Node_Entry*));
	if(Lookup_Node_Entry(node1)!=NULL){
		Node_Entry* t=Lookup_Node_Entry(node1);
		nodelist[0]=t;
	}
	else{
		nodelist[0]=Insert_Node_Entry(node1);
	}
	
	if(Lookup_Node_Entry(node2)!=NULL){
		Node_Entry* t=Lookup_Node_Entry(node2);
		nodelist[1]=t;
	}
	else{
		nodelist[1]=Insert_Node_Entry(node2);
	}
	Insert_Device_Entry(name,numnodes,nodelist,value);
}

void ParseCap(char *name, char *node1, char *node2, double value)
{
	int numnodes;
	Node_Entry **nodelist;
	
	printf("[Capacitor parsed ...]\n");
	printf("   name=%s, node+=%s, node-=%s, C=%e\n", name, node1, node2, value);
	nCap++;

	// Save the device, nodes, value info to the symbol tables.
	// Please write your own code here ...
	numnodes=2;
	nodelist=(Node_Entry **)malloc(numnodes*sizeof(Node_Entry*));
	if(Lookup_Node_Entry(node1)!=NULL){
		Node_Entry* t=Lookup_Node_Entry(node1);
		nodelist[0]=t;
	}
	else{
		nodelist[0]=Insert_Node_Entry(node1);
	}
	
	if(Lookup_Node_Entry(node2)!=NULL){
		Node_Entry* t=Lookup_Node_Entry(node2);
		nodelist[1]=t;
	}
	else{
		nodelist[1]=Insert_Node_Entry(node2);
	}
	Insert_Device_Entry(name,numnodes,nodelist,value);
}

void ParseCapIC(char *name, char *node1, char *node2, double value, double init){}
void ParseIndIC(char *name, char *node1, char *node2, double value, double init){}

void ParseInd(char *name, char *node1, char *node2, double value)
{
	int numnodes;
	Node_Entry **nodelist;
	
	printf("[Inductor parsed ...]\n");
	printf("   name=%s, node+=%s, node-=%s, L=%e\n", name, node1, node2, value);
	nInd++;

	// Save the device, nodes, value info to the symbol tables.
	// Please write your own code here ...
	numnodes=2;
	nodelist=(Node_Entry **)malloc(numnodes*sizeof(Node_Entry*));
	if(Lookup_Node_Entry(node1)!=NULL){
		Node_Entry* t=Lookup_Node_Entry(node1);
		nodelist[0]=t;
	}
	else{
		nodelist[0]=Insert_Node_Entry(node1);
	}
	
	if(Lookup_Node_Entry(node2)!=NULL){
		Node_Entry* t=Lookup_Node_Entry(node2);
		nodelist[1]=t;
	}
	else{
		nodelist[1]=Insert_Node_Entry(node2);
	}
	Insert_Device_Entry(name,numnodes,nodelist,value);
}



void ParseVsrc(char *name, char *node1, char *node2, double value)
{
	int numnodes;
	Node_Entry **nodelist;
	
	printf("[Voltage Source parsed ...]\n");
	printf("   name=%s, node+=%s, node-=%s, V=%e\n", name, node1, node2, value);
	nVsrc++;

	// Save the device, nodes, value info to the symbol tables.
	// Please write your own code here ...
	numnodes=2;
	nodelist=(Node_Entry **)malloc(numnodes*sizeof(Node_Entry*));
	if(Lookup_Node_Entry(node1)!=NULL){
		Node_Entry* t=Lookup_Node_Entry(node1);
		nodelist[0]=t;
	}
	else{
		nodelist[0]=Insert_Node_Entry(node1);
	}
	
	if(Lookup_Node_Entry(node2)!=NULL){
		Node_Entry* t=Lookup_Node_Entry(node2);
		nodelist[1]=t;
	}
	else{
		nodelist[1]=Insert_Node_Entry(node2);
	}
	Insert_Device_Entry(name,numnodes,nodelist,value);
}

void ParseIsrc(char *name, char *node1, char *node2, double value)
{
	int numnodes;
	Node_Entry **nodelist;
	
	printf("[Current source parsed ...]\n");
	printf("   name=%s, node+=%s, node-=%s, I=%e\n", name, node1, node2, value);
	nIsrc++;

	// Save the device, nodes, value info to the symbol tables.
	// Please write your own code here ...
	numnodes=2;
	nodelist=(Node_Entry **)malloc(numnodes*sizeof(Node_Entry*));
	if(Lookup_Node_Entry(node1)!=NULL){
		Node_Entry* t=Lookup_Node_Entry(node1);
		nodelist[0]=t;
	}
	else{
		nodelist[0]=Insert_Node_Entry(node1);
	}
	
	if(Lookup_Node_Entry(node2)!=NULL){
		Node_Entry* t=Lookup_Node_Entry(node2);
		nodelist[1]=t;
	}
	else{
		nodelist[1]=Insert_Node_Entry(node2);
	}
	Insert_Device_Entry(name,numnodes,nodelist,value);

}

void ParseVCCS(char *name, char *node1, char *node2, char *node3, char *node4, double value)
{
	int numnodes;
	Node_Entry **nodelist;
	
	printf("[VCCS parsed ...]\n");
	printf("   name=%s, N+=%s, Ne-=%s,  Nc+=%s, Nc-=%s, G=%e\n", 
			name, node1, node2, node3, node4, value);
	nVCCS++;

	// Save the device, nodes, value info to the symbol tables.
	// Please write your own code here ...
	numnodes=4;
	nodelist=(Node_Entry **)malloc(numnodes*sizeof(Node_Entry*));
	if(Lookup_Node_Entry(node1)!=NULL){
		Node_Entry* t=Lookup_Node_Entry(node1);
		nodelist[0]=t;
	}
	else{
		nodelist[0]=Insert_Node_Entry(node1);
	}
	
	if(Lookup_Node_Entry(node2)!=NULL){
		Node_Entry* t=Lookup_Node_Entry(node2);
		nodelist[1]=t;
	}
	else{
		nodelist[1]=Insert_Node_Entry(node2);
	}
	if(Lookup_Node_Entry(node3)!=NULL){
		Node_Entry* t=Lookup_Node_Entry(node3);
		nodelist[2]=t;
	}
	else{
		nodelist[2]=Insert_Node_Entry(node3);
	}
	
	if(Lookup_Node_Entry(node4)!=NULL){
		Node_Entry* t=Lookup_Node_Entry(node4);
		nodelist[3]=t;
	}
	else{
		nodelist[3]=Insert_Node_Entry(node4);
	}
	Insert_Device_Entry(name,numnodes,nodelist,value);
}


void Summarize()
{
	printf("[Finished parsing netlist!]\n");
	printf("   #res=%d, #cap=%d, #ind=%d, #vccs=%d, #vsrc=%d, #isrc=%d\n", \
		nRes, nCap, nInd, nVCCS, nVsrc, nIsrc);
}
