#include "game.h"

Game::Game() {
    m_Font.loadFromFile("resources/calibri.ttf");
    Init();
}

void Game::Init() {
    //��������� ������ ������
    for (int i = 0; i < g_ArraySize; ++i)
        m_Elements[i] = i + 1;
    //������ ������ ������ � ������ ������ �������
    m_EmptyIndex = g_ArraySize - 1;
    m_Elements[m_EmptyIndex] = 0; //������ ������ ����� �������� 0
    m_Solved = true;
}

bool Game::Check() {
    //�������� ����������� �����������
    for (std::size_t i = 0; i < g_ArraySize; ++i) {
        if (m_Elements[i] > 0 && m_Elements[i] != i + 1)
            return false;
    }
    return true;
}

void Game::Move(Direction direction) {
    //��������� ������ � ������� ������ ������
    int col = m_EmptyIndex % g_Size;
    int row = m_EmptyIndex / g_Size;

    //�������� �� ����������� ����������� � ���������� ������� ������
    int moveIndex = -1;

    if (direction == Direction::Left && col < (g_Size - 1)) 
        moveIndex = m_EmptyIndex + 1;

    if (direction == Direction::Right && col > 0) 
        moveIndex = m_EmptyIndex - 1;

    if (direction == Direction::Up && row < (g_Size - 1)) 
        moveIndex = m_EmptyIndex + g_Size;

    if (direction == Direction::Down && row > 0) 
        moveIndex = m_EmptyIndex - g_Size;

    if (m_EmptyIndex >= 0 && moveIndex >= 0) {
        int tmp = m_Elements[m_EmptyIndex];
        m_Elements[m_EmptyIndex] = m_Elements[moveIndex];
        m_Elements[moveIndex] = tmp;
        m_EmptyIndex = moveIndex;
    }
    m_Solved = Check();
}

void Game::draw(sf::RenderTarget & aTarget, sf::RenderStates aStates) const {
    aStates.transform *= getTransform();
    sf::Color color = sf::Color(200, 100, 200);

    //������ ����� �������� ����
    sf::RectangleShape shape(sf::Vector2f(g_FieldSize, g_FieldSize));
    shape.setOutlineThickness(2.f);
    shape.setOutlineColor(color);
    shape.setFillColor(sf::Color::Transparent);
    aTarget.draw(shape, aStates);

    // �������������� ����� ��� ��������� ���� ������
    shape.setSize(sf::Vector2f(g_CellSize - 2, g_CellSize - 2));
    shape.setOutlineThickness(2.f);
    shape.setOutlineColor(color);
    shape.setFillColor(sf::Color::Transparent);

    // �������������� ��������� ��������� ��� ��������� ������� ������
    sf::Text text("", m_Font, 52);
    for (std::size_t i = 0; i < g_ArraySize; ++i) {
        shape.setOutlineColor(color);
        text.setFillColor(color);
        text.setString(std::to_string(m_Elements[i]));

        if (m_Solved) {
            shape.setOutlineColor(sf::Color::Cyan);
            text.setFillColor(sf::Color::Cyan);
        }
        else  if (m_Elements[i] == i+1) {
            text.setFillColor(sf::Color::Green);
        }

        //������ ��� ������ ����� ������
        if (m_Elements[i] > 0) {
            // ���������� ������� ������ ��� ���������
            sf::Vector2f position(i % g_Size * g_CellSize + 10.f, i / g_Size * g_CellSize + 10.f);
            shape.setPosition(position);
            // ������� ������ �������� �������
            text.setPosition(position.x + 30.f + (m_Elements[i] < 10 ? 15.f : 0.f), position.y + 25.f);
            aTarget.draw(shape, aStates);
            aTarget.draw(text , aStates);
        }
    }
}
