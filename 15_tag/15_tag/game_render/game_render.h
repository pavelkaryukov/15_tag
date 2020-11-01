#pragma once
#include "../game_model/game_model.h"
#include <SFML/Graphics.hpp>
#include <memory>

class GameRender : public sf::Drawable, public sf::Transformable {
    std::weak_ptr<GameModel> m_GameModel;
    sf::RenderWindow m_Window;
    sf::Text m_Text;
public:
    GameRender(std::weak_ptr<GameModel>&& aGame);
    ~GameRender() {};
    sf::RenderWindow& window() { return m_Window; };
    bool Init();
    void Render();

    void draw(sf::RenderTarget& aTarget, sf::RenderStates aStates) const override;
private:
    void DrawElements(sf::RectangleShape& aShape, sf::Text& aText, sf::Color& aColor, sf::RenderTarget& aTarget, sf::RenderStates& aStates) const;
};
