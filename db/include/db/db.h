#pragma once
#include <dbImpl_qt_sql/dbImpl_qt_sql.h>
#include <data_structures/game.hpp>
#include <data_structures/user.hpp>
#include <QSqlDatabase>
#include <QSqlQuery>

class dbIf;

class db {
public:
  db() {
    database_ = std::make_unique<dbImpl_qt_sql>();
    database_->init();
  }

  auto add(QString const& table_name, QSqlRecord const& record) const -> void {
    database_->insertRecord(table_name, record);
  }

  auto find(QString const& table_name, QSqlRecord const& record) const -> std::vector<QSqlRecord> {
    return database_->findRecords(table_name, record);
  }

  auto remove(QString const& table_name, QSqlRecord const& record) const -> void {
    return database_->deleteRecord(table_name, record);
  }

  auto modify(QString const& table_name, QSqlRecord const& record_with_modifications, QSqlRecord const& record_with_conditions) const -> void {
    return database_->modifyRecord(table_name, record_with_modifications, record_with_conditions);
  }

  auto get(QString const& table_name) const -> std::vector<QSqlRecord> {
    return database_->allRecords(table_name);
  }
private:
  std::unique_ptr<dbIf> database_;
};
