//
//  Board.cpp
//  Project3_Minesweeper
//
//  Created by Jose Manuel Quintas on 4/12/19.
//  Copyright © 2019 Jose Manuel Quintas. All rights reserved.
//

#include "Board.hpp"
#include "ResourcePath.hpp"

Board::Board()
{
    float x=0.0f;
    float y = 0.0f;
    int horizontal = 0;
    
    for(int i=0; i<400; i++)
    {
        Tile *piece = new Tile;
        piece->setCoordinate(x,y);
        x +=32.0f;
        horizontal++;
        if(horizontal == 25)
        {
            horizontal = 0;
            x=0.0f;
            y +=32.0f;
        }
        board.push_back(piece);
    }
    //    int i =0;
    
    //    filling(i);
    //    setboom(5, true);
    //    Bobs.push_back(5);
    //
    //    setboom(9, true);
    //    Bobs.push_back(9);
    //
    //    setboom(399, true);
    //    Bobs.push_back(399);
    //    total_mines =3;
    //    total_tiles = 400-3;
    randomboomgenerator();
};


void Board::filling(int &i)
{
    std::ifstream file;
    total_mines =0;
    if(i==1)
    {
        file.open(resourcePath()+"boards/testboard1.brd", std::ios_base::binary);
    }
    if(i==2)
    {
        file.open(resourcePath()+"boards/testboard2.brd", std::ios_base::binary);
    }
    if(i==3)
    {
        file.open(resourcePath()+"boards/testboard3.brd", std::ios_base::binary);
    }
    
    if(file.is_open()) {
        int t;
        int count =0;
        Bobs.clear();
        
        for (int j = 0; j < 16; j++)
        {
            //std::cout << j+1 << ". round" << std::endl;
            for (int i = 0; i < 25; i++) {
                t=0;
                file.read((char *)&t, 1);
                t = t-48;
                if(t==1)
                {
                    setboom(count, true);//there is a bomb
                    Bobs.push_back(count);
                    total_mines++;
                }
                //std::cout << "read: " << t << std::endl;
                //board.at(count)->boom(t);
                count++;
            }
            short tt;
            file.read((char *) &tt, 2);
            //std::cout << std::endl;
        }
        file.close();
        total_tiles = 400-total_mines;
    }
};

Board::~Board()
{
    for(int i=0; i<board.size(); i++)
    {
        delete board[i];
    }
    board.clear();
};


void Board::ResetBoard(int &option)
{
    //    for(int i=0; i<board.size(); i++)
    //    {
    //        delete board[i];
    //    }
    //    board.clear();
    
    for(int i=0; i<board.size(); i++)
    {
        board.at(i)->resetTilesetting();
    }
    
    Bobs.clear();
    neigboor1.clear();
    neigboor2.clear();
    neigboor3.clear();
    neigboor4.clear();
    neigboor5.clear();
    neigboor6.clear();
    neigboor7.clear();
    neigboor8.clear();
    
    float x=0.0f;
    float y = 0.0f;
    int horizontal = 0;
    
    //    for(int i=0; i<400; i++)
    //    {
    //        Tile *piece = new Tile;
    //        piece->setCoordinate(x,y);
    //        x +=32.0f;
    //        horizontal++;
    //        if(horizontal == 25)
    //        {
    //            horizontal = 0;
    //            x=0.0f;
    //            y +=32.0f;
    //        }
    //     board.push_back(piece);
    //    }
    if(option ==1)
    {
        filling(option);
    }
    else
        if(option ==2)
        {
            filling(option);
        }
        else
            if(option ==3)
            {
                filling(option);
            }
            else{
                //            setboom(5, true);
                //            Bobs.push_back(5);
                //
                //            setboom(9, true);
                //            Bobs.push_back(9);
                //
                //            setboom(399, true);
                //            Bobs.push_back(399);
                //            total_mines = 3;
                //            total_tiles = 400-total_mines;
                randomboomgenerator();
            }
    
}


//Print board
//option1: piece by piece
sf::Sprite Board::printPiece(int x)
{
    return board.at(x)->Status();
};

void Board::findflag(std::vector<int> &flagcount)
{
    flagcount.clear();
    for(int i =0; i<400; i++)
    {
        
        if(board.at(i)->is_there_a_flag() == true)
        {
            flagcount.push_back(i);
        }
    }
}

