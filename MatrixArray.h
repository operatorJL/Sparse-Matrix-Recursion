/***********************************
Header file for matrix class

************************************/
class MatrixArray
{
	private:
		
		double matrix[101][101];
		int maxI;
		int maxJ;
	
		
	public:
	
	MatrixArray();
	MatrixArray(double newMatrix[][101], int,int);
	
	void readFile(char *);
	void printMatrix(char *);
	void setValue(int,int,double);
	double getValue(int,int);
	void setMaxI(int);
	int getMaxI();
	void setMaxJ(int);
	int getMaxJ();
	const MatrixArray operator *(const MatrixArray& matxB);
	void arrayAdd(MatrixArray&,MatrixArray&,MatrixArray&,int, int);
	void printScreen();

};

