#pragma once
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;

class Animacion
{
private:
    sf::Texture texture;
    sf::Sprite sprite;
    bool esCorrecto;
    sf::Clock clock;
    sf::Event event;
    sf::IntRect cordenadas = sf::IntRect(izquierda, arriba, ancho, alto);
public:
    Animacion(string path)
    {
        // Cargar la imagen desde un archivo
        if (!texture.loadFromFile(path))
        {
            this->esCorrecto = true;
            // Crear un sprite y asignarle la textura
            this->sprite = sf::Sprite(texture);
            this->sprite.setPosition(400, 300);
            float frameTime = 0.1f; // Tiempo entre cada frame en segundos
            int currentFrame = 0;
            int numFrames = 7; // Número total de frames en la animación
            int frameWidth = 20;
            int frameHeight = 26;
            // Calcular cordenadas del cuadro de recorte del sprite
            int arriba = 70;
            int izquierda = (currentFrame * 20) + 6;
            int ancho = 20;
            int alto = 26;
                // Construir re
        }

    }
    int Actualizar()
    {
        while (window.isOpen())
        {
            // Procesar eventos
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
    ~Animacion() 
    {}
};