void Board::randomboomgenerator()
{
    
    Bobs.clear(); //clear all the previous location of the bobs
    total_mines =0;
    
    int v1 = rand() %400; //ceate a new location
    setboom(v1, true); //set boom at location as true -> there is a bomb
    Bobs.push_back(v1); //save location
    //total_mines++;
    
    std::vector <int> random;
    bool true_random = true;
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // set initial seed value to system clock
    int t =0;
    int to =0;
    while(random.size() != 50)
    {
        //std::cout << t << " position " << to <<" random v1: " << v1 <<std::endl;
        for(int k =0; k<random.size(); k++)
        {
            if(v1 == random.at(k))
            {
                true_random = false;
                break;
            }
            t++;
        }
        if(true_random == true)
        {
            random.push_back(v1);
            to++;
            setboom(v1, true); //set boom at location as true -> there is a bomb
            Bobs.push_back(v1); //save location
            total_mines++;
            
        }
        v1 = rand() %400;
        true_random = true;
        t++;
    }
    
    total_tiles = 400-total_mines;
    //std :: cout << "total tiles " << total_tiles <<std::endl;
    //std :: cout << "total mines " << total_mines <<std::endl;
}

sf::Sprite Board::showflag(int x)
{
    return board.at(x)->getflag();
};


void Board::open(int x, int y)
{
    y = y-1;
    int location = (x + y*25)-1;
    std::cout << "Location: " << location <<std::endl;
    if(location<400)
    {
        preopen(location);
        
        //        board.at(location)->check();
        //        findneighboor(location);
    }
    //    std::cout << "Check happen: " << board.at(location)->hidden <<std::endl;
}

void Board::preopen(int &loc)
{
    if (board.at(loc)->precheck()==true )
    {
        
        std::cout << "Check happen " << std::endl;
        if(board.at(loc)->is_there_a_flag() == false)
        {
            board.at(loc)->check();
            if(board.at(loc)->Reviewboom() == false)
            {
                findneighboor(loc);
            }
            total_tiles--;
        }
        else
        {
            std::cout  << "Can't be reveal, there is a flag" <<std::endl;
        }
    }
    else
    {
        std::cout  << "it is already reveal" <<std::endl;
    }
    
}


