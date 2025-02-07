#include <iostream>
#include <string>
using namespace std;

struct book{
    string title;
    string author;
    int year;
};

int main(){
    int n;

    cout << "Enter the number of books you want to enter: ";
    cin >> n;

    cin.ignore();
    book* books = new book[n];
    
    for (int i = 0; i < n; i++)
    { 
        cout << "Enter the book "<<i+1<<" Title: ";
        getline(cin, books[i].title);

        cout << "Enter the book "<<i+1<<" Author: ";
        getline(cin, books[i].author);

        cout << "Enter the book "<<i+1<<" Year: ";
        cin>>books[i].year;
        cin.ignore();

    }
    int y;

    cout << "Enter the year after which you want to see books published: ";
    cin >> y;

    cout << "\nBooks published after " << y << ":"<<endl;

    bool found = false;

    for (int i = 0; i < n; i++)
    {
        if(books[i].year>y){
            found = true;
            cout << "Book "<<i+1<<" :\n"<<books[i].title<<"\n"<<books[i].author<<"\n"<<books[i].year<<endl;
        }
    }
    if (!found) {
        cout << "Error! no books found. ";
    }
    
    delete[] books;
    
    return 0;
}