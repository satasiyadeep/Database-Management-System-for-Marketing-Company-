#pragma once
#include <string>
using namespace std;
class node_company_product
{
    // protected:
    //     float commission_rate;
    //     string product_name;
    //     float price;
    //     float total_sale;
    //     float total_profit;
    //     int total_number_of_products;
    //     node_company_product *next;

public:
    float commission_rate;
    string product_name;
    float price;
    float total_sale;
    float total_profit;
    int total_number_of_products;
    node_company_product *next;
    friend class node_company;
    friend class company;
    friend class customer;
    friend class node_customer;
    friend class node_customer_product;
};
