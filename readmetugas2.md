# <h1 align="center">TEORI ALPRO dan STRUKTUR DATA - TUGAS 2 </h1>
<p align="center">Naufal Alif Anargya</p>
<p align="center">2311110041</p>

## CPMK 2 – SubCPMK 2 
### 1. Terdapat tiga algoritma sorting yang umum digunakan yakni, Bubble Sort, Selection Sort, dan Merge Sort. Berikan penjelasan alur dari masing-masing algoritma tersebut, dan jelaskan runtime dari best case dan worst case masing-masing algoritma!
1. **Bubble Sort**:
   - **Alur**: Bubble sort adalah algoritma sorting sederhana yang berulang kali membandingkan setiap pasangan elemen yang berdekatan dan menukar mereka jika dalam urutan yang salah. Ini melanjutkan melalui daftar hingga tidak ada lagi pertukaran yang dibuat, yang menandakan bahwa daftar sudah diurutkan.
   - **Best Case Runtime**: O(n), di mana n adalah jumlah elemen dalam daftar, ketika daftar sudah dalam urutan yang benar.
   - **Worst Case Runtime**: O(n^2), di mana n adalah jumlah elemen dalam daftar, ketika daftar dalam urutan terbalik atau hampir terbalik.

2. **Selection Sort**:
   - **Alur**: Selection sort juga merupakan algoritma sederhana yang memilih elemen minimum dari daftar dan menukarnya dengan elemen pertama. Kemudian, elemen minimum berikutnya dari daftar yang tidak diurutkan dipilih, dan ditukar dengan elemen kedua, dan seterusnya.
   - **Best Case Runtime**: O(n^2), karena bahkan jika daftar sudah dalam urutan yang benar, masih memerlukan jumlah langkah yang sama seperti dalam kasus terburuk.
   - **Worst Case Runtime**: O(n^2), ketika daftar dalam urutan terbalik atau hampir terbalik.

3. **Merge Sort**:
   - **Alur**: Merge sort adalah algoritma rekursif yang membagi daftar menjadi dua bagian, mengurutkan masing-masing bagian secara terpisah, dan kemudian menggabungkan hasilnya. Proses ini dilakukan secara rekursif sampai daftar terbagi menjadi satu elemen, dan kemudian digabungkan kembali dalam urutan yang benar.
   - **Best Case Runtime**: O(n log n), di mana n adalah jumlah elemen dalam daftar, karena dalam setiap langkah, daftar dibagi menjadi dua bagian.
   - **Worst Case Runtime**: O(n log n), bahkan saat daftar sudah diurutkan, karena penggabungan dua daftar terurut membutuhkan waktu O(n).

### 2. Buatlah fungsi dari salah satu algoritma sorting pada soal nomor 1, dan berikan penjelasan pada program tersebut 
- **Bubble Sort** 
```C++
#include <iostream>
#include <vector>

void bubble_sort(std::vector<int>& arr)
{
    bool swapped = true;
    for (int i = 0; i < arr.size() && swapped; i++)
    {
        swapped = false;
        for (int j = 0; j < arr.size() - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
    }
}

int main()
{
    std::vector<int> arr = {12, 11, 13, 5, 6};
    bubble_sort(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i] << " ";
    }
    return 0;
}
```
- **Penjelasan** : Fungsi `bubble_sort` menerima sebuah vektor integer sebagai argumen dan mengurutkannya secara naik menggunakan algoritma Bubble Sort. Di dalam fungsi, terdapat dua iterasi: iterasi luar untuk memastikan bahwa setiap elemen pada akhirnya berada pada posisi yang benar, dan iterasi dalam untuk melakukan perbandingan dan pertukaran jika diperlukan. Setiap kali pertukaran dilakukan, variabel swapped diatur ke true. Iterasi berhenti jika tidak ada pertukaran yang dilakukan pada iterasi tertentu, menandakan bahwa vektor sudah terurut. Pada fungsi main, sebuah vektor integer diinisialisasi, diurutkan menggunakan fungsi `bubble_sort`, dan hasilnya ditampilkan ke layar.

### 3. Tulislah sebuah fungsi untuk mensorting dan mengecek dua buah array of strings, sehingga menghasilkan “anagram” dan “tidak anagram” 
Contoh: 

Input string1 = “bahu” string2 = “buah” 

Output: “anagram”

Input string1 = “makan” string2 = “minum”

