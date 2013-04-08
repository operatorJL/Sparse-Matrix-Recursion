test list


	if((A.maxI!=B.maxI) || (A.maxJ!=B.maxJ))
	{	
		cout<<"Can not add matrices of different size\n";
		return;
	}
	else if((A.currentRow==NULL) || (B.currentRow==NULL))
	{
		return;
	}
	else if((A.currentNode==NULL) || (B.currentNode==NULL))
	{
		if(A.currentNode==NULL)
		{
			A.currentRow=A.currentRow->nextRow;
			A.currentNode=A.currentRow->headNode;
			addMatx(A,B,C);
		}
		else if(B.currentNode==NULL)
		{
			B.currentRow=B.currentRow->nextRow;
			B.currentNode=B.currentRow->headNode;
			addMatx(A,B,C);
		
		}
	}
	else if((A.currentNode->iValue) < (B.currentNode->iValue))
	{
		A.currentRow=A.currentRow->nextRow;
		A.currentNode=A.currentRow->headNode;
		addMatx(A,B,C);
	}
	else if((A.currentNode->iValue) > (B.currentNode->iValue))
	{	
		B.currentRow=B.currentRow->nextRow;
		B.currentNode=B.currentRow->headNode;
		addMatx(A,B,C);
	}
	else if((A.currentNode->jValue) < (B.currentNode->jValue))
	{	
		A.currentNode=A.currentNode->nodeLink;
		addMatx(A,B,C);
	}
	else if((A.currentNode->jValue) > (B.currentNode->jValue))
	{	
		B.currentNode=B.currentNode->nodeLink;
		addMatx(A,B,C);
	}
	else
	{
		sum=(A.currentNode->value) + (B.currentNode->value);
		
		if(sum!=0)
		{	
			int tempI=A.currentNode->iValue;
			int tempJ=A.currentNode->jValue;
			
			
			A.currentNode=A.currentNode->nodeLink;
			B.currentNode=B.currentNode->nodeLink;
			C.addEntry(tempI,tempJ,sum);
			addMatx(A,B,C);
		}
		else
		{	
			A.currentNode=A.currentNode->nodeLink;
			B.currentNode=B.currentNode->nodeLink;
			addMatx(A,B,C);
		}
	}