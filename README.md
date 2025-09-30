# TP3DPBO2425C1
TP 3 Frizkia (Fakhri Rizkiana)

# Janji
Saya Fakhri Rizkiana Sya'ban Kusnendar dengan NIM 2405534 mengerjakan<br> 
TP 3 dalam mata kuliah Desain dan Pemrograman<br>
Berorientasi Objek untuk keberkahanNya maka saya tidak<br>
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.<br>

# Penjelasan Program
Program ini memiliki tema game RPG isekai dengan nama FrizIsekai, berikut adalah struktur rancangannya<br>
<img width="1234" height="1064" alt="Frizisekai" src="https://github.com/user-attachments/assets/94cf0ef5-2203-4969-9252-54032f6f17d0" />

Program ini memiliki beberapa Class dan ada beberapa Class yang memiliki relasi tertentu yang tertera sebagai berikut:<br>

1. Quest <br>
- name (str)<br>
- desc (str)<br>
Relasi: digunakan oleh Player, FriendlyNPC<br>


2. Karakter
- name (str)<br>
- gender (str)<br>
- race (str)<br>
- affiliation (aggregation ke Factions (hanya bisa ada 1 faction))<br>
Relasi: Aggregation -> Factions<br>
Turunan: CanBattle, FriendlyNPC<br>


3. Factions<br>
- name (str)<br>
- desc (str)<br>
Relasi: digunakan oleh Karakter<br>


4. CanBattle (child dari Karakter)<br>
- maxActionPoint (int)<br>
- maxHealth (int)<br>
- maxMana (int)<br>
- class (str)<br>
Turunan: Player, Enemies<br>


5. Player (child dari CanBattle)
- level (int)<br>
- class (str)<br>
- skillOwned (aggregation -> Skills)<br>
- magicOwned (aggregation -> Magics)<br>
- activeQuest (aggregation -> Quest)<br>
Relasi: Use Abilities<br>


6. Enemies (child dari CanBattle)<br>
- is_elite (bool)<br>
- is_escapable (bool)<br>


7. FriendlyNPC (child dari Karakter)<br>
- is_marryable (bool)<br>
- birthday (str)<br>
- haveQuest (composition -> Quest)<br>
Turunan: Companion, Merchant, Trainer<br>


8. Companion (child dari FriendlyNPC dan CanBattle)<br>
- fee (int)<br>
- grade (F/E/D/C/B/A/S/SS)<br>


9. Merchant (child dari FriendlyNPC)<br>
- type (Alchemist / Blacksmith / General Goods)<br>
- openTime (str)<br>


10. Trainer (child dari FriendlyNPC)<br>
- fee (int)<br>
- trainingType (Health / Mana / ActionPoint)<br>


11. Abilities<br>
- name (str)<br>
- description (str)<br>
- type (Damage / Heal)<br>
- cooldown (int, seconds)<br>
Turunan: Skills, Magics<br>


12. Skills (child dari Abilities)<br>
- apCost (int)<br>


13. Magics (child dari Abilities)<br>
- manaCost (str)<br>
- element (Fire / Water / Earth / Wind / Dark / Light)<br>


<h3>Penjelasan Relasi</h3><br>
- Karakter memiliki aggregation dengan Factions untuk menunjukan karakter ini berasal dari faction apa (hanya bisa ada 1 faction per karakter)<br>
- CanBattle dan FriendlyNPC adalah child dari Karakter, hal ini digunakan untuk memisahkan antara karakter yang bisa bertarung dan tidak.<br>
- Player, Enemies dan Companion adalah child dari CanBattle karena mereka adalah karakter yang bisa bertanrung<br>
- Companion adalah child dari FriendlyNPC dan CanBattle karena ini adalah jenis karakter yang tidak memusuhi Player, tapi masih bisa bertarung mendampingi Player<br>
- FriendlyNPC adalah child dari Karakter, karena karakter ini adalah karakter yang baik terhadap player (bahkan ada kemungkinan untuk dinikahi :v), Class ini memiliki 3 child yaitu: Companion, Merchant, Trainer<br>
- Abilities memiliki child Skills dan Magics untuk memisahkan kemampuan yang menggunakan ActionPoint dan Magic<br>
- Player memiliki aggregation ke Skills, Magics, dan Quest. Karena setiap Player bisa mempunyai semua hal tersebut (atau bahkan tidak sama sekali) dan jika player ini menghilang sekalipun, semua Class tersebut tidak akan hilang dan masih bisa digunakan oleh player lain.<br>
- FriendlyNPC punya composition ke Quest karena setiap NPC bisa memberikan quest (atau tidak) kepada player. dan jika karakter ini hilang, maka questnya akan ikut hilang<br>

Note: Semua Class mempunyai metode Getter & Setter<br>


