#include <iostream>
#include <typeinfo>

class Link{
  Link* prev;
  Link* succ;
public:
  std::string value;
  Link(const std::string& v, Link* p = nullptr, Link* s = nullptr) : value{v}, prev{p}, succ{s} {}

  Link* next() const{ return succ; }

  void insert(Link* n){
    if (n == nullptr) return;
    if (this == nullptr) return;
    n->succ = this;
    std::cout << typeid(this).name() << '\n';
    std::cout << typeid(n).name() << '\n';
  }
};

void print_all(Link* p){
  while (p){
    std::cout << p->value;
    if (p = p->next()) std::cout << " --> ";
  }
  std::cout << '\n';
}

int main(){
  Link* norse = new Link{"Thor"};
  std::cout << typeid(norse).name() << '\n';
  print_all(norse);
  norse->insert(new Link{"Lisa"});
  //print_all(norse);
}
