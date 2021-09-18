#include "./../Header/NY_random.h"

std::random_device NY_random::rnd;

int NY_random::intrand_nl()
{
    return rnd();
}

int NY_random::intrand_sl(int max, int min)
{
    //�����Z���k�E�c�C�X�^����������
    std::mt19937 mt(rnd());
    //�����w��͈͂̈�l����
    std::uniform_int_distribution<> rand(min, max);

    return rand(mt);
}

double NY_random::doublerand_sl(double max, double min)
{
    //�����Z���k�E�c�C�X�^����������
    std::mt19937 mt(rnd());
    //�����w��͈͂̈�l����
    std::uniform_real_distribution<> rand(min, max);

    return rand(mt);
}

float NY_random::floatrand_sl(float max, float min)
{
    //�����Z���k�E�c�C�X�^����������
    std::mt19937 mt(rnd());
    //�����w��͈͂̈�l����
    std::uniform_real_distribution<> rand(min, max);

    return static_cast<float>(rand(mt));
}
