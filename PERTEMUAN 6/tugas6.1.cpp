#include <iostream>
using namespace std;  

class contoh { //Nama class
private: //pembatas akses
  int nilai; //input variabel nilai pada tipe data int

public: //pemberian akses diluar class
  contoh(int n) {  // Pendeklarasian setter agar dapat memasukkan nilai pada "nilai"
    nilai = n; //inisialisasi nilai contoh dengan variabel nilai dan n
  } 
  int getNum() { //Pendeklarasian getter untuk mengambil nilai yang sudah dimasukkan pada fungsi setter
    return nilai; //memanggil nilai
  } 
};  //penutup class

int main() {
  contoh obj(10); //membuat objek dari sebuah class yang bernilai 10
  cout << "Nilai Yang diinput: " << obj.getNum() << endl; //output 

  return 0;
}

//program ini merupakan penerapan program constructor