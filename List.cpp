#include "List.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
 
ifstream fin;
ofstream out;
 
//Default constructor to initialize all values 
List::List()
{
		head=NULL;
		currentRow=NULL;
		currentNode = NULL;
		maxI=1;
		maxJ=1;
		i=1;
		j=1;
		rowcount=1;
		tempVal=0;
		input=" ";

}

//destructor
List::~List()
{
	Row *rTemp=NULL;
	node *nTemp=NULL;
	
	currentRow=head;
	currentNode=currentRow->headNode;
	
	while(currentRow!=NULL)
	{	
		currentNode=currentRow->headNode;

		while(currentNode!=NULL)
		{
			nTemp=currentNode;
			currentNode=currentNode->nodeLink;
			delete nTemp;
		}
		
		rTemp=currentRow;
		currentRow=currentRow->nextRow;
		delete rTemp;
	}
}


/******************************************************
Receives input from filename passed as argument
does error checking to make sure input is valid.
then stores the iValue, jValue, and value into a node
which is then inserted in the list             
*******************************************************/
void List::readFile(char* file)
{
	fin.open(file);
	int line=0;
	
	if(fin.fail())
		cout<<"*Failed to open file* \n";
	
	
	while(!fin.eof())
	{
		
		++line;
		
	
		getline(fin, input);
		
		if(input=="")
			continue;
		
		if(input[0]=='#')
			continue;
			
		istringstream parse(input);
		
		
		
		if(!(parse>> i >> j >> tempVal))
		{
			cout<<"Line "<<line<<" input error\n";
			continue;
		}
		
		parse>> i >> j >> tempVal;
		
		if(i<=0)
		{
			cout<<"Line "<<line<<" negative i entry\n";
			continue;
		}
		
		if(j<=0)
		{
			cout<<"Line "<<line<<" negative j entry\n";
			continue;	
		}
	
		if(j>maxJ)
			maxJ=j;
			
		
		if(currentRow==NULL || i>maxI)
		{
			maxI=i;
			rowcount++;
			
			newRow = new Row(i,j,tempVal);
			newRow->addNode();
			
			if(head==NULL)
			{
				head=newRow;
				currentRow=newRow;
				currentNode=newRow->newEntry;
			}
			else
			{	
				currentRow->nextRow=newRow;
				currentRow=newRow;	
				currentNode=newRow->newEntry;
			}	
		}
		else
		{
			newNode = new node(i,j,tempVal);
			currentNode->nodeLink=newNode;	
			currentNode=newNode;
		}
	}
	
	fin.close();
}

void List::addEntry(int i, int j, double tempVal)
{
	if(currentRow==NULL || i>maxI)
	{
		maxI=i;
		rowcount++;
			
		newRow = new Row(i,j,tempVal);
			
		newRow->addNode();
			
		if(head==NULL)
		{
				
			head=newRow;
			currentRow=newRow;
			currentNode=newRow->newEntry;
				
		}
		else
		{	
			currentRow->nextRow=newRow;
			currentRow=newRow;
			currentNode=newRow->newEntry;
		}
			
	}
		else
		{	
			newNode = new node(i,j,tempVal);
			currentNode->nodeLink=newNode;
			currentNode=newNode;
		}




}
/******************************************
function to print Matrix recieved as input
prints matrix in sparse list form
*******************************************/
void List::printScreen()
{
	setNodes();
	
	while(currentRow!=NULL)
	{	
		currentNode=currentRow->headNode;
	
		while(currentNode!=NULL)
		{
			
			cout<<currentNode->iValue<<" "<<currentNode->jValue<<" "<<currentNode->value<<endl;
		
			currentNode=currentNode->nodeLink;
		}
		
		currentRow=currentRow->nextRow;
	}
 
	if(search(maxI,maxJ)==0)
	{
		cout << maxI << " " << maxJ << " 0\n";
	}

}

