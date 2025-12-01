# Messaging-Platform-with-OOPS-Structured-Enquiry-4th-Sem


A console-based messaging application built using Object-Oriented Programming principles in C++.
It supports user login, multimedia messaging (text, image, voice notes), chat history viewing, and conversation management using polymorphism.

---

## 🚀 **Problem Statement**

This project aims to build a functional **messaging platform** using C++, allowing users to send and receive text, image, and voice note messages. It implements user login, conversation handling, message categorization, and chat history viewing. The system demonstrates OOP concepts such as abstraction, inheritance, and polymorphism to simulate real-world chat application behavior.

---

## ✨ **Features**

* **User Authentication:** Users can create accounts and log in securely.
* **Multimedia Messaging:** Supports Text, Image/GIF, and Voice Note messages.
* **Message Categorization:** Separate classes for sent and received messages.
* **OOP-Based Design:** Uses inheritance, virtual functions, and polymorphism.
* **Conversation Management:** Stores all chats per user using dynamic memory.
* **View Chat History:** Displays all messages exchanged with any user.
* **Menu-driven Interface:** Simple and interactive console UI.
* **Error Handling:** Safe execution using try–catch blocks.
* **Memory Safety:** Proper deletion of dynamically allocated objects.

---

## 🛠 **Tech Stack**

* Language: **C++**
* Paradigm: **Object-Oriented Programming**
* Concepts Used:

  * Inheritance
  * Polymorphism
  * Abstraction
  * Dynamic Memory Allocation
  * Exception Handling

---

## 📁 **Project Structure**

```
Message (Base Class)
 ├── TextMessage
 ├── ImageMessage
 ├── VoiceNoteMessage
 ├── ReceivedTextMessage
 ├── ReceivedImageMessage
 └── ReceivedVoiceNoteMessage

Conversation (Base Class)
 └── MultimediaConversation

Logindetails (User Credentials)
```

## 📸 **Sample Output (Console)**

```
WELCOME TO THE MESSAGING PLATFORM
1. Start Conversation
2. View Chats
3. Send Message
4. Receive Message
5. Exit
```

# **📘 CLASS DESCRIPTIONS (3–4 lines each)**

### **1. Message (Base Class)**

Represents a generic message with common attributes like message content.
Contains a pure virtual function `getType()` to be overridden by all message types.
Acts as the parent class for all sent and received message types.

### **2. TextMessage / ImageMessage / VoiceNoteMessage**

Derived classes for sent messages.
Each overrides `getType()` to return its message label (e.g., "Sent Text").
Stores the content (text or filename) of the message.

### **3. ReceivedTextMessage / ReceivedImageMessage / ReceivedVoiceNoteMessage**

Handles received versions of all message types.
Overrides `getType()` with labels like “Received Text”.
Used to store messages received from other users.

### **4. Logindetails**

Stores username, password, and basic user statistics.
Used for authentication during login and account creation.
Keeps simple user-related data for the application.

### **5. Conversation (Abstract Base Class)**

Represents a conversation for a specific user.
Maintains a vector of polymorphic Message pointers.
Defines virtual methods for starting and receiving conversations.

### **6. MultimediaConversation**

Implements conversation features like sending & receiving multimedia messages.
Provides menu-based interaction for users.
Handles storage and categorization of messages.

---

# **📐 UML CLASS DIAGRAM (TEXT-BASED)**

```
                   +-------------------+
                   |      Message      |
                   +-------------------+
                   | - content: string |
                   +-------------------+
                   | + getType()       |
                   | + getContent()    |
                   +-------------------+
                          ^
     -------------------------------------------------
     |               |               |               |
+-------------+ +-------------+ +-------------+ +---------------+
| TextMessage | | ImageMessage| | VoiceNote   | | ReceivedText  |
+-------------+ +-------------+ +-------------+ +---------------+
| getType()   | | getType()   | | getType()   | | getType()     |
+-------------+ +-------------+ +-------------+ +---------------+

     Similar subclasses:
     - ReceivedImageMessage
     - ReceivedVoiceNoteMessage

                    +------------------------+
                    |     Conversation       |
                    +------------------------+
                    | - username: string     |
                    | - messages: vector<>   |
                    +------------------------+
                    | + startConversation()  |
                    | + startreceivedConv()  |
                    +------------------------+
                             ^
                             |
                    +------------------------+
                    |  MultimediaConversation |
                    +------------------------+
                    | + sendTextMessage()    |
                    | + sendImageMessage()   |
                    | + sendVoiceNoteMessage()|
                    +------------------------+

+---------------------+
|    Logindetails     |
+---------------------+
| username: string    |
| password: string    |
+---------------------+
```

