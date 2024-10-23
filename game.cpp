#include <bits/stdc++.h>
using namespace std;

void change(char* grid,int* length,char* orientation,int* left,int* top);
void moveGrid(char* grid, char element,char move);
void moveInput(char*  element, char* move,char* grid);
void movex(char* grid, char element,char move,int x1,int y1, int x2, int y2);
void movey(char* grid, char element,char move,int x1,int y1, int x2, int y2);
char newch();
void placeKey(char* grid);
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
    
    placeKey(&grid[0]);
    cout<<"\n ~ FINAL GRID ~\n";
    show(&grid[0]);

    bool win = false;
    char element;
    char move;
    cout<<"Start playing. Give your moves in the format: Element direction(R/L/U/D)\n For example: A D\n(This will take block containing element A down if possible)\n";
    while(!win)
    {
        moveInput(&element, &move, &grid[0]);
        moveGrid(&grid[0], element, move);
        //show(&grid[0]);
        //checkwin
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

void placeKey(char* grid)
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

}

void moveGrid(char* grid , char element,char move)
{
    int positionx1 = -1, positiony1 = -1;
    int positionx2 = -1, positiony2 = -1;

    for(int row = 0; row < 6; row++)
    {
        for(int column = 0; column < 6; column++)
        {
            if(*(grid+row*6+column) == element && positionx1==-1)
            {
                cout<<"First Position of element is "<<row+1<<" and "<<column+1;
                positionx1 = column;
                positiony1 = row;
            }
            if(*(grid+row*6+column) == element)
            {
                cout<<"Last Position of element is "<<row+1<<" and "<<column+1;
                positionx2 = column;
                positiony2 = row;
            }
        }
    }

    if(move == 'L' || move =='R')
    {
        movex(&grid[0], element, move, positionx1, positiony1, positionx2, positiony2);
        cout<<"CURRENT GRID: \n";
        show(&grid[0]);
    }
    if(move == 'U' || move =='D')
    {
        movey(&grid[0], element, move, positionx1, positiony1, positionx2, positiony2);
        cout<<"CURRENT GRID: \n";
        show(&grid[0]);
    }
}

void movex(char* grid, char element,char move,int x1,int y1, int x2, int y2)
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
            }
        }
    }
    else
    {
        cout<<"Cannot move vertical blocks horizontally";
    }
}


void movey(char* grid, char element,char move,int x1,int y1, int x2, int y2)
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

