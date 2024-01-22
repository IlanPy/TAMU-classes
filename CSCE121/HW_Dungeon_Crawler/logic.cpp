#include <iostream>
#include <fstream>
#include <string>
#include "logic.h"

using std::cout, std::endl, std::ifstream, std::string;

/**
 * TODO: Student implement this function
 * Load representation of the dungeon level from file into the 2D map.
 * Calls createMap to allocate the 2D array.
 * @param   fileName    File name of dungeon level.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @param   maxCol      Number of columns in the dungeon table (aka width).
 * @param   player      Player object by reference to set starting position.
 * @return  pointer to 2D dynamic array representation of dungeon map with player's location., or nullptr if loading fails for any reason
 * @updates  maxRow, maxCol, player
 */
char** loadLevel(const string& fileName, int& maxRow, int& maxCol, Player& player) {
    ifstream inFS;
    string dimension_row, dimension_col, start_row, start_col;
    string temp_str;
    char temp;
    int int_dimension_row, int_dimension_col, int_start_row, int_start_col;
    int count = 0;
    inFS.open(fileName);
    //verify that file is open
    if(!inFS.is_open()){
        return nullptr;
    }
    //check dimensions
    inFS >> int_dimension_row >> int_dimension_col;
    if(inFS.fail()) return nullptr;
    if(int_dimension_col < 1 || int_dimension_row < 1
        || int_dimension_col > 999999 || int_dimension_row > 999999){
        return nullptr;
    }
    //check area overflow
    if(int_dimension_row > INT32_MAX/int_dimension_col){
        return nullptr;
    }
    //check starting position
    inFS >> int_start_row >> int_start_col;
    if(inFS.fail()) return nullptr;
    //check min and max
    if(int_start_row < 0 || int_start_col < 0
        || int_start_row >= int_dimension_row
        || int_start_col >= int_dimension_col){
        return nullptr;
    }
    //initialize starting position
    player.row = int_start_row;
    player.col = int_start_col;
    //set maxRow and maxCol
    maxRow = int_dimension_row;
    maxCol = int_dimension_col;
    //verify each element
    for(int i = 0; i < maxRow; i++){
        for(int j = 0; j < maxCol; j++){
            inFS.get(temp);
            if(inFS.fail()){
                return nullptr;
            }
            while(std::isspace(temp)){
                inFS.get(temp);
                if(inFS.fail()){
                    return nullptr;
                }
            } 
            if(temp != '+' && temp != '-'
                && temp != '$' && temp != '@'
                && temp != 'M' && temp != '?'
                && temp != '!'){
                    return nullptr;
            }
            if(temp == '?' || temp == '!'){
                count++;
            }
        } 
    }
    if(count == 0){
        return nullptr;
    }
    //check if too many
    inFS >> temp;
    if(!inFS.fail()){
        return nullptr;
    }
    //set dynamic array
    char** map;
    map = new char*[maxRow];
    for(int i = 0; i < maxRow; i++){
        map[i] = new char[maxCol];
    }
    //set array
    inFS.clear(); inFS.seekg(0);
    inFS >> dimension_row >> dimension_col;
    inFS >> start_row >> start_col;
    for(int i = 0; i < maxRow; i++){
        for(int j = 0; j < maxCol; j++){
            inFS.get(temp);
            //skip spaces and newlines
            while(std::isspace(temp)){
                inFS.get(temp);
                if(inFS.fail()){
                    return nullptr;
                }
            } 
            map[i][j] = temp;
        }
    }
    map[int_start_row][int_start_col] = TILE_PLAYER;
    return map;
    //what to do if player has no treasure and only a exit i.e cant leave
}

/**
 * TODO: Student implement this function
 * Translate the character direction input by the user into row or column change.
 * That is, updates the nextRow or nextCol according to the player's movement direction.
 * @param   input       Character input by the user which translates to a direction.
 * @param   nextRow     Player's next row on the dungeon map (up/down).
 * @param   nextCol     Player's next column on dungeon map (left/right).
 * @updates  nextRow, nextCol
 */
