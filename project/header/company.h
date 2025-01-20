#pragma once
#include "node_company.h"
class company 
{
protected:
public:
    node_company *head;

    company();
    void add_company();
    void add_product(node_company_product *, node_company *);
    // void print();
    void print_all_products();
    void add_additional_products(node_company_product *, int);
    void add_additional_company(node_company *, node_company_product *, int);
    friend class customer;
    friend class node_company;
    friend class node_company_product;
    friend class node_custom;
    friend class node_custom_product;
};
