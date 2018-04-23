//TODO:
//ustalic jak ze zmywaniem, ustalic jak z zasobami (nie wiem czy klasa jest potrzebna)
#include "header.h"
#include "names.h"

string generateName();
void generateCooks(int number);
void generateFoods(int number);
void generateWaiters(int number);
void generateCleaninGuys(int number);
void generateClients();

vector<Cook> cooks;
vector<Waiter> waiters;
vector<CleaningGuy> ceaning_guys;
vector<Food> food_list;
vector<Order> orders;
vector<Clients> clients_list;


int main(){
  srand(time(NULL));

  Resources *res;
  res = new Resources();

  cout << "Kucharze:\n";
  generateCooks(5);
  for(int i = 0; i < cooks.size(); i++){
    cout << cooks[i].name << " " << cooks[i].cook_id << " " << cooks[i].status << " " << cooks[i].order_id << "\n";
  }

  cout << "Kelnerzy:\n";
  generateWaiters(5);
  for(int i = 0; i < waiters.size(); i++){
    cout << waiters[i].name << " " << waiters[i].waiter_id << " " << waiters[i].status << " " << waiters[i].order_id << " " << waiters[i].target_table_id << "\n";
  }

  return 0;
}

string generateName(){
  string name = table_with_names[rand() % (sizeof(table_with_names)/sizeof(*table_with_names))];
  return name;
}

void generateCooks(int number){
  Cook *c;
  for(int i = 0; i < number; i++){
    c = new Cook(generateName(), i);
    cooks.push_back(*c);
  }
  c = NULL;
}

void generateFood(int number);

void generateWaiters(int number){
  Waiter *w;

  for(int i = 0; i < number; i++){
    w = new Waiter(generateName(), i);
    waiters.push_back(*w);
  }
  w = NULL;
}
void generateCleaninGuys(int number);
void generateClients();
