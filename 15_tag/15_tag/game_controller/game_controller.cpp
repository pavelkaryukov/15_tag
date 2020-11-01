#include "game_controller.h"
#include <stdexcept>

void GameController::Run() {
    if (m_Render.expired() || m_Game.expired())
        throw std::runtime_error("GameController: m_Render or m_Game empty");

    sf::Event event;
    int move_counter = 0;	// ������� ��������� ����� ��� ������������� �����������

    while (m_Render.lock()->window().isOpen()) {
        while (m_Render.lock()->window().pollEvent(event)) {
            if (event.type == sf::Event::Closed) m_Render.lock()->window().close();
            if (event.type == sf::Event::KeyPressed) {
                // �������� ������� ������� - ��������� ��������������� ��������
                if (event.key.code == sf::Keyboard::Escape) m_Render.lock()->window().close();
                if (event.key.code == sf::Keyboard::Left)   m_Game.lock()->Move(Direction::Left);
                if (event.key.code == sf::Keyboard::Right)  m_Game.lock()->Move(Direction::Right);
                if (event.key.code == sf::Keyboard::Up)     m_Game.lock()->Move(Direction::Up);
                if (event.key.code == sf::Keyboard::Down)   m_Game.lock()->Move(Direction::Down);
                // ����� ����
                if (event.key.code == sf::Keyboard::F2) {
                    m_Game.lock()->Init();
                    move_counter = 100;
                }
            }
        }

        // ���� ������� ����� ������ ����, ���������� ������������ �����������
        if (move_counter-- > 0) m_Game.lock()->Move((Direction)(rand() % 4));

        // ��������� ����������� �������� �� ���������
        m_Render.lock()->Render();
    }
}
