#include <iostream>
using namespace std;

const int GRIDSIZE = 20;
const int INITIALANT = 100;
const int INITIALBUG = 5;
const int ANTBREED = 3;
const int BUGBREED = 8;
const int BUGSTARVE = 3;

class World;
class Organism;

bool inGrid(int x, int y) {
    return x >= 0 && x < GRIDSIZE && y >= 0 && y < GRIDSIZE;
}

class World {
    friend class Organism;
    friend class Ant;
    friend class Doodlebug;

   private:
    Organism *grid[GRIDSIZE][GRIDSIZE];

   public:
    World() {
        for (int i = 0; i < GRIDSIZE; i++) {
            for (int j = 0; j < GRIDSIZE; j++) {
                grid[i][j] = NULL;
            }
        }
    }
    ~World() {}
    Organism *get_point(int x, int y) {
        if (inGrid(x, y)) {
            return grid[x][y];
        }
        return NULL;
    }
    void set_point(int x, int y, Organism *org) {
        if (inGrid(x, y)) {
            grid[x][y] = org;
        }
    }
    void display();
    void dowork();
};

class Organism {
    friend class World;

   protected:
    int x, y, breedCount, starveCount;
    World *world;

   public:
    bool moved;
    Organism(World *w, int x, int y) : world(w), x(x), y(y) {
        breedCount = 0;
        starveCount = 0;
        moved = false;
        w->set_point(x, y, this);
    }
    virtual ~Organism() {}
    virtual int get_type() = 0;
    virtual void move() = 0;
    virtual void breed() = 0;
    virtual bool starve() = 0;

    void moveDefault() {
        int direction = rand() % 4;

        switch (direction) {
            case 0:
                if ((y > 0) && (world->get_point(x, y - 1) == NULL)) {
                    world->set_point(x, y - 1, world->get_point(x, y));
                    world->set_point(x, y, NULL);
                    y--;
                }
                break;
            case 1:
                if ((y < GRIDSIZE - 1) &&
                    (world->get_point(x, y + 1) == NULL)) {
                    world->set_point(x, y + 1, world->get_point(x, y));
                    world->set_point(x, y, NULL);
                    y++;
                }
                break;
            case 2:
                if ((x > 0) && (world->get_point(x - 1, y) == NULL)) {
                    world->set_point(x - 1, y, world->get_point(x, y));
                    world->set_point(x, y, NULL);
                    x--;
                }
                break;
            case 3:
                if ((x < GRIDSIZE - 1) &&
                    (world->get_point(x + 1, y) == NULL)) {
                    world->set_point(x + 1, y, world->get_point(x, y));
                    world->set_point(x, y, NULL);
                    x++;
                }
                break;
            default:
                break;
        }
    }
};

// ==============================================================================

class Ant : public Organism {
   public:
    Ant(World *w, int x, int y) : Organism(w, x, y) {}
    ~Ant() {}
    int get_type() { return 1; }
    void move();
    void breed();
    bool starve() { return false; };
};

void Ant::move() {
    moved = true;
    moveDefault();
    // cout << "Ant Moved. ";
}

void Ant::breed() {
    // cout << "Ant Breedcount Called.";
    breedCount++;
    if (breedCount == ANTBREED) {
        breedCount = 0;
        if ((y > 0) && (world->get_point(x, y - 1) == NULL)) {
            Ant *newAnt = new Ant(world, x, y - 1);
        } else if ((y < GRIDSIZE - 1) && (world->get_point(x, y + 1) == NULL)) {
            Ant *newAnt = new Ant(world, x, y + 1);
        } else if ((x > 0) && (world->get_point(x - 1, y) == NULL)) {
            Ant *newAnt = new Ant(world, x - 1, y);
        } else if ((x < GRIDSIZE - 1) && (world->get_point(x + 1, y) == NULL)) {
            Ant *newAnt = new Ant(world, x + 1, y);
        }
    }
}

// ==============================================================================

class Doodlebug : public Organism {
   public:
    Doodlebug(World *w, int x, int y) : Organism(w, x, y) {}
    ~Doodlebug() {}
    int get_type() { return 2; }
    void move();
    void breed();
    bool starve() { return (starveCount >= BUGSTARVE) ? true : false; }
};

