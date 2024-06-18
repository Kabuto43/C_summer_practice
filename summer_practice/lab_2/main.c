#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "products.dat"

typedef struct
{
    char name[50];
    char manufacturer[50];
    char release_date[11]; // Формат "YYYY-MM-DD"
    int shelf_life;        // у днях
    float price;
    int quantity;
    char department[50];
} Product;

void createFile()
{
    FILE *file =
        fopen(FILENAME, "wb"); // binary write-для запису у двійковому режимі
    if (file == NULL)
    {
        printf("Помилка створення файлу.\n");
        return;
    }
    fclose(file);
    printf("Файл створено.\n");
}

void addProduct()
{
    FILE *file =
        fopen(FILENAME, "ab"); // binary append-додавання у двійковому режимі
    if (file == NULL)
    {
        printf("Помилка відкриття файлу.\n");
        return;
    }

    Product product;
    printf("Введіть назву товару: ");
    scanf("%s", product.name);
    printf("Введіть виробника: ");
    scanf("%s", product.manufacturer);
    printf("Введіть дату випуску (YYYY-MM-DD): ");
    scanf("%s", product.release_date);
    printf("Введіть термін придатності (в днях): ");
    scanf("%d", &product.shelf_life);
    printf("Введіть ціну одиниці продукції: ");
    scanf("%f", &product.price);
    printf("Введіть обсяг продукції: ");
    scanf("%d", &product.quantity);
    printf("Введіть назву відділу: ");
    scanf("%s", product.department);

    fwrite(&product, sizeof(Product), 1, file);
    fclose(file);
    printf("Запис додано.\n");
}

void viewProducts()
{
    FILE *file =
        fopen(FILENAME, "rb"); // binary read-для читання у двійковому режимі
    if (file == NULL)
    {
        printf("Файл не існує або помилка відкриття файлу.\n");
        return;
    }

    Product product;
    while (fread(&product, sizeof(Product), 1, file))
    {
        printf("Назва: %s, Виробник: %s, Дата випуску: %s, Термін придатності: %d, "
               "Ціна: %.2f, Обсяг: %d, Відділ: %s\n",
               product.name, product.manufacturer, product.release_date,
               product.shelf_life, product.price, product.quantity,
               product.department);
    }

    fclose(file);
}

void searchProduct()
{
    char searchName[50];
    printf("Введіть назву товару для пошуку: ");
    scanf("%s", searchName);

    FILE *file = fopen(FILENAME, "rb");
    if (file == NULL)
    {
        printf("Файл не існує або помилка відкриття файлу.\n");
        return;
    }

    Product product;
    int found = 0;
    while (fread(&product, sizeof(Product), 1, file))
    {
        if (strcmp(product.name, searchName) == 0)
        {
            printf("Знайдено товар: Назва: %s, Виробник: %s, Дата випуску: %s, "
                   "Термін придатності: %d, Ціна: %.2f, Обсяг: %d, Відділ: %s\n",
                   product.name, product.manufacturer, product.release_date,
                   product.shelf_life, product.price, product.quantity,
                   product.department);
            found = 1;
        }
    }

    if (!found)
    {
        printf("Товару з такою назвою не знайдено.\n");
    }

    fclose(file);
}

void printProductsByDepartment()
{
    char searchDepartment[50];
    printf("Введіть назву відділу: ");
    scanf("%s", searchDepartment);

    FILE *file = fopen(FILENAME, "rb");
    if (file == NULL)
    {
        printf("Файл не існує або помилка відкриття файлу.\n");
        return;
    }

    Product *products = NULL;
    int count = 0;
    float totalValue = 0.0;

    Product product;
    while (fread(&product, sizeof(Product), 1, file))
    {
        if (strcmp(product.department, searchDepartment) == 0)
        {
            products = realloc(products, (count + 1) * sizeof(Product));
            products[count++] = product;
            totalValue += product.price * product.quantity;
        }
    }

    if (count == 0)
    {
        printf("Товарів у цьому відділі не знайдено.\n");
    }
    else
    {
        // Сортування товарів за назвою в алфавітному порядку
        for (int i = 0; i < count - 1; i++)
        {
            for (int j = 0; j < count - i - 1; j++)
            {
                if (strcmp(products[j].name, products[j + 1].name) > 0)
                {
                    Product temp = products[j];
                    products[j] = products[j + 1];
                    products[j + 1] = temp;
                }
            }
        }

        printf("Товари у відділі %s:\n", searchDepartment);
        for (int i = 0; i < count; i++)
        {
            printf("Назва: %s, Виробник: %s, Дата випуску: %s, Термін придатності: "
                   "%d, Ціна: %.2f, Обсяг: %d\n",
                   products[i].name, products[i].manufacturer,
                   products[i].release_date, products[i].shelf_life,
                   products[i].price, products[i].quantity);
        }

        printf("Загальна вартість товарів у відділі %s: %.2f\n", searchDepartment,
               totalValue);
    }

    free(products);
    fclose(file);
}

int main()
{
    int choice;

    while (1)
    {
        printf("\nМеню:\n");
        printf("1. Створити файл\n");
        printf("2. Додати запис у файл\n");
        printf("3. Переглянути вміст файлу\n");
        printf("4. Пошук товару за назвою\n");
        printf("5. Вивести товари за відділом\n");
        printf("6. Вийти\n");
        printf("Виберіть опцію: ");
        scanf("%d", &choice);

        switch (choice)
        {
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
            printf("Невірний вибір. Спробуйте ще раз.\n");
        }
    }

    return 0;
}