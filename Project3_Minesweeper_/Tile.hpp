//
//  Tile.hpp
//  Project3_Minesweeper
//
//  Created by Jose Manuel Quintas on 4/12/19.
//  Copyright © 2019 Jose Manuel Quintas. All rights reserved.
//

#ifndef Tile_hpp
#define Tile_hpp

#include <stdio.h>
#include <iomanip>
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>


class Tile {
public:
    Tile();
    //~Tile();
    
    Tile(float x2, float y2); // create a tile with specific coordinates
    
    sf::Sprite  getTile();
    
    sf::Sprite  getflag();
    
    sf::Sprite getmines();
    
    sf::Sprite  getTile_O();
    
    sf::Sprite  getnumb1();
    sf::Sprite  getnumb2();
    sf::Sprite  getnumb3();
    sf::Sprite  getnumb4();
    sf::Sprite  getnumb5();
    sf::Sprite  getnumb6();
    sf::Sprite  getnumb7();
    sf::Sprite  getnumb8();
    
    
    void setCoordinate(float x2, float y2); //set all sprite of tile to specific coordinate
    
    sf::Sprite Status();
    
    void check();
    bool precheck();
    
    
    /*---------------------------------------------------------------*/
    //
    //         working with flag
    //
    /*---------------------------------------------------------------*/
    void actFlags();
    bool is_there_a_flag();
    
    /*---------------------------------------------------------------*/
    //
    //         working with mines
    //
    /*---------------------------------------------------------------*/
    void boom(bool isthere); //set if on tile exist a boom, flase meab, no boom on this tile
    bool safe(); //return if oom has explote or not
    void kabbom(); //boom is press
    bool Reviewboom(); //let see is there s bomb
    
    
    void resetTilesetting(); 
    
private:
    //elements
    //1.title
    sf::Texture tile;
    sf::Sprite Stile;
    
    //2. flag
    sf::Texture flag;
    sf::Sprite Sflag;
    
    
    //3. mines
    sf::Texture mines;
    sf::Sprite Smines;
    
    
    //4. tile open
    sf::Texture tile_open;
    sf::Sprite Stile_O;
    
    //5. coordinates
    float x =0;
    float y = 0;
    
    //6. It is hidden?
    bool hidden = true; //it is hidden, inactive
    
    //7. is there a flag?
    bool flaging = false;
    
    //7. is there a boom?
    bool bomb = false; // does pile posses a bomb? false = NO
    bool active_bomb = false; // has bomb explote? false = NO
    
    
    //8.A work with neighboor
    sf::Texture numb1;
    sf::Sprite Snumb1;
    
    //8.B work with neighboor
    sf::Texture numb2;
    sf::Sprite Snumb2;
    
    //8.C work with neighboor
    sf::Texture numb3;
    sf::Sprite Snumb3;
    
    //8.D work with neighboor
    sf::Texture numb4;
    sf::Sprite Snumb4;
    
    //8.E work with neighboor
    sf::Texture numb5;
    sf::Sprite Snumb5;
    
    //8.F work with neighboor
    sf::Texture numb6;
    sf::Sprite Snumb6;
    
    //8.G work with neighboor
    sf::Texture numb7;
    sf::Sprite Snumb7;
    
    //8.H work with neighboor
    sf::Texture numb8;
    sf::Sprite Snumb8;
};

#endif /* Tile_hpp */
