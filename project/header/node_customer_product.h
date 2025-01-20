#pragma once

#include <string>
using namespace std;
class node_customer_product
{
private:
    string name_of_product;
    string name_of_company;
    float price_of_product;
    int number_of_products; // number of products customer buy 
    float total_cost; // total cost of perticular products 
    node_customer_product *next;

public:
    friend class node_customer;
    friend class customer;
    friend class company;
    friend class node_company;
    friend class node_company_product;
};
