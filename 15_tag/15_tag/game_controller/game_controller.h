#pragma once
#include "../game_render/game_render.h"
#include <SFML/Graphics.hpp>

class GameController {
    std::weak_ptr<GameModel>  m_Game;
    std::weak_ptr<GameRender> m_Render;
public:
    GameController(std::weak_ptr<GameModel>&& aGame, std::weak_ptr<GameRender>&& aRender) : m_Game(std::move(aGame)), m_Render(std::move(aRender)) {};
    ~GameController() { std::cout << "GameController destructor" << std::endl; };
    void Run();
};