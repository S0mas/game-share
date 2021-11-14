#pragma once
#include <db/db.h>
#include <QObject>
#include <QDebug>

class interface : public QObject {
  Q_OBJECT

  db database;
public:
  Q_INVOKABLE QStringList get_games() {
    auto games = database.get("games");
    QStringList list;
    for(auto const& game : games) {
      list << game.field("name").value().toString();
    }
    return list;
  }

  Q_INVOKABLE void add_game(QString const& c, QString const& n, QString const& d, QString const& o = "") {
    game g(c, n, d);
    g.current_owner(o);
    database.add("games", g);
  }

  Q_INVOKABLE void remove_game(QString const& code) {
    game g;
    g.code(code);
    database.remove("games", g);
  }

  Q_INVOKABLE void find_game() {}   //TODO

  Q_INVOKABLE void modify_game() {} //TODO

  Q_INVOKABLE QStringList get_users() {
    auto users = database.get("users");
    QStringList list;
    for(auto const& user : users) {
      list << user.field("name").value().toString();
    }
    return list;
  }

  Q_INVOKABLE void add_user(QString const& n, int const a) {
    user u(n, a);
    database.add("users", u);
  }

  Q_INVOKABLE void remove_user(int const id) {
    user u;
    u.id(id);
    database.remove("users", u);
  }

  Q_INVOKABLE void find_user() {}               //TODO

  Q_INVOKABLE void modify_user() {}             //TODO
};
