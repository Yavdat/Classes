#include <iostream>
#include <vector>

using namespace std;

int ComputeDistance(const string& source,const string& destination) {
    return source.length() - destination.length();
}

class Route {
public:
    Route() {};
    Route(const string& new_source, const string& new_destination) {
        this->source = new_source;
        this->destination = new_destination;
        UpdateLength();
    }
    ~Route() {
        for (const string& entry : compute_distance_log) {
            cout << entry << "\n";
        }
    }
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
    vector<string> compute_distance_log;

    void UpdateLength() {
        length = ComputeDistance(source, destination);
        compute_distance_log.push_back(source + "-" + destination);
    }

};

Route BuildRoute(const string& source, const string& destination) {
    Route route;
    route.SetSource(source);
    route.SetDestination(destination);
    return route;
}

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
    
    PrintRoute(Route());
    PrintRoute({});

    // Route route("Moscow", "Nizhniy Novgorod");
    route.GetSource() = "Moscow"; // бесполезное присваивание


    int destination_name_length = route.GetDestination().length();

    route.SetSource("Moscow");
    route.SetDestination("Vologda");

    PrintRoute(route);

    cout << "route lentgh: " << route.GetLength() << endl;

    ReverseRoute(route);
    PrintRoute(route);

    Route route2 = BuildRoute("Ufa", "Kazan");
    PrintRoute(route2);
    cout << "route lentgh: " << route2.GetLength() << endl;

    vector<Route> routes;
    routes.push_back({"Khimki", "Konakovo"});

    return 0;
}