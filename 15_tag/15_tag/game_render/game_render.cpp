#include "game_render.h"
#include "../assets/assets.h"

GameRender::GameRender(std::weak_ptr<GameModel>&&  aGame) {
    m_GameModel = std::move(aGame);
    Init();
}

bool GameRender::Init() {
    setPosition(50.f, 50.f);
    // ������� ���� �������� 600 �� 600 � �������� ���������� 60 ������ � �������
    m_Window.create(sf::VideoMode(600, 600), "15");
    m_Window.setFramerateLimit(60);
    // ����� � ������������ ������
    m_Text = sf::Text("F2 - New Game / Esc - Exit / Arrow Keys - Move Tile", Assets::Instance().font, 20);
    m_Text.setFillColor(sf::Color::Cyan);
    m_Text.setPosition(5.f, 5.f);
    return true;
}
                                                               
void GameRender::Render() {
    m_Window.clear();
    m_Window.draw(*this);
    m_Window.draw(m_Text);
    m_Window.display();
}

void GameRender::draw(sf::RenderTarget& aTarget, sf::RenderStates aStates) const {
    aStates.transform *= getTransform();
    sf::Color color = sf::Color(200, 100, 200);

    // ������ ����� �������� ����
    sf::RectangleShape shape(sf::Vector2f(GameModel::FIELD_SIZE, GameModel::FIELD_SIZE));
    shape.setOutlineThickness(2.f);
    shape.setOutlineColor(color);
    shape.setFillColor(sf::Color::Transparent);
    aTarget.draw(shape, aStates);

    // �������������� ����� ��� ��������� ���� ������
    shape.setSize(sf::Vector2f(GameModel::CELL_SIZE - 2, GameModel::CELL_SIZE - 2));
    shape.setOutlineThickness(2.f);
    shape.setOutlineColor(color);
    shape.setFillColor(sf::Color::Transparent);

    // �������������� ��������� ��������� ��� ��������� ������� ������
    sf::Text text("", Assets::Instance().font, 52);
    DrawElements(shape, text, color, aTarget, aStates);
}

void GameRender::DrawElements(sf::RectangleShape& aShape, sf::Text& aText, sf::Color& aColor, sf::RenderTarget& aTarget, sf::RenderStates& aStates) const {
    if (m_GameModel.expired())
        throw std::runtime_error("GameRender: m_GameModel are expired");

    int *elements = m_GameModel.lock()->Elements();
    for (unsigned int i = 0; i < GameModel::ARRAY_SIZE; i++) {
        aShape.setOutlineColor(aColor);
        aText.setFillColor(aColor);
        aText.setString(std::to_string(elements[i]));
        if (m_GameModel.lock()->IsSolved()) {
            // �������� ����������� �������� ������ ������
            aShape.setOutlineColor(sf::Color::Cyan);
            aText.setFillColor(sf::Color::Cyan);
        }
        else if (elements[i] == i + 1) {
            // ������ ������ �� ����� ������ �������� ������
            aText.setFillColor(sf::Color::Green);
        }

        // ������ ��� ������, ����� ������
        if (elements[i] > 0) {
            // ���������� ������� ������ ��� ���������
            sf::Vector2f position(i % GameModel::SIZE * GameModel::CELL_SIZE + 10.f,
                                  i / GameModel::SIZE * GameModel::CELL_SIZE + 10.f);
            aShape.setPosition(position);
            // ������� ������ �������� �������
            aText.setPosition(position.x + 30.f + (elements[i] < 10 ? 15.f : 0.f), position.y + 25.f);
            aTarget.draw(aShape, aStates);
            aTarget.draw(aText, aStates);
        }
    }
}
