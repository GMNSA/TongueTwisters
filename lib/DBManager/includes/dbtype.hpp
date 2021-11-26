#ifndef DB_TYPE_HPP
#define DB_TYPE_HPP

#include <QMap>

enum eError
{
  OK = 0,
  ERROR_DRIVER,
  ERROR_WORKSPACE,
  ERROR_DATABASE_OPEN,
  ERROR_DATABASE_COPY,
};

static const QMap<QString, QString> gDBaseArgs{
  { "Classics", "text" },
  { "Poems", "text" },
  { "Voice", "text" },
  { "Breathing", "text" },
};

enum eDBType
{
  CLASSICS = 0,
  VOICE,
  BREATHING,
  POEMS
};

static const QMap<eDBType, QString> gNameDbType{
  { eDBType::CLASSICS, "Classics" },
  { eDBType::BREATHING, "Breathing" },
  { eDBType::POEMS, "Poems" },
  { eDBType::VOICE, "Voice" },
};

#endif // DB_TYPE_HPP
