#include <iostream>
#include <bitset>

static const char *const title = "Организация ЭВМ";
static const char *const taskNumber = "Работа №";
static const char *const variant = "Вариант: ";
static const char *const madeBy = "Выполнил: ";
static const char *const task = "Задание: ";

static const int uintLength = sizeof(u_int) * 8;
static const int uintMaxBitNumber = uintLength - 1;
static const int doubleLength = sizeof(double) * 8;
static const int doubleMaxNumber = doubleLength - 1;

void showStartMessage();

int runUnsignedInt();

int runDouble();

void showNoArgError();

void showWrongArgError(const char *arg);

void showError();

using namespace std;

inline void clear() {
    cout << "\033[2J\033[1;1H";
}

union Udouble {
    double d;
    unsigned long u;
};

int main(int argc, char *argv[]) {
    showStartMessage();
    if (argc == 1) {
        showNoArgError();
        return -1;
    } else {
        const char *arg = argv[1];
        if (string(arg) == "uint") {
            return runUnsignedInt();
        } else if (string(arg) == "double") {
            return runDouble();
        } else {
            showWrongArgError(arg);
            return -1;
        }
    }
}

void showWrongArgError(const char *arg) {
    cout << "Указан неверный аргумент: " << arg << endl;
    showNoArgError();
}

void showNoArgError() {
    cout << "Для запуска укажите аргумент: <uint> - для unsigned int, <double> - для double" << endl;
}

int runDouble() {
    double number(0);
    cout << "Введите десятичное число: ";
    cin >> number;
    cout << "Вы ввели: " << number << endl;
    Udouble udouble;
    udouble.d = number;
    bitset<doubleLength> bits(udouble.u);
    cout << "Введенное число в двоичном виде: " << endl;
    cout << bits << endl;
    u_short position(0);
    cout << "Введите номер младшего бита от ["
         << 0
         << "] до ["
         << doubleMaxNumber
         << "]" << endl;
    cin >> position;
    if (position < 0 || position > doubleMaxNumber) {
        showError();
        return -1;
    }
    u_short count(0);
    cout << "Введите количество битов для изменения от ["
         << 0
         << "] до ["
         << doubleMaxNumber - position
         << "]" << endl;
    cin >> count;
    if (count < 0 || count > doubleMaxNumber - position) {
        showError();
        return -1;
    }
    int bit;
    for (size_t i = position; i < position + count; ++i) {
        cout << i
             << "-й бит: ";
        cin >> bit;
        bits.set(i, static_cast<bool>(bit));
    }
    cout << "Полученное число в двоичном виде: " << endl;
    cout << bits << endl;
    cout << "Полученное число в десятичном виде: " << endl;
    Udouble result;
    result.u = bits.to_ullong();
    cout <<  result.d << endl;
    return 0;
}

int runUnsignedInt() {
    u_int number(0);
    cout << "Введите целое беззнаковое число: ";
    cin >> number;
    cout << "Вы ввели: " << number << endl;
    bitset<uintLength> bits(number);
    cout << "Введенное число в двоичном виде: " << endl;
    cout << bits << endl;
    u_short position(0);
    cout << "Введите номер младшего бита от ["
         << 0
         << "] до ["
         << uintMaxBitNumber
         << "]" << endl;
    cin >> position;
    if (position < 0 || position > uintMaxBitNumber) {
        showError();
        return -1;
    }
    u_short count(0);
    cout << "Введите количество битов для изменения от ["
         << 0
         << "] до ["
         << uintMaxBitNumber - position
         << "]" << endl;
    cin >> count;
    if (count < 0 || count > uintMaxBitNumber - position) {
        showError();
        return -1;
    }
    int bit;
    for (size_t i = position; i < position + count; ++i) {
        cout << i
             << "-й бит: ";
        cin >> bit;
        bits.set(i, static_cast<bool>(bit));
    }
    cout << "Полученное число в двоичном виде: " << endl;
    cout << bits << endl;
    cout << "Полученное число в десятичном виде: " << endl;
    cout << (u_int) bits.to_ulong();
    return 0;
}

void showError() { cout << "Ошибка!!!" << endl; }

void showStartMessage() {
    cout << "\t\t" << title << endl;
    cout << endl;
    cout << taskNumber << 1 << endl;
    cout << variant << 4 << endl;
    cout << madeBy << "Гаврилов П.А." << endl;
    cout << task << "Установить в заданное пользователем состояние определённое количество рядом стоящих бит, "
         << "номер младшего из которых, как и всё остальное, вводится с клавиатуры." << endl;
    cout << endl;
}
