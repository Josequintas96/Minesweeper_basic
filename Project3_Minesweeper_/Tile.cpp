//
//  Tile.cpp
//  Project3_Minesweeper
//
//  Created by Jose Manuel Quintas on 4/12/19.
//  Copyright © 2019 Jose Manuel Quintas. All rights reserved.
//

#include "Tile.hpp"
#include "ResourcePath.hpp"

Tile::Tile()
{
    //if (!tile.loadFromFile(resourcePath()+"images/tile_hidden.png"))
    if(!tile.loadFromFile(resourcePath()+"tile_hidden.png"))
    {
        std::cout << "wrong title"<<std::endl;
        return EXIT_FAILURE;
    }
    Stile.setTexture(tile);
    
    if (!mines.loadFromFile(resourcePath()+"mine.png")) {
        std::cout << "wrong mines"<<std::endl;
        return EXIT_FAILURE;
    }
    Smines.setTexture(mines);
    
    if (!flag.loadFromFile(resourcePath()+"flag.png")) {
        std::cout << "wrong flag"<<std::endl;
        return EXIT_FAILURE;
    }
    Sflag.setTexture(flag);
    
    if (!tile_open.loadFromFile(resourcePath()+"tile_revealed.png")) {
        std::cout << "wrong title revelaed"<<std::endl;
        return EXIT_FAILURE;
    }
    Stile_O.setTexture(tile_open);
    
    if (!numb1.loadFromFile(resourcePath()+"number_1.png")) {
        std::cout << "wrong numb1"<<std::endl;
        return EXIT_FAILURE;
    }
    Snumb1.setTexture(numb1);
    
    if (!numb2.loadFromFile(resourcePath()+"number_2.png")) {
        std::cout << "wrong numb2"<<std::endl;
        return EXIT_FAILURE;
    }
    Snumb2.setTexture(numb2);
    
    if (!numb3.loadFromFile(resourcePath()+"number_3.png")) {
        std::cout << "wrong numb3"<<std::endl;
        return EXIT_FAILURE;
    }
    Snumb3.setTexture(numb3);
    
    if (!numb4.loadFromFile(resourcePath()+"number_4.png")) {
        std::cout << "wrong numb4"<<std::endl;
        return EXIT_FAILURE;
    }
    Snumb4.setTexture(numb4);
    
    if (!numb5.loadFromFile(resourcePath()+"number_5.png")) {
        std::cout << "wrong numb5"<<std::endl;
        return EXIT_FAILURE;
    }
    Snumb5.setTexture(numb5);
    
    if (!numb6.loadFromFile(resourcePath()+"number_6.png")) {
        std::cout << "wrong numb6"<<std::endl;
        return EXIT_FAILURE;
    }
    Snumb6.setTexture(numb6);
    
    if (!numb7.loadFromFile(resourcePath()+"number_7.png")) {
        std::cout << "wrong numb1"<<std::endl;
        return EXIT_FAILURE;
    }
    Snumb7.setTexture(numb7);
    
    if (!numb8.loadFromFile(resourcePath()+"number_8.png")) {
        std::cout << "wrong numb8"<<std::endl;
        return EXIT_FAILURE;
    }
    Snumb8.setTexture(numb8);
    
    setCoordinate( 0.0f, 0.0f);
    
};

Tile::Tile(float x2, float y2)
{
    if (!tile.loadFromFile(resourcePath()+"tile_hidden.png")) {
        std::cout << "wrong title"<<std::endl;
        return EXIT_FAILURE;
    }
    Stile.setTexture(tile);
    
    if (!mines.loadFromFile(resourcePath()+"mine.png")) {
        std::cout << "wrong mines"<<std::endl;
        return EXIT_FAILURE;
    }
    Smines.setTexture(mines);
    
    if (!flag.loadFromFile(resourcePath()+"flag.png")) {
        std::cout << "wrong flag"<<std::endl;
        return EXIT_FAILURE;
    }
    Sflag.setTexture(flag);
    
    if (!tile_open.loadFromFile(resourcePath()+"tile_revealed.png")) {
        std::cout << "wrong title revelaed"<<std::endl;
        return EXIT_FAILURE;
    }
    Stile_O.setTexture(tile_open);
    
    if (!numb1.loadFromFile(resourcePath()+"number_1.png")) {
        std::cout << "wrong numb1"<<std::endl;
        return EXIT_FAILURE;
    }
    Snumb1.setTexture(numb1);
    
    if (!numb2.loadFromFile(resourcePath()+"number_2.png")) {
        std::cout << "wrong numb2"<<std::endl;
        return EXIT_FAILURE;
    }
    Snumb2.setTexture(numb2);
    
    if (!numb3.loadFromFile(resourcePath()+"number_3.png")) {
        std::cout << "wrong numb3"<<std::endl;
        return EXIT_FAILURE;
    }
    Snumb3.setTexture(numb3);
    
    if (!numb4.loadFromFile(resourcePath()+"number_4.png")) {
        std::cout << "wrong numb4"<<std::endl;
        return EXIT_FAILURE;
    }
    Snumb4.setTexture(numb4);
    
    if (!numb5.loadFromFile(resourcePath()+"number_5.png")) {
        std::cout << "wrong numb5"<<std::endl;
        return EXIT_FAILURE;
    }
    Snumb5.setTexture(numb5);
    
    if (!numb6.loadFromFile(resourcePath()+"number_6.png")) {
        std::cout << "wrong numb6"<<std::endl;
        return EXIT_FAILURE;
    }
    Snumb6.setTexture(numb6);
    
    if (!numb7.loadFromFile(resourcePath()+"number_7.png")) {
        std::cout << "wrong numb1"<<std::endl;
        return EXIT_FAILURE;
    }
    Snumb7.setTexture(numb7);
    
    if (!numb8.loadFromFile(resourcePath()+"number_8.png")) {
        std::cout << "wrong numb8"<<std::endl;
        return EXIT_FAILURE;
    }
    Snumb8.setTexture(numb8);
    
    setCoordinate( x2, y2);
    
};

