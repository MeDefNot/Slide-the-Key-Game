#include <bits/stdc++.h>
using namespace std;

void change(char* grid,int* length,char* orientation,int* left,int* top);
void moveGrid(char* grid, char element,char move, char* kori, int* kpos, int* kwin);
void moveInput(char*  element, char* move,char* grid);
void movex(char* grid, char element,char move,int x1,int y1, int x2, int y2, char* kori, int* kpos, int* kwin);
void movey(char* grid, char element,char move,int x1,int y1, int x2, int y2, char* kori, int* kpos, int* kwin);
char newch();
void placeKey(char* grid, int* kpos, int*kwin, char* kori);
void show(char* a);
void takeInput(int* length, char* orientation, int* left, int* top);

int main()
{
    //storing grid in string because everything else is new to me -_-
    string grid = "                                    ";

    cout<<"Generating an empty 6x6 grid...\n";
    show(&grid[0]);
    
    //arranging the grid
    int length;
    char orientation;
    int left;
    int top;

    bool finishedgrid = false;
    while(finishedgrid!=true)
    {   
        char ans;
        cout<<"\nDo you want to add an element?(y/n) :";
        cin>>ans;
        if(ans == 'y' || ans =='Y')
        {
            takeInput(&length, &orientation, &left, &top);
            change(&grid[0], &length, &orientation, &left, &top);
            cout<<"\n**$Curret grid$**\n";
            show(&grid[0]);
        } 
        else if(ans == 'n' || ans == 'N')
        {
            finishedgrid = true;
        }   
        else
        {
            cout<<"Invalid response. Try again\n";
        }
    }

    int kposition, kwin;
    char kori; //key orientation
    
    placeKey(&grid[0], &kposition, &kwin, &kori);
    cout<<"\n ~ FINAL GRID ~\n";
    show(&grid[0]);

    bool win = false;
    char element;
    char move;
    cout<<"Start playing. Give your moves in the format: Element direction(R/L/U/D)\n For example: A D\n(This will take block containing element A down if possible)\n";
    while(!win)
    {
        cout<<"\nMove key by "<<kposition-kwin<<" boxes.";
        moveInput(&element, &move, &grid[0]);
        moveGrid(&grid[0], element, move, &kori, &kposition, &kwin);
        if(kposition == kwin)
        {
            cout<<"YOU WON!";
            cout<<"\n \\o       o/   o__ __o        o         o                    o              o            o__ __o            o          o      \n  v\\     /v   /v     v\\      <|>       <|>                  <|>            <|>          /v     v\\          <|\\        <|>     \n   <\\   />   />       <\\     / \\       / \\                  / \\            / \\         />       <\\         / \\o      / \\     \n     \\o/   o/           \\o   \\o/       \\o/                  \\o/            \\o/       o/           \\o       \\o/ v\\     \\o/     \n      |   <|             |>   |         |                    |              |       <|             |>       |   <\\     |      \n     / \\   \\           //    < >       < >                  < >            < >       \\           //       / \\    \\o  / \\     \n     \\o/     \\         /      \\         /                    \\o    o/\\o    o/          \\         /         \\o/     v\\ \\o/     \n      |       o       o        o       o                      v\\  /v  v\\  /v            o       o           |       <\\ |      \n     / \\      <\\__ __/>        <\\__ __/>                       <\\/>    <\\/>             <\\__ __/>          / \\        < \\     \n                                                                                                                              \n                                                                                                                              \n                                                                                                                              ";
            break;
        }
    }    

    return 0;
}

void show(char* grid)
{
    for(int row = 0; row < 6; row++)
    {
        cout<<"          ___ ___ ___ ___ ___ ___\n";
        cout<<"           ";
        for(int column = 0; column < 6; column++)
        {
            cout<<*(grid+row*6+column)<<" | ";
        }
        cout<<"\n";        
    }
}

