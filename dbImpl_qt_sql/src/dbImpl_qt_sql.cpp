#include "../include/dbImpl_qt_sql/dbImpl_qt_sql.h"
#include <loguru/loguru.hpp>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlTableModel>
#include <QSqlField>
#include <QSqlError>
#include <QString>

void dbImpl_qt_sql::init()
{
  FUNCTION_START_DEBUG_LOG;

  auto db = QSqlDatabase::addDatabase("QSQLITE");
  db.setDatabaseName("custom_db_testABCD.sqlite");
  bool ok = db.open();

  db.exec("CREATE TABLE games (code varchar(255) NOT NULL PRIMARY KEY, name varchar(255) NOT NULL, description varchar(255), current_owner varchar(255) )");
  db.exec("CREATE TABLE users ("
          "id INTEGER PRIMARY KEY AUTOINCREMENT DEFAULT 1,"
          "name varchar(255),"
          "age integer"
          ")");
}

void dbImpl_qt_sql::createTable(QString const& table) {
  FUNCTION_START_DEBUG_LOG;
}

bool check_conditions(QSqlRecord const& record, QSqlRecord const& conditions) {
  for (int conditionId = 0; conditionId < conditions.count(); ++conditionId) {
    if (conditions.value(conditionId) != record.value(conditions.fieldName(conditionId))) {
      return false;
    }
  }
  return true;
}

std::vector<int> get_rows(QString const& table_name, QSqlRecord const& conditions) {
  QSqlTableModel model;
  model.setTable(table_name);
  model.select();

  std::vector<int> rows;

  for (int row = 0; row < model.rowCount(); ++row) {
    if (check_conditions(model.record(row), conditions)) {
      rows.push_back(row);
    }
  }
  return rows;
}

void dbImpl_qt_sql::insertRecord(QString const& table_name, QSqlRecord const& record) {
  FUNCTION_START_DEBUG_LOG;

  QSqlTableModel model;
  model.setTable(table_name);
  model.select();

  model.insertRecord(-1, record);
  model.submitAll();
}

void dbImpl_qt_sql::modifyRecord(QString const& table_name, QSqlRecord const& modifications, QSqlRecord const& conditions) {
  FUNCTION_START_DEBUG_LOG;
  auto rows = get_rows(table_name, conditions);

  QSqlTableModel model;
  model.setTable(table_name);
  model.select();

  for (auto row : rows) {
    model.setRecord(row, modifications);
  }
}

void dbImpl_qt_sql::deleteRecord(QString const& table_name, QSqlRecord const& conditions) {
  FUNCTION_START_DEBUG_LOG;
  auto rows = get_rows(table_name, conditions);

  QSqlTableModel model;
  model.setTable(table_name);
  model.select();

  for (auto row : rows) {
    model.removeRows(row, 1);
  }
  model.select();
}

std::vector<QSqlRecord> dbImpl_qt_sql::allRecords(QString const& table_name) {
  FUNCTION_START_DEBUG_LOG;

  QSqlTableModel model;
  model.setTable(table_name);
  model.select();

  std::vector<QSqlRecord> records;
  for (int row = 0; row < model.rowCount(); ++row) {
    records.push_back(model.record(row));
  }
  return records;
}

std::vector<QSqlRecord> dbImpl_qt_sql::findRecords(QString const& table_name, QSqlRecord const& conditions) {
  FUNCTION_START_DEBUG_LOG;
  QSqlTableModel model;
  model.setTable(table_name);
  model.select();

  auto rows = get_rows(table_name, conditions);
  std::vector<QSqlRecord> records;
  for (auto row : rows) {
    records.push_back(model.record(row));
  }
  return records;
}