void List::printFile(char *file)
{
	setNodes();
	if(currentNode==NULL)
		return;
	
	out.open(file);
	
	out<<"#Matrix C\n";
	out<<"#Linked List\n";
	
	if(out.fail())
		cout<<"\n*Error opening output file\n";
		
	while(currentRow!=NULL)
	{	
		currentNode=currentRow->headNode;
	
		while(currentNode!=NULL)
		{
			if(currentNode->value!=0)
			out<<currentNode->iValue<<" "<<currentNode->jValue<<" "<<currentNode->value<<endl;
		
			currentNode=currentNode->nodeLink;
		}
		
		currentRow=currentRow->nextRow;
	}
 
	if(search(maxI,maxJ)==0)
	{
		out << maxI << " " << maxJ << " 0\n";
	}
	
	out.close();
}

/**********************************************************
search function to find if 2 given indexes are in the list
if they are found they return value, if not it returns 0
***********************************************************/
double List::search(int i,int j)
{
	currentRow=head;
	currentNode=currentRow->headNode;
	
	
	while(currentRow!=NULL)
	{	
		currentNode=currentRow->headNode;

		while(currentNode!=NULL)
		{
			if((currentNode->iValue==i) && (currentNode->jValue==j))
			{	
				return currentNode->value;
			}
			currentNode=currentNode->nodeLink;
		}
	
		currentRow=currentRow->nextRow;
	
	}

	return 0.0;
}

//sets the traversal nodes to the top of the list
void List::setNodes()
{
	currentRow=head;
	currentNode=currentRow->headNode;
}

/*******************************************************
function to multiply the two matrices
uses the O(n^3) algorithm but it also calls the search function
for every iterations to not very efficient
only prints to file if the multiplication is not 0
*******************************************************/
void List::multiply(List& listB, char *file)
{
	out.open(file);
	double aVal;
	double bVal;
	double tempval=0.0;
	
	out<<"#Matrix C\n";
	out<<"#Linked List\n";
	
	if(maxJ != listB.maxI)
		{
			cout<<"Invalid matrix dimensions\n";
			cout<<"cannot multiply matrices\n";
		}
	else
	{
		for (int i = 1 ; i <= maxI; i++)
		{	
			for (int j = 1;  j <= listB.maxJ; j++)
			{	
				for (int k = 1; k <= maxJ; k++)
				{	
					aVal=search(i,k);
					bVal=listB.search(k,j);
					
					tempval+=aVal*bVal;					
				}
				
				if(tempval!=0)
				{
					out<<i<<" "<<j<<" "<<tempval<<endl;
					tempval=0;
				
				}
			}
		}
	}
	
	out.close();
}

/***********************************************
	Linked list function to add matrices 
	recursively.  takes 3 lists as arguments
	with the first subscripts of a matrix
	and creates a new list for the result
	of the sum 
************************************************/
void List::addMatx(List &A, List &B, List &C, int i, int j)
{
	double sum;
	double tempA, tempB;
	
	if((A.maxI!=B.maxI) || (A.maxJ!=B.maxJ))
	{
		cout<<"\nCan not add matrices of different size\n";
		return;
	}
	else if(((i>A.maxI) && (i>B.maxI)) || ((j>A.maxJ) && (j>B.maxJ)))
	{	
		C.maxI=A.maxI;
		C.maxJ=B.maxJ;
		return;
	}
	else
	{	
		tempA=A.search(i,j);
		tempB=B.search(i,j);
		
		sum=tempA+tempB;
		
		if(i==maxI && j==maxJ)
		{
			if(sum==0)
				C.addEntry(i,j,sum);
		}
		
		if(sum!=0)
		{
			C.addEntry(i,j,sum);
			
			if(j==maxJ)
			{	
				j=1;
				addMatx(A,B,C,i+1,j);
			}
			else
			{
				addMatx(A,B,C,i,j+1);
			}
		}
		else 
		{
			if(j==maxJ)
			{	
				j=1;
				addMatx(A,B,C,i+1,j);		
			}
			else
			{
				addMatx(A,B,C,i,j+1);
			}
		}
	}
}