void change(char* grid,int* length,char* orientation,int* left,int* top)
{
    char newc = newch();
    if(*orientation == 'v')
    {
        //go through the grid
        for(int i = 0; i < *length ; i++)
        {
            *(grid+(*top+i)*6 + *left) = newc;
        }
        cout<<"\n";
    }
    if(*orientation == 'h')
    {
        //go through the grid
        for(int i = 0; i < *length ; i++)
        {
            *(grid+*top * 6 + *left+i) = newc;
        }
    }
}

char current = 'A'-1;

char newch()
{
    current = current+1;
    return current;
}

void takeInput(int* length, char* orientation, int* left, int* top)
{
    cout<<"Put your input seperated by spaces in the following order:\nlength orientation(v/h) left top\n";
    cin>>*length;
    cin>>*orientation;
    cin>>*left;
    cin>>*top;

    if(*length > 6)
    {
        cout<<"\nWarning: Length cannot be greater than 6.";
        while(*length>6)
        {
            cout<<"\nTry again!\nLength: ";
            cin>>*length;
        }
    }
    if(*length < 2)
    {
        cout<<"\nWarning: Length cannot be smaller than 2.";
        while(*length<2)
        {
            cout<<"\nTry again!\nLength: ";
            cin>>*length;
        }
    }

    if(!(*orientation == 'v' || *orientation == 'V' || *orientation == 'h' || *orientation == 'H'))
    {
        cout<<"\nWarning: Element can be either horizontal(h) or vertical(v)";
        while(!(*orientation == 'v' || *orientation == 'V' || *orientation == 'h' || *orientation == 'H'))
        {
            cout<<"\nTry again!\nOrientation: ";
            cin>>*orientation;
        }
    }

    int sideways, top2bottom;
    if(*orientation == 'v' || *orientation == 'V')
    {
        sideways = 1;
        top2bottom = *length;
    }
    else 
    {
        sideways = *length;
        top2bottom = 1;
    }


    if(*left+sideways > 6)
    {
        cout<<"\nWarning: Element is going outside grid";
        while(*left+sideways > 6)
        {
            cout<<"\nTry again!\nLeft: ";
            cin>>*left;
        }
    }
    if(*top+top2bottom > 6)
    {
        cout<<"\nWarning: Element is going outside grid";
        while(*top+top2bottom > 6)
        {
            cout<<"\nTry again!\nTop: ";
            cin>>*top;
        }
    }
}

void placeKey(char* grid, int* kpos,int *kwin, char* kori)
{
    cout<<"Place the key in position (x,y).";
    cout<<"Put your input seperated by spaces in the following order: orientation  x y\n";
    int length = 2;
    char orientation;
    cin>>orientation;
    int top, left;
    cin>>left;
    cin>>top;

    if(!(orientation == 'v' || orientation == 'V' || orientation == 'h' || orientation == 'H'))
    {
        cout<<"\nWarning: Key can be either horizontal(h) or vertical(v)";
        while(!(orientation == 'v' || orientation == 'V' || orientation == 'h' || orientation == 'H'))
        {
            cout<<"\nTry again!\nOrientation: ";
            cin>>orientation;
        }
    }

    int sideways, top2bottom;
    if(orientation == 'v' || orientation == 'V')
    {
        sideways = 1;
        top2bottom = length;
    }
    else 
    {
        sideways = length;
        top2bottom = 1;
    }


    if((int)left + sideways > 6)
    {
        cout<<"\nWarning: Key is going outside grid";
        while((int)left+sideways > 6)
        {
            cout<<"\nTry again!\nLeft: ";
            cin>>left;
        }
    }
    if(top+top2bottom > 6)
    {
        cout<<"\nWarning: Element is going outside grid";
        while(top+top2bottom > 6)
        {
            cout<<"\nTry again!\nTop: ";
            cin>>top;
        }
    }
    char newc = '$';
    if(orientation == 'v')
    {
        //go through the grid
        for(int i = 0; i < length ; i++)
        {
            *(grid+(top+i)*6 + left) = newc;
        }
        cout<<"\n";
    }
    if(orientation == 'h')
    {
        //go through the grid
        for(int i = 0; i < length ; i++)
        {
            *(grid+top*6 + left+i) = newc;
        }
    }
    *kori = orientation;
    *kpos = top*6+left;

    if(orientation == 'v' || orientation == 'V')
    {
        int down;
        cout<<"\nHow many boxes does the key need to go down? :";
        cin>>down;
        if(top+down > 5)
        {
            cout<<"\nWarning: Keep it within the grid. Try again: ";
            cin>>down;
        }
        *kwin = (top+down)*6 + left;
    }
    else
    {
        int right;
        cout<<"\nHow many boxes to the right does the key need to go ? :";
        cin>>right;
        if(left+right > 5)
        {
            cout<<"\nWarning: Keep it within the grid. Try again: ";
            cin>>right;
        }
        *kwin = top*6 + left + right;
    }
    cout<<"\n\nPosition of key: "<<*kpos<<" Position of win: "<<*kwin<<"\n";
}

