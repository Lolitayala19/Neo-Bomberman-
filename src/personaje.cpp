#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <Direccion.hpp>

class Bomba
{
public:
    Bomba(sf::Vector2f position, sf::Color color)
    {
    shape.setSize(sf::Vector2f(1, 1));
    shape.setPosition(position); // Posición inicial cuadro
    shape.setFillColor(color);

        // Cargar la imagen desde un archivo
        
    if (!texture.loadFromFile("./Imagenes/Bomba.png"))
        {
        
        }
    this->sprite = sf::Sprite(texture);
    this->sprite.setPosition(position); // Posición inicial sprite    
    }
 void draw(sf::RenderWindow &window)
    {
        window.draw(this->shape);
        window.draw(this->sprite);
    }

    void update(){
        // Actualizar el frame de la animación
        if (clock.getElapsedTime().asSeconds() >= frameTime)
        {
            currentFrame = (currentFrame + 1) % numFrames;
            sprite.setTextureRect(sf::IntRect((currentFrame * 16) - 10, 7, 16, 15));
            clock.restart();
        }
    }

private:
    sf::RectangleShape shape;
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Clock clock;
    float frameTime = 1.0f; // Tiempo entre cada frame en segundos
    int currentFrame = 0;
    int numFrames = 3; // Número total de frames en la animación
    int frameWidth = 16;
    int frameHeight = 15;



};

class Personaje
{
public:

    Personaje(sf::Vector2f position, sf::Color color)
    {
        shape.setSize(sf::Vector2f(1, 1));
        shape.setPosition(position); // Posición inicial cuadro
        shape.setFillColor(color);

        // Cargar la imagen desde un archivo
        
        if (!texture.loadFromFile("./Imagenes/PERSONAJES.png"))
        {
        
        }
        this->sprite = sf::Sprite(texture);
        this->sprite.setPosition(position); // Posición inicial sprite
    }

    void move(float offsetX, float offsetY)
    {
        sprite.move(offsetX, offsetY);
        shape.move(offsetX, offsetY);
    }

    void draw(sf::RenderWindow &window)
    {
        window.draw(this->shape);
        window.draw(this->sprite);
    }

    void update()
    {
        // Actualizar el frame de la animación
        if (clock.getElapsedTime().asSeconds() >= frameTime)
        {
            currentFrame = (currentFrame + 1) % numFrames;
            sprite.setTextureRect(sf::IntRect((currentFrame * 21) + 0, 0, 21, 26));
            clock.restart();
        }
    }
private:
    sf::RectangleShape shape;
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Clock clock;
    float frameTime = 0.1f; // Tiempo entre cada frame en segundos
    int currentFrame = 0;
    int numFrames = 7; // Número total de frames en la animación
    int frameWidth = 20;
    int frameHeight = 26;
};

class Enemigo
{
public:

    Enemigo(sf::Vector2f position, sf::Color color)
    {
        shape.setSize(sf::Vector2f(1, 1));
        shape.setPosition(position); // Posición inicial cuadro
        shape.setFillColor(color);

        // Cargar la imagen desde un archivo
        
        if (!texture.loadFromFile("./Imagenes/ENEMIGO1.png"))
        {
        
        }
        this->sprite = sf::Sprite(texture);
        this->sprite.setPosition(position); // Posición inicial sprite
    }

    void move(float offsetX, float offsetY)
    {
        sprite.move(offsetX, offsetY);
        shape.move(offsetX, offsetY);
    }

    void draw(sf::RenderWindow &window)
    {
        window.draw(this->shape);
        window.draw(this->sprite);
    }

    void update(){
        // Actualizar el frame de la animación
        if (clock.getElapsedTime().asSeconds() >= frameTime)
        {
            currentFrame = (currentFrame + 1) % numFrames;
            sprite.setTextureRect(sf::IntRect((currentFrame * 19) + 0, 0, 19, 28));
            clock.restart();
        }
    }

private:
    sf::RectangleShape shape;
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Clock clock;
    float frameTime = 0.2; // Tiempo entre cada frame en segundos
    int currentFrame = 0;
    int numFrames = 7; // Número total de frames en la animación
    int frameWidth = 19;
    int frameHeight = 28;
};

int main()
{
    sf::Texture texture;
    if (!texture.loadFromFile("./Imagenes/Mapa.png"))
    {
        // Manejar el error si no se puede cargar la imagen
        return -1;
    }
     // Crear un sprite y asignarle la textura
    sf::Sprite sprite(texture);
    
    sf::Music music;
    if (!music.openFromFile("./assets/music/Nivel1.mp3"))
    {
        // Error al cargar el archivo de música
        return -1;
    }

    // Reproducir la música
    music.play();

    sf::RenderWindow window(sf::VideoMode(300, 200), "NeoBomberman");

    Personaje Bomberman(sf::Vector2f(50, 50), sf::Color::Red);
    Enemigo Medusa(sf::Vector2f(180,80),sf::Color::Red);
    Bomba Bomba(sf::Vector2f(10,10),sf::Color::Red);
    Bomba.update();
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            Bomberman.move(velocidad * -1, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            Bomberman.move(velocidad, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            Bomberman.move(0, velocidad * -1);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            Bomberman.move(0, velocidad);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
        {
            Bomba.update();
            Bomba.draw(window);
        }
        


        // Actualizar animacion pikachu
        Bomberman.update();
        Medusa.update();
        window.clear();
        window.draw(sprite);
        Bomberman.draw(window);
        Medusa.draw(window);
      
       window.display();

        if (music.getStatus() != sf::Music::Playing)
        {
            window.close();
        }
    }

    return 0;
}