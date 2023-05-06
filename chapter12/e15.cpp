#include <iostream>
#include <memory>

using namespace std;

struct destination{};
struct connection{};

connection connect(destination *pd)
{
    cout << "Connect to the server." << endl;
    return connection();
}

void disconnect(connection c)
{
    cout << "Disconnect from the server." << endl;
}

/*
void end_connection(connection *p)
{
    disconnect(*p);
}
*/

void f(destination &d)
{
    cout << "Use shared_ptr manage connect." << endl;
    connection c = connect(&d);
    shared_ptr<connection> p(&c, [](connection *p){disconnect(*p);});
    cout << "Use the connection." << endl;
}

int main()
{
    destination dest;
    f(dest);

    return 0;
}