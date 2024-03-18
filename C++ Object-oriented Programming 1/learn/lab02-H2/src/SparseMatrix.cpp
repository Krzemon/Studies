#include "SparseMatrix.h"

SparseMatrix::SparseMatrix(){}

SparseMatrix::SparseMatrix (int rows, int columns):Rows (rows), Columns (columns)
{
	Matrix = new int **[Rows];
	for (int i = 0; i < Rows; i++)
	  {
		Matrix[i] = new int *[Columns];
	  }

	for(int i = 0; i < Rows; i++)
	{
		for(int j = 0 ; j < Columns ; j++)
		{
			Matrix[i][j] = nullptr;
		}
	}
}

SparseMatrix::SparseMatrix (const SparseMatrix& other)
{
Rows = other.Rows;
Columns = other.Columns;
Matrix = new int **[Rows];
for (int i = 0; i < Rows; i++)
  {
	Matrix[i] = new int *[Columns];
  }

  for(int i = 0 ; i <Rows; i++)
  {
	for(int j =0; j< Columns; j++)
	{
		if(other.Matrix[i][j] != nullptr)
		Matrix[i][j] = new int(*other.Matrix[i][j]);
		else 
		{
			Matrix[i][j] = nullptr;
		}
	}
  }
}


SparseMatrix& SparseMatrix::operator= (const SparseMatrix & other)
  {
	if (this != &other)
	  {

		for (int i = 0; i < Rows; i++)
		  {
			for (int j = 0; j < Columns; j++)
			  {
				if(Matrix[i][j] != nullptr)
				delete Matrix[i][j];
			  }
			delete[]Matrix[i];
		  }

		Rows = other.Rows;
		Columns = other.Columns;

		Matrix = new int** [Rows];
		for (int i = 0; i < Rows; i++)
		  {
			Matrix[i] = new int *[Columns];
			for (int j = 0; j < Columns; j++)
			  {
				if(other.Matrix[i][j] != nullptr)
				Matrix[i][j] = new int(*other.Matrix[i][j]);
				else 
				{
					Matrix[i][j] = nullptr;
				}
			  }
		  }
	  }

	return *this;
  }

  SparseMatrix::SparseMatrix(SparseMatrix&& other)
  {
	Rows = other.Rows;
	Columns = other.Columns;
	Matrix = other.Matrix;
	other.Matrix = nullptr;
  }

  SparseMatrix& SparseMatrix::operator= (SparseMatrix&& other)
  {
	if (this != &other)
	  {
		for (int i = 0; i < Rows; i++)
		  {
			for (int j = 0; j < Columns; j++)
			  {
				if(Matrix[i][j] != nullptr)
				delete Matrix[i][j];
			  }
			delete[] Matrix[i];
		  }

		Rows = other.Rows;
		Columns = other.Columns;
		Matrix = other.Matrix;
		other.Matrix = nullptr;
	  }

	return *this;
}

SparseMatrix::~SparseMatrix ()
  {
	if(Matrix != nullptr){
	for (int i = 0; i < Rows; i++)
	  {
		for (int j = 0; j < Columns; j++)
		  {
			if(Matrix[i][j] != nullptr)
			delete Matrix[i][j];
		  }
		delete [] Matrix[i];
	  }
	delete[] Matrix;
	}
  }

  void SparseMatrix::insert(int row, int col, int *value)
  {
	if (row >= Rows)
	  {
		return;					
	  }
	if (col >= Columns)
	  {
		return;					
	  }
	else
	  {
		if(Matrix[row][col] != nullptr)
		delete Matrix[row][col];


		Matrix[row][col] = value;
	  }

  }

  void SparseMatrix::reset(int row, int col)
  {
    if (row >= Rows)
	  {
		return;				
	  }
	if (col >= Columns)
	  {
		return;					
	  }
    else
    {
		if(Matrix[row][col] != nullptr)
		delete Matrix[row][col];
        Matrix[row][col] = new int(0);
    }

  }


 int** SparseMatrix::operator[](int index) 
    {
        
        return Matrix[index];
    } 



std::ostream& operator<<(std::ostream& os, const SparseMatrix& object)
{

	if(object.Matrix != nullptr){
    for(int i = 0; i < object.Rows; i++)
    {
        for(int j = 0; j< object.Columns; j++)
        {
			if(object.Matrix[i][j] != nullptr){
            os << *(object.Matrix[i][j]) << " ";
			}
			else 
			{
				os << "0";
			}
		}

        os  << "\n";
    }
	 
	}
	return os;
	}

   