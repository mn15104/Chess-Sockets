#ifndef GRID_H
#define GRID_H

#include <stdio.h>
#include <stdlib.h>
#include "Chess.h"
#include "King.h"
#include "SpriteSheet.h"
#include <utility>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include <array>

enum class PlayerState {
    Blue,
    Red
};

enum class GridState {
    AwaitingCellSelect,
    CellSelected,
};

class Grid {
    using ChessPiece = std::pair<std::unique_ptr<Chess>, ChessTeam>;
public:
    Grid(sf::RenderWindow* t_window);
    //Draw grid to window
    void drawGrid();
    void processInput(const sf::Vector2i t_xy);
    void selectCell(const sf::Vector2i t_xy);
    void moveCell(const sf::Vector2i t_xy);
    PlayerState playerState;
    GridState gridState;
    
private:
    SpriteSheet spriteMaker;
    std::array<std::array<ChessPiece, 10>, 10> grid;
    sf::Sprite chessGrid;
    sf::RenderWindow* window = nullptr;
    ChessPiece* selectedPiece;
}; 

#endif 