void Board::findneighboor(int &loc)
{
    int mines =0;
    if(loc < 25)
    {
        if(loc==0)
        {
            std::cout<<"number of neighbors is 3" <<std::endl;
            if(board.at(loc+1)->Reviewboom()==true)
            {
                mines++;
            }
            if(board.at(loc+25)->Reviewboom() == true)
            {
                mines++;
            }
            if(board.at(loc+26)->Reviewboom() == true)
            {
                mines++;
            }
            
            //first round - 3N
            if(mines ==0)
            {
                std::cout << "Open neighbor happen" <<std::endl;
                int location = loc+1;
                preopen(location);
                location = loc+25;
                preopen(location);
                location = loc+26;
                preopen(location);
            }
        }else
            if(loc==24)
            {
                std::cout<<"number of neighbors is 3" <<std::endl;
                if(board.at(loc-1)->Reviewboom()==true)
                {
                    mines++;
                }
                if(board.at(loc+25)->Reviewboom() == true)
                {
                    mines++;
                }
                if(board.at(loc+24)->Reviewboom() == true)
                {
                    mines++;
                }
                
                //second round - 3N
                if(mines ==0)
                {
                    std::cout << "Open neighbor happen" <<std::endl;
                    int location = loc-1;
                    preopen(location);
                    location = loc+25;
                    preopen(location);
                    location = loc+24;
                    preopen(location);
                }
            }
            else
            {
                std::cout<<"number of neighbors is 5" <<std::endl;
                if(board.at(loc-1)->Reviewboom()==true)
                {
                    std::cout<<"back ";
                    mines++;
                }
                if(board.at(loc+1)->Reviewboom()==true)
                {
                    std::cout<<"next ";
                    mines++;
                }
                if(board.at(loc+25)->Reviewboom() == true)
                {
                    std::cout<<"bellow ";
                    mines++;
                }
                if(board.at(loc+26)->Reviewboom() == true)
                {
                    std::cout<<"below+next ";
                    mines++;
                }
                if(board.at(loc+24)->Reviewboom()==true)
                {
                    std::cout<<"bellow+back ";
                    mines++;
                }
                
                //third round -5N
                if(mines ==0)
                {
                    std::cout << "Open neighbor happen" <<std::endl;
                    int location = loc-1;
                    preopen(location);
                    location = loc+1;
                    preopen(location);
                    location = loc+25;
                    preopen(location);
                    location = loc+26;
                    preopen(location);
                    location = loc+24;
                    preopen(location);
                }
            }
        std::cout<<"there exist: " << mines << " mines." << std::endl;
    }
    else if(loc>=25 && loc<375)
    {
        if(loc%25 ==0)
        {
            std::cout<<"number of neighbors is 5" <<std::endl;
            if(board.at(loc-25)->Reviewboom()==true)
            {
                std::cout<<"above ";
                mines++;
            }
            if(board.at(loc-24)->Reviewboom()==true)
            {
                std::cout<<"above+next ";
                mines++;
            }
            if(board.at(loc+1)->Reviewboom()==true)
            {
                std::cout<<"next ";
                mines++;
            }
            if(board.at(loc+25)->Reviewboom() == true)
            {
                std::cout<<"bellow ";
                mines++;
            }
            if(board.at(loc+26)->Reviewboom() == true)
            {
                std::cout<<"bellow+next ";
                mines++;
            }
            
            
            //fourth round -5N
            if(mines ==0)
            {
                std::cout << "Open neighbor happen" <<std::endl;
                int location = loc-25;
                preopen(location);
                location = loc-24;
                preopen(location);
                location = loc+1;
                preopen(location);
                location = loc+25;
                preopen(location);
                location = loc+26;
                preopen(location);
            }
        }
        else
            if(loc%25 == 24)
            {
                std::cout<<"number of neighbors is 5" <<std::endl;
                if(board.at(loc-25)->Reviewboom()==true)
                {
                    std::cout<<"above ";
                    mines++;
                }
                if(board.at(loc-26)->Reviewboom()==true)
                {
                    std::cout<<"above+back ";
                    mines++;
                }
                if(board.at(loc-1)->Reviewboom()==true)
                {
                    std::cout<<"back ";
                    mines++;
                }
                if(board.at(loc+24)->Reviewboom() == true)
                {
                    std::cout<<"bellow+back ";
                    mines++;
                }
                if(board.at(loc+25)->Reviewboom() == true)
                {
                    std::cout<<"bellow ";
                    mines++;
                }
                
                
                //fifth round -5N
                if(mines ==0)
                {
                    std::cout << "Open neighbor happen" <<std::endl;
                    int location = loc-25;
                    preopen(location);
                    location = loc-26;
                    preopen(location);
                    location = loc-1;
                    preopen(location);
                    location = loc+24;
                    preopen(location);
                    location = loc+25;
                    preopen(location);
                }
            }
            else
            {
                std::cout<<"number of neighbors is 8" <<std::endl;
                if(board.at(loc-1)->Reviewboom()==true)
                {
                    std::cout<<"back ";
                    mines++;
                }
                if(board.at(loc-26)->Reviewboom()==true)
                {
                    std::cout<<"above+back ";
                    mines++;
                }
                if(board.at(loc-25)->Reviewboom()==true)
                {
                    std::cout<<"above ";
                    mines++;
                }
                if(board.at(loc-24)->Reviewboom()==true)
                {
                    std::cout<<"above+next ";
                    mines++;
                }
                if(board.at(loc+1)->Reviewboom()==true)
                {
                    std::cout<<"next ";
                    mines++;
                }
                if(board.at(loc+26)->Reviewboom() == true)
                {
                    std::cout<<"bellow+next ";
                    mines++;
                }
                if(board.at(loc+25)->Reviewboom() == true)
                {
                    std::cout<<"bellow ";
                    mines++;
                }
                if(board.at(loc+24)->Reviewboom() == true)
                {
                    std::cout<<"bellow+back ";
                    mines++;
                }
                
                
                //sixth round -6N
                if(mines ==0)
                {
                    std::cout << "Open neighbor happen" <<std::endl;
                    int location = loc-1;
                    preopen(location);
                    location = loc-26;
                    preopen(location);
                    location = loc-25;
                    preopen(location);
                    location = loc-24;
                    preopen(location);
                    location = loc+1;
                    preopen(location);
                    location = loc+26;
                    preopen(location);
                    location = loc+25;
                    preopen(location);
                    location = loc+24;
                    preopen(location);
                }
            }
        std::cout<<"there exist: " << mines << " mines." << std::endl;
    }
    else
        if(loc>=375 && loc <=399)
        {
            if(loc==375)
            {
                std::cout<<"number of neighbors is 3" <<std::endl;
                if(board.at(loc+1)->Reviewboom()==true)
                {
                    std::cout<<"next ";
                    mines++;
                }
                if(board.at(loc-25)->Reviewboom() == true)
                {
                    std::cout<<"above ";
                    mines++;
                }
                if(board.at(loc-24)->Reviewboom() == true)
                {
                    std::cout<<"above+next ";
                    mines++;
                }
                
                //seveth round - 3N
                if(mines ==0)
                {
                    std::cout << "Open neighbor happen" <<std::endl;
                    int location = loc+1;
                    preopen(location);
                    location = loc-25;
                    preopen(location);
                    location = loc-24;
                    preopen(location);
                }
            }else
                if(loc==399)
                {
                    std::cout<<"number of neighbors is 3" <<std::endl;
                    if(board.at(loc-1)->Reviewboom()==true)
                    {
                        std::cout<<"back ";
                        mines++;
                    }
                    if(board.at(loc-25)->Reviewboom() == true)
                    {
                        std::cout<<"above ";
                        mines++;
                    }
                    if(board.at(loc-26)->Reviewboom() == true)
                    {
                        std::cout<<"above+back ";
                        mines++;
                    }
                    
                    
                    //eigth round - 3N
                    if(mines ==0)
                    {
                        std::cout << "Open neighbor happen" <<std::endl;
                        int location = loc-1;
                        preopen(location);
                        location = loc-25;
                        preopen(location);
                        location = loc-26;
                        preopen(location);
                    }
                }
                else
                {
                    std::cout<<"number of neighbors is 5" <<std::endl;
                    if(board.at(loc-1)->Reviewboom()==true)
                    {
                        std::cout<<"back ";
                        mines++;
                    }
                    if(board.at(loc-26)->Reviewboom()==true)
                    {
                        std::cout<<"above+back ";
                        mines++;
                    }
                    if(board.at(loc-25)->Reviewboom()==true)
                    {
                        std::cout<<"above ";
                        mines++;
                    }
                    if(board.at(loc-24)->Reviewboom() == true)
                    {
                        std::cout<<"above+next ";
                        mines++;
                    }
                    if(board.at(loc+1)->Reviewboom() == true)
                    {
                        std::cout<<"next ";
                        mines++;
                    }
                    
                    //ninth round - 5N
                    if(mines ==0)
                    {
                        std::cout << "Open neighbor happen" <<std::endl;
                        int location = loc-1;
                        preopen(location);
                        location = loc-26;
                        preopen(location);
                        location = loc-25;
                        preopen(location);
                        location = loc-24;
                        preopen(location);
                        location = loc+1;
                        preopen(location);
                    }
                }
            std::cout<<"there exist: " << mines << " mines." << std::endl;
        }
    markneigbor(mines, loc);
};

