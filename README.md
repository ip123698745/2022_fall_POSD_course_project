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
- 
##
##
