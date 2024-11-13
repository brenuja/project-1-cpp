Banking System in C++

 Description
This is a simple banking system built in C++ as a first project by B Renuja. The application allows users to create new accounts, deposit and withdraw money, view account details, and manage multiple accounts using a binary file for persistent storage.

 Features
- Account Creation: Users can create new accounts by providing their name, account number, and initial deposit amount.
- Deposit and Withdrawal: Users can deposit to or withdraw from their account balance.
- Account Details: Users can view details for a specific account or get a list of all account holders.
- File Storage: Data is stored in a binary file (`info.dat`) for persistence, allowing account details to be saved between sessions.

 Installation
To set up and run this project on your local machine:

1. Clone this repository:
   ```bash
   git clone https://github.com/brenuja/project-1-cpp.git
   ```

2. Navigate to the project directory:
   ```bash
   cd project-1-cpp
   ```

3. Compile the code:
   ```bash
   g++ main.cpp -o banking_system
   ```

4. Run the application:
   ```bash
   ./banking_system
   ```

Usage
1. When you start the application, a menu with options appears:
   - 1: Create a new account.
   - 2: Deposit money to an existing account.
   - 3: Withdraw money from an existing account.
   - 4: View details of a specific account.
   - 5: View details of all accounts.
   - 6: Exit the program.

2. Select the desired option by entering the corresponding number and follow the prompts.

 Example
```plaintext
1. Create new account:
2. Deposit amount:
3. Withdraw amount:
4. Get details of particular account:
5. Get details of all accounts:
6. Exit
Enter your choice: 1
Enter name: John Doe
Enter account number: 12345
Enter amount: 500
```

Known Issues
- `conio.h` and `clrscr()` may not work on non-Windows systems. Removing these lines should solve compatibility issues on Unix-based systems.

License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
