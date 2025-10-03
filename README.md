<img width="742" height="945" alt="SesudahAdd2" src="https://github.com/user-attachments/assets/b93f0df2-47a2-4af7-bd53-19bd5054554a" /><img width="954" height="1002" alt="SesudahAdd1" src="https://github.com/user-attachments/assets/6a65d715-7dc2-403f-8965-b2129691a3a3" /># TP3DPBO2425C1
TP 3 Frizkia (Fakhri Rizkiana)

# Janji
Saya Fakhri Rizkiana Sya'ban Kusnendar dengan NIM 2405534 mengerjakan<br> 
TP 3 dalam mata kuliah Desain dan Pemrograman<br>
Berorientasi Objek untuk keberkahanNya maka saya tidak<br>
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.<br>

# Penjelasan Program
Program ini memiliki tema game RPG isekai dengan nama FrizIsekai, berikut adalah struktur rancangannya<br>
<img width="1234" height="1064" alt="Frizisekai" src="https://github.com/user-attachments/assets/c1c6212b-3f6c-405b-871b-710e6ce0d87e" />


Program ini memiliki beberapa Class dan ada beberapa Class yang memiliki relasi tertentu yang tertera sebagai berikut:<br>
<ol type = 1>
  <li>
    Quest => Quest yang bisa dilaksanakan oleh Player. Quest akan diberikan melalui FriendlyNPC <br>
    - name (str) => nama dari questnya<br>
    - desc (str) => deskripsi dari quest, seperti penjelasan quest, jumlah item yang dibutuhkan, dsb<br>
    Relasi: digunakan oleh Player, FriendlyNPC<br><br>
  </li>
  <li>
    Karakter => Mencakup semua karakter yang aada di game ini<br>
    - name (str) => nama karakter<br>
    - gender (str) => gender karakter<br>
    - race (str) => ras dari karakter tersebutbr>
    - affiliation (aggregation ke Factions (hanya bisa ada 1 faction)) => karakter ini dari faksi apa (bisa tanpa faksi atau unaffiliated)<br>
    Relasi: Aggregation -> Factions<br>
    Turunan: CanBattle, FriendlyNPC<br><br>
  </li>
  <li>
    Factions => Faksi atau guild<br>
    - name => nama faksi(str)<br>
    - desc => penjelasan dari faksi. misalnya faksi para assassin, faksi para pedagang, dsb(str)<br>
    Relasi: digunakan oleh Karakter<br><br>
  </li>
  <li>
    CanBattle (child dari Karakter) => karakter yang bisa ikut pertarungan<br>
    - maxActionPoint (int) => jumlah maksimal Action Point<br>
    - maxHealth (int) => jumlah maksimal Health<br>
    - maxMana (int) => jumlah maksimal Mana<br>
    - class (str) => kelas dari karakter, misalnya Knight, mage, tank, dsb<br>
    Turunan: Player, Enemies<br><br>
  </li>
  <li>
    Player (child dari CanBattle) => Karakter yang dimainkan oleh user<br>
    - level (int) => level dari player<br>
    - skillOwned (aggregation -> Skills) => skill yang dimiliki player<br>
    - magicOwned (aggregation -> Magics) => skill yang dimiliki player<br>
    - activeQuest (aggregation -> Quest) => skill yang dimiliki player<br>
    Relasi: Use Abilities<br><br>
  </li>
  <li>
    Enemies (child dari CanBattle) => karakter hostile<br>
    - is_elite (bool) => apakah karakter ini karakter elite?<br>
    - is_escapable (bool) => apakah player bisa lari dari karakter ini di dalam pertarungan<br><br>
  </li>
  <li>
    FriendlyNPC (child dari Karakter) => karakter yang bersifat friendly ke player<br>
  - is_marryable (bool) => bisa dinikahi atau tidak (eaaa nikah)<br>
  - birthday (str) => tanggal ulang tahun<br>
  - haveQuest (composition -> Quest) => apa karakter ini punya quest untuk diberikan (bisa kosong atau no quest)<br>
  Turunan: Companion, Merchant, Trainer<br><br>
  </li>
  <li>
    Companion (child dari FriendlyNPC dan CanBattle) => FriendlyNPC yang bisa ikut bertarung dengan player<br>
    - fee (int) => jumlah bayaran yang harus dibayarkan (bisa gratis)<br>
    - grade (F/E/D/C/B/A/S/SS) => peringkat dari companion, semakin tinggi semakin baik<br><br>
  </li>
  <li>
    Merchant (child dari FriendlyNPC) => NPC pedagang<br>
    - type (Alchemist / Blacksmith / General Goods) => tipe pedagang (berpengaruh pada barang dagangannya)<br>
    - openTime (str) (buka jam berapa hingga jam berapa. misalnya 07.00 - 19.00<br><br>
  </li>
  <li>
    Trainer (child dari FriendlyNPC) => NPC pelatih untuk membantu meningkatkan stats player<br>
    - fee (int) => bayaran yang harus dibayarkan<br>
    - trainingType (Health / Mana / ActionPoint) => tipe latihan<br><br>
  </li>
  <li>
    Abilities => kemampuan yang bisa digunakan oleh player<br>
    - name (str) => nama dari kemampuannya<br>
    - description (str) => deskripsi dari kemampuannya<br>
    - type (Damage / Heal) => kemampuan ini tipe serangan atau heal<br>
    - cooldown (int, seconds) => cooldown sebelum bisa digunakan lagi<br>
    Turunan: Skills, Magics<br><br>
  </li>
  <li>
    Skills (child dari Abilities)<br>
  - apCost (int) => jumlah AP yang berkurang setiap penggunaan skill<br><br>
  </li>
  <li>
    Magics (child dari Abilities)<br>
  - manaCost (str) => jumlah mana yang berkurang setiap penggunaan magic<br>
  - element (Fire / Water / Earth / Wind / Dark / Light) => tipe dari magic ini<br><br>
  </li>
</ol>

<h3>Penjelasan Relasi</h3>
<ul>
  <li>Karakter memiliki aggregation dengan Factions untuk menunjukan karakter ini berasal dari faction apa (hanya bisa ada 1 faction per karakter)</li>
  <li>CanBattle dan FriendlyNPC adalah child dari Karakter, hal ini digunakan untuk memisahkan antara karakter yang bisa bertarung dan tidak.</li>
  <li>Player, Enemies dan Companion adalah child dari CanBattle karena mereka adalah karakter yang bisa bertanrung</li>
  <li>Companion adalah child dari FriendlyNPC dan CanBattle karena ini adalah jenis karakter yang tidak memusuhi Player, tapi masih bisa bertarung mendampingi Player</li>
  <li>FriendlyNPC adalah child dari Karakter, karena karakter ini adalah karakter yang baik terhadap player (bahkan ada kemungkinan untuk dinikahi :v), Class ini memiliki 3 child yaitu: Companion, Merchant, Trainer</li>
  <li>Abilities memiliki child Skills dan Magics untuk memisahkan kemampuan yang menggunakan ActionPoint dan Magic</li>
  <li>Player memiliki aggregation ke Skills, Magics, dan Quest. Karena setiap Player bisa mempunyai semua hal tersebut (atau bahkan tidak sama sekali) dan jika player ini menghilang sekalipun, semua Class tersebut tidak akan hilang dan masih bisa digunakan oleh player lain.</li>
  <li>FriendlyNPC punya composition ke Quest karena setiap NPC bisa memberikan quest (atau tidak) kepada player. dan jika karakter ini hilang, maka questnya akan ikut hilang</li>
</ul>

Note: Semua Class mempunyai metode Getter & Setter<br>

# Dokumentasi
Kondisi sebelum di add<br>
<img width="823" height="179" alt="sebelumAdd" src="https://github.com/user-attachments/assets/5d49ce5e-ac0a-40e8-bc22-1a0499d50a26" /><br><br>

Sesudah di add<br>
<img width="954" height="1002" alt="SesudahAdd1" src="https://github.com/user-attachments/assets/d87e998d-bc02-48dc-ab5c-c5f9375b4f67" />
![Uploading Sesu<img width="869" height="937" alt="SesudahAdd3" src="https://github.com/user-attachments/assets/098e9e56-49bc-4a3a-b97e-0d5a129055c6" />
dahAdd2.png…]()
<img width="636" height="942" alt="SesudahAdd4" src="https://github.com/user-attachments/assets/6ba6d32b-248d-47c8-814b-5c847fc2537d" />
<img width="632" height="954" alt="SesudahAdd5" src="https://github.com/user-attachments/assets/fff92991-b21e-491b-b344-aec160db9d12" />

