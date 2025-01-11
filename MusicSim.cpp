#include <iostream>
#include <string>

class SongNode //your songs
{
    public:
        std::string song; //member that stores name
        std::string artist; //member that stores artist
        SongNode* next;
        SongNode* previous;
};

//prototype functions
void addFirst(std::string s, std::string a);
void add_beginning(std::string s, std::string a);
void insert_after(int whatnode, std::string s, std::string a);
void print_DLL(SongNode* head);

//global pointer
SongNode* head;

int main()
{
    int killswitch = 0;
    //has to add a song to begin a playlist
    std::cout << "\nPlease enter first song name: ";
    std::string name;
    getline(std::cin, name);
    std::cout << "\nPlease enter artist name: ";
    std::string human;
    getline(std::cin, human);
    addFirst(name, human);
    print_DLL(head);

    while(killswitch == 0)
    {
        std::cout << "\n1. Add a song to play next";
        std::cout << "\n2. Add a song after a specific song";
        std::cout << "\n3. Print out Playlist";
        std::cout << "\n4. Leave Music Playlist";
        std::cout << "\nWhat would you like to do?: ";
        int choice;
        std::cin >> choice;
        std::cin.ignore();

        if(choice == 1)
        {
            std::cout << "\nPlease enter song name: ";
            std::string name;
            getline(std::cin, name);
            std::cout << "\nPlease enter artist name: ";
            std::string human;
            getline(std::cin, human);
            add_beginning(name, human);
            std::cout << "\n\"" << name << "\" has been added to the beginning\n";
        }

        else if(choice == 2)
        {
            std::cout << "\nPlease enter song name: ";
            std::string name;
            getline(std::cin, name);
            std::cout << "\nPlease enter artist name: ";
            std::string human;
            getline(std::cin, human);

            print_DLL(head);
            std::cout << "\nWhich song number do you want to add \"" << name << "\" after?: ";
            int whatnode;
            std::cin >> whatnode;
            std::cin.ignore();
            insert_after(whatnode, name, human);
            std::cout << "\n\"" << name << "\" has been added\n";

        }
        else if(choice == 3)
        {
            print_DLL(head);
        }
        else if(choice == 4)
        {
            std::cout << "\n\nThanks for listening!\n\n";
            killswitch = 1;
        }
        else
        {
            std::cout << "\nC'mon man, follow instructions...\n";
        }
    }
    
    return 0;
}

void addFirst(std::string s, std::string a)
{
    SongNode* node = new SongNode();    //creates a pointer to point to newly created node
    node->song = s; //sets values of new song equal to what user inputted
    node->artist = a;
    node->next = nullptr;   //sets new song's next ptr equal to nothing
    node->previous = nullptr;   //same idea
    head = node;    //the head pointer now points to new song
}

void add_beginning(std::string s, std::string a)
{
    SongNode* node = new SongNode();    //creates a pointer to point to the newly created song
    node->song = s;
    node->artist = a;
    node->previous = nullptr;    //this is done since this song will be the new beginning
    node->next = head; //new node will now point to previous head of playlist
    head->previous = node; //the previous pointer of the previous starting node now points to the new starting node
    head = node;   //new head of playlist is new node
}

void insert_after(int whatnode, std::string s, std::string a)
{
    //searches and finds song the user identifies
    SongNode* prevNode = head; //creates a traversing pointer that starts at the beginning of the playlist
    int position = 1; //counter
    
    while(position < whatnode)  //this loops moves the traversing pointer until it meets the song the user identified
    {
        prevNode = prevNode->next;  //this line is what moves the pointer across the playlist
        position++;
    }

    //create a new song
    SongNode* node = new SongNode();
    node->song = s;
    node->artist = a;

    //insertion of song
    node->next = prevNode->next;    //new song's next pointer will now point to whatever the previous node's next is pointing to
    node->previous = prevNode;  //new song's previous pointer will now point to the previous node
    
    if(prevNode->next != nullptr)   //this checks if the previous node is the end of the playlist
    {
    prevNode->next->previous = node;    //whatever node the previous node's next pointer was pointing to, that node's previous pointer will now point to the new song
    }

    prevNode->next = node; //the previous node's next pointer will now point to the new song
}

void print_DLL(SongNode* head)
{
    SongNode* traverser; // this node starts at the head and will traverse the playlist
    traverser = head;

    int num = 1;
    std::cout << "\n--------JOSHI PLAYLIST--------\n" << std::endl;
    while(traverser != nullptr) //this will loop until the traverser points to nothing (the end of the list)
    {
        std::cout << num << ". \"" << traverser->song << "\" by " << traverser->artist << std::endl;
        traverser = traverser->next; //moves along the playlist
        num++;
    }
    std::cout << "\n------------------------------\n" << std::endl;
}