Output: “tidak anagram”

```C++
#include <iostream>
#include <string>
#include <algorithm>

std::string sortString(std::string str) {
    std::sort(str.begin(), str.end());
    return str;
}

std::string checkAnagram(std::string str1, std::string str2) {
    std::string sortedStr1 = sortString(str1);
    std::string sortedStr2 = sortString(str2);

    if (sortedStr1 == sortedStr2) {
        return "anagram";
    } else {
        return "tidak anagram";
    }
}

int main() {
    std::string string1, string2;
  
    std::cout << "Masukkan string pertama: ";
    std::cin >> string1;
    std::cout << "Masukkan string kedua: ";
    std::cin >> string2;
  
    std::cout << "Output: " << checkAnagram(string1, string2) << std::endl;
    
    return 0;
}
```
- **Penjelasan** : Code diatas mencakup dua fungsi, `sortString` untuk mengurutkan string dan `checkAnagram` untuk memeriksa apakah dua string yang diberikan merupakan anagram atau tidak. Fungsi checkAnagram membandingkan kedua string setelah diurutkan dan mengembalikan "anagram" jika mereka sama setelah diurutkan, dan "tidak anagram" jika tidak. Pada main, program meminta pengguna untuk memasukkan dua string, kemudian memanggil checkAnagram untuk memeriksa hubungan anagram antara keduanya dan menampilkan hasilnya.

### 4. Tulislah sebuah fungsi program dengan asumsi sebagai berikut: Terdapat dua buah sorted array A dan B yang memiliki tipe data sama, dimana array A memiliki indeks yang cukup untuk menampung array B. Gabungkan array B kedalam array A, kemudian urutkan array tersebut!

- **Code** : 
```C++
#include <iostream>
#include <vector>
#include <algorithm>

void mergeArrays(std::vector<int>& A, const std::vector<int>& B, int m, int n) {
    int i = m - 1; 
    int j = n - 1; 
    int k = m + n - 1; 
    while (i >= 0 && j >= 0) {
        if (A[i] > B[j]) {
            A[k--] = A[i--];
        } else {
            A[k--] = B[j--];
        }
    }

    while (j >= 0) {
        A[k--] = B[j--];
    }
}

int main() {
    std::vector<int> A = {1, 3, 5, 7, 9, 0, 0, 0, 0}; 
    std::vector<int> B = {2, 4, 6, 8}; 
    int m = 5; 
    int n = B.size(); 

    mergeArrays(A, B, m, n);

    std::cout << "Array hasil penggabungan dan pengurutan: ";
    for (int num : A) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

- **Penjelasan** : Kode ini menggabungkan dua array yang telah diurutkan sebelumnya (A dan B) menjadi satu array baru (A), tetap mempertahankan urutan yang terurut. Fungsi "mergeArrays" menerima dua vektor dan indeks yang menunjukkan jumlah elemen valid untuk masing-masing vektor. Proses menggabungkan algoritma dimulai dengan membandingkan elemen terbesar dari dua vektor dan kemudian memasukkannya ke posisi yang tepat di vektor pertama. Setelah elemen dari vektor kedua dimasukkan, elemen dari vektor pertama juga dimasukkan jika masih ada elemen dari vektor kedua. Selanjutnya, dalam mode "main", dua vektor dibuat, dan fungsi "mergeArrays" digunakan untuk menggabungkan dan mengurutkan vektor A. Hasilnya ditampilkan.

## CPMK 2 – SubCPMK 3
### 1. Terdapat dua algoritma searching yang umum digunakan yakni, Binary Search dan Linear Search. Berikan penjelasan alur dari masing-masing algoritma tersebut, dan jelaskan runtime dari best case dan worst case masing-masing algoritma!

- **Jawab** : 
1. **Linear Search**:
   - **Alur**: Linear Search memeriksa setiap elemen dalam urutan tertentu secara berurutan hingga elemen yang dicari ditemukan atau mencapai akhir array.
   - **Best Case Runtime**: O(1), ketika elemen yang dicari berada di posisi pertama. Sehingga, algoritma hanya perlu melakukan satu iterasi untuk menemukannya, membuat kompleksitas waktu menjadi konstan.
   - **Worst Case Runtime**: O(n), ketika elemen yang dicari berada di posisi terakhir atau tidak ada dalam array. Algoritma harus memeriksa setiap elemen dari awal hingga akhir array, sehingga memerlukan waktu yang linear seiring dengan ukuran array.

2. **Binary Search**:
   - **Alur**: Binary Search bekerja dengan membagi array menjadi dua bagian, membandingkan elemen tengah dengan elemen yang dicari, dan memperbarui batas pencarian berdasarkan hasil perbandingan. Proses ini diulangi hingga elemen yang dicari ditemukan atau pencarian menjadi tidak mungkin.
   - **Best Case Runtime**: O(1), ketika elemen yang dicari berada tepat di tengah array. Ini mengakibatkan pencarian langsung menemukan elemen target setelah satu iterasi saja, karena setiap iterasi membagi array menjadi dua bagian.
   - **Worst Case Runtime**: O(log n), ketika setiap iterasi membagi array menjadi dua bagian dan hanya perlu menelusuri logaritma basis 2 dari ukuran array untuk menemukan elemen yang dicari. Meskipun setiap iterasi membagi array menjadi dua bagian, jumlah iterasi maksimum yang dibutuhkan hanya sebanyak logaritma basis 2 dari ukuran array. Hal ini karena setiap iterasi memperkecil ukuran array yang harus dicari menjadi setengahnya, sehingga mencapai konvergensi dengan cepat.

### 2. Buatlah fungsi dari salah satu algoritma searching pada soal nomor 1, dan berikan penjelasan pada program tersebut
- **Binary Search** : 
```C++
#include <iostream>
#include <algorithm> 
#include <string>