void Board::markneigbor(int &neigh, int &loc)
{
    switch(neigh)
    {
        case 1:
        {
            neigboor1.push_back(loc);
            break;
        }
        case 2:
        {
            neigboor2.push_back(loc);
            break;
        }
        case 3:
        {
            neigboor3.push_back(loc);
            break;
        }
        case 4:
        {
            neigboor4.push_back(loc);
            break;
        }
        case 5:
        {
            neigboor5.push_back(loc);
            break;
        }
        case 6:
        {
            neigboor6.push_back(loc);
            break;
        }
        case 7:
        {
            neigboor7.push_back(loc);
            break;
        }
        case 8:
        {
            neigboor8.push_back(loc);
            break;
        }
        default:
            break;
            
    }
}

void Board::findnumb1(std::vector<int> &numb1)
{
    numb1.clear();
    
    int k = neigboor1.size();
    //    if(k ==0)
    //    {
    //        std::cout << "neigboor 1 = 0 happen " <<std::endl;
    //        neigboor1.push_back(0);
    //    }
    
    //std::cout << "find numb1 happen: " << neigboor1.size() << " and " << k <<std::endl;
    if(k > 0)
    {
        //std::cout << "why?? " <<std::endl;
        for(int i =0; i<neigboor1.size(); i++)
        {
            //std::cout << "why?? " <<std::endl;
            numb1.push_back(neigboor1.at(i));
        }
    }
}
sf::Sprite Board::printnumb1(int &loc)
{
    return board.at(loc)->getnumb1();
}

