#include <iostream>
#include <cstring>
using namespace std;

struct Reservation {
    char name[50];
    int table_number;
    char time[20];
};

class Reservation_System {
private:
    Reservation* reservations;
    int capacity;
    int customer;

    void capacity_of_number() {
        capacity *= 2;
        Reservation* new_reservations = new Reservation[capacity];
        for (int i = 0; i < customer; i++) {
            new_reservations[i] = reservations[i];
        }
        delete[] reservations;
        reservations = new_reservations;
    }

public:
    Reservation_System() {
        capacity = 10;
        reservations = new Reservation[capacity];
        customer = 0;
    }

    ~Reservation_System() {
        delete[] reservations;
    }

    void addreservation(const char* name, int table_number, const char* time) {
        if (customer == capacity) {
            capacity_of_number();
        }
        strncpy(reservations[customer].name, name, 50);
        reservations[customer].table_number = table_number;
        strncpy(reservations[customer].time, time, 20);
        customer++;
        cout << "Rezervasyonunuz " << name << ", Masa no: " << table_number << ", Saat: " << time << " olarak kaydedildi..." << endl;
    }

    void cancelreservation(const char* name, int table_number, const char* time) {
        for (int i = 0; i < customer; i++) {
            if (strcmp(reservations[i].name, name) == 0 && reservations[i].table_number == table_number && strcmp(reservations[i].time, time) == 0) {
                for (int j = i; j < customer - 1; j++) {
                    reservations[j] = reservations[j + 1];
                }
                customer--;
                cout << "Rezervasyon iptal edildi: " << name << ", Masa no: " << table_number << ", Saat: " << time << endl;
                return;
            }
        }
        cout << "Rezervasyon bulunamad�." << endl;
    }

    void showreservation() const {
        if (customer == 0) {
            cout << "Rezervasyon bulunamad�" << endl;
        } else {
            cout << "Mevcut Rezervasyonlar: " << endl;
            for (int i = 0; i < customer; i++) {
                cout << "�sim: " << reservations[i].name << ", Masa no: " << reservations[i].table_number << ", Saat: " << reservations[i].time << endl;
            }
        }
    }
};

int main() {
    Reservation_System reservation_system;
    int choice;
    char name[50];
    int table_number;
    char time[20];

    do {
        cout << "     Yemek Rezervasyon Sistemine Ho�geldiniz     " << endl;
        cout << "1. Rezervasyon Olu�tur" << endl;
        cout << "2. Rezervasyon �ptal Et" << endl;
        cout << "3. Mevcut Rezervasyonlar� G�ster" << endl;
        cout << "4. Rezervasyon Sisteminden ��k��" << endl;
        cout << "Se�iminiz (Numara yazman�z yeterlidir.): ";

        cin >> choice;

        switch (choice) {
        case 1:
            cout << "�sim: ";
            cin >> name;
            cout << "Rezervasyon Masa Numaran�z: ";
            cin >> table_number;
            cout << "Rezervasyon Saat Ka�ta ger�ekle�ecek: ";
            cin >> time;
            reservation_system.addreservation(name, table_number, time);
            break;

        case 2:
            cout << "Isim: ";
            cin >> name;
            cout << "Rezervasyon Masa Numaraniz: ";
            cin >> table_number;
            cout << "Rezervasyon Saat Kacta ger�eklesecek: ";
            cin >> time;
            reservation_system.cancelreservation(name, table_number, time);
            break;

        case 3:
            reservation_system.showreservation();
            break;

        case 4:
            cout << "��k�� yap�l�yor..." << endl;
            break;

        default:
            cout << "Ge�ersiz i�lem..." << endl;
        }
    } while (choice != 4);

    return 0;
}
