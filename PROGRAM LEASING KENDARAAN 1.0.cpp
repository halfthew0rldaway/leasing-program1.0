#include <iostream>
#include <iomanip>
#include <cstring>
#include <conio.h>
#include <fstream>
#include <string>
#include <windows.h>
#include <ctime>
#include <cstdlib>


using namespace std;



struct DataPengajuan {
    string nomorKTP;
    string namaLengkap;
    string nomorTelepon;
    string alamatEmail;
    string kotaDomisili;
    int kodePos;
    bool sudahMenikah;
    int jumlahAnak;
    int jumlahIstri;
    string linkFile; 
};

struct Pelanggan {
    char nama[30];
    char alamat[40];
    char kd_mobil[4];
    char kd_motor[4];
    char merk[10];
    char tipe[10];
    char no_ktp[16];
    char id_transaksi[16];
    char no_hp[16];
    char pembayaran[16];
    int lama;
    int bunga;
    int cicilan;
    int tot_hrg;
    int totbay;
    int bayardp;
};

    
bool dataLengkap(const DataPengajuan& data) {
    if (data.sudahMenikah) {
        return !data.nomorKTP.empty() && !data.namaLengkap.empty() && !data.nomorTelepon.empty() &&
               !data.alamatEmail.empty() && !data.kotaDomisili.empty() && data.kodePos > 0 && data.jumlahAnak >= 0 &&
               !data.linkFile.empty();
    } else {
        return !data.nomorKTP.empty() && !data.namaLengkap.empty() && !data.nomorTelepon.empty() &&
               !data.alamatEmail.empty() && !data.kotaDomisili.empty() && data.kodePos > 0 &&
               !data.linkFile.empty();
    }
}

void prosesPengajuan(const DataPengajuan& data) {
    if (dataLengkap(data)) {
        cout << "Pengajuan kredit untuk " << data.namaLengkap << " telah diverifikasi." << endl;
    }
}

void inputDataPengajuan(DataPengajuan& pengajuan) {
    cout << "\t\t ==================================================" << endl;
    cout << "\t\t	MOHON DILENGKAPI UNTUK TAHAP VERIFIKASI!" << endl;
    cout << "\t\t ==================================================" << endl;
    
    cout << "Masukkan nama lengkap   : ";
    getline(cin, pengajuan.namaLengkap);
    system("cls");
    
    cout << "\t\t ==================================================" << endl;
    cout << "\t\t 	MOHON DILENGKAPI UNTUK TAHAP VERIFIKASI!" << endl;
    cout << "\t\t ==================================================" << endl;
    
    cout << "Masukkan nomor KTP      : ";
    getline(cin, pengajuan.nomorKTP);
    system("cls");

    cout << "\t\t ==================================================" << endl;
    cout << "\t\t 	MOHON DILENGKAPI UNTUK TAHAP VERIFIKASI!" << endl;
    cout << "\t\t ==================================================" << endl;

    cout << "Masukkan nomor telepon  : ";
    getline(cin, pengajuan.nomorTelepon);
    system("cls");

    cout << "\t\t ==================================================" << endl;
    cout << "\t\t 	MOHON DILENGKAPI UNTUK TAHAP VERIFIKASI!" << endl;
    cout << "\t\t ==================================================" << endl;

    cout << "Masukkan alamat email   : ";
    getline(cin, pengajuan.alamatEmail);
    system("cls");

    cout << "\t\t ==================================================" << endl;
    cout << "\t\t 	MOHON DILENGKAPI UNTUK TAHAP VERIFIKASI!" << endl;
    cout << "\t\t ==================================================" << endl;

    cout << "Masukkan kota domisili  : ";
    getline(cin, pengajuan.kotaDomisili);
    system("cls");

    cout << "\t\t ==================================================" << endl;
    cout << "\t\t 	MOHON DILENGKAPI UNTUK TAHAP VERIFIKASI!" << endl;
    cout << "\t\t ==================================================" << endl;

    cout << "Masukkan kode pos       : ";
    cin >> pengajuan.kodePos;
    cin.ignore(); 
    system("cls");

    cout << "\t\t ==================================================" << endl;
    cout << "\t\t 	MOHON DILENGKAPI UNTUK TAHAP VERIFIKASI!" << endl;
    cout << "\t\t ==================================================" << endl;

    cout << "Apakah sudah menikah? (0 untuk tidak, 1 untuk ya): ";
    cin >> pengajuan.sudahMenikah;

    if (pengajuan.sudahMenikah) {
        cout << "Masukkan jumlah istri   : ";
        cin >> pengajuan.jumlahIstri;
        cout << "Masukkan jumlah anak    : ";
        cin >> pengajuan.jumlahAnak;
    }
    system("cls");

    cin.ignore();
    cout << "\t\t ==================================================" << endl;
    cout << "\t\t 	MOHON DILENGKAPI UNTUK TAHAP VERIFIKASI!" << endl;
    cout << "\t\t ==================================================" << endl;

    cout << "Masukkan link folder drive yang isinya\n"
         << "berupa foto selfie KTP, foto kartu keluarga,\n"
         << "foto slip gaji 3 bulan terakhir, dan foto surat nikah : ";
    getline(cin, pengajuan.linkFile);

}

