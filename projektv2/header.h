#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

class Resources{

public:
  int tables;
  int plates;
  int cutlery;
  int bowls;
  int pans;
  int pots;
  int wooden_spoons;
  int knives;
  int specials;

  Resources(){
    this->tables = 10;
    this->plates = 50;
    this->cutlery = 50;
    this->bowls = 50;
    this->pans = 20;
    this->pots = 20;
    this->wooden_spoons = 20;
    this->knives = 30;
    this->specials = 15;
  }
};

class Food{
public:
  string name;
  //string *needed_items;
  vector<int> needed_items;
  int prep_time;

  Food(string name, vector<int> needed_items, int prep_time){
    this->name = name;
    this->needed_items = needed_items;
    this->prep_time = prep_time;
  }
};

class Clients{
public:
  int clients_id;
  int clients_number;
  vector <string> names;
  int table_status; //0 - no table, 1 - waiting for waiter, 2 - waiting for food, 3 - eating
  vector <Food> orders;
  int table_number;

  Clients(int clients_id, int clients_number, vector<string> names){
    this->clients_id = clients_id;
    this->clients_number = clients_number;
    this->names = names;
    this->table_status = 0;
    this->orders.clear();
    this->table_number = 0;
  }
};

class Cook{
public:
  string name;
  int cook_id;
  int status;
  int order_id;
  vector<int> dish_status;

  Cook(string name, int cook_id){
    this->name = name;
    this->cook_id = cook_id;
    this->status = 0;
    this->order_id = 0;
    this->dish_status.clear();
  }
};

class Waiter{
public:
  int waiter_id;
  string name;
  int status;
  int order_id;
  int target_table_id;

  Waiter(string name, int waiter_id){
    this->waiter_id = waiter_id;
    this->name = name;
    this->status = 0;
    this->order_id = 0;
    this->target_table_id = 0;
  }
};

class Order{
public:
  int order_id;
  bool order_status;
  vector<Food> order_list;
  int table_id;

  Order(int order_id, bool order_status, vector<Food> order_list, int table_id){
    this->order_id = order_id;
    this->order_status = order_status;
    this->order_list = order_list;
    this->table_id = table_id;
  }

};

class CleaningGuy{
public:
  int cleaningguy_id;
  string name;
  int status;
  int co_zmywa;
};
