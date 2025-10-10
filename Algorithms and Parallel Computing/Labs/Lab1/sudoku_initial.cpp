/*
 * Check sudoku matrix
 */

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

const size_t SIZE = 9;




/*
 * YOUR CODE GOES HERE
 */





// Return:
//         1 if sudoku matrix complies to all Sudoku rules
//        -1 if a row violates the game rules
//        -2 if a column violates the game rules
//        -3 if a region violates the game rules
int check_sudoku(const unsigned sudoku[][SIZE]);

// Create a Sudoku matrix by Lewis' Algorithm
// (https://en.wikipedia.org/wiki/Sudoku_solving_algorithms)
void generate_sudoku(unsigned sudoku[][SIZE]);

int main()
{
    // initialize a sudoku matrix
    unsigned sudoku[SIZE][SIZE] = {
            {1,2,3,4,5,6,7,8,9},
            {2,3,4,5,6,7,8,9,1},
            {3,4,5,6,7,8,9,1,2},
            {4,5,6,7,8,9,1,2,3},
            {5,6,7,8,9,1,2,3,4},
            {6,7,8,9,1,2,3,4,5},
            {7,8,9,1,2,3,4,5,6},
            {8,9,1,2,3,4,5,6,7},
            {9,1,2,3,4,5,6,7,8}
    };

    unsigned sudoku3[SIZE][SIZE] = {
        {5,3,4,6,7,8,9,1,2},
        {6,7,2,1,9,5,3,4,8},
        {1,9,8,3,4,2,5,6,7},
        {8,5,9,7,6,1,4,2,3},
        {4,2,6,8,5,3,7,9,1},
        {7,1,3,9,2,4,8,5,6},
        {9,6,1,5,3,7,2,8,4},
        {2,8,7,4,1,9,6,3,5},
        {3,4,5,2,8,6,1,7,9}
    };

    // check
    int res = check_sudoku(sudoku);
    cout << "check_sudoku returns: " <<  res << endl;

    // initialize another sudoku matrix
    unsigned sudoku2[SIZE][SIZE];
    generate_sudoku(sudoku2);

    // check
    int res_2 = check_sudoku(sudoku2);
    cout << "check_sudoku returns: " <<  res_2 << endl;

    return 0;
}

int search_key (const unsigned v[], unsigned n_elements, unsigned key)
{
    unsigned key_found = 0;

    for (size_t i=0; i<n_elements; ++i)
        if (v[i] == key)
            key_found = 1;

    return key_found;
}




/*
 * YOUR CODE GOES HERE
 */

int basic_search(const unsigned v[], unsigned n_elements){
    unsigned key_allNumbers=1;
    for (int i=1;i<10;i++){
        if (!search_key(v,SIZE,i)){
            key_allNumbers = 0;
        }
    }       
    return key_allNumbers;

}

int check_rows(const unsigned sudoku[][SIZE]){
    unsigned valid_rows = 1;
    unsigned row_values[SIZE];
    for (int row=0;row<SIZE;row++){
        for (int col=0;col<SIZE;col++){
            row_values[col]=sudoku[row][col];
        }
        if(basic_search(row_values,SIZE)==0){
            valid_rows=0;
            return valid_rows;
        }
    }
    return valid_rows;
}

int check_cols(const unsigned sudoku[][SIZE]){
    unsigned valid_cols=1;
    unsigned col_values[SIZE];
    for (int col=0;col<SIZE;col++){
        for(int row=0;row<SIZE;row++){
            col_values[row]=sudoku[row][col];
            }
        if(basic_search(col_values,SIZE)==0){
            valid_cols=0;
            return valid_cols;
        }
    }
    return valid_cols;
}

int check_regions(const unsigned sudoku[][SIZE]){
    unsigned valid_region=1;
    unsigned region_values[SIZE];
    const size_t region_size = 3;
    for (int row=0;row<SIZE;row+=region_size){
        for(int col=0;col<SIZE;col+=region_size){
            int i=0;
            for (int row_aux=row;row_aux<row+region_size;row_aux++){
                for (int col_aux=col;col_aux<col+region_size;col_aux++){
                    region_values[i]=sudoku[row_aux][col_aux];
                    i++;
                }
            }
            if(basic_search(region_values,SIZE)==0){
                valid_region=0;
                return valid_region;
            }
        }  
    }
    return valid_region;
}

int check_sudoku(const unsigned sudoku[][SIZE])
{
    int check;
    int regions = check_regions(sudoku);
    int cols = check_cols(sudoku);
    int rows = check_rows(sudoku);
    cout<<cols<<endl;
    if (regions==1 && cols==1 && rows==1){
        check=1;
    }else if (regions!=1)
    {
        check=-3;
    }else if (cols!=1)
    {
        check=-2;
    }else if (rows!=1)
    {
        check=-1;
    }
    
    
    

    return check;
}

void generate_sudoku(unsigned sudoku[][SIZE])
{
    int x = 0;
    for (size_t i=1; i<=3; ++i)
    {
        for (size_t j=1; j<=3; ++j)
        {
            for (size_t k=1; k<=SIZE; ++k)
            {
                sudoku[3*(i-1)+j-1][k-1] = (x % SIZE) + 1;
                x++;
            }
            x += 3;
        }
        x++;
    }
}