void Board::findnumb2(std::vector<int> &numb1)
{
    numb1.clear();
    
    int k = neigboor2.size();
    //    if(k ==0)
    //    {
    //        std::cout << "neigboor 2 = 0 happen " <<std::endl;
    //        neigboor2.push_back(0);
    //    }
    
    //std::cout << "find numb1 happen: " << neigboor1.size() << " and " << k <<std::endl;
    if(k > 0)
    {
        //std::cout << "why?? " <<std::endl;
        for(int i =0; i<neigboor2.size(); i++)
        {
            //std::cout << "why?? " <<std::endl;
            numb1.push_back(neigboor2.at(i));
        }
    }
}
sf::Sprite Board::printnumb2(int &loc)
{
    return board.at(loc)->getnumb2();
}

void Board::findnumb3(std::vector<int> &numb1)
{
    numb1.clear();
    
    int k = neigboor3.size();
    //    if(k ==0)
    //    {
    //        std::cout << "neigboor 3 = 0 happen " <<std::endl;
    //        neigboor3.push_back(0);
    //    }
    
    //std::cout << "find numb1 happen: " << neigboor1.size() << " and " << k <<std::endl;
    if(k > 0)
    {
        //std::cout << "why?? " <<std::endl;
        for(int i =0; i<neigboor3.size(); i++)
        {
            //std::cout << "why?? " <<std::endl;
            numb1.push_back(neigboor3.at(i));
        }
    }
}
sf::Sprite Board::printnumb3(int &loc)
{
    return board.at(loc)->getnumb3();
}

void Board::findnumb4(std::vector<int> &numb1)
{
    numb1.clear();
    
    int k = neigboor4.size();
    //if(k ==0)
    //{
    //std::cout << "neigboor 3 = 0 happen " <<std::endl;
    //  neigboor4.push_back(0);
    //}
    
    //std::cout << "find numb1 happen: " << neigboor1.size() << " and " << k <<std::endl;
    if(k > 0)
    {
        //std::cout << "why?? " <<std::endl;
        for(int i =0; i<neigboor4.size(); i++)
        {
            //std::cout << "why?? " <<std::endl;
            numb1.push_back(neigboor4.at(i));
        }
    }
}
sf::Sprite Board::printnumb4(int &loc)
{
    return board.at(loc)->getnumb4();
}

void Board::findnumb5(std::vector<int> &numb1)
{
    numb1.clear();
    
    int k = neigboor5.size();
    //    if(k ==0)
    //    {
    //        std::cout << "neigboor 3 = 0 happen " <<std::endl;
    //        neigboor5.push_back(0);
    //    }
    
    //std::cout << "find numb1 happen: " << neigboor1.size() << " and " << k <<std::endl;
    if(k > 0)
    {
        //std::cout << "why?? " <<std::endl;
        for(int i =0; i<neigboor5.size(); i++)
        {
            //std::cout << "why?? " <<std::endl;
            numb1.push_back(neigboor5.at(i));
        }
    }
}
sf::Sprite Board::printnumb5(int &loc)
{
    return board.at(loc)->getnumb5();
}

void Board::findnumb6(std::vector<int> &numb1)
{
    numb1.clear();
    
    int k = neigboor6.size();
    //    if(k ==0)
    //    {
    //        std::cout << "neigboor 3 = 0 happen " <<std::endl;
    //        neigboor6.push_back(0);
    //    }
    
    //std::cout << "find numb1 happen: " << neigboor1.size() << " and " << k <<std::endl;
    if(k > 0)
    {
        //std::cout << "why?? " <<std::endl;
        for(int i =0; i<neigboor6.size(); i++)
        {
            //std::cout << "why?? " <<std::endl;
            numb1.push_back(neigboor6.at(i));
        }
    }
}

void Board::findnumb7(std::vector<int> &numb1)
{
    numb1.clear();
    
    int k = neigboor7.size();
    //    if(k ==0)
    //    {
    //        std::cout << "neigboor 3 = 0 happen " <<std::endl;
    //        neigboor7.push_back(0);
    //    }
    
    //std::cout << "find numb1 happen: " << neigboor1.size() << " and " << k <<std::endl;
    if(k > 0)
    {
        //std::cout << "why?? " <<std::endl;
        for(int i =0; i<neigboor7.size(); i++)
        {
            //std::cout << "why?? " <<std::endl;
            numb1.push_back(neigboor7.at(i));
        }
    }
}
sf::Sprite Board::printnumb7(int &loc)
{
    return board.at(loc)->getnumb7();
}

