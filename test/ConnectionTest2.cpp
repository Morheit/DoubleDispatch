/* Copyright (c) 2018 Yaroslav Stanislavyk <stl.ros@outlook.com> */

#include <gtest/gtest.h>

#include "ConnectionDispatcher.hpp"
#include "DBConnection2.hpp"

namespace {

int GetMySqlConnection2Info(DoubleDispatch::IDBConnection& db_connection) {
  DoubleDispatch::MySqlConnectionDispatcher mysql_connection_dispatcher;
  db_connection.Dispatch(mysql_connection_dispatcher);

  if (nullptr == mysql_connection_dispatcher.connection()) {
    return 0;
  }

  return mysql_connection_dispatcher.connection()->Query();
}

std::string GetMySqlConnection2AdvancedInfo(
    DoubleDispatch::IDBConnection& db_connection) {
  DoubleDispatch::MySqlConnectionDispatcher mysql_connection_dispatcher;
  db_connection.Dispatch(mysql_connection_dispatcher);

  if (nullptr == mysql_connection_dispatcher.connection()) {
    return std::string();
  }

  return mysql_connection_dispatcher.connection()
      ->AdvancedQuery()
      .server_version;
}

int GetSqLiteConnection2Info(DoubleDispatch::IDBConnection& db_connection) {
  DoubleDispatch::SqLiteConnectionDispatcher sqlite_connection_dispatcher;
  db_connection.Dispatch(sqlite_connection_dispatcher);

  if (nullptr == sqlite_connection_dispatcher.connection()) {
    return 0;
  }

  return sqlite_connection_dispatcher.connection()->Query();
}

TEST(MySqlDBConnection2Test, GetInfoTest) {
  DoubleDispatch::MySqlDBConnection mysql_connection("4.2.2 MySQL Server", 10);
  DoubleDispatch::SqLiteDBConnection sqlite_connection(2);

  ASSERT_EQ(10, GetMySqlConnection2Info(mysql_connection));
  ASSERT_EQ(0, GetMySqlConnection2Info(sqlite_connection));
}

TEST(MySqlDBConnection2Test, GetAdvancedInfo) {
  DoubleDispatch::MySqlDBConnection mysql_connection("4.2.2 MySQL Server", 10);
  DoubleDispatch::SqLiteDBConnection sqlite_connection(2);

  ASSERT_EQ("4.2.2 MySQL Server",
            GetMySqlConnection2AdvancedInfo(mysql_connection));
  ASSERT_EQ("", GetMySqlConnection2AdvancedInfo(sqlite_connection));
}

TEST(PassWrongChildrensTest, SqLiteAndMySql) {
  DoubleDispatch::SqLiteDBConnection sqlite_connection(7);
  DoubleDispatch::MySqlDBConnection mysql_connection("Some SQL server", 8);

  ASSERT_EQ(0, GetSqLiteConnection2Info(mysql_connection));
  ASSERT_EQ(0, GetMySqlConnection2Info(sqlite_connection));
}

}  // namespace
