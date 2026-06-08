### 組別: 第12組
### 系級班級：資工1A
### 成員資訊:
組長:林星丞
組員:許子謙、王通元
# 小專題題目:
撲克牌二十一點(Black Jack)
# 系統功能說明:
本遊戲實作了標準的 Blackjack 核心規則與以下功能：

* **完全 OOP 架構**：清晰劃分 `Card`, `Deck`, `Player`,`Game` 類別，具備高可讀性與擴充性。
* **動態洗牌系統**：結合時間種子 (`chrono`) 與 `std::shuffle` 演算法，確保每一局牌組排序的絕對隨機與公平。
* **智慧計分演算法 (Ace 判定)**：系統能自動處理 "A" 的雙重場景（1 點或 11 點）。當手牌總分超過 21 點且持 A 時，自動將 A 降為 1 點計算。
* **莊家決策 AI**：嚴格執行賭場標準規則，莊家手牌未滿 17 點必須強制加牌，滿 17 點（含）以上自動停牌。
* **互動式遊戲流程**：文字介面即時顯示雙方手牌與點數，提供 Hit (加牌) / Stand (停牌) 決策。
* **無縫接關機制**：單局結算後，可選擇立刻重開新局或優雅結束程式。
# 程式介紹 :
本專案主要包含以下核心檔案：

* **`main.cpp`**：程式入口點，負責系統環境初始化與啟動遊戲中樞。
* **`Card.h`**：定義單張撲克牌物件，封裝花色、點數與 const 數值。
* **`Deck.h`**：管理 52 張牌組，實作牌組生成、洗牌與發牌邏輯。
* **`Player.h`**：基礎玩家類別，管理手牌、智慧計分與 `virtual` 顯示方法。
* **`Game.h`**：遊戲中樞 (Controller)，掌控整個遊戲生命週期與雙方回合邏輯。

# 程式使用方式:
直接下載專案壓縮檔並解壓縮
# 程式安裝方式:
本專案僅依賴標準 C++ 函式庫，不需額外安裝第三方庫。請確保你的電腦已安裝 C++ 編譯器

# 運行畫面截圖:
<img width="254" height="152" alt="image (3)" src="https://github.com/user-attachments/assets/8bc782b2-dce5-4217-93f4-c50b767d4d69" />
<img width="302" height="131" alt="image (5)" src="https://github.com/user-attachments/assets/a51ced1c-57ea-4b64-b43c-dc7beb81d8e0" />
<img width="251" height="93" alt="image (2)" src="https://github.com/user-attachments/assets/1ac28dc9-ff5b-42fb-8183-a582f943b0f9" />
<img width="250" height="100" alt="image (4)" src="https://github.com/user-attachments/assets/0dc82117-1742-4329-8f0a-6b8520212169" />


# UML 圖片:
* <img width="1062" height="1056" alt="image (1)" src="https://github.com/user-attachments/assets/80d74340-58be-468c-90d2-c1b3ca6211e5" />

# 分工資訊:
*組長: 林星丞  程式撰寫、查找資料、簡報製作、上台報告   
*組員: 許子謙  撰寫程式、查找資料、上台報告   
*組員: 王通元  撰寫程式、查找資料、上台報告  

