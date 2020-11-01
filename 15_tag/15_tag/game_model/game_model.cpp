#include "game_model.h"
#include <cstddef>

GameModel::GameModel() {
    Init();
}

void GameModel::Init() {
    //��������� ������ ������
    for (int i = 0; i < ARRAY_SIZE; ++i)
        m_Elements[i] = i + 1;
    //������ ������ ������ � ������ ������ �������
    m_EmptyIndex = ARRAY_SIZE - 1;
    m_Elements[m_EmptyIndex] = 0; //������ ������ ����� �������� 0
    m_Solved = true;
}                             

bool GameModel::Check() {
    //�������� ����������� �����������
    for (std::size_t i = 0; i < ARRAY_SIZE; ++i) {
        if (m_Elements[i] > 0 && m_Elements[i] != i + 1)
            return false;
    }
    return true;
}

void GameModel::Move(Direction direction) {
    //��������� ������ � ������� ������ ������
    int col = m_EmptyIndex % SIZE;
    int row = m_EmptyIndex / SIZE;

    //�������� �� ����������� ����������� � ���������� ������� ������
    int moveIndex = -1;

    if (direction == Direction::Left && col < (SIZE - 1))
        moveIndex = m_EmptyIndex + 1;

    if (direction == Direction::Right && col > 0)
        moveIndex = m_EmptyIndex - 1;

    if (direction == Direction::Up && row < (SIZE - 1))
        moveIndex = m_EmptyIndex + SIZE;

    if (direction == Direction::Down && row > 0)
        moveIndex = m_EmptyIndex - SIZE;

    if (m_EmptyIndex >= 0 && moveIndex >= 0) {
        int tmp = m_Elements[m_EmptyIndex];
        m_Elements[m_EmptyIndex] = m_Elements[moveIndex];
        m_Elements[moveIndex] = tmp;
        m_EmptyIndex = moveIndex;
    }
    m_Solved = Check();
}
