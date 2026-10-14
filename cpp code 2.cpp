#include <iostream>
#include <string>

using namespace std;

// Structure to store vehicle details
struct Node
{
    int vehicleNo;       // Stores vehicle number
    string ownerName;    // Stores owner's name
    Node* next;          // Pointer to the next node
};

Node* head = NULL;       // Global head pointer for the linked list

// Global variables to manage parking capacity
const int MAX_CAPACITY = 5; // Maximum capacity of the parking lot
int currentCount = 0;       // Counter for currently parked vehicles


// 1. Function to insert a new vehicle
void addVehicle()
{
    // Check if the parking lot is full
    if (currentCount >= MAX_CAPACITY)
    {
        cout << "\n--- Parking is Full! No more space available. ---\n";
        return; // Return immediately without allocating memory
    }

    // Allocate memory for the new vehicle node
    Node* newNode = new Node;

    cout << "\nEnter Vehicle Number: ";
    cin >> newNode->vehicleNo;

    cout << "Enter Owner Name: ";
    cin >> newNode->ownerName;

    newNode->next = NULL;

    // If the list is empty, make the new node the head
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        // Traverse to the last node
        Node* temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        // Link the last node to the new node
        temp->next = newNode;
    }

    currentCount++; // Increment the vehicle count on successful addition
    cout << "\nVehicle Added Successfully!\n";
}


// 2. Function to display all parked vehicles
void display()
{
    Node* temp = head;

    // Check if the parking lot is empty
    if (head == NULL)
    {
        cout << "\nParking is Empty\n";
        return;
    }

    // Display the current capacity status
    cout << "\n--- Parked Vehicles ---\n";
    cout << "Total Occupied: " << currentCount << " / " << MAX_CAPACITY << "\n\n";

    // Loop through the list to print vehicle details
    while (temp != NULL)
    {
        cout << "Vehicle No: " << temp->vehicleNo << " | Owner: " << temp->ownerName << endl;
        temp = temp->next; // Move to the next node
    }
}


// 3. Function to search for a vehicle by its number
void searchVehicle()
{
    Node* temp = head;
    int no;

    cout << "\nEnter Vehicle Number: ";
    cin >> no;

    // Search the linked list sequentially
    while (temp != NULL)
    {
        if (temp->vehicleNo == no)
        {
            cout << "\nVehicle Found!";
            cout << "\nOwner: " << temp->ownerName << endl;
            return; // Exit function once found
        }
        temp = temp->next;
    }

    // If loop ends without returning, vehicle doesn't exist
    cout << "\nVehicle Not Found!\n";
}


// 4. Function to delete/remove a vehicle from parking
void deleteVehicle()
{
    Node* temp = head;
    Node* prev = NULL;
    int no;

    cout << "\nEnter Vehicle Number to Remove: ";
    cin >> no;

    // Traverse to find the node to be deleted and track its previous node
    while (temp != NULL && temp->vehicleNo != no)
    {
        prev = temp;
        temp = temp->next;
    }

    // If the vehicle number is not found in the system
    if (temp == NULL)
    {
        cout << "\nVehicle Not Found!\n";
        return;
    }

    // If the node to be deleted is the head node
    if (prev == NULL)
    {
        head = temp->next;
    }
    else
    {
        // Bypass the target node to remove it from the list chain
        prev->next = temp->next;
    }

    delete temp; // Free up the allocated memory
    currentCount--; // Decrement the vehicle count
    cout << "\nVehicle Removed Successfully!\n";
}


// Main function handling the interactive menu system
int main()
{
    int choice;

    while (true)
    {
        cout << "\n===== PARKING MANAGEMENT =====\n";
        cout << "1. Add Vehicle\n";
        cout << "2. Display Vehicles\n";
        cout << "3. Search Vehicle\n";
        cout << "4. Remove Vehicle\n";
        cout << "5. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                addVehicle();
                break;
            case 2:
                display();
                break;
            case 3:
                searchVehicle();
                break;
            case 4:
                deleteVehicle();
                break;
            case 5:
                cout << "\nThank you for using the Parking System!\n";
                return 0; // Terminate program execution
            default:
                cout << "\nInvalid Choice! Please try again.";
        }
    }
    return 0;
}