void Board::findnumb8(std::vector<int> &numb1)
{
    numb1.clear();
    
    int k = neigboor8.size();
    //    if(k ==0)
    //    {
    //        std::cout << "neigboor 3 = 0 happen " <<std::endl;
    //        neigboor8.push_back(0);
    //    }
    
    //std::cout << "find numb1 happen: " << neigboor1.size() << " and " << k <<std::endl;
    if(k > 0)
    {
        //std::cout << "why?? " <<std::endl;
        for(int i =0; i<neigboor8.size(); i++)
        {
            //std::cout << "why?? " <<std::endl;
            numb1.push_back(neigboor8.at(i));
        }
    }
}
sf::Sprite Board::printnumb8(int &loc)
{
    return board.at(loc)->getnumb8();
}

sf::Sprite Board::printnumb6(int &loc)
{
    return board.at(loc)->getnumb6();
}

void Board::putflag(int x, int y)
{
    std::cout << "put a flag" << std::endl;
    y = y-1;
    int locationX = (x + y*25)-1;
    std::cout << "Location: " << locationX <<std::endl;
    if(locationX<400)
    {
        board.at(locationX)->actFlags();
        std::cout << "the flag is x: " << x << "__y: "<< y <<std::endl;
    }
};

void Board::setboom(int location, bool isthere)
{
    //std::cout << "Set bomb happen" << std::endl;
    //std::cout << "the state is: " << isthere <<std::endl;
    board.at(location)->boom(isthere);
};

bool Board::board_kaboom(int &location) //did you press a bomb?
{
    for(int i=0; i<Bobs.size(); i++)
    {
        if(board.at(Bobs.at(i))->safe() == true)
        {
            //std::cout << "board_kaboom happen " <<std::endl;
            location = Bobs.at(i);
            //std::cout << "Bobs: " << Bobs.at(i) <<std::endl;
            //std::cout << "location: " << location <<std::endl;
            return true;
        }
    }
    return false;
}
sf::Sprite Board::Printmine(int &location)
{
    //std::cout << "location3: " << location <<std::endl;
    return board.at(location)->getmines();
}

sf::Sprite Board::printDebug()
{
    return extraboard.getdebug();
}

sf::Sprite Board::printTest1()
{
    return extraboard.getTest1();
}
sf::Sprite Board::printTest2()
{
    return extraboard.getTest2();
}
sf::Sprite Board::printTest3()
{
    return extraboard.getTest3();
}

sf::Sprite Board::printDig0()
{
    return extraboard.getDig0();
}

sf::Sprite Board::printDig1()
{
    return extraboard.getDig1();
}

sf::Sprite Board::printDig0_O()
{
    return extraboard.getDig0_O();
}

sf::Sprite Board::printDigsymbol()
{
    return extraboard.getDigsymbol();
}


sf::Sprite Board::choiceDigits1(int &i)
{
    if(i<10)
    {
        extraboard.SDig0.setPosition(sf::Vector2f(21.0f,512.0f));
        return extraboard.getDig0();
    }
    else
    {
        int k = i/10;
        if(k==1)
        {
            extraboard.SDig1.setPosition(sf::Vector2f(21.0f,512.0f));
            return extraboard.getDig1();
        }
        return extraboard.Bring_Digit(k, 21.0f ,512.0f);
    }
};
sf::Sprite Board::choiceDigits2(int &i)
{
    int j=i;
    int k = j%10;
    if(k==1)
    {
        extraboard.SDig1.setPosition(sf::Vector2f(42.0f,512.0f));
        return extraboard.getDig1();
    }
    return extraboard.Bring_Digit(k, 42.0f ,512.0f);
};

sf::Sprite Board::printFace_h()
{
    return extraboard.getFace_h();
};
sf::Sprite Board::printFace_l()
{
    return extraboard.getFace_l();
};
sf::Sprite Board::printFace_w()
{
    return extraboard.getFace_w();
};


int Board::returnTiles()
{
    return total_tiles;
}

int Board::returnMines()
{
    return total_mines;
}

