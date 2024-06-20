<h1 align="center">TEORI ALPRO dan STRUKTUR DATA - TUGAS 3 </h1>
<p align="center">Naufal Alif Anargya</p>
<p align="center">2311110041</p>

## Priority Queue
### Dasar Teori
Priority Queue adalah struktur data yang mirip dengan Queue, tetapi memiliki prioritas untuk setiap elemen yang mempengaruhi urutan pemrosesannya. Salah satu cara untuk mengimplementasikannya adalah dengan menggunakan struktur data heap, yang melibatkan tiga komponen utama: heap, comparator, dan last. Dengan menggunakan heap, kita dapat menambahkan atau menghapus elemen dengan kompleksitas waktu logaritmik. Dalam priority queue ini, akan terbentuk pohon biner yang seimbang. Tujuan pembentukan pohon biner ini adalah untuk meminimalkan tinggi pohon, yang memungkinkan operasi pada elemen daun dilakukan dalam waktu logaritmik. [1]
- **Heap :**
HeapSort adalah struktur data berbentuk pohon yang memenuhi sifat-sifat heap, di mana jika simpul B adalah anak dari simpul A, maka nilai di simpul A lebih besar atau sama dengan nilai di simpul B. Akibatnya, elemen dengan nilai terbesar selalu berada di akar, dan struktur ini disebut max heap (jika perbandingannya dibalik sehingga elemen terkecil berada di akar, maka disebut min heap). Oleh karena itu, heap sering digunakan untuk mengimplementasikan priority queue. Operasi-operasi yang dapat dilakukan pada heap antara lain:

- Delete-max atau delete-min: menghapus simpul akar dari max heap atau min heap.
- Increase-key atau decrease-key: mengubah nilai yang tersimpan di suatu simpul.
- Insert: menambahkan nilai baru ke dalam heap.
- Merge: menggabungkan dua heap menjadi satu heap baru yang berisi semua elemen dari kedua heap tersebut. [2]

**Contoh program priority queue**
```C++
#include <iostream>
#include <queue>
#include <vector>
#include <functional> // for std::greater

class PriorityQueue {
private:
    // Using a min-heap, priority_queue by default is a max-heap
    std::priority_queue<std::pair<int, std::string>, std::vector<std::pair<int, std::string>>, std::greater<std::pair<int, std::string>>> pq;

public:
    void push(int priority, const std::string& item) {
        pq.emplace(priority, item);
    }

    std::string pop() {
        if (pq.empty()) {
            throw std::out_of_range("PriorityQueue is empty");
        }
        std::string item = pq.top().second;
        pq.pop();
        return item;
    }

    bool is_empty() const {
        return pq.empty();
    }
};

int main() {
    PriorityQueue pq;
    pq.push(3, "A");
    pq.push(1, "B");
    pq.push(2, "C");

    while (!pq.is_empty()) {
        std::cout << pq.pop() << std::endl;
    }

    return 0;
}

```