void Doodlebug::move() {
    moved = true;
    // cout << "Bug moved. ";
    if (world->get_point(x, y - 1) != NULL &&
        world->get_point(x, y - 1)->get_type() == 1) {
        delete (world->grid[x][y - 1]);
        world->set_point(x, y - 1, world->get_point(x, y));
        world->set_point(x, y, NULL);
        y--;
        starveCount = 0;
        // cout << "Bug eats Ant 1." << endl;

    } else if (world->get_point(x, y + 1) != NULL &&
               world->get_point(x, y + 1)->get_type() == 1) {
        delete (world->grid[x][y + 1]);
        world->set_point(x, y + 1, world->get_point(x, y));
        world->set_point(x, y, NULL);
        y++;
        starveCount = 0;
        // cout << "Bug eats Ant 2." << endl;

    } else if (world->get_point(x - 1, y) != NULL &&
               world->get_point(x - 1, y)->get_type() == 1) {
        delete (world->grid[x - 1][y]);
        world->set_point(x - 1, y, world->get_point(x, y));
        world->set_point(x, y, NULL);
        x--;
        starveCount = 0;
        // cout << "Bug eats Ant 3." << endl;

    } else if (world->get_point(x + 1, y) != NULL &&
               world->get_point(x + 1, y)->get_type() == 1) {
        delete (world->grid[x + 1][y]);
        world->set_point(x + 1, y, world->get_point(x, y));
        world->set_point(x, y, NULL);
        x++;
        starveCount = 0;
        // cout << "Bug eats Ant 4." << endl;
    } else {
        starveCount++;
        moveDefault();
        // cout << "Bug starves." << endl;
    }
}

void Doodlebug::breed() {
    // cout << "Bug Breedcount Called.";
    breedCount++;
    if (breedCount == BUGBREED) {
        breedCount = 0;
        if ((y > 0) && (world->get_point(x, y - 1) == NULL)) {
            Doodlebug *newBug = new Doodlebug(world, x, y - 1);
            // cout << "New Bug created." << endl;
        } else if ((y < GRIDSIZE - 1) && (world->get_point(x, y + 1) == NULL)) {
            Doodlebug *newBug = new Doodlebug(world, x, y + 1);
            // cout << "New Bug created." << endl;
        } else if ((x > 0) && (world->get_point(x - 1, y) == NULL)) {
            Doodlebug *newBug = new Doodlebug(world, x - 1, y);
            // cout << "New Bug created." << endl;
        } else if ((x < GRIDSIZE - 1) && (world->get_point(x + 1, y) == NULL)) {
            Doodlebug *newBug = new Doodlebug(world, x + 1, y);
            // cout << "New Bug created." << endl;
        }
    }
}

// ==============================================================================

void World::display() {
    for (int j = 0; j < GRIDSIZE; j++) {
        for (int i = 0; i < GRIDSIZE; i++) {
            if (grid[i][j] == NULL)
                cout << '-' << " ";
            else if (grid[i][j]->get_type() == 1)
                cout << 'o' << " ";
            else if (grid[i][j]->get_type() == 2)
                cout << 'X' << " ";
        }
        cout << endl;
    }
}

void World::dowork() {
    for (int i = 0; i < GRIDSIZE; i++) {
        for (int j = 0; j < GRIDSIZE; j++) {
            if (grid[i][j] != NULL) {
                grid[i][j]->moved = false;
            }
        }
    }

    for (int i = 0; i < GRIDSIZE; i++) {
        for (int j = 0; j < GRIDSIZE; j++) {
            if ((grid[i][j] != NULL) && (grid[i][j]->get_type() == 2)) {
                if (grid[i][j]->moved == false) {
                    grid[i][j]->moved = true;
                    grid[i][j]->move();
                }
            }
        }
    }

    for (int i = 0; i < GRIDSIZE; i++) {
        for (int j = 0; j < GRIDSIZE; j++) {
            if ((grid[i][j] != NULL) && (grid[i][j]->get_type() == 1)) {
                if (grid[i][j]->moved == false) {
                    grid[i][j]->moved = true;
                    grid[i][j]->move();
                }
            }
        }
    }

    for (int i = 0; i < GRIDSIZE; i++) {
        for (int j = 0; j < GRIDSIZE; j++) {
            if ((grid[i][j] != NULL) && (grid[i][j]->get_type() == 2)) {
                if (grid[i][j]->starve()) {
                    delete (grid[i][j]);
                    grid[i][j] = NULL;
                }
            }
        }
    }

    for (int i = 0; i < GRIDSIZE; i++) {
        for (int j = 0; j < GRIDSIZE; j++) {
            if ((grid[i][j] != NULL) && (grid[i][j]->moved == true)) {
                grid[i][j]->breed();
            }
        }
    }
}

int main() {
    World w;
    srand(time(0));
    int antCount = 0;
    int bugCount = 0;

    while (antCount < INITIALANT) {
        int x = rand() % GRIDSIZE;
        int y = rand() % GRIDSIZE;
        if (w.get_point(x, y) == NULL) {
            antCount++;
            Ant *a = new Ant(&w, x, y);
        }
    }

    while (bugCount < INITIALBUG) {
        int x = rand() % GRIDSIZE;
        int y = rand() % GRIDSIZE;
        if (w.get_point(x, y) == NULL) {
            bugCount++;
            Doodlebug *d = new Doodlebug(&w, x, y);
        }
    }

    int i = 0;
    while (true) {
        cout << endl << endl << "World at time " << i << ": " << endl;
        w.display();
        w.dowork();
        i++;
        cout << "Press ENTER to continue";
        cin.ignore();
    }

    return 0;
}