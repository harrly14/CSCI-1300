/*
Develop a library system by creating a library class to manage a colletion of books

4.1 
    create a class Library by splitting the code into the following files: 
        a header file Library.h to declare the definition of the class
        an implementation file Library.cpp to implement the class defined in the header
        a driver file LibraryDriver.cpp that contains the main function
4.2
    write getAveragePageCount
4.3
    write findLibraryWithLargestAveragePageCount  
*/
#include "Library.h"
#include <iostream>

std::string findLibraryWithLargestAveragePageCount(Library libraries[], const int ARR_SIZE) {
    //return name of library with highest avg page count
    //if multiple libraries have the same largest avg page count, return the first
    double largest_avg_pages = 0;
    int selected_index = 0;
    for (int i = 0; i < ARR_SIZE; ++i) {
        Library current_library = libraries[i];
        if (current_library.getAveragePageCount() > largest_avg_pages) {
            largest_avg_pages = current_library.getAveragePageCount();
            selected_index = i;
        }
    }
    return libraries[selected_index].getName();
}

int main() {
    const int ARR_SIZE = 2;
    int page_counts1[3] = {250, 300, 350};
    int page_counts2[4] = {200, 300, 250, 400};
    Library library1 = Library("Downtown Library", page_counts1, 3);
    Library library2 = Library("Uptown Library", page_counts2, 4);
    Library libraries[ARR_SIZE] = {library1, library2};
    std::cout << findLibraryWithLargestAveragePageCount(libraries,ARR_SIZE) << std::endl;
}
/*
Expected Output:
Downtown Library
Explanation:
Average page count of library1 = 300.00
Average page count of library2 = 287.50
library1 has the largest average pag
*/