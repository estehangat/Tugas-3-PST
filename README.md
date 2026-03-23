# Traffic Light 4 Arah - Arduino Uno

Project ini merupakan simulasi sistem **lampu lalu lintas (traffic light) 4 arah** menggunakan **Arduino Uno** dan komponen LED. Sistem bekerja secara otomatis dan berulang, mengatur pergantian lampu hijau searah jarum jam: **Utara → Timur → Selatan → Barat**, dengan kondisi default semua lampu merah sebelum satu sisi aktif.

---

## Komponen yang Digunakan

- 1x Arduino Uno R3 - mikrokontroler utama yang menggunakan pin digital 2–13
- 1x Kabel USB Type-B - untuk menghubungkan Arduino ke komputer / sumber daya
- 4x LED Merah - satu untuk setiap arah (Utara, Timur, Selatan, Barat)
- 4x LED Kuning - satu untuk setiap arah (Utara, Timur, Selatan, Barat)
- 4x LED Hijau - satu untuk setiap arah (Utara, Timur, Selatan, Barat)
- 12x Resistor 220Ω - satu per LED, dipasang langsung seri antara LED dan pin Arduino untuk membatasi arus agar LED tidak rusak
- ±25x Kabel jumper - untuk menghubungkan setiap komponen ke pin Arduino
- Arduino IDE - software untuk menulis dan mengupload kode ke Arduino
- Tinkercad - platform online untuk membuat dan menguji simulasi rangkaian secara virtual

---

## Skema Pin Arduino

Setiap arah menggunakan 3 pin digital untuk lampu merah, kuning, dan hijau.

| Arah    | Pin Merah | Pin Kuning | Pin Hijau |
|---------|-----------|------------|-----------|
| Utara   | 2         | 3          | 4         |
| Timur   | 5         | 6          | 7         |
| Selatan | 8         | 9          | 10        |
| Barat   | 11        | 12         | 13        |

---

## Skema Rangkaian

Setiap LED dihubungkan dengan pola berikut:

```
Pin Digital Arduino → Resistor 220Ω → Anoda LED (+) → Katoda LED (−) → GND Arduino
```

**Penjelasan:**
- **Resistor 220Ω** dipasang seri sebelum LED berfungsi sebagai pembatas arus agar LED tidak rusak akibat arus berlebih.
- **Anoda (kaki panjang)** LED dihubungkan ke resistor yang menuju pin Arduino.
- **Katoda (kaki pendek)** LED dihubungkan ke GND Arduino.
- Semua katoda LED dapat dihubungkan ke satu jalur GND bersama.

---

## Aturan Waktu Sistem

| Kondisi Lampu | Durasi |
|---------------|--------|
| Hijau menyala | 5 detik |
| Kuning kedip | 3x kedip (masing-masing 0,3 detik ON / 0,3 detik OFF) |
| Kuning menyala penuh | 2 detik |
| Merah | Aktif saat simpang tidak giliran |

---

## Alur Kerja Sistem

```
[START]
   ↓
Semua Merah (Default)
   ↓
┌─────────────────────────────┐
│  Utara: Hijau 5s            │
│         Kuning kedip 3x     │
│         Kuning penuh 2s     │
│         Kembali Merah       │
├─────────────────────────────┤
│  Timur: (sama seperti atas) │
├─────────────────────────────┤
│  Selatan: (sama)            │
├─────────────────────────────┤
│  Barat: (sama)              │
└─────────────────────────────┘
   ↓
[ULANGI dari awal ∞]
```

---

## Simulasi Tinkercad

Link simulasi: **[https://www.tinkercad.com/things/cWEh6bXuNaZ/editel?sharecode=NqfmEAbEjuPbohAAS_vyRQFNrjc1hCUeWsBq5T1uOr0]**
