#pragma once
#include <iostream>
namespace ins {

template <typename elem_type> struct elem {
  elem *next_elem;
  elem *prev_elem;
  elem_type value;

  // Konstruktori
  elem() = default;
  elem(elem_type A) : value{A} {};

  // Destruktor
  // ~elem() { std::cout << "Gotov" << std::endl; }
};

template <typename elem_type> struct list {
private:
  elem<elem_type> *first_elem_;
  elem<elem_type> *last_elem_;
  unsigned long num_of_elem_ = 0;

public:
  struct iterator {
    elem<elem_type> *position;
    iterator &operator++() {
      this->position = this->position->next_elem;
      return *this;
    }
    iterator operator++(int) {
      iterator temp = *this;
      this->position = this->position->next_elem;
      return temp;
    }
    elem_type &operator*() { return this->position->value; };

    iterator &operator=(const iterator &IT) {
      this->position = IT.position;
      return *this;
    }

    bool operator!=(iterator IT) {
      if (IT.position == this->position)
        return false;
      return true;
    }
  };

  iterator begin() { return iterator{first_elem_}; };
  iterator end() { return iterator{last_elem_}; };
  unsigned long size() { return num_of_elem_; }

  void gurni_ga(elem_type za_gurnut) {
    elem<elem_type> *temp;
    temp = new elem{elem_type{}};
    last_elem_->value = za_gurnut;
    last_elem_->next_elem = temp;
    temp->prev_elem = last_elem_;
    last_elem_ = temp;
    last_elem_->next_elem = temp;
    num_of_elem_++;
  }

  void skini_ga(int k = 1) {

    for (int i = 0; i < k; i++) {
      last_elem_->prev_elem->next_elem = last_elem_->prev_elem;
      elem<elem_type> *temp = last_elem_;
      last_elem_ = last_elem_->prev_elem;
      num_of_elem_--;
      delete temp;
    }
  }

  void umetni_ga(elem_type za_umetnut, unsigned long poz) {
    elem<elem_type> *poz_elem = first_elem_;
    for (int i = 1; i < poz; i++) {
      poz_elem = poz_elem->next_elem;
    }
    elem<elem_type> *temp;
    temp = new elem{elem_type{}};
    temp->value = za_umetnut;
    temp->next_elem = poz_elem->next_elem;
    poz_elem->next_elem->prev_elem = temp;
    poz_elem->next_elem = temp;
    temp->prev_elem = poz_elem;
  }

  list() {
    first_elem_ = new elem{elem_type{}};
    first_elem_->next_elem = first_elem_;
    first_elem_->prev_elem = first_elem_;
    last_elem_ = first_elem_;
  };

  list(list &d) {
    num_of_elem_ = d.num_of_elem_;
    list();
    for (it = d.begin(); it != d.end(); it++) {
      (*this).gurni_ga(*it);
    }
  }
};

} // namespace ins
