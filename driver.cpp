#include <iostream>
#include <memory>
#include <typeinfo>

template<typename T>
class Linked_list : public std::enable_shared_from_this<Linked_list<T>>{
  T data;
  std::shared_ptr<Linked_list<T>> prev;
  std::shared_ptr<Linked_list<T>> succ;
public:
  Linked_list(const T d, std::shared_ptr<Linked_list<T>> p = nullptr, std::shared_ptr<Linked_list<T>> s = nullptr) : data{d}, prev{p}, succ{s} {}
  //~Linked_list(){ delete curr; }

  std::shared_ptr<Linked_list<T>> f(){ return this->shared_from_this(); }

  T get_data() const{ return data; }
  std::shared_ptr<Linked_list<T>> get_prev() const{ return prev; }
  std::shared_ptr<Linked_list<T>> get_succ() const{ return succ; }

  void set_prev(std::shared_ptr<Linked_list<T>> p) { prev = p; }
  void set_succ(std::shared_ptr<Linked_list<T>> s) { succ = s; }

  std::shared_ptr<Linked_list<T>> insert(std::shared_ptr<Linked_list<T>> n){
    if (n == nullptr) return this->f();
    if (this == nullptr) return n;
    /*std::cout << typeid(this).name() << '\n';
    std::cout << typeid(n).name() << '\n';*/
    std::shared_ptr<Linked_list<T>> s = this->f();
    n->succ = s;
    if (s->prev) s->prev->succ = n;
    n->prev = s->prev;
    s->prev = n;
    return n;
  }
};

template<typename T>
void print_ll(std::shared_ptr<Linked_list<T>> p){
  while (p){
    std::cout << p->get_data();
    if (p = p->get_succ()) std::cout << " --> ";
  }
  std::cout << '\n';
}

/*template<typename t>
void ll_data_entry(){

}*/

int main(){
  //Linked_list<std::string> ll("Marge");
  //std::shared_ptr<Linked_list<std::string>> lll = std::make_shared<Linked_list<std::string>>("Lisa");
  std::shared_ptr<Linked_list<std::string>> l = std::shared_ptr<Linked_list<std::string>>(new Linked_list<std::string>("Bart"));

  /*std::cout << typeid(ll).name() << '\n';
  std::cout << typeid(lll).name() << '\n';*/
  //std::cout << typeid(l).name() << '\n';

  //print_ll(l);

  std::shared_ptr<Linked_list<std::string>> p = std::shared_ptr<Linked_list<std::string>>(new Linked_list<std::string>("Homer"));
  //l->insert(std::shared_ptr<Linked_list<std::string>>(new Linked_list<std::string>("Lisa")));
  l = l->insert(p);
  print_ll(l);
}
