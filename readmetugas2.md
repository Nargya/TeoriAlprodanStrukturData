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
- **Output :** ![Screenshot 2024-05-16 224059](https://github.com/Nargya/TeoriAlprodanStrukturData/assets/161468671/84f713d6-3ae9-48b4-bf6c-b97173e971ed)

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
- **Output :** ![Screenshot 2024-05-16 224548](https://github.com/Nargya/TeoriAlprodanStrukturData/assets/161468671/e534a0b8-e9ed-4817-997f-cc66a82eb2d2)

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
- **Output :** ![Screenshot 2024-05-16 224724](https://github.com/Nargya/TeoriAlprodanStrukturData/assets/161468671/c196c188-c753-49c9-8b94-e4bb1d039469)


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
- **Output :** ![Screenshot 2024-05-16 224901](https://github.com/Nargya/TeoriAlprodanStrukturData/assets/161468671/9f5c6286-a094-4f5b-b7bc-429c944cfbcc)

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

- **Output :** ![Screenshot 2024-05-16 225122](https://github.com/Nargya/TeoriAlprodanStrukturData/assets/161468671/09c5da8f-5e09-4583-9570-72e74342a90f)

- **Penjelasan :** Data siswa seperti NIM, nama, dan IPK dimasukkan ke dalam program dan ditampilkan. Ini dilakukan melalui struktur "Mahasiswa", yang terdiri dari tiga komponen: NIM (nomor induk mahasiswa), nama, dan IPK (indeks prestasi kumulatif).  Program meminta pengguna untuk memasukkan data menggunakan `scanf`, kemudian menampilkannya.

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

### 2. Buatlah sebuah algoritma dan fungsi program untuk menghapus node di tengah single linked list! 

```C++
#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void insert(int data) {
        Node* new_node = new Node(data);
        if (head == nullptr) {
            head = new_node;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = new_node;
        }
    }

    void deleteMiddleNode(int position) {
        if (position <= 0 || head == nullptr || head->next == nullptr) {
            return;
        }

        Node* prev_node = nullptr;
        Node* current_node = head;
        int current_position = 1;

        while (current_node != nullptr && current_position < position) {
            prev_node = current_node;
            current_node = current_node->next;
            current_position++;
        }

        if (current_node == nullptr) {
            return;
        }

        if (prev_node == nullptr) {
            head = head->next;
        } else {
            prev_node->next = current_node->next;
        }

        delete current_node;
    }

    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList linkedList;
    linkedList.insert(1);
    linkedList.insert(2);
    linkedList.insert(3);
    linkedList.insert(4);
    linkedList.insert(5);

    cout << "Linked List awal:" << endl;
    linkedList.display();

    int positionToDelete = 3;
    linkedList.deleteMiddleNode(positionToDelete);

    cout << "Linked List setelah menghapus node ke-" << positionToDelete << ":" << endl;
    linkedList.display();

    return 0;
}
```
- **Output :** ![Screenshot 2024-05-16 225258](https://github.com/Nargya/TeoriAlprodanStrukturData/assets/161468671/ae35c052-19be-4ec6-b42a-c9e531843fb7)


- **Penjelasan :** Implementasi tersebut menggunakan dua kelas, yaitu `Node` dan `LinkedList`, untuk merepresentasikan linked list. Kelas `Node` digunakan untuk mewakili setiap elemen dalam linked list dengan properti `data` untuk menyimpan nilai data dan `next` sebagai pointer ke node berikutnya. Kelas `LinkedList` memiliki properti `head` yang merupakan pointer ke node pertama dalam linked list, serta metode untuk menyisipkan data baru (`insert`), menghapus node di tengah linked list berdasarkan posisi (`deleteMiddleNode`), dan menampilkan isi linked list (`display`). Dalam `main()`, linked list dibuat, data disisipkan, isi awal ditampilkan, kemudian sebuah node dihapus di tengah linked list, dan akhirnya isi linked list setelah penghapusan ditampilkan.

### 3. Buatlah sebuah program untuk mengecek apakah linked list adalah sebuah palindrom! 

```C++
#include <iostream>
#include <stack>
#include <string>
#include <locale>

std::string cleanAndLowercase(std::string str) {
    std::string cleanedStr;
    std::locale loc;

    for (char c : str) {
        if (std::isalpha(c, loc)) { 
            cleanedStr += std::tolower(c, loc); 
        }
    }

    return cleanedStr;
}

bool isPalindrome(std::string str) {
    std::stack<char> charStack;

    str = cleanAndLowercase(str);
    int length = str.length();
    int halfLength = length / 2;
    for (int i = 0; i < halfLength; ++i) {
        charStack.push(str[i]);
    }

    int i = (length % 2 == 0) ? halfLength : halfLength + 1;
    while (i < length) {
        if (str[i] != charStack.top()) {
            return false; 
        }
        charStack.pop();
        ++i;
    }

    return true; 
}

int main() {
    std::string input;
    std::cout << "Masukkan kalimat: ";
    std::getline(std::cin, input);

    if (isPalindrome(input)) {
        std::cout << "Kalimat tersebut adalah palindrom." << std::endl;
    } else {
        std::cout << "Kalimat tersebut bukan palindrom." << std::endl;
    }

    return 0;
}
```
- **Ouput :** ![Screenshot 2024-05-16 225433](https://github.com/Nargya/TeoriAlprodanStrukturData/assets/161468671/a4fdc9bb-0516-4249-95f2-6dd0d4947a06)

- **Penjelasan :** Program tersebut menentukan apakah sebuah kalimat yang dimasukkan pengguna merupakan palindrom atau tidak. Pertama, program membersihkan kalimat dari karakter non-alfabet dan mengubahnya menjadi huruf kecil. Kemudian, program membagi kalimat menjadi dua bagian dan memasukkan bagian pertama ke dalam stack. Setelah itu, program membandingkan setiap karakter dalam bagian kedua dengan karakter-karakter yang dikeluarkan dari stack. Jika semua karakter cocok, maka kalimat tersebut adalah palindrom. Jika tidak, maka kalimat tersebut bukan palindrom.

## CPMK 2 – SubCPMK 6
### 1. Tulislah sebuah program dari operasi stack seperti pop, push, isEmpty, isFull, dll(min 5)! 

```C++
#include <iostream>
using namespace std;

#define MAX_SIZE 5 // Ukuran maksimum stack

class Stack {
private:
    int top; // Indeks atas dari stack
    int arr[MAX_SIZE]; // Array untuk menyimpan elemen-elemen stack

public:
    // Konstruktor untuk menginisialisasi stack
    Stack() {
        top = -1; // Mengatur top ke -1 menandakan stack kosong
    }

    // Fungsi untuk menambahkan elemen ke stack (push)
    void push(int value) {
        if (isFull()) {
            cout << "Stack penuh. Tidak bisa menambahkan elemen lagi.\n";
        } else {
            top++;
            arr[top] = value;
            cout << "Elemen " << value << " berhasil ditambahkan ke stack.\n";
        }
    }

    // Fungsi untuk menghapus elemen dari stack (pop)
    void pop() {
        if (isEmpty()) {
            cout << "Stack kosong. Tidak ada elemen yang dapat dihapus.\n";
        } else {
            cout << "Elemen " << arr[top] << " dihapus dari stack.\n";
            top--;
        }
    }

    // Fungsi untuk memeriksa apakah stack kosong
    bool isEmpty() {
        return top == -1;
    }

    // Fungsi untuk memeriksa apakah stack penuh
    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    // Fungsi untuk menampilkan isi stack
    void display() {
        if (isEmpty()) {
            cout << "Stack kosong.\n";
        } else {
            cout << "Isi stack:\n";
            for (int i = top; i >= 0; i--) {
                cout << arr[i] << "\n";
            }
        }
    }
};

int main() {
    Stack stack;
    
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);

    stack.push(6); // Stack penuh, pesan akan ditampilkan

    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();

    stack.pop(); // Stack kosong, pesan akan ditampilkan

    return 0;
}
```
- **Output :** ![Screenshot 2024-05-16 225548](https://github.com/Nargya/TeoriAlprodanStrukturData/assets/161468671/225e9ad2-1a5b-4f69-a770-f5a71170035e)

- **Penjelasan :** Dengan array sebagai struktur penyimpanan, program ini menggunakan ide stack. Program ini melakukan semua operasi pada stack, seperti "push" untuk menambahkan elemen ke stack, "pop" untuk menghapus elemen dari stack, "isEmpty" untuk memeriksa apakah stack kosong, "isFull" untuk memeriksa apakah stack penuh, dan "display" untuk menampilkan isi stack. Selain itu, program ini mengirimkan pesan jika mencoba menambahkan elemen ke stack yang sudah penuh atau menghapus elemen

### 2. Dengan array sebagai struktur penyimpanan, program ini menggunakan ide stack. Program ini melakukan semua operasi pada stack, seperti "push" untuk menambahkan elemen ke stack, "pop" untuk menghapus elemen dari stack, "isEmpty" untuk memeriksa apakah stack kosong, "isFull" untuk memeriksa apakah stack penuh, dan "display" untuk menampilkan isi stack. Selain itu, program ini mengirimkan pesan jika mencoba menambahkan elemen ke stack yang sudah penuh atau menghapus elemen

```C++
#include <iostream>
#include <stack>
using namespace std;

// Fungsi untuk mensortir stack
void sortStack(stack<int>& mainStack) {
    stack<int> tempStack;
    
    while (!mainStack.empty()) {
        // Ambil elemen dari stack utama
        int temp = mainStack.top();
        mainStack.pop();
        
        // Pindahkan elemen dari stack utama ke stack sementara
        while (!tempStack.empty() && tempStack.top() > temp) {
            mainStack.push(tempStack.top());
            tempStack.pop();
        }
        tempStack.push(temp);
    }

    // Salin kembali elemen dari stack sementara ke stack utama
    while (!tempStack.empty()) {
        mainStack.push(tempStack.top());
        tempStack.pop();
    }
}

// Fungsi untuk menampilkan isi stack
void displayStack(stack<int> s) {
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    stack<int> myStack;
    myStack.push(30);
    myStack.push(-5);
    myStack.push(18);
    myStack.push(14);
    myStack.push(-3);

    cout << "Stack sebelum diurutkan: ";
    displayStack(myStack);

    sortStack(myStack);

    cout << "Stack setelah diurutkan: ";
    displayStack(myStack);

    return 0;
}
```
- **Output :** ![Screenshot 2024-05-16 225719](https://github.com/Nargya/TeoriAlprodanStrukturData/assets/161468671/1df0e074-6275-4d7f-a26c-f12219577815)

- **Penjelasan :** Program ini menggunakan dua stack, yaitu mainStack yang menyimpan elemen-elemen yang belum diurutkan dan tempStack yang digunakan sebagai stack sementara untuk menyimpan elemen-elemen yang sedang diurutkan. Algoritma yang digunakan untuk mengurutkan stack adalah dengan mengambil elemen dari mainStack, lalu memindahkan elemen-elemen yang lebih besar dari temp ke mainStack, dan memasukkan temp ke tempStack. Setelah itu, elemen-elemen dari tempStack dipindahkan kembali ke mainStack, sehingga stack diurutkan dari nilai terkecil hingga terbesar.

## CPMK 2 – SubCPMK 7
### 1. Tulislah sebuah program dari operasi queue seperti enqueue/add, dequeue/remove, isEmpty, isFull, dll(min 5)! 
```C++
#include <iostream>
using namespace std;

#define MAX_SIZE 5 // Ukuran maksimum queue

class Queue {
private:
    int front, rear; // Variabel untuk menyimpan indeks front dan rear
    int arr[MAX_SIZE]; // Array untuk menyimpan elemen-elemen queue

public:
    // Konstruktor untuk menginisialisasi queue
    Queue() {
        front = -1; // Mengatur front ke -1 menandakan queue kosong
        rear = -1; // Mengatur rear ke -1 menandakan queue kosong
    }

    // Fungsi untuk menambahkan elemen ke dalam queue (enqueue)
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue penuh. Tidak bisa menambahkan elemen lagi.\n";
        } else {
            if (isEmpty()) {
                front = rear = 0; // Jika queue kosong, atur front dan rear ke 0
            } else {
                rear = (rear + 1) % MAX_SIZE; // Geser rear ke depan (modulo untuk lingkaran)
            }
            arr[rear] = value;
            cout << "Elemen " << value << " berhasil ditambahkan ke dalam queue.\n";
        }
    }

    // Fungsi untuk menghapus elemen dari queue (dequeue)
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue kosong. Tidak ada elemen yang dapat dihapus.\n";
        } else {
            cout << "Elemen " << arr[front] << " dihapus dari queue.\n";
            if (front == rear) {
                front = rear = -1; // Jika queue hanya memiliki satu elemen, atur front dan rear ke -1
            } else {
                front = (front + 1) % MAX_SIZE; // Geser front ke depan (modulo untuk lingkaran)
            }
        }
    }

    // Fungsi untuk memeriksa apakah queue kosong
    bool isEmpty() {
        return front == -1 && rear == -1;
    }

    // Fungsi untuk memeriksa apakah queue penuh
    bool isFull() {
        return (rear + 1) % MAX_SIZE == front;
    }

    // Fungsi untuk menampilkan isi queue
    void display() {
        if (isEmpty()) {
            cout << "Queue kosong.\n";
        } else {
            cout << "Isi queue: ";
            int i = front;
            while (i != rear) {
                cout << arr[i] << " ";
                i = (i + 1) % MAX_SIZE; // Geser ke depan (modulo untuk lingkaran)
            }
            cout << arr[rear] << endl;
        }
    }
};

int main() {
    Queue queue;
    
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);

    queue.enqueue(6); // Queue penuh, pesan akan ditampilkan

    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();

    queue.dequeue(); // Queue kosong, pesan akan ditampilkan

    return 0;
}
```
- **Output :** ![Screenshot 2024-05-16 225831](https://github.com/Nargya/TeoriAlprodanStrukturData/assets/161468671/67844eaa-c4b9-4c5a-a8f6-42ce3ce1c42b)

- **Penjelasan :** Konsep queue digunakan dalam program ini, yang menggunakan array sebagai struktur penyimpanan. Program ini dapat melakukan semua operasi pada queue, seperti enqueue untuk menambahkan elemen ke dalam queue, dequeue untuk menghapus elemen dari queue, isEmpty untuk mengetahui apakah queue kosong, isFull untuk mengetahui apakah queue penuh, dan display untuk menampilkan isi queue. Selain itu, program ini akan mengirimkan pesan jika mencoba menambahkan elemen ke dalam queue yang sudah penuh atau menghapus elemen dari queue yang sudah kosong.

### 2. Sebuah selter hewan terlantar, yang mana hanya menerima kucing dan anjing, menerapkan konsep “first in, first out” dalam proses adopsi. Orang-orang yang hendak mengadopsi harus mengikuti aturan berikut: 1. mengadopsi hewan yang paling “tua” (berdasarkan waktu masuk ke selter) dan tidak dapat memilih kucing atau anjing; 2. memilih antara kucing atau anjing, namun akan menerima yang paling tua. Buatlah data struktur untuk mengimplementasikan kondisi tersebut, silahkan menggunakan beberapa operasi queue seperti enquee, dequeueAny, dequeueDog, dan dequeueCat.

```C++
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
```
- **Output :** ![Screenshot 2024-05-16 225945](https://github.com/Nargya/TeoriAlprodanStrukturData/assets/161468671/94f3f341-f97b-46d5-a3e5-dd6460f60dcf)

- **Penjelasan :** Dalam program ini, fungsi time(nullptr) digunakan untuk mencatat waktu kedatangan hewan ke shelter, yang dikenal sebagai time stamp. Setelah itu, kami mengidentifikasi hewan yang paling "tua" sebelum mengambilnya. DequeueAny dan DequeueCat masing-masing akan mengambil hewan terlama, sementara DequeueDog dan DequeueCat masing-masing akan mengambil kucing atau anjing terlama berdasarkan jenisnya.
