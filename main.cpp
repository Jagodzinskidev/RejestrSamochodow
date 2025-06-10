#include <iostream>
#include "Registry.h"

int main() {
    Registry registry;
    int choice;

    while (true) {
        std::cout << "\n=== REJESTR SAMOCHODOW ===\n";
        std::cout << "1. Dodaj auto\n";
        std::cout << "2. Usun auto\n";
        std::cout << "3. Edytuj auto\n";
        std::cout << "4. Wyswietl wszystkie auta\n";
        std::cout << "5. Wyjscie\n";
        std::cout << "6. Wyszukaj auto\n";
        std::cout << "Wybor: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string brand;
                int year, mileage;
                std::cout << "Marka: ";
                std::cin >> brand;
                std::cout << "Rok zakupu: ";
                std::cin >> year;
                std::cout << "Przebieg [km]: ";
                std::cin >> mileage;
                registry.addCar(brand, year, mileage);
                break;
            }
            case 2: {
                int index;
                std::cout << "Indeks auta do usuniecia: ";
                std::cin >> index;
                registry.deleteCar(index);
                break;
            }
            case 3: {
                int index;
                std::string brand;
                int year, mileage;
                std::cout << "Indeks auta do edycji: ";
                std::cin >> index;
                std::cout << "Nowa marka: ";
                std::cin >> brand;
                std::cout << "Nowy rok zakupu: ";
                std::cin >> year;
                std::cout << "Nowy przebieg: ";
                std::cin >> mileage;
                registry.editCar(index, brand, year, mileage);
                break;
            }
            case 4:
                registry.displayAll();
                break;
            case 5:
                std::cout << "Zamykanie programu...\n";
                return 0;
            case 6: {
                int searchChoice;
                std::cout << "Wyszukaj po:\n";
                std::cout << "1. Marka\n";
                std::cout << "2. Rocznik\n";
                std::cout << "3. Maksymalny przebieg\n";
                std::cout << "Wybor: ";
                std::cin >> searchChoice;
                switch (searchChoice) {
                    case 1: {
                        std::string brand;
                        std::cout << "Podaj marke: ";
                        std::cin >> brand;
                        registry.searchByBrand(brand);
                        break;
                    }
                    case 2: {
                        int year;
                        std::cout << "Podaj rocznik: ";
                        std::cin >> year;
                        registry.searchByYear(year);
                        break;
                    }
                    case 3: {
                        int maxMileage;
                        std::cout << "Podaj maksymalny przebieg: ";
                        std::cin >> maxMileage;
                        registry.searchByMaxMileage(maxMileage);
                        break;
                    }
                    default:
                        std::cout << "Nieprawidlowy wybor!\n";
                }
                break;
            }
            default:
                std::cout << "Nieprawidlowy wybor!\n";
        }
    }

    return 0;
}