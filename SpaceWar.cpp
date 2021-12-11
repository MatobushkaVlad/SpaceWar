#include <SFML/Graphics.hpp>
#include "Enemies.hpp"
#include "Hero.hpp"
#include "Hero_Lazer.hpp"
#include "Enemies_Lazer.hpp"
#include <iostream>
#include <thread>
#include <chrono>

using namespace std::chrono_literals;

int main()
{
    const int width = 640;
    const int height = 1080;
    const int N = 20;

    sf::RenderWindow window(sf::VideoMode(width, height), "Space War");

    sf::Texture texture;
    if (!texture.loadFromFile("Textures/background.jpg"))
    {
        std::cout << "ERROR when loading back.jpg" << std::endl;
        return false;
    }
    sf::Sprite back;
    back.setTexture(texture);

    std::vector<en::Enemies*> enemies;
    std::vector<el::Enemies_Lazer*> e_lazers;
    for (int i = 0; i <= width; i += width / N)
    {
        enemies.push_back(new en::Enemies(i, 0, 20, rand() % 5 + 1));
        e_lazers.push_back(new el::Enemies_Lazer(i, 0, 10, 20, 6));
    }
    for (const auto& enemy : enemies)
        if (!enemy->Setup())
            return -1;
    for (const auto& e_lazer : e_lazers)
        if (!e_lazer->Setup())
            return -1;

    he::Hero* hero = nullptr;
    hero = new he::Hero(320, 900, 30, 39);
    hl::Hero_Lazer* lazer = nullptr;
    lazer = new hl::Hero_Lazer(320, 900, 10, 20, 20);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //Enemies
        for (const auto& enemy : enemies)
            for (const auto& e_lazer : e_lazers)
            {
                e_lazer->Move();
                enemy->Move();
                if (e_lazer->GetY() > height)
                {
                    e_lazer->SetY(enemy->GetY());
                }
                if (enemy->GetY() > height)
                {
                    enemy->SetVelocity(rand() % 5 + 1);
                    enemy->SetY(0);
                }
        
            }

        if (!lazer->Setup())
        {
            delete lazer;
            window.close();
            return -1;
        }

        if (lazer != nullptr)
        {
            lazer->Move();
            if (lazer->GetY() < 0)
                lazer->SetY(hero->GetY());
        }

        if (!hero->Setup())
        {
            delete hero;
            window.close();
            return -1;
        }

        //Очищение окна
        window.clear();

        //Отрисовка фона
        window.draw(back);

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

        std::this_thread::sleep_for(20ms);
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

    return 0;
}