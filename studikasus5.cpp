#include <iostream>
#include <iomanip>
using namespace std;

class sks {
  public :
    void input();
    void proses();
    int rekursif(int j, int i);
    void output();
  private :
   string a[20];
   string nama;
   int b[20];
   int hsks = 120000;
   int bykA, i, nim;
   float total, total_biaya1, total_biaya2, jml_sks, diskonsatu, 
 diskondua;
};

void sks::input(){
  cout<<"Masukkan Nama  :  "; cin>>nama;
  cout<<"Masukkan NIM   :  "; cin>>nim;
  cout<<"Masukkan banyak Mata Kuliah  : "; cin>>bykA;
  for(i = 0; i < bykA; i++){
    cout<<"Masukan mata kuliah " <<i + 1<< " : ";
    cin.ignore();
    getline(cin, a[i]);
    cout<<"Masukkan SKS          : ";
    cin>>b[i];
    cout<<"--------------------------------------"<<endl;
  }
}

int sks::rekursif(int j, int i){
  if(i < 0){
    return i;
  }
  else{
    jml_sks += b[i];
    total   += hsks * b[i];
    return rekursif(j, (i-1));
  }
}
//ini aku lanjutin
void sks::proses(){
  int j = 1;
  i--;
  rekursif(j,i);
  diskonsatu = total * 0,10;
  total_biaya1 = total - diskonsatu;
  diskondua = total_biaya1 * 0,05;
  total_biaya2 = total_biaya1 - diskondua;
}
void sks::output(){
	cout<<"\n\n=================================="<<endl;
	cout<<"Nama : " << nama <<endl;
	
	cout<<"NIM : " << nim <<endl;
	cout<<"---------------------------------------"<<endl;
	cout<<"Mata Kuliah			SKS "<<endl;
	cout<<"---------------------------------------"<<endl;
	for (i = 0; i <bykA; i++){
		cout<<" ";
		cout<<setiosflags(ios::left)<<setw(26)<<a[i]<<" ";
		cout<<setiosflags(ios::left)<<setw(2)<<b[i]<<endl;
	}
	cout<<"---------------------------------------"<<endl;
	cout<<"			     Jumlah SKS : "<<jml_sks<<endl;
	cout<<"			Pembayaran Awal : "<<total<<endl;
	cout<<"	Total Pembayaran Diskon : "<<total_biaya2<<endl;
	cout<<"---------------------------------------"<<endl;
}
int main(){
	sks a;
	a.input();
	a.proses();
	a.output();
}
