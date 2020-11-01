#pragma once
#include <iostream>

enum class Direction { Left = 0, Right = 1, Up = 2, Down = 3 };

class GameModel {
public:
    static const int SIZE = 4;			        // ������ �������� ���� � �������
    static const int ARRAY_SIZE = SIZE * SIZE;	// ������ �������
    static const int FIELD_SIZE = 500;		    // ������ �������� ���� � ��������
    static const int CELL_SIZE = 120;		    // ������ ������ � ��������
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