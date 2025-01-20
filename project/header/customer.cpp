#include <iostream>
#include <string>
#include <math.h>
#include <stdlib.h>

#include "customer.h"
typedef unsigned long long ull;
using namespace std;

customer::customer()
{
    customer_head = NULL; // initialize customer head with NULL
}
node_customer *customer::search(ull phone) // this function search customer by their phone number
{
    node_customer *temp = customer_head;
    if (temp == NULL)
    {
        // if there is no any customer it returns adress of customer head
        return temp;
    }
    else
    {
        while (temp != NULL && temp->mobile_number != phone)
            temp = temp->next;
        if (temp == NULL)
        {
            node_customer *newnode = new node_customer();
            newnode->next = customer_head;
            newnode->product_detail_head = NULL;
            customer_head = newnode;
            return newnode;
        }
        else
            return temp;
    }
}
node_customer *customer::add_customer()// this function add basic detail of customer
{
    string name;
    string gmail;
    ull mobile_number;

    cout << "\n\tEnter your name: ";
    cin >> name;
    cout << "\tEnter your email: ";
    cin >> gmail;
    cout << "\tEnter your phone number: ";
    cin >> mobile_number;
    node_customer *p = search(mobile_number); // call search function for find customer 
    if (p == NULL)
    {
        node_customer *newnode = new node_customer();
        newnode->name = name;
        newnode->Gmail_ID = gmail;
        newnode->mobile_number = mobile_number;
        newnode->total_buyings = newnode->total_profit = 0;

        newnode->next = NULL;
        newnode->product_detail_head = NULL;
        customer_head = newnode;
        return newnode;
    }
    else
    {
        if (p->product_detail_head == NULL)
        {
            p->name = name;
            p->Gmail_ID = gmail;
            p->mobile_number = mobile_number;
            p->total_buyings = p->total_profit = 0;
        }
        return p;
    }
}
void customer::buy_product(int index, node_company *temp_company, node_customer *temp)// function for buying products
{
    // first we traverse all the products to reach the products at given index
    // start of travesing
    node_company_product *temp_product;
    while (index--)
    {
        temp_product = temp_company->products_head;
        while (temp_product != NULL && index != 0)
        {
            temp_product = temp_product->next;
            index--;
        }
        if (temp_product == NULL)
        {
            temp_company = temp_company->next;
            index++;
        }
        else
            break;
    }
    // end of travesing
    int number;
    cout << "\tEnter Quantity: ";
    cin >> number;
    // below four function are for add the basic detail and additional details 
    add_product_details(temp, temp_product, temp_company, number);
    add_customer_additional_details(temp, temp_product, number);
    add_additional_company(temp_company, temp_product, number);
    add_additional_products(temp_product, number);
}

void customer::add_customer_additional_details(node_customer *temp, node_company_product *temp_product, int number)
{
    temp->total_buyings = temp->total_buyings + (number * temp_product->price);
    temp->total_profit = temp->total_profit + ((number * temp_product->price) * (temp_product->commission_rate) / 100);
    temp->toal_product = temp->toal_product + (number);
}

void customer::add_product_details(node_customer *temp, node_company_product *temp_product, node_company *temp_company, int number)
{
    node_customer_product *newnode = new node_customer_product();

    newnode->name_of_product = temp_product->product_name;

    newnode->price_of_product = temp_product->price;
    newnode->number_of_products = number;
    newnode->total_cost = (number * newnode->price_of_product);
    newnode->name_of_company = temp_company->company_name;
    if (temp->product_detail_head == NULL)
        newnode->next = NULL;
    else
        newnode->next = temp->product_detail_head;
    temp->product_detail_head = newnode;
}

void company::add_additional_products(node_company_product *temp_product, int number)
{
    temp_product->total_sale = temp_product->total_sale + (number * temp_product->price);
    temp_product->total_profit = temp_product->total_profit + ((number * temp_product->price) * (temp_product->commission_rate) / 100);
    temp_product->total_number_of_products = temp_product->total_number_of_products + number;
}

void company::add_additional_company(node_company *temp_company, node_company_product *temp_product, int number)
{
    temp_company->total_company_sale = temp_company->total_company_sale + (number * temp_product->price);
    temp_company->total_amount_of_profit = temp_company->total_amount_of_profit + ((number * temp_product->price) * (temp_product->commission_rate) / 100);
    temp_company->total_number_of_products = temp_company->total_number_of_products + number;
}

void customer::print_customer_list() // this function print list of all customer in our database
{
    system("CLS");
    cout << "==============================================================================================================" << endl;
    node_customer *temp = customer_head;
    cout << "|| NAME         || Gmail ID             || MO. NUMBER || TOTAL PRODUCTS BUY || TOTAL BUYING || TOTAL PROFIT ||" << endl;
    cout << "--------------------------------------------------------------------------------------------------------------" << endl;

    while (temp != NULL)
    {
        cout << "|| " << temp->name << string(12 - (temp->name).length(), ' ') << " || " << temp->Gmail_ID << string(20 - (temp->Gmail_ID).length(), ' ') << " || " << temp->mobile_number << " || " << temp->toal_product << string(18 - ((int)log10(temp->toal_product) + 1), ' ') << " || " << temp->total_buyings << string(12 - ((int)log10(temp->total_buyings) + 1), ' ') << " || " << temp->total_profit << string(12 - ((int)log10(temp->total_profit) + 1), ' ') << "||" << endl;
        temp = temp->next;
    }
    cout << "==============================================================================================================" << endl;
}

void customer::print_customer_wise_product_details() // this function print list of customer wise products details
{
    system("CLS");
    node_customer *temp_customer = customer_head;
    node_customer_product *temp_product;
    cout << "=========================================================================================" << endl;
    cout << "|| NAME         || PRODUCT    || COMPANY    || PRICE      || QUANTITY || TOTAL COST   ||" << endl;
    cout << "-----------------------------------------------------------------------------------------" << endl;

    while (temp_customer != NULL)
    {
        cout << "|| " << temp_customer->name << string(12 - (temp_customer->name).length(), ' ') << " || " << string(10, ' ') << " || " << string(10, ' ') << " || " << string(10, ' ') << " || " << string(8, ' ') << " || " << string(12, ' ') << " || " << endl;
        temp_product = temp_customer->product_detail_head;
        while (temp_product != NULL)
        {
            cout << "|| " << string(12, ' ') << " || " << temp_product->name_of_product << string(10 - (temp_product->name_of_product).length(), ' ') << " || " << temp_product->name_of_company << string(10 - (temp_product->name_of_company).length(), ' ') << " || " << temp_product->price_of_product << string(10 - ((int)log10(temp_product->price_of_product) + 1), ' ') << " || " << temp_product->number_of_products << string(7 - ((int)log10(temp_product->number_of_products)), ' ') << " || " << temp_product->total_cost << string(11 - ((int)log10(temp_product->total_cost)), ' ') << " ||" << endl;
            temp_product = temp_product->next;
        }
        temp_customer = temp_customer->next;
    }
    cout << "=========================================================================================" << endl;
}