void getDirection(char input, int& nextRow, int& nextCol) {
    if(input == MOVE_UP){
        nextRow--;
    } else if(input == MOVE_DOWN){
        nextRow++;
    } else if(input == MOVE_RIGHT){
        nextCol++;
    } else if(input == MOVE_LEFT){
        nextCol--;
    }
}

/**
 * TODO: [suggested] Student implement this function
 * Allocate the 2D map array.
 * Initialize each cell to TILE_OPEN.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @param   maxCol      Number of columns in the dungeon table (aka width).
 * @return  2D map array for the dungeon level, holds char type.
 */
char** createMap(int maxRow, int maxCol) {
    if(maxRow < 1 || maxCol < 1){
        return nullptr;
    }
    char** map;
    map = new char*[maxRow];
    for(int i = 0; i < maxRow; i++){
        map[i] = new char[maxCol];
    }
    for(int i = 0; i < maxRow; i++){
        for(int j = 0; j < maxCol; j++){
            map[i][j] = TILE_OPEN;
        }
    }
    return map;
}

/**
 * TODO: Student implement this function
 * Deallocates the 2D map array.
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @return None
 * @update map, maxRow
 */
void deleteMap(char**& map, int& maxRow) {
    if(map != nullptr){
        for(int i = 0; i < maxRow; i++){
            delete[] map[i];
        }
    }
    delete[] map;
    map = nullptr;
    maxRow =0;
}

/**
 * TODO: Student implement this function
 * Resize the 2D map by doubling both dimensions.
 * Copy the current map contents to the right, diagonal down, and below.
 * Do not duplicate the player, and remember to avoid memory leaks!
 * You can use the STATUS constants defined in logic.h to help!
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height), to be doubled.
 * @param   maxCol      Number of columns in the dungeon table (aka width), to be doubled.
 * @return  pointer to a dynamically-allocated 2D array (map) that has twice as many columns and rows in size.
 * @update maxRow, maxCol
 */
char** resizeMap(char** map, int& maxRow, int& maxCol) {
    int temp = maxRow;
    //check validity
    if(map == nullptr || map == NULL){
        return nullptr;
    } else if(maxRow < 1 || maxCol < 1 || maxRow > 999999
        || maxCol > 999999){
        return nullptr;
    }
    //set dynamic array
    char** new_map = createMap(maxRow*2, maxCol*2);
    //allocate array A
    for(int i = 0; i < maxRow; i++){
        for(int j = 0; j < maxCol; j++){
            new_map[i][j] = map[i][j];
        }
    }
    //allocate array C
    for(int i = maxRow; i < maxRow*2; i++){
        for(int j = 0; j < maxCol; j++){
            if(map[i-maxRow][j] == TILE_PLAYER){
                new_map[i][j] = TILE_OPEN;
            } else{
                new_map[i][j] = map[i-maxRow][j];
            }
        }
    }
    //allocate array B
    for(int i = 0; i < maxRow; i++){
        for(int j = maxCol; j < maxCol*2; j++){
            if(map[i][j-maxCol] == TILE_PLAYER){
                new_map[i][j] = TILE_OPEN;
            } else{
                new_map[i][j] = map[i][j-maxCol];
            }
        }
    }
    //allocate array D
    for(int i = maxRow; i < maxRow*2; i++){
        for(int j = maxCol; j < maxCol*2; j++){
            if(map[i-maxRow][j-maxCol] == TILE_PLAYER){
                new_map[i][j] = TILE_OPEN;
            } else{
                new_map[i][j] = map[i-maxRow][j-maxCol];
            }
        }
    }
    //delete map
    deleteMap(map, maxRow);
    maxRow = temp*2;
    maxCol = maxCol*2;
    return new_map;
}

