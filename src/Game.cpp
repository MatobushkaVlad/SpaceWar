#include <SFML/Graphics.hpp>
#include <Enemies.hpp>
#include <Hero.hpp>
#include <Hero_Lazer.hpp>
#include <Enemies_Lazer.hpp>
#include <Menu.hpp>
#include <Game.hpp>
#include <iostream>
#include <thread>
#include <chrono>
#include <windows.h>

using namespace std::chrono_literals;

namespace ga
{
    bool Game()
    {
        const int width = 640;
        const int height = 1080;
        const int N = 10;
        int score = 0;

        sf::RenderWindow window(sf::VideoMode(width, height), "Space War");

        //Иконка окна
        sf::Image icon;
        if (!icon.loadFromFile("Textures/SpaceWar.png"))
        {
            return false;
        }
        window.setIcon(32, 32, icon.getPixelsPtr());

        me::Menu(window);

        if (me::Menu(window) == false)
        {
            return false;
        }

        //Загрузка фона
        sf::Texture texture;
        if (!texture.loadFromFile("Textures/background2.jpg"))
        {
            std::cout << "ERROR when loading background2.jpg" << std::endl;
            return false;
        }
        sf::Sprite back;
        back.setTexture(texture);

        //Загрузка шрифта
        sf::Font font;
        if (!font.loadFromFile("Fonts/STENCIL.ttf"))
        {
            std::cout << "ERROR: font was not loaded." << std::endl;
            return false;
        }

        //Текст
        sf::Text text;
        text.setFont(font);
        text.setCharacterSize(30);
        text.setFillColor(sf::Color(235, 1, 101));
        text.setStyle(sf::Text::Bold);

        //создание врагов и их лазеров
        std::vector<en::Enemies*> enemies;
        std::vector<el::Enemies_Lazer*> e_lazers;
        for (int i = 20; i <= width; i += width / N)
        {
            int L = rand() % 5 + 5;
            enemies.push_back(new en::Enemies(i, 0, 20, L));
            e_lazers.push_back(new el::Enemies_Lazer(i, 0, 10, 20, L + 3));
        }
        for (const auto& enemy : enemies)
            if (!enemy->Setup())
                return false;
        for (const auto& e_lazer : e_lazers)
            if (!e_lazer->Setup())
                return false;

        //Создание героя и его лазера
        he::Hero* hero = nullptr;
        hero = new he::Hero(320, 900, 30, 39);
        hl::Hero_Lazer* lazer = nullptr;
        lazer = new hl::Hero_Lazer(320, 900, 10, 20, 25);

        int M = 0;

        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            //Враги и их лазеры
            for (const auto& enemy : enemies)
            {
                enemy->Move();
                int L = rand() % 5 + 5;
                if (enemy->GetY() > height)
                {
                    enemy->SetVelocity(L);
                    enemy->SetY(0);
                }
                for (const auto& e_lazer : e_lazers)
                {
                    if (e_lazer->GetX() == enemy->GetX())
                    {
                        e_lazer->Move();
                        if ((e_lazer->GetY() > height))
                        {
                            e_lazer->SetVelocity(L + 3);
                            e_lazer->SetY(enemy->GetY());
                        }
                    }
                    int x_el = e_lazer->GetX();
                    int y_el = e_lazer->GetY();
                    float l_el = e_lazer->GetL();

                    int x_e = enemy->GetX();
                    int y_e = enemy->GetY();
                    float r_e = enemy->GetR();

                    int x_h = hero->GetX();
                    int y_h = hero->GetY();
                    float l_h = hero->GetL();

                    //Расстояние от врагов и их лазеров до героя
                    float d_1 = sqrt((x_h - x_el) * (x_h - x_el) + (y_h - y_el) * (y_h - y_el));
                    float d_2 = sqrt((x_h - x_e) * (x_h - x_e) + (y_h - y_e) * (y_h - y_e));

                    if ((l_h + l_el >= d_1) || (l_h + r_e >= d_2))
                    {
                        for (const auto& enemy : enemies) { enemy->SetVelocity(0); }
                        for (const auto& e_lazer : e_lazers) { e_lazer->SetVelocity(0); }
                        lazer->SetVelocity(0);
                        M = 1;
                    }
                }
            }

            if (!lazer->Setup())
            {
                delete lazer;
                window.close();
                return false;
            }

            //Лазер героя
            if (lazer != nullptr)
            {
                lazer->Move();
                if (lazer->GetY() < 0)
                    lazer->Set(hero->GetX(), hero->GetY());
                for (const auto& enemy : enemies)
                {
                    int X = lazer->GetX();
                    int Y = lazer->GetY();
                    float L = lazer->GetL();

                    int x = enemy->GetX();
                    int y = enemy->GetY();
                    float R = enemy->GetR();

                    float d = sqrt((X - x) * (X - x) + (Y - y) * (Y - y));
                    if (L + R >= d)
                    {
                        enemy->SetY(0);
                        lazer->Set(hero->GetX(), hero->GetY());
                        score++;
                    }
                }
            }

            if (!hero->Setup())
            {
                delete hero;
                window.close();
                return false;
            }

            //Движение героя
            if (hero != nullptr)
            {
                if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::W))) { hero->Move(0, -8); }
                if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::S))) { hero->Move(0, 8); }
                if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::A))) { hero->Move(-8, 0); }
                if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::D))) { hero->Move(8, 0); }
            }

            //Ограничения области игры
            if (((hero->GetX() - 8) <= 22)) { hero->SetX(23); }

            if ((hero->GetX() + 8) >= 615) { hero->SetX(614); }

            if ((hero->GetY() - 8) <= 200) { hero->SetY(201); }

            if ((hero->GetY() + 8) >= 1030) { hero->SetY(1020); }

            //Очищение окна
            window.clear();

            //Отрисовка фона
            window.draw(back);

            text.setString(std::string("Score: ") + std::to_string(score));
            window.draw(text);

            for (const auto& e_lazer : e_lazers)
                window.draw(*e_lazer->GetEL());

            //Отрисовка врагов
            for (const auto& enemy : enemies)
                window.draw(*enemy->GetE());

            //Отрисовка героя
            if (hero != nullptr)
                window.draw(*hero->GetH());

            //Отрисовка лазера героя
            if (lazer != nullptr)
                window.draw(*lazer->GetHL());

            //Оторбражение всего, что есть в буфере
            window.display();

            std::this_thread::sleep_for(30ms);

            //если R, то выходим в меню (рестарт)
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) { return true; }
            //если эскейп, то выходим из игры
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) { return false; }

            if (M == 1)
            {
                me::RestartMenu(window);
                if (me::RestartMenu(window) == true)
                {
                    M = 0;
                    return true;
                }
                else { return false; }
            }
        }

        for (const auto& e_lazer : e_lazers)
            delete e_lazer;
        e_lazers.clear();

        for (const auto& enemy : enemies)
            delete enemy;
        enemies.clear();

        if (lazer != nullptr)
            delete lazer;

        if (hero != nullptr)
            delete hero;
    }

    void RestartGame()
    {
        if (Game()) { RestartGame(); }
    }

}