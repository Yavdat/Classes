#include <iostream>

using namespace std;

class Route {
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

/*
Структура(struct) - набор публичных полей
используем, если не нужно контролировать консистентность
*/
/*
Класс(class) скрывает данные, предоставляя определенный интерфейс доступа к ним
используем, если поля связаны друг с другом и эту связь нужно контролировать.
*/

int main() {
    Route route;
    route.GetSource() = "Moscow"; // бесполезное присваивание

    cout << route.GetLength();

    int destination_name_length = route.GetDestination().length();
    return 0;
}