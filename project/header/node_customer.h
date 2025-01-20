#pragma once
#include <string>
#include "node_customer_product.h"
using namespace std;
typedef unsigned long long ull;

class node_customer
{
private:
    string name;
    string Gmail_ID;
    ull mobile_number;
    float total_buyings; // total_buyings of perticular customer
    float total_profit; // total_profit we made from perticular customer
    int toal_product; // total product that perticular customer had bought
    node_customer_product *product_detail_head; // head of list of product list of perticular customer
    node_customer *next;

public:
    friend class customer;
    friend class company;
    friend class node_company;
    friend class node_company_product;

    friend class node_customer_product;
};
