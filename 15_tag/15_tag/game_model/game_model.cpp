#include "game_model.h"
#include <cstddef>

GameModel::GameModel() {
    Init();
}

void GameModel::Init() {
    //Заполняем массив плашек
    for (int i = 0; i < ARRAY_SIZE; ++i)
        m_Elements[i] = i + 1;
    //Ставим пустую плашку в правую нижнюю позицию
    m_EmptyIndex = ARRAY_SIZE - 1;
    m_Elements[m_EmptyIndex] = 0; //Пустая плашка имеет значение 0
    m_Solved = true;
}                             

bool GameModel::Check() {
    //Проверка собранности головоломки
    for (std::size_t i = 0; i < ARRAY_SIZE; ++i) {
        if (m_Elements[i] > 0 && m_Elements[i] != i + 1)
            return false;
    }
    return true;
}

void GameModel::Move(Direction direction) {
    //Вычисляем строку и колонку пустой плашки
    int col = m_EmptyIndex % SIZE;
    int row = m_EmptyIndex / SIZE;

    //Проверка на возможность перемещения и вычисления индекса плашки
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
