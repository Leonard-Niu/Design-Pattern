#include <iostream>
#include <string.h>
#include <unordered_map>

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

class CellFactory {
public:
    static void registerCell(CellType type, Cell* cell) {
        // std::pair<CellType, Cell*>(type, cell);
        sCellRegisterMap[type] = cell;
    }

    static void registerCell(std::pair<CellType, Cell*> pair) {
        // std::pair<CellType, Cell*>(type, cell);
        sCellRegisterMap[pair.first] = pair.second;
    }

    static void unregisterCell(CellType type) {
        sCellRegisterMap.erase(type);
    }

    static Cell* create(CellType type) {
        return sCellRegisterMap[type]->clone();
    }

private:
    static std::unordered_map<CellType, Cell*> sCellRegisterMap;
};

std::unordered_map<CellType, Cell*> CellFactory::sCellRegisterMap = std::unordered_map<CellType, Cell*>();

int main() {
    Cell* red = new Cell(CellType::RedBloodCell);
    Cell* white = new Cell(CellType::WhiteBloodCell);

    CellFactory::registerCell(std::pair<CellType, Cell*>(CellType::RedBloodCell, red));
    CellFactory::registerCell(std::pair<CellType, Cell*>(CellType::WhiteBloodCell, white));

    Cell* newCell = CellFactory::create(CellType::RedBloodCell);
    return 0;
}