#include <iostream>
using namespace std;
// Function to calculate the transpose of a matrix
void transposeMatrix(int originalMatrix[][3], int n, int m){ //changed this to match original matrix. changed from double to voi
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < m; j++){
            int temp = originalMatrix[i][j]; //added int data type. changed all instances of matrix to originalMatrix
            originalMatrix[i][j] = originalMatrix[j][i]; 
            originalMatrix[j][i] = temp;
        }
    }

}

int main(){
    const int rows = 3;
    const int cols = 3;
    int originalMatrix[rows][cols] =
    {
    {1, 1, 1},
    {2, 2, 2},
    {3, 3, 3}
    };

    // Calculate the transpose matrix using the function
    transposeMatrix(originalMatrix, rows, cols); //removed setting it equal to the result. removed brackets from originalMatrix

    // Display the transpose matrix
    cout << "Transpose Matrix:" << endl;
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            cout << originalMatrix[i][j] << " "; //changed result to originalMatrix
        }
    cout << endl;
    }
    return 0;
}