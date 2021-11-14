#pragma once

#include "macros.hpp"
#include <QSqlRecord>
#include <QSqlField>
#include <QVariant>
#include <QMetaType>

class game : public QSqlRecord {
public:
  game();
  game(QString const& code, QString const& name, QString const& description = "");
  game(QSqlRecord const& record);

  STR_PARAM(code)
  STR_PARAM(name)
  STR_PARAM(description)
  STR_PARAM(current_owner)

  auto is_available() const noexcept -> bool;
};
