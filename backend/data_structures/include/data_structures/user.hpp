#pragma once

#include "macros.hpp"

class user : public QSqlRecord {
public:
  user();
  user(QString const& name, int const age);

  INT_PARAM(id)
  STR_PARAM(name)
  INT_PARAM(age)
};
