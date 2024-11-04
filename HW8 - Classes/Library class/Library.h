#ifndef LIBRARY_H
#define LIBRARY_H
#include <iostream>

class Library{
    public:
        Library();
        Library(std::string n);
        Library(std::string name, int page_counts[], int arr_size);
        std::string getName();
        int getCurrentBooks();
        void setName(std::string n);
        int getPageCount(int i);
        bool addPageCount(int pages);
        double getAveragePageCount();
    private:
        std::string _name;
        const static int _MAX_BOOKS = 10;
        int _page_counts[_MAX_BOOKS];
        int _current_books;
};

#endif