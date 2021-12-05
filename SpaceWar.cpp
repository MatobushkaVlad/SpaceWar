#include <SFML/Graphics.hpp>
#include "Enemies.hpp"
#include "Hero.hpp"
#include <thread>
#include <chrono>

using namespace std::chrono_literals;

int main()
{
    const int width = 640;
    const int height = 1080;
    const int N = 20;

    sf::RenderWindow window(sf::VideoMode(width, height), "Space War");

    std::vector<en::Enemies*> enemies;
    for (int i = 0; i <= width; i += width / N)
        enemies.push_back(new en::Enemies(i, 0, 20, rand() % 5 + 1));

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
        {
            enemy->Move();
            if (enemy->GetY() > height)
            {
                enemy->SetVelocity(rand() % 5 + 1);
                enemy->SetY(0);
            }
        }

        window.clear();

        for (const auto& enemy : enemies)
            window.draw(*enemy->GetE());

        //Hero
        std::vector<he::Hero*> heroes;
        heroes.push_back(new he::Hero(500, 1000, 20, 30));

        for (const auto& hero : heroes)
            window.draw(*hero->GetH());

        window.display();

        std::this_thread::sleep_for(20ms);
    }

    for (const auto& hero : heroes)
        delete hero;
    heroes.clear();

    for (const auto& enemy : enemies)
        delete enemy;
    enemies.clear();

    return 0;
}