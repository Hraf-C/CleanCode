#include <iostream>
#include <optional>
#include <p6/p6.h>
#include "menu.h"

struct CellIndex {
    int x;
    int y;
};
float cell_radius(int board_size)
{
    return 1.f / static_cast<float>(board_size);
}

glm::vec2 cell_bottom_left_corner(CellIndex index, int board_size)
{
    const auto idx = glm::vec2{static_cast<float>(index.x),
                               static_cast<float>(index.y)};
    return p6::map(idx,
                   glm::vec2{0.f}, glm::vec2{static_cast<float>(board_size)},
                   glm::vec2{-1.f}, glm::vec2{1.f});
}

void draw_cell(CellIndex index, int board_size, p6::Context& ctx)
{
    ctx.square(p6::BottomLeftCorner{cell_bottom_left_corner(index, board_size)},
               p6::Radius{cell_radius(board_size)});
}

void draw_board(int size, p6::Context& ctx)
{
    for (int x = 0; x < size; ++x) {
        for (int y = 0; y < size; ++y) {
            ctx.square(p6::BottomLeftCorner{p6::map(glm::vec2{static_cast<float>(x), static_cast<float>(y)},
                                                    glm::vec2{0.f}, glm::vec2{static_cast<float>(size)},
                                                    glm::vec2{-1.f}, glm::vec2{1.f})},
                       p6::Radius{1.f / static_cast<float>(size)});
        }
    }
}

int main()
{
     auto ctx   = p6::Context{{800, 800, "Noughts and Crosses"}};
    ctx.update = [&]() {
        ctx.background({.8f, 0.8f, 0.8f});
        ctx.stroke_weight = 0.01f;
        ctx.stroke        = {0.f, 0.2f, 0.3f};
        ctx.fill          = {0.f, 0.f, 0.f, 0.f};
        draw_board(3, ctx);
    };
    ctx.start();
}


//Menu();
