#include "Headers/Status.hpp"
#include <iostream>


// Inicializa a fonte
void Status::initFont()
{
    if (!this->font.loadFromFile("Assests/Fonts/MetalSlug.otf"))
    {
        std::cout << "ERRO: Não foi possível carregar a fonte!" << std::endl;
    }
}

Status::Status(float vidaInicialAtirador, float vidaInicialBase, float projeteisDisponiveis)
    : vidaInicialAtirador(vidaInicialAtirador), vidaInicialBase(vidaInicialBase), projeteisDisponiveis(projeteisDisponiveis)
{
    this->initFont();

    // Configura o texto para a vida do atirador
    this->vidaAtiradorText.setFont(this->font);
    this->vidaAtiradorText.setCharacterSize(24);
    this->vidaAtiradorText.setFillColor(sf::Color::Black);
    

    // Configura o texto para a vida da base
    this->vidaBaseText.setFont(this->font);
    this->vidaBaseText.setCharacterSize(24);
    this->vidaBaseText.setFillColor(sf::Color::Black);

    // Configura o texto para os projéteis disponíveis
    this->projeteisDisponiveisText.setFont(this->font);
    this->projeteisDisponiveisText.setCharacterSize(24);
    this->projeteisDisponiveisText.setFillColor(sf::Color::Black);

    
}

Status::~Status()
{
}

void Status::update(const Atirador& atirador, const Base& base)
{
    // Converte a vida do atirador de float para int
    int vidaAtiradorInt = static_cast<int>(atirador.getVida());
    int vidaInicialAtiradorInt = static_cast<int>(vidaInicialAtirador);
    int projeteisDisponiveisInt = atirador.getProjeteisDisponiveis();

    // Atualiza o texto com a vida do atirador e da base
    this->vidaAtiradorText.setString("Vida do Atirador: " + std::to_string(vidaAtiradorInt) + "/" + std::to_string(vidaInicialAtiradorInt));
    this->vidaBaseText.setString("Vida da Base: " + std::to_string(static_cast<int>(base.getVida())) + "/" + std::to_string(static_cast<int>(vidaInicialBase)));
    this->projeteisDisponiveisText.setString("Balas: " + std::to_string(projeteisDisponiveisInt));

    // Posição do texto no lado direito da tela
    float windowWidth = 800.f; // Conforme o tamanho da janela
    float offsetX = 20.f; // Espaçamento da borda direita

    // Posição do texto da vida do atirador
    this->vidaAtiradorText.setPosition(windowWidth - this->vidaAtiradorText.getGlobalBounds().width - offsetX, 10.f);

    // Posição do texto da vida da base 
    this->vidaBaseText.setPosition(windowWidth - this->vidaBaseText.getGlobalBounds().width - offsetX, 40.f);

    // Posição do texto dos projéteis disponíveis
    this->projeteisDisponiveisText.setPosition(windowWidth - this->projeteisDisponiveisText.getGlobalBounds().width - offsetX, 70.f);
}


void Status::render(sf::RenderTarget* target)
{
    target->draw(this->vidaAtiradorText);
    target->draw(this->vidaBaseText);
    target->draw(this->projeteisDisponiveisText);
}
