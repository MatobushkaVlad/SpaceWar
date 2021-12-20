#pragma once
#include "Game.hpp"

namespace me
{
    void Menu(sf::RenderWindow& window)
    {
        sf::Texture Start;
        sf::Texture Exit;
        sf::Texture Menu_texture;

        Menu_texture.loadFromFile("Textures/background.jpg");
        Start.loadFromFile("Textures/start.png");
        Exit.loadFromFile("Textures/exit.png");

        sf::Sprite menu_texture;
        menu_texture.setTexture(Menu_texture);

        sf::Sprite start;
        start.setTexture(Start);
        start.setPosition(160, 300);

        sf::Sprite exit;
        exit.setTexture(Exit);
        exit.setPosition(160, 500);

        int nombermenu = 0;
        bool menu = true;

        while (menu)
        {
            start.setColor(sf::Color::White);
            exit.setColor(sf::Color::White);

            window.clear();

            if (sf::IntRect(160, 300, 300, 100).contains(sf::Mouse::getPosition(window))) { start.setColor(sf::Color::Red); nombermenu = 1; }
            if (sf::IntRect(160, 500, 300, 100).contains(sf::Mouse::getPosition(window))) { exit.setColor(sf::Color::Red); nombermenu = 2; }

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                if (nombermenu == 1) { menu = false; }
                if (nombermenu == 2) { window.close(); menu = false; }
            }

            window.draw(menu_texture);
            window.draw(start);
            window.draw(exit);

            window.display();
        }

    }

}
