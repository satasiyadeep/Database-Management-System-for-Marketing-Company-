#pragma once
#include "node_customer.h"
#include "company.h"
// #include "node_company.h"
// #include "node_company_product.h"
typedef unsigned long long ull;

class customer : public company, public node_company
{
private:
    node_customer *customer_head;
    // node_company *head;

public:
    customer();
    node_customer *search(ull);
    node_customer *add_customer();
    void buy_product(int, node_company *,node_customer *);
    void add_customer_additional_details(node_customer *, node_company_product *, int);
    void add_product_details(node_customer *, node_company_product *, node_company *, int);
    void print_customer_list();
    void print_customer_wise_product_details();
    friend class company;
    friend class node_company;
    friend class node_company_product;

    friend class node_customer;
    friend class node_customer_product;
};
