#include <iostream>
#include <string>
using namespace std;

class Library {
private:
    string booklist[100]; 
    string borrowedBooks[100]; 
    bool availableBooks[100]; 
    int bookCount;

public:
    Library() {
        bookCount = 0;
    }

    void addBook(string bookName) {
        if (bookCount < 100) {
            booklist[bookCount] = bookName;
            availableBooks[bookCount] = true;
            cout << "Book " << bookName << " added to the library." << endl;
            bookCount++;
        } else {
            cout << "Library is full, cannot add more books." << endl;
        }
    }

    void lendBook(string bookName, string studentName) {
        for (int i = 0; i < bookCount; i++) {
            if (booklist[i] == bookName) {
                if (availableBooks[i]) {
                    availableBooks[i] = false;
                    borrowedBooks[i] = studentName;
                    cout << "Book " << bookName << " has been borrowed by " << studentName << "." << endl;
                } else {
                    cout << "Sorry, " << bookName << " is already borrowed by " << borrowedBooks[i] << "." << endl;
                }
                return;
            }
        }
        cout << "Sorry, " << bookName << " is not available in the library." << endl;
    }

    void returnBook(string bookName) {
        for (int i = 0; i < bookCount; i++) {
            if (booklist[i] == bookName && !availableBooks[i]) {
                availableBooks[i] = true;
                cout << "Book " << bookName << " returned by " << borrowedBooks[i] << "." << endl;
                borrowedBooks[i] = "";
                return;
            }
        }
        cout << "Error: " << bookName << " was not borrowed." << endl;
    }

    void displayBooks() {
        bool found = false;
        cout << "Available books:" << endl;
        for (int i = 0; i < bookCount; i++) {
            if (availableBooks[i]) {
                cout << "- " << booklist[i] << endl;
                found = true;
            }
        }
        if (!found) {
            cout << "No books available in the library." << endl;
        }
    }
};

int main() {
    Library lib;
    lib.addBook("C++ Programming");
    lib.addBook("Data Structures");
    lib.displayBooks();
    lib.lendBook("C++ Programming", "Ali");
    lib.displayBooks();
    lib.returnBook("C++ Programming");
    lib.displayBooks();
    return 0;
}
