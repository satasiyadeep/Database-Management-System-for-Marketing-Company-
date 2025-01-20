#include <iostream>
#include <string>
#include <stdlib.h>
#include <conio.h>
#include "../header/company.cpp"
#include "../header/customer.cpp"
using namespace std;

void dashboard();

int main()
{
    company company_list;   // object for company
    customer customer_list; // object for customer
    while (1)
    {
        dashboard(); // for display dashboard
        int choice;
        cout<<"\n\n\tEnter your choice : ";
        cin >> choice;
        char e;
        node_customer *new_customer;
        switch (choice)
        {
        case 1:
            company_list.add_company(); // this function add new company
            break;
        case 2:
            company_list.print_all_products(); // this function print all products we have
            int n, index;
            cout << "\tEnter how many products you want to buy : ";
            cin >> n;
            new_customer = customer_list.add_customer();
            while (n--)
            {
                cout << "\tEnter index of product that you want to buy : ";
                cin >> index;
                customer_list.buy_product(index, company_list.head, new_customer); // this function add new customer in our database
            }
            break;
        case 3:
            customer_list.print_customer_list(); // this function print customer list
        exit_lable:
        {
        }
            cout << "\tEnter \"e\" for exit : ";
            cin >> e;
            if (e == 'e')
                break;
            else
                goto exit_lable;
        case 4:
            company_list.print_all_products(); // this function print list of  all products
        exit_lable2:
        {
        }
            cout << "\tEnter \"e\" for exit : ";
            cin >> e;
            if (e == 'e')
                break;
            else
                goto exit_lable2;
        case 5:
            customer_list.print_customer_wise_product_details(); // this function print list of customer wise product details
        exit_lable1:
        {
        }
            cout << "\tEnter \"e\" for exit : ";
            cin >> e;
            if (e == 'e')
                break;
            else
                goto exit_lable1;
        case 6:
            system("CLS"); // for clear screen
            exit(0);       // for end of program
            break;
        }
    }
    return 0;
}

void dashboard() // this function print dashboard
{
    system("CLS");
    
    cout << string(18, ' ');
    cout << "==================================================================================================" << endl;
    cout << string(18, ' ');

    cout << "||" << string(30, ' ') << "||" << string(30, ' ') << "||" << string(30, ' ') << "||" << endl;
    cout << string(18, ' ');

    cout << "||" << string(10, ' ') << "1. COMPANY" << string(10, ' ') << "||" << string(9, ' ') << "2. CUSTOMER" << string(10, ' ') << "||" << string(7, ' ') << "3. CUSTOMER LIST" << string(7, ' ') << "||" << endl;
    cout << string(18, ' ');

    cout << "||" << string(30, ' ') << "||" << string(30, ' ') << "||" << string(30, ' ') << "||" << endl;
    cout << string(18, ' ');

    cout << "==================================================================================================" << endl;
    cout << string(18, ' ');

    cout << "||" << string(30, ' ') << "||" << string(30, ' ') << "||" << string(30, ' ') << "||" << endl;
    cout << string(18, ' ');

    cout << "||" << string(6, ' ') << "4. PRODUCT DETAILS" << string(6, ' ') << "||" << string(7, ' ') << "5. CUSTOMER WISE" << string(7, ' ') << "||" << string(11, ' ') << "6. EXIT" << string(12, ' ') << "||" << endl;
    cout << string(18, ' ');

    cout << "||" << string(30, ' ') << "||" << string(30, ' ') << "||" << string(30, ' ') << "||" << endl;
    cout << string(18, ' ');

    cout << "==================================================================================================" << endl;
}