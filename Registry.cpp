//
// Created by Seweryn on 10.06.2025.
//
#include "Registry.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>

Registry::Registry() {
    cars = nullptr;
    size = 0;
}

Registry::~Registry() {
    for (int i = 0; i < size; ++i) {
        delete cars[i];
    }
    free(cars);
}

void Registry::addCar(const std::string& brand, const std::string& model, int year, int mileage) {
    Car** newCars = (Car**)realloc(cars, (size + 1) * sizeof(Car*));
    if (newCars == nullptr) {
        std::cerr << "Blad alokacji pamieci!\n";
        return;
    }
    cars = newCars;
    cars[size] = new Car(brand, model, year, mileage);
    ++size;
}

void Registry::deleteCar(int index) {
    if (index < 0 || index >= size) {
        std::cout << "Nieprawidlowy indeks!\n";
        return;
    }

    delete cars[index];

    for (int i = index; i < size - 1; ++i) {
        cars[i] = cars[i + 1];
    }

    --size;
    Car** newCars = (Car**)realloc(cars, size * sizeof(Car*));
    if (newCars != nullptr || size == 0) {
        cars = newCars;
    }
}

void Registry::editCar(int index, const std::string& brand, const std::string& model, int year, int mileage) {
    if (index < 0 || index >= size) {
        std::cout << "Nieprawidlowy indeks!\n";
        return;
    }
    cars[index]->edit(brand, model, year, mileage);
}

void Registry::displayAll() const {
    if (size == 0) {
        std::cout << "Brak samochodow w rejestrze.\n";
        return;
    }

    for (int i = 0; i < size; ++i) {
        std::cout << i << ". ";
        cars[i]->display();
    }
}

void Registry::searchByBrand(const std::string& brand) const {
    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (cars[i]->getBrand() == brand) {
            std::cout << i << ". ";
            cars[i]->display();
            found = true;
        }
    }
    if (!found) {
        std::cout << "Brak samochodow o podanej marce.\n";
    }
}

void Registry::searchByModel(const std::string& model) const {
    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (cars[i]->getModel() == model) {
            std::cout << i << ". ";
            cars[i]->display();
            found = true;
        }
    }
    if (!found) std::cout << "Brak samochodow o podanym modelu.\n";
}


void Registry::searchByYear(int year) const {
    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (cars[i]->getYear() == year) {
            std::cout << i << ". ";
            cars[i]->display();
            found = true;
        }
    }
    if (!found) {
        std::cout << "Brak samochodow z podanego rocznika.\n";
    }
}

void Registry::searchByMaxMileage(int maxMileage) const {
    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (cars[i]->getMileage() <= maxMileage) {
            std::cout << i << ". ";
            cars[i]->display();
            found = true;
        }
    }
    if (!found) {
        std::cout << "Brak samochodow o przebiegu rownym badz mniejszym niz " << maxMileage << "km.\n";
    }
}

void Registry::saveToFile(const char* filename) const {
    FILE* file = fopen(filename, "w");
    if (!file) {
        std::cout << "Nie mozna otworzyc pliku do zapisu!\n";
        return;
    }
    fprintf(file, "%d\n", size);
    for (int i = 0; i < size; ++i) {
        // Marka i model bez spacji!
        fprintf(file, "%s %s %d %d\n",
                cars[i]->getBrand().c_str(),
                cars[i]->getModel().c_str(),
                cars[i]->getYear(),
                cars[i]->getMileage());
    }
    fclose(file);
    std::cout << "Rejestr zapisany do pliku " << filename << "\n";
}

void Registry::loadFromFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        std::cout << "Nie mozna otworzyc pliku do odczytu!\n";
        return;
    }
    // Usuń stare dane
    for (int i = 0; i < size; ++i) {
        delete cars[i];
    }
    free(cars);
    cars = nullptr;
    size = 0;

    int newSize;
    if (fscanf(file, "%d\n", &newSize) != 1) {
        std::cout << "Blad odczytu rozmiaru rejestru!\n";
        fclose(file);
        return;
    }
    for (int i = 0; i < newSize; ++i) {
        char brand[100], model[100];
        int year, mileage;
        if (fscanf(file, "%99s %99s %d %d\n", brand, model, &year, &mileage) == 4) {
            addCar(std::string(brand), std::string(model), year, mileage);
        } else {
            std::cout << "Blad odczytu danych samochodu!\n";
        }
    }
    fclose(file);
    std::cout << "Rejestr wczytany z pliku " << filename << "\n";
}
