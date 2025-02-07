#include <iostream>
#include <string>
using namespace std;

struct inventory
{
    int productID;
    string name;
    float price;
    int quantity;
};

int main()
{
    int n;
    cout << "Enter the number of products: ";
    cin >> n;
    inventory *products = new inventory[n];

    for (int i = 0; i < n; i++)
    {
        cout<<"Enter Product ID:";
        cin>>products[i].productID;        
        cin.ignore();
        
        cout << "Enter product name: ";
        getline(cin, products[i].name);
        
        cout << "Enter quantity of product: ";
        cin >> products[i].quantity;
        
        cout << "Enter price: ";
        cin >> products[i].price;
    }

    float sum=0;
    for (int i = 0; i < n; i++)
    {
        cout << "Cost of " << products[i].name << ": " << products[i].quantity * products[i].price << endl;
        sum += products[i].quantity * products[i].price;
    }
    cout<<"\n--Total value = "<<sum<<"---"; 
    
    delete[] products;
    
    return 0;
}