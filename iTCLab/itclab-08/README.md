# iTCLab Kit Temperature Monitoring and On/Off Control via IoT

## Informasi Umum
Program ini dikembangkan oleh Assoc. Prof. Dr. Basuki Rahmat dan tim dari Universitas Pembangunan Nasional "Veteran" Jawa Timur sebagai bagian dari penelitian Intelligent Control, Robotics and Automation Systems Research Group. Firmware ini digunakan pada iTCLab Shield dengan board berbasis ESP32 untuk memonitor suhu dari dua sensor dan mengendalikan dua heater serta LED menggunakan sinyal PWM, dengan data dan kendali diteruskan melalui jaringan WiFi dan protokol MQTT.

## Fitur Utama
- Koneksi ke jaringan WiFi dan broker MQTT publik (`broker.emqx.io`)
- Pembacaan dua sensor suhu analog (T1 dan T2) pada pin A0 (GPIO34) dan A1 (GPIO35)
- Kontrol output PWM untuk dua heater (Q1 pada GPIO32, Q2 pada GPIO33)
- Kontrol brightness LED (GPIO26) sebagai indikator status
- Logika proteksi suhu dengan batas atas 58°C untuk mematikan otomatis heater
- Publikasi nilai suhu ke topik MQTT "Suhu1" dan "Suhu2"
- Penerimaan perintah via MQTT untuk mengaktifkan/mematikan heater Q1 dan Q2

## Spesifikasi Perangkat Keras dan PWM
- Pin Sensor Suhu:  
  - `pinT1 = 34`  
  - `pinT2 = 35`
- Pin Heater dan LED PWM:  
  - `pinQ1 = 32` (Heater 1)  
  - `pinQ2 = 33` (Heater 2)  
  - `pinLED = 26` (LED)
- PWM:  
  - Frekuensi: 5000 Hz  
  - Resolusi: 8 bit (0-255)  
  - Channel LED: 0  
  - Channel Q1: 1  
  - Channel Q2: 2

## Detail Program

### Koneksi WiFi dan MQTT
- Program menghubungkan board ESP32 ke jaringan WiFi yang telah dikonfigurasi (`ssid` dan `password`).
- Setelah tersambung ke WiFi, board menghubungkan klien MQTT ke broker `broker.emqx.io` di port 1883.
- Board berlangganan ke topik "heater1bas" dan "heater2bas" untuk menerima perintah kontrol heater.

### Fungsi Kontrol Heater dan LED
- `Q1on()` dan `Q1off()` untuk mengaktifkan dan mematikan heater Q1 dengan sinyal PWM.
- `Q2on()` dan `Q2off()` untuk heater Q2.
- `ledon()` dan `ledoff()` untuk menyalakan/mematikan LED sebagai indikator proteksi suhu.

### Pembacaan Suhu
- Fungsi `cektemp()` membaca nilai analog dari sensor suhu dan mengonversinya ke Celsius.
- Nilai suhu T1 dan T2 dibaca, dikonversi, lalu dikirim ke serial monitor dan diterbitkan ke topik MQTT masing-masing ("Suhu1" dan "Suhu2").

### Logika Pengendalian Otomatis
- Jika suhu sensor T1 atau T2 melebihi batas atas 58°C, heater terkait dimatikan dan LED indikator menyala sebagai peringatan.
- Jika suhu di bawah batas, heater akan menyala kembali dan LED dimatikan.

### Callback penerimaan MQTT
- Fungsi `receivedCallback()` menangani pesan yang masuk pada topik berlangganan:
  - Payload '1': Nyalakan Q1
  - Payload '2': Matikan Q1
  - Payload '3': Nyalakan Q2
  - Payload '4': Matikan Q2

## Cara Penggunaan
1. Hubungkan iTCLab Shield dengan ESP32 sesuai pin yang telah ditetapkan.
2. Sesuaikan `ssid` dan `password` WiFi dalam kode.
3. Upload kode ini via Arduino IDE ke board ESP32.
4. Monitor output serial untuk melihat status koneksi dan pembacaan suhu.
5. Gunakan client MQTT untuk mengirimkan perintah ke topik "heater1bas" dan "heater2bas" untuk mengendalikan heater.
6. Lihat nilai suhu yang dikirim ke broker MQTT pada topik "Suhu1" dan "Suhu2".

## Catatan Tambahan
- Program menggunakan pin PWM hardware ESP32 dengan kanal dan frekuensi yang sesuai untuk kontrol heater dan LED.
- Batas suhu proteksi bisa disesuaikan sesuai kebutuhan pada variabel `upper_temperature_limit`.
- Delay dan frekuensi loop sudah diatur agar pembacaan suhu dan pengiriman data berjalan lancar.

---
