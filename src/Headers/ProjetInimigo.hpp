#ifndef PROJETINIMIGO_HPP
#define PROJETINIMIGO_HPP

#include <SFML/Graphics.hpp>

class ProjetInimigo {
public:
    // Construtor
    ProjetInimigo(sf::Texture* texture, float x, float y, float dirX, float dirY, float speed);

    // Atualiza a posição do projétil
    void update();

    // Retorna os limites do projétil para detecção de colisão
    const sf::FloatRect getBounds() const;

    // Renderiza o projétil
    void render(sf::RenderTarget* target);

private:
    sf::Sprite shape;        // Sprite que representa o projétil
    sf::Vector2f direction;  // Direção do movimento do projétil
    float speed;             // Velocidade do projétil
};

#endif // PROJETINIMIGO_HPP
