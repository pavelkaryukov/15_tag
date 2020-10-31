#pragma once
#include <SFML/Graphics.hpp>

const int g_Size = 4; //размер игрового поля в плашках
const int g_ArraySize = g_Size * g_Size;  
const int g_FieldSize = 500;// размер игрового поля в пикселях
const int g_CellSize = 120; //Размер плашки в пикселях

enum class Direction {
    Left = 0, 
    Right,
    Up, 
    Down
};

class Game : public sf::Drawable, public sf::Transformable {
protected:
    int m_Elements[g_ArraySize];
    int m_EmptyIndex;
    bool m_Solved;
    sf::Font m_Font;
public:
    Game();
    void Init();
    bool Check();
    void Move(Direction direction);
public:
    virtual void draw(sf::RenderTarget& aTarget, sf::RenderStates aStates) const;
};


