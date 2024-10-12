// COMSC-210 | Lab 21 | Anthony R. Sarabia
// IDE used: Visual Studio 

#include <iostream>
#include <iomanip>
#include <cstdlib>     // For rand() and srand()
#include <string>      // For string operations
#include <ctime>       // For time()
using namespace std; 

const int MIN_LIST = 5;
const int MAX_LIST = 20; 
const int MIN_AGE = 1;               
const int MAX_AGE = 20;                    
const int NAME_COUNT = 15;           // Number of names in the names array
const int COLOR_COUNT = 15;          // Number of colors in the colors array

//Goat Class
class Goat {
private:
    int age;
    string name;
    string color;

    // Static arrays of names and colors for Goat initialization
    static const string names[NAME_COUNT];
    static const string colors[COLOR_COUNT];

public:
    Goat() {
        age = rand() % (MAX_AGE - MIN_AGE + 1) + MIN_AGE;
        name = names[rand() % NAME_COUNT];
        color = colors_list[rand() % COLOR_COUNT];
    }
    
    // Parameterized constructor
    Goat(int a, const string& n, const string& c) : age(a), name(n), color(c) {}

    //Getters
    int get_age() const { return age; }
    string get_name() const { return name; }
    string get_color() const { return color; }
    string get_description() const {
        return name + " (" + color + ", " + to_string(age) + ")";
    }
    //bool overload
    bool operator==(const Goat& other) const {
        return (age == other.age) && (name == other.name) && (color == other.color);
    }
   
};

const string Goat::names[NAME_COUNT] = {
    "Senior", "Godlike", "Old", "Mature", "Teen", "Youngster", "Elder",
    "Veteran", "Baby", "Warrior", "Legend", "Epic", "Hero", "Champion", "Rogue"
};
const string Goat::colors[NAME_COUNT] = {
  "Yellow", "Red", "Gold", "Mauve", "White", "Blue", "Green",
    "Purple", "Black", "Silver", "Orange", "Brown", "Pink", "Cyan", "Indigo"
};

class DoublyLinkedList {
private:
    struct Node {
        Goat data;
        Node* prev;
        Node* next;
        Node(const Goat& goatData, Node* previousN = nullptr, Node* nextN = nullptr) 
            : data(goatData), prev(previousN), next(nextN){}
        
    };

    Node* head;
    Node* tail;

public:
    // constructor
    DoublyLinkedList() { head = nullptr; tail = nullptr; }

    void push_back(int value) {
        Node* newNode = new Node(value);
        if (!tail)  // if there's no tail, the list is empty
            head = tail = newNode;
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void push_front(int value) {
        Node* newNode = new Node(value);
        if (!head)  // if there's no head, the list is empty
            head = tail = newNode;
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insert_after(int value, int position) {
        if (position < 0) {
            cout << "Position must be >= 0." << endl;
            return;
        }

        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
            return;
        }

        Node* temp = head;
        for (int i = 0; i < position && temp; ++i)
            temp = temp->next;

        if (!temp) {
            cout << "Position exceeds list size. Node not inserted.\n";
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next)
            temp->next->prev = newNode;
        else
            tail = newNode; // Inserting at the end
        temp->next = newNode;
    }

    void delete_node(int value) {
        if (!head) return; // Empty list

        Node* temp = head;
        while (temp && temp->data != value)
            temp = temp->next;

        if (!temp) return; // Value not found

        if (temp->prev) {
            temp->prev->next = temp->next;
        }
        else {
            head = temp->next; // Deleting the head
        }

        if (temp->next) {
            temp->next->prev = temp->prev;
        }
        else {
            tail = temp->prev; // Deleting the tail
        }

        delete temp;
    }

    void print() {
        Node* current = head;
        if (!current) return;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void print_reverse() {
        Node* current = tail;
        if (!current) return;
        while (current) {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }

    ~DoublyLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Driver program
int main() {
    DoublyLinkedList list;
    int size = rand() % (MAX_LS - MIN_LS + 1) + MIN_LS;

    for (int i = 0; i < size; ++i)
        list.push_back(rand() % (MAX_NR - MIN_NR + 1) + MIN_NR);
    cout << "List forward: ";
    list.print();

    cout << "List backward: ";
    list.print_reverse();

    cout << "Deleting list, then trying to print.\n";
    list.~DoublyLinkedList();
    cout << "List forward: ";
    list.print();

    return 0;
}
