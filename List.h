#include "Row.h"
#include <string>
#include <iostream>
using namespace std;

class List
{	
	public:
		
		Row *head;
		Row *newRow;
		node *newNode;
		Row *currentRow;
		node *currentNode;
		node *cHead;
		int maxI;
		int maxJ;
		int i;
		int j;
		int rowcount;
		double tempVal;
		string input;
		
		List();
		~List();
		void readFile(char *);
		void addEntry(int,int,double);
		double search(int,int);
		void printScreen();
		void printFile(char*);
		void setNodes();
		void multiply(List&, char*);
		void addMatx(List&,List&,List&,int,int);
	


};