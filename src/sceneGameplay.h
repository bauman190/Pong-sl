#pragma once
#include "Ball.h"
#include "Player.h"

void drawGamePlay(Ball ball, Paddle player1, Paddle player2, int scoreP1, int scoreP2);


void updateGameplay(Ball& ball, Paddle& player1, Paddle& player2, int& scoreP1, int& scoreP2);