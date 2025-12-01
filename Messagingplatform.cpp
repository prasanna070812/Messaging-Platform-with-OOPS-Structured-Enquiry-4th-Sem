/*You are developing a multiplayer game in C++ where multiple
players can interact with each other in a virtual world.
 How would you design classes and functions to handle player interactions,
 synchronization between players, and game logic for collaborative gameplay experiences?*/

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

// Base class for all message types
class Message
{
protected:
    string content;

public:
    Message(const string &content) : content(content) {}
    virtual string getType() const = 0;
    virtual string getContent() const
    {
        return content;
    }
    virtual ~Message() {}
};

// Derived class for text messages
class TextMessage : public Message
{
public:
    TextMessage(const string &content) : Message(content) {}
    string getType() const override
    {
        return "\t\tSent Text";
    }
};

// Derived class for image messages
class ImageMessage : public Message
{
public:
    ImageMessage(const string &content) : Message(content) {}
    string getType() const override
    {
        return "\t\tSent Image";
    }
};

// Derived class for voice note messages
class VoiceNoteMessage : public Message
{
public:
    VoiceNoteMessage(const string &content) : Message(content) {}
    string getType() const override
    {
        return "\t\tSent Voice Note";
    }
};

// Derived class for received text messages
class ReceivedTextMessage : public Message
{
public:
    ReceivedTextMessage(const string &content) : Message(content) {}
    string getType() const override
    {
        return "Received Text";
    }
};

// Derived class for received image messages
class ReceivedImageMessage : public Message
{
public:
    ReceivedImageMessage(const string &content) : Message(content) {}
    string getType() const override
    {
        return "Received Image";
    }
};

// Derived class for received voice note messages
class ReceivedVoiceNoteMessage : public Message
{
public:
    ReceivedVoiceNoteMessage(const string &content) : Message(content) {}
    string getType() const override
    {
        return "Received Voice Note";
    }
};

class Logindetails
{
private:
    string pass;

public:
    string username;
    int friends;
    float co;
    Logindetails(string a, string f, int c, float g)
    {
        pass = a;
        username = f;
        friends = c;
        co = g;
    }
};

// Base class for all conversation types
class Conversation
{
protected:
    string username;
    vector<Message *> messages; // Store multiple messages for each user

public:
    virtual void startConversation() = 0;
    virtual void startreceivedConversation() = 0;

    string getUsername() const
    {
        return username;
    }

    const vector<Message *> &getMessages() const
    {
        return messages;
    }

    vector<Message *> &getMutableMessages()
    {
        return messages;
    }

    virtual ~Conversation()
    {
        for (auto msg : messages)
        {
            delete msg;
        }
    }
};

// Derived class for a conversation with multimedia support
class MultimediaConversation : public Conversation
{
public:
    void startConversation() override
    {
        try
        {
            cout << "Enter the username you want to send a message to: ";
            getline(cin, username);

            int ch;
            do
            {
                // Clear the screen
                cout << "\n\t\t-----------------------------\n";
                cout << "\t\tSelect type of message:\n";
                cout << "\t\t-----------------------------\n";
                cout << "\t\t1. Send Text Messages\n";
                cout << "\t\t2. Send Image or GIF\n";
                cout << "\t\t3. Send Voice Note\n";
                cout << "\t\t4. Back\n";
                cout << "\t\t-----------------------------\n";
                cout << "Enter your choice: ";
                cin >> ch;
                cin.ignore(); // Clear newline character from buffer

                switch (ch)
                {
                case 1:
                    sendTextMessage();
                    break;
                case 2:
                    sendImageMessage();
                    break;
                case 3:
                    sendVoiceNoteMessage();
                    break;
                case 4:
                    break;
                default:
                    cout << "Error  :  Invalid choice!\n";
                }
            } while (ch != 4);
        }
        catch (const exception &e)
        {
            cout << "An error occurred: " << e.what() << endl;
        }
    }

