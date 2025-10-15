#include <iostream>
using namespace std;
//1
int main() {
    setlocale(LC_ALL, "ru");
    const int pizza_prices[4] = { 10, 12, 15, 20 };  // Цены на пиццу
    const int drink_prices[3] = { 3, 4, 5 };  // Цены на напитки
    int choice, quantity, total = 0;
    char more = 'y';

    // Меню пицц и напитков
    cout << "Меню пицц:\n1. Пицца 1 (10$)\n2. Пицца 2 (12$)\n3. Пицца 3 (15$)\n4. Пицца 4 (20$)\n";
    cout << "Меню напитков:\n1. Напиток 1 (3$)\n2. Напиток 2 (4$)\n3. Напиток 3 (5$)\n";

    // Процесс заказа
    while (more == 'y' || more == 'Y') {
        cout << "Введите код продукта (1-4 для пиццы, 5-7 для напитков): ";
        cin >> choice;

        if (choice >= 1 && choice <= 4) {
            cout << "Введите количество пицц: ";
            cin >> quantity;
            total += pizza_prices[choice - 1] * quantity;
        }
        else if (choice >= 5 && choice <= 7) {
            cout << "Введите количество напитков: ";
            cin >> quantity;
            total += drink_prices[choice - 5] * quantity;
        }
        else {
            cout << "Неверный код продукта.\n";
        }

        cout << "Хотите заказать еще (y/n)? ";
        cin >> more;
    }

    // Применение скидок
    if (total > 50) {
        total *= 0.8;  // Скидка 20% при заказе более 50$
    }
    else if (total > 20) {
        total -= 5;  // Скидка 5$ для заказа более 20$
    }

    cout << "Ваш чек:\nСумма заказа: $" << total << endl;
    return 0;
}

//2
int main() {
    setlocale(LC_ALL, "ru");
    double sales[3], salary[3];
    double best_sales = 0, best_salary = 0;
    double bonus = 200;

    // Ввод уровня продаж для трех менеджеров
    for (int i = 0; i < 3; i++) {
        cout << "Введите уровень продаж для менеджера #" << i + 1 << ": ";
        cin >> sales[i];
    }

    // Расчет зарплаты и определение лучшего менеджера
    for (int i = 0; i < 3; i++) {
        if (sales[i] <= 500) {
            salary[i] = 200 + (sales[i] * 0.03);  // 3% от продаж
        }
        else if (sales[i] <= 1000) {
            salary[i] = 200 + (sales[i] * 0.05);  // 5% от продаж
        }
        else {
            salary[i] = 200 + (sales[i] * 0.08);  // 8% от продаж
        }

        if (salary[i] > best_salary) {
            best_salary = salary[i];
            best_sales = sales[i];
        }
    }

    // Награждение лучшего менеджера
    best_salary += bonus;

    // Вывод результатов
    for (int i = 0; i < 3; i++) {
        cout << "Зарплата менеджера #" << i + 1 << ": " << salary[i] << endl;
    }
    cout << "Лучший менеджер с продажами " << best_sales << " получит зарплату: " << best_salary << endl;

    return 0;
}