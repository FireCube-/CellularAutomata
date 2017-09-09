#pragma once

#include <bitset>

constexpr int WIDTH = 2000, HEIGHT = 1000, SCALE = 10;
const int GRID_X = floor(WIDTH / SCALE);
constexpr std::bitset<3> PATTERNS[8] = { 0b000, 0b001, 0b010, 0b011, 0b100, 0b101, 0b110, 0b111 };
constexpr uint_fast8_t RULE = 30;