    void startreceivedConversation() override
    {
        try
        {
            cout << "Enter the username from whom message received: ";
            getline(cin, username);

            int ch;
            do
            {
                // Clear the screen
                cout << "\n\t\t-----------------------------\n";
                cout << "\t\tSelect type of message to received:\n";
                cout << "\t\t-----------------------------\n";
                cout << "\t\t1. Received Text Message\n";
                cout << "\t\t2. Received Image Message\n";
                cout << "\t\t3. Received Voice Note Message\n";
                cout << "\t\t4. Back\n";
                cout << "\t\t-----------------------------\n";
                cout << "Enter your choice: ";
                cin >> ch;
                cin.ignore(); // Clear newline character from buffer

                switch (ch)
                {
                case 1:
                    receiveTextMessage();
                    break;
                case 2:
                    receiveImageMessage();
                    break;
                case 3:
                    receiveVoiceNoteMessage();
                    break;
                case 4:
                    break;
                default:
                    cout << "Invalid choice!\n";
                }
            } while (ch != 4);
        }
        catch (const exception &e)
        {
            cout << "An error occurred while receiving the message: " << e.what() << endl;
        }
    }

    void sendTextMessage()
    {
        try
        {
            cout << "Enter your message:\n";
            string input;
            getline(cin, input);
            messages.push_back(new TextMessage(input)); // Store each message
        }
        catch (const exception &e)
        {
            cout << "An error occurred while sending the text message: " << e.what() << endl;
        }
    }

    void sendImageMessage()
    {
        try
        {
            cout << "Enter the filename of the image (Add .jpg at end):\n";
            string input;
            getline(cin, input);
            messages.push_back(new ImageMessage(input)); // Store each message
        }
        catch (const exception &e)
        {
            cout << "An error occurred while sending the image message: " << e.what() << endl;
        }
    }

    void sendVoiceNoteMessage()
    {
        try
        {
            cout << "Enter the filename of the voice note (Add .acc at end):\n";
            string input;
            getline(cin, input);
            messages.push_back(new VoiceNoteMessage(input)); // Store each message
        }
        catch (const exception &e)
        {
            cout << "An error occurred while sending the voice note message: " << e.what() << endl;
        }
    }

    void receiveMessage()
    {
        try
        {
            int ch;
            do
            {
                // Clear the screen
                cout << "\n\t\t-----------------------------\n";
                cout << "\t\tSelect type of message to receive:\n";
                cout << "\t\t-----------------------------\n";
                cout << "\t\t1. Receive Text Message\n";
                cout << "\t\t2. Receive Image Message\n";
                cout << "\t\t3. Receive Voice Note Message\n";
                cout << "\t\t4. Back\n";
                cout << "\t\t-----------------------------\n";
                cout << "Enter your choice: ";
                cin >> ch;
                cin.ignore(); // Clear newline character from buffer

                switch (ch)
                {
                case 1:
                    receiveTextMessage();
                    break;
                case 2:
                    receiveImageMessage();
                    break;
                case 3:
                    receiveVoiceNoteMessage();
                    break;
                case 4:
                    break;
                default:
                    cout << "Invalid choice!\n";
                }
            } while (ch != 4);
        }
        catch (const exception &e)
        {
            cout << "An error occurred while receiving the message: " << e.what() << endl;
        }
    }

    void receiveTextMessage()
    {
        try
        {
            cout << "Enter the received text message: ";
            string input;
            getline(cin, input);
            messages.push_back(new ReceivedTextMessage(input)); // Store the received text message
        }
        catch (const exception &e)
        {
            cout << "An error occurred while receiving the text message: " << e.what() << endl;
        }
    }

    void receiveImageMessage()
    {
        try
        {
            cout << "Enter the filename of the received image (Add .jpg at end): ";
            string input;
            getline(cin, input);
            messages.push_back(new ReceivedImageMessage(input)); // Store the received image message
        }
        catch (const exception &e)
        {
            cout << "An error occurred while receiving the image message: " << e.what() << endl;
        }
    }

    void receiveVoiceNoteMessage()
    {
        try
        {
            cout << "Enter the filename of the received voice note (Add .acc at end): ";
            string input;
            getline(cin, input);
            messages.push_back(new ReceivedVoiceNoteMessage(input)); // Store the received voice note message
        }
        catch (const exception &e)
        {
            cout << "An error occurred while receiving the voice note message: " << e.what() << endl;
        }
    }
};

void displayConversations(const vector<Conversation *> &conversations)
{
    // Clear the screen
    cout << "\t\t----------------\n";
    cout << "\t\tCHATS:\n";
    cout << "\t\t----------------\n";
    for (const auto &convo : conversations)
    {
        cout << "\t\t" << convo->getUsername() << endl;
    }

    string user;
    cout << "\nEnter the username whose conversation you want to see: ";
    getline(cin, user);

    bool userFound = false;

    // Check if the user exists in the CHATS
    for (const auto &convo : conversations)
    {
        if (convo->getUsername() == user)
        {
            userFound = true;
            cout << "\n\t--------------------\n";
            cout << "\tConversation with " << user << ":\n";
            cout << "\t----------------------\n";
            for (const auto &message : convo->getMessages())
            {
                cout << message->getType() << ": " << message->getContent() << endl;
            }
            break;
        }
    }

    if (!userFound)
    {
        cout << "User " << user << " not found in the CHATS!\n";
    }
}

