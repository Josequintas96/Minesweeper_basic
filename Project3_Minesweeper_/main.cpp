
//
// Disclaimer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resources, use the helper
// function `resourcePath()` from ResourcePath.hpp
//
#include "ResourcePath.hpp"

#include <iomanip>
#include <iostream>
#include <vector>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Tile.hpp"
#include "Board.hpp"
#include "Controls.hpp"



void GPS(int x, int y, Board &mapM, int version, bool &actDebug, bool &face, bool &win); // mre important method, where action is been taken, which action should be taken

int main(int, char const**)
{
    bool act_debug = false; //if the debug option open?? false mean no
    bool game = true; // game continue; if false, then a mines a been pressed
    bool gameW = false; // game continue; if true, then you have win
    //int tile_num = 400;
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Minesweeper");
    
         //Set the Icon
        sf::Image icon;
        if (!icon.loadFromFile(resourcePath() + "mine_icon.png")) {
            return EXIT_FAILURE;
        }
        window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    
    
    Board plan;
    
    
    
    // Start the game loop
    while (window.isOpen())
    {
        // Process events - right click, or left click
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    std::cout << "the right button was pressed" << std::endl;
                    std::cout << "mouse x: " << event.mouseButton.x << std::endl;
                    int x =event.mouseButton.x;
                    std::cout << "mouse y: " << event.mouseButton.y << std::endl;
                    int y =event.mouseButton.y;
                    GPS(x,y, plan, 1, act_debug, game, gameW);//1 mean left buttom, in other words, select
                }
                else
                    if (event.mouseButton.button == sf::Mouse::Right)
                    {
                        std::cout << "the Flag button was pressed" << std::endl;
                        std::cout << "mouse x: " << event.mouseButton.x << std::endl;
                        int x =event.mouseButton.x;
                        std::cout << "mouse y: " << event.mouseButton.y << std::endl;
                        int y =event.mouseButton.y;
                        GPS(x,y, plan, 2, act_debug, game, gameW); // 2 mean right buttom, in other words, a flag
                    }
            }
            
            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
        }
        
        // Clear screen
        window.clear();
        
        
        /*---------------------------------------------------------------*/
        //
        //          Draw Tiles and neighboor
        //
        /*---------------------------------------------------------------*/
        for(int i=0; i<400; i++)
            window.draw(plan.printPiece(i));
        
        std::vector<int> numb;
        plan.findnumb1(numb);
        for(int i=0; i<numb.size(); i++)
        {
            window.draw(plan.printnumb1(numb.at(i)));
        }
        plan.findnumb2(numb);
        for(int i=0; i<numb.size(); i++)
        {
            window.draw(plan.printnumb2(numb.at(i)));
        }
        plan.findnumb3(numb);
        for(int i=0; i<numb.size(); i++)
        {
            window.draw(plan.printnumb3(numb.at(i)));
        }
        plan.findnumb4(numb);
        for(int i=0; i<numb.size(); i++)
        {
            window.draw(plan.printnumb4(numb.at(i)));
        }
        plan.findnumb5(numb);
        for(int i=0; i<numb.size(); i++)
        {
            window.draw(plan.printnumb5(numb.at(i)));
        }
        plan.findnumb6(numb);
        for(int i=0; i<numb.size(); i++)
        {
            window.draw(plan.printnumb6(numb.at(i)));
        }
        plan.findnumb7(numb);
        for(int i=0; i<numb.size(); i++)
        {
            window.draw(plan.printnumb7(numb.at(i)));
        }
        plan.findnumb8(numb);
        for(int i=0; i<numb.size(); i++)
        {
            window.draw(plan.printnumb8(numb.at(i)));
        }
        
        
        
        /*---------------------------------------------------------------*/
        //
        //          Draw mines
        //
        /*---------------------------------------------------------------*/
        int p = 0;
        if(plan.board_kaboom(p)==true)
        {
            window.draw(plan.Printmine(p));
            window.draw(plan.printFace_l());
            game =false;
        }
        else
        {
            window.draw(plan.printFace_h());
        }
        
        if(act_debug ==true || game == false)
        {
            for(int k =0; k< plan.Bobs.size(); k++)
            {
                window.draw(plan.Printmine(plan.Bobs.at(k)));
            }
        }
        //window.draw(piece.getTile());
        // Draw the string
        //window.draw(text);
        
        /*---------------------------------------------------------------*/
        //
        //          Print the Controls
        //
        /*---------------------------------------------------------------*/
        window.draw(plan.printDebug()); // print the reveal mind
        window.draw(plan.printTest1());
        window.draw(plan.printTest2());
        window.draw(plan.printTest3());
        
        if(plan.returnTiles() ==0)
        {
            window.draw(plan.printFace_w());
        }
        
        /*---------------------------------------------------------------*/
        //
        //          Draw flags
        //
        /*---------------------------------------------------------------*/
        std::vector<int> goo;
        plan.findflag(goo);
        int totalflags;
        if(plan.returnTiles() >0) // as long is greater than zero, if there exist a flag somewhere, lets add it
        {
            for(int i=0; i<goo.size(); i++)
            {
                window.draw(plan.showflag(goo.at(i)));
            }
            totalflags = plan.returnMines() - goo.size();
        }
        else
        {
            //you have won, let set a flag on all bombs
            for(int k =0; k< plan.Bobs.size(); k++)
            {
                window.draw(plan.showflag(plan.Bobs.at(k)));
            }
            gameW = true;
            totalflags = 0;
        }
        
        /*---------------------------------------------------------------*/
        //
        //         Counter of numbers of reaminig flags on the board
        //
        /*---------------------------------------------------------------*/
        if(totalflags >=0)
        {
            window.draw(plan.printDig0_O()); //0 omega
        }
        else
        {
            totalflags = (-1)*totalflags;
            window.draw(plan.printDigsymbol()); //0 omega
        }
        //totalflags = 15;
        window.draw(plan.choiceDigits1(totalflags));
        window.draw(plan.choiceDigits2(totalflags));
        //std::cout << "Numbers of flags: " << totalflags <<std::endl;
        
        
        // Update the window
        window.display();
        
    }
    
    return EXIT_SUCCESS;
}


