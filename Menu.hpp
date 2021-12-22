#pragma once
#include "Game.hpp"

namespace me
{
    bool Menu(sf::RenderWindow& window)
    {
        sf::Texture Start;
        sf::Texture Exit;
        sf::Texture Menu_texture;
        sf::Texture GameName;

        Menu_texture.loadFromFile("Textures/background.jpg");
        Start.loadFromFile("Textures/start.png");
        Exit.loadFromFile("Textures/exit.png");
        GameName.loadFromFile("Textures/SpaceWarIcon.png");

        sf::Sprite menu_texture;
        menu_texture.setTexture(Menu_texture);

        sf::Sprite start;
        start.setTexture(Start);
        start.setPosition(160, 450);

        sf::Sprite exit;
        exit.setTexture(Exit);
        exit.setPosition(160, 600);

        sf::Sprite name;
        name.setTexture(GameName);
        name.setPosition(110, 100);

        int nombermenu = 0;
        bool menu = true;

        while (menu)
        {
            start.setColor(sf::Color::White);
            exit.setColor(sf::Color::White);

            window.clear();

            if (sf::IntRect(160, 450, 300, 100).contains(sf::Mouse::getPosition(window))) { start.setColor(sf::Color::Red); nombermenu = 1; }
            if (sf::IntRect(160, 600, 300, 100).contains(sf::Mouse::getPosition(window))) { exit.setColor(sf::Color::Red); nombermenu = 2; }

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                if (nombermenu == 1) { menu = false; }
                if (nombermenu == 2) { return false; window.close(); menu = false; }
            }

            window.draw(menu_texture);
            window.draw(start);
            window.draw(exit);
            window.draw(name);

            window.display();
        }

    }

    bool RestartMenu(sf::RenderWindow& window)
    {
        sf::Texture Menu_texture;
        sf::Texture GameOver;
        sf::Texture Restart;
        sf::Texture Exit;

        Menu_texture.loadFromFile("Textures/background.jpg");
        GameOver.loadFromFile("Textures/GameOver.png");
        Restart.loadFromFile("Textures/Restart.png");
        Exit.loadFromFile("Textures/exit.png");

        sf::Sprite menu_texture;
        menu_texture.setTexture(Menu_texture);

        sf::Sprite gameover;
        gameover.setTexture(GameOver);
        gameover.setPosition(20, 100);

        sf::Sprite restart;
        restart.setTexture(Restart);
        restart.setPosition(160, 450);

        sf::Sprite exit;
        exit.setTexture(Exit);
        exit.setPosition(160, 600);

        int nombermenu = 0;
        bool menu = true;

        while (menu)
        {
            restart.setColor(sf::Color::White);
            exit.setColor(sf::Color::White);

            window.clear();

            if (sf::IntRect(160, 450, 300, 100).contains(sf::Mouse::getPosition(window))) { restart.setColor(sf::Color::Red); nombermenu = 1; }
            if (sf::IntRect(160, 600, 300, 100).contains(sf::Mouse::getPosition(window))) { exit.setColor(sf::Color::Red); nombermenu = 2; }

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                if (nombermenu == 1) { menu = false; return true; }
                if (nombermenu == 2) { return false; window.close(); menu = false; }
            }

            window.draw(menu_texture);
            window.draw(gameover);
            window.draw(restart);
            window.draw(exit);

            window.display();
        }
    }

}
