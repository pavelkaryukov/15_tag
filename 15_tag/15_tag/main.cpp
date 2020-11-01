#include "assets/assets.h"
#include "game_model/game_model.h"
#include "game_render/game_render.h"
#include "game_controller/game_controller.h"

int main() {
    std::shared_ptr<GameModel>  game = std::make_shared<GameModel>();// Создаем модель игры
    std::shared_ptr<GameRender> render = std::make_shared<GameRender>(game);	// Создаем представление
    GameController controller(game, render);	// Создаем контроллер
    try {
        controller.Run(); // Запускаем игру
    }
    catch (std::exception* e) {
        std::cout << e->what() << std::endl;
    }
    return 0;
}