sf::Sprite  Tile::getTile()
{
    return Stile;
}

sf::Sprite  Tile::getflag()
{
    return Sflag;
};

sf::Sprite Tile::getmines()
{
    return Smines;
};

sf::Sprite  Tile::getTile_O()
{
    return Stile_O;
};

sf::Sprite  Tile::getnumb1()
{
    return Snumb1;
}
sf::Sprite  Tile::getnumb2()
{
    return Snumb2;
};
sf::Sprite  Tile::getnumb3()
{
    return Snumb3;
};
sf::Sprite  Tile::getnumb4()
{
    return Snumb4;
};
sf::Sprite  Tile::getnumb5()
{
    return Snumb5;
};
sf::Sprite  Tile::getnumb6()
{
    return Snumb6;
};
sf::Sprite  Tile::getnumb7()
{
    return Snumb7;
};
sf::Sprite  Tile::getnumb8()
{
    return Snumb8;
};


void Tile::setCoordinate(float x2, float y2)
{
    x = x2;
    y = y2;
    Stile.setPosition(sf::Vector2f(x,y));
    Sflag.setPosition(sf::Vector2f(x,y));
    Smines.setPosition(sf::Vector2f(x,y));
    Stile_O.setPosition(sf::Vector2f(x,y));
    Snumb1.setPosition(sf::Vector2f(x,y));
    Snumb2.setPosition(sf::Vector2f(x,y));
    Snumb3.setPosition(sf::Vector2f(x,y));
    Snumb4.setPosition(sf::Vector2f(x,y));
    Snumb5.setPosition(sf::Vector2f(x,y));
    Snumb6.setPosition(sf::Vector2f(x,y));
    Snumb7.setPosition(sf::Vector2f(x,y));
    Snumb8.setPosition(sf::Vector2f(x,y));
};

sf::Sprite Tile::Status()
{
    if(hidden == false)
    {
        return getTile_O();
    }
    
    return getTile();
    
};

bool Tile::is_there_a_flag()
{
    //std::cout << "Is there a flag" << std::endl;
    return flaging;
}

void Tile::check()
{
    if(hidden == true)
    {
        hidden = false;
        actFlags();
        kabbom();
    }
};

bool Tile::precheck()
{
    //before ending checking, make sure the tile has been reveal already
    return hidden;
};

void Tile::boom(bool isthere) // set a boom in tile
{
    //std::cout << "bomb happen" << std::endl;
    //std::cout << "the bool is: " << isthere << std::endl;
    bomb = isthere;
};

bool Tile::Reviewboom() // set a boom in tile
{
    return bomb;
};



void Tile::kabbom() // is there a bomb in tile just pressesed?
{
    if(bomb == true)
    {
        std::cout << "Explosion" <<std::endl;
        active_bomb = true; // now the bomb has been active
    }else
    {
        std::cout << "safe" <<std::endl;
    }
    
};

bool Tile::safe()
{
    return active_bomb;
}

void Tile::actFlags()
{
    if(hidden == true)
    {
        if(flaging==false)
        {
            std::cout << "Now there is a flag" << std::endl;
            flaging = true;
        }
        else
        {
            std::cout << "Now there is NO a flag" << std::endl;
            flaging = false;
        }
    }
    else
    {
        flaging = false;
        std::cout << "No flag accepted" <<std::endl;
    }
};


void Tile::resetTilesetting()
{
    hidden = true;
    flaging = false;
    bomb = false;
    active_bomb = false;
}

