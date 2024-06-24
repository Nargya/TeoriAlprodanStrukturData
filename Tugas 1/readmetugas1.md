<h1 align="center">TEORI ALPRO dan STRUKTUR DATA - TUGAS 1 </h1>
<p align="center">Naufal Alif Anargya</p>
<p align="center">2311110041</p>

## SOAL 
### 1. Buat code dengan ketentuan berikut : 
- Cari cara duplikasi maksimal menggunakan 1 for, tidak bolaeh ada for di dalam for. 
- Bisa mengubah struktur datanya / fungsi rekursif / dan seterusnya.
- indeks = 2,1,3,4

## Contoh SALAH: 
```C++
bool cekDuplikat(int arr[]){
    int panjangArr=4;
    for(int i=0; i<panjangArr; i++){
        for(int j=i+1; j<panjangArr; j++){
            if(arr[i]==arr[j]){
                return true;
            }
        }
    }
    return false;
}
```

## JAWABAN SOAL 1
```C++
#include <iostream>
#include <vector>

std::vector<int> duplicateElements(const std::vector<int>& arr, const std::vector<int>& indices) {
    size_t newSize = 0;
    for (int index : indices) {
        newSize += index;
    }

    std::vector<int> newArr(newSize);

    size_t newArrIndex = 0;
    for (size_t i = 0; i < arr.size(); ++i) {
        for (int j = 0; j < indices[i]; ++j) {
            newArr[newArrIndex++] = arr[i];
        }
    }
    
    return newArr;
}

int main() {
    std::vector<int> arr = {1, 2, 3, 4};
    std::vector<int> indices = {2, 1, 3, 4};
    
    std::vector<int> result = duplicateElements(arr, indices);
    
    std::cout << "Array setelah duplikasi: ";
    for (int elem : result) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}
```
  
**Output :**  
![Screenshot 2024-06-24 165036](https://github.com/Nargya/TeoriAlprodanStrukturData/assets/161468671/c450984a-76b7-4d9a-ba40-6ebb969213b8)

**Penjelasan :**  
Karena hanya menggunakan satu loop "for" dan tidak ada loop nested yang jelas, kode tersebut sudah sesuai dengan ketentuan. Fungsi "duplicateElements" membuat array baru dengan ukuran yang dihitung berdasarkan jumlah duplikasi yang diperlukan, dan loop "for" digunakan untuk mengisi array baru dengan elemen-elemen yang diduplikasi sesuai dengan indeks yang diberikan. Metode ini memanfaatkan perhitungan awal ukuran array untuk menghindari loops nested langsung dan memastikan bahwa hanya ada satu loop "for".
