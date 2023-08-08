#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PRODUCT_NAME_LENGTH 50

struct Product {
    double old_price;
    double new_price;
    unsigned int id;
    char product_type;
    char product_name[MAX_PRODUCT_NAME_LENGTH];
};

// Function to generate a random double between min and max with 2 decimal places
double randomDouble(double min, double max) {
    double range = max - min;
    double random = ((double)rand() / (double)RAND_MAX) * range + min;
    return ((int)(random * 100)) / 100.0;
}

// Function to generate a random character from 'A' to 'D'
char randomProductType() {
    char product_types[] = {'A', 'B', 'C', 'D'};
    int random_index = rand() % 4;
    return product_types[random_index];
}

// Function to generate a random product name
void randomProductName(char* product_name) {
    char* names[] = {"Product1", "Product2", "Product3", "Product4", "Product5"};
    int random_index = rand() % 5;
    strcpy(product_name, names[random_index]);
}

// Function to generate a unique id for a product
unsigned int generateUniqueId() {
    static unsigned int id = 1;
    return id++;
}

// Function to print product information
void printProduct(struct Product product) {
    printf("ID: %u\n", product.id);
    printf("Product Name: %s\n", product.product_name);
    printf("Product Type: %c\n", product.product_type);
    printf("Old Price: %.2lf\n", product.old_price);
    printf("New Price: %.2lf\n", product.new_price);
    printf("\n");
}

// Function to compare products based on the price difference, product type, name, and id
int compareProducts(const void* a, const void* b) {
    struct Product* productA = (struct Product*)a;
    struct Product* productB = (struct Product*)b;

    double price_diff_A = productA->new_price - productA->old_price;
    double price_diff_B = productB->new_price - productB->old_price;

    if (price_diff_A > price_diff_B)
        return -1;
    else if (price_diff_A < price_diff_B)
        return 1;
    else {
        int type_compare = productA->product_type - productB->product_type;
        if (type_compare != 0)
            return type_compare;
        else {
            int name_compare = strcmp(productA->product_name, productB->product_name);
            if (name_compare != 0)
                return name_compare;
            else {
                return productA->id - productB->id;
            }
        }
    }
}

// Function to write array of products to binary file
void writeProductsToFile(struct Product* products, int size, const char* filename) {
    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }
    fwrite(products, sizeof(struct Product), size, file);
    fclose(file);
}

// Function to read products from binary file and print their information
void readProductsFromFile(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    int num_products = file_size / sizeof(struct Product);
    struct Product* products = (struct Product*)malloc(file_size);

    fread(products, sizeof(struct Product), num_products, file);

    for (int i = 0; i < num_products; i++) {
        printProduct(products[i]);
    }

    free(products);
    fclose(file);
}

int main() {
    srand(time(0)); // Seed the random number generator

    int num_products = 40;
    struct Product* products = (struct Product*)malloc(num_products * sizeof(struct Product));

    for (int i = 0; i < num_products; i++) {
        products[i].old_price = randomDouble(4.99, 100.45);
        products[i].new_price = randomDouble(4.99, 100.45);
        products[i].product_type = randomProductType();
        randomProductName(products[i].product_name);
        products[i].id = generateUniqueId();

        printProduct(products[i]);
    }

    printf("Sorting products...\n");
    qsort(products, num_products, sizeof(struct Product), compareProducts);

    printf("Sorted products:\n");
    for (int i = 0; i < num_products; i++) {
        printProduct(products[i]);
    }

    writeProductsToFile(products, num_products, "products.bin");

    free(products);

    printf("Reading products from file:\n");
    readProductsFromFile("products.bin");

    return 0;
}
