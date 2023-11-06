void visitAccessibleRooms(bool* accessible, int current, int** rooms, int* roomsColSize) {
    if (!accessible[current]) {
            accessible[current] = true;
        for (int i = 0; i < roomsColSize[current]; i++ ) {  
            visitAccessibleRooms(accessible, rooms[current][i], rooms,  roomsColSize);
        }
    }
}


bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize) {
    // busca largura
    bool accessible[roomsSize];
    for (int i = 0; i < roomsSize; i++) {
        accessible[i] = false;
    }

    visitAccessibleRooms(accessible, 0, rooms, roomsColSize);
    for (int i = 0; i < roomsSize; i++) {
        if (!(accessible[i])) {
            return false;
        }
    }
    return true;
}