
#ifndef S21_FACADE_H_
#define S21_FACADE_H_

// Подключение необходимых заголовочных файлов

// Подсистема 1
class Subsystem1 {
public:
    void Operation1();
};

// Подсистема 2
class Subsystem2 {
public:
    void Operation2();
};

// Фасад
class Facade {
private:
    Subsystem1 subsystem1;
    Subsystem2 subsystem2;

public:
    void Operation();
};

#endif // S21_FACADE_H_