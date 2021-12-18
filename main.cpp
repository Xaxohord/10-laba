#include <SFML/Graphics.hpp>
#include <thread>
#include <chrono>
#include <iostream>
#include <string>
#include <shape.hpp>
#include <vector>

using namespace std::chrono_literals;

int main()
{   
    srand(time(0));
    const int width = 800;
    const int height = 600;
    const int N = 50;//кол-во фигурок
    sf::RenderWindow window(sf::VideoMode(width, height), L"Прямогоульник!");

    // 1 
    std::vector<kr::Rectangle*> rectangles; //rectangles - название вектора

    for (int i = 0; i <= width; i += width / N)

        rectangles.push_back(new kr::Rectangle( i, 600,  10, 20, rand() % 5 + 1));


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        for (const auto& rectangle : rectangles)
        {
            rectangle->Move();
            //если y<0 ,тогда прямоугольник останавливается в заданной позиции
            if (rectangle->GetY() < 0)
            {
                rectangle->Stop();
       
            }
        }

        window.clear();
        for (const auto& rectangle : rectangles)
            window.draw(*rectangle->Get());

        window.display();

        std::this_thread::sleep_for(40ms);
    }

    for (const auto& rectangle : rectangles)
        delete rectangle;
    rectangles.clear();

    return 0;
}