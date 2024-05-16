#include <iostream>
#include <queue>
#include <string>
#include <ctime>
using namespace std;

class AnimalShelter {
private:
    queue<string> catQueue;
    queue<string> dogQueue;
    queue<time_t> arrivalTime; // Queue untuk menyimpan waktu kedatangan hewan

public:
    // Fungsi untuk menambahkan hewan ke dalam shelter
    void enqueue(string animal) {
        if (animal == "cat") {
            catQueue.push(animal);
        } else if (animal == "dog") {
            dogQueue.push(animal);
        }
        // Simpan waktu kedatangan hewan saat ini
        arrivalTime.push(time(nullptr));
    }

    // Fungsi untuk mengambil hewan yang pertama kali datang
    string dequeueAny() {
        if (catQueue.empty() && dogQueue.empty()) {
            return "Shelter kosong";
        } else if (catQueue.empty()) {
            string dog = dogQueue.front();
            dogQueue.pop();
            arrivalTime.pop();
            return dog;
        } else if (dogQueue.empty()) {
            string cat = catQueue.front();
            catQueue.pop();
            arrivalTime.pop();
            return cat;
        } else {
            // Bandingkan waktu kedatangan hewan
            if (arrivalTime.front() <= arrivalTime.front()) {
                string cat = catQueue.front();
                catQueue.pop();
                arrivalTime.pop();
                return cat;
            } else {
                string dog = dogQueue.front();
                dogQueue.pop();
                arrivalTime.pop();
                return dog;
            }
        }
    }

    // Fungsi untuk mengambil kucing yang pertama kali datang
    string dequeueCat() {
        if (catQueue.empty()) {
            return "Tidak ada kucing di shelter";
        }
        string cat = catQueue.front();
        catQueue.pop();
        arrivalTime.pop();
        return cat;
    }

    // Fungsi untuk mengambil anjing yang pertama kali datang
    string dequeueDog() {
        if (dogQueue.empty()) {
            return "Tidak ada anjing di shelter";
        }
        string dog = dogQueue.front();
        dogQueue.pop();
        arrivalTime.pop();
        return dog;
    }
};

int main() {
    AnimalShelter shelter;

    shelter.enqueue("cat");
    shelter.enqueue("dog");
    shelter.enqueue("cat");
    shelter.enqueue("dog");
    shelter.enqueue("cat");

    cout << "Hewan yang diadopsi: " << shelter.dequeueAny() << endl;
    cout << "Kucing yang diadopsi: " << shelter.dequeueCat() << endl;
    cout << "Anjing yang diadopsi: " << shelter.dequeueDog() << endl;

    return 0;
}