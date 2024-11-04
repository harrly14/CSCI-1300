#include <iostream>
#include "Library.h"


Library::Library(){
    _name = "";
    _current_books = 0;
}
Library::Library(std::string n) {
    _name = n;
    _current_books = 0;
    for (int i = 0; i < _MAX_BOOKS; ++i) {
        _page_counts[i] = 0;
    }

}
Library::Library(std::string name, int page_counts[], int arr_size){
    _name = name;
    if (arr_size >=10) {
        _current_books = _MAX_BOOKS;
    } else {
        _current_books = arr_size;
    }
    for (int i = 0; i < _MAX_BOOKS; ++i) {
        if (i < arr_size) {
            _page_counts[i] = page_counts[i];
        } else {
            _page_counts[i] = 0;
        }
    }
}
std::string Library::getName() {
    return _name;
}
int Library::getCurrentBooks() {
    return _current_books;
}
void Library::setName(std::string n) {
    _name = n;
}
int Library::getPageCount(int i) {
    if (i>= _current_books) {
return -1;
    } 
    return _page_counts[i];
}
bool Library::addPageCount(int pages) {
    if (_current_books >= _MAX_BOOKS) {
return false;
    }
    if (pages < 0 ) {
return false;
    }
    _page_counts[_current_books] = pages;
    ++_current_books;
    return true;
}
double Library::getAveragePageCount() {
    //calculates and returns the average page count of the  books in the library
    //possible errors with ints being divided
    double sum = 0;
    for (int i = 0; i < _current_books; ++i) {
sum += _page_counts[i];
    }
    return sum/_current_books;
}