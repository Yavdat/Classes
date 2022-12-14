#include <iostream>

using namespace std;

struct Route {
public:
    string GetSource() {
        return source;
    }
    string GetDestination() {
        return destination;
    }
    int GetLength() {
        return length;
    }
private:
    string source;
    string destination;
    int length;
}; 

int main() {
    Route route;
    route.GetSource() = "Moscow"; // бесполезное присваивание

    cout << route.GetLength();

    int destination_name_length = route.GetDestination().length();
    return 0;
}