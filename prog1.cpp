#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};
class Linked_list
{
public:
    Node *head;
    int size;
    Linked_list()
    {
        head = nullptr;
        size = 0;
    }
    void insertAt_Front(int data)
    {
        Node *for_front = new Node(data);
        if (this->head == nullptr)
        {
            this->head = for_front;
        }
        else
        {
            for_front->next = this->head;
            this->head = for_front;
        }
    }
    void insertAt_End(int data)
    {
        Node *for_end = new Node(data);
        if (this->head == NULL)
        {
            this->head = for_end;
        }
        else
        {
            Node *ptr = this->head;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = for_end;
        }
        this->size++;
    }
    void deleteAt_Front()
    {
        if (this->head == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }
        Node *for_Delete = this->head;
        this->head = this->head->next;
        delete for_Delete;
    }
    void deleteAt_End()
    {
        if (this->head == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }
        if (this->head->next == nullptr)
        {
            delete this->head;
            this->head = nullptr;
            return;
        }
        Node *temp = this->head;
        while (temp->next->next != nullptr)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }
    void insertAt_Index(int index, int data)
    {
        Node *for_index = new Node(data);
        if (index == 0)
        {
            insertAt_Front(data);
        }
        else if (index > 0 && index <= this->size)
        {
            Node *temp = this->head;
            for (int i = 0; i < index; i++)
            {
                temp = temp->next;
            }
            for_index->next = temp->next;
            temp->next = for_index;
        }
        size++;
    }

    void updateAt_Index(int index, int data)
    {
        if (index == 0)
        {
            this->head->data = data;
        }
        else if (index > 0 && index <= this->size)
        {
            Node *temp = this->head;
            for (int i = 0; i < index; i++)
            {
                temp = temp->next;
            }
            temp->data = data;
        }
    }
    void deleteAt_Index(int index)
    {
        if (index == 0)
        {
            Node *for_indxDelete = this->head;
            this->head = this->head->next;
            delete for_indxDelete;
        }
        else if (index > 0 && index <= this->size)
        {
            Node *temp = this->head;
            for (int i = 0; i < index - 1; i++)
            {
                temp = temp->next;
            }
            Node *for_indxdelete = temp->next;
            temp->next = temp->next->next;
            delete for_indxdelete;
        }
    }
    void display_List()
    {
        Node *temp = this->head;
        while (temp != nullptr)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    Linked_list list;
    int index, data, choice;
    cout << "-----------Linked List Operations------------" << endl
         << endl;
    do
    {
        cout << "Enter 1 for Insert at Front" << endl;
        cout << "Enter 2 for Insert at End" << endl;
        cout << "Enter 3 for Insert at Index" << endl;
        cout << "Enter 4 for Update at Index" << endl;
        cout << "Enter 5 for Delete at Index" << endl;
        cout << "Enter 6 for Display the list" << endl;
        cout << "Enter 0 for exit" << endl;

        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the data to insert at front: ";
            cin >> data;
            list.insertAt_Front(data);
            break;
        case 2:
            cout << "Enter the data to insert at end: ";
            cin >> data;
            list.insertAt_End(data);
            break;

        case 3:
            cout << "Enter the index to insert at: ";
            cin >> index;
            cout << "Enter the data to insert at index " << index << ": ";
            cin >> data;
            list.insertAt_Index(index, data);
            break;

        case 4:
            cout << "Enter the index to update: ";
            cin >> index;
            cout << "Enter the data to update at index " << index << ": ";
            cin >> data;
            list.updateAt_Index(index, data);
            break;

        case 5:
            cout << "Enter the index to delete: ";
            cin >> index;
            list.deleteAt_Index(index);
            break;

        case 6:
            cout << "The linked list is: ";
            list.display_List();
            break;

        case 0:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (choice != 0);

    return 0;
}