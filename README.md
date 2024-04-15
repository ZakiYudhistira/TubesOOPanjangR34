# Tugas Besar IF2250 | Kelola Kerajaan Bersama LabPro
## Kontributor
| NIM | Name |
| ------ | ------ |
| 13522018 | Ibrahim Ihsan Rasyid |
| 13522031 | Zaki Yudhistira Candra |
| 13522039 | Edbert Eddyson Gunawan |
| 13522049 | Vanson Kurnialim |
| 13522076 | Muhammad Syarafi Akmal |
| 10023510 | M Teguh Wijaksono |

## Kelola Kerajaan

Kelola kerjaan merupakan permainan sederhana yang melibatkan 3 peran yang berbeda, masing-masing peran akan berlomba untuk meraih nominal kekayaan tertentu dan berat badan tertentu demi memenangkan permainan. Terdapat 3 peran utama yaitu :
- Walikota (Hanya ada 1)
- Peternak
- Pemain

## Kebutuhan Program
- C++
- Program dijalankan di environment linux
- Compiler g++

## Instalasi
1. Clone repository ini
2. Buka terminal pada direktori repositori
3. Masukkan command make pada terminal
4. Tunggu hingga program dapat dijalankan

## Cara Memainkan Permainan
1. Permainan dapat dimainkan oleh minimal 2 orang pemain
2. Diwajibkan terdapat minimal 1 orang walikota untuk setiap sesi permainan
3. State permainan dapat disimpan dan dimuat
4. Pemain yang mencapai berat badan dan gulden tertentu akan memenangkan permainan

## Mekanik Permainan
Mekanik berikut dapat dijalankan oleh pemain dengan masukkan command pada terminal, tergantung pada giliran dan peran yang diperankan oleh pemain
1. NEXT
 | Untuk mengkahiri giliran, pemain dapat menjalankan perintah di bawah ini selama gilirannya berlangsung
2. CETAK_PENYIMPANAN
 | Untuk mencetak daftar barang atau produk yang dimiliki oleh pemain
3. PUNGUT_PAJAK (Walikota)
 | Walikota dapat memungut pajak dari pemain lainnya sebagai penghasilan utama walikota
4. CETAK_LADANG / CETAK_PETERNAKAN (Peternak / Petani)
 | Petani dan Peternak dapat mengetahui kondisi ladang / peternakan mereka melalui pencetakan ladang / peternakan
5. TANAM
 | Petani dapat menanam tanaman yang dibeli dari toko ke ladang
6. TERNAK
 | Petani dapat menaruh seekor binatang atau lebih pada peternakannya
7. BANGUN
 | Semua pemain dapat membangun bangunan, tetapi untuk walikota digratiskan
8. MAKAN
 | Semua pemain dapat mengonsumsi produk makanan yang ada di penyimpanannya
9. KASIH_MAKAN
 | Seorang peternak dapat memberi makan hewan ternaknya
10.BELI
 | Semua pemain dapat membeli sebuah barang dari toko
11.JUAL
 | Semua pemain dapat menjual komoditasnya apda toko dan memeroleh uang
12.PANEN
 | Petani dan Peternak dapat memanen hasil ternak / tani nyaaaaa
13.MUAT
 | Program dapat membuat state sebuah game yang telah berlangsung
14.SIMPAN
 | Program dapat menyimpan state game yang sedang berlangsung