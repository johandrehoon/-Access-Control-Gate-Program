# Access Control Gate Program

This program provides a simple graphical interface for controlling access to a gate using a keypad. The interface allows users to input a password through a series of buttons and verify their access. The gate description and password are initialized in the program.

## Features

- **Graphical User Interface (GUI):** Built using Qt framework, offering an intuitive keypad for user interaction.
- **Keypad Input:** A keypad layout that includes digits (0-9), a hash (`#`), a clear button, and an enter button to submit the password.
- **Password Verification:** A simple password-based access control system that verifies the entered password.
- **Feedback Messages:** Provides users with informative messages for access granted, access denied, invalid password format, and password input requirements.

## Usage

The `main.cpp` file contains the implementation of the access control system. The program creates a GUI application using the Qt framework with the following components:

1. **Gate Initialization:** Creates a `Gate` object with a description ("Gate 1") and a password (1234).
2. **Keypad:** Allows users to input their password using the on-screen keypad. The input field is read-only and updated using button clicks.
3. **Password Verification:** The `Enter` button triggers the verification of the entered password. The password must end with a `#` character for the input to be valid. The application then checks if the password matches the one set for the gate.
4. **User Feedback:** Displays appropriate messages for access granted, denied, or invalid input.

## Example

After launching the program, users can:
- Enter their password using the keypad.
- End the password with `#` and press the "Enter" button.
- Receive a message indicating if access is granted or denied.

## Dependencies

- Qt framework (QtWidgets, QApplication)
- Custom classes:
  - `Gate.h`
- Qt environment is required to compile and run this program.

## How to Run

1. Install the Qt framework and set up a development environment.
2. Clone the repository and navigate to the directory containing `main.cpp`.
3. Compile the program using `qmake` and `make` commands:
   ```bash
   qmake
   make
