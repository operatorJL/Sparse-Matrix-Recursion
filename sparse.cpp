//Joel Loucks
//1033681
#include <iostream>
#include <fstream>
#include <string>
#include "clp.h"
#include "MatrixArray.h"
#include "List.h"
using namespace std; 

ofstream zeroMat;

int main(int argc,char** argv)
{
	CommandLineParser clp(argv[1],';');  
	
	char *v1 = clp.extract("A");
	char *v2 = clp.extract("B");
	char *v3 = clp.extract("result");
	char *v4 = clp.extract("storage");
	char *v5 = clp.extract("operation");
	

	if(v1 == NULL ) {
		cout<<"There is no file1 name!\n";
	}
	if(v2 ==NULL){
		cout<<"There is no file2 name!\n";
	}
	if(v3 == NULL){
		cout<<"There is no file3 name!\n";
	}
	if(v4 == NULL){
		cout<<"Array assumed\n";
	}
	if(v5 == NULL){
		cout<<"Addition assumed\n";
	}

	string storage = v4;
	string operation = v5;
	
	//determines which algorithm to run from the command line 
	if((storage == "array") && (operation == "multiply"))
	{
		MatrixArray A,B,C;
		
		A.readFile(v1);
		B.readFile(v2);
		
		C= A.operator*(B);
	
		C.printMatrix(v3);
	
	}
	else if((storage == "array") && (operation == "add"))
	{
		MatrixArray A,B,C;
		
		A.readFile(v1);
		B.readFile(v2);
		
		A.arrayAdd(A,B,C,1,1);
		
		C.printMatrix(v3);
	
	}
	else if((storage == "linkedlist") && (operation == "multiply"))
	{
		List A, B;
	
		A.readFile(v1);
		B.readFile(v2);
		
		A.multiply(B,v3);
	}
	else if((storage == "linkedlist") && (operation == "add"))
	{
		List A,B,C;
	
		A.readFile(v1);
		B.readFile(v2);
		A.setNodes();
		B.setNodes();
		
		A.addMatx(A,B,C,1,1);
	
		if(C.head!=NULL)
		{	
			C.printFile(v3);
		}
	}
	
	cout<<"\n*Thank you for using the sparse matrix multiplier!*\n";

	return 0;
}