void moveGrid(char* grid , char element,char move,char* kori,int* kpos,int* kwin)
{
    int positionx1 = -1, positiony1 = -1;
    int positionx2 = -1, positiony2 = -1;

    cout<<"\nOrientation: "<<*kori<<"\n";
   
    for(int row = 0; row < 6; row++)
    {
        for(int column = 0; column < 6; column++)
        {
            if(*(grid+row*6+column) == element && positionx1==-1)
            {
                positionx1 = column;
                positiony1 = row;
            }
            if(*(grid+row*6+column) == element)
            {
                positionx2 = column;
                positiony2 = row;
            }
        }
    }

    if(move == 'L' || move =='R')
    {
        movex(&grid[0], element, move, positionx1, positiony1, positionx2, positiony2, kori, kpos, kwin);
        cout<<"CURRENT GRID: \n";
        show(&grid[0]);
    }
    if(move == 'U' || move =='D')
    {
        movey(&grid[0], element, move, positionx1, positiony1, positionx2, positiony2, kori, kpos, kwin);
        cout<<"CURRENT GRID: \n";
        show(&grid[0]);
    }
}


void movex(char* grid, char element,char move,int x1,int y1, int x2, int y2, char* kori, int* kpos, int* kwin)
{
    //check if horizontal
    if(y1 == y2)
    {
        //horizontal
        if(move == 'R')
        {
            if(x2==5 || *(grid+y2*6+x2+1) != ' ')
            {
                cout<<"\nImpossible move\n";
            }
            else
            {
                *(grid+y1*6+x1) = ' ';
                *(grid+y2*6+x2+1) = element;
                if(element == '$')
                {
                    *kpos = *kpos + 1;
                }
            }
        }
        else
        {
            if(x1==0 || *(grid+y2*6+x1-1) != ' ')
            {
                cout<<"\nImpossible move\n";
            }
            else
            {
                *(grid+y1*6+x2) = ' ';
                *(grid+y2*6+x1-1) = element;
                if(element == '$')
                {
                    *kpos = *kpos -1;
                }
            }
        }
    }
    else
    {
        cout<<"Cannot move vertical blocks horizontally";
    }
}


void movey(char* grid, char element,char move,int x1,int y1, int x2, int y2,char* kori, int* kpos, int* kwin )
{
    //check if vertical
    if(x1 == x2)
    {
        //horizontal
        if(move == 'U')
        {
            if(y1 == 0 || *(grid+y1*6+x1-6) != ' ')
            {
                cout<<"\nImpossible move\n";
            }
            else
            {
                *(grid+y1*6+x1-6) = element;
                *(grid+y2*6+x2) = ' ';
                if(element == '$')
                {
                    *kpos = *kpos - 6;
                }
            }
        }
        else
        {
            if(y2==5 || *(grid+y2*6+x2+6) != ' ')
            {
                cout<<"\nImpossible move\n";
            }
            else
            {
                *(grid+y1*6+x1) = ' ';
                *(grid+y2*6+x2+6) = element;
                if(element == '$')
                {
                    *kpos = *kpos+6;
                }
            }
        }
    }
    else
    {
        cout<<"Cannot move horizontal blocks vertically";
    }
}

void moveInput(char*  element, char* move,char* grid)
{
    cout<<"\nMove: ";
    cin>>*element>>*move;
}
