/*! \file matrix.h 
    \brief Header file for Matrix class
*/

#include <stdexcept>
using namespace std;

/*! \class Matrix
    \brief A class that represents a 2D matrix of integers.
*/
class Matrix {
    /** Number of rows in the matrix*/
    int rows;

    /** Number of columns in the matrix*/
    int cols;

    /** 1D array to store the matrix data*/
    int *elems;

    /*! \fn void copy_elems(const Matrix &m)
        \brief deep copy a matrix
        \param m Matrix to copy contents from into the current Matrix
    */
    void copy_elems(const Matrix &m) {
        rows = m.rows;
        cols = m.cols;
        
        /** make a deep copy*/
        elems = new int[rows*cols];

        for (int i = 0; i < rows * cols; i++) {
            elems[i] = m.elems[i];
        }
    }

    /*! \fn void copy_elems(Matrix &m)
        \brief move matrix contents 
        \param m Matrix to move contents from into the current Matrix
    */
    void move_elems(Matrix &m) {
        rows = m.rows;
        cols = m.cols;
        elems = m.elems;
        m.elems = nullptr;
    }

    /*! \fn void delete_elems()
        frees the dynamically allocated memory.
    */
    void delete_elems() {
        delete[] elems;
    }

    /*! \fn int get_index(int r, int c) const
        calculate the index in array 
        \param r Row number
        \param c Column number
        \return the index in the elems array
    */
    int get_index(int r, int c) const {
        return r * cols + c;
    }

public:
    /*! Default Constructor
        Takes no arguments, set rows and cols both to zero
    */
    Matrix() {
        rows = 0;
        cols = 0;
        elems = new int[0];
    }

    /*! Constructor 
        \brief initializes a rows x cols zeros matrix 
     
        An invalid_argument error is thrown if if rows or cols is not positive.
     
        \param rows Number of rows
        \param cols Number of columns
     */
    Matrix(int rows, int cols) {
        if (rows <= 0 || cols <= 0) {
            throw invalid_argument(
                "Number of rows and columns must be positive."
            );
        }

        this->rows = rows;
        this->cols = cols;
        elems = new int[rows * cols];

        for (int i = 0; i < rows * cols; i++) {
            elems[i] = 0;
        }
    }

    /*! Copy-constructor 
        Creates a new matrix object by copying contents from m.
     
        \param m Matrix to copy contents from
    */
    Matrix(const Matrix &m) {
        copy_elems(m);
    }

    /*! Move-constructor 
        Creates a new matrix object by contents from m.
     
        \param m Matrix to move contents from
    */
    Matrix(Matrix &&m) {
        move_elems(m);
    }

    /*! Destructor 
        frees the dynamically allocated memory.
    */
    ~Matrix() {
        delete[] elems;
    }

    /*! Copy-assignment operator that frees the resources in the object and
       copies the contents of m into the object, returning the reference to
       the object.
      
       \param m Matrix to copy contents from
     */
    Matrix & operator=(const Matrix &m) {
        /** Detect and handle self-assignment */
        if (this == &m) {
            return *this;
        }

        delete_elems();
        copy_elems(m);

        return *this;
    }

    /*! Move-assignment operator that frees the resources in the object and
       moves the contents of m into the object, returning the reference to
       the object.
      
       \param m Matrix to move contents from
     */
    Matrix & operator=(Matrix &&m) {
        /** Detect and handle self-assignment */
        if (this == &m) {
            return *this;
        }

        delete_elems();
        move_elems(m);

        return *this;
    }

    /*! \fn int numRows() const
        \brief Getter of row number
        \return row number of the matrix
    */
    int numRows() const {
        return rows;
    }

    /*! \fn int numCols() const
        \brief Getter of column number
        \return column number of the matrix
    */
    int numCols() const {
        return cols;
    }
  
    /*! \fn int get(int r, int c) const
        \brief Getter of an element 
        \param r Row index
        \param c Column index
        \return element at row index r and col index c
    */
    int get(int r, int c) const {
        if (r < 0 || r >= rows || c < 0 || c >= cols) {
            throw invalid_argument("The row or column index is out of bounds.");
            } 

        return elems[get_index(r, c)];
    }

    /*! \fn int get(int r, int c, int value) 
        \brief Setter of an element 
        \param r Row index
        \param c Column index
        \param value the value to store at row index r and col index c
    */
    void set(int r, int c, int value) {
        if (r < 0 || r >= rows || c < 0 || c >= cols) {
            throw invalid_argument("The row or column index is out of bounds.");
            } 

        elems[r * cols + c] = value;
    }

    /*! \fn bool operator==(const Matrix &m) const
       Returns true if the two matrices are equal, with the same size and
       identical elements, and false otherwise.
     
        \param m Matrix to compare to
        \return Boolean value indicating whether they were equal or not
    */
    bool operator==(const Matrix &m) const {
        if (rows != m.rows || cols != m.cols) {
            return false;
        }

        for (int i = 0; i < rows * cols; i++) {
            if (elems[i] != m.elems[i]) {
                return false;
            }
        }

        return true;
    }

    /*! \fn bool operator！=(const Matrix &m) const
       Returns true if the two matrices are not equal, and false otherwise.
     
        \param m Matrix to compare to
        \return Boolean value indicating whether they were equal or not
    */
    bool operator!=(const Matrix &m) const {
        return !operator==(m);
    }





};