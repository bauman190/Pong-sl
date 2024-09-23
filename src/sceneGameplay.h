#pragma once
#include "Ball.h"
#include "Player.h"
#include "Win.h"

void drawGamePlay(Ball ball, Paddle player1, Paddle player2, int scoreP1, int scoreP2, WhoWins whoWins);


void updateGameplay(Ball& ball, Paddle& player1, Paddle& player2, int& scoreP1, int& scoreP2, WhoWins& whoWins);

void resetGamePlay(Ball& ball, Paddle& player1, Paddle& player2, int& scoreP1, int& scoreP2);