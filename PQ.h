#include <queue>

#define MAXSIZE 800

enum SortCriteria{

    BMI,
    AGE,
    HEIGHT,
    WEIGHT
};

struct BMIAnalysis {
    int age;
    double height;
    double weight;
    double bmi;
    static SortCriteria currentSortCriteria;

    bool operator<(const BMIAnalysis& other) const{
        switch (currentSortCriteria){
            case BMI:
                return bmi < other.bmi;
            case AGE:
                return age < other.age;
            case HEIGHT:
                return height < other.height;
            case WEIGHT:
                return weight < other.weight;
            default:
                return false;
        }
    }

    static void SetSortCriteria(SortCriteria attribute) {
        currentSortCriteria = attribute;
    }



};

class PQ
{
public:

    PQ(); // Constructor

    void MakeEmpty();  // Returns the list to the empty state.

    bool IsFull() const; // Determines whether list is full. (Precondition -- list has been initialized). Return value of "True" indicates class is full.

    int GetLength() const; // Determines the number of elements in list.

    void PutItem(BMIAnalysis); // Adds the item to the list.

    void ResetList();  // Initializes iterator's current position for an iteration through the list.

    BMIAnalysis GetNextItem(); // Gets the next element in the list.

    bool HasNextItem();

    void PrintList();  // Print all elements of the list in a readable format.

    void PrintPriorityBMI();

    void PrintPriorityAGE();

    void PrintPriorityHEIGHT();

    void PrintPriorityWEIGHT();

    void SetSortCriteria(SortCriteria attribute);

private:
    int length;
    BMIAnalysis ListItems[MAXSIZE];
    int currentPos;



    std::priority_queue<BMIAnalysis> PriorityQueue;
    SortCriteria currentSortCriteria;
};

struct BMIAnalysis;

