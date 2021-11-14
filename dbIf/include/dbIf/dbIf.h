#pragma once
#include <string>
#include <vector>
#include <stdexcept>
#include <format>
#include <variant>
#include <algorithm>
#include <map>

#include <QSqlRecord>

class dbIf {
public:
  virtual auto init() -> void = 0;
  virtual auto createTable(QString const& table) -> void = 0;
  virtual auto insertRecord(QString const& table_name, QSqlRecord const& record) -> void = 0;
  virtual auto modifyRecord(QString const& table_name, QSqlRecord const& modifications, QSqlRecord const& conditions = {}) -> void = 0;
  virtual auto deleteRecord(QString const& table_name, QSqlRecord const& conditions = {}) -> void = 0;
  virtual auto allRecords(QString const& table_name) -> std::vector<QSqlRecord> = 0;
  virtual auto findRecords(QString const& table_name, QSqlRecord const& conditions = {}) -> std::vector<QSqlRecord> = 0;
};