int main() {
    DataPengajuan pengajuan;
    Pelanggan pelanggan;

    inputDataPengajuan(pengajuan);

    system("cls");
    cout << "DATA PENGAJUAN KREDIT" << endl;
    cout << "==================================================" << endl;
    cout << "\tNama Lengkap   	  : " << pengajuan.namaLengkap << endl;
    cout << "\tNomor KTP      	  : " << pengajuan.nomorKTP << endl;
    cout << "\tNomor Telepon  	  : " << pengajuan.nomorTelepon << endl;
    cout << "\tAlamat Email   	  : " << pengajuan.alamatEmail << endl;
    cout << "\tKota Domisili  	  : " << pengajuan.kotaDomisili << endl;
    cout << "\tKode Pos       	  : " << pengajuan.kodePos << endl;
    cout << "\tSudah Menikah  	  : " << (pengajuan.sudahMenikah ? "Ya" : "Tidak") << endl;
    if (pengajuan.sudahMenikah) {
    cout << "\tJumlah Istri   	  : " << pengajuan.jumlahIstri << endl;
    cout << "\tJumlah Anak    	  : " << pengajuan.jumlahAnak << endl;
    }
    cout << "\tLink Folder Drive : " << pengajuan.linkFile << endl;

    prosesPengajuan(pengajuan);
    
    if (!dataLengkap(pengajuan)) {
    cout << "Data pengajuan tidak lengkap. Pengajuan kredit tidak dapat diproses." << endl;
    return 1;
	}
	
	cout << "\n\nTekan tombol apa saja untuk melanjutkan...";
    cin.get();  
    
    char lagi;
    int input, tipe_mobil, tipe_motor, hrg_mobil, hrg_motor;

menu:
	system("cls");
    cout << endl << endl;
    cout << "\t\t==============================================" << endl;
    cout << "\t\t        | PROGRAM KREDIT KENDARAAN | " << endl;
    cout << "\t\t        |     COBA COBA FINANCE    | " << endl;
    cout << "\t\t        |      BEKASI ASELI        | " << endl;
    cout << "\t\t==============================================" << endl;
    cout << endl << endl;
    cout << "\t\t Selamat Datang Di COBA COBA FINANCE " << endl << endl;
    cout << "\t Pilihan Menu : " << endl << endl;
    cout << "\t 1. Beli Mobil " << endl;
    cout << "\t 2. Beli Motor " << endl;
    cout << "\t 3. Informasi Harga Unit Yang Tersedia " << endl;
    cout << "\t 4. Keluar " << endl;
    cout << "\t =======================================================" << endl << endl << endl;
    cout << "\t Input Pilihan Anda : ";
    cin >> input;

    if (input == 1)
    {
        system("cls");
    mobil:
    	system("cls");
        cout << endl << endl;
        cout << "\t\t==============================================" << endl;
        cout << "\t\t        | PROGRAM KREDIT KENDARAAN | " << endl;
        cout << "\t\t        |     COBA COBA FINANCE    | " << endl;
        cout << "\t\t        |      BEKASI ASELI        | " << endl;
        cout << "\t\t==============================================" << endl;
        cout << endl << endl;
        cout << " Nama   \t\t: ";
        cin.ignore();
        cin.getline(pelanggan.nama, sizeof(pelanggan.nama));
        cout << " Alamat \t\t: ";
        cin.getline(pelanggan.alamat, sizeof(pelanggan.alamat));
        cout << " Nomor KTP \t\t: ";
        cin.getline(pelanggan.no_ktp, sizeof(pelanggan.no_ktp));
        cout << " Nomor HP \t\t: ";
        cin.getline(pelanggan.no_hp, sizeof(pelanggan.no_hp));
        cout << " Metode Pembayaran\t: ";
        cin.getline(pelanggan.pembayaran, sizeof(pelanggan.pembayaran));
    	cout << " Jumlah DP\t\t: ";
    	cin >> pelanggan.bayardp; 
    	cin.ignore();
    	
        system("cls");
        cout << "\n\t\t==============================" << endl;
        cout << " \t\t| MERK MOBIL | KODE MOBIL|" << endl;
        cout << " \t\t==============================" << endl;
        cout << " \t\t| 1. TOYOTA   | TY        |" << endl;
        cout << " \t\t| 2. DAIHATSU | DH        |" << endl;
        cout << " \t\t| 3. Suzuki   | SZ        |" << endl;
        cout << " \t\t==============================" << endl;
        cout << "\n Masukan Kode Mobil [TY/DH/SZ] : ";
        cin.getline(pelanggan.kd_mobil, sizeof(pelanggan.kd_mobil));

        if ((strcmp(pelanggan.kd_mobil, "TY") == 0) || (strcmp(pelanggan.kd_mobil, "ty") == 0))
        {
            strcpy(pelanggan.merk, " Toyota");
            system("cls");
        kembali1:
            cout << endl << endl;
            cout << "\t\t ============================" << endl;
            cout << "\t\t | Tipe Mobil | Harga |" << endl;
            cout << "\t\t ============================" << endl;
            cout << "\t\t | 1.Fortuner |Rp.560.250.000 |" << endl;
            cout << "\t\t | 2.Avanza   |Rp.272.100.000 |" << endl;
            cout << "\t\t | 3.Innova   |Rp.379.120.000 |" << endl;
            cout << "\t\t ============================" << endl;
            cout << "\n Pilih Tipe Mobil [1/2/3] : ";
            cin >> tipe_mobil;
            cout << endl;

            if (tipe_mobil == 1)
            {
                strcpy(pelanggan.tipe, " Fortuner");
                hrg_mobil = 560250000;
            }
            else if (tipe_mobil == 2)
            {
                strcpy(pelanggan.tipe, " Avanza");
                hrg_mobil = 272100000;
            }
            else if (tipe_mobil == 3)
            {
                strcpy(pelanggan.tipe, " Innova");
                hrg_mobil = 379120000;
            }
            else
            {
                system("cls");
                cout << "\n\n\t\tTipe Mobil Tidak Tersedia. Silahkan Ulangi !!" << endl;
                goto kembali1;
            }
        }
        else if ((strcmp(pelanggan.kd_mobil, "DH") == 0) || (strcmp(pelanggan.kd_mobil, "dh") == 0))
        {
            strcpy(pelanggan.merk, " Daihatsu");
            system("cls");
        kembali2:
            cout << endl << endl;
            cout << "\t\t ============================" << endl;
            cout << "\t\t | Tipe Mobil | Harga |" << endl;
            cout << "\t\t ============================" << endl;
            cout << "\t\t | 1.Sigra    |Rp.136.180.000 |" << endl;
            cout << "\t\t | 2.Xenia    |Rp.220.240.000 |" << endl;
            cout << "\t\t | 3.Terios   |Rp.243.050.000 |" << endl;
            cout << "\t\t ============================" << endl;
            cout << "\n Pilih Tipe Mobil [1/2/3] : ";
            cin >> tipe_mobil;
            cout << endl;

            if (tipe_mobil == 1)
            {
                strcpy(pelanggan.tipe, " Sigra");
                hrg_mobil = 136180000;
            }
            else if (tipe_mobil == 2)
            {
                strcpy(pelanggan.tipe, " Xenia");
                hrg_mobil = 220240000;
            }
            else if (tipe_mobil == 3)
            {
                strcpy(pelanggan.tipe, " Terios");
                hrg_mobil = 243050000;
            }
            else
            {
                system("cls");
                cout << "\n\n\t\tTipe Mobil Tidak Tersedia. Silahkan Ulangi !!" << endl;
                goto kembali2;
            }
        }
        else if ((strcmp(pelanggan.kd_mobil, "SZ") == 0) || (strcmp(pelanggan.kd_mobil, "sz") == 0))
        {
            strcpy(pelanggan.merk, " Suzuki");
            system("cls");
        kembali3:
            cout << endl << endl;
            cout << "\t\t ============================" << endl;
            cout << "\t\t | Tipe Mobil | Harga |" << endl;
            cout << "\t\t ============================" << endl;
            cout << "\t\t | 1.XL7      |Rp.259.300.000 |" << endl;
            cout << "\t\t | 2.Ignis    |Rp.213.880.000 |" << endl;
            cout << "\t\t | 3.Ertiga   |Rp.262.650.000  |" << endl;
            cout << "\t\t ============================" << endl;
            cout << "\n Pilih Tipe Mobil [1/2/3] : ";
            cin >> tipe_mobil;
            cout << endl;

            if (tipe_mobil == 1)
            {
                strcpy(pelanggan.tipe, " XL7");
                hrg_mobil = 259300000;
            }
            else if (tipe_mobil == 2)
            {
                strcpy(pelanggan.tipe, " Ignis");
                hrg_mobil = 213880000;
            }
            else if (tipe_mobil == 3)
            {
                strcpy(pelanggan.tipe, " Ertiga");
                hrg_mobil = 262650000;
            }
            else
            {
                system("cls");
                cout << "\n\n\t\tTipe Mobil Tidak Tersedia. Silahkan Ulangi !!" << endl;
                goto kembali3;
            }
        }
        else
        {
            cout << "\n\n\t\tKode Mobil Tidak Tersedia. Silahkan Ulangi !!" << endl;
            goto mobil;
        }
        cout << " Lama Cicilan (bulan) : ";
        cin >> pelanggan.lama;

    pelanggan.tot_hrg = hrg_mobil / pelanggan.lama;
    pelanggan.bunga = 0;

        if (pelanggan.lama == 6) {
        pelanggan.bunga = pelanggan.tot_hrg * 0.03;
        } else if (pelanggan.lama == 12) {
        pelanggan.bunga = pelanggan.tot_hrg * 0.06;
         } else if (pelanggan.lama == 18) {
        pelanggan.bunga = pelanggan.tot_hrg * 0.09;
        } else if (pelanggan.lama == 24) {
        pelanggan.bunga = pelanggan.tot_hrg * 0.12;
        } else if (pelanggan.lama == 30) {
        pelanggan.bunga = pelanggan.tot_hrg * 0.15;
        } else {
        std::cout << "Durasi cicilan tidak valid. Program berhenti." << std::endl;
        return 1; // Exit with error code
        }
        pelanggan.cicilan= pelanggan.tot_hrg + pelanggan.bunga - pelanggan.bayardp;
        
        pelanggan.totbay = pelanggan.cicilan * pelanggan.lama;

        // Menyimpan data pelanggan ke dalam file EXCEL
        ofstream outfile;
        outfile.open("pelanggan.csv", ios::app);
        outfile << pelanggan.nama << ","
                << pelanggan.alamat << ","
                << pelanggan.no_ktp << ","
                << pelanggan.no_hp << ","
                << pelanggan.pembayaran << ","
                << pelanggan.merk << ","
                << pelanggan.tipe << ","
                << pelanggan.tot_hrg << ","
                << pelanggan.bunga << ","
                << pelanggan.cicilan << ","
                << pelanggan.bayardp << ","
                << pelanggan.totbay << endl;
        outfile.close();

        system("cls");

        cout << "\t\t==============================================" << endl;
        cout << "\t\t        | PROGRAM KREDIT KENDARAAN | " << endl;
        cout << "\t\t        |     COBA COBA FINANCE    | " << endl;
        cout << "\t\t        |      BEKASI ASELI        | " << endl;
        cout << "\t\t==============================================" << endl;
        cout << "\t\t Nama\t\t\t: " << pelanggan.nama << endl;
        cout << "\t\t Alamat\t\t\t: " << pelanggan.alamat << endl;
        cout << "\t\t Nomor KTP\t\t: " << pelanggan.no_ktp << endl;
        cout << "\t\t Nomor HP\t\t: " << pelanggan.no_hp << endl;
        cout << "\t\t Pembayaran\t\t: " << pelanggan.pembayaran << endl;
        cout << "\t\t Jenis Kendaraan\t:" << pelanggan.merk << pelanggan.tipe << endl;
        cout << "\t\t Harga\t\t        : Rp." << hrg_mobil << endl;
        cout << "\t\t Lama cicilan\t\t: " << pelanggan.lama << " Bulan" << endl;
        cout << "\t\t DP \t\t\t: Rp." << pelanggan.bayardp << endl;
        cout << "\t\t==============================================" << endl;
        cout << "\t\t Cicilan per-bulan belum termasuk bunga\t\t: Rp." << pelanggan.tot_hrg << endl;
        cout << "\t\t bunga (3%) *berlaku kelipatan sesuai tenor\t: Rp." << pelanggan.bunga << endl;
         cout << "\t\t------------------------------------------------------------" << endl;
        cout << "\t\t DP yang sudah dibayar						  : -Rp." << pelanggan.bayardp << endl;
        cout << "\t\t------------------------------------------------------------" << endl;
        cout << "\t\t Total Cicilan Yang Harus Dibayar per-bulan\t: Rp." << pelanggan.cicilan << endl;
        cout << "\t\t==============================================" << endl;

        cout << "\n\n\t\tBeli Lagi ? (Y/T) : ";
        cin >> lagi;
        if (lagi == 'Y' || lagi == 'y')
            goto menu;
        else
            goto selesai;
    }
    else if (input == 2)
    {
        system("cls");
    motor:
        cout << endl << endl;
        cout << "\t\t==============================================" << endl;
        cout << "\t\t        | PROGRAM KREDIT KENDARAAN | " << endl;
        cout << "\t\t        |     COBA COBA FINANCE    | " << endl;
        cout << "\t\t        |      BEKASI ASELI        | " << endl;
        cout << "\t\t==============================================" << endl;
        cout << endl << endl;
        cout << " Nama    \t\t: ";
        cin.ignore();
        cin.getline(pelanggan.nama, sizeof(pelanggan.nama));
        cout << " Alamat\t\t\t: ";
        cin.getline(pelanggan.alamat, sizeof(pelanggan.alamat));
        cout << " Nomor KTP\t\t: ";
        cin.getline(pelanggan.no_ktp, sizeof(pelanggan.no_ktp));
        cout << " Nomor HP\t\t: ";
        cin.getline(pelanggan.no_hp, sizeof(pelanggan.no_hp));
        cout << " Metode Pembayaran\t: ";
        cin.getline(pelanggan.pembayaran, sizeof(pelanggan.pembayaran));
        system("cls");
        cout << "\n\t\t==============================" << endl;
        cout << " \t\t| MERK MOTOR | KODE MOTOR |" << endl;
        cout << " \t\t==============================" << endl;
        cout << " \t\t| 1. Honda   | HN        |" << endl;
        cout << " \t\t| 2. Yamaha  | YM        |" << endl;
        cout << " \t\t| 3. Suzuki  | SZ        |" << endl;
        cout << " \t\t==============================" << endl;
        cout << "\n Masukan Kode Motor [HN/YM/SZ] : ";
        cin >> pelanggan.kd_motor;

        if ((strcmp(pelanggan.kd_motor, "HN") == 0) || (strcmp(pelanggan.kd_motor, "hn") == 0))
        {
            strcpy(pelanggan.merk, " Honda");
            system("cls");
        kembali4:
            cout << endl << endl;
            cout << "\t\t ============================" << endl;
            cout << "\t\t | Tipe Motor    | Harga |" << endl;
            cout << "\t\t ============================" << endl;
            cout << "\t\t | 1.CBR150    |Rp.38.962.000 |" << endl;
            cout << "\t\t | 2.Vario     |Rp.27.750.000  |" << endl;
            cout << "\t\t | 3.PCX       |Rp.36.080.000  |" << endl;
            cout << "\t\t ============================" << endl;
            cout << "\n Pilih Tipe Motor [1/2/3] : ";
            cin >> tipe_motor;
            cout << endl;

            if (tipe_motor == 1)
            {
                strcpy(pelanggan.tipe, " CBR150");
                hrg_motor = 38962000;
            }
            else if (tipe_motor == 2)
            {
                strcpy(pelanggan.tipe, " Vario");
                hrg_motor = 27750000;
            }
            else if (tipe_motor == 3)
            {
                strcpy(pelanggan.tipe, " PCX");
                hrg_motor = 36080000;
            }
            else
            {
                system("cls");
                cout << "\n\n\t\tTipe Motor Tidak Tersedia. Silahkan Ulangi !!" << endl;
                goto kembali4;
            }
        }
        else if ((strcmp(pelanggan.kd_motor, "YM") == 0) || (strcmp(pelanggan.kd_motor, "ym") == 0))
        {
            strcpy(pelanggan.merk, " Yamaha");
            system("cls");
        kembali5:
            cout << endl << endl;
            cout << "\t\t ============================" << endl;
            cout << "\t\t | Tipe Motor  | Harga |" << endl;
            cout << "\t\t ============================" << endl;
            cout << "\t\t | 1.R15     |Rp.44.995.000 |" << endl;
            cout << "\t\t | 2.Aerox   |Rp.31.560.000 |" << endl;
            cout << "\t\t | 3.Nmax    |Rp.25.700.000  |" << endl;
            cout << "\t\t ============================" << endl;
            cout << "\n Pilih Tipe Motor [1/2/3] : ";
            cin >> tipe_motor;
            cout << endl;

            if (tipe_motor == 1)
            {
                strcpy(pelanggan.tipe, " R15");
                hrg_motor = 44995000;
            }
            else if (tipe_motor == 2)
            {
                strcpy(pelanggan.tipe, " Aerox");
                hrg_motor = 31560000;
            }
            else if (tipe_motor == 3)
            {
                strcpy(pelanggan.tipe, " Nmax");
                hrg_motor = 25700000;
            }
            else
            {
                system("cls");
                cout << "\n\n\t\tTipe Motor Tidak Tersedia. Silahkan Ulangi !!" << endl;
                goto kembali5;
            }
        }
        else if ((strcmp(pelanggan.kd_motor, "SZ") == 0) || (strcmp(pelanggan.kd_motor, "sz") == 0))
        {
            strcpy(pelanggan.merk, " Suzuki");
            system("cls");
        kembali6:
            cout << endl << endl;
            cout << "\t\t ============================" << endl;
            cout << "\t\t | Tipe Motor 	  | Harga |" << endl;
            cout << "\t\t ============================" << endl;
            cout << "\t\t | 1.GSX        |Rp.38.350.000 |" << endl;
            cout << "\t\t | 2.Address	 |Rp.20.870.000  |" << endl;
            cout << "\t\t | 3.Burgman	 |Rp.24.700.000  |" << endl;
            cout << "\t\t ============================" << endl;
            cout << "\n Pilih Tipe Motor [1/2/3] : ";
            cin >> tipe_motor;
            cout << endl;

            if (tipe_motor == 1)
            {
                strcpy(pelanggan.tipe, " GSX");
                hrg_motor = 38350000;
            }
            else if (tipe_motor == 2)
            {
                strcpy(pelanggan.tipe, " Address");
                hrg_motor = 20870000;
            }
            else if (tipe_motor == 3)
            {
                strcpy(pelanggan.tipe, " Burgman");
                hrg_motor = 24700000;
            }
            else
            {
                system("cls");
                cout << "\n\n\t\tTipe Motor Tidak Tersedia. Silahkan Ulangi !!" << endl;
                goto kembali6;
            }
        }
        else
        {
            cout << "\n\n\t\tKode Motor Tidak Tersedia. Silahkan Ulangi !!" << endl;
            goto motor;
        }
        cout << " Lama Peminjaman (Bulan) : ";
        cin >> pelanggan.lama;

    pelanggan.tot_hrg = hrg_motor / pelanggan.lama;
    pelanggan.bunga = 0;

        if (pelanggan.lama == 6) {
        pelanggan.bunga = pelanggan.tot_hrg * 0.03;
        } else if (pelanggan.lama == 12) {
        pelanggan.bunga = pelanggan.tot_hrg * 0.06;
         } else if (pelanggan.lama == 18) {
        pelanggan.bunga = pelanggan.tot_hrg * 0.09;
        } else if (pelanggan.lama == 24) {
        pelanggan.bunga = pelanggan.tot_hrg * 0.12;
        } else if (pelanggan.lama == 30) {
        pelanggan.bunga = pelanggan.tot_hrg * 0.15;
        } else {
        std::cout << "Durasi cicilan tidak valid. Program berhenti." << std::endl;
        return 1;
        }
        pelanggan.cicilan = pelanggan.tot_hrg + pelanggan.bunga;
        pelanggan.totbay = pelanggan.cicilan * pelanggan.lama;

        // Menyimpan data pelanggan ke dalam file EXCEL
        ofstream outfile;
        outfile.open("pelanggan.csv", ios::app);
        outfile << pelanggan.nama << ","
                << pelanggan.alamat << ","
                << pelanggan.no_ktp << ","
                << pelanggan.no_hp << ","
                << pelanggan.pembayaran << ","
                << pelanggan.merk << ","
                << pelanggan.tipe << ","
                << pelanggan.tot_hrg << ","
                << pelanggan.bunga << ","
                << pelanggan.cicilan << ","
                << pelanggan.totbay << endl;
        outfile.close();

    	
        system("cls");


        cout << "\t\t==============================================" << endl;
        cout << "\t\t        | PROGRAM KREDIT KENDARAAN | " << endl;
        cout << "\t\t        |     COBA COBA FINANCE    | " << endl;
        cout << "\t\t        |      BEKASI ASELI        | " << endl;
        cout << "\t\t==============================================" << endl;
        cout << "\t\t 					Resi 					   " << endl;
        cout << "\t\t==============================================" << endl;
        cout << "\t\t Nama\t\t\t: " << pelanggan.nama << endl;
        cout << "\t\t Alamat\t\t\t: " << pelanggan.alamat << endl;
        cout << "\t\t Nomor KTP\t\t: " << pelanggan.no_ktp << endl;
        cout << "\t\t Nomor HP\t\t: " << pelanggan.no_hp << endl;
        cout << "\t\t Pembayaran\t\t: " << pelanggan.pembayaran << endl;
        cout << "\t\t Jenis Kendaraan\t:" << pelanggan.merk << pelanggan.tipe << endl;
        cout << "\t\t Harga\t\t        : Rp." << hrg_motor << endl;
        cout << "\t\t Lama cicilan\t\t: " << pelanggan.lama << " Bulan" << endl;
        cout << "\t\t==============================================" << endl;
        cout << "\t\t Cicilan per-bulan belum termasuk bunga\t\t: Rp." << pelanggan.tot_hrg << endl;
        cout << "\t\t bunga (3%) *berlaku kelipatan sesuai tenor\t: Rp." << pelanggan.bunga << endl;
        cout << "\t\t------------------------------------------------------------" << endl;
        cout << "\t\t Total Cicilan Yang Harus Dibayar per-bulan\t: Rp." << pelanggan.cicilan << endl;
        cout << "\t\t==============================================" << endl;

        cout << "\n\n\t\tBeli Lagi ? (Y/T) : ";
        cin >> lagi;
        if (lagi == 'Y' || lagi == 'y')
            goto menu;
        else
            goto selesai;
    }
    else if (input == 3)
        {
        system("cls");
        cout << endl
             << endl;
        cout << "\t\t==============================================" << endl;
        cout << "\t\t        | PROGRAM KREDIT KENDARAAN | " << endl;
        cout << "\t\t        |     COBA COBA FINANCE    | " << endl;
        cout << "\t\t        |      BEKASI ASELI        | " << endl;
        cout << "\t\t==============================================" << endl;
        cout << endl
             << endl;
        cout << " Berikut informasi tentang harga unit yang tersedia : " << endl
             << endl;
        cout << "\n\t========================================================" << endl;
        cout << " \t| MERK MOBIL | KODE MOBIL | TIPE MOBIL | HARGA     |" << endl;
        cout << "\t========================================================" << endl;
        cout << " \t|            |            | 1.Fortuner |Rp.560.250.000 |" << endl;
        cout << " \t| TOYOTA     | TY         | 2.Avanza   |Rp.272.180.000 |" << endl;
        cout << " \t|            |            | 3.Innova   |Rp.379.120.000 |" << endl;
        cout << " \t----------------------------------------------------------" << endl;
        cout << " \t|            |            | 1.Sigra   |Rp.136.180.000 |" << endl;
        cout << " \t| DAIHATSU   | DH         | 2.Xenia   |Rp.220.240.000 |" << endl;
        cout << " \t|            |            | 3.Terios  |Rp.243.050.000 |" << endl;
        cout << " \t----------------------------------------------------------" << endl;
        cout << " \t|            |            | 1.XL7      |Rp.259.300.000 |" << endl;
        cout << " \t| SUZUKI     | SZ         | 2.Ignis    |Rp.213.880.000 |" << endl;
        cout << " \t|            |            | 3.Ertiga   |Rp.262.650.000 |" << endl;
        cout << "\t========================================================" << endl;
                cout << "\n\t========================================================" << endl;
        cout << " \t| MERK MOTOR | KODE MOTOR | TIPE MOTOR |  HARGA    |" << endl;
        cout << "\t========================================================" << endl;
        cout << " \t|            |            | 1.R15      |Rp.44.995.000 |" << endl;
        cout << " \t| YAMAHA     | YM         | 2.AEROX    |Rp.31.560.000 |" << endl;
        cout << " \t|            |            | 3.NMAX     |Rp.25.700.000 |" << endl;
        cout << " \t----------------------------------------------------------" << endl;
        cout << " \t|            |            | 1.CBR150   |Rp.38.962.000  |" << endl;
        cout << " \t| HONDA      | HD         | 2.VARIO    |Rp.27.750.000  |" << endl;
        cout << " \t|            |            | 3.PCX      |Rp.36.080.000 |" << endl;
        cout << " \t----------------------------------------------------------" << endl;
        cout << " \t|            |            | 1.GSX      |Rp.38.350.000  |" << endl;
        cout << " \t| SUZUKI     | SZ         | 2.ADDRESS  |Rp.20.870.000  |" << endl;
        cout << " \t|            |            | 3.BURGMAN  |Rp.24.700.000 |" << endl;
        cout << "\t========================================================" << endl;
        cout << "\n\n Tekan [Enter] untuk kembali ke Menu Utama ";
        getch();
        goto menu;
    }
    else if (input == 4)
    {
    selesai:
        cout << endl << endl;
        cout << "\n\n\t\t\t\tTerima Kasih Telah Menggunakan Layanan Kami" << endl;
    }
    else
    {
        cout << "\n\n\t\t\tPilihan Tidak Tersedia. Silahkan Ulangi !!" << endl;
        goto menu;
    }

    std::cout << "Press any key to exit...";
    std::cin.ignore();
    std::cin.get(); 

    return 0;
}
