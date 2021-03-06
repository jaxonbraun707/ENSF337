//   matrix.cpp


#include "matrix.h"

Matrix::Matrix(int r, int c):rowsM(r), colsM(c)
{
    matrixM = new double* [rowsM];
    assert(matrixM != NULL);
    
    for(int i=0; i < rowsM; i++){
        matrixM[i] = new double[colsM];
        assert(matrixM[i] != NULL);
    }
    sum_rowsM = new double[rowsM];
    assert(sum_rowsM != NULL);
    
    sum_colsM = new double[colsM];
    assert(sum_colsM != NULL);
}


Matrix::~Matrix()
{
    destroy();
}

Matrix::Matrix(const Matrix& source)
{
    copy(source);
}

Matrix& Matrix::operator= (const Matrix& rhs)
{
    if(&rhs != this){
        destroy();
        copy(rhs);
    }
   
    return *this;
}

double Matrix::get_sum_col(int i) const
{
    assert(i >= 0 && i < colsM);
    return sum_colsM[i];
}

double Matrix::get_sum_row(int i) const
{
    assert(i >= 0 && i < rowsM);
    return sum_rowsM[i];
}


void Matrix::sum_of_rows()const
{
   for (int i = 0; i < rowsM; i++){
       double sum = 0;
       for (int j = 0; j < colsM; j++){
           sum += matrixM[i][j];
       }
       sum_rowsM[i] = sum;
   }
}

void Matrix::sum_of_cols()const
{
    for (int i = 0; i < colsM; i++){
        double sum = 0;
        for (int j = 0; j < rowsM; j++){
            sum += matrixM[j][i];
        }
        sum_colsM[i] = sum;
    }
}

void Matrix::copy(const Matrix& source)
{
    
    if(source.matrixM == NULL){
        matrixM = NULL;
        sum_rowsM = NULL;
        sum_colsM = NULL;
        rowsM = 0;
        colsM = 0;
        return;
    }
    
    rowsM = source.rowsM;
    colsM = source.colsM;
    
    sum_rowsM = new double[rowsM];
    assert(sum_rowsM != NULL);
    
    
    sum_colsM = new double[colsM];
    assert(sum_colsM != NULL);
    
    matrixM = new double*[rowsM];
    assert(matrixM !=NULL);
    for(int i =0; i < rowsM; i++){
        matrixM[i] = new double[colsM];
        assert(matrixM[i] != NULL);
    }
    for (int i = 0; i < rowsM; i++){
        for (int j = 0; j < colsM; j++){
            matrixM[i][j] = source.matrixM[i][j];
        }
    }
    sum_of_rows();
    sum_of_cols();
}

    

void Matrix::destroy()
{
    for (int i = 0; i < rowsM; i++)
        delete[] matrixM[i];
    delete[] matrixM;
    delete[] sum_rowsM;
    delete[] sum_colsM;
}
