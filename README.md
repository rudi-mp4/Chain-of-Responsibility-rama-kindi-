# Balatro Terminal Replica - Technical Design Document (TDD)

## 1. Overview
Proyek ini adalah replika berbasis terminal dari game **Balatro**, sebuah sistem evaluasi dan scoring poker-hand yang terinspirasi oleh game roguelike berbasis poker. Sistem ini dibangun menggunakan C++ dengan pendekatan modular dan pola desain (design patterns) untuk memastikan fleksibilitas dan kemudahan pengembangan.

Tujuan utama proyek:
*   Mengevaluasi kombinasi kartu poker.
*   Menghitung skor berdasarkan kombinasi dan level tangan.
*   Menerapkan efek Joker untuk memodifikasi skor.
*   Mengelola alur permainan melalui sistem Blind dan Ante.
*   Menyediakan mekanisme Skip Reward menggunakan Command Pattern.

## 2. Arsitektur High-Level
Sistem dibagi menjadi beberapa komponen utama dengan tanggung jawab yang spesifik:

| Sistem | Tanggung Jawab | Kelas Utama |
| :--- | :--- | :--- |
| **Game Manager** | Mengatur alur game dan inisialisasi awal. | `GameManager` |
| **Game Session** | Menyimpan state runtime (skor, ante, deck, pending commands). | `GameSession` |
| **Card System** | Merepresentasikan kartu dan manajemen deck/tangan. | `Card`, `Hand`, `HandGenerator` |
| **Poker Evaluation** | Mendeteksi tipe kombinasi kartu poker (Chain of Responsibility). | `IPokerHandChecker`, `PokerHandChecker` |
| **Scoring System** | Menghitung skor dasar berdasarkan tipe tangan dan level. | `HandResolver`, `ScoringRule`, `HandScoreTable` |
| **Joker System** | Menerapkan modifikasi skor melalui efek Joker. | `JokerManager`, `ScoreContext`, `Joker` |
| **Blind System** | Mengatur progres permainan dan target skor (State Pattern). | `BlindState`, `SmallBlindState`, `BigBlindState`, `BossBlindState` |
| **Reward System** | Mengelola reward yang tertunda atau instan (Command Pattern). | `RewardCommand`, `BonusHandCommand`, `FreePlayingCardCommand` |
| **Shop System** | Mengelola pembelian Joker dan item lainnya. | `Shop`, `ShopInventory`, `ShopItem` |

## 3. Runtime Flow
Alur eksekusi permainan mengikuti urutan berikut:

`main()` → `GameManager::setupJokers()` → Inisialisasi `GameSession` → **Loop Permainan**:
1.  **Session Setup**: Inisialisasi Blind State saat ini.
2.  **Gameplay Loop**:
    *   Tampilkan state saat ini (Ante, Score, Hands).
    *   Pemain memilih aksi: **PLAY**, **DISCARD**, atau **SKIP**.
    *   Jika **PLAY**: Evaluasi kartu → Hitung skor dasar → Terapkan efek Joker → Update total skor.
    *   Jika **SKIP**: Buat `RewardCommand` → Simpan ke `PendingCommands` → Transisi ke Blind berikutnya.
3.  **Shop Phase**: Setelah mengalahkan Blind, pemain masuk ke Shop untuk membeli item atau Joker baru.
4.  **Blind Transition**: Cek target skor → Jika tercapai, pindah ke Blind berikutnya melalui `BlindState::nextState()`.

## 4. Sistem Detail

### A. Sistem Evaluasi Poker Hand (Chain of Responsibility)
Sistem ini menentukan jenis kombinasi kartu yang dibuat oleh pemain. Menggunakan pola *Chain of Responsibility* di mana setiap *checker* bertanggung jawab atas satu jenis kombinasi.

**Prioritas Evaluasi (Kuat ke Lemah):**
1.  `FlushFive`
2.  `FlushHouse`
3.  `FiveOfAKind`
4.  `RoyalFlush`
5.  `StraightFlush`
6.  `FourOfAKind`
7.  `FullHouse`
8.  `Flush`
9.  `Straight`
10. `ThreeOfAKind`
11. `TwoPair`
12. `OnePair`
13. `HighCard` (Fallback)

Setiap *checker* mengimplementasikan `IPokerHandChecker` dengan fungsi `checkPokerHand()`.

### B. Sistem Scoring
`HandResolver` mengombinasikan hasil evaluasi tangan dengan aturan scoring.
*   **Formula**: `Total Skor = (Base Chips + Bonus Chips) × (Base Mult + Bonus Mult)`
*   `HandScoreTable` menyimpan nilai dasar (Chips & Mult) untuk setiap jenis kombinasi.

### C. Sistem Joker
Joker berfungsi sebagai modifikasi skor dinamis.
*   `JokerManager` menyimpan daftar Joker yang dimiliki pemain.
*   `ScoreContext` membawa data skor mutabel yang akan dimodifikasi oleh Joker saat `onScoreCalculated()` dipanggil.
*   **Contoh**: `PairJoker` (+4 Mult jika tangan adalah Pair), `FlatChipJoker` (+20 Chips setiap tangan).

### D. Blind State System (State Pattern)
Digunakan untuk menangani progresi Blind tanpa banyak percabangan `if-else`.
*   **States**: `SmallBlindState` → `BigBlindState` → `BossBlindState`.
*   Setiap State menentukan target skor, reward uang, dan tipe reward jika di-skip.
*   `BossBlindState` memiliki behavior khusus untuk menaikkan Ante dan mengulang siklus.

### E. Skip Reward System (Command Pattern)
Menangani reward yang didapat saat pemain memilih untuk melewati (skip) sebuah Blind.
*   Setiap `BlindState` menghasilkan `RewardCommand` yang spesifik.
*   Command dapat dieksekusi segera atau ditunda (*deferred*) berdasarkan `RewardTiming` (contoh: `NextBlind`, `NextShop`, `NextAnte`).

### F. Shop System
Sistem Shop memungkinkan pemain untuk memperkuat deck atau Joker mereka.
*   `ShopInventory` menyimpan daftar item yang tersedia secara acak.
*   `ShopItem` merepresentasikan entitas yang dapat dibeli (seperti Joker).
*   Pemain menggunakan uang yang didapat dari reward Blind untuk bertransaksi.

## 5. Panduan Ekstensi

### Menambah Joker Baru
1.  Buat kelas baru yang mewarisi `Joker`.
2.  Implementasikan `getName()`, `getDescription()`, dan `onScoreCalculated()`.
3.  Daftarkan Joker tersebut di `GameManager::setupJokers()`.

### Menambah Tipe Tangan Poker Baru
1.  Tambah nilai baru di enum `HandRank`.
2.  Buat kelas *checker* baru yang mewarisi `IPokerHandChecker`.
3.  Daftarkan *checker* tersebut di `PokerHandChecker` sesuai urutan prioritas.
4.  Tambahkan data skor dasar di `HandScoreTable`.

---
*Dokumentasi ini disesuaikan berdasarkan arsitektur replika Balatro Terminal.*
