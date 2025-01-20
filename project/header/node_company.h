#pragma once
#include <string>
#include "node_company_product.h"
using namespace std;
class node_company
{
public:
    string company_name;
    float total_company_sale;
    float total_amount_of_profit;
    int total_number_of_products;
    node_company_product *products_head;
    node_company *next;
    friend class company;
    friend class node_company_product;
    friend class customer;
    friend class node_customer_product;
    friend class node_customer;
};
