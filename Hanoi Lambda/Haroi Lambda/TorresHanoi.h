#pragma once
#include <iostream>
#include <functional>
class TorresHanoi {
public:
    TorresHanoi(int numDiscos) : numDiscos_(numDiscos) {}

    void resolver();

private:
    int numDiscos_;
};

