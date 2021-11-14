#include "../include/data_structures/game.hpp"
#include <QDebug>
#include <QVariant>

game::game() {
  create_name();
  create_code();
  create_description();
  create_current_owner();
}

game::game(QString const& code, QString const& name, QString const& description) : game()
{
  this->code(code);
  this->name(name);
  this->description(description);
}

game::game(QSqlRecord const& record)
{
  for(int row = 0; row < record.count(); ++row) {
    append(record.field(row));
  }
}

auto game::is_available() const noexcept -> bool {
  return current_owner().isEmpty();
}
