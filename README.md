# Task 1 - Arsytektur Core Loop dan Prinsip SOLID

**Konsep Game:** Balatro Core Loop Architecture Poker Roguelike.

### Step 2 - Identifikasi Invarian (Invariant Identification)

Struktur Invariant adalah fondasi sistem yang mengatur urutan jalannya permainan. Urutan ini bersifat tetap dan tidak boleh berubah agar logika program tetap konsisten.

**Invariant Structure:**
- `RunSession.h` / `.cpp`
  - Bertindak sebagai orkestrator utama yang memanggil fase: Input -> Scoring -> Reward -> Shop.
- `TurnInput.h`
  - Struktur data standar yang menghubungkan hasil dari Generator menuju Scoring Rule.

Jika urutan di dalam `RunSession` diubah (misalnya `ComputeReward` dijalankan sebelum `ComputeBaseScore`), maka pemain bisa mendapatkan hadiah tanpa ada perhitungan skor yang valid.

---

### Step 3 - Elemen Mutable

Elements Mutable adalah komponen yang dapat diganti atau dimodifikasi perilakunya tanpa mengubah struktur utama permainan. Hal ini dicapai melalui penggunaan *Interface* dan *Dependency Injection*.

**Mutable Elements:**
- `IInputGenerator`
  - Dapat berupa `StandardInputGenerator` (pintar) atau `RandomInputGenerator` (acak).
- `IChooseHand`
  - Strategi pemilihan kartu, seperti `OptimalHandChooser` atau `RandomHandChooser`.
- `IScoringRule`
  - Aturan perhitungan skor dasar, seperti `StandardScoringRule`.
- `IRewardRule`
  - Aturan pemberian uang, seperti `StandardRewardRule` atau `ModifiedRewardRule`.
- `ShopSystem`
  - Logika transaksi dan jenis item yang dijual di toko.

---

## Refleksi Design Pattern

**1. Inti Sistem yang Tetap (Invariant Structure)**
 Inti dari sistem ini adalah kelas `RunSession`. Ia berfungsi sebagai pengatur utama yang menentukan alur permainan secara kaku. Urutan tahapan permainan, mulai dari menghasilkan masukan, menghitung skor, menentukan hasil menang/kalah, memberikan imbalan, hingga interaksi dengan sistem toko, semuanya diatur oleh `RunSession` dan tidak bisa dirubah.
 
**2. Komponen yang Fleksibel (Mutable Parts)** Fleksibilitas sistem terletak pada implementasi konkret dari berbagai antarmuka. Kelas-kelas yang mengimplementasikan `IInputGenerator`, `IScoringRule`, `IRewardRule`, `ShopSystem`, dan `IChooseHand` dapat dengan mudah diganti, dimodifikasi, atau bahkan ditambahkan tanpa mengganggu struktur inti `RunSession`. Contohnya, kita bisa saja membuat generator masukan acak (`RandomInputGenerator`) atau aturan imbalan yang dimodifikasi (`ModifiedRewardRule`) tanpa khawatir merusak fondasi program. 

**3. Pengaruh Penggantian Generator Masukan terhadap Alur Utama** Mengganti implementasi `InputGenerator` tidak akan memengaruhi `RunSession` sama sekali. Ini berkat penerapan pola **Dependency Injection**. `RunSession` hanya berinteraksi melalui kontrak antarmuka `IInputGenerator`, bukan pada kelas spesifiknya. Selama kelas baru tersebut mematuhi kontrak antarmuka dan menghasilkan data masukan yang sesuai, `RunSession` akan menerimanya tanpa masalah. Ini adalah contoh nyata dari penerapan **Open-Closed Principle (OCP)**. 

**4. Konsekuensi Jika Logika Skor Ditempatkan di `RunSession`** Menempatkan logika perhitungan skor langsung di dalam `RunSession` akan melanggar **Single Responsibility Principle (SRP)**. `RunSession` akan memiliki dua tanggung jawab utama: mengelola alur permainan dan melakukan perhitungan skor yang spesifik. Akibatnya, setiap kali ada perubahan aturan skor atau penambahan fitur terkait kartu, kelas `RunSession` yang krusial ini harus diubah. Hal ini sangat berisiko menimbulkan kesalahan pada alur permainan, membuat kode menjadi kaku, dan menghambat pengembangan seiring bertambahnya kompleksitas program.