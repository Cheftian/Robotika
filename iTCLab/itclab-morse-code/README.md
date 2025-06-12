# Arduino Morse Code LED: Mengirim Pesan "HELLO"

## Deskripsi  
Program ini menggunakan sebuah LED yang terhubung pada pin 2 Arduino untuk mengirimkan pesan "HELLO" dalam kode Morse. LED akan menyala dengan pola durasi pendek dan panjang sesuai dengan titik (dot) dan garis (dash) Morse yang merepresentasikan setiap huruf dari kata "HELLO."

## Spesifikasi Pin  
- LED terhubung pada pin **2**

## Pola Morse "HELLO"  
- H: .... (empat titik)  
- E: . (satu titik)  
- L: .-.. (titik-garis-titik-titik), diulang dua kali untuk dua huruf L  
- O: --- (tiga garis)

## Penjelasan Fungsi  
- `lowMorse()`: Menyalakan LED dengan durasi pendek (500ms delay sebelum dan saat LED ON) — merepresentasikan titik (dot).  
- `longMorse()`: Menyalakan LED dengan durasi panjang (4000ms delay sebelum dan saat LED ON) — merepresentasikan garis (dash).  
- `intervalMorse()`: Delay dengan LED menyala dan mati (2000ms delay sebelumnya dan saat LED ON) sebagai jeda antar huruf dalam pesan.

## Cara Kerja Program  
1. Fungsi `setup()` mengatur mode pin LED sebagai output.  
2. Fungsi `loop()` menjalankan urutan pola Morse untuk kata "HELLO":  
   - Mengirim sinyal Morse untuk H, E, dua huruf L, dan O secara berurutan.  
   - Menggunakan `lowMorse()`, `longMorse()`, dan `intervalMorse()` untuk mengatur durasi LED menyala dan jeda antar sinyal.  

## Catatan  
- Delay yang digunakan memastikan LED menyala dengan durasi yang cukup jelas untuk masing-masing titik dan garis kode Morse.  
- Interval antar huruf juga dikontrol dengan jeda LED menyala dan mati agar pesan dapat dipahami.  
- Anda dapat memodifikasi durasi pada fungsi `lowMorse()`, `longMorse()`, dan `intervalMorse()` untuk menyesuaikan kecepatan sinyal.

---

Program ini cocok untuk pembelajaran dasar Arduino dan kode Morse untuk aplikasi sederhana pengiriman pesan visual dengan LED.

