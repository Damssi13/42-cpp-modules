            // Class: Contact
Class Contact
    Private:
        string firstName
        string lastName
        string nickname
        string phoneNumber
        string darkestSecret
    
    Public:
        // Constructor
        Function Contact()
            Set firstName = ""
            Set lastName = ""
            Set nickname = ""
            Set phoneNumber = ""
            Set darkestSecret = ""
        
        // Function to set contact details
        Function setContactDetails(fn, ln, nn, pn, ds)
            Set firstName = fn
            Set lastName = ln
            Set nickname = nn
            Set phoneNumber = pn
            Set darkestSecret = ds
        
        // Function to check if contact is empty
        Function isEmpty()
            Return (firstName is empty OR lastName is empty OR nickname is empty OR 
                   phoneNumber is empty OR darkestSecret is empty)
        
        // Functions to get contact fields
        Function getFirstName()
            Return firstName
        Function getLastName()
            Return lastName
        Function getNickname()
            Return nickname
        Function getPhoneNumber()
            Return phoneNumber
        Function getDarkestSecret()
            Return darkestSecret

// Class: PhoneBook
Class PhoneBook
    Private:
        Contact contacts[8]  // Fixed array of 8 contacts
        integer oldestIndex  // Tracks the oldest contact to replace
    
    Public:
        // Constructor
        Function PhoneBook()
            Set oldestIndex = 0
            For i from 0 to 7
                Initialize contacts[i] as empty Contact
        
        // Function to add a contact
        Function addContact(newContact)
            If newContact.isEmpty() == false
                Set contacts[oldestIndex] = newContact
                Set oldestIndex = (oldestIndex + 1) mod 8
        
        // Function to display all contacts
        Function displayContacts()
            For i from 0 to 7
                If contacts[i].isEmpty() == false
                    Print formatted line with:
                        - Column 1: i (index)
                        - Column 2: truncate(contacts[i].getFirstName(), 10)
                        - Column 3: truncate(contacts[i].getLastName(), 10)
                        - Column 4: truncate(contacts[i].getNickname(), 10)
                    Each column is 10 chars wide, right-aligned, separated by '|'
                    If text > 10 chars, truncate and end with '.'
        
        // Function to display a specific contact by index
        Function displayContactByIndex(index)
            If index >= 0 AND index < 8 AND contacts[index].isEmpty() == false
                Print contacts[index].getFirstName()
                Print contacts[index].getLastName()
                Print contacts[index].getNickname()
                Print contacts[index].getPhoneNumber()
                Print contacts[index].getDarkestSecret()
            Else
                Print "Invalid index or empty contact!"

        // Helper Function to truncate text
        Function truncate(text, width)
            If length(text) > width
                Return substring(text, 0, width-1) + "."
            Else
                Return text padded with spaces to width


# The main flow
Program PhoneBook80s
    // Executable name: PhoneBook80s
    Declare PhoneBook myPhoneBook
    
    // Main loop
    While true
        Print "Enter command (ADD, SEARCH, EXIT): "
        Read input command
        
        If command == "EXIT"
            Print "Goodbye, 80s rockstar! Contacts lost to the void!"
            Break loop and exit program
        
        Else If command == "ADD"
            // Prompt for contact details
            Print "First Name: "
            Read firstName
            Print "Last Name: "
            Read lastName
            Print "Nickname: "
            Read nickname
            Print "Phone Number: "
            Read phoneNumber
            Print "Darkest Secret: "
            Read darkestSecret
            
            // Create new contact
            Declare Contact newContact
            Call newContact.setContactDetails(firstName, lastName, nickname, phoneNumber, darkestSecret)
            
            If newContact.isEmpty() == false
                Call myPhoneBook.addContact(newContact)
                Print "Contact added, totally rad!"
            Else
                Print "Error: All fields must be filled, dude!"
        
        Else If command == "SEARCH"
            Call myPhoneBook.displayContacts()
            Print "Enter index (0-7) to view details: "
            Read index
            
            If index is valid number
                Call myPhoneBook.displayContactByIndex(index)
            Else
                Print "Whoa, bad vibes! Invalid index!"
        
        Else
            Print "Invalid command, try ADD, SEARCH, or EXIT, neon warrior!"
        
        Print newline for readability