**Output :**  
![Screenshot 2024-06-20 224938](https://github.com/Nargya/TeoriAlprodanStrukturData/assets/161468671/951eff22-9fc1-458f-bec6-b9b4f363312b)

**Penjelasan :**  
Program dimulai dengan mengimpor header iostream, queue, vector, dan functional. Kelas PriorityQueue didefinisikan untuk mengelola elemen-elemen dengan prioritas menggunakan priority_queue dari STL, yang dikonfigurasikan sebagai min-heap dengan std::greater. Metode push menambahkan elemen ke priority_queue dengan prioritas yang diberikan, sementara metode pop menghapus dan mengembalikan elemen dengan prioritas tertinggi, dan melempar pengecualian jika queue kosong. Metode is_empty mengecek apakah queue kosong. Pada main, elemen-elemen dimasukkan ke dalam Priority Queue, dan loop while digunakan untuk mencetak dan menghapus elemen-elemen berdasarkan prioritas hingga queue kosong.

**Alur program :**  
Output program menunjukkan elemen dengan prioritas tertinggi diproses terlebih dahulu. Pada contoh di atas, elemen "B" memiliki prioritas tertinggi (1), diikuti oleh "C" (2), dan "A" (3). Oleh karena itu, elemen-elemen dicetak dalam urutan "B", "C", dan "A", sesuai dengan urutan prioritas yang diberikan.

## Hash Table
### Dasar Teori
### Parafrase dan Ringkasan

Algoritma tabel hash atau hash table adalah salah satu algoritma yang digunakan untuk menyimpan dan mencari data dengan cepat dan efisien. Algoritma ini telah banyak dikembangkan dan digunakan di berbagai bidang karena keunggulannya dalam efisiensi waktu operasi untuk pengarsipan dan pencarian data. Di bidang jaringan komputer, tabel hash telah dikembangkan menjadi hybrid open hash table yang digunakan untuk memproses jaringan komputer, terutama pada sistem jaringan ad hoc yang bergerak (mobile ad hoc networks). Selain itu, distributed hash table digunakan untuk mencari dan menemukan berbagai macam web service di Internet.

Tabel hash menyimpan data dalam memori dalam bentuk baris dan kolom, membentuk tabel yang dapat diakses dengan cepat. Setiap pertemuan antara baris dan kolom disebut slot. Tabel hash terdiri dari dua bagian utama: sebuah larik (array) dan sebuah fungsi hash. Fungsi hash memetakan kunci-kunci yang diberikan ke dalam larik, mendistribusikan data yang dimasukkan oleh pengguna ke dalam tabel. Salah satu metode untuk menentukan kunci dalam tabel hash adalah dengan menggunakan sistem modulus dari nilai integer data. Misalnya, untuk memetakan huruf-huruf abjad A-Z, dapat digunakan nilai ASCII dari huruf yang diinputkan dan sistem modulus dari 6 [3]. 

Proses hash terdiri dari dua langkah utama:

1. **Menghitung fungsi hash**: Fungsi hash mengubah kunci (key) menjadi alamat dalam tabel dengan memetakan kunci tersebut ke alamat yang spesifik. Idealnya, kunci-kunci yang berbeda dipetakan ke alamat yang berbeda, namun dalam praktiknya, beberapa kunci mungkin dipetakan ke alamat yang sama, yang disebut tabrakan (collision).

2. **Resolusi tabrakan (collision resolution)**: Ini adalah proses untuk menangani tabrakan dengan mencari lokasi kosong dalam tabel secara berurutan atau menggunakan fungsi hash lain untuk menemukan lokasi yang kosong [4].

**Program Hash Table**
```C++
#include <iostream>
#include <list>
#include <vector>

class HashTable {
private:
    std::vector<std::list<std::pair<int, std::string>>> table;
    int size;

    int hashFunction(int key) {
        return key % size;
    }

public:
    HashTable(int size) {
        this->size = size;
        table.resize(size);
    }

    void insertItem(int key, const std::string& value) {
        int hashIndex = hashFunction(key);
        table[hashIndex].emplace_back(key, value);
    }

    void deleteItem(int key) {
        int hashIndex = hashFunction(key);
        auto& cell = table[hashIndex];
        auto it = cell.begin();
        while (it != cell.end()) {
            if (it->first == key) {
                it = cell.erase(it);
                return;
            } else {
                ++it;
            }
        }
        std::cout << "Key not found" << std::endl;
    }

    std::string searchItem(int key) {
        int hashIndex = hashFunction(key);
        auto& cell = table[hashIndex];
        for (auto& pair : cell) {
            if (pair.first == key) {
                return pair.second;
            }
        }
        return "Key not found";
    }

    void displayHashTable() {
        for (int i = 0; i < size; ++i) {
            std::cout << "Bucket " << i << ": ";
            for (auto& pair : table[i]) {
                std::cout << "(" << pair.first << ", " << pair.second << ") ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    HashTable ht(7);
    ht.insertItem(10, "Apple");
    ht.insertItem(20, "Banana");
    ht.insertItem(15, "Grape");
    ht.insertItem(7, "Orange");
    ht.insertItem(14, "Mango");

    ht.displayHashTable();

    std::cout << "Search key 15: " << ht.searchItem(15) << std::endl;

    ht.deleteItem(20);
    ht.displayHashTable();

    return 0;
}

```

**Output :**  
![Screenshot 2024-06-20 230854](https://github.com/Nargya/TeoriAlprodanStrukturData/assets/161468671/e4626846-a16b-42a8-a806-24178ad2f261)

**Penjelasan :**  
Program ini mengimpor header iostream dan vector untuk input/output dan penggunaan vektor, serta list untuk mendefinisikan list doubly linked yang menangani collision. Kelas HashTable mengelola elemen-elemen dengan prioritas menggunakan priority_queue dari STL, yang dikonfigurasikan sebagai min-heap dengan std::greater. Fungsi hash memetakan kunci ke indeks tabel dengan menggunakan modulus dari ukuran tabel (key % size). Metode insertItem menambahkan item ke tabel hash, deleteItem menghapus item berdasarkan kunci, searchItem mencari item berdasarkan kunci dan mengembalikan nilainya, dan displayHashTable menampilkan isi tabel hash.

**Alur program :**  
Dimulai dengan membuat tabel hash berukuran 7, program kemudian menggunakan fungsi hash untuk menentukan indeks dan menambahkan beberapa item ke dalam tabel hash. Isi tabel hash ditampilkan, dengan semua bucket dan isinya. Selanjutnya, program mencari dan mencetak nilai berdasarkan kunci, menghapus item dengan kunci tertentu, dan menampilkan tabel hash setelah penghapusan. Output program menampilkan isi tabel hash sebelum dan setelah penghapusan, serta hasil pencarian item.

## Rekursif
### Dasar Teori
Rekursi adalah teknik dalam matematika di mana sebuah fungsi didefinisikan dengan memanfaatkan fungsi itu sendiri. Dalam konteks pemrograman, rekursi diimplementasikan sebagai fungsi yang memanggil dirinya sendiri. Ini adalah pendekatan untuk memecahkan masalah di mana solusi tergantung pada solusi masalah yang lebih sederhana secara berulang. Iterasi, di sisi lain, adalah pendekatan yang menggunakan perulangan di dalam fungsi untuk menyelesaikan masalah, yang merupakan ciri khas dari paradigma pemrograman imperatif. Kebanyakan bahasa pemrograman mendukung baik rekursi maupun iterasi, namun ada bahasa yang mungkin tidak mendukung salah satu dari keduanya. Sebuah fungsi adalah jenis relasi di mana setiap elemen dalam domain A terhubung tepat satu elemen dalam codomain B. Fungsi rekursif adalah fungsi yang mengacu pada dirinya sendiri. Fungsi rekursif terdiri dari dua bagian utama: basis dan rekurens. Basis berisi nilai awal yang tidak memanggil fungsi itu sendiri, dan berfungsi untuk memberikan nilai yang sudah ditentukan dan menghentikan rekursi. Rekurens adalah bagian dari fungsi yang mendefinisikan argumen dalam terminologi dirinya sendiri. Saat fungsi rekursif memanggil bagian rekurens, argumen fungsi tersebut harus mendekati nilai basis [5].

**Contoh Program :**
```C++
#include <iostream>

unsigned long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    int n;
    std::cout << "Masukkan bilangan untuk dihitung faktorialnya: ";
    std::cin >> n;

    unsigned long long result = factorial(n);

    std::cout << "Faktorial dari " << n << " adalah: " << result << std::endl;

    return 0;
}

```

**Output :**  
![Screenshot 2024-06-20 233545](https://github.com/Nargya/TeoriAlprodanStrukturData/assets/161468671/055b4aa7-4100-4e33-9be0-fe2ad59b7749)


**Penjelasan :**  
Program di atas adalah implementasi fungsi rekursif dalam C++ untuk menghitung faktorial dari suatu bilangan. Fungsi factorial menerima parameter integer n dan mengembalikan nilai faktorial dari n. Pada fungsi rekursif, basis kasus adalah ketika n adalah 0 atau 1, di mana faktorialnya adalah 1. Jika n lebih besar dari 1, fungsi akan memanggil dirinya sendiri dengan parameter n - 1 dan mengalikan hasilnya dengan n, sehingga menghitung faktorial secara rekursif.

**Alur Program :**  
Program ini menghitung faktorial dari suatu bilangan menggunakan rekursi dalam C++. Fungsi `main` memulai dengan menginisialisasi nilai `n` sebagai 5. Program kemudian memanggil fungsi `factorial` dengan nilai `n`. Fungsi `factorial` memproses nilai `n` dengan memeriksa jika `n` adalah 0 atau 1, maka langsung mengembalikan 1. Jika tidak, fungsi `factorial` memanggil dirinya sendiri dengan nilai `n-1` dan mengalikan hasilnya dengan `n`. Proses ini berlanjut sampai mencapai basis kasus dan mengembalikan hasil akhir ke pemanggilnya di fungsi `main`. Akhirnya, hasil faktorial dari `n` ditampilkan ke layar. Program ini menggambarkan penggunaan rekursi untuk menghitung faktorial dengan memanfaatkan pemanggilan fungsi berulang hingga mencapai kondisi berhenti.

## Graph and Tree
### Dasar Teori
Sebuah pohon adalah jenis graf tak berarah yang terhubung tanpa mengandung rangkaian sederhana. Pohon sering digunakan dalam berbagai konteks seperti struktur organisasi perusahaan, silsilah keluarga, skema eliminasi dalam pertandingan, dan struktur kimia molekul. Dalam pohon, simpul yang memiliki derajat satu disebut daun, sedangkan simpul dengan derajat lebih dari satu disebut simpul cabang atau simpul internal. Kumpulan pohon yang terpisah disebut sebagai hutan. Pohon secara umum menggambarkan hubungan hierarkis atau struktur terurut di antara elemen-elemen yang terhubung [6].

Graf dapat dibedakan berdasarkan orientasi arah pada sisinya menjadi dua jenis: graf berarah (directed graph) dan graf tak berarah (undirected graph). Graf tak berarah tidak memiliki orientasi arah pada sisinya, sehingga urutan pasangan titik tidak diperhatikan. Sementara itu, graf berarah memiliki setiap sisinya sebagai pasangan terurut dari dua titik, dengan titik awal dan titik akhir yang membedakan arah. Dalam konteks graf berarah, penting untuk memperhatikan arah dari setiap sisi, sementara dalam graf tak berarah, sisinya hanya menunjukkan hubungan tanpa arah spesifik antar titik [7].

**Contoh Program :**
```C++
#include <iostream>
#include <list>
#include <unordered_map>

class Graph {
private:
    std::unordered_map<int, std::list<int>> adjList;

public:
    void addEdge(int u, int v) {
        adjList[u].push_back(v); 
        adjList[v].push_back(u); 
    }

    void printGraph() {
        for (auto& pair : adjList) {
            std::cout << "Node " << pair.first << " is connected to:";
            for (int neighbor : pair.second) {
                std::cout << " " << neighbor;
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    Graph graph;

    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);
    graph.addEdge(4, 5);

    graph.printGraph();

    return 0;
}

```

**Output :**  
![Screenshot 2024-06-20 235059](https://github.com/Nargya/TeoriAlprodanStrukturData/assets/161468671/fb08bf55-4551-4210-af73-09efaae95d5f)

**Penjelasan :**  
Program ini menggunakan representasi adjacency list untuk merepresentasikan graf tak berarah dalam C++. Kelas Graph menggunakan unordered_map untuk menyimpan node-node sebagai kunci dan list node-node terhubung sebagai nilainya. Pendekatan ini efisien dalam menyimpan dan mengakses informasi mengenai hubungan antar node dalam graf.

**Alur Program :**  
Program dimulai dengan mendefinisikan kelas `Graph`, yang menggunakan `unordered_map` untuk menyimpan adjacency list dari graf. Setiap node direpresentasikan sebagai kunci dalam `unordered_map`, dengan nilai berupa `list` yang berisi node-node terhubung. Saat program dijalankan, objek `Graph` dibuat dalam fungsi `main`. Beberapa edge (sisi) ditambahkan ke graf menggunakan metode `addEdge(int u, int v)`. Setiap kali edge ditambahkan, metode ini memastikan untuk menambahkan koneksi dua arah antara node `u` dan `v`, sesuai dengan sifat graf tak berarah. Setelah itu, program memanggil `printGraph()` untuk mencetak representasi graf dalam bentuk adjacency list. Hasilnya adalah tampilan yang menunjukkan setiap node beserta daftar node-node terhubungnya.

### Referensi

[1] Aditya Nurcholis H, Simon Batara N, Mohamad Octamanullah, *"Penerapan struktur data Heap Priority Queue pada algoritma
Djikstra untuk mendapatkan kompleksitas O((n + m)log n)"*, Laboratorium Ilmu dan Rekayasa Komputasi
Departemen Teknik Informatika, Institut Teknologi Bandung, 2005

[2] Fenisa Lourence Tobing, Fenina Adline Twince Tobing, Jimmy Peranginangin, *"Implementasi Algoritma Heapsort dalam Game Pembelajaran Algoritma Sorting"*, Jurnal Widya, vol.3, no.2, Oktober 2022.

[3] Jasson Prestiliano, *"Aplikasi Tabel Hash dalam Pengarsipan dan Pencarian Data"*, Jurnal Teknologi Informasi-Aiti, Vol. 4, No. 1, Februari 2007.

[4] Viska Mutiawani, *"HASHTABLE SEBAGAI ALTERNATIF DARI ALGORITMA PENCARIAN BINER PADA APLIKASI E-ACESIA"*, JURNAL INFORMATIKA, Vol. 8, No. 2, Juli 2014.

[5] Stephen Herlambang, *"Implementasi Fungsi Rekursif Dalam Algoritma dan Perbandingannya dengan Fungsi Iteratif"*, Jurusan Teknik Informatika ITB, Bandung.

[6] Amir Muntaha, *"Graf Pohon dan Implementasinya dalam beberapa persoalan"*, Program Studi Teknik Informatika Sekolah Teknik Elektro dan Informatika, Institut Teknologi Bandung, 2007

[7] Tito Nurdiyanto, Ely Susanti, *"EFISIENSI PENGGUNAAN MATRIKS IN-DEGREE UNTUK MENGKONTRUKSISPANNING-TREEPADA GRAF BERARAH"*, JES-MAT, Vol. 5, No.1, Maret 2019.
