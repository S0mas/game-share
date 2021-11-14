#pragma once

#include <string>
#include <QString>
#include <QSqlRecord>
#include <QSqlField>
#include <QVariant>
#include <QMetaType>

#define PARAM(variant_type, name) \
private: \
  void create_##name() { append(QSqlField(#name, QMetaType::fromType<variant_type>())); } \
public: \
  variant_type name() const { return field(#name).value().value<variant_type>(); } \
  void name(variant_type const& value) { setValue(#name, QVariant::fromValue(value)); }

#define STR_PARAM(name) PARAM(QString, name)
#define INT_PARAM(name) PARAM(int64_t, name)
#define DOUBLE_PARAM(name) PARAM(double, name)