void sendMessageToUser(vector<Conversation *> &conversations, const string &user)
{
    // Check if the user exists in the CHATS
    bool userFound = false;
    for (auto &convo : conversations)
    {
        if (convo->getUsername() == user)
        {
            userFound = true;
            int ch;
            do
            {
                // Clear the screen
                cout << "\n\t\t-----------------------------\n";
                cout << "\t\tSelect type of message:\n";
                cout << "\t\t-----------------------------\n";
                cout << "\t\t1. Send Text Messages\n";
                cout << "\t\t2. Send Image or GIF\n";
                cout << "\t\t3. Send Voice Note\n";
                cout << "\t\t4. Back\n";
                cout << "\t\t-----------------------------\n";
                cout << "Enter your choice: ";
                cin >> ch;
                cin.ignore(); // Clear newline character from buffer

                try
                {
                    switch (ch)
                    {
                    case 1:
                    {
                        cout << "Enter your message to " << user << ": ";
                        string message;
                        getline(cin, message);
                        convo->getMutableMessages().push_back(new TextMessage(message)); // Add the message to the user's conversation
                        cout << "Message sent to " << user << "!\n\n";
                        break;
                    }
                    case 2:
                    {
                        cout << "Enter the filename of the image (Add .jpg at end): ";
                        string message;
                        getline(cin, message);
                        convo->getMutableMessages().push_back(new ImageMessage(message)); // Add the message to the user's conversation
                        cout << "Image sent to " << user << "!\n\n";
                        break;
                    }
                    case 3:
                    {
                        cout << "Enter the filename of the voice note (Add .acc at end): ";
                        string message;
                        getline(cin, message);
                        convo->getMutableMessages().push_back(new VoiceNoteMessage(message)); // Add the message to the user's conversation
                        cout << "Voice Note sent to " << user << "!\n\n";
                        break;
                    }
                    case 4:
                        break;
                    default:
                        cout << "Invalid choice!\n";
                    }
                }
                catch (const exception &e)
                {
                    cout << "An error occurred: " << e.what() << endl;
                }
            } while (ch != 4);
            return;
        }
    }

    if (!userFound)
    {
        cout << "User " << user << " not found in the CHATS!\n";
    }
}

