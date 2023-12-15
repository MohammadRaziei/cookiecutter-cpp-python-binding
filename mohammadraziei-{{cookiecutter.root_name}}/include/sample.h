#pragma once
#include <string>

class Sample {
   public:
    static Sample create_sample(int);

   public:
    Sample(int var);
    int get_var() const;
    void set_var(int var);

    std::string str() const;

   private:
    int var = 0;
};