bool binarySearch(const std::string& sentence, char target) {
    return std::binary_search(sentence.begin(), sentence.end(), target);
}

int main() {
    std::string sentence;
    char target;

    std::cout << "Masukkan kalimat: ";
    std::getline(std::cin, sentence);

    std::cout << "Masukkan huruf yang ingin Anda cari: ";
    std::cin >> target;

    std::sort(sentence.begin(), sentence.end());

    bool found = binarySearch(sentence, target);

    if (found) {
        std::cout << "Huruf '" << target << "' ditemukan dalam kalimat." << std::endl;
    } else {
        std::cout << "Huruf '" << target << "' tidak ditemukan dalam kalimat." << std::endl;
    }

    return 0;
}
```
- **Penjelasan** :
Kode tersebut menggunakan algoritma binary search untuk menemukan huruf dalam kalimat yang dimasukkan oleh pengguna. Dengan menggunakan fungsi `std::binary_search` dari library `algorithm`, binarySearch melakukan pencarian biner pada string frasa terhadap karakter target. Program ini meningkatkan efisiensi pencarian dalam kalimat dengan memberi tahu pengguna jika huruf ditemukan atau tidak ditemukan. Ini dilakukan dengan menggunakan gagasan algoritma pencarian binario.

### 3. Tulislah sebuah fungsi program dengan kondisi sebagai berikut:
Terdapat sebuah sorted array of strings yang mana terdapat string kosong diantaranya, carilah lokasi/indeks dari kata yang dicari! 
Input: bola, {“Adi”,””,””, “”, “bermain”, “”, “bola”, “”, “”, “sedang”}

Output: 6

- **Sorted Array** :
```C++
#include <iostream>
#include <vector>
#include <string>

int searchWord(const std::vector<std::string>& arr, const std::string& word) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        while (arr[mid] == "" && mid <= right) {
            mid++;
        }

        if (mid <= right) {
     
            int compare = word.compare(arr[mid]);
            if (compare == 0) {
                return mid;
            } else if (compare < 0) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        } else {
           
            break;
        }
    }

    return -1;
}

