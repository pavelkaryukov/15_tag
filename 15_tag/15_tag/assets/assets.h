#pragma once                
#include <stdexcept>
#include <SFML/Graphics.hpp>
class Assets {
public:
    sf::Font font;
    
    static Assets& Instance() {
        static Assets assets;
        
        if (!assets.m_Loaded)
            assets.Load();

        return assets;
    }
private:
    bool m_Loaded = false;
    Assets() { };
    ~Assets() {};
    Assets(Assets const&) = delete;
    Assets& operator= (Assets const&) = delete;
    void Load() {
        if (!font.loadFromFile("resources//calibri.ttf"))
            throw std::runtime_error("cant open font file resources//colibri.ttf");
    }
};