void GPS(int x, int y, Board &mapM, int version, bool &actDebug, bool &face, bool &win)
{
    
    int hor = float(x)/32 + 1;
    
    int ver = float(y)/32 + 1;
    std::cout << "Graph x: " << hor << "__y: " << ver <<std::endl;
    
    //    for(int x1=0; x1<40; x1++)
    //        std::cout << x1 << ". " << mapM.board.at(x1)->hidden << std::endl;
    //
    
    if(version ==1)
    {
        if(face == true && win == false ) //you haven win nor press a mine
        {
            mapM.open(hor,ver);
            
            if((x>=588 && x<652) && (y>512 && y<576)) //press test1
            {
                std::cout << "test 1 happen " << std::endl;
                int i =1;
                mapM.ResetBoard(i);
                std::cout << "Number of bombs " << mapM.Bobs.size()<< std::endl;
                
            }
            
            if((x>652 && x<716) && (y>512 && y<576)) //press test2
            {
                int i =2;
                mapM.ResetBoard(i);
                std::cout << "Number of bombs " << mapM.Bobs.size()<< std::endl;
            }
            
            if((x>716 && x<780) && (y>512 && y<576)) // press test3
            {
                std::cout << "test 3 happen " << std::endl;
                int i =3;
                mapM.ResetBoard(i);
                std::cout << "Number of bombs " << mapM.Bobs.size()<< std::endl;
            }
        }
        if((x>524 && x<588) && (y>512 && y<576))//press Debug
        {
            if(actDebug==false)
            {
                actDebug = true;
            }
            else
            {
                actDebug = false;
            }
        }
        
        
        //press a face
        if((x>368 && x<432) && (y>512 && y<576)) //test3
        {
            std::cout << "Face is presses " << std::endl;
            int i =0;
            mapM.ResetBoard(i);
            face = true;
            win = false;
        }
        
        
    }
    if(face ==true && win == false) //
    {
        if(version == 2)
        {
            mapM.putflag(hor, ver);
        }
    }
    std::cout << "number of tiles: " << mapM.returnTiles() << std::endl;
    std::cout << std::endl;
}