int main() {
    std::vector<std::string> arr = {"Adi", "", "", "", "bermain", "", "bola", "", "", "sedang"};
    std::string word = "bola";

    int result = searchWord(arr, word);

    if (result != -1) {
        std::cout << "Kata \"" << word << "\" ditemukan pada indeks " << result << std::endl;
    } else {
        std::cout << "Kata \"" << word << "\" tidak ditemukan dalam array" << std::endl;
    }

    return 0;
}
```
- **Output** :
![Screenshot 2024-05-15 012705](https://github.com/Nargya/TeoriAlprodanStrukturData/assets/161468671/bad76d97-dee6-4470-814f-8a9daef17b0f)

- **Penjelasan** :
Fungsi searchWord menemukan kata dalam array urut yang terdiri dari kata-kata yang memiliki string kosong di antaranya. Fungsi ini menggunakan pendekatan binary search untuk menemukan lokasi pertama kata yang tidak kosong, dan kemudian melakukan pencarian biner untuk menemukan kata di lokasi tersebut. Hasilnya adalah indeks untuk kata-kata yang sedang dicari. Karena kata "bola" ditemukan di lokasi tertentu dalam array dalam contoh ini, pencarian kata "bola" akan menghasilkan indeks 6.


## CPMK 2 – SubCPMK 4
### 1. Berikan penjelasan dari struct dan buatlah sebuah contoh program dari struct!
- **Struct :** 
Struct adalah tipe data bentukan yang berisi kumpulan variabel-variabel yang bernaung dalam satu nama yang sama dan memiliki kaitan satu sama lain. Berbeda dengan array hanya berupa kumpulan variabel yang bertipe data sama, struct bisa memiliki variabel-variabel yang bertipe data sama atau berbeda, bahkan bisa menyimpan variabel yang bertipe data array atau struct itu sendiri. Variabel-variabel yang menjadi anggota struct disebut dengan elemen struct. Penggunaan/pemakaian tipe data struct dilakukan dengan membuat suatu variabel yang bertipe data struct tersebut. Pengaksesan elemen struct dilakukan secara individual dengan menyebutkan nama variabel struct diikuti dengan operator titik (.).

- **Contoh Program :**
```C++
#include <iostream>
#include <stdio.h>
using namespace std;
struct Mahasiswa
{
    char NIM[9];
    char nama[30];
    float ipk; };

int main()
{
    Mahasiswa mhs;
    system("cls");
    printf("NIM = ");scanf("%s", &mhs.NIM);
    printf("Nama = ");scanf("%s", &mhs.nama);
    printf("IPK = ");scanf("%f", &mhs.ipk);
    printf("Data Anda : \n");
    printf("NIM : %s\n", mhs.NIM);
    printf("Nama : %s\n", mhs.nama);
    printf("IPK : %f\n", mhs.ipk);
    
    return 0;
}
```
Data siswa seperti NIM, nama, dan IPK dimasukkan ke dalam program dan ditampilkan. Ini dilakukan melalui struktur "Mahasiswa", yang terdiri dari tiga komponen: NIM (nomor induk mahasiswa), nama, dan IPK (indeks prestasi kumulatif).  Program meminta pengguna untuk memasukkan data menggunakan `scanf`, kemudian menampilkannya.

## CPMK 2 – SubCPMK 5
### 1.	Buatlah sebuah fungsi program untuk menghilangkan duplikasi data pada unsorted linked list (single atau double atau circular) (40 Poin)
- **Single linked list :**
```C++
#include <iostream>
#include <unordered_set>

struct Node {
    int data;
    Node* next;
};

void removeDuplicates(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return;
    }

    std::unordered_set<int> seen;
    Node* current = head;
    Node* prev = nullptr;

    while (current != nullptr) {
        if (seen.find(current->data) != seen.end()) {
            prev->next = current->next;
            delete current;
            current = prev->next;
        } else {
            seen.insert(current->data);
            prev = current;
            current = current->next;
        }
    }
}

void displayList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

void push(Node** head, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = *head;
    *head = newNode;
}

int main() {
    Node* head = nullptr;
    push(&head, 10);
    push(&head, 12);
    push(&head, 11);
    push(&head, 12);
    push(&head, 11);
    push(&head, 10);

    std::cout << "Linked list sebelum menghapus duplikasi: ";
    displayList(head);

    removeDuplicates(head);

    std::cout << "Linked list setelah menghapus duplikasi: ";
    displayList(head);

    return 0;
}
```
- **Output :**
![Screenshot 2024-05-15 015628](https://github.com/Nargya/TeoriAlprodanStrukturData/assets/161468671/ebec68cc-a622-49fc-8312-a6c7f3eafe0f)

Code tersebut digunakan untuk menghapus duplikasi data dari single linked list. Fungsi `removeDuplicates` menggunakan set yang tidak terurut untuk melacak data yang telah ditemukan sebelumnya dalam linked list dan menghapus node yang memiliki data yang sama. Setiap data yang ditemukan pertama kali ditambahkan ke dalam set, dan ketika data yang sama ditemukan kembali, node tersebut dihapus. Untuk menguji efektivitasnya, program menampilkan linked list sebelum dan sesudah penghapusan duplikasi.

