#include "Computer.h"

Computer::Computer() : name("Undefined"), frequency(0), ram(0), hasDVD(false), price(0) {}

Computer::Computer(string n, double f, int r, bool d, double p)
    : name(n), frequency(f), ram(r), hasDVD(d), price(p) {
}

void Computer::display() const {
    cout << left << setw(15) << name
        << " | " << frequency << " GHz | "
        << ram << " GB RAM | DVD: " << (hasDVD ? "+" : "-")
        << " | Price: " << price << "$" << endl;
}

void showAll(MyVector<Computer>& v) {
    cout << "\n--- Inventory ---\n";
    for (int i = 0; i < v.getSize(); i++) v[i].display();
}

void findByName(MyVector<Computer>& v) {
    string target;
    cout << "Enter name to find: "; cin >> target;
    bool found = false;
    for (int i = 0; i < v.getSize(); i++) {
        if (v[i].name == target) {
            v[i].display();
            found = true;
        }
    }
    if (!found) cout << "Not found.\n";
}

void removeSlowest(MyVector<Computer>& v) {
    if (v.getSize() == 0) return;
    int minIdx = 0;
    for (int i = 1; i < v.getSize(); i++) {
        if (v[i].frequency < v[minIdx].frequency) minIdx = i;
    }
    cout << "Slowest PC: " << v[minIdx].name << " (Marked/Ignored)\n";

}

void countDVD(MyVector<Computer>& v) {
    int count = 0;
    for (int i = 0; i < v.getSize(); i++) if (v[i].hasDVD) count++;
    cout << "Total with DVD: " << count << endl;
}

void updatePrices(MyVector<Computer>& v) {
    for (int i = 0; i < v.getSize(); i++) {
        if (v[i].ram >= 16) v[i].price += 150;
    }
    cout << "Prices updated for 16GB+ RAM.\n";
}

void sortByPrice(MyVector<Computer>& v) {
    for (int i = 0; i < v.getSize() - 1; i++) {
        for (int j = 0; j < v.getSize() - i - 1; j++) {
            if (v[j].price > v[j + 1].price) {
                Computer temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
    cout << "Sorted by price.\n";
}