int main()
{
    try
    {
        cout << "\t\t--------------------------------------------------------------" << endl;
        cout << "\t\t\t   Blast off into the world of messaging! " << endl;
        cout << "\t\t--------------------------------------------------------------" << endl;
        cout << "\t\t       W   W  EEEEE  L      CCCCC   OOOOO  M     M  EEEEE\n";
        cout << "\t\t       W   W  E      L     C       O     O MM   MM  E\n";
        cout << "\t\t       W W W  EEEE   L     C       O     O M M M M  EEEE\n";
        cout << "\t\t       WW WW  E      L     C       O     O M  M  M  E\n";
        cout << "\t\t       W   W  EEEEE  LLLLL  CCCCC   OOOOO  M     M  EEEEE\n";
        cout << "\t\t--------------------------------------------------------------" << endl;
        cout << "\t\t\t   Step into our colorful chat universe! " << endl;
        cout << "\t\t--------------------------------------------------------------" << endl;
        char ch;
        string cuname = "shantanu", cpass = "shantanu", uname, pass;
        cout << "\n\t\t===============================================\n";
        cout << "\t\tEnter Login (L) or Create Account (C): ";
        cin >> ch;
        cin.ignore();

        switch (ch)
        {
        case 'c':
        case 'C':
            cout << "\t\tCreating New Account: " << endl;
            cout << "\t\tEnter Username: ";
            getline(cin, cuname);
            cout << "\t\tEnter Password: ";
            getline(cin, cpass);
            cout << "\t\tAccount Created successfully\n\n";
        case 'l':
        case 'L':
            cout << "\t\tEnter Login Details: " << endl;
            cout << "\t\tEnter Username: ";
            getline(cin, uname);
            cout << "\t\tEnter Password: ";
            getline(cin, pass);
            if (cuname == uname && cpass == pass)
            {
                cout << "\t\tLogin Successful\n"
                     << endl;
                cout << "\t\t===============================================\n";
            }
            else
            {
                cout << "\t\tInvalid Login Details..\n"
                     << endl;
                cout << "\t\t===============================================\n";
                exit(0);
            }
            break;
        default:
            throw invalid_argument("Invalid choice! Please enter 'L' for login or 'C' for create account.");
        }

        vector<Conversation *> conversations;
        int choice;

        if (conversations.empty())
        {
            cout << "Empty CHATS\n";
        }

        do
        {
            cout << "Press Enter to continue...";
            cin.get();
            system("cls"); // Clear the screen
            cout << "\n\t\t-----------------------------\n";
            cout << "\t\tCHAT Operations:\n";
            cout << "\t\t-----------------------------\n";
            cout << "\t\t1. Start a new multimedia conversation\n";
            cout << "\t\t2. View CHATS\n";
            cout << "\t\t3. Send message to specific user\n";
            cout << "\t\t4. Receive message\n";
            cout << "\t\t5. Exit\n";
            cout << "\t\t-----------------------------\n";
            cout << "Enter your choice: ";
            cin >> choice;
            cin.ignore(); // Clear newline character from buffer

            switch (choice)
            {
            case 1:
            {
                try
                {
                    Conversation *newConversation = new MultimediaConversation();
                    newConversation->startConversation();
                    conversations.push_back(newConversation);
                }
                catch (const exception &e)
                {
                    cout << "An error occurred while starting a new conversation: " << e.what() << endl;
                }
                break;
            }
            case 2:
            {
                if (conversations.empty())
                {
                    cout << "Empty CHATS\n";
                }
                else
                {
                    displayConversations(conversations);
                }
                break;
            }
            case 3:
            {
                if (conversations.empty())
                {
                    cout << "No conversations to send a message to.\n";
                }
                else
                {
                    string user;
                    cout << "Enter the username you want to send a message to: ";
                    getline(cin, user);
                    sendMessageToUser(conversations, user);
                }
                break;
            }
            case 4:
            {
                string user;
                cout << "Enter the username from whom messages received: ";
                getline(cin, user);

                bool existingConversation = false;
                // Check if the user exists in the CHATS
                for (auto &convo : conversations)
                {
                    if (convo->getUsername() == user)
                    {
                        existingConversation = true;
                        static_cast<MultimediaConversation *>(convo)->receiveMessage();
                        break;
                    }
                }

                if (!existingConversation)
                {
                    Conversation *newConversation = new MultimediaConversation();
                    newConversation->startreceivedConversation();
                    conversations.push_back(newConversation);
                }

                break;
            }
            case 5:
            {
                system("cls");
                cout << "\n\t\t===============================================\n";
                cout << "\t\tLogging Out...";
                cout << endl;

                cout << "\t\tLogged Out Successfully.";
                cout << "\n\t\t===============================================\n";
                cout << endl<<endl<<endl<<endl;
                cout << "\t\t--------------------------------------------------------------" << endl;
                cout << "\t\t\t   Thank you for choosing our messaging platform! " << endl;
                cout << "\t\t--------------------------------------------------------------" << endl;
                cout <<  "\tTTTTTTTTTT  HH    HH   AAAA    NN     NN  KK    KK  YYY YYY   OOOOO  UU    UU" << endl;
                cout <<  "\t    TT      HH    HH  AA  AA   NNN    NN  KK  KK     YY YY   OO   OO UU    UU" << endl;
                cout <<  "\t    TT      HHHHHHHH  AAAAAA   NN NN  NN  KKKK        YYY    OO   OO UU    UU" << endl;
                cout <<  "\t    TT      HH    HH  AA  AA   NN  NN NN  KK  KK      YYY    OO   OO UU    UU" << endl;
                cout <<  "\t    TT      HH    HH  AA  AA   NN    NNN  KK    KK    YYY     OOOOO   UUUUUU" << endl;
                cout << "\t\t--------------------------------------------------------------" << endl;
                cout << "\t\t\t     Your support means the world to us. " << endl;
                cout << "\t\t--------------------------------------------------------------" << endl;
                break;
            }
            default:
                cout << "Invalid choice! Try again...\n";
            }
        } while (choice != 5);

        // Clean up dynamic memory
        for (auto convo : conversations)
        {
            delete convo;
        }
    }
    catch (const exception &e)
    {
        cout << "An error occurred: " << e.what() << endl;
    }

    return 0;
}
