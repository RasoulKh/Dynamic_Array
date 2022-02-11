#include <iostream>
using namespace std;

struct Dimension {
    int x;
    int y;
    int z;
};
//*********************************//
//***********   Main   ************//
//*********************************//
int main(){

    Dimension size_1D;
    Dimension size_2D;
    Dimension size_3D;

    /* Defining a Dynamic 1D Array with the size of "size" */
    cout << "Size of the 1D Array: " << endl;
    cin >> size_1D.x;

    /* Defining a Dynamic 2D Array with the size of "row" and "col" */
    cout << "Rows (x) and Columns (y) of the 2D Array: " << endl;
    cin >> size_2D.x;
    cin >> size_2D.y;
    

    /* Defining a Dynamic 3D Array with the size of "row", "col", "depth" */
    cout << "Rows (x), Columns (y), and Depth (z) of the 3D Array: " << endl;
    cin >> size_3D.x;
    cin >> size_3D.y;
    cin >> size_3D.z;
    
    /* Allocation of 1D Array  */
    int* Array_1D = new int[size_1D.x];

    /* Allocation of 2D Array  */
    int** Array_2D = new int*[size_2D.x];
    for (int i = 0; i<size_2D.x; i++){
        Array_2D[i] = new int[size_2D.y];
    }

    /* Allocation of 3D Array  */
    int*** Array_3D = new int**[size_3D.x];
    for(int i = 0; i<size_3D.x; i++){
        // Allocate memory blocks for
        // rows of each 2D array
        Array_3D[i] = new int*[size_3D.y];

        for(int j = 0; j < size_3D.y; j++){
            // Allocate memory blocks for
            // columns of each 2D array
            Array_3D[i][j] = new int[size_3D.z];
        }
    }

    /* Filling 1D array  */
    for (int i = 0; i < size_1D.x; i++){
        Array_1D[i] = i * i;
    }

    /* Filling 2D array  */
    for(int i = 0; i < size_2D.x; i++){
        for (int j = 0; j< size_2D.y; j++){
            Array_2D[i][j] = (i * i) + (j * j);
        }
    }

    /* Filling 3D array  */
    for(int i = 0; i < size_3D.x; i++){
        for (int j = 0; j < size_3D.y; j++){
            for (int k = 0; k < size_3D.z; k ++){
                Array_3D[i][j][k] = (i * i) + (j * j) + (k * k);
            }
        }
    }

    /* Printing out 1D Array */
    cout << "Printing out 1D Array" << endl;
    for (int i = 0; i < size_1D.x; i++){
        cout << Array_1D[i] << " " << endl;
/*      cout << "Array_1D[" << i << "] is: " << *(Array_1D + i) << endl; */
    }

    /* Printing out 2D Array */
    cout << "Printing 2D Array: " << endl;
   for(int i = 0; i < size_2D.x; i++){
        for (int j = 0; j< size_2D.y; j++){
            cout << Array_2D[i][j] << " ";
        }
        cout << endl;
    }

    /* Printing out 3D Array */
    cout << "Printing out 3D Array: " << endl;
   for(int i = 0; i < size_3D.x; i++){
        for (int j = 0; j< size_3D.y; j++){
            for(int k = 0; k < size_3D.z; k++){
                cout << Array_3D[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    /* De-allocating the dynamic 1D Array */
    delete[] Array_1D;
    Array_1D = NULL;

    /* De-allocating the dynamic 2D Array */
    for (int i = 0; i<size_2D.x; i++){
        delete[] Array_2D[i];
    }
    delete[] Array_2D;
    Array_2D = NULL;

    /* De-allocating the dynamic 3D Array */
    for(int i = 0; i < size_3D.x; i++){
        for(int j = 0; j < size_3D.y; j++){
            delete[] Array_3D[i][j]; 
        }
        delete[] Array_3D[i];
    }
    delete[] Array_3D;
    Array_3D = NULL;

    return 0;
}
