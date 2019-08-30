//
//  Controls.cpp
//  Project3_Minesweeper
//
//  Created by Jose Manuel Quintas on 4/12/19.
//  Copyright © 2019 Jose Manuel Quintas. All rights reserved.
//

#include "Controls.hpp"

#include "ResourcePath.hpp"



Controls::Controls()
{
    /*---------------------------------------------------------------*/
    //
    //          DEBUG & TEST
    //
    /*---------------------------------------------------------------*/
    if(!debug.loadFromFile(resourcePath()+ "debug.png"))
    {
        std::cout << "wrong debug revelaed"<<std::endl;
        return EXIT_FAILURE;
    }
    Sdebug.setTexture(debug);
    Sdebug.setPosition(sf::Vector2f(524.0f,512.0f));
    
    if(!test1.loadFromFile(resourcePath()+ "test_1.png"))
    {
        std::cout << "wrong test1 revelaed"<<std::endl;
        return EXIT_FAILURE;
    }
    Stest1.setTexture(test1);
    Stest1.setPosition(sf::Vector2f(588.0f,512.0f));
    
    if(!test2.loadFromFile(resourcePath()+ "test_2.png")) {
        std::cout << "wrong test2 revelaed"<<std::endl;
        return EXIT_FAILURE;
    }
    Stest2.setTexture(test2);
    Stest2.setPosition(sf::Vector2f(652.0f,512.0f));
    
    if(!test3.loadFromFile(resourcePath()+ "test_3.png"))
    {
        std::cout << "wrong test3 revelaed"<<std::endl;
        return EXIT_FAILURE;
    }
    Stest3.setTexture(test3);
    Stest3.setPosition(sf::Vector2f(716.0f,512.0f));
    
    /*---------------------------------------------------------------*/
    //
    //          FACES
    //
    /*---------------------------------------------------------------*/
    
    
    if(!Face_h.loadFromFile(resourcePath()+ "face_happy.png"))
    {
        std::cout << "wrong smiling face revelaed"<<std::endl;
        return EXIT_FAILURE;
    }
    SFace_h.setTexture(Face_h);
    SFace_h.setPosition(sf::Vector2f(368.0f,512.0f));
    
    if(!Face_l.loadFromFile(resourcePath()+ "face_lose.png"))
    {
        std::cout << "wrong loser face revelaed"<<std::endl;
        return EXIT_FAILURE;
    }
    SFace_l.setTexture(Face_l);
    SFace_l.setPosition(sf::Vector2f(368.0f,512.0f));
    
    if(!Face_w.loadFromFile(resourcePath()+ "face_win.png"))
    {
        std::cout << "wrong winner face revelaed"<<std::endl;
        return EXIT_FAILURE;
    }
    SFace_w.setTexture(Face_w);
    SFace_w.setPosition(sf::Vector2f(368.0f,512.0f));
    
    /*---------------------------------------------------------------*/
    //
    //          DIGITS 0,1,2,3,4,5,6,7,8,9,-
    //
    /*---------------------------------------------------------------*/
    if(!Dig0.loadFromFile(resourcePath()+ "digits.png", sf::IntRect(0,0,21,32)));
    SDig0.setTexture(Dig0);
    //SDig0.setPosition(sf::Vector2f(0.0f,512.0f));
    
    if(!Dig0_O.loadFromFile(resourcePath()+ "digits.png", sf::IntRect(0,0,21,32)));
    SDig0_O.setTexture(Dig0_O);
    SDig0_O.setPosition(sf::Vector2f(0.0f,512.0f));
    
    if(!Dig1.loadFromFile(resourcePath()+ "digits.png", sf::IntRect(21,0,21,32)));
    SDig1.setTexture(Dig1);
    //SDig1.setPosition(sf::Vector2f(21.0f,512.0f));
    
    if(!Dig2.loadFromFile(resourcePath()+ "digits.png", sf::IntRect(42,0,21,32)));
    SDig2.setTexture(Dig2);
    //SDig2.setPosition(sf::Vector2f(21.0f,512.0f));
    
    if(!Dig3.loadFromFile(resourcePath()+ "digits.png", sf::IntRect(63,0,21,32)));
    SDig3.setTexture(Dig3);
    
    if(!Dig4.loadFromFile(resourcePath()+ "digits.png", sf::IntRect(84,0,21,32)));
    SDig4.setTexture(Dig4);
    
    if(!Dig5.loadFromFile(resourcePath()+ "digits.png", sf::IntRect(105,0,21,32)));
    SDig5.setTexture(Dig5);
    
    if(!Dig6.loadFromFile(resourcePath()+ "digits.png", sf::IntRect(126,0,21,32)));
    SDig6.setTexture(Dig6);
    
    if(!Dig7.loadFromFile(resourcePath()+ "digits.png", sf::IntRect(147,0,21,32)));
    SDig7.setTexture(Dig7);
    
    if(!Dig8.loadFromFile(resourcePath()+ "digits.png", sf::IntRect(168,0,21,32)));
    SDig8.setTexture(Dig8);
    
    if(!Dig9.loadFromFile(resourcePath()+ "digits.png", sf::IntRect(189,0,21,32)));
    SDig9.setTexture(Dig9);
    
    if(!Digsymbol.loadFromFile(resourcePath()+ "digits.png", sf::IntRect(210,0,21,32)));
    SDigsymbol.setTexture(Digsymbol);
    SDigsymbol.setPosition(sf::Vector2f(0.0f,512.0f));
    SDigsymbol_O.setTexture(Digsymbol);
    
    
};


