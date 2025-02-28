<p align="center">
  <img src="./unix_logo.png" width="400"/>
</p>

<h1 align="center">A Simple, Super Fast Grocery Management System</h1>

<div align="center">

![Contributions](https://img.shields.io/badge/Contributions-Welcome-blue?style=for-the-badge&logo=git)
![C Language](https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c)
![Terminal App](https://img.shields.io/badge/Environment-Terminal-black?style=for-the-badge&logo=gnu-bash)

---

## **🌟 Overview**

**UNIX Grocery Management System** is a lightweight and efficient terminal-based application designed to help users manage grocery inventory seamlessly. The system is optimized for performance, simplicity, and minimal memory usage.

### **Features at a Glance**
| Feature          | Functionality                                           |
|-----------------|---------------------------------------------------------|
| **Add Products**   | Insert new products into the inventory                 |
| **View Products**  | Display all stored items with details                  |
| **Search Products** | Find specific products by name                        |
| **Delete Products** | Remove unwanted products from the inventory           |
| **Update Products** | Modify existing product information                   |

---

## **🛠️ Code Breakdown**

### **📌 Structure**
The program is designed to be lightweight and efficient by:
- Removing unnecessary elements such as QR codes and stock tracking.
- Storing price values as strings to avoid integer overflow.
- Using file-based storage to persist inventory data.

### **📌 Main Functionality**
The main menu provides a simple interface for users to choose actions, with the ability to return to the menu or exit after completing a task.

```c
printf("1. Add Products\n");
printf("2. View Products\n");
printf("3. Search Products\n");
printf("4. Delete Products\n");
printf("5. Update Products\n");
```

---

## **🔍 Core Functionalities**

### **🛒 Add Products**
- Reads user input and appends items to `INVENTORY.txt`.
- Ensures valid price input by verifying numeric characters.
- Prevents inventory overflow beyond 100 items.

```c
if (counter == 100) {
  printf("Inventory full!\n");
}
```

---

### **📋 View Products**
- Loads inventory from file and displays product details in a structured format.
- Uses a secondary array to prevent memory corruption issues.

```c
printf("\n%s\n%s\n%s\n", inventory[i].prod_name, inventory[i].type, inventory[i].price);
```

---

### **🔍 Search Products**
- Uses a loop and `strcmp()` to match user queries with stored product names.
- Displays product details upon a successful match.

```c
if (strcmp(search_key, inventory[count].prod_name) == 0) {
  printf("Found: %s\n", inventory[count].prod_name);
}
```

---

### **🗑️ Delete Products**
- Finds a product based on name input and removes it.
- Shifts remaining items in the inventory array to fill the gap.
- Writes updated inventory back to file.

```c
for (int i = sk_idx; i < count - 1; i++) {
  strcpy(inventory[i].prod_name, inventory[i + 1].prod_name);
}
```

---

### **✏️ Update Products**
- Locates the product by name.
- Takes updated information and overwrites the existing entry.
- Ensures all fields are properly formatted.

```c
scanf(" %[^"]", up_name);
strcpy(inventory[i].prod_name, up_name);
```

---

## **📌 How to Run the Program**

### **💻 Compilation & Execution**

```bash
gcc projnewupdated.c -o grocery_management
./grocery_management
```

### **📌 Sample Run**

https://github.com/user-attachments/assets/b2d97aa6-973a-4022-b283-44c3e3ff3ee3

---

## **👥 Development Team:**
This project was developed by:

| Name                      | Institution             | ID | GitHub | Followers |
|---------------------------|-------------------------|--  |--------|------|
| **Rajin Khan**            | North South University | 2212708042 | [![Rajin's GitHub](https://img.shields.io/badge/-rajin--khan-181717?style=for-the-badge&logo=github&logoColor=white)](https://github.com/rajin-khan) | ![Followers](https://img.shields.io/github/followers/rajin-khan?label=Follow&style=social) |
| **Saumik Saha Kabbya**    | North South University | 2211204042 | [![Saumik's GitHub](https://img.shields.io/badge/-Kabbya04-181717?style=for-the-badge&logo=github&logoColor=white)](https://github.com/Kabbya04) | ![Followers](https://img.shields.io/github/followers/Kabbya04?label=Follow&style=social) |
| **Samiyeel Alim Binaaf**    | North South University | 2212779042 | [![Samiyeel's GitHub](https://img.shields.io/badge/-Pronaaf2k-181717?style=for-the-badge&logo=github&logoColor=white)](https://github.com/Pronaaf2k) | ![Followers](https://img.shields.io/github/followers/Pronaaf2k?label=Follow&style=social) |


Star the repo if you wanna support more projects like this!

---

</div>
