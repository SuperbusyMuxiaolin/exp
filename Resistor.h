#ifndef RESISTOR_H
#define RESISTOR_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <termios.h>
#include <errno.h>
#include <stdlib.h>
#include <stdint.h>

class Resistor {
private:
    int resistance;  // 电阻值
    char* alert;  // 报警信息

public:
    // 构造函数
    Resistor(int initialResistance = 0, const char* initialAlert = "") {
        resistance = initialResistance;
        alert = new char[strlen(initialAlert) + 1];
        strcpy(alert, initialAlert);
    }

    // 析构函数
    ~Resistor() {
        delete[] alert;
    }

    // 设置电阻值和报警信息
    void update() {
        int fd_adc;
        int THRESHOLD_HIGH = 9000;
        int THRESHOLD_LOW = 1000;
        const char* adc = "/dev/adc";
        char buffer[512];
        memset(buffer, 0, sizeof(buffer));

        if ((fd_adc = open(adc, O_RDWR | O_NOCTTY | O_NDELAY)) < 0) {
            printf("open ADC error\n");
            return;
        }

        int en = read(fd_adc, buffer, 10);  
        if (en == 0) {
            printf("ADC read error\n");
            return;
        }
        int len = atoi(buffer);
        resistance = len * 10000 / 4095;

        if (resistance > THRESHOLD_HIGH) {
            setAlert("Too high!");
            printf("high");
        } else if (resistance < THRESHOLD_LOW) {
            setAlert("Too low!");
            printf("low");
        } else {
            setAlert("None");
            printf("None");
        }
    }

    // 设置报警信息
    void setAlert(const char* newAlert) {
        delete[] alert;
        alert = new char[strlen(newAlert) + 1];
        strcpy(alert, newAlert);
    }

    // 获取电阻值
    int getResistance() const {
        return resistance;
    }

    // 获取报警信息
    const char* getAlert() const {
        return alert;
    }
};

#endif // RESISTOR_H



