#include <iostream>

void getTicket(int**& tickets, int& rows, int&cols, int&ticketRow, int& ticketCol){
    bool seatFound = false;
    if(tickets == nullptr){
        rows = 2;
        cols = 4;
        tickets = new int*[rows];
        for(int i = 0; i < rows; i++){
            tickets[i] = new int[cols];
        } //forgot this bracket
        for(unsigned int i = 0; i < rows; i++){
            for(unsigned int j = 0; j < cols; j++){
                tickets[i][j] = 0;
            }
        }
    }
    for(unsigned int i = 0; i < rows; i++){
        for(unsigned int j = 0; j < cols; j++){
            if(tickets[i][j] == 0){
                seatFound = true;
                ticketRow = i;
                ticketCol = j;
                tickets[i][j] = 1;
                break;
            }
        }
        if(seatFound){
            break;
        }
    }
    if(!seatFound){
        int** temp = new int*[5+rows];
        for(unsigned int i = 0; i < 5+rows; i++){
            // for(unsigned int j = 0; j < cols; j++){
                temp[i] = new int[cols];
            // } added commented in exam which is wrong
        }
        for(unsigned int i = 0; i < rows; i++){
            for(unsigned int j = 0; j < cols; j++){
                temp[i][j] = tickets[i][j];
            }
        }
        for(unsigned int i = 0; i < rows; i++){
            delete[] tickets[i];
        }
        delete[] tickets;
        tickets = temp;
        temp = nullptr;
        for(unsigned int i  = rows; i < 5+rows; i++){
            for(unsigned int j = 0;j < cols; j++){
                tickets[i][j] = 0;
            }
        }
        tickets[rows][0] = 1;
        ticketRow = rows;
        ticketCol = 0;
        rows = 5+rows;
    }
}

int main() {
    int rows = 5;
    int cols = 4;
    int** tickets = new int*[rows];
    for(int i = 0; i < rows; i++){
        tickets[i] = new int[cols];
    }
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            tickets[i][j] = 1;
        }
    }
    tickets[rows-1][cols-1] = 0;
    tickets[rows-2][cols-2] = 0;
    int ticketRow;
    int ticketCol;
    getTicket(tickets, rows, cols, ticketRow, ticketCol);
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            std::cout << tickets[i][j] << " ";
        }
        std::cout << std::endl;
    }
    for(int i = 0; i < rows; i++){
        delete[] tickets[i];
    }
    delete[] tickets;
}
