// Utara
#define MERAH_U   2
#define KUNING_U  3
#define HIJAU_U   4

// Timur
#define MERAH_T   5
#define KUNING_T  6
#define HIJAU_T   7

// Selatan
#define MERAH_S   8
#define KUNING_S  9
#define HIJAU_S   10

// Barat
#define MERAH_B   11
#define KUNING_B  12
#define HIJAU_B   13

void setup() {
  int pins[] = {2,3,4,5,6,7,8,9,10,11,12,13};
  for (int i = 0; i < 12; i++) {
    pinMode(pins[i], OUTPUT);
  }
  semuaMerah(); // Default
}

void loop() {
  aktifkanSimpang(MERAH_U, KUNING_U, HIJAU_U); // Utara
  aktifkanSimpang(MERAH_T, KUNING_T, HIJAU_T); // Timur
  aktifkanSimpang(MERAH_S, KUNING_S, HIJAU_S); // Selatan
  aktifkanSimpang(MERAH_B, KUNING_B, HIJAU_B); // Barat
}

void semuaMerah() {
  for (int p = 2; p <= 13; p++) digitalWrite(p, LOW);

  digitalWrite(MERAH_U, HIGH);
  digitalWrite(MERAH_T, HIGH);
  digitalWrite(MERAH_S, HIGH);
  digitalWrite(MERAH_B, HIGH);
}

void aktifkanSimpang(int pinMerah, int pinKuning, int pinHijau) {
  semuaMerah();

  digitalWrite(pinMerah, LOW);
  digitalWrite(pinHijau, HIGH);
  delay(5000); // Hijau 5 detik

  digitalWrite(pinHijau, LOW);
  for (int i = 0; i < 3; i++) {
    digitalWrite(pinKuning, HIGH);
    delay(300);
    digitalWrite(pinKuning, LOW);
    delay(300);
  }

  digitalWrite(pinKuning, HIGH);
  delay(2000); // Kuning 2 detik
  digitalWrite(pinKuning, LOW);

  digitalWrite(pinMerah, HIGH);
}