#include <string>
#include <iostream>
#include <sstream>
#include "knight.hpp"
#include "piece.hpp" 

using namespace std;

Knight::Knight(char color, int x , int y):Piece(color, x, y){
}//constructor
bool Knight::isValidMove(Piece*** board, Position destiny){
	if (position.getX()+2 == destiny.getX() && position.getY()+1 == destiny.getY() && (board[destiny.getY()][destiny.getX()] == NULL|| board[destiny.getY()][destiny.getX()]->getColor() != color))//x+2, y+1
		return true;
	else if(position.getX()+2 == destiny.getX() && position.getY()-1 == destiny.getY() && (board[destiny.getY()][destiny.getX()] == NULL|| board[destiny.getY()][destiny.getX()]->getColor() != color))//x+2, y-1
		return true;
	else if(position.getX()-2 == destiny.getX() && position.getY()+1 == destiny.getY() && (board[destiny.getY()][destiny.getX()] == NULL|| board[destiny.getY()][destiny.getX()]->getColor() != color))//x-2, y+1
		return true;
	else if(position.getX()-2 == destiny.getX() && position.getY()-1 == destiny.getY() && (board[destiny.getY()][destiny.getX()] == NULL|| board[destiny.getY()][destiny.getX()]->getColor() != color))//x-2, y-1
		return true;
	else if(position.getX()+1 == destiny.getX() && position.getY()+2 == destiny.getY() && (board[destiny.getY()][destiny.getX()] == NULL|| board[destiny.getY()][destiny.getX()]->getColor() != color))//x+1 y+2
		return true;
	else if(position.getX()-1 == destiny.getX() && position.getY()+2 == destiny.getY() && (board[destiny.getY()][destiny.getX()] == NULL|| board[destiny.getY()][destiny.getX()]->getColor() != color))//x-1, y+2
		return true;
	else if(position.getX()+1 == destiny.getX() && position.getY()-2 == destiny.getY() && (board[destiny.getY()][destiny.getX()] == NULL|| board[destiny.getY()][destiny.getX()]->getColor() != color))//x+1 y-2
		return true;
	else if(position.getX()-1 == destiny.getX() && position.getY()-2 == destiny.getY() && (board[destiny.getY()][destiny.getX()] == NULL|| board[destiny.getY()][destiny.getX()]->getColor() != color))//x-1, y-2
		return true;
	else
		return false;
}//si el moviemiento es valido

bool Knight::moveTo(Piece*** board, Position destiny){
	if(isValidMove(board,destiny)){
		board[position.getY()][position.getX()] = NULL;
		position = destiny;
		board[position.getY()][position.getX()] = this;
		return true;
	}
	else{
		cout << "Invalid move" << endl;
		return false;
	}
}//se mueve
string Knight::toString()const{
	stringstream ss;
	if (color == 'N'){
		ss << "C";
	}
	else{
		ss << "c";
	}
	return ss.str();
}