/*---------------------------------------------------------------*/
//
//          DEBUG & TEST
//
/*---------------------------------------------------------------*/
sf::Sprite Controls::getdebug()
{
    return Sdebug;
}
sf::Sprite Controls::getTest1()
{
    return Stest1;
};
sf::Sprite Controls::getTest2()
{
    return Stest2;
};
sf::Sprite Controls::getTest3()
{
    return Stest3;
};
/*---------------------------------------------------------------*/
//
//          DIGITS 0,1,2,3,4,5,6,7,8,9,-
//
/*---------------------------------------------------------------*/
sf::Sprite Controls::getDig0()
{
    return SDig0;
};
sf::Sprite Controls::getDig1()
{
    return SDig1;
};
sf::Sprite Controls::getDig0_O()
{
    return SDig0_O;
};
sf::Sprite Controls::getDig2()
{
    return SDig2;
};
sf::Sprite Controls::getDig3()
{
    return SDig3;
};
sf::Sprite Controls::getDig4()
{
    return SDig4;
};
sf::Sprite Controls::getDig5()
{
    return SDig5;
};
sf::Sprite Controls::getDig6()
{
    return SDig6;
};
sf::Sprite Controls::getDig7()
{
    return SDig7;
};
sf::Sprite Controls::getDig8()
{
    return SDig8;
};
sf::Sprite Controls::getDig9()
{
    return SDig9;
};
sf::Sprite Controls::getDigsymbol()
{
    return SDigsymbol;
};

sf::Sprite Controls::Bring_Digit(int &i, float x, float y)
{
    int k =i;
    switch (k) {
        case 0:
            SDig0.setPosition(sf::Vector2f(x,y));
            return getDig0();
            break;
            //
            // case 1: seem not to be working, the reason is unknow, I had to take it out of switch
        case 2:
            SDig2.setPosition(sf::Vector2f(x,y));
            return getDig2();
            break;
        case 3:
            SDig3.setPosition(sf::Vector2f(x,y));
            return getDig3();
            break;
        case 4:
            SDig4.setPosition(sf::Vector2f(x,y));
            return getDig4();
            break;
        case 5:
            SDig5.setPosition(sf::Vector2f(x,y));
            return getDig5();
            break;
        case 6:
            SDig6.setPosition(sf::Vector2f(x,y));
            return getDig6();
            break;
        case 7:
            SDig7.setPosition(sf::Vector2f(x,y));
            return getDig7();
            break;
        case 8:
            SDig8.setPosition(sf::Vector2f(x,y));
            return getDig8();
            break;
        case 9:
            SDig9.setPosition(sf::Vector2f(x,y));
            return getDig9();
            break;
        default:
            break;
    }
    SDigsymbol_O.setPosition(x, y);
    return SDigsymbol_O;
};

/*---------------------------------------------------------------*/
//
//          FACES
//
/*---------------------------------------------------------------*/
sf::Sprite Controls::getFace_h()
{
    return SFace_h;
};
sf::Sprite Controls::getFace_l()
{
    return SFace_l;
};
sf::Sprite Controls::getFace_w()
{
    return SFace_w;
};

