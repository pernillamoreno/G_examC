#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// Define number between 10 and 1000
#define MIN 10
#define MAX 1000

bool uniqueEvenNumber(int number, int *array, int size);
void fillMatrix(int *array, int rows, int col);
void printMatrix(int *array, int rows, int col);
void calculateRow(int *array, int rows, int col);
void calculateCol(int *array, int rows, int col);

int main()
{
    int r, c;
    // Get the number of rows and columns from the user
    printf("Enter the number of rows: ");
    scanf("%d", &r);
    printf("Enter the number of columns: ");
    scanf("%d", &c);

    /*matrix is a pointer to an int; malloc allocates memory for a 2D matrix with r rows and c columns.
    int *matrix: This declares matrix as a pointer to an int.
    It's going to be used to store the memory address of the dynamically allocated 2D matrix.*/
    int *matrix = (int *)malloc(r * c * sizeof(int));

    // Check if memory allocation is successful
    if (matrix == NULL)
    {
        printf("Memory allocation error.\n");
        return 1;
    }

    // Fill the matrix with unique random numbers
    fillMatrix(matrix, r, c);
    printf("Matrix:\n");
    // Print the matrix
    printMatrix(matrix, r, c);

    // Print the sum of each row
    calculateRow(matrix, r, c);

    // Print the sum of each column
    calculateCol(matrix, r, c);

    // Free allocated memory
    free(matrix);

    return 0;
}

/**
 * Checks if a number is unique and even in the given array.
 *
 *  number The number to check.
 *  array  A pointer to the array.
 *  size   The size of the array.
 *  return true if the number is unique and even; otherwise, false.
 */
bool uniqueEvenNumber(int number, int *array, int size)
{

    if (number % 2 != 0)
    {
        return false; // Number is not even
    }

    /* Check if the number is already exsist in the array.
     number == array[i]. If number is equal to a index
    in the array. It's not uniqe, and the return is false.*/
    for (int i = 0; i < size; i++)
    {
        if (number == array[i])
        {
            return false; // False if number is not unique
        }
    }
    return true; // True if number is unique and even
}

// Function to fill array with unique random numbers
void fillMatrix(int *array, int rows, int col)
{
    srand(time(NULL));

    // Loop to fill array with unique random numbers
    for (int i = 0; i < rows * col;)
    {
        int randomNumber;
        /*do-while loop.
        The loop will generate random numbers and checking if they are
        unique and even in uniqueEvenNumber function.
        while It will continue looping until a unique and even number
        pops up :).*/
        do
        {
            randomNumber = rand() % (MAX - MIN + 1) + MIN;
        } while (!uniqueEvenNumber(randomNumber, array, i));

        array[i++] = randomNumber;
    }
}

// Function to print a matrix
void printMatrix(int *array, int rows, int col)
{
    // Loop that print element of the matrix
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < col; j++)
        {
            /*The expression i * col + j calculate
             the index of the element in a 2D array (matrix).
            1 i is the current row number.
            2 col is the total number of columns in the matrix.
            3 j is the current column number.*/
            printf("%d ", array[i * col + j]);
        }
        printf("\n");
    }
}

// Function that calculate and print the sum of elements in every row of the matrix
void calculateRow(int *array, int rows, int col)
{
    // Loop that calculate and print the sum of every row
    for (int i = 0; i < rows; i++)
    {
        int sum = 0;
        for (int j = 0; j < col; j++)
        {
            sum += array[i * col + j];
        }
        printf("Row nr:%d sum:%d  \n", i + 1, sum);
    }
    printf("\n");
}

// Function to calculate and print the sum of elements in each column of the matrix
void calculateCol(int *array, int rows, int col)
{
    // Loop to calculate and print the sum of each column
    for (int j = 0; j < col; j++)
    {
        int sum = 0;
        for (int i = 0; i < rows; i++)
        {
            sum += array[i * col + j];
        }
        printf("Column nr:%d sum: %d \n", j + 1, sum);
    }
    printf("\n");
}
