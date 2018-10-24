#include <iostream>
#include <bitset>

static const char *const title = "Организация ЭВМ";
static const char *const taskNumber = "Работа №";
static const char *const variant = "Вариант: ";
static const char *const madeBy = "Выполнил: ";
static const char *const task = "Задание: ";

void showStartMessage();

template<typename T>
int runDouble();

void showNoArgError();

void showWrongArgError(const char *arg);

void showError();

template<typename T>
T getNumber();

using namespace std;

template<typename T>
union Utype {
    Utype(T t) : t(t) {}

    Utype(unsigned long u) : u(u) {}

    T t;
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
            return runDouble<u_int>();
        } else if (string(arg) == "double") {
            return runDouble<double>();
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

template<typename T>
int runDouble() {
    const int typeLength = sizeof(T) * 8;
    const int typeMaxBitNumber = typeLength - 1;
    T number(0);
    cout << "Введите число: ";
    number = getNumber<T>();
    cout << "Вы ввели: " << number << endl;
    Utype<T> utype(number);
    bitset<typeLength> bits(utype.u);
    cout << "Введенное число в двоичном виде: " << endl;
    cout << bits << endl;
    u_short position(0);
    cout << "Введите номер младшего бита от ["
         << 0
         << "] до ["
         << typeMaxBitNumber
         << "]" << endl;
    position = getNumber<u_short>();
    if (position < 0 || position > typeMaxBitNumber) {
        showError();
        return -1;
    }
    u_short count(0);
    cout << "Введите количество битов для изменения от ["
         << 0
         << "] до ["
         << typeMaxBitNumber - position + 1
         << "]" << endl;
    count = getNumber<u_short>();
    if (count < 0 || count > typeMaxBitNumber - position + 1) {
        showError();
        return -1;
    }
    int bit;
    for (size_t i = position; i < position + count; ++i) {
        cout << i
             << "-й бит: ";
        bit = getNumber<int>();
        if (bit != 0 && bit != 1) {
            showError();
            return -1;
        }
        bits.set(i, static_cast<bool>(bit));
    }
    cout << "Полученное число в двоичном виде: " << endl;
    cout << bits << endl;
    cout << "Полученное число в десятичном виде: " << endl;
    Utype<T> result(bits.to_ulong());
    cout << result.t << endl;
    return 0;
}

template<typename T>
T getNumber() {
    T result;
    cin >> result;
    if (cin.fail()) {
        showError();
        exit(-1);
    }
    return result;
}

void showError() { cout << "Ошибка!!!" << endl; }

void showStartMessage() {
    cout << "\t\t" << title << endl;
    cout << endl;
    cout << taskNumber << 1 << endl;
    cout << variant << 4 << endl;
    cout << madeBy << "Гаврилов П.А." << endl;
    cout << task << "Установить в заданное пользователем состояние определённое количество рядом стоящих бит, "
         << "номер младшего из которых, как и всё остclecальное, вводится с клавиатуры." << endl;
    cout << endl;
}
