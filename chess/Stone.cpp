#include "Stone.h"
#include "board.h"
#include "ui_board.h"
Stone::Stone()
{

}

void Stone::init(int id)
{
    // 每方总共有16个棋子
    struct
    {
        int row,col;
        Stone::TYPE type;
    } pos[32] = {
    {0,0,Stone::TA},
    {0,1,Stone::QI},
    {0,2,Stone::ZHUJIAO},
    {0,3,Stone::HOU},
    {0,4,Stone::WANG},
    {0,5,Stone::ZHUJIAO},
    {0,6,Stone::QI},
    {0,7,Stone::TA},

    {1,0,Stone::BING},
    {1,1,Stone::BING},
    {1,2,Stone::BING},
    {1,3,Stone::BING},
    {1,4,Stone::BING},
    {1,5,Stone::BING},
    {1,6,Stone::BING},
    {1,7,Stone::BING},
 //------------------------
    {7,0,Stone::TA},
    {7,1,Stone::QI},
    {7,2,Stone::ZHUJIAO},
    {7,3,Stone::HOU},
    {7,4,Stone::WANG},
    {7,5,Stone::ZHUJIAO},
    {7,6,Stone::QI},
    {7,7,Stone::TA},

    {6,0,Stone::BING},
    {6,1,Stone::BING},
    {6,2,Stone::BING},
    {6,3,Stone::BING},
    {6,4,Stone::BING},
    {6,5,Stone::BING},
    {6,6,Stone::BING},
    {6,7,Stone::BING},
    };

        this->_col = pos[id].col;
        this->_row = pos[id].row;
        this->_type = pos[id].type;

    _id = id;
    _dead = false;
    _red = id<16; //id 小于16时，bool _red为真

}
void Stone::canju1(int id){
    struct
    {
        int row,col;
        Stone::TYPE type;
    } pos[3] = {
    {0,4,Stone::WANG},
    {3,4,Stone::WANG},
    {7,5,Stone::TA},
    };
    this->_col = pos[id].col;
    this->_row = pos[id].row;
    this->_type = pos[id].type;

    _id = id;
    _dead = false;
    _red = id<1; //
}
void Stone::canju2(int id){
    struct
    {
        int row,col;
        Stone::TYPE type;
    } pos[3] = {
    {2,5,Stone::WANG},
    {5,3,Stone::WANG},
    {4,2,Stone::HOU},
    };
    this->_col = pos[id].col;
    this->_row = pos[id].row;
    this->_type = pos[id].type;

    _id = id;
    _dead = false;
    _red = id<1; //
}
void Stone::canju3(int id){
    struct
    {
        int row,col;
        Stone::TYPE type;
    } pos[4] = {
    {1,5,Stone::WANG},
    {6,6,Stone::WANG},
    {3,0,Stone::TA},
    {5,1,Stone::TA},
    };
    this->_col = pos[id].col;
    this->_row = pos[id].row;
    this->_type = pos[id].type;

    _id = id;
    _dead = false;
    _red = id<1; //
}
void Stone::canju4(int id){
    struct
    {
        int row,col;
        Stone::TYPE type;
    } pos[4] = {
    {3,1,Stone::WANG},
    {4,3,Stone::QI},
    {2,3,Stone::WANG},
    {3,2,Stone::HOU},
    };
    this->_col = pos[id].col;
    this->_row = pos[id].row;
    this->_type = pos[id].type;

    _id = id;
    _dead = false;
    _red = id<2; //
}

