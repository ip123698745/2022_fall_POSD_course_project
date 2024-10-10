# 2022_fall_POSD_course_project
- 此課程專案使用多個 Design Pattern 來實現一個簡單的圖形繪製工具
- 使用 C++ 進行實作並搭配單元測試及 valgrid 來驗證程式的正確性及消除記憶體洩漏(Memory Leak)的問題，並透過每次作業疊代的過程套用多個 Design Pattern 來完成專案的實作。
## Composite pattern
- 圖形繪製中有個名為 CompoundShape 的複合圖形，此複合圖形即是使用 Composite pattern 來完成複合圖形的實作，使圖形可以以樹狀結構完成複合圖形的建構。
## Iterator pattern
- 在此專案中也實作不同遍歷的方式來遍歷複合圖形內部的所有圖形，並使用 DFS 和 BFS 等演算法進行遍歷，這個設計主要是想了解一個複合圖形是由那些圖形構成的。
## Visitor pattern
- 此設計主要是針對圖形之間有無碰撞而使用的設計模式，因為碰撞的判定不應該由圖形這個物件所擁有，所以使用 visitor pattern 的方式來完成對碰撞的實作，並使用簡單的 2D 碰撞偵測方式 Axis-aligned minimum bounding box (AABB)。
## Abstract Factory pattern
- 針對複合圖形想了解該圖形由那些基礎圖形或較小的複合圖形構成，設計一個 IteratorFactory 用於生產不同遍歷方式的工廠類別，透過該類別可以完成不同遍歷方式(例如: BFS、DFS、List)物件的製造。
## Parser, Scanner, and Builder
- Scanner 會讀取文件並將文件內部重要的文字提取出來，再透過 Parser 將對應名稱的物件及其所需的參數提供給 Builder，最後透過 Builder 將對應的物件生成出來。
## Singleton
- 這一部分的設計是在後續才添加上去的，目的是使 IteratorFactory 生成的各種遍歷方式的 Iterator 能夠被視作是唯一用於遍歷的物件存在，因為用於遍歷的物件也不需要有第二個相同用於遍歷的 Iterator 物件存在，僅僅只需一個就夠。
## Adapter
- 由於本專案使用到 SDL library 用於圖形繪製，我們需要在不修改現有程式碼的情況下，透過 SDLAdapter (這裡是 Object Adapter) 實作我們定義用於繪製圖形的類別 Canvas 並將 SDLRender 作為 SDLAdapter 的成員變數，完成對 Canvas 介面的實作同時又能兼容第三方圖形繪製工具的 API。
## Command
- 本專案也透過此設計模式完成對圖形的一些基本操作，例如: 拖放、移動、回溯...等命令。
