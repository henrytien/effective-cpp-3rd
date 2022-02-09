#include <iostream>
#include <vector>

class Widget {
public:
  Widget() {}
  ~Widget() {} // assume this might emit an exception
};

void doSomething() {
  std::vector<Widget> v;
} // v is automatically destroyed here

class DBConnection {
public:
  DBConnection() {}
  ~DBConnection() {}
  static DBConnection create(); // function to return
  // DBConnection objects; params
  // omitted for simplicity
  void close(); // close connection; throw an
                // exception if closing fails
};
DBConnection DBConnection::create() {
  static DBConnection db;
  return db;
}
void DBConnection::close() {}

class DBConn { // class to manage DBConnection
public:        // objects
  DBConn(const DBConnection &d, bool c) : db(d), closed(c) {}
  ~DBConn() // make sure database connections
  {         // are always closed
    // db.close();
    if (!closed) {
      try {
        db.close();
      } catch (const std::exception &) {
        // log
      }
    }
  }
  void close() {
    db.close();
    closed = true;
  }

private:
  DBConnection db;
  bool closed;
};

int main() {
  std::cout << "Item 8: Prevent exceptions from leaving destructors."
            << std::endl;

  DBConn dbc(DBConnection::create(), false); // create DBConnection object
                                             // and turn it over to a DBConn
                                             // object to manage
  return 0;
}