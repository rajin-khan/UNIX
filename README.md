# Grocery Management System - UNIX

## Vision

UNIX aims to create a streamlined grocery management system that is efficient, quick, and takes up minimal space.

## Code Breakdown

**Structure**: Designed to simplify the grocery item list by removing unnecessary elements like QR codes and stock, while storing price as a string for space efficiency.

**Main Function**: User-friendly interface with a main menu allowing users to navigate through various tasks. Additional option provided to return to the main menu or exit the program after task completion.

**Recalling the Main Menu**: Deceptively simple logic recalls the main menu by calling a void function, `main_menu`, to maintain a streamlined user experience.

**Adding Products**: Non-void function adds products to the inventory while verifying price input to ensure correctness and prevent overflow.

**Viewing Products**: Utilizes a new array to display product information from the inventory file, enhancing program reliability.

**Searching for Products**: Void function scans and compares search key with product names to display product information upon match.

**Deleting Products**: Items are deleted from the inventory file by shifting array elements and rewriting the file with updated data.

**Updating Products**: Allows users to update product information by searching for and replacing existing records in the inventory file.

## Collaborators

- [Adib Ar Rahman Khan](https://github.com/rajin-khan)
- [Saumik Saha Kabbya](https://github.com/Kabbya04)
- [Samiyeel Alim Binaaf](https://github.com/Pronaaf2k)

## Technologies Used

- Language: Basic C
- Framework: None
- Environment: Terminal application
