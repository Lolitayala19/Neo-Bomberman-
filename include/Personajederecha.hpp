#pragma once

#include <SFML/Graphics.hpp>

class Personajederecha
{
private:
    /* data */
public:
    Personajederecha(/* args */) 
    {

    }
    int Caminarderecha()
    {
            // Crear una ventana
    sf::RenderWindow window(sf::VideoMode(800, 600), "Sprite Animado");

    // Cargar la imagen desde un archivo
    sf::Texture texture;
    if (!texture.loadFromFile("Imagenes/Personaje.png"))
    {
        // Manejo de error si no se puede cargar la imagen
        return -1;
    }

    // Crear un sprite y asignarle la textura
    sf::Sprite sprite(texture);
    sprite.setPosition(400, 300);

    sf::Clock clock;
    float frameTime = 0.1f; // Tiempo entre cada frame en segundos
    int currentFrame = 0;
    int numFrames = 7; // Número total de frames en la animación
    int frameWidth = 20;
    int frameHeight = 26;

    while (window.isOpen())
    {
        // Procesar eventos
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        // Actualizar el frame de la animación
        if (clock.getElapsedTime().asSeconds() >= frameTime)
        {
            // Calcular el cuadro que se debe de ver
            currentFrame = (currentFrame + 1) % numFrames;
            // Calcular cordenadas del cuadro de recorte del sprite
            int arriba = 126;
            int izquierda = (currentFrame * 20)+ 6;
            int ancho = 20;
            int alto = 26;
            // Construir rectangulo de recorte
            sf::IntRect cordenadas = sf::IntRect(izquierda,arriba,ancho,alto);
            // Agregar rectangulo de recorte al sprite
            sprite.setTextureRect(cordenadas);
            // Reiniciar el reloj
            clock.restart();
        }

        window.clear();
        window.draw(sprite);
        window.display();
    }

    return 0;      
    }
    ~Personajederecha() 
    {

    }
};