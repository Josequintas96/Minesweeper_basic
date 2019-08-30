//
//  Controls.hpp
//  Project3_Minesweeper
//
//  Created by Jose Manuel Quintas on 4/12/19.
//  Copyright © 2019 Jose Manuel Quintas. All rights reserved.
//

#ifndef Controls_hpp
#define Controls_hpp

#include <stdio.h>
#include <iomanip>
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

class Controls {
public:
    Controls();
    
    sf::Sprite getdebug();
    sf::Sprite getTest1();
    sf::Sprite getTest2();
    sf::Sprite getTest3();
    
    sf::Sprite getFace_h();
    sf::Sprite getFace_l();
    sf::Sprite getFace_w();
    
    //16.Digit 0
    sf::Texture Dig0;
    sf::Sprite SDig0;
    
    //17.Digit 1
    sf::Texture Dig1;
    sf::Sprite SDig1;
    
    /*---------------------------------------------------------------*/
    //
    //         return any of sprites
    //
    /*---------------------------------------------------------------*/
    sf::Sprite getDig0();
    sf::Sprite getDig0_O();
    sf::Sprite getDig1();
    sf::Sprite getDig2();
    sf::Sprite getDig3();
    sf::Sprite getDig4();
    sf::Sprite getDig5();
    sf::Sprite getDig6();
    sf::Sprite getDig7();
    sf::Sprite getDig8();
    sf::Sprite getDig9();
    sf::Sprite getDigsymbol();
    sf::Sprite Bring_Digit(int &i, float x, float y);
    
    
private:
    //elements Part 2
    //9. debug
    sf::Texture debug;
    sf::Sprite Sdebug;
    
    //10.test 1
    sf::Texture test1;
    sf::Sprite Stest1;
    
    //11.test 2
    sf::Texture test2;
    sf::Sprite Stest2;
    
    //12.test 3
    sf::Texture test3;
    sf::Sprite Stest3;
    
    //13.Face Happy
    sf::Texture Face_h;
    sf::Sprite SFace_h;
    
    //14.Face lose
    sf::Texture Face_l;
    sf::Sprite SFace_l;
    
    //14.Face win
    sf::Texture Face_w;
    sf::Sprite SFace_w;
    
    
    
    //16.5.Digit 0-omega
    sf::Texture Dig0_O;
    sf::Sprite SDig0_O;
    
    
    //18.Digit 2
    sf::Texture Dig2;
    sf::Sprite SDig2;
    
    //19.Digit 3
    sf::Texture Dig3;
    sf::Sprite SDig3;
    
    //20.Digit 4
    sf::Texture Dig4;
    sf::Sprite SDig4;
    
    //21.Digit 5
    sf::Texture Dig5;
    sf::Sprite SDig5;
    
    //22.Digit 6
    sf::Texture Dig6;
    sf::Sprite SDig6;
    
    //23.Digit 7
    sf::Texture Dig7;
    sf::Sprite SDig7;
    
    //24.Digit 8
    sf::Texture Dig8;
    sf::Sprite SDig8;
    
    //25.Digit 9
    sf::Texture Dig9;
    sf::Sprite SDig9;
    
    //26.Digit symbol
    sf::Texture Digsymbol;
    sf::Sprite SDigsymbol;
    sf::Sprite SDigsymbol_O;
    //sf::Sprite SDigsymbol_M;
    
    
};


#endif /* Controls_hpp */
