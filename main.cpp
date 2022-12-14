#include <iostream>

using namespace std;

int ComputeDistance(const string& source,const string& destination) {
    return source.length() - destination.length();
}

class Route {
public:
    // указываем что метод не имеет права менять объект
    string GetSource() const {
        return source;
    }
    string GetDestination() const {
        return destination;
    }
    int GetLength() const {
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

void PrintRoute(const Route& route) {
    cout << route.GetSource() << " - " <<
        route.GetDestination() << "\n";
}

void ReverseRoute(Route& route) {
    string old_source = route.GetSource();
    string old_destination = route.GetDestination();
    route.SetSource(old_destination);
    route.SetDestination(old_source);
}
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

    route.SetSource("Moscow");
    route.SetDestination("Vologda");
    PrintRoute(route);
    return 0;
}