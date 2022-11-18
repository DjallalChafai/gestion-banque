#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML window");

    sf::Texture texture;
    if (!texture.loadFromFile("achratatouille.jpeg"))
        return EXIT_FAILURE;
    sf::Sprite sprite(texture);

    sf::Font font;
    if(!font.loadFromFile("ArialTh.ttf"))
        return EXIT_FAILURE;
    sf::Text text("Bah wsh!!!", font, 50);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(sprite);
        window.draw(text);
        window.display();
        
    }

    return EXIT_SUCCESS;
    
}