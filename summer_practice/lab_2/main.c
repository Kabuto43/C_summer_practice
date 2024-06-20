#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "products.dat"

typedef struct {
    char name[50];
    char manufacturer[50];
    char release_date[11]; // Format "YYYY-MM-DD"
    int shelf_life;        // in days
    float price;
    int quantity;
    char department[50];
} Product;

void createFile() {
    FILE *file = fopen(FILENAME, "wb"); // binary write mode
    if (file == NULL) {
        printf("Error creating file.\n");
        return;
    }
    fclose(file);
    printf("File created.\n");
}

void addProduct() {
    FILE *file = fopen(FILENAME, "ab"); // binary append mode
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    Product product;
    printf("Enter product name: ");
    scanf("%s", product.name);
    printf("Enter manufacturer: ");
    scanf("%s", product.manufacturer);
    printf("Enter release date (YYYY-MM-DD): ");
    scanf("%s", product.release_date);
    printf("Enter shelf life (in days): ");
    scanf("%d", &product.shelf_life);
    printf("Enter unit price: ");
    scanf("%f", &product.price);
    printf("Enter quantity: ");
    scanf("%d", &product.quantity);
    printf("Enter department name: ");
    scanf("%s", product.department);

    fwrite(&product, sizeof(Product), 1, file);
    fclose(file);
    printf("Record added.\n");
}

void viewProducts() {
    FILE *file = fopen(FILENAME, "rb"); // binary read mode
    if (file == NULL) {
        printf("File does not exist or error opening file.\n");
        return;
    }

    Product product;
    while (fread(&product, sizeof(Product), 1, file)) {
        printf(" Name: %s,\n Manufacturer: %s,\n Release Date: %s,\n Shelf Life: %d,\n "
               "Price: %.2f,\n Quantity: %d,\n Department: %s\n",
               product.name, product.manufacturer, product.release_date,
               product.shelf_life, product.price, product.quantity,
               product.department);
    }

    fclose(file);
}

void searchProduct() {
    char searchName[50];
    printf("Enter product name to search: ");
    scanf("%s", searchName);

    FILE *file = fopen(FILENAME, "rb");
    if (file == NULL) {
        printf("File does not exist or error opening file.\n");
        return;
    }

    Product product;
    int found = 0;
    while (fread(&product, sizeof(Product), 1, file)) {
        if (strcmp(product.name, searchName) == 0) {
            printf("Product found: \nName: %s,\n Manufacturer: %s,\n Release Date: %s,\n "
                   "Shelf Life: %d,\n Price: %.2f,\n Quantity: %d,\n Department: %s\n",
                   product.name, product.manufacturer, product.release_date,
                   product.shelf_life, product.price, product.quantity,
                   product.department);
            found = 1;
        }
    }

    if (!found) { printf("No product found with that name.\n"); }


    fclose(file);
}

void printProductsByDepartment() {
    char searchDepartment[50];
    printf("Enter department name: ");
    scanf("%s", searchDepartment);

    FILE *file = fopen(FILENAME, "rb");
    if (file == NULL) {
        printf("File does not exist or error opening file.\n");
        return;
    }

    Product *products = NULL;
    int count = 0;
    float totalValue = 0.0;

    Product product;
    while (fread(&product, sizeof(Product), 1, file)) {
        if (strcmp(product.department, searchDepartment) == 0) {
            products = realloc(products, (count + 1) * sizeof(Product));
            products[count++] = product;
            totalValue += product.price * product.quantity;
        }
    }

    if (count == 0) { printf("No products found in this department.\n"); }
    else {
        // Sort products by name in alphabetical order
        for (int i = 0; i < count - 1; i++) {
            for (int j = 0; j < count - i - 1; j++) {
                if (strcmp(products[j].name, products[j + 1].name) > 0) {
                    Product temp = products[j];
                    products[j] = products[j + 1];
                    products[j + 1] = temp;
                }
            }
        }

        printf("Products in department %s:\n", searchDepartment);
        for (int i = 0; i < count; i++) {
            printf("Name: %s,\n Manufacturer: %s,\n Release Date: %s,\n Shelf Life: "
                   "%d,\n Price: %.2f\n, Quantity: %d\n",
                   products[i].name, products[i].manufacturer,
                   products[i].release_date, products[i].shelf_life,
                   products[i].price, products[i].quantity);
        }

        printf("Total value of products in department %s: %.2f\n", searchDepartment, totalValue);
    }

    free(products);
    fclose(file);
}

int main() {
    int choice;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Create file\n");
        printf("2. Add record to file\n");
        printf("3. View file contents\n");
        printf("4. Search product by name\n");
        printf("5. List products by department\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            createFile();
            break;
        case 2:
            addProduct();
            break;
        case 3:
            viewProducts();
            break;
        case 4:
            searchProduct();
            break;
        case 5:
            printProductsByDepartment();
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}