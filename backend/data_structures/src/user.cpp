#include "../include/data_structures/user.hpp"

user::user() {
  create_id();
  create_name();
  create_age();
}

user::user(QString const& name, int const age) : user()
{
  this->name(name);
  this->age(age);
}
