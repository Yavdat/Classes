#include <iostream>

using namespace std;

int ComputeDistance(const string& source,const string& destination) {
    return source.length() - destination.length();
}

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
    void SetSource(const string& new_source) {
        source = new_source;
        UpdateLength();
    }
    void SetDestination(const string& new_destination) {
        destination = new_destination;
        UpdateLength();
    }

private:
    string source;
    string destination;
    int length;

    void UpdateLength() {
        length = ComputeDistance(source, destination);
    }

}; 

/*
Структура(struct) - набор публичных полей
используем, если не нужно контролировать консистентность
*/
/*
Класс(class) скрывает данные, предоставляя определенный интерфейс доступа к ним
используем, если поля связаны друг с другом и эту связь нужно контролировать.

Делал поля приватными, чтобы использование класса было более безопасным.
Планировал, что класс сам будет при необходимости обновлять длину маршрута.
*/

int main() {
    Route route;
    route.GetSource() = "Moscow"; // бесполезное присваивание

    cout << route.GetLength();

    int destination_name_length = route.GetDestination().length();
    return 0;
}