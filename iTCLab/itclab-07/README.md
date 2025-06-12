# Dokumentasi Firmware iTCLab Shield Versi 1.04

## Deskripsi  
Firmware ini mengontrol perangkat iTCLab Shield, termasuk pengaturan output heater (Q1 dan Q2), pembacaan sensor suhu (T1 dan T2), serta kontrol level LED menggunakan PWM pada board berbasis Arduino. Firmware memungkinkan pengiriman perintah serial untuk mengatur daya heater dan LED secara presisi serta monitoring suhu secara real-time.

## Versi Firmware  
- Versi saat ini: **1.04**

## Spesifikasi Pin  
- **pinT1 (Pin 34)**: Input sensor suhu T1  
- **pinT2 (Pin 35)**: Input sensor suhu T2  
- **pinQ1 (Pin 32)**: Output heater Q1 (PWM)  
- **pinQ2 (Pin 33)**: Output heater Q2 (PWM)  
- **pinLED (Pin 26)**: Output LED (PWM)  

## Properti PWM  
- Frekuensi PWM: 5000 Hz  
- Channel PWM LED: 0  
- Channel PWM Q1: 1  
- Channel PWM Q2: 2  
- Resolusi PWM: 8 bit (nilai 0-255)  

## Variabel Global  
- Buffer untuk menerima data serial  
- Variabel untuk menyimpan perintah dan nilai yang diterima  
- Batas suhu maksimum: 59 °C  
- Jumlah sampel pembacaan suhu: 10 sampel  

## Penjelasan Fungsi Utama  
### 1. `parseSerial()`  
- Membaca data yang masuk dari serial hingga karakter newline (`\n`)  
- Memisahkan perintah (command) dari nilai data (parameter)  
- Mengubah perintah menjadi huruf kapital dan nilai menjadi angka desimal

### 2. `dispatchCommand()`  
- Mengeksekusi perintah sesuai command yang diterima:  
  - `Q1` dan `Q2`: Mengatur daya heater Q1 dan Q2 (nilai antara 0-25) dalam PWM dengan konversi ke rentang 0-255  
  - `T1` dan `T2`: Membaca sensor suhu dengan multiple sampling dan mengirimkan suhu aktual ke serial  
  - `LED`: Mengatur intensitas LED (0-100%) di channel PWM LED  
  - `V` atau `VER`: Menampilkan versi firmware melalui serial  
  - `X`: Mematikan output Q1 dan Q2 (stop)  

### 3. `checkTemp()`  
- Memantau pembacaan suhu pada sensor T1 dan T2 secara berkala  
- Jika suhu melampaui batas atas (59 °C), maka heater Q1 dan Q2 dimatikan secara otomatis sebagai langkah proteksi  

### 4. `setup()`  
- Inisialisasi komunikasi serial dengan baud rate 115200  
- Setup channel PWM untuk pin Q1, Q2, dan LED dengan frekuensi dan resolusi yang telah ditentukan  
- Inisialisasi output PWM dengan nilai 0 (OFF)  

### 5. `loop()`  
- Fungsi utama yang berjalan berulang  
- Memanggil fungsi parsing serial, eksekusi perintah, dan pengecekan suhu berulang kali  

## Cara Penggunaan  
1. Hubungkan iTCLab Shield ke board Arduino sesuai pin yang ditentukan.  
2. Upload firmware ini menggunakan Arduino IDE.  
3. Gunakan terminal serial (baud 115200) untuk mengirimkan perintah kontrol seperti:  
   - `Q1 10` (atur heater Q1 ke level 10)  
   - `Q2 15` (atur heater Q2 ke level 15)  
   - `LED 50` (atur LED ke 50% brightness)  
   - `T1` atau `T2` untuk membaca suhu sensor terkait  
   - `X` untuk mematikan heater  
   - `V` atau `VER` untuk menampilkan versi firmware  

## Catatan Penting  
- Firmware menggunakan fitur `ledc` PWM khusus untuk platform yang mendukung hardware PWM seperti ESP32.  
- Pembacaan suhu menggunakan multiple sampling untuk meningkatkan akurasi.  
- Proteksi suhu otomatis efektif untuk mencegah kerusakan akibat suhu terlalu tinggi.  

---