/**
 * TODO: Student implement this function
 * Checks if the player can move in the specified direction and performs the move if so.
 * Cannot move out of bounds or onto TILE_PILLAR or TILE_MONSTER.
 * Cannot move onto TILE_EXIT without at least one treasure. 
 * If TILE_TREASURE, increment treasure by 1.
 * Remember to update the map tile that the player moves onto and return the appropriate status.
 * You can use the STATUS constants defined in logic.h to help!
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @param   maxCol      Number of columns in the dungeon table (aka width).
 * @param   player      Player object to by reference to see current location.
 * @param   nextRow     Player's next row on the dungeon map (up/down).
 * @param   nextCol     Player's next column on dungeon map (left/right).
 * @return  Player's movement status after updating player's position.
 * @update map contents, player
 */
int doPlayerMove(char** map, int maxRow, int maxCol, Player& player, int nextRow, int nextCol) {
    int status = STATUS_MOVE;
    //check if nextRow, nextCol are valid
    if(nextRow >= maxRow || nextCol >= maxCol
        || nextRow < 0 || nextCol < 0
        || map[nextRow][nextCol] == TILE_PILLAR
        || map[nextRow][nextCol] == TILE_MONSTER){
            status = STATUS_STAY;
            nextRow = player.row;
            nextCol = player.col;
    } else if(map[nextRow][nextCol] == TILE_TREASURE){
        status = STATUS_TREASURE;
        player.treasure = player.treasure + 1;
    } else if(map[nextRow][nextCol] == TILE_AMULET){
        status = STATUS_AMULET;
    } else if(map[nextRow][nextCol] == TILE_DOOR){
        status = STATUS_LEAVE;
    } else if(map[nextRow][nextCol] == TILE_EXIT
        && player.treasure >= 1){
            status = STATUS_ESCAPE;
    } else if(map[nextRow][nextCol] == TILE_EXIT
        && player.treasure < 1){
            status = STATUS_STAY;
            nextRow = player.row;
            nextCol = player.col;
    }
    map[player.row][player.col] = TILE_OPEN;
    map[nextRow][nextCol] = TILE_PLAYER;
    player.row = nextRow;
    player.col = nextCol;
    return status;
}

/**
 * TODO: Student implement this function
 * Update monster locations:
 * We check up, down, left, right from the current player position.
 * If we see an obstacle, there is no line of sight in that direction, and the monster does not move.
 * If we see a monster before an obstacle, the monster moves one tile toward the player.
 * We should update the map as the monster moves.
 * At the end, we check if a monster has moved onto the player's tile.
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @param   maxCol      Number of columns in the dungeon table (aka width).
 * @param   player      Player object by reference for current location.
 * @return  Boolean value indicating player status: true if monster reaches the player, false if not.
 * @update map contents
 */
bool doMonsterAttack(char** map, int maxRow, int maxCol, const Player& player) {
    //first check up
    for(int i = player.row-1; i>=0; i--){
        if(map[i][player.col] == TILE_PILLAR){
            break;
        } else if(map[i][player.col] == TILE_MONSTER){
            map[i][player.col] = TILE_OPEN;
            map[i+1][player.col] = TILE_MONSTER;
        }
    }
    //check down
    for(int i = player.row+1; i<maxRow; i++){
        if(map[i][player.col] == TILE_PILLAR){
            break;
        } else if(map[i][player.col] == TILE_MONSTER){
            map[i][player.col] = TILE_OPEN;
            map[i-1][player.col] = TILE_MONSTER;
        }
    }
    //check left
    for(int j = player.col-1; j>=0; j--){
        if(map[player.row][j] == TILE_PILLAR){
            break;
        } else if(map[player.row][j] == TILE_MONSTER){
            map[player.row][j] = TILE_OPEN;
            map[player.row][j+1] = TILE_MONSTER;
        }
    }
    //check right
    for(int j = player.col+1; j<maxCol; j++){
        if(map[player.row][j] == TILE_PILLAR){
            break;
        } else if(map[player.row][j] == TILE_MONSTER){
            map[player.row][j] = TILE_OPEN;
            map[player.row][j-1] = TILE_MONSTER;
        }
    }
    //if monster reached player
    if(map[player.row][player.col] == TILE_MONSTER){
        return true;
    } else{
        return false;
    }
}
