#pragma once
#include <iostream>

enum class Direction { Left = 0, Right = 1, Up = 2, Down = 3 };

class GameModel {
public:
    static const int SIZE = 4;			        // Размер игрового поля в плашках
    static const int ARRAY_SIZE = SIZE * SIZE;	// Размер массива
    static const int FIELD_SIZE = 500;		    // Размер игрового поля в пикселях
    static const int CELL_SIZE = 120;		    // Размер плашки в пикселях
protected:
    int m_Elements[ARRAY_SIZE];
    int m_EmptyIndex;
    bool m_Solved;
public:
    GameModel();
    void Init();
    bool Check();
    void Move(Direction direction);
    bool IsSolved() const { return m_Solved; }
    int* Elements() { return m_Elements; }
    ~GameModel() {}
};