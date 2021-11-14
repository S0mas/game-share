#pragma once
#include <dbIf/dbIf.h>

class dbImpl_qt_sql : public dbIf {
public:
  auto init() -> void override;
  auto createTable(QString const& table) -> void override;

  auto insertRecord(QString const& table_name, QSqlRecord const& record) -> void override;
  auto modifyRecord(QString const& table_name, QSqlRecord const& modifications, QSqlRecord const& conditions = {}) -> void override;
  auto deleteRecord(QString const& table_name, QSqlRecord const& conditions) -> void override;
  auto allRecords(QString const& table_name) -> std::vector<QSqlRecord> override;
  auto findRecords(QString const& table_name, QSqlRecord const& conditions = {}) -> std::vector<QSqlRecord> override;
};
