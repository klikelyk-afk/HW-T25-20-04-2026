#include <iostream>
#include <string>
#include "Vector.h"
#include "Computer.h"

using namespace std;

int main() {

    setlocale(LC_ALL, "Ukrainian");

    MyVector<Computer> computers;


    computers.push_back(Computer("Asus ROG", 3.8, 16, true, 1500));
    computers.push_back(Computer("HP Pavilion", 2.4, 8, false, 800));
    computers.push_back(Computer("Dell XPS", 4.2, 32, true, 2200));
    computers.push_back(Computer("Lenovo Think", 2.1, 4, false, 450));

    int choice;
    int skipIndex = -1;

    do {
        cout << "\n--- МЕНЮ КЕРУВАННЯ КОМП'ЮТЕРАМИ ---\n";
        cout << "1. Показати всi комп'ютери\n";
        cout << "2. Знайти за назвою\n";
        cout << "3. Видалити найповiльнiший\n";
        cout << "4. Кiлькiсть з дисководом\n";
        cout << "5. Пiдняти цiну для моделей з 16GB+ RAM\n";
        cout << "6. Сортувати за цiною\n";
        cout << "0. Вихiд\n";
        cout << "Ваш вибір: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "\nСписок комп'ютерiв у наявностi:\n";
            for (int i = 0; i < computers.getSize(); i++) {
                if (i == skipIndex) continue;
                computers[i].display();
            }
            break;

        case 2: {
            string target;
            cout << "Введiть назву для пошуку: ";
            cin.ignore();
            getline(cin, target);
            bool found = false;
            for (int i = 0; i < computers.getSize(); i++) {
                if (i != skipIndex && computers[i].name == target) {
                    computers[i].display();
                    found = true;
                    break;
                }
            }
            if (!found) cout << "Комп'ютер не знайдено.\n";
            break;
        }

        case 3: {
            int minIdx = -1;
            double minFreq = 999.0;
            for (int i = 0; i < computers.getSize(); i++) {
                if (i == skipIndex) continue;
                if (computers[i].frequency < minFreq) {
                    minFreq = computers[i].frequency;
                    minIdx = i;
                }
            }
            if (minIdx != -1) {
                cout << "Видаляємо найповiльнiший ПК: " << computers[minIdx].name << endl;
                skipIndex = minIdx;
            }
            break;
        }

        case 4: {
            int count = 0;
            for (int i = 0; i < computers.getSize(); i++) {
                if (i != skipIndex && computers[i].hasDVD) count++;
            }
            cout << "Всього моделей з дисководом: " << count << endl;
            break;
        }

        case 5:
            for (int i = 0; i < computers.getSize(); i++) {
                if (i != skipIndex && computers[i].ram >= 16) {
                    computers[i].price += 150;
                }
            }
            cout << "Цiни оновлено для потужних моделей.\n";
            break;


        case 6:
            for (int i = 0; i < computers.getSize() - 1; i++) {
                for (int j = 0; j < computers.getSize() - i - 1; j++) {
                    if (computers[j].price > computers[j + 1].price) {
                        Computer temp = computers[j];
                        computers[j] = computers[j + 1];
                        computers[j + 1] = temp;
                    }
                }
            }
            cout << "Список вiдсортовано за цiною.\n";
            break;

        case 0:
            cout << "Завершення роботи...\n";
            break;

        default:
            cout << "Невірний пункт меню!\n";
        }
    } while (choice != 0);

    return 0;
}