# Dokumentasi Proyek Kontrol Motor DC dengan Arduino

## Deskripsi Singkat  
Program ini ditujukan untuk mengendalikan sebuah motor DC menggunakan mikrokontroler Arduino. Motor dikontrol untuk dapat berputar maju, berhenti, dan mundur dengan kecepatan yang dapat diatur menggunakan PWM (Pulse Width Modulation).

## Konfigurasi Pin  
- **motor1Pin1** (Pin 27): Pin kontrol arah motor (input 1)  
- **motor1Pin2** (Pin 26): Pin kontrol arah motor (input 2)  
- **enable1Pin** (Pin 12): Pin untuk mengaktifkan PWM pada motor  

## Properti PWM  
- Frekuensi : 30 kHz  
- Channel PWM : 0  
- Resolusi PWM : 8 bit (nilai 0-255)  
- Duty cycle awal : 200  

## Penjelasan Program  
1. Pada fungsi `setup()`:  
   - Pin motor diset sebagai output.  
   - Channel PWM diinisialisasi dengan frekuensi dan resolusi yang telah ditentukan.  
   - Pin enable1Pin dihubungkan ke channel PWM.  
   - Serial monitor dibuka pada baud rate 115200 untuk debugging dan monitoring.

2. Pada fungsi `loop()`:  
   - Motor bergerak maju dengan kecepatan maksimal selama 2 detik (arah motor dikendalikan dengan mengubah logika pin motor1Pin1 dan motor1Pin2).  
   - Motor berhenti selama 1 detik.  
   - Motor bergerak mundur selama 2 detik.  
   - Motor berhenti selama 1 detik.  
   - Motor bergerak maju lagi dengan kecepatan meningkat secara bertahap dari duty cycle 200 hingga 255, dengan kenaikan step 5 setiap 0.5 detik.  
   - Setelah mencapai nilai maksimal, duty cycle di-reset ke 200 dan siklus loop berulang.

## Cara Menggunakan  
1. Sambungkan motor DC ke pin-pin yang telah dikonfigurasi pada papan Arduino.  
2. Upload program ke Arduino menggunakan Arduino IDE.  
3. Amati pergerakan motor dan output pada Serial Monitor.  

## Catatan  
- Program ini menggunakan fitur `ledc` yang khusus pada board Arduino yang mendukung PWM hardware seperti ESP32.  
- Fungsi `ledcWrite()` digunakan untuk mengatur duty cycle PWM pada pin enable yang mengontrol power motor.

---
