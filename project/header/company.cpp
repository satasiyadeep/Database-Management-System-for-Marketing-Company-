#include <iostream>
#include "company.h"
#include <string>
#include <math.h>
#include <stdlib.h>
using namespace std;
company::company()
{
  head = NULL; // initialize head of company list as NULL
}
void company::add_company() // this function add new company in our database
{
  string c_name;
  cout << "\n\tEnter name of your company : ";
  cin >> c_name;

  node_company *newnode = new node_company();

  newnode->company_name = c_name;
  newnode->total_amount_of_profit = newnode->total_company_sale = newnode->total_number_of_products = 0;
  if (head == NULL)
    newnode->next = NULL;
  else
    newnode->next = head;

  head = newnode;
  newnode->products_head = NULL;
  node_company_product *temp = newnode->products_head;
  node_company *temp2 = newnode;
  add_product(temp, temp2); // this function add product in company's own product list
}

void company::add_product(node_company_product *temp, node_company *temp2) // this function add product in company's own product list
{
  cout << "\tEnter how many products you want to enter : ";
  int product;
  cin >> product;
  for(int i=1;i<=product;i++)
  {
    string p_name;
    int price_of_product;
    int commission;

    node_company_product *newnode = new node_company_product();
    if(i%10==1)
      cout << "\n\tEnter the name of "<<i<<"st product : ";
    else if(i%10==2)
      cout << "\n\tEnter the name of "<<i<<"nd product : ";
    else if(i%10==2)
      cout << "\n\tEnter the name of "<<i<<"rd product : ";
    else
      cout << "\n\tEnter the name of "<<i<<"th product : ";
    cin >> p_name;
    cout << "\tEnter the price of your product : ";
    cin >> price_of_product;
    cout << "\tEnter the commission rate: ";
    cin >> commission;

    newnode->product_name = p_name;
    newnode->price = price_of_product;
    newnode->commission_rate = commission;
    newnode->total_profit = newnode->total_sale = newnode->total_number_of_products = 0;

    if (temp == NULL)
      newnode->next = NULL;
    else
      newnode->next = temp;
      
    temp = newnode;
    temp2->products_head = temp;
  }
}

void company::print_all_products()
{
  system("CLS");

  cout << string(20, ' ');

  cout << "====================================================" << endl;
  node_company *temp = head;
  cout << string(20, ' ');

  cout << "|| INDEX || PRODUCT NAME ||  PRICE  ||  COMPANY   ||" << endl;
  cout << string(20, ' ');

  cout << "----------------------------------------------------" << endl;
  int index = 1;
  while (temp != NULL)
  {
    node_company_product *temp1 = temp->products_head;
    while (temp1 != NULL)
    {
      cout << string(20, ' ');
      cout << "|| " << index << string(5 - (((int)log10(index)) + 1), ' ') << " || " << temp1->product_name << string(12 - (temp1->product_name).length(), ' ') << " || " << temp1->price << string(7 - (((int)log10(temp1->price)) + 1), ' ') << " || " << temp->company_name << string(10 - (temp->company_name).length(), ' ') << " ||" << endl;
      temp1 = temp1->next;
      index++;
    }
    temp = temp->next;
  }
  cout << string(20, ' ');
  cout << "====================================================" << endl;
}