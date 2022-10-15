#include <iostream>
#include <time.h>
#include <string.h>

enum class CellType {
    RedBloodCell,
    WhiteBloodCell,
};

class Cell {
public:
    Cell(CellType cellType) {
        mCellType = cellType;
        memset(mStartTime, '\0', sizeof(mStartTime));
        time_t now = time(nullptr);
        // strftime(mStartTime,sizeof(mStartTime),"%X",localtime(&now));
        strcpy(this->mStartTime, ctime(&now));
        printf("%s", ctime(&now));
    }

    Cell(const Cell& cell) {
        this->mCellType = cell.mCellType;
        memset(mStartTime, '\0', sizeof(mStartTime));
        // memset(this->mStartTime, *cell.mStartTime, sizeof(mStartTime));
        strcpy(this->mStartTime, cell.mStartTime);
    }

    Cell* clone() {
        return new Cell(*this);
    }

private:
    CellType mCellType;
    char mStartTime[64];
};

int main() {
    Cell* red = new Cell(CellType::RedBloodCell);
    Cell* white = new Cell(CellType::WhiteBloodCell);
    // cell division
    Cell* newRed = red->clone();
    return 0;
}