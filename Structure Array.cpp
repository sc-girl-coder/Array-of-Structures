/* Samantha Casler
Last Modified 10/21/18 */

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

// Structure for product information
struct Info
{
    int id;
    double price;
    int numberSold;
    double itemSales;
};

struct Sales
{
    double totalSales;
    int totalSold;
};

void originalArray (Info [], const int);
double itemSalesCalc (Info [], const int);
void selectionSort (Info [], const int);
void sortedArray (Info [], const int);

int main ()
{
    const int numProducts = 15;

    // Array of structures
    Info products [numProducts];

    //opening the input file with the product information
    ifstream fin;
    fin.open ("Project 6_Products_Input.txt");


    for (int count = 0; count < numProducts; count++)
    {
        fin >> products[count].id;
        fin >> products[count].price;
        fin >> products[count].numberSold;
    }

    originalArray (products, numProducts);

    for (int count = 0; count < numProducts; count++)
    {

        products[count].itemSales = itemSalesCalc (products, count);
    }

    selectionSort (products, numProducts);

    Sales total;

    for (int count = 0; count < numProducts; count++)
    {
        total.totalSales += products[count].itemSales;

        total.totalSold += products[count].numberSold;

    }

    sortedArray (products, numProducts);

    cout << endl << endl;
    cout << setw(20) << left << "Total Units Sold: ";
    cout << total.totalSold << endl;
    cout << setw(20) << left << "Total Sales of all Items: ";
    cout << "$" << total.totalSales << endl;

    fin.close();


    return 0;

}

void originalArray (Info array [], const int SIZE)
{

    cout << setw (60) << right << "Original Array of Structures: \n\n";

    for (int count = 0; count < SIZE; count++)
    {
        cout << setw(20) << left << "Product ID: ";
        cout << array[count].id << endl;
        cout << setw(20) << left << "Unit Price: ";
        cout << setprecision(2) << fixed << "$" << array[count].price << endl;
        cout << setw(20) << left << "Quantities Sold: ";
        cout << array[count].numberSold << endl << endl;
    }
}

double itemSalesCalc (Info array[], const int SIZE)
{
    double sales;

    sales = array[SIZE].price * array[SIZE].numberSold;

    return sales;
}

void selectionSort (Info array[], const int SIZE)
{
    int beginHere;
    int index;
    double value;
    int value2;
    double value3;
    int value4;

    for (beginHere = 0; beginHere < (SIZE -1); beginHere++)
    {
        index = beginHere;
        value = array[beginHere].itemSales;
        value2 = array[beginHere].id;
        value3 = array[beginHere].price;
        value4 = array[beginHere].numberSold;


        for (int count = beginHere +1; count < SIZE; count++)
        {
            if (array [count].itemSales < value)
            {
                value = array[count].itemSales;
                value2 = array [count].id;
                value3 = array[count].price;
                value4 = array [count].numberSold;
                index = count;
            }

        }
            array [index].itemSales = array[beginHere].itemSales;
            array [index].id = array[beginHere].id;
            array [index].price = array[beginHere].price;
            array [index].numberSold = array[beginHere].numberSold;
            array [beginHere].itemSales = value;
            array [beginHere].id = value2;
            array [beginHere].price = value3;
            array [beginHere].numberSold = value4;
    }
}

void sortedArray (Info array [], const int SIZE)
{
     cout << setw(65) << right << "Sorted Array of Structures: (by Sales) \n\n";

   for (int count = 0; count < SIZE; count++)
    {
        cout << setw(20) << left << "Product ID: ";
        cout << array[count].id << endl;
        cout << setw(20) << left << "Unit Price: ";
        cout << setprecision(2) << fixed << "$" << array[count].price << endl;
        cout << setw(20) << left << "Quantities Sold: ";
        cout << array[count].numberSold << endl;
        cout << setw(20) << left << "Sales: ";
        cout << setprecision(2) << fixed << "$" << array[count].itemSales << endl << endl;
    }
}

