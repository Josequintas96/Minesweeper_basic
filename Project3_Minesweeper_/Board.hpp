//
//  Board.hpp
//  Project3_Minesweeper
//
//  Created by Jose Manuel Quintas on 4/12/19.
//  Copyright © 2019 Jose Manuel Quintas. All rights reserved.
//

#ifndef Board_hpp
#define Board_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

#include <vector>
#include "Tile.hpp"
#include "Controls.hpp"

class Board
{
public:
    Board();
    ~Board();
    
    void ResetBoard(int &option);
    
    //Print board
    //option1: piece by piece
    sf::Sprite printPiece(int x);
    void open(int x, int y);
    void preopen(int &loc);
    void findneighboor(int &loc);
    int returnTiles();
    int returnMines();
    void markneigbor(int &neig, int &loc);
    
    /*---------------------------------------------------------------*/
    //
    //         accumulate different location where exist a specific number of neighbor
    //
    /*---------------------------------------------------------------*/
    void findnumb1(std::vector<int> &numb1);
    void findnumb2(std::vector<int> &numb1);
    void findnumb3(std::vector<int> &numb1);
    void findnumb4(std::vector<int> &numb1);
    void findnumb5(std::vector<int> &numb1);
    void findnumb6(std::vector<int> &numb1);
    void findnumb7(std::vector<int> &numb1);
    void findnumb8(std::vector<int> &numb1);
    
    
    /*---------------------------------------------------------------*/
    //
    //         print different numbers
    //
    /*---------------------------------------------------------------*/
    sf::Sprite printnumb1(int &loc);
    sf::Sprite printnumb2(int &loc);
    sf::Sprite printnumb3(int &loc);
    sf::Sprite printnumb4(int &loc);
    sf::Sprite printnumb5(int &loc);
    sf::Sprite printnumb6(int &loc);
    sf::Sprite printnumb7(int &loc);
    sf::Sprite printnumb8(int &loc);
    
    
    /*---------------------------------------------------------------*/
    //
    //         working with flags
    //
    /*---------------------------------------------------------------*/
    void putflag(int x, int y);
    void findflag(std::vector<int> &flagcount);//return diiferent location were a flag exist
    sf::Sprite showflag(int x);//print flag
    
    /*---------------------------------------------------------------*/
    //
    //         working with mines
    //
    /*---------------------------------------------------------------*/
    std::vector<int> Bobs; //how many bobs are there (size), and locations (data)
    void filling(int &i); //organize bombs
    void randomboomgenerator();
    void setboom(int location, bool isthere); //set bomb on expecific position
    bool board_kaboom(int &location); //did you press a bomb?
    sf::Sprite Printmine(int &location);
    
    /*---------------------------------------------------------------*/
    //
    //         printing any of different elements
    //
    /*---------------------------------------------------------------*/
    sf::Sprite printDebug();
    sf::Sprite printTest1();
    sf::Sprite printTest2();
    sf::Sprite printTest3();
    sf::Sprite printFace_h();
    sf::Sprite printFace_l();
    sf::Sprite printFace_w();
    sf::Sprite printDig0();
    sf::Sprite printDig0_O();
    sf::Sprite printDig1();
    sf::Sprite printDigsymbol();
    sf::Sprite choiceDigits1(int &i);
    sf::Sprite choiceDigits2(int &i);
    
    
    std::vector<Tile *> board;
private:
    
    Controls extraboard;
    int total_mines=0;
    int total_tiles=400;
    std::vector<int> neigboor1;//which tiles has 1 bomb neighbor
    std::vector<int> neigboor2;//which tiles has 2 bomb neighbor
    std::vector<int> neigboor3;//which tiles has 3 bomb neighbor
    std::vector<int> neigboor4;//which tiles has 4 bomb neighbor
    std::vector<int> neigboor5;//which tiles has 5 bomb neighbor
    std::vector<int> neigboor6;//which tiles has 6 bomb neighbor
    std::vector<int> neigboor7;//which tiles has 7 bomb neighbor
    std::vector<int> neigboor8;//which tiles has 8 bomb neighbor
    
};

#endif /* Board_hpp */
