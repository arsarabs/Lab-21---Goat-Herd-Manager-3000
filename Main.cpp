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


    // push_back() inserts a Goat object at the end of the list
    void push_back(const Goat& goat) {
        // Create a new node with the Goat object, current tail as previous, and no next node
        Node* newNode = new Node(goat, nullptr, head);
        if (!tail)  // if there's no tail, the list is empty
            head = tail = newNode; // Head and tail both point to the new node
        else {
            tail->next = newNode; // head and tail both point to the new node
            newNode->prev = tail; // current tail's next points to new node
            tail = newNode; //update 
        }
    }
    // push_front() inserts a Goat object at the front of the list
    void push_front(const Goat& goat) {
        // Create a new node with the Goat object, no previous node, and current head as next
        Node* newNode = new Node(goat, nullptr, head);
        if (!head)  // if there's no head, the list is empty
            head = tail = newNode; // head and tail both point to the new node
        else {
         
            head->prev = newNode;  // current head's previous points to new node
            head = newNode; //update
        }
    }



    //PUSH FRONT/PUSH BACK COMPLETE, WORK BELOW





    void insert_after(const Goat& goat, int position) {
        if (position < 0) {
            cout << "Position must be >= 0." << endl;
            return;
        }

        Node* temp = head; // starting from head

        //transverse 
        for (int i = 0; i < position && temp != nullptr; ++i) {
            temp = temp->next;
        }

        if (temp == nullptr) { // If position exceeds list size
            cout << "Position exceeds list size. Node not inserted." << endl;
            return;
        }
        // Create a new node with the Goat object, temp as previous, and temp->next as next
        Node* newNode = new Node(goat, temp, temp->next);
        if (temp->next) { // If not inserting at the end
            temp->next->prev = newNode; // Update the next node's previous pointer
        }
        else {
            tail = newNode; // If inserting at the end, update tail
        }
        temp->next = newNode; // Update temp's next to the new node
     
    }

    void delete_node(const string& name) {
        if (!head) { // If the list is empty
            cout << "List is empty. Cannot delete." << endl;
            return;
        }

        Node* temp = head;
        while (temp && temp->data.get_name() != name)
            temp = temp->next;

        if (!temp) { // If Goat with the specified name is not found
            cout << "Goat with name \"" << name << "\" not found." << endl;
            return;
        }

        // adjusting previous nodes next ptr
        if (temp->prev) {
            temp->prev->next = temp->next;
        }
        else {
            head = temp->next; // Deleting the head
        }
        // adjusting next nodes next ptr
        if (temp->next) {
            temp->next->prev = temp->prev;
        }
        else {
            tail = temp->prev; // Deleting the tail
        }

        delete temp; // free memory to avoid leak
    }
    // print() displays the Goat objects from head to tail
    void print() {
        if (!head) { // If the list is empty
            cout << "List is empty" << endl;
            return;
        }
        Node* current = head; //starting from head
        if (!current) return;
        while (current) { // Traverse the list
            cout << current->data.get_description() << " ";
            current = current->next; //next node
        }
        cout << endl;
    }

    // print_reverse() displays the Goat objects from tail to head
    void print_reverse() {
        if (!tail) { // If the list is empty
            cout << "List is empty" << endl;
            return;
        }

        Node* current = tail; // Start from the tail
        if (!current) return;
        while (current) {
            cout << current->data.get_description() << " ";
            current = current->prev; //prevoius node
        }
        cout << endl;
    }

    // Destructor deletes all nodes and frees the memory
    ~DoublyLinkedList() {
        Node* current = head; // Start from the head
        while (current) { // Traverse the list
            Node* temp = current; // Temporary pointer to current node
            current = current->next; // Move to the next node
            delete temp; // Delete the current node
        }
    }
};
 
//Protoype
int get_random_list_size();

// Driver program
int main() {
  

    return 0;
}

int get_random_list